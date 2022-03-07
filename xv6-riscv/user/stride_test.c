#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) {
    if (fork() == 0) {
        if (fork() == 0) { //in parent 
            //sleep(5);
            struct pstat stats;
            getpstat(&stats);
            for(int i = 0; i < NPROC; i++)
            {
                printf("stats2: #%d\npid: %d  inuse: %d  nice value: %d  runtime: %d  pass value: %d  stride value: %d\n", i, stats.pid[i], stats.inuse[i], stats.nice[i], stats.runtime[i], stats.pass[i], stats.stride[i]);
            }  
        }
        else //in child 2
            {
                nice(19);
                while (1);
            }
    } else { //in child 1
        nice(14);
        while (1);
    }
    exit(0);
}

