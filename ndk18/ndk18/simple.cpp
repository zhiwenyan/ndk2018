#include <stdio.h>
#include <stdlib.h>



void setName(char** str){
	*str = "steven";
	//指针变量不断赋值，改变的是指针的指向

}

/*void main(){

	// 1、指针使用的注意事项  
	char* name = "Steven";
	char* tempName = name;

	//运算打印  
	for (int i = 0; i < 6; i++){
		printf("%c\n", *tempName);
		tempName++;

	}

	printf("name=%s\n", name);

	//写法有没有问题
	char* str = NULL;
	//强调一个概念，指针变量与指针所指向的内存变量是两个不同的概念

	setName(&str);

	printf("str=%s\n",str);
	getchar();
}*/

//const 关键字 在c和c++ 会有区别 

/*void main(){
	//常量
	const int number = 100;
	printf("number=%s\n", number);

	//常量指针(常量指针的常量是不能修改的)
	const int* number_p = &number;

	//*number_p = number;

	//指针常量(值不能改，指针也不成改)
	int number3;
	int* const number3 = &number3;




	getchar();
}*/

void print(char** str, int length){
	for (int i = 0; i < length; i++)
	{
		printf("%s\n", str[i]);

	}
}

//二级指针的内存模型  （可以看做二维数组）
//指针数组：数组指针指向的是数组元素首地址
void main(){
	char* name = "steven";
	char** nameP = &name;
	
	//单独的拿字符串数组来讲
	//第一种定义方式  
	//char** username = {"aa","bb"};

	char* username[10] = { { "aaa" }, {"bbb"} };
	for (int i = 0; i <2; i++)
	{
		printf("%s\n",username[i]);
	}
	print(username, 2);

	//第二种定义方式 定义二维数组
	char username1[10][30] = { { "aaa" }, { "bbb" }, { "ccc" } };

	for (int i = 0; i <3; i++)
	{
		printf("%s\n", username1[i]);
	}

	//print(username1, 3); //为什么不行？这个是指针的步长不一样

	getchar();
}


