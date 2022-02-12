#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
nice(int n, char* proc, char* args[])
{
  if (n > 19 || n < 0) {
    return -1;
  } 
  change_nice(n);
  exec(proc, args);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("nice: invalid parameters\n");
    exit(1);
  }
  int n = atoi(argv[1]);
  char* proc = argv[2];
  char*[argc - 3] arguments; 
  for (int i = 3; i < argc; i++) {
    arguments[i - 3] = argv[i];
  }
  return nice(n, proc, arguments);
}

