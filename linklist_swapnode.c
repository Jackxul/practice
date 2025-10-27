/**
 * File: linklist_swapnode.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-27 16:29:26
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

Node *createNode(int val){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> next = NULL;
	temp -> data = val;
	return temp;
}
Node *createList(int *arr, int length){
	if(length <= 0){
		printf("length is zero\n");
		return NULL;
	}
	Node *head = createNode(*arr);
	Node *curr = head;
	for(int i = 1; i < length; i++){
		curr -> next = createNode(*(arr + i));
		curr = curr -> next;
	}
	return head;
}

void printlist(Node *head){
	if(head == NULL){
		printf("list is empty\n");
		return ;
	}
	Node *curr = head;
	while(curr -> next != NULL){
		printf("%d -> ",curr -> data);
		curr = curr -> next;
	}
	printf("%d\n",curr -> data);
}

Node *swapNode(Node *head, int val1, int val2){
	if(head == NULL){
		printf("List is empty.\n");
		return NULL;
	}

	Node *pre1 = NULL;
	Node *pre2 = NULL;
	Node *curn1 = head;
	Node *curn2 = head;

	while(curn1 != NULL && curn1 -> data != val1){
		pre1 = curn1;
		curn1 = curn1 -> next;
	}
	while(curn2 != NULL && curn2 -> data != val2){
		pre2 = curn2;
		curn2 = curn2 -> next;
	}
	if(pre1 != NULL){
		pre1 -> next = curn2;
	}else{
		head = curn2;
	}
	if(pre2 != NULL){
		pre2 -> next = curn1;
	}else{
		head = curn1;
	}
	Node *temp = curn1 -> next;
	curn1 -> next = curn2 -> next;
	curn2 -> next = temp;

	return head;
}


int main(int argc, char *argv[]) {
	
	int *arr = (int*)malloc(sizeof(int) * Size);

	for(int i = 0; i < Size; i++){
		*(arr + i) = i;
	}
	

	Node *head = createList(arr, Size);
	
	printf("\n");

	printlist(head);

	printf("\n");
	printf("\n");

	head = swapNode(head, 25, 70);
	head = swapNode(head, 2, 3);
	

	printlist(head);


	return 0;
}


