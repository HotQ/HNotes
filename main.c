#include "hn_globalDependency.h"

void initConfig();
void PrintDLList(DuLinkList L){

    DuLinkList p=L->next;
    while(p!=L){
        //printf("%d",p->data);
        p=p->next;
    }
}


character_p CreateCharacter(char ch1){
	if(ch1==27)return NULL;

	character_p e= (character_p)malloc(sizeof(character)); RecordMalloc(sizeof(character),"CreateCharacter");	
	char ch2,ch3;

	if(ch1>0){
		e -> type = 1;
		e -> en = ch1;
	}else{
		ch2 = getch();
		ch3 = getch();


		if(ch1==-30 && ch2==-128){
			e -> type = 3;
			e -> zh_ps[0]=ch1;
			e -> zh_ps[1]=ch2;
			e -> zh_ps[2]=ch3;
			e -> zh_ps[3]='\0';

		}else{
			e -> type = 2;
			e -> zh[0]=ch1;
			e -> zh[1]=ch2;
			e -> zh[2]=ch3;
			e -> zh[3]='\0';
		}
	}
	return e;
}


void PrintwCharacter(character_p chp){
	if(chp->type==1)printw("%c",chp->en);
	if(chp->type==2)printw("%s",chp->zh);
	if(chp->type==3)printw("%s",chp->zh_ps);
}


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
		void initConfig();
		db_login(conn_ptr);

		MemoryReport();

		printw("press 'e' if you wanna quit: ");
		refresh();
		noecho();
		while(getch()!='e');
		endwin();
		return 0;
	}

			
	


/*
Usage: gcc [options] file...
Options:
  -pass-exit-codes         Exit with highest error code from a phase
  --help                   Display this information
  --target-help            Display target specific command line options
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...]
                           Display specific types of command line options
  (Use '-v --help' to display command line options of sub-processes)
  --version                Display compiler version information
  -dumpspecs               Display all of the built in spec strings
  -dumpversion             Display the version of the compiler
  -dumpmachine             Display the compiler's target processor
  -print-search-dirs       Display the directories in the compiler's search path
  -print-libgcc-file-name  Display the name of the compiler's companion library
  -print-file-name=<lib>   Display the full path to library <lib>
  -print-prog-name=<prog>  Display the full path to compiler component <prog>
  -print-multiarch         Display the target's normalized GNU triplet, used as
                           a component in the library path

*/


}


void initConfig(){
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
}
