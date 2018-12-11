#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Student{

public:
	//构造函数 
	Student(){
		cout << "空参构造函数" << endl;
	}
	Student(int age){
		cout << "一个参构造函数" << endl;

	}

	Student(int age,char* name){
		cout << "两个参构造函数" << endl;
		this->age = age;
		this->name = (char*)malloc(sizeof(char)*100);
		strcpy(this->name, name);
	}

	//析构函数：内存回收的时候调用
	//如果在对象内部开辟了堆内存，在析构函数中释放内存
	~Student(){
		cout << "析构函数" << endl;
		//释放内存
		free(this->name);
		this->name = NULL;

	}
	//拷贝构造函数，对象会有一个默认的构造函数，用来对象之间赋值
	Student(const Student& stu){ //常量的引用
		cout << "拷贝构造函数" << endl;
	}
private:    
	char* name;
	int age;
public:
	void setAge(int age){
		//this指针
		this->age = age;
	};
	void setName(char* name){
		this->name = name;
	};
	int getAge(){
		return this->age;
	}
	char* getName(){
		return this->name;

	}
};
struct  Person
{
	int age;
	char* name;

};


/*void main(){

	//new 出来是一个指针
	Student *stu = new Student();
	stu->setAge(25);
	stu->setName("ssss");

	cout << "age=" << stu->getAge() << "name=" << stu->getName() << endl;


	Student *stu1 = new Student(25,"Steven");
	cout << "age=" << stu1->getAge() << "name=" << stu1->getName() << endl;
	delete(stu1);

	//用malloc的方式，并没有构造函数
	Student *stu2=(Student*)malloc(sizeof(Student));
	stu2->setAge(25);
	stu2->setName("ssssssss");
	cout << "age=" << stu2->getAge() << "name=" << stu2->getName() << endl;



	//malloc free new delete 区别  都跟开辟内存和释放内存有关  
	//1、malloc/free 是一套 new/delete 也是配套的
	//2、malloc/free不会去调用构造函数和析构函数  
	//Student *stu2 = (Student*)malloc(sizeof(Student));
	//free(stu2);
	//3、new/delete 
	//Student *stu1 = new Student(25, "Steven");
	//delete(stu1);
	//4、如果用了new，那么一定要记得delete
	getchar();
	}*/

//拷贝构造函数和调用场景
void main(){
	Person person1 = {25,"Steven"};
	Person person2 = person1; //= 是赋值 把里面所有定义的属性赋值，c/c++编译器帮我们做的

	cout << "person1=" << &person1 << "person2=" << &person2 << endl;

	Student *stu = new Student(25,"sssssssssss");
//	stu->setAge(25);
//	stu->setName("ssss");
	Student *stu1 = stu;  //是赋值 把里面所有定义的属性赋值 c/c++编译器帮我们做的 会调用对象的拷贝函数

	cout << "age=" << stu1->getAge() << "name=" << stu1->getName() << endl;

	delete(stu);

	Student s;
	s.setAge(22);
	s.setName("111111");
	cout << "age=" << s.getAge() << "name=" << s.getName() << endl;


	Student s1 = s;
	getchar();
}