#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//比如我们现在计算1+2+3+5+6***+n
//任何算法特定执行的n步骤下，我们都可以推演出算法的复杂度（时间、空间） 
//时间复杂度简单的理解为执行的步骤
int sum1(int n){ // n+2步 O(n+2)
	int sum = 0; //1 步
	for ( int i = 0; i <= n; i++){ // n步
		sum += i;
	}
	return sum; //1 步
}
int sum2(int n){ //O(1)
	return (1 + n)*n / 2; //1步
}
//空间复杂度  反转一个字符串 aaa222bbb-》bbb222aaa
char* reversel(char* str,int n){
	//第一种写法 
	//创建一个新的数组  
	char* res = (char*)malloc(sizeof(char)*n);  //空间复杂度 O(n)
	//倒序循环
	for (int i = n; i >= 0; i--){
		res[n - i] = str[i-1];
	}
	return res;

}
void reverse2(char str[], int n){ //空间复杂度 O(1) //时间复杂度O（n/2）
	int middle =n / 2;
	for (int i = 0; i < middle; i++){
		//i的位置与i+middle的位置进行交换
		//会涉及到交换，1次交换两次赋值

	}
}

void main(){
	int sum = sum2(100);
	printf("sum=%d\n",sum);
	char* str = "aaa22bbbcc";
	char* res = reversel(str, strlen(str));
	printf("%s\n", res);

	getchar();
}