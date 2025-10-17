/**
 * File: adder.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-17 09:49:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;     // 找出需要進位的部分
        a = a ^ b;             // 無進位加法
        b = carry << 1;        // 進位左移一位
    }
    return a;
}


int main(int argc, char *argv[]) {

	printf("%d\n", add(5, 3)); // 8
	return 0;
}


