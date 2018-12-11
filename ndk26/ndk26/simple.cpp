#include <iostream>

using namespace std;

class Person{
public:
		   string name;
		   int age;

	

public:
	Person(string name, int age){
		this->name = name;
		this->age = age;
	}
};
class Student:public Person{
public:
	Student(string name, int age) :Person(name,age){

	}

};


void main(){

	double number1 = 1.01;
	//直接转换
	//int number2 = number1;
	//1、static_cast 基本类型数据之间转换 如把int转char
	int number2 = static_cast<int>(number1);
	cout << number2 << endl;
	//2、把一种类型转化为另一种类型
   //Student* stu = new Student("steven", 25);
	//Person* person = static_cast<Person*>(stu);
	//cout << person->name.c_str() << ","  << person->age << endl;
	Person* person = new Person("steven",25);
	//向上转型
	Student* stu = static_cast<Student*>(person);

	cout << stu->name.c_str() << "," << stu->age << endl;

	//常量类型的转换
	const Person* person1 = new Person("sss",21);
	Person* p2 = const_cast<Person*>(person1);
	p2->age = 24;


	//reinterpret_cast  强制类型转换，用于转换任何类型

	Person* person2 = new Person("steven", 25);
	Student* stu2 = reinterpret_cast<Student*>(person);
	cout << stu2->name.c_str() << "," << stu2->age << endl;


	long mPtr = (long)person;

	cout << mPtr << endl;
	//dynamic_cast 动态转换

	getchar();
}