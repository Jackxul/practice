/**
 * File: quicksort.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-06 19:55:56
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

struct foo1 {
    char c;
    uint64_t v1;
    uint16_t v2;
};

struct foo2 {
    uint64_t v1;
    uint16_t v2;
    char c;
};
struct __attribute__((__packed__)) foo3 {
    char c;
    uint64_t v1;
    uint16_t v2;
};
struct foo4{
	int c;
	short v1;
	char v2;
};
union U2 {
    char c;       // 1 byte
    int i;        // 4 bytes
    short a;
    long long z;
    double x;
    char arr[9];  // 9 bytes
};
typedef struct U3{
	int c;
	short v1;
	char v2;
	long v3;
	long long v4;
	double v5;
	float v6;
}U3;
union unionA {
	int a[5];
	char b;
	double c;
};
 
struct B {
	int n;
	union unionA a;
	char c[10];
	int d[2];
};

int main() {
    printf("foo1: %zu\n", sizeof(struct foo1));
    printf("foo2: %zu\n", sizeof(struct foo2));
    printf("foo3: %zu\n", sizeof(struct foo3));
    printf("foo4: %zu\n", sizeof(struct foo4));
    printf("U2: %zu\n", sizeof(union U2));
    printf("U3: %zu\n", sizeof(U3));

    printf("offset of foo1.c: %zu\n", offsetof(struct foo1, c));
    printf("offset of foo1.v1: %zu\n", offsetof(struct foo1, v1));
    printf("offset of foo1.v2: %zu\n", offsetof(struct foo1, v2));

    printf("offset of foo2.v1: %zu\n", offsetof(struct foo2, v1));
    printf("offset of foo2.v2: %zu\n", offsetof(struct foo2, v2));
    printf("offset of foo2.c: %zu\n", offsetof(struct foo2, c));
    
    printf("offset of foo3.c: %zu\n", offsetof(struct foo3, c));
    printf("offset of foo3.v1: %zu\n", offsetof(struct foo3, v1));
    printf("offset of foo3.v2: %zu\n", offsetof(struct foo3, v2));

    printf("offset of foo4.c: %zu\n", offsetof(struct foo4, c));
    printf("offset of foo4.v1: %zu\n", offsetof(struct foo4, v1));
    printf("offset of foo4.v2: %zu\n", offsetof(struct foo4, v2));

    printf("offset of U2.c: %zu\n", offsetof(union U2, c));
    printf("offset of U2.i: %zu\n", offsetof(union U2, i));
    printf("offset of U2.a: %zu\n", offsetof(union U2, a));
    printf("offset of U2.z: %zu\n", offsetof(union U2, z));
    printf("offset of U2.x: %zu\n", offsetof(union U2, x));
    printf("offset of U2.arr: %zu\n", offsetof(union U2, arr));

    printf("offset of U3.c: %zu\n", offsetof(U3, c));
    printf("offset of U3.v1: %zu\n", offsetof(U3, v1));
    printf("offset of U3.v2: %zu\n", offsetof(U3, v2));
    printf("offset of U3.v3: %zu\n", offsetof(U3, v3));
    printf("offset of U3.v4: %zu\n", offsetof(U3, v4));
    printf("offset of U3.v5: %zu\n", offsetof(U3, v5));
    printf("offset of U3.v6: %zu\n", offsetof(U3, v6));


    	printf("size of unionA: %zu\n", sizeof(union unionA));
	printf("offset of unionA.a: %zu\n", offsetof(union unionA, a));
	printf("offset of unionA.b: %zu\n", offsetof(union unionA, b));
	printf("offset of unionA.c: %zu\n", offsetof(union unionA, c));


	printf("size of struct B: %zu\n", sizeof(struct B));
	printf("offset of B.n: %zu\n", offsetof(struct B, n));
	printf("offset of B.a: %zu\n", offsetof(struct B, a));
	printf("offset of B.c: %zu\n", offsetof(struct B, c));
	printf("offset of B.d: %zu\n", offsetof(struct B, d));


    return 0;
}

