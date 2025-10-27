/**
 * File: linklist_swapdata.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-26 22:38:48
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
	temp -> data = val;
	temp -> next = NULL;
	return temp;
}

Node *createList(int *arr, int length){
	if(length <= 0){
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

void swapdata(Node *head, int val1, int val2){
	if(head == NULL){
		printf("List is empty\n");
		return ;
	}
	Node *curr = head;
	Node *n1 = NULL;
	Node *n2 = NULL;
	while(curr != NULL){
		if(curr -> data == val1){
			n1 = curr;
		}else if(curr -> data == val2){
			n2 = curr;
		}else if(n1 && n2){
			break;
		}else{

		}
		curr = curr -> next;
	}
	n1 -> data = val2;
	n2 -> data = val1;
}
void replacedata(Node *head, int val1, int val2){
	if(head == NULL){
		printf("List is empty\n");
		return ;
	}
	Node *curr = head;
	while(curr != NULL){
		if(curr -> data == val1){
			curr -> data = val2;
		}else if(curr -> data == val2){
			curr -> data = val1;
		}else{

		}
		curr = curr -> next;
	}
}

void printlist(node *head){
	if(head == null){
		printf("list is empty\n");
		return ;
	}
	node *curr = head;
	while(curr -> next != null){
		printf("%d -> ",curr -> data);
		curr = curr -> next;
	}
	printf("%d\n",curr -> data);
}


int main(int argc, char *argv[]) {
	
	
	int *arr = (int*)malloc(sizeof(int) * Size);
	
	for(int i = 0; i < Size; i++){
		*(arr + i) = i;
	}
	
	Node *head = createList(arr, Size);
	
	printf("\n");

	printList(head);

	printf("\n");
	printf("\n");

	swapdata(head, 25, 70);
	
	replacedata(head, 77, 100);

	printList(head);
	
	return 0;
}


