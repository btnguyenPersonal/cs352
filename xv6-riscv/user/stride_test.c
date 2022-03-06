#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
    struct pstat stats1;
    struct pstat stats2;
    if (fork() == 0) {
        sleep(100);
        for(int i = 0; i < NPROC; i++)
        {
            printf("stats2: #%d\npid: %d  inuse: %d  nice value: %d  runtime: %d  pass value: %d  stride value: %d\n", i, stats2.pid[i], stats2.inuse[i], stats2.nice[i], stats2.runtime[i], stats2.pass[i], stats2.stride[i]);
        }  
        for(int i = 0; i < NPROC; i++)
        {
            printf("stats1: #%d\npid: %d  inuse: %d  nice value: %d  runtime: %d  pass value: %d  stride value: %d\n", i, stats1.pid[i], stats1.inuse[i], stats1.nice[i], stats1.runtime[i], stats1.pass[i], stats1.stride[i]);
        }  
    } else {
        if (fork() == 0) {
            nice(19);
            while (1) {
                getpstat(&stats1);
            }
        } else {
            nice(14);
            while (1) {
                getpstat(&stats2);
            }
        }
    }
    exit(0);
}

