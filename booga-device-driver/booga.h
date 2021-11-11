#ifndef __BOOGA_H
#define __BOOGA_H
/*
 * booga.h -- definitions for the char module
 *
 */
#ifndef BOOGA_MAJOR
#define BOOGA_MAJOR 0   /* dynamic major by default */
#endif

#ifndef BOOGA_NR_DEVS
#define BOOGA_NR_DEVS 4    /* booga0 through example3 */
#endif
/*
 * Split minors in two parts
 */
#define TYPE(dev)   (MINOR(dev) >> 4)  /* high nibble */
#define NUM(dev)    (MINOR(dev) & 0xf) /* low  nibble */

/*
 * The different configurable parameters
 */
struct booga_stats {
	long int booga_output;
    long int googoo_output;
    long int neka_output;
    long int wooga_output;
	long int bytes_read;
	long int bytes_written;
	long int booga0_open_count;
	long int booga1_open_count;
	long int booga2_open_count;
	long int booga3_open_count;
	struct semaphore sem;
};
typedef struct booga_stats booga_stats;

/*extern booga_stats Booga_Device_Stats;*/

#endif /* __BOOGA_H */
