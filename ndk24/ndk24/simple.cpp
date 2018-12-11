#include<iostream>
using namespace std;

/*class Person{

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
		cout << "年龄" << this->age << "姓名" << this->name << endl;
	}
};

//继承使用:
//类继承修饰符 public 
class Student :public Person{
private:
	//char* cursorName;
	Cursor cursor;
public:
	//Person(age, name) 调用父类的构造函数
	//不光可以给父类初始化属性，还可以给本类初始化属性用逗号隔开
	Student(int age, char* name, string cursorName) :Person(age, name), cursor(cursorName){  //调用Cursor的构造函数
		this->cursor = cursor;
		cout << "Student构造函数" << endl;

	}

public:
	void print(){
		cout << age << "," << name << "," << cursor.getName().c_str << endl;
	}
};

class Cursor{
	string name;
public:
	Cursor(string name){
		this->name = name;
	}
public:
	string getName(){
		return this->name;
	}

};
*/
//多继承
/*class Person{
private:
	char* name;
public:
	Person(char* name){
		this->name = name;
	}
public:
	char* getName(){
		return this->name;
	}

};

class Child{
private:
	int age;
public:
	Child(int age){
		this->age = age;
	}
public:
	int getAge(){
		return this->age;
	}

};
class Student : public Person, public Child{  //多继承

public:
	Student(char* name, int age) :Person(name), Child(age){

	}
};
//虚继承 （二义性） 解决程序当中存在的二义性
class A{
public:
	char* name;

};
class B : virtual public A{  //确保继承过来的相同的属性或者函数，只存在一份拷贝

};
class C : virtual public A{

};
class D : public B, public C{

};
*/

//c++ 中的多态

/*
class Activity{
public: 
	virtual void onCreate(){  //支持多态
		cout << "Activity中的onCreate()" << endl;
	}

	
};
void startActivity(Activity* activity){
	activity->onCreate();
}
class MainActivity : public Activity{
public:
	void onCreate(){
		cout << "MainActivity中的onCreate()" << endl;
	}
};
class WecomeActivity :public Activity{
public:
	void onCreate(){
		cout << "WecomeActivity中的onCreate()" << endl;
	}
};
*/

//抽象类和接口

/*class BaseActivity {
public:
	void onCreate(){
		//initData();
		//initView();
	}
	virtual void initData()=0;  //虚函数，没有实现的 类似于java中的抽象方法，子类必须实现
	virtual void initView()=0;

};
class MainActivity : public BaseActivity{

public:
	void initData(){
		cout << "initData()" << endl;
	}

	void initView(){
		cout << "initView()" << endl;

	}

};*/


int add(int number1,int number2){
	return number1 + number2;
}

double add(double number1, double number2){
	return number1 + number2;
}

float add(float number1, float number2){
	return number1 + number2;
}


//模板函数  （相当于java中的泛型）
template<typename T>

T add(T number1, T number2){
	return number1 + number2;

}

void main(){
/*	Student* stu = new Student("steven", 24);
	cout << stu->getAge() << stu->getName() << endl;


	D d;
	d.name = "ssss";
	cout << d.name << d.name << endl;
	*/


	//c++中的多态是怎样的？默认情况下是不存在的
	//父类指向子类的引用。重写、里氏替换原则
	//程序在运行期间并不知晓运行的状态，只有在真正运行的过程中才会去找需要运行的状态
	//java中的多态
	/*Activity* activity1 = new MainActivity;
	Activity* activity2 = new WecomeActivity;
	startActivity(activity1);	
	startActivity(activity2);
	//c++静态多态（函数的重载） 动态多态（子父类）
	*/

	/*BaseActivity* activity = new MainActivity();
	activity->initData();
	*/

	int sum = add(1, 2);

	cout << sum << endl;

	double sum2 = add(1.0, 2.0);

	cout << sum2 << endl;

	float sum3 = add(1.0f, 2.0f);

	cout << sum3 << endl;
	getchar();
}
