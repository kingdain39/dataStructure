#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

typedef struct {
    ListNode *head;   // Head pointer
    ListNode *tail;   // Tail pointer
    int length;       // # of nodes
} ListType;

ListType list1;
ListNode* createNode(element data){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->link = NULL;
    newNode->data = data;
    return newNode;
}

void error(char* message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init(ListType* plist){
    plist->length = 0;
    plist->head = plist->tail = NULL;
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


int is_empty(ListType *list)
{
    if (list->head == NULL) return 1;
    else return 0;
}


int get_length(ListType *list)
{
    return list->length;
}


// Return node pointer of 'pos' in the list.
ListNode *get_node_at(ListType *list, int pos)
{
    int i;
    ListNode *tmp_node = list->head;
    if (pos < 0) return NULL;
    for (i = 0; i < pos; i++)
        tmp_node = tmp_node->link;
    return tmp_node;
}


// Insert new data at the 'position'
void add(ListType *list, int position, element data)
{
    ListNode *p;
    if ((position >= 0) && (position <= list->length)) {

        
        //ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        ListNode *node = createNode(data);
        if (node == NULL) error("Memory allocation error");

        node->data = data;
        if (position == 0) {
            if(get_length(list)==0) list->tail = node; //length가 0이엇을때 tail처리
            insertNode(&(list->head),NULL, node);

        }
        else {
            if(position == get_length(list)) list->tail = node; //맨뒤노드를 추가할때 tail처리
            p = get_node_at(list, position-1);
            insertNode(&(list->head), p, node);
        }
        list->length++;
    }
}

void add_first(ListType *list,element data){
    ListNode* node = createNode(data);
    if(get_length(list)==0) list->tail = node;
    insertNode(&(list->head), NULL, node);
    
    list->length++;
}

void add_last(ListType *list, element data){
    ListNode* node = createNode(data);
    insertNode(&(list->head), list->tail , node);
    list->tail = node;
    list->length++;
    
}

void delete_first(ListType *list){
   if(get_length(list) == 0){
        deleteNode(&(list->head), NULL);
        return;
    }
    if(get_length(list)==1){
        list->tail = NULL;
        deleteNode(&(list->head),NULL);
        }
    else{
        deleteNode(&(list->head),NULL);
    }
    list->length--;
    
}

void delete_last(ListType *list){
    if(get_length(list) == 0){
        deleteNode(&(list->head), NULL);
        return;
    }
    if(get_length(list) == 1){
        list->tail = NULL;
        deleteNode(&(list->head),NULL);
        }
    else{
        ListNode *p = get_node_at(list, get_length(list) - 2);
            list->tail = p; 
            deleteNode(&(list->head), p);
    }
    list->length--;
}

// delete a data at the 'pos' in the list
void delete(ListType *list, int pos)
{
    if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
        if (pos == 0) {
            if(get_length(list)==1)list->tail = NULL; // 맨 처음 노드가 맨 마지막 노드일 때 tail처리

            deleteNode(&(list->head), NULL);
        }
        else {
            ListNode *p = get_node_at(list, pos - 1);
            if(pos == get_length(list)-1) list->tail = p; //맨 뒤 노드를 삭제 할 때
            deleteNode(&(list->head), p);
        }
        list->length--;
    }
}


// Return the data at the 'pos'.
element get_entry(ListType *list, int pos)
{
    ListNode *p;
    if (pos >= list->length) error("Position error");
    p = get_node_at(list, pos);
    return p->data;
}


// Display data in the buffer.
void display(ListType *list)
{
    int i;
    ListNode *node = list->head;
    printf("( ");
    for (i = 0; i < list->length; i++) {
        printf("%d ", node->data);
        node = node->link;
    }
    printf(" )\n");
}


// Find a node whose data = item
int is_in_list(ListType *list, element item)
{
    ListNode *p;
    p = list->head;
    while ((p != NULL)) {
        if (p->data == item)
            break;
        p = p->link;
    }
    if (p == NULL) return FALSE;
    else return TRUE;
}

int main()
{
ListType list1;
init(&list1);
add_first(&list1, 20);
add_last(&list1, 30);
add_first(&list1, 10);
add_last(&list1, 40);
add(&list1, 2, 70);
display(&list1);
delete(&list1, 2);
delete_first(&list1);
delete_last(&list1);
display(&list1);
printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE": "FALSE");
printf("%d\n", get_entry(&list1, 0));
}
