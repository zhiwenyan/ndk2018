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
	//��c��=�൱���ǣ����ݣ���ֵ�������ǰ�stu1��ֵ��stu2
	stu2 = stu1; //=��ֵ�Ĳ��� java�е�stu2������stu1
	printf("%p,%p\n",&stu1,&stu2);
	printf("%s\n", stu2.name);*/

	Student stu;
	//stu.name = "yanzhiwen";  //��ָ��ָ�������е�yanzhiwen	
	//�ṹ����ָ�룬���Ǳ���Ҫ�Խṹ��ָ���ʼ������ֵ��
	//ָ�����ָ���κε�ַ�����Ĵ�С��Զ��4�ֽ�

	stu.name = (char*)malloc(100);
	//��stu.name�ڴ����濽�����ݡ�yanzhiwen��
	strcpy(stu.name,"yanzhiwen");
	stu.age = 24;


	printf("%s\n", stu.name);
	printf("%d\n", stu.age);
	printf("%d\n",sizeof(stu.name));

	getchar();
}