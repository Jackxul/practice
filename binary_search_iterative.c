/**
 * File: binary_search.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-09 16:15:18
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define NUM 500
void binary_search(int *arr, int size, int target){
	int left = 0, right = size - 1;
	bool flag = true;
	while(left <= right){
		int mid = (left + right) / 2;
		if(*(arr + mid) > target){
			right = mid - 1;
		}else if(*(arr + mid) < target){
			left = mid + 1;
		}else{
			printf("Target %d Found at array[%d]\n",target ,mid);
			flag = false;
			break;
		}
	}
	if(flag){
		printf("Not Found");
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
	create_array(arr, size);
	print_array(arr, size);
	insertion_sort(arr, size);
	printf("After Sorting:\n");
	print_array(arr, size);
	
	printf("Binary Search For");
	scanf("%d",&target);
	
	binary_search(arr, size, target);

	return 0;
}


