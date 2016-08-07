#ifndef HN_CONCOLE_H_INCLUDED
#define HN_CONCOLE_H_INCLUDED

void* initMonitor(void *arg);

WINDOW *currentWin;
int current_std_h,
	current_std_w;

extern WINDOW	*winEntry,
		        *winHnote,
		        *winPawmanager,
		        *winConsole ,
		        *winBColumn,
		        *winTemp;
		        
#endif // HN_CONCOLE_H_INCLUDED