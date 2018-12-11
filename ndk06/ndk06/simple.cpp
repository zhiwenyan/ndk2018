#include<stdio.h>//导入头文件，都是方法的声明 .h,.hpp里面都是方法的声明，.cpp(c++),.c都是方法的实现

void change(int* p){
	*p = 200;
}
void change(int* m, int* n){
	int temp = *m;
	*m = *n;
	*n = temp;
}


void main(){  //函数的主入口
	//printf("Hello World!");
	//基本类型的数据  
	int i = 100;
	double d = 100;
	float f = 100;
	long l = 100;
	short s = 100;
	char c = 'D';
	//输出打印，需要占位符
	printf("i的值是：%d\n",i);
	printf("d的值是：%lf\n", d);
	printf("f的值是：%f\n", f);
	printf("l的值是：%ld\n", l);
	printf("s的值是：%d\n", s);
	printf("c的值是：%c\n", c);


	printf("*********************************************\n");

	//变量的地址：任何的变量（数据）都有地址
	int a = 100;
	//&i 变量的地址
	//通过Debug的调试，我们可以根据地址去查询改地址的数据 int 类型 4字节，sizeof（）获取数据类型所占的字节数  
	printf("i的地址是：%p\n", &a);


	printf("*********************************************\n");

	//指针变量和获取地址的值

	int m = 100;

	printf("m的值是：%d\n", m);
	printf("m的地址值是：%p\n",&m);
	//通过*获取地址的值
	printf("m的值是：%d\n", *(&m));
	//指针（地址）变量 指针存放（指向）的就是变量的地址
	//int* 代表int类型的指针（地址）
	int* p = &m;

	printf("p的值是：%d\n", *p);
	printf("********************************************\n");
	//通过指针修改值
	int n = 100;
	int* p1 = &n;
	//获取指针的值间接修改
	*p1 = 300;
	printf("n的值：%d\n", n);

	//通过方法修改值
	int x = 100;
	printf("x修改前的值：%d\n", x);
	change(&x);
	printf("x修改后的值：%d\n", x);
	printf("*******************************************\n");


	//题目：写个方法对两个值进行交换
	int y = 100;
	int j = 200;
	change(&y, &j);
	printf("y的值：%d\n",y);
	printf("j的值：%d\n", j);

	getchar();
}