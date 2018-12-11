#include <iostream>
using namespace std;
/*class Vector{
private:
	int x;
	int y;
public:
	Vector(int x, int y){
		this->x = x;
		this->y = y;
	}

	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}
	int getX(){
		return this->x;
	}
	int getY(){
		return this->y;
	}

	//一般定义在类的里面
	//重载减号运算符 
	//为什么要用引用  为了防止重复创建对象
	//const关键字，为了防止修改值
	Vector operator-(const Vector &v1)  {
		int x = this->x - v1.x;
		int y = this->y - v1.y;
		Vector v(x, y);
		return v;
	}
	void operator++(){
		this->x=this->x++;

}
};


//定义在类的外面
//重载加运算符 +   关键字operator+
Vector operator+(Vector v1, Vector v2)  {
	int x = v1.getX() + v2.getX();
	int y = v1.getY() + v2.getY();
	Vector v(x, y);
	return v;
		

}


void main(){
	Vector v1(1, 2);
	Vector v2(2, 3);

	//重载运算符

	Vector v=v1+v2;
	cout<< v.getX()<< v.getY() << endl;

	Vector vv = v1 - v2;
	cout << vv.getX() << vv.getY() << endl;
	getchar();
}
*/



class Person{

public:
	//构造函数 
	Person(){
		cout << "空参构造函数" << endl;
	}
	Person(int age){
		cout << "一个参构造函数" << endl;

	}

	Person(int age, char* name){
		cout << "两个参构造函数" << endl;
		this->age = age;
		this->name = name;
	}
public:
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

public:
	void print(){
		printf("父类");
		cout << "年龄"<<this->age << "姓名" << this->name << endl;
	}
};

//继承使用:
//类继承修饰符 public 
class Student: public Person{
private:
	char* cursor;
public:
	//Person(age, name) 调用父类的构造函数
	//不光可以给父类初始化属性，还可以给本类初始化属性用逗号隔开
	Student(int age, char* name) :Person(age, name), cursor("c++"){  //调用父类的构造函数
		cout<< this->age<<endl;
		cout << "Student构造函数" << endl;

	}
public:
	void print(){
		cout << cursor << endl;
	}
};

class Teacher :Person{
	Teacher(int age, char* name) :Person(age, name){  //调用父类的构造函数
		cout << "Teacher构造函数" << endl;

	}

};
void main(){
	Student stu(24,"sss");
	stu.print();
	getchar();

}

