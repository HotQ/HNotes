#include "ncurses.h"

#include "hn_memoryManager.h"

void  RecordMalloc(int size,char *caller){
	mallocMemory+=size;
	//wprintw("malloc: %5d  %5db   %s\n",mallocMemory,size,caller);refresh();
}

void  RecordFree(int size,char *caller){
	freeMemory+=size;
	//printw("free: %5d  %5db   %s\n",freeMemory,size,caller);
}


void MemoryReport(WINDOW  *win){
	wprintw(win,"\n\nMemoryReport\n");
	wprintw(win,"*************************\n");
	wprintw(win,"> malloc memory:%7d |\n",mallocMemory );
	wprintw(win,">   free memory:%7d |\n",freeMemory );
	wprintw(win,"*************************\n");
	wrefresh(win);
}