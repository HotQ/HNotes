#include "hn_globalDependency.h"

//extern int mallocTimes;


void  RecordMalloc(int size,char *caller){

	mallocMemory+=size;

	//printw("malloc: %5d  %5db   %s\n",mallocMemory,size,caller);refresh();
}

void  RecordFree(int size,char *caller){

	freeMemory+=size;
	printw("free: %5d  %5db   %s\n",freeMemory,size,caller);
}


void MemoryReport(){
	printw("\n\nMemoryReport\n");
	printw("*************************\n");
	printw("> malloc memory:%7d |\n",mallocMemory );
	printw(">   free memory:%7d |\n",freeMemory );
	printw("*************************\n");
	refresh();

}