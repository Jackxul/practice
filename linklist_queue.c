/**
 * File: linklist_queue.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-15 16:16:31
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


//使用Linked List實作 Queue：back, front, empty, push, pop

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *front;
	Node *back;
}Queue;

Queue *createqueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q -> front = NULL;
	q -> back = NULL;
	return q;
}

bool empty(Queue *q){
	if(q -> front == NULL){
		return true;
	}else{
		return false;
	}
}
int back(Queue *q){
	if(!empty(q)){
		return q -> back -> data;
	}else{
		return -1;
	}
}

void push(Queue *q, int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = value;
	newNode -> next = NULL;
	if(!empty(q)){
		q -> back -> next = newNode;
		q -> back = newNode;
	}else{
		q -> front = q -> back = newNode;
	}
}

int pop(Queue *q){
	if(!empty(q) && q -> front -> next != NULL){
		int rval = q -> front -> data;
		Node *temp = q -> front;
		q -> front = q -> front -> next;
		free(temp);
		return rval;
	}else if(!empty(q) && q -> front -> next == NULL){
		int rval = q -> front -> data;
		Node *temp = q -> front;
		q -> front = NULL;
		q -> back = NULL;
		free(temp);
		return rval;
	}else{
		return -1;
	}
}

int front(Queue *q){
	if(!empty(q)){
		return q -> front -> data;
	}else{
		return -1;
	}
}

void printQ(Queue *q){
	if(empty(q)){
		printf("Queue is empty.\n");
		return ;
	}
	Node *temp = q -> front;
	while(!empty(q) && temp -> next != NULL){
		printf("val : %d\n",temp -> data);
		temp = temp -> next;
	}
	printf("back val : %d\n",temp -> data);
}

int main(void) {
	

	Queue *q = createqueue();
	
	push(q, 10);
	push(q, 20);
	push(q, 30);
	
	printQ(q);
	
	printf("front = %d\n", front(q));
	printf("back = %d\n", back(q));
	
	printf("pop = %d\n", pop(q));
	printf("pop = %d\n", pop(q));
	printf("pop = %d\n", pop(q));
	printf("pop (empty) = %d\n", pop(q)); // 應該回 -1
	
	printQ(q);

return 0;

}


