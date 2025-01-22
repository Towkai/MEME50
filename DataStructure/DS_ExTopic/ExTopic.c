#include<stdio.h>
#include"../Func/intlist.h"


void main() {
    Node *head = NULL;
	traverse(head);
	append(&head, 54);
	append(&head, 12);
	append(&head, 30);
	append(&head, 25);
	Node *node = find(&head, 30);
	insert(&head, 2, 67);
	traverse(head);
	printf("Have %d Nodes\n", count(head));
	node = find(&head, 30);
	delete(&head, node);
	traverse(head);
	printf("Have %d Nodes\n", count(head));

    Node *head1 = NULL;
	append(&head1, 54);
	append(&head1, 12);
	append(&head1, 30);
	append(&head1, 25);
    insertList(&head, head1, 1);
	traverse(head);

	freeList(&head);
}