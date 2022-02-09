#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct proc proc[NPROC];

int
nice(int n, char* pr, char* args[])
{

  int pid;

  if (n > 19 || n < 0) {
    return -1;
  }
  exec(pr, args);
  struct proc *p;
  for(p = proc; p < &proc[NPROC]; p++) {
    if (p->state == UNUSED) {
      p--;
      pid = p->pid;
      break;
    }
  }
  change_nice(n, pid);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("nice: invalid parameters\n", argv[i]);
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
