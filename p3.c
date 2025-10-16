/**
 * File: p3.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-16 11:59:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*給予一個 structure 
struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF
unsigned int ListHead = 0;
其中有兩個條件
條件一  ListArray[Entry1].NextPtr = ListArray[Entry2] 
條件二  (ListArray[Entry2].DataH << 16 + ListArray[Entry2].DataL) > (ListArray[Entry1].DataH << 16 + ListArray[Entry1].DataL)
==> 第一個 index 中的 NextPtr 會指到另一個 index 中的起始位址 
    另一個 index 中的起始位址的資料內容大小一定大於原起始資料的大小
請寫一個function(unsigned int DATA_A, unsigned int DATA_B)，
能在ListArray中找到符合ListArray[Entry].DataH == Data_A 且 ListArray[Entry].DataL == Data_B
並印出其結果。如果沒有找到的話，印出”no found"  */
struct ListStruct {
    unsigned int DataH;    // 資料高位
    unsigned int DataL;    // 資料低位
    unsigned int NextPtr;  // 指向下一個節點的索引（模擬 pointer）
};

struct ListStruct ListArray[1000];
#define NULL 0xFFFF        // 表示結尾（相當於 NULL pointer）
unsigned int ListHead = 0; // 鏈結串列起始節點索引

void findvalue(unsigned int DATA_A, unsigned int DATA_B){
	unsigned int temp = ListHead; 
	while(temp != NULL){
		if(ListArray[temp].DataH == DATA_A && ListArray[temp].DataL == DATA_B){
			printf("Found at %u\n",temp);
			printf("DataH = %u\n", ListArray[temp].DataH);
        		printf("DataL = %u\n", ListArray[temp].DataL);
        		printf("NextPtr = %u\n", ListArray[temp].NextPtr);
			return ;
		}else{
			temp = ListArray[temp].NextPtr;
		}


	}
	printf("no found.\n");
	return ;
}

int main(int argc, char *argv[]) {

	ListArray[0].DataH = 1;
	ListArray[0].DataL = 10;
	ListArray[0].NextPtr = 1;
	
	ListArray[1].DataH = 2;
	ListArray[1].DataL = 20;
	ListArray[1].NextPtr = 2;
	
	ListArray[2].DataH = 3;
	ListArray[2].DataL = 30;
	ListArray[2].NextPtr = NULL;
	
	ListHead = 0;
	
	findvalue(3, 30);   // ✅ Found
	findvalue(5, 50);

	return 0;
}


