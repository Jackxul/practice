/**
 * File: p1.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-07 23:05:48
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define LOW 0
#define HIGH 500


void array_create(int *arr, int len, int low_bound, int high_bound){
	int temp = 0;
	while(temp < len){
		int val = rand()%(high_bound + 1) + low_bound;
		bool flag = false;
		for(int in = 0; in < temp; in++){
			if(*(arr + in) == val){
				flag = true;
				break;
			} 
		}
		if(!flag){
			*(arr + temp) = val;
			temp++;
		}
	}
}
void print_array(int *arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d  ",*(arr + i));
	}
	printf("\n");
}
int *selection_sort(int *arr, int len){
	int temp = 0;
	int *min = NULL;
	for(int out = 0; out < len; out++){
		min = arr + out;
		for(int in = out; in < len; in++){
			if(*(arr + in) < *min){
				min = arr + in;
			}else{
				//donothing
			}
		}
		temp = *(arr + out);
		*(arr + out) = *min;
		*min = temp;
	}
	return arr;
}
/* 給一個int a[20]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，
   且不包含a陣列內的元素，請用最少的時間和空間複雜度完成 */
void function(int *arr, int len){
	int *ptr = arr;
	for(int i = LOW; i <= HIGH; i++){
		if((ptr -arr) < len && *ptr == i){
			ptr++;
		}else{
			printf("%d  ",i);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	
	int array[20];
	int len = sizeof(array)/sizeof(array[0]);
	array_create(array, len, LOW, HIGH);
	printf("Before Sort : ");
	print_array(array, len);
	printf("\nAfter Sort : ");
	print_array(selection_sort(array, len), len);
	
	printf("\nPrint %d to %d \n\n", LOW, HIGH);
	function(array, len);

	return 0;
}


