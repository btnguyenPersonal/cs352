// nicetest for nice

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  printf("nice value: %d", nice(15));
  exit(0);
}
