#include "hn_globalDependency.h"


// 初始化双向链表
void InitList(DuLinkList *L){
    *L=(DuLinkList)malloc(sizeof(DuLNode));RecordMalloc(sizeof(DuLNode),"InitList");
    (*L)->data=NULL;
    (*L)->next=(*L)->prior=(*L);
}


// 返回双向链表的长度
int ListLength(DuLinkList L){
    DuLinkList crtNode=L,headNode=L;
    int i=0;
    while(crtNode->next!=headNode){
        crtNode=crtNode->next;
        i++;
    }
    return i;
}
/*
// 清空双向链表
void ClearList(DuLinkList *L){
    DuLinkList crtNode=(*L)->prior;
    while(crtNode->prior!=(*L)){
        crtNode=crtNode->prior;
        free(crtNode->next);RecordFree(sizeof(DuLNode),"ClearList");
    }
    (*L)->next=(*L)->prior=(*L);
}

void DeletList(DuLinkList L){
    DuLinkList crtNode=L->prior;
    while(crtNode!=L){
        crtNode=crtNode->prior;
        free(crtNode->next);RecordFree(sizeof(DuLNode),"DeletList_e");
    }
    free(L);RecordFree(sizeof(DuLNode),"DeletList_Head");
}

//初始化L1，并将L赋值为L1
void CopyLstLst(DuLinkList L,DuLinkList L1){

    DuLinkList p=L->next,p1; int length=ListLength(L),i;
    //InitList(&L1);

    while(p!=L){
        ListInsertTail(L1,p->data);
        p=p->next;
    }
}

void CopyLstChrChr(DuLinkList L,char *chr1,char *chr2){
    while(chr1!=chr2+1){
        //printf("\n%d  ",*(chr1)-48);
        ListInsertTail(L,*(chr1)-48);
        //PrintDLListL;
        chr1++;
    }
}

*/


// 尾插法
void ListInsertTail(DuLinkList L,void *e){

    DuLinkList headNode=L,
               oldTail=L->prior,
               newTail;
    newTail=(DuLinkList)malloc(sizeof(DuLNode));RecordMalloc(sizeof(DuLNode),"ListInsertTail");
    newTail->data=e;

    newTail->next=L;
    newTail->prior=oldTail;

    oldTail->next=newTail;
    L->prior=newTail;
}

/*
// 头插法
void ListInsertHead(DuLinkList L,int e){



    DuLinkList newNode=(DuLinkList)malloc(sizeof(DuLNode));RecordMalloc(sizeof(DuLNode),"ListInsertHead");
    newNode->data=e;
    newNode->next=L->next;
    newNode->prior=L;
    L->next->prior=newNode;
    L->next=newNode;

}

// 中间插入
void ListInsert(DuLinkList L,int i ,int e){
    DuLinkList p,nNode=(DuLinkList)malloc(sizeof(DuLNode));RecordMalloc(sizeof(DuLNode),"ListInsert");
    nNode->data=e;

    if(i>0){
        p=L;
        while(i>0){
            p=p->next;i--;
        }
    }
    if(i<0){
        i=0-i;
        p=L->prior;
        while(i>1){
            p=p->prior;i--;
        }
    }

    nNode->next=p->next;
    p->next->prior=nNode;
    p->next=nNode;
    nNode->prior=p;


}

DuLinkList ListSplit(DuLinkList L,int i){

    DuLinkList p;

    if(i>0){
        p=L;
        while(i>0){
            p=p->next;i--;
        }
    }
    if(i<0){
        i=0-i;
        p=L->prior;
        while(i>1){
            p=p->prior;i--;
        }
        p=p->prior;
    }
    DuLinkList L1;
    L1=(DuLinkList)malloc(sizeof(DuLNode));RecordMalloc(sizeof(DuLNode)," ListSplit");
    L1->data=-65535;
    L1->next=p->next;
    p->next->prior=L1;

    L->prior->next=L1;
    L1->prior=L->prior;
    L->prior=p;
    p->next=L;
    return L1;

}


*/