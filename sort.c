/**
 * File: quick_sort.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-06 20:18:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define NUM 500

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *arr, int head, int tail){
	int i = head - 1;
	int j = tail + 1;
	int pivot = head;
	while(1){
		do{
			i++;
		}while(*(arr + i) < *(arr + pivot));
		do{
			j--;
		}while(*(arr + j) > *(arr + pivot));
		if(i >= j){
			return j;
		}
		swap(arr + i, arr + j);
	}
}
void quick_sort(int *arr, int head, int tail){
	if(head < tail){
		int p = partition(arr, head, tail);
		quick_sort(arr, head, p);
		quick_sort(arr, p + 1, tail);
	}
}
int *insertion_sort(int *arr, int len){
	for(int out = 0; out < len; out++){
		int *ptr = arr + out;
		int key = *ptr;

		while(ptr - arr > 0 && key < *(ptr - 1)){
			*ptr = *(ptr - 1);
			ptr--;
		}
		*ptr = key;
	}
	return arr;
}
int *merge_sort(int *arr, int len){

	return arr;
}
int *selection_sort(int *arr, int len){
	int *ptr_temp = NULL, temp = 0;
	for(int out = 0; out < len; out++){
		ptr_temp = arr + out;
		for(int in = out; in < len; in++){
			if(*ptr_temp > *(arr + in)){
				ptr_temp = arr + in;
			}else{
				continue;
			}
		}	
		temp = *(arr + out);
		*(arr + out) = *ptr_temp;
		*ptr_temp = temp;
	}
	return arr;
}
int *bubble_sort(int *arr, int len){
	int temp = 0;
	bool flag = false;
	for(int out = 0; out < len; out++){
		for(int in=0; in < len - 1; in++){
			if(arr[in] >= arr[in+1]){
				temp = arr[in];
				arr[in] = arr[in+1];
				arr[in+1] = temp;
				flag = true;
			}else{
				continue;
			}
		}
		if(flag){
			flag = false;
		}else{
			break;
		}
	}
	return arr;
}

void print_array(int *arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void create_array(int *arr, int len){
	for(int i = 0; i < len; i++){
		arr[i] = rand() % NUM;
	}
}
int main(void){
	
	srand((unsigned)time(NULL));
	int arr1[] = {42, 17, 93, 8, 55, 71, 23, 66, 19, 37};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {84, 12, 39, 57, 46, 92, 28, 75, 64, 3, 51, 90, 16, 8, 70};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int arr3[] = {31, 77, 14, 95, 62, 5, 43, 27, 89, 11, 58, 36, 81, 24, 68, 99, 7, 53, 40, 20};
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	int arr4[500];
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	create_array(arr4, size4);
	
	print_array(arr1, size1);
	printf("After sorting:\n");
	//bubble_sort(arr1, size1);
	//selection_sort(arr1, size1);
	//insertion_sort(arr1, size1);
	quick_sort(arr1, 0, size1 - 1);
	print_array(arr1, size1);
	printf("\n");

	print_array(arr2, size2);
	printf("After sorting:\n");
	//bubble_sort(arr2, size2);
	//selection_sort(arr2, size2);
	//insertion_sort(arr2, size2);
	quick_sort(arr2, 0, size2 - 1);
	print_array(arr2, size2);
	printf("\n");

	print_array(arr3, size3);
	printf("After sorting:\n");
	//bubble_sort(arr3, size3);
	//selection_sort(arr3, size3);
	//insertion_sort(arr3, size3);
	quick_sort(arr3, 0, size3 - 1);
	print_array(arr3, size3);
	printf("\n");

	print_array(arr4, size4);
	printf("After sorting:\n");
	//bubble_sort(arr4, size4);
	//selection_sort(arr4, size4);
	//insertion_sort(arr4, size4);
	quick_sort(arr4, 0, size4 - 1);
	print_array(arr4, size4);
	printf("\n");

	return 0;
}


