/**
 * File: linklist_delete.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-23 15:48:50
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

Node *createNode(int data){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}
	

Node *createList(int *arr, int size){
	if(size <= 0){
		return NULL;
	}
	Node *head = createNode(*(arr));
	Node *curr = head;
	for(int i = 1; i < size; i++){
		curr -> next = createNode(*(arr + i));
		curr = curr -> next;
	}
	return head;
}
void printList(Node *head){
	if(head == NULL){
		return ;
	}
	Node *curr = head;
	while(curr -> next != NULL){
		printf("%d -> ",curr -> data);
		curr = curr -> next;
	}
	printf("%d\n",curr -> data);
}
void searchNode(Node *head, int data){
	if(head == NULL){
		printf("List is empty\n");
		return ;
	}
	Node *curr = head;
	while(curr != NULL){
		if(curr -> data == data){
			printf("Data found!\n");
			return;
		}
		curr = curr -> next;
	}
	printf("Data Not Found\n");
}
Node *addNodetoList(Node *head, int data){
	if(head == NULL){
		 return createNode(data);
	}
	Node *curr = head;
	while(curr -> next != NULL){
		curr = curr -> next;
	}
	curr -> next = createNode(data);
	return head;
}
Node *deleteNode(Node *head, int data){
	if(head == NULL){
		printf("List is empty\n");
		return NULL;
	}
	Node *curr = head;
	Node *prev = NULL;
	while(curr != NULL){
		if(curr -> data == data && prev != NULL){
			Node *temp = curr;
			curr = curr -> next;
			prev -> next = curr;
			free(temp);
		}else if(curr -> data == data && prev == NULL){ //delete head
			Node *temp = curr;
			head = curr -> next;
			curr = head;
			prev = NULL;
			free(temp);
		}else{
			prev = curr;
			curr = curr -> next;
		}
	}
	return head;
}

Node *reverseList(Node *head){
	if(head == NULL){
		return NULL;
	}
	Node *curr = head;
	Node *prev = NULL;
	Node *temp = NULL;
	while(curr != NULL){
		temp = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}
Node *insertNode(Node *head, int data, int position){
	if(head == NULL){
		return createNode(data);
	}else{
		Node *curr = head;
		Node *prev = NULL;
		Node *temp = createNode(data);
		while(curr != NULL && position > 0){
			prev = curr;
			curr = curr -> next;
			position--;
		}
		prev -> next = temp;
		temp -> next = curr;
	}
	return head;
}

void freeList(Node *head){
    Node *curr;
    while(head != NULL){
        curr = head;
        head = head->next;
        free(curr);
    }
}
int main(int argc, char *argv[]) {

	srand((unsigned)time(NULL));
	
	int *arr = malloc(Size * sizeof(int));

	for(int i = 0; i < Size; i++){
		*(arr + i) = rand() % 500;
	}

	Node *head = createList(arr, Size);
	
	printList(head);
	printf("\n\n");

	head = reverseList(head);

	printList(head);

	printf("\n\n");

	head = deleteNode(head, rand() % 500);
	printList(head);
	printf("\n\n");



	return 0;
}


