#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "ncurses.h"
#include "mysql.h"

#include "hn_editor.h"
#include "hn_dbLogin.h"
#include "hn_memoryManager.h"

#define  initConfig()\
	start_color();\
	init_color(COLOR_BLACK, 0, 0, 0);\
	init_pair(1, COLOR_GREEN, COLOR_BLACK);\
	init_pair(2, COLOR_RED, COLOR_BLACK);\
	init_pair(3, COLOR_BLACK, COLOR_WHITE);

int main(int argc, char **argv){
	
	setlocale(LC_ALL,"");
	MYSQL *conn_ptr;
	printf("%d\n",argc );
	if(argc>1){
		if(strcmp(argv[1],"--help")==0){
			printf("Usage: gcc [options] file...\n");
			printf("Options:\n");
			printf("     --help                   Display this information\n");
			printf("     --version                Display version information\n");
			printf(" -p, --pwdmanager             Open hn_pwdManager");
			return 0;
		}else if(strcmp(argv[1],"--pwdmanager")==0 || strcmp(argv[1],"-p")==0){
			printf("Not done yet:)\n");
		}else{
			printf("there's no command like \033[31;5m\"%s\"\033[0m\n",argv[1] );
		}
	
	}else{
		initscr();
		initConfig();

		char *arrChoice[5]={"HNotes","PasswordManager","Debug","Quit"};int choice;
		keypad(stdscr, TRUE);

		do{
			choice = SelectString(">>>>> ",arrChoice,4);
			switch(choice){
				case 1:;
				case 2:
					printw("Not done yet:)\n");
					refresh();
					break;
				case 3:
					db_login(conn_ptr);
				case 4:
					break;
			}
		}while(choice!=4);
		
		MemoryReport();
		endwin();
		return 0;
	}

}
