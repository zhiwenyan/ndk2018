#include <iostream>
#include <stdarg.h>


using namespace std;
//1���ɱ���� 
int sum(int count, ...){ // java int... c++ ...
	va_list vp;
	//�ɱ������ʼ������count ��������￪ʼ
	va_start(vp,count);

	//��ȡ�ɱ����
	int number = va_arg(vp, int);


	//��ȡ��һ��
	number = va_arg(vp, int);


	//��ȡ��һ��,������Ĭ����0
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
	//�൱�ڶ�����һ����̬����
	static int tag;  //��̬�Ĳ���ֱ�Ӹ�ֵ


public:
	static void change(){
		tag += 22;
		cout << "tag=" << Student::tag << endl;

	}
};
//��̬������c++�б���Ҫ��ʼ������ʼ������Ҫ��д
int Student::tag = 10;
//��̬ 1����̬����ֱ������������::
//     2����̬�����Ա����ȳ�ʼ�� 
//     3����̬�ķ���ֻ�ܲ�����̬������

//����Ĵ�С  1����ṹ����㷽ʽ����
//			  2����̬�����ͷ�����û���㵽���еĴ�С
//            3��ջ���ѡ�ȫ�֣���̬���������ַ�����������������Ĵ�Сֻ����ͨ�����й�

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

	cout << "C�Ĵ�С=" << sizeof(C) << endl;

	getchar();
}
//this->ָ��:����ǰ�Ķ�����Ϊ��ķ������ڴ������������һ����ģ�����Ҫ��this ����