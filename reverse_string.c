/**
 * File: reverse_string.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-15 22:32:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}
void reverse_string(char *arr){
	int size = 0;
	for(int i = 0; *(arr + i) != '\0'; i++){
		size++;
	}
	for(int i = 0; i < (size / 2); i++){
		swap(arr + i, arr + size - 1 - i);
	}
}
int main(void) {
	
	char a[200];
	printf("Input string : ");
	gets(a);
	reverse_string(a);
	puts(a);
	return 0;
}
