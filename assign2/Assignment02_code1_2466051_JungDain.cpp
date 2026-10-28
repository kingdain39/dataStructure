// linked_stack.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
element data;
struct DlistNode *llink;
struct DlistNode *rlink;
} DlistNode;

typedef struct {
	DlistNode head;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->head.rlink = &(s->head);
	s->head.llink = &(s->head);
}

int is_empty(LinkedStackType *s)
{
	return (s->head.rlink == &(s->head));
}

void push(LinkedStackType *s, element item)
{
	DlistNode *temp = (DlistNode *)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n"); 
			return;
	}

	else {
		temp->data = item;
		temp->llink = s->head.llink;
		temp->rlink = &(s->head);
		s->head.llink->rlink = temp;
		s->head.llink = temp;
	}
}

element pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode *temp = s->head.llink;
		int item = temp->data;
		temp->llink->rlink = &(s->head);
		s->head.llink = temp->llink;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {		
		return s->head.llink->data;
	}
}

int main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}




