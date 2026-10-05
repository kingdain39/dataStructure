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

void deleteNode(ListNode **phead, ListNode *p){
    if(*phead == NULL){ //리스트가 이미 비어있을 때 헤드에 아무것도 없을 때
        printf("리스트가 이미 비어있음\n");
        return;
    }

    ListNode *removed = NULL;

    if(p==NULL){//p가 비었다. -> 가장 맨앞노드를 제거하는 것.
        removed = (*phead);
        *phead = (*phead)->link;
    }

    else{
        if(p->link == NULL){
            printf("삭제할 노드가 없습니다"); //p가 마지막 노드였을 수도 있음
            return;
        }
        removed = p->link;
        p->link = removed->link;
    }

     free(removed);
     return;
}


void mergeList_BtoA_Accending(ListNode **headA, ListNode **headB){
    insertNode(headA, NULL, createNode(0));
    ListNode* runner = *headA;
    while(true){
       
        if(runner->link == NULL){
            runner->link = *headB;
            *headB = NULL;
            break;
        }

        if(*headB == NULL){
            break;
        }

        if(runner->link->data >= (*headB)->data){
            ListNode* temp = *headB;
            *headB = (*headB)->link;
            insertNode(headA, runner, temp);
        }

        runner= runner->link;
    }

    deleteNode(headA,NULL);

    return;
}


void printList(ListNode *head){
    ListNode *p = head;
    while(p != NULL){
        
        printf("%d -> ",p->data);
        p = p->link;
    }
    printf("NULL\n");

}

ListNode* convertArr2LinkedList(int A[], int length){
    ListNode *headA = NULL;
    ListNode *lastA = NULL;
    for(int i=0; i<length; i++){
        ListNode* newNode = createNode(A[i]);
        insertNode(&headA, lastA, newNode);
        lastA = newNode;
    }

    return headA;
    
}

int main(void){
    int A[7] = {1,2,5, 10,15, 20,25};
    int B[6] ={3,7,8,15,18, 30};

    ListNode* headA = convertArr2LinkedList(A,sizeof(A)/sizeof(A[0]));
    ListNode* headB = convertArr2LinkedList(B,sizeof(B)/sizeof(B[0]));

    printf("전\n");
    printList(headA);
    printList(headB);
    mergeList_BtoA_Accending(&headA, &headB);

    printf("후\n");
    printList(headA);
    printList(headB);


}