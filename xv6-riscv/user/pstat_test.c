#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
  struct pstat stats;
  getpstat(&stats);

  for(int i = 0; i < NPROC; i++)
  {
    printf("#%d\npid: %d  inuse: %d  nice value: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i]);
  }  

  exit(0);
}
