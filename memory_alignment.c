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
union U2 {
    char c;       // 1 byte
    int i;        // 4 bytes
    short a;
    long long z;
    double x;
    char arr[9];  // 5 bytes
};

int main() {
    printf("foo1: %zu\n", sizeof(struct foo1));
    printf("foo2: %zu\n", sizeof(struct foo2));
    printf("foo3: %zu\n", sizeof(struct foo3));
    printf("U2: %zu\n", sizeof(union U2));

    printf("offset of foo1.c: %zu\n", offsetof(struct foo1, c));
    printf("offset of foo1.v1: %zu\n", offsetof(struct foo1, v1));
    printf("offset of foo1.v2: %zu\n", offsetof(struct foo1, v2));

    printf("offset of foo2.v1: %zu\n", offsetof(struct foo2, v1));
    printf("offset of foo2.v2: %zu\n", offsetof(struct foo2, v2));
    printf("offset of foo2.c: %zu\n", offsetof(struct foo2, c));
    
    printf("offset of foo3.c: %zu\n", offsetof(struct foo3, c));
    printf("offset of foo3.v1: %zu\n", offsetof(struct foo3, v1));
    printf("offset of foo3.v2: %zu\n", offsetof(struct foo3, v2));

    return 0;
}

