/**
 * File: bitoperation2.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-16 12:33:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//給一個unsigned short, 問換算成16進制後四個值是否相同? 若是回傳1,否則回傳0
int isHexequal(unsigned short input){
	unsigned short temp[4];
	temp[0] = (0xF000 & input) >> 12;
	temp[1] = (0x0F00 & input) >> 8;
	temp[2] = (0x00F0 & input) >> 4;
	temp[3] = (0x000F & input);


	return ((temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3]));
}
int testhighestbit(unsigned long input){
	unsigned long mask = 1UL << 63;
	int i;
	for(i = 0; mask != 0; i++, mask >>= 1){
		if(input & mask){
			break;
		}
	}
	return (64 - i);
}

int main(int argc, char *argv[]) {


	return 0;
}


