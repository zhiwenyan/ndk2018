#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//дһ����ӡ�����С

void print(int* arr,int length){

	for (int i = 0; i < length; i++){

		printf("%d", arr[i]);

	}

}

struct MyStruct
{
	char* name;

};
typedef struct MyStruct Student;

char* getStr1(){
	char* str = "12345";
	return str;
}

char* getStr2(){
	char* str = "12345";
	return str;
}
char* getStr3(){
	char buffer[128];
	strcpy(buffer, "123456");
	return buffer;
}
char* getStr4(){
	char buffer[128];
}



//��
char *getMem(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char)* num);    //�����ڴ�ռ�
	if (p1 == NULL)
	{
		return NULL;
	}
	return p1;
}
d
//ջ
//ע�� return���ǰ��ڴ�� 64���ֽ�,��return����,
//���ǰ��ڴ����׵�ַ ,���ظ� tmp
// ���ָ��Ĺؼ�,���ڴ�. û���ڴ������ָ�� 
char * getMem2()
{
	char buf[64];		//��ʱ���� ջ�����
	strcpy(buf, "123456789");
	return buf;
}
void main(){

	int a;//����c��C++����������һ��������С��4�ֽڵ��ڴ�ռ� 
	int arr[] = { 1, 2, 3, 4, 5 };  //arr �������͵Ĵ�С�ռ�
	int size = sizeof(arr) / sizeof(int);
	printf("size=%d\n", size);
	print(arr, size);
	Student stu = { "steven" };
	printf("name=%s\n", stu.name);

	char* ch=(char*)malloc(100);


	char* str1 = NULL;
	char* str2 = NULL;
	str1 = getStr1();
	str2 = getStr2();
	if (str1 == str2){
		printf("str1==str2\n");
	}
	char* str3 = NULL;
	str3 = getStr3();

	printf("%d,%d,%s\n", str1, str2,str3);


	char *tmp = NULL;
	tmp = getMem(10);
	printf("%s\n",tmp);

	if (tmp == NULL)
	{
		printf("NULL");
		return;
	}
	strcpy(tmp, "111222"); //��tmp��ָ����ڴ�ռ���copy����
	printf("hello..tmp:%s.\n", tmp);


	char *tmp1 = NULL;
	tmp1 = getMem2();
	printf("hello..tmp:%s.\n", tmp1);

	char* temp2 = NULL;
	temp2 = getMem(2);
	temp2 = "ssss";
	
	printf("hello..tmp:%s.\n", temp2);


	getchar();

}