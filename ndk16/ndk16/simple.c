#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//写一个打印数组大小

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



//堆
char *getMem(int num)
{
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char)* num);    //申请内存空间
	if (p1 == NULL)
	{
		return NULL;
	}
	return p1;
}
d
//栈
//注意 return不是把内存块 64个字节,给return出来,
//而是把内存块的首地址 ,返回给 tmp
// 理解指针的关键,是内存. 没有内存哪里的指针 
char * getMem2()
{
	char buf[64];		//临时变量 栈区存放
	strcpy(buf, "123456789");
	return buf;
}
void main(){

	int a;//告诉c和C++编译器开辟一块连续大小的4字节的内存空间 
	int arr[] = { 1, 2, 3, 4, 5 };  //arr 数据类型的大小空间
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
	strcpy(tmp, "111222"); //向tmp做指向的内存空间中copy数据
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