#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//�����������ڼ���1+2+3+5+6***+n
//�κ��㷨�ض�ִ�е�n�����£����Ƕ��������ݳ��㷨�ĸ��Ӷȣ�ʱ�䡢�ռ䣩 
//ʱ�临�Ӷȼ򵥵����Ϊִ�еĲ���
int sum1(int n){ // n+2�� O(n+2)
	int sum = 0; //1 ��
	for ( int i = 0; i <= n; i++){ // n��
		sum += i;
	}
	return sum; //1 ��
}
int sum2(int n){ //O(1)
	return (1 + n)*n / 2; //1��
}
//�ռ临�Ӷ�  ��תһ���ַ��� aaa222bbb-��bbb222aaa
char* reversel(char* str,int n){
	//��һ��д�� 
	//����һ���µ�����  
	char* res = (char*)malloc(sizeof(char)*n);  //�ռ临�Ӷ� O(n)
	//����ѭ��
	for (int i = n; i >= 0; i--){
		res[n - i] = str[i-1];
	}
	return res;

}
void reverse2(char str[], int n){ //�ռ临�Ӷ� O(1) //ʱ�临�Ӷ�O��n/2��
	int middle =n / 2;
	for (int i = 0; i < middle; i++){
		//i��λ����i+middle��λ�ý��н���
		//���漰��������1�ν������θ�ֵ

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