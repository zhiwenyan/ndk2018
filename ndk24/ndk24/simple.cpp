#include<iostream>
using namespace std;

/*class Person{

public:
	//���캯�� 
	Person(){
		cout << "�ղι��캯��" << endl;
	}
	Person(int age){
		cout << "һ���ι��캯��" << endl;

	}

	Person(int age, char* name){
		cout << "�����ι��캯��" << endl;
		this->age = age;
		this->name = name;
	}
public:
	char* name;
	int age;
public:
	void setAge(int age){
		//thisָ��
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
		printf("����");
		cout << "����" << this->age << "����" << this->name << endl;
	}
};

//�̳�ʹ��:
//��̳����η� public 
class Student :public Person{
private:
	//char* cursorName;
	Cursor cursor;
public:
	//Person(age, name) ���ø���Ĺ��캯��
	//������Ը������ʼ�����ԣ������Ը������ʼ�������ö��Ÿ���
	Student(int age, char* name, string cursorName) :Person(age, name), cursor(cursorName){  //����Cursor�Ĺ��캯��
		this->cursor = cursor;
		cout << "Student���캯��" << endl;

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
//��̳�
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
class Student : public Person, public Child{  //��̳�

public:
	Student(char* name, int age) :Person(name), Child(age){

	}
};
//��̳� �������ԣ� ��������д��ڵĶ�����
class A{
public:
	char* name;

};
class B : virtual public A{  //ȷ���̳й�������ͬ�����Ի��ߺ�����ֻ����һ�ݿ���

};
class C : virtual public A{

};
class D : public B, public C{

};
*/

//c++ �еĶ�̬

/*
class Activity{
public: 
	virtual void onCreate(){  //֧�ֶ�̬
		cout << "Activity�е�onCreate()" << endl;
	}

	
};
void startActivity(Activity* activity){
	activity->onCreate();
}
class MainActivity : public Activity{
public:
	void onCreate(){
		cout << "MainActivity�е�onCreate()" << endl;
	}
};
class WecomeActivity :public Activity{
public:
	void onCreate(){
		cout << "WecomeActivity�е�onCreate()" << endl;
	}
};
*/

//������ͽӿ�

/*class BaseActivity {
public:
	void onCreate(){
		//initData();
		//initView();
	}
	virtual void initData()=0;  //�麯����û��ʵ�ֵ� ������java�еĳ��󷽷����������ʵ��
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


//ģ�庯��  ���൱��java�еķ��ͣ�
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


	//c++�еĶ�̬�������ģ�Ĭ��������ǲ����ڵ�
	//����ָ����������á���д�������滻ԭ��
	//�����������ڼ䲢��֪�����е�״̬��ֻ�����������еĹ����вŻ�ȥ����Ҫ���е�״̬
	//java�еĶ�̬
	/*Activity* activity1 = new MainActivity;
	Activity* activity2 = new WecomeActivity;
	startActivity(activity1);	
	startActivity(activity2);
	//c++��̬��̬�����������أ� ��̬��̬���Ӹ��ࣩ
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
