/**
 * File: bit_operation_adder.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-19 15:00:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int add(int a, int b){
	int mask = a & b;
	for(int i = 0; b != 0; i++){
		mask = a & b;
		a = (a ^ b);
		b = mask << 1;
	}
	return a;
}


int main(int argc, char *argv[]) {


	printf("%d + %d = %d\n",10, 23, add(10, 23) );

	return 0;
}


