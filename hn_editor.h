#ifndef HN_EDITOR_H_INCLUDED
#define HN_EDITOR_H_INCLUDED

typedef struct  character{
    int type;   /* 1 @#$aqwe123
                   2 “‘’”
                   3 《》，。汉语 */
    char en;
    char zh[5];
    char zh_ps[5];
}character,*character_p;

character_p CreateCharacter(char ch1);
void PrintwCharacter(WINDOW  *win,character_p chp);
int SelectString(WINDOW  *win,char* info,char *proposal[],int size);
void _Marquee(WINDOW  *win,char *info,char *proposal[],int pos,int size);

#endif // HN_EDITOR_H_INCLUDED