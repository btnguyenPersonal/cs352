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
  char* arguments[argc]; 
  for (int i = 2; i < argc; i++) {
    arguments[i - 2] = argv[i];
  }
  return chnice(n, proc, arguments);
}
