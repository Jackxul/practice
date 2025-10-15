/**
 * File: binary_search_recursive.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-15 16:18:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define NUM 500

int binary_search(int *array, int target, int left, int right){
	int mid = (left + right) / 2;
	if(left > right){
		return -1;
	}else if(*(array + mid) == target){
		return mid;
	}else{
		return *(array + mid) > target ? binary_search(array, target, left, mid - 1) : binary_search(array, target, mid + 1, right);
	}
}

void insertion_sort(int *arr, int len){
	int *ptr = NULL;
	int key;
	for(int out = 0; out < len; out++){
		ptr = arr + out;
		key = *(arr + out);
		while(ptr - arr > 0 && *(ptr - 1) > key){
			*ptr = *(ptr - 1);
			ptr--;
		}
		*ptr = key;
	}
}
void print_array(int *arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void create_array(int *arr, int len){
	int val;
	int count = 0;
	bool flag = false;
	for(int i = 0; i < len; i++){
		val = rand() % NUM;
		while(count < i){
			if(arr[count++] == val){
				flag = true;
				count = 0;
				break;
			}
		}
		if(!flag){
			arr[i] = val;
			count = 0;

		}else{
			flag = false;
			i--;
		}
	}
}
int main() {
	
	srand((unsigned)time(NULL));
	int target = 0;
	int arr[50];
	int size = sizeof(arr)/sizeof(arr[0]);

	int (*a)(int *, int , int, int);
	a = &binary_search;
	create_array(arr, size);
	print_array(arr, size);
	insertion_sort(arr, size);
	printf("After Sorting:\n");
	print_array(arr, size);
	
	printf("Binary Search For");
	scanf("%d",&target);
	
	//binary_search(arr, target, 0, size - 1);
	if(a(arr, target, 0, size -1) == -1){
		printf("Not found\n");
	}else{
		printf("found in place %d.\n", a(arr, target, 0, size -1));
	}
	return 0;
}
