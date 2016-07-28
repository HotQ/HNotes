#ifndef HN_DULINKLIST_H_INCLUDED
#define HN_DULINKLIST_H_INCLUDED

typedef struct DuLNode{
    void *data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;



typedef struct  character{
    int type;   // 1 @#$aqwe123
                // 2 “‘’”
                // 3 《》，。汉语
    char en;
    char zh[5];
    char zh_ps[5];


}character,*character_p;


void InitList(DuLinkList *);
int ListLength(DuLinkList );

void ClearList(DuLinkList *);
void DeletList(DuLinkList);

void CopyLstLst(DuLinkList ,DuLinkList );

void ListInsertTail(DuLinkList ,void *);
void ListInsertHead(DuLinkList ,int );
void ListInsert(DuLinkList ,int ,int );

DuLinkList ListSplit(DuLinkList ,int);



#endif // DULINKLIST_H_INCLUDED
