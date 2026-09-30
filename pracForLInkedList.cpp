#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* createNode(element data){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->link = NULL;
    newNode->data = data;
    return newNode;
}

void insertNode(ListNode **phead, ListNode *p, ListNode *newNode){
    if(p==NULL){
        newNode->link = *phead;
        *phead = newNode;
    }
    else{
        newNode->link = p->link;
        p->link = newNode;
    }
}