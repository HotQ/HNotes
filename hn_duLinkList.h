#ifndef HN_DULINKLIST_H_INCLUDED
#define HN_DULINKLIST_H_INCLUDED

typedef struct DuLNode{
    void *data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

void InitList(DuLinkList *);
void PrintList(DuLinkList L,void (*PrintNode)(void *));

int ListLength(DuLinkList );

void ClearList(DuLinkList *);
void DeletList(DuLinkList);

void CopyLstLst(DuLinkList ,DuLinkList );

void ListInsertTail(DuLinkList ,void *);
void ListInsertHead(DuLinkList ,int );
void ListInsert(DuLinkList ,int ,int );

DuLinkList ListSplit(DuLinkList ,int);

#endif // HN_DULINKLIST_H_INCLUDED
