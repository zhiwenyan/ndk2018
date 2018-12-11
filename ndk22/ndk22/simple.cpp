#include <iostream>
#include <stdarg.h>


using namespace std;
//1、可变参数 
int sum(int count, ...){ // java int... c++ ...
	va_list vp;
	//可变参数开始方法，count 代表从哪里开始
	va_start(vp,count);

	//读取可变参数
	int number = va_arg(vp, int);


	//读取下一个
	number = va_arg(vp, int);


	//读取下一个,超出了默认是0
	number = va_arg(vp, int);

	cout << "number=" <<number<< endl;

	int sum = 0;
	//for (int i = 0; i < count; i++){
	//	sum += va_arg(vp, int);
	//}
	//va_end(vp);
	return sum;


}

class Student{
public:
	char* name;
	int age;
	//相当于顶定义一个静态属性
	static int tag;  //静态的不能直接赋值


public:
	static void change(){
		tag += 22;
		cout << "tag=" << Student::tag << endl;

	}
};
//静态属性在c++中必须要初始化，初始化必须要重写
int Student::tag = 10;
//静态 1、静态可以直接用类名操作::
//     2、静态的属性必须先初始化 
//     3、静态的方法只能操作静态的属性

//对象的大小  1、与结构体计算方式类似
//			  2、静态变量和方法并没有算到类中的大小
//            3、栈、堆、全局（静态、常量、字符串），代码区，类的大小只与普通属性有关

class C{
public:
	int a;
	int f;
	double b;
	char c;
	static int d;

public:
	int gatA(){
		return this->a;
	}
};
void main(){


	int sum1=sum(10,1,2,4,5);
	cout << "sum1=" << sum1 << endl;

	Student stu;
	//stu.tag = 12;
	//Student::tag = 12;

	cout << "tag=" << Student::tag << endl;
	stu.change();

	cout << "C的大小=" << sizeof(C) << endl;

	getchar();
}
//this->指针:代表当前的对象，因为类的方法存在代码区，大家是一起共享的，所以要做this 区分