#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Student{

public:
	//���캯�� 
	Student(){
		cout << "�ղι��캯��" << endl;
	}
	Student(int age){
		cout << "һ���ι��캯��" << endl;

	}

	Student(int age,char* name){
		cout << "�����ι��캯��" << endl;
		this->age = age;
		this->name = (char*)malloc(sizeof(char)*100);
		strcpy(this->name, name);
	}

	//�����������ڴ���յ�ʱ�����
	//����ڶ����ڲ������˶��ڴ棬�������������ͷ��ڴ�
	~Student(){
		cout << "��������" << endl;
		//�ͷ��ڴ�
		free(this->name);
		this->name = NULL;

	}
	//�������캯�����������һ��Ĭ�ϵĹ��캯������������֮�丳ֵ
	Student(const Student& stu){ //����������
		cout << "�������캯��" << endl;
	}
private:    
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
};
struct  Person
{
	int age;
	char* name;

};


/*void main(){

	//new ������һ��ָ��
	Student *stu = new Student();
	stu->setAge(25);
	stu->setName("ssss");

	cout << "age=" << stu->getAge() << "name=" << stu->getName() << endl;


	Student *stu1 = new Student(25,"Steven");
	cout << "age=" << stu1->getAge() << "name=" << stu1->getName() << endl;
	delete(stu1);

	//��malloc�ķ�ʽ����û�й��캯��
	Student *stu2=(Student*)malloc(sizeof(Student));
	stu2->setAge(25);
	stu2->setName("ssssssss");
	cout << "age=" << stu2->getAge() << "name=" << stu2->getName() << endl;



	//malloc free new delete ����  ���������ڴ���ͷ��ڴ��й�  
	//1��malloc/free ��һ�� new/delete Ҳ�����׵�
	//2��malloc/free����ȥ���ù��캯������������  
	//Student *stu2 = (Student*)malloc(sizeof(Student));
	//free(stu2);
	//3��new/delete 
	//Student *stu1 = new Student(25, "Steven");
	//delete(stu1);
	//4���������new����ôһ��Ҫ�ǵ�delete
	getchar();
	}*/

//�������캯���͵��ó���
void main(){
	Person person1 = {25,"Steven"};
	Person person2 = person1; //= �Ǹ�ֵ ���������ж�������Ը�ֵ��c/c++����������������

	cout << "person1=" << &person1 << "person2=" << &person2 << endl;

	Student *stu = new Student(25,"sssssssssss");
//	stu->setAge(25);
//	stu->setName("ssss");
	Student *stu1 = stu;  //�Ǹ�ֵ ���������ж�������Ը�ֵ c/c++���������������� ����ö���Ŀ�������

	cout << "age=" << stu1->getAge() << "name=" << stu1->getName() << endl;

	delete(stu);

	Student s;
	s.setAge(22);
	s.setName("111111");
	cout << "age=" << s.getAge() << "name=" << s.getName() << endl;


	Student s1 = s;
	getchar();
}