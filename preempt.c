#include "preempt.h"

struct timeval                  prev;
int                             resultat[RANGE / STEP];

void                            calcul(struct timeval  *now)
{
  unsigned long                 delta = 0;
  int                           res = 0;

  delta = (now->tv_sec - prev.tv_sec) * 1000000
    + (now->tv_usec - prev.tv_usec);
  delta -= SLEEPTIME;

/* DEBUG TEST
  if (delta > LIMITTIME)
    printf("[!]delta(us) = %ld\n", delta);
  else
    printf("[#]delta(us) = %ld\n", delta);
*/ /* END DEBUG TEST */

  res = delta / STEP;

  if (res < RANGE / STEP)
    resultat[res]++;
}

void                            init()
{
  prev.tv_sec = 0;
  prev.tv_usec = 0;
}

void                            print_res()
{
  int                           borne = RANGE / STEP;
  int                           i;

  for(i = 0; i < borne; ++i)
    printf("delta = %i ==> elements = %i\n", i * STEP, resultat[i]);
}

int                             main(void)
{
  int                           loop = LOOPTIME;
  struct timeval                now;

  init();

  while (loop)
  {
    gettimeofday(&prev, NULL);
    usleep(SLEEPTIME);
    gettimeofday(&now, NULL);
    calcul(&now);
    loop--;
  }
  print_res();
  return 0;
}
