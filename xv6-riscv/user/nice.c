#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
chnice(int n, char* proc, char* args[])
{
  if (n > 19 || n < 0) {
    return -1;
  } 
  nice(n);
  exec(proc, args);
  return 0;
}

int
main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("nice: invalid parameters\n");
    exit(1);
  }
  int n = atoi(argv[1]);
  char* proc = argv[2];
  char* arguments[argc - 3]; 
  int i = 3;
  while (argv[i] != 0) {
    arguments[i - 3] = argv[i];
    i++;
  }
  return chnice(n, proc, arguments);
}
