#ifndef PREEMPT_H_
# define PREEMPT_H_

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

# define LOOPTIME 300
# define SLEEPTIME 100000
# define LIMITTIME 50

# define RANGE 50
# define STEP 2

void            calcul(struct timeval *now);
void            init();
void            print_res();
int             main(void);


#endif /* !PREEMPT_H_ */
