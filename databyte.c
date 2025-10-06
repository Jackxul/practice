/**
 * File: databyte.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-06 20:05:55
 */
#include <stdio.h>
unsigned char a[8] = {0x12, 0x23, 0x34, 0x45, 0x56, 0x78, 0x89, 0x91};
unsigned short *b= a;
unsigned char *c = a;
unsigned int *d = a;
unsigned char v[8]={0x12,0x23,0x34,0x45,0x56,0x78,0x89,0x91};
unsigned short *bv=(&v+1);
unsigned long long *pp = v;
int main() {
    // 輸出 b 所指向的地址中的內容
    printf("Before increment: 0x%04x\n", *(b+1));
    printf("AddrB %p\n", b);
    printf("addr b[0] = %p\n",&b[0]);
    printf("addr b[1] = %p\n",&b[1]);
    printf("addr b[7] = %p\n",&b[7]);
    printf("=========================\n");
    printf("addr a[0] = %p\n",&a[0]);
    printf("addr a[1] = %p\n",&a[1]);
    printf("addr a[7] = %p\n",&a[7]);
    printf("=========================\n");  
    printf("addr &a = %p\n",&a);
    printf("addr b = %p\n",b);
    printf("addr c = %p\n",c);
    printf("addr d = %p\n",d);
    printf("=========================\n");  
    printf("addr v[0] = %p\n",&v[0]);
    printf("addr v[1] = %p\n",&v[1]);
    printf("LaG:%x\n",v[8]);
    printf("LaG:%p\n",&v[7]);
    printf("LaG:%p\n",&v[8]);
    printf("LaGdqdqndjclqnlcnqlkc:%p\n",bv);
    printf("LaG:%p\n",&v[9]);
    printf("LaG:%x\n",v[8]);
    printf("LaG:%x\n",v[9]);
    printf("LaG:%x\n",v[821]);
    v[821] = '0x91';
    printf("LaG:%x\n",v[821]);
    printf("addr pp = %p\n",pp + 1);
    printf("addr pp narong = %lx\n",*pp);
    printf("addr pp+1 narong = %lx\n",*(pp + 1));
    printf("sizeof = %d\n",sizeof(long long));

    
    printf("addr &v = %p\n",&v);
    printf("addr bv = %p\n",bv);
    
    
// 執行 ++(*b)
++(*b);
b++;
c++;
d++;


// 輸出 b 所指向的地址中的內容
printf("After increment: 0x%04x\n", *b);
printf("AddrA %p\n", b);
printf("AddrC %p\n", c);
printf("AddrD %p\n", d);
return 0;

}
