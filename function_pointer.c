/**
 * File: function_pointer.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-15 16:04:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


int add(int a, int b){
	return a + b;
}
int sub(int a, int b){
	return a - b;
}
int dev(int a,int b){
	return b == 0 ? -1 : a / b;
}
int mul(int a, int b){
	return a * b;
}
int main(int argc, char *argv[]) {
	int (*array[4])(int, int);


	*array = add;
	*(array + 1) = sub;
	array[2] = dev;
	array[3] = mul;


	for(int i = 0; i < 4; i++){
		printf("%d\n",array[i](10, 5));
	}
	return 0;
}
