#include <stdio.h>
#include <stdlib.h>
#include <iostream> // c++的包
using namespace std;  //命名空间

// 1、c++ 代码中可以混淆c代码，c++里面写c代码，也可以调用
// 2、c++面向对象 c面向过程  
// 3、很多开源框架使基于c++的
/*void main(){
	
	//c++打印 
	//std::cout << "Hello World" << std::endl;
	cout << "Hello World" << endl;
	getchar();

}*/
//2、常量
/*void main(){
	const int numebr = 100;
	//int* numberP = &numebr; //不能通过地址去修改值  

	getchar();

}*/

//3、引用 
void swap(int* number1, int* number2){
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}
/*void swap(int* number1,int* number2){
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}

void swap1(int &number1,int &number2){  //引用

	int temp = number1;
	number1 = number2;
	number2 = temp;
}


void main(){
	//交换值
	int number1 = 10;
	int numebr2 = 20;
	swap(&number1, &numebr2);
	cout << "number1=" <<number1<<"number2="<<numebr2<< endl;


	int a = 10;
	//int b = a;  //这两个地址是不一样的
	int &b = a;
	b = 20;
	cout << "a的地址=\n" << &a<< "b的地址=\n" << &b << endl;
	cout << "a=" << a << "b=" << b << endl;


	//引用：四驱模型的拷贝，引用其实是地址赋值，可以看做成同一块内存地址的一个变量
	swap1(number1, numebr2);
	cout << "number1=" << number1 << "number2=" << numebr2 << endl;


	getchar();
}*/
//4、函数重载和默认参数

/*int add(int number1, int number2=200){
	return number1 + number2;
}
// c是不允许函数重载的
int add(int number1, int number2, int number3){
	return number1 + number2 + number3;;

}
void main(){
	int a = add(1, 2);
	int b = add(1, 2, 3);
	int c = add(1);

	cout << "a=" << a << "b=" << b << "c=" << c << endl;

	getchar();
}*/
// 5、类的初探

class Student1{
private:    //私有 包装  影响下面所有的属性
	char* name;
	int age;

public:
	void setAge(int age){
		//this指针
		this->age = age;
	}
	void setName(char* name){
		this->name = name;
	}
	int getAge(){
		return this->age;
	}
	char* getName(){
		return this->name;

	}
};
void main(){

	//new 出来是一个指针
	Student1 *stu = new Student1();
	stu->setAge(12);
	stu->setName("ssss");
	
	cout << "age=" << stu->getAge() << "name=" << stu->getName() <<endl;


	int number1 = 10;
	int numebr2 = 20;
	swap(&number1, &numebr2);
	cout << "number1=" << number1 << "number2=" << numebr2 << endl;


	int a = 10;
	//int b = a;  //这两个地址是不一样的
	int &b = a;   //这两个地址是一样的
	b = 20;
	cout << "a的地址=" << &a << "b的地址=" << &b << endl;
	cout << "a=" << a << "b=" << b << endl;

	getchar();
}