#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// sets the nice value and executes the program
int
chnice(int n, char* proc, char* args[])
{
  // check nice value boundaries
  if (n > 19 || n < 0) {
    return -1;
  } 
  // changes nice value to n
  nice(n);
  // executes the process
  exec(proc, args);
  return 0;
}
int
main(int argc, char *argv[]) {
  // parameter check
  if (argc < 3) {
    printf("nice: invalid parameters\n");
    exit(1);
  }
  // sets n to argument 1
  // sets proc to argument 2
  // sets the rest to arguments
  int n = atoi(argv[1]);
  char* proc = argv[2];
  char* arguments[argc]; 
  for (int i = 2; i < argc; i++) {
    arguments[i - 2] = argv[i];
  }
  return chnice(n, proc, arguments);
}
