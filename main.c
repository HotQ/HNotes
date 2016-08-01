#include "hn_globalDependency.h"

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
		//printw("rrrrrr:  %d \n", SelectString("show:   ",a,5));	refresh();

		do{
			choice = SelectString("s>>>>> ",arrChoice,4);
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

		//keypad(stdscr, FALSE);


		// printw("press 'e' if you wanna quit: ");
		// refresh();
		// noecho();
		// while(getch()!='e');
		endwin();
		return 0;
	}

}


