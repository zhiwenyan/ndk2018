#include <stdio.h>
#include <string.h>
#include <malloc.h>


struct Worker{  //定义一个结构体，相当于java的class
	char name[18]; //10
 	int age;   //4
	double salary;  //8
}; 
struct Worker1{  //定义一个结构体，相当于java的class
	char name[10];
    int age;
    double salary;
}steven{ "zhiwen", 22, 10000 }, jack{ "jack", 20, 100000 }; //直接赋值


struct Worker2{  //定义一个结构体，相当于java的class
	char name[10];
	int age;
	double salary;
}worker2;  //变量名



//结构体和结构体指针取别名  
typedef Worker worker_;
typedef Worker* worker_p;

// 5 联合体的定义和使用 

union Person
{
	char name[10];
	int age;
};


//6 枚举的定义和使用  

enum  CommentType
{
	TEXT=10,TEXT_IMAGE
};

void main(){
	//计算的规则：
	//1、按照最大的字节去计算   2、算的时候只会按照基本类型去计算 3、首先所有的字节数加来，是否能够整除属性最大字节数，不够网上累加
	int size1 = sizeof(Worker);
	printf("%d\n", size1);


	CommentType comment = TEXT;
	printf("%d\n",comment);

	printf("%s\n", steven.name);

	worker2.age = 88;
	printf("%d\n", worker2.age);


	
	//	1、结构体的定义和使用
	 Worker worker = { "steven", 24, 1000.00 }; //初始化

	//赋值
	strcpy_s(worker.name, "yanzhiwen");
	worker.age = 25;
	worker.salary = 10000000;

	//	计算规则：
	//	1. 按照最大字节大小去计算
	//	2. 算的时候会按照基本类型的类型计算
	//	3. 首先会把所有的字节数加起来，是否能够整除最大的字节数，如果不够会往上累加，一直加到能整除的位置
	int size = sizeof(Worker);
	printf("size=%d\n", size);

	//	jack.age=33;

	printf("name=%s,age=%d,salary=%lf\n", worker.name, worker.age, worker.salary);


	//	printf("name=%s,age=%d,salary=%lf", jack.name, jack.age, jack.salary);

	//2、通过结构体指针去操作数据  
	 Worker woker1;
	Worker* worker_p = &woker1;
	worker_p->age = 30;
	strcpy_s(worker_p->name, "stevenyan");
	worker_p->salary = 88888;

	printf("name=%s,age=%d,salary=%lf\n", worker_p->name, worker_p->age, worker_p->salary);

	//3、创建结构体数组  

	Worker workers[10] = {};  //创建了1个，静态开辟
	workers[9] = { "steven9", 1, 100 };
	printf("name=%s,age=%d,salary=%lf\n", workers[9].name, workers[9].age, workers[9].salary);

	//动态内存开辟Worker* 结构体指针
	Worker* workers_p = (Worker*)malloc(sizeof(Worker)* 10);
	//把指针移到第10个
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