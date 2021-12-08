/**
 * Implementation of a memory allocator based on the Buddy System.
 * See Knuth Art of Computer Programming, vol. 1, page 442. 
 * Each available block starts with a header that consists
 * of a tag (free/reserved), kval (size of block 2^kval), next
 * and previous pointers. Each reserved block has the tag and kval 
 * field only. All allocations are done in powers of two. All requests
 * are rounded up to the next power of two.
 * 
 * 
 */
 
#include "buddy.h"
int initialized = FALSE;
void free_buddy(void *ptr);

/* the header for an available block */
struct block_header {
	short tag;
	short kval;
	struct block_header *next;
	struct block_header *prev;
};
const int RESERVED = 0;
const int FREE = 1;
const int UNUSED = -1; /* useful for header nodes */

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* supports memory upto 2^(MAX_KVAL-1) (or 64 GB) in size */
#define  MAX_KVAL  37

/* default memory allocation is 512MB */
const size_t DEFAULT_MAX_MEM_SIZE = 512*1024*1024;


/* A static structure stores the table of pointers to the lists in the buddy system.  */
struct pool {
	void *start; // pointer to the start of the memory pool
	int lgsize;  // log2 of size
	size_t size; // size of the pool, same as 2 ^ lgsize
	/* the table of pointers to the buddy system lists */
	struct block_header * avail[MAX_KVAL];
} pool;

struct block_header * buddy_exists(struct block_header * block, int k) 
{
	size_t base = (size_t) pool.start;
	size_t block_relative_address = (size_t) block - base; 
	return (struct block_header *)((block_relative_address ^ (1ULL << k)) + base);
}

int exponent_of_two(size_t size) 
{
	int k = 0;
	while (1ULL << k <= size) {
		k++;
	}
	return k;
}

void pop_from_list(struct block_header * header) 
{
	if (pool.avail[header->kval] != header) {
		if (header->next == NULL) {
			header->prev->next = NULL;
			header->prev = NULL;
		} else {
			header->prev->next = header->next;
			header->next->prev = header->prev;
			header->next = NULL;
			header->prev = NULL;
		}
	} else 
	{
		if (header->next == NULL) {
			pool.avail[header->kval] = NULL;
		} else {
			pool.avail[header->kval] = header->next;
			pool.avail[header->kval]->prev = NULL;
			header->next = NULL;
		}
	}
}

void * retrieve_block(struct block_header * block, int user_k) 
{
	struct block_header * buddy;
	pop_from_list(block);
	while (block && block->kval != user_k) 
	{
		buddy = buddy_exists(block, block->kval - 1);
		block->kval--;
		buddy->kval = block->kval;
		buddy->tag = FREE;
		buddy->prev = NULL;
		buddy->next = pool.avail[buddy->kval];
		if (pool.avail[buddy->kval]) 
		{
			pool.avail[buddy->kval]->prev = buddy;
		}
		pool.avail[buddy->kval] = buddy;
	}
	block->tag = RESERVED;
	return block;
}

void *allocate_with_malloc(size_t size) 
{
	int k_value;
	if (!initialized) {
        buddy_init(0);
    }
	size = size + sizeof(struct block_header);
	int i;
	k_value = exponent_of_two(size);
	for (i=k_value; i<=pool.lgsize; i++) {
		if (pool.avail[i] && pool.avail[i]->tag == FREE) {
			return (struct block_header *) ((char *) retrieve_block(pool.avail[i], k_value) + sizeof(struct block_header));
		}
	}
	return NULL;
}

void *malloc(size_t size) 
{
	pthread_mutex_lock(&mutex);
    void * ptr = allocate_with_malloc(size);
    pthread_mutex_unlock(&mutex);
    return ptr;
}

void *allocate_with_calloc(size_t nmemb, size_t size) 
{
    void * ptr;
    if (!initialized) 
	{
        buddy_init(0);
    }
    ptr = allocate_with_malloc(nmemb * size);
    memset(ptr, 0, nmemb * size);
    return ptr;
}


