#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stddef.h>
#include <sys/time.h> 
#include <time.h> 
#include <unistd.h>  
#include <pthread.h>  
#include <errno.h> 
#include <string.h>

#include "ncurses.h"
#include "mysql.h"

#include "hn_editor.h"
#include "hn_dbLogin.h"
#include "hn_memoryManager.h"
#include "hn_HNote.h"
#include "hn_PasswordManager.h"
#include "hn_console.h"


#define  initConfig()\
	start_color();\
	init_color(COLOR_BLACK, 0, 0, 0);\
	init_pair(1, COLOR_GREEN, COLOR_BLACK);\
	init_pair(2, COLOR_RED, COLOR_BLACK);\
	init_pair(3, COLOR_BLACK, COLOR_WHITE);


WINDOW	*winEntry      =NULL,
        *winHnote      =NULL,
        *winPawmanager =NULL,
        *winConsole    =NULL,
        *winBColumn    =NULL;

void ShowHelp();
void initConcole();


int main(int argc, char **argv){
	
	setlocale(LC_ALL,"");
	MYSQL *conn_ptr;
	if(argc>1){
		if(strcmp(argv[1],"--help")==0){
			ShowHelp();
			return 0;
		}else if(strcmp(argv[1],"--pwdmanager")==0 || strcmp(argv[1],"-p")==0){
			entryPasswordManager();
			return 0;
		}else{
			printf("there's no command like \033[31;5m\"%s\"\033[0m\n",argv[1] );
			return 0;
		}
	
	}else{
		initscr();
		initConfig();

		char *arrChoice[5]={"HNotes","PasswordManager","test","Quit"};int choice;
		keypad(stdscr, TRUE);
		scrollok(stdscr,TRUE);
		initConcole();

		usleep(100);
		do{
			choice = SelectString(">>>>> ",arrChoice,4);
			switch(choice){
				case 1:
					entryHNote();
					break;
				case 2:
					entryPasswordManager();
					break;
				case 3:
					db_login(conn_ptr);
					break;
				case 4:
					break;
			}
		}while(choice!=4);
		
		MemoryReport();
		refresh();

		getchar();
		endwin();
		return 0;
	}
}


void ShowHelp(){
	printf("Usage: HNotes [options]...\n");
	printf("Options:\n");
	printf("     --help                   Display this information\n");
	printf("     --version                Display version information\n");
	printf(" -p, --pwdmanager             Open hn_pwdManager");
}

void initConcole(){
	int height,width;

	getmaxyx(stdscr, height, width);
	winBColumn = newwin( 0, width , height-1, 1 );
	wrefresh(winBColumn);

    pthread_t pthd = pthread_create(&pthd, NULL, initMonitor , NULL);
}