#include <locale.h>
#include <stddef.h>
#include <sys/time.h> 
#include <time.h> 
#include <unistd.h>  
#include <pthread.h>  
#include <errno.h> 
#include <string.h>

#include "ncurses.h"
#include "hn_console.h"

void* initMonitor(void *arg)
{
    struct timespec ts, ts1;
    int count = 0;
 
    ts.tv_nsec = 5e8;    
    ts.tv_sec = 0;
    while(1)
    {       
        mvwprintw(winBColumn,0,0,"count:%d",count);wrefresh(winBColumn);
    
    	count++;
        if ( nanosleep(&ts, &ts1) == -1 ){
            printf("error!\n");
        }
    }
    return NULL;
}
