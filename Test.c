#include <stdio.h>
#include <stdlib.h>

#define F(x,y) x*y
int F2(int x, int y){
	return x*y;
}
int main(){
	

	

	int a = F(1+3,3+1);
	int a2 = F2(1+3,3+1);
	int a3 = F((1+3),(3+1));
	int a4 = F2((1+3),(3+1));

	printf("F() = %d\n",a);
	printf("F2() = %d\n",a2);
	printf("F3() = %d\n",a3);
	printf("F4() = %d\n",a4);
	
	printf("%d\n",(0|1));

}
