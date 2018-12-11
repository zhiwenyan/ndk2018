#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct{
	char* name;
	int age;
}Student;
void main(){
	/*Student stu1 = {"Steven",24};
	Student stu2;
	//在c中=相当于是（内容）赋值操作，是把stu1赋值给stu2
	stu2 = stu1; //=赋值的操作 java中的stu2对象变成stu1
	printf("%p,%p\n",&stu1,&stu2);
	printf("%s\n", stu2.name);*/

	Student stu;
	//stu.name = "yanzhiwen";  //将指针指向常量区中的yanzhiwen	
	//结构体套指针，我们必须要对结构体指针初始化（赋值）
	//指针可以指向任何地址，它的大小永远是4字节

	stu.name = (char*)malloc(100);
	//在stu.name内存里面拷贝数据“yanzhiwen”
	strcpy(stu.name,"yanzhiwen");
	stu.age = 24;


	printf("%s\n", stu.name);
	printf("%d\n", stu.age);
	printf("%d\n",sizeof(stu.name));

	getchar();
}