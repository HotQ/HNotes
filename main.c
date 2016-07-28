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



/*

	//char a[100];int i=0;
	char a1;int a2;
	while(a1!=10){
		a1 = getch();
		printw("\r%c   %d\n",a1,a1);
		
	}

	//db_login(conn_ptr);
	MemoryReport();

*/



	int aa=1,*a;char bb='c',*b=NULL;double cc=0.1,*c=&cc;

	char ch=getch();

	printw("\n********************************************************\n");

	character ch1,ch2;
	ch1.type = 1;
	ch2.type = 2;


	DuLinkList L,L1;
	//InitList(&L);
	//ListInsertTail(L,CreateCharacter(getch()));
	//ListInsertTail(L,CreateCharacter(getch()));
	PrintwCharacter(CreateCharacter(getch()));
	PrintwCharacter(CreateCharacter(getch()));
	//printw("\n%d      %d      0x%x\n",sizeof(ch1),   ListLength(L)   ,(unsigned int)(long)&ch1);


/*
    ListInsert(&L,1,9);
    PrintDLList(L);printf("\n");

    ListSplit(&L,-3);
    PrintDLList(L);printf("\n");
    PrintDLList(L1);printf("\n");
*/












	MemoryReport();

	while(getch()!='e'){}
	printw("Quit!\n");
	printw("\n********************************************************\n");
	
	refresh();

	endwin();
	return 0;
}