void *calloc(size_t nmemb, size_t size) 
{
	pthread_mutex_lock(&mutex);
    void * ptr = allocate_with_calloc(nmemb, size);
    pthread_mutex_unlock(&mutex);
    return ptr;
}

void *allocate_with_realloc(void *ptr, size_t size) 
{
    struct block_header * block;
    void * ptr1;
    if (!initialized) 
	{
        buddy_init(0);
    }
    if (!ptr) {
        return allocate_with_malloc(size);
    }
    block = (struct block_header *)((char *)ptr - sizeof(struct block_header));

    if (block && block->tag == RESERVED && size) {
        ptr1 = allocate_with_malloc(size);
        if (ptr1) 
		{
            memcpy(ptr1, ptr, (1 << block->kval) - sizeof(struct block_header));
            free_buddy(ptr);
            return ptr1;
        }
    }
    return NULL;
}

void *realloc(void *ptr, size_t size) 
{
	pthread_mutex_lock(&mutex);
    void * returned_ptr = allocate_with_realloc(ptr, size);
    pthread_mutex_unlock(&mutex);
    return returned_ptr;
}

void unplug_the_block(struct block_header * header) 
{
	struct block_header * buddy;
	buddy = buddy_exists(header, header->kval);
	struct block_header * temp;
	while(header->kval < pool.lgsize && buddy && buddy->tag == FREE && header->kval == buddy->kval) {
		pop_from_list(buddy);
		if (buddy < header) {
			temp = buddy;
			buddy = header;
			header = temp;
		}
		buddy->tag = UNUSED;
		header->kval++;
		buddy = buddy_exists(header, header->kval);
	}
	header->tag = FREE;
	header->prev = NULL;
	header->next = pool.avail[header->kval];
	if (pool.avail[header->kval]) {
		pool.avail[header->kval]->prev = header;
	}
	pool.avail[header->kval] = header;
}

void free_buddy(void *ptr) 
{
	struct block_header * block;
	if(!initialized || ptr == NULL) 
	{
		return;
	}
	block = (struct block_header *) ((char *) ptr - sizeof(struct block_header));

	if (block->tag == RESERVED) {
		unplug_the_block(block);
	}
}

void free(void *ptr) 
{
	pthread_mutex_lock(&mutex);
    free_buddy(ptr);
    pthread_mutex_unlock(&mutex);
}

int buddy_init(size_t size) { 
	int i;
	if (initialized) 
	{
		return TRUE;
	}
	if (size == 0) 
	{
		size = DEFAULT_MAX_MEM_SIZE;
	} 
	else if (DEFAULT_MAX_MEM_SIZE * 2 * 32 < size) 
	{
		return TRUE;

	} 
	pool.lgsize = exponent_of_two(size);
	pool.size = 1ULL << pool.lgsize;
	pool.start = sbrk(pool.size);
	for (i=0; i<=pool.lgsize; i++) {
		pool.avail[i] = NULL;
	}
	pool.avail[pool.lgsize] = (struct block_header *) pool.start;
	pool.avail[pool.lgsize]->tag = FREE;
	pool.avail[pool.lgsize]->kval = pool.lgsize;
	pool.avail[pool.lgsize]->next = NULL;
	pool.avail[pool.lgsize]->prev = NULL;
	initialized = TRUE;
    return TRUE;
}


void printBuddyLists(void) {
    if (!initialized) 
        return;
    int i, available_blocks = 0;
    struct block_header * block;

    printf("\n");
    for (i=0; i <= pool.lgsize; i++) 
	{
        printf("List %d: head = %p ", i, &pool.avail[i]);
        block = pool.avail[i];
        while(block != NULL && block->tag == FREE) 
		{
            printf("--> [tag=%d, kval=%d, addr=%p] ", block->tag, block->kval, block);
            block = block->next;
            available_blocks++;
        }
        printf("--> <null>\n");
    }

    printf("\n Number of available blocks = %d\n", available_blocks);
}
