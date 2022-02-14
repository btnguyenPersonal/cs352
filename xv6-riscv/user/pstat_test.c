#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
  struct pstat stats;
  getpstat(&stats);

  //for(int i =0; i < (sizeof(stats.pid) / sizeof(stats.pid[0])); i++)
  //{
   // printf("pid: %d\ninuse: %d\nnice value: %d\n", stats.pid[i], stats.inuse[i], stats.nice[i]);
  //}  

  return 0;
}
