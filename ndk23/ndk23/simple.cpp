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

	//һ�㶨�����������
	//���ؼ�������� 
	//ΪʲôҪ������  Ϊ�˷�ֹ�ظ���������
	//const�ؼ��֣�Ϊ�˷�ֹ�޸�ֵ
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


//�������������
//���ؼ������ +   �ؼ���operator+
Vector operator+(Vector v1, Vector v2)  {
	int x = v1.getX() + v2.getX();
	int y = v1.getY() + v2.getY();
	Vector v(x, y);
	return v;
		

}


void main(){
	Vector v1(1, 2);
	Vector v2(2, 3);

	//���������

	Vector v=v1+v2;
	cout<< v.getX()<< v.getY() << endl;

	Vector vv = v1 - v2;
	cout << vv.getX() << vv.getY() << endl;
	getchar();
}
*/



class Person{

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
		cout << "����"<<this->age << "����" << this->name << endl;
	}
};

//�̳�ʹ��:
//��̳����η� public 
class Student: public Person{
private:
	char* cursor;
public:
	//Person(age, name) ���ø���Ĺ��캯��
	//������Ը������ʼ�����ԣ������Ը������ʼ�������ö��Ÿ���
	Student(int age, char* name) :Person(age, name), cursor("c++"){  //���ø���Ĺ��캯��
		cout<< this->age<<endl;
		cout << "Student���캯��" << endl;

	}
public:
	void print(){
		cout << cursor << endl;
	}
};

class Teacher :Person{
	Teacher(int age, char* name) :Person(age, name){  //���ø���Ĺ��캯��
		cout << "Teacher���캯��" << endl;

	}

};
void main(){
	Student stu(24,"sss");
	stu.print();
	getchar();

}

