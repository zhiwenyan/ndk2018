#include <stdio.h>
#include <stdlib.h>
#include <iostream> // c++�İ�
using namespace std;  //�����ռ�

// 1��c++ �����п��Ի���c���룬c++����дc���룬Ҳ���Ե���
// 2��c++������� c�������  
// 3���ܶ࿪Դ���ʹ����c++��
/*void main(){
	
	//c++��ӡ 
	//std::cout << "Hello World" << std::endl;
	cout << "Hello World" << endl;
	getchar();

}*/
//2������
/*void main(){
	const int numebr = 100;
	//int* numberP = &numebr; //����ͨ����ַȥ�޸�ֵ  

	getchar();

}*/

//3������ 
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

void swap1(int &number1,int &number2){  //����

	int temp = number1;
	number1 = number2;
	number2 = temp;
}


void main(){
	//����ֵ
	int number1 = 10;
	int numebr2 = 20;
	swap(&number1, &numebr2);
	cout << "number1=" <<number1<<"number2="<<numebr2<< endl;


	int a = 10;
	//int b = a;  //��������ַ�ǲ�һ����
	int &b = a;
	b = 20;
	cout << "a�ĵ�ַ=\n" << &a<< "b�ĵ�ַ=\n" << &b << endl;
	cout << "a=" << a << "b=" << b << endl;


	//���ã�����ģ�͵Ŀ�����������ʵ�ǵ�ַ��ֵ�����Կ�����ͬһ���ڴ��ַ��һ������
	swap1(number1, numebr2);
	cout << "number1=" << number1 << "number2=" << numebr2 << endl;


	getchar();
}*/
//4���������غ�Ĭ�ϲ���

/*int add(int number1, int number2=200){
	return number1 + number2;
}
// c�ǲ����������ص�
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
// 5����ĳ�̽

class Student1{
private:    //˽�� ��װ  Ӱ���������е�����
	char* name;
	int age;

public:
	void setAge(int age){
		//thisָ��
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

	//new ������һ��ָ��
	Student1 *stu = new Student1();
	stu->setAge(12);
	stu->setName("ssss");
	
	cout << "age=" << stu->getAge() << "name=" << stu->getName() <<endl;


	int number1 = 10;
	int numebr2 = 20;
	swap(&number1, &numebr2);
	cout << "number1=" << number1 << "number2=" << numebr2 << endl;


	int a = 10;
	//int b = a;  //��������ַ�ǲ�һ����
	int &b = a;   //��������ַ��һ����
	b = 20;
	cout << "a�ĵ�ַ=" << &a << "b�ĵ�ַ=" << &b << endl;
	cout << "a=" << a << "b=" << b << endl;

	getchar();
}