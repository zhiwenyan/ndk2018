#include <stdio.h>
#include <string.h>
#include <malloc.h>


struct Worker{  //����һ���ṹ�壬�൱��java��class
	char name[18]; //10
 	int age;   //4
	double salary;  //8
}; 
struct Worker1{  //����һ���ṹ�壬�൱��java��class
	char name[10];
    int age;
    double salary;
}steven{ "zhiwen", 22, 10000 }, jack{ "jack", 20, 100000 }; //ֱ�Ӹ�ֵ


struct Worker2{  //����һ���ṹ�壬�൱��java��class
	char name[10];
	int age;
	double salary;
}worker2;  //������



//�ṹ��ͽṹ��ָ��ȡ����  
typedef Worker worker_;
typedef Worker* worker_p;

// 5 ������Ķ����ʹ�� 

union Person
{
	char name[10];
	int age;
};


//6 ö�ٵĶ����ʹ��  

enum  CommentType
{
	TEXT=10,TEXT_IMAGE
};

void main(){
	//����Ĺ���
	//1�����������ֽ�ȥ����   2�����ʱ��ֻ�ᰴ�ջ�������ȥ���� 3���������е��ֽ����������Ƿ��ܹ�������������ֽ��������������ۼ�
	int size1 = sizeof(Worker);
	printf("%d\n", size1);


	CommentType comment = TEXT;
	printf("%d\n",comment);

	printf("%s\n", steven.name);

	worker2.age = 88;
	printf("%d\n", worker2.age);


	
	//	1���ṹ��Ķ����ʹ��
	 Worker worker = { "steven", 24, 1000.00 }; //��ʼ��

	//��ֵ
	strcpy_s(worker.name, "yanzhiwen");
	worker.age = 25;
	worker.salary = 10000000;

	//	�������
	//	1. ��������ֽڴ�Сȥ����
	//	2. ���ʱ��ᰴ�ջ������͵����ͼ���
	//	3. ���Ȼ�����е��ֽ������������Ƿ��ܹ����������ֽ�������������������ۼӣ�һֱ�ӵ���������λ��
	int size = sizeof(Worker);
	printf("size=%d\n", size);

	//	jack.age=33;

	printf("name=%s,age=%d,salary=%lf\n", worker.name, worker.age, worker.salary);


	//	printf("name=%s,age=%d,salary=%lf", jack.name, jack.age, jack.salary);

	//2��ͨ���ṹ��ָ��ȥ��������  
	 Worker woker1;
	Worker* worker_p = &woker1;
	worker_p->age = 30;
	strcpy_s(worker_p->name, "stevenyan");
	worker_p->salary = 88888;

	printf("name=%s,age=%d,salary=%lf\n", worker_p->name, worker_p->age, worker_p->salary);

	//3�������ṹ������  

	Worker workers[10] = {};  //������1������̬����
	workers[9] = { "steven9", 1, 100 };
	printf("name=%s,age=%d,salary=%lf\n", workers[9].name, workers[9].age, workers[9].salary);

	//��̬�ڴ濪��Worker* �ṹ��ָ��
	Worker* workers_p = (Worker*)malloc(sizeof(Worker)* 10);
	//��ָ���Ƶ���10��
	workers_p += 9;
	workers_p->age = 22;
	strcpy_s(workers_p->name, "stevenyan");
	workers_p->salary = 88888;
	printf("name=%s,age=%d,salary=%lf\n", workers_p->name, workers_p->age, workers_p->salary);

	//Person person;
	//strcpy_s(person.name, "sss");
	//person.age = 22;
	//printf("name=%s,age=%d\n", person.name, person.age);

	
	getchar();
}