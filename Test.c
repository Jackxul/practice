#include <stdio.h>
#include <stdlib.h>
#define A 0x1<<4

int main(int argc, char *argv[]){
	
	int i = 100;
	int *p = &i;
	int **pp = &p;
	printf("i = %d\n", i);
	printf("&i = %p\n", &i);
	printf("p = %p\n", p);
	printf("&p = %p\n", &p);
	printf("*p = %d\n", *p);
	printf("pp = %p\n", pp);
	printf("&pp = %p\n", &pp);
	printf("*pp = %p\n", *pp);
	printf("**pp = %d\n", **pp);
	return 0;
}

