/**
 * File: gcd.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-08 22:33:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define N1 213
#define N2 282

int GCD(int a, int b){
	if(a == 0 || b == 0){
		return a + b;
	}else if(a >= b){
		return a%b == 0 ? b : GCD(b , a%b);
	}else{
		return b%a == 0 ? a : GCD(a , b%a);
	}
}
int LCM(int a, int b){
	return (a * b) / GCD(a , b);
}

int main(int argc, char *argv[]) {

	printf("GCD of %d and %d is %d\n", N1, N2, GCD(N1, N2));
	printf("LCM of %d and %d is %d\n", N1, N2, LCM(N1, N2));
	return 0;
}


