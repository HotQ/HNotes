#include "hn_globalDependency.h"


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


int main(){
	
	setlocale(LC_ALL,"");

	refresh();
	MYSQL *conn_ptr;


	initscr();
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);

	db_login(conn_ptr);



	MemoryReport();

	printw("press 'e' if you wanna quit: ");
	noecho();
	while(getch()!='e');
	echo();

	refresh();

	endwin();
	return 0;
}
