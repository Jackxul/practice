/**
 * File: linklist_stack.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-16 18:08:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *head;
	Node *tail;
}Stack;

bool isempty(Stack *st){
	return (st -> head == NULL && st -> tail == NULL);
}

Stack *createstack(){
	Stack *st = (Stack*)malloc(sizeof(Stack));
	st -> head = NULL;
	st -> tail = NULL;
	return st;
}

void push(Stack *st, int value){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> data = value;
	temp -> next = NULL;
	if(isempty(st)){
		st -> head = temp;
		st -> tail = temp;
		return;
	}else{
		st -> tail -> next = temp;
		st -> tail = temp;
		return;
	}
}
int pop(Stack *st){
	if(isempty(st)){
		return -1;
	}else if(st -> head != st -> tail){
		Node *temp = st -> head;
		while(temp -> next != st -> tail){
			temp = temp -> next;
		}
		st -> tail = temp;
		temp = temp -> next;
		st -> tail -> next = NULL;
		int val = temp -> data;
		free(temp);
		return val;
	}else{
		int val = st -> head -> data;
		st -> head = NULL;
		st -> tail = NULL;
		free(st -> head);
		return val;
	}
}


void search(Stack *st, int value){
	if(isempty(st)){
		printf("no found, Stack is empty.\n");
		return;
	}else{
		Node *temp = st -> head;
		int count = 1;
		bool flag = false;
		while(temp != NULL){
			if(value == temp -> data){
				printf("Value %d found at Stack's %dth.\n",value, count);
				flag = true;
				break;
			}else{
				count++;
				temp = temp -> next;
			}
		}
		if(!flag){
			printf("no found.\n");
		}

		return;
	}
}

void printST(Stack *st){
	if(isempty(st)){
		printf("Stack is empty.\n");
		return;
	}else{
		Node *temp = st -> head;
		while(temp -> next != NULL){
			printf("Stack val : %d\n",temp -> data);
			temp = temp -> next;
		}
		printf("Stack tail val : %d\n",temp -> data);
		return;
	}
}
int main(int argc, char *argv[]) {


	Stack *st = createstack();

	push(st, 10);
	push(st, 20);
	push(st, 30);
	push(st, 40);
	push(st, 50);
	push(st, 60);
	push(st, 70);
	search(st, 70);
	pop(st);
	search(st, 70);
	push(st, 80);
	push(st, 90);
	push(st, 100);
	printST(st);
	
	search(st, 50);
	search(st, 70);
	
	printST(st);

	while(!isempty(st)){
		pop(st);
	}
	printST(st);


	return 0;
}


