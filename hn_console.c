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
struct timespec ts1,
                ts={
                    .tv_nsec = 5e6,
                    .tv_sec=0
                    }; 

void RefreshBColum();

void* initMonitor(void *arg)
{


    int count = 0;

    while(1)
    {       
        if ( nanosleep(&ts, &ts1) == -1 )
            printf("error!\n");
        RefreshBColum(&count);

    }
    return NULL;
}

void RefreshBColum(int *count){
    int height,width;
    getmaxyx(stdscr, height, width);

    werase(winBColumn);wrefresh(winBColumn);    

    if(height!=current_std_h || width!=current_std_w){
        current_std_w=width;
        current_std_h=height;
        delwin(winBColumn);
        winBColumn = newwin( 0, width , height-1, 1 );
    }
    mvwprintw(winBColumn,0,0,"count:%d h:%d w:%d",(*count),current_std_h,current_std_w);wrefresh(winBColumn);    
    (*count)++;
}