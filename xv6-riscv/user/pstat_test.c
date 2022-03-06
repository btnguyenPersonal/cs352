#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
  struct pstat stats;
  // gets stats for all processes
  getpstat(&stats);

  // prints out all of the process stats for each process
  for(int i = 0; i < NPROC; i++)
  {
    printf("#%d\npid: %d  inuse: %d  nice value: %d  runtime: %d  pass value: %d  stride value: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.pass[i], stats.stride[i]);
  }  

  exit(0);
}
