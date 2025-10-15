/**
 * File: bitwiseoperation.c
 * Author: Jack Liao
 * Description: 
 * Created on: 2025-10-09 17:28:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
/*
 *SET BIT
 *CLEAR BIT
 *FLIP BIT
 *GET BIT
 * */
#define SET_BIT(num, n) ((num) | (1U << n))
#define CLEAR_BIT(num, n) ((num) & ~(1U << n) )
#define FLIP_BIT(num, n) ((num) ^ (1U << n))
#define GET_BIT(num, n) (((num) >> n) & 1U)
/*
2. 白板題給一個 8-bit size的值求最高位元是在第幾個bit
3. SET BIT(n) = 1, CLEAR BIT(n) = 0
4. 判斷是否是2的次方
5. 判斷一整數是偶數還是奇數
6. 請擷取出Input中的第七個bit值?
7. 請擷取出Input中的第N個bit值?
8. 計算有幾個位元是 1
*/

int q2(int num){
	int highest_bit = 0;
	for(int i = 0; i < 8; i++ ){
		if(num & (1 << i)){
			highest_bit = i;
		}
	}
	return highest_bit;
}
//q3 上面define
bool q4(int num){
	if(num == 0){
		return false;
	}else{
		return ((num) & (num - 1)) == 0 ? true : false;
	}
}
bool q5(int num){
	return ((num) & 1U) == 0? true : false ;
}
//q6 上面define
//q7 上面define
int q8(int num){
	int bit_sum = 0;
	for(int i = 0; num!= 0 ; i++){
		bit_sum += (((1U << i) & num) >> i);
		num = (num & (1U << i)) == 1 ? (num & (1U << i)) : num ;
	}
}
int main(int argc, char *argv[]) {


	return 0;
}
