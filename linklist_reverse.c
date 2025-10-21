/**
 * File: linklist_reverse.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-21 12:47:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define Size 250

typedef struct Node{
	struct Node *next;
	int data;
}Node;

typedef struct LinkedList{
	Node *head;
} LinkedList;

Node *createNode(int value) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> data = value;
	temp -> next = NULL;
	return temp;
}
void printList(LinkedList *lst){
	Node *curr = lst -> head;
	while(curr -> next != NULL){
		printf("%d -> ", curr -> data);
		curr = curr -> next;
	}
	printf("%d\n", curr -> data);
}
void *reverseList(LinkedList *lst){
	Node *prev = NULL;
	Node *curr = lst -> head;
	while(curr != NULL){
		Node *curn = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = curn;
	}
	lst -> head = prev;
}

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));

	LinkedList *lst = (LinkedList*)malloc(sizeof(LinkedList));
	lst -> head = createNode(0);
	Node *curr = lst -> head;
	for(int i = 0; i < Size; i++){
		curr -> next = createNode(rand() * i % 500);
		curr = curr -> next;
	}
	printList(lst);
	reverseList(lst);
	printf("\nReverse\n\n");
	printList(lst);

	return 0;
}


