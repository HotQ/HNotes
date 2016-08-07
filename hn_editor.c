#include <stdlib.h>

#include "ncurses.h"

#include "hn_editor.h"
#include "hn_memoryManager.h"

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

void PrintwCharacter(WINDOW  *win,character_p chp){
	if(chp->type==1)wprintw(win,"%c",chp->en);
	if(chp->type==2)wprintw(win,"%s",chp->zh);
	if(chp->type==3)wprintw(win,"%s",chp->zh_ps);
}

int SelectString(WINDOW  *win,char* info,char *proposal[],int size){
	int pos=1,ch;
	_Marquee(win,info,proposal,pos,size);
	wrefresh(win);
	while(1){
		ch=wgetch(win);
		switch(ch){
			case KEY_LEFT :

				if(pos==1)pos=size;
				else pos--;

				wprintw(win,"\r"); 
				_Marquee(win,info,proposal,pos,size);
				break; 
			case KEY_RIGHT:

				if(pos==size)pos=1;
				else pos++;
				wprintw(win,"\r");
				_Marquee(win,info,proposal,pos,size);
				break;
			case 10:
				_Marquee(win,info,proposal,pos,size);
				wprintw(win,"\n");
				return pos;
				break;
		}
	}
}

void _Marquee(WINDOW  *win,char *info,char *proposal[],int pos,int size){
	int i;
	wprintw(win,"%s",info);
	for(i=0;i<size;i++){
		if((i+1)==pos){ 
			/*init_pair(3, COLOR_BLACK, COLOR_WHITE)*/           	
            wattron(win,COLOR_PAIR(3));
            wprintw(win," %s ",proposal[i]);
			wattroff(win,COLOR_PAIR(3));
		}else{
			wprintw(win," %s ",proposal[i]);
		}
	}
	wrefresh(win);

}
