// ptest for pcount

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  printf("pcount before: %d\n", pcount());
  if(fork() > 0) {
    // the expected answer should be the previous pcount plus one
    // this is because the parent will call fork(), and when the child
    // is created, then when the child calls fork(), that will return 0,
    // so the sleep(5) and the pcount() will not run for the child. 
    // Therefore, the parent will call sleep(5), meaning that the 
    // child will run through and exit and become a zombie process.
    // Then the parent runs, and since the child is a zombie process, 
    // it will get included in the pcount, so it will include the child and the parent
    // , whereas before it was only the parent, so the expected answer should be the previous pcount plus one

    sleep(5);  // Let child exit before parent.
    printf("pcount after: %d\n", pcount());
  }
  exit(0);
}
