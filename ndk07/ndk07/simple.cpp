#include<stdio.h>
void add(int num1, int num2){
	printf("num1+num2=%d", (num1 + num2));
}
void mins(int num1, int num2){
	printf("num1-num2=%d", (num1 - num2));
}
/*函数指针（回调）*/
void opreate(void(method)(int,int),int num1,int num2){
	method(num1, num2);
}


//监听数据压缩回调
void call_back(int current, int total){
	printf("压缩的进度%d/%d", current,total);
}
void compress(char* fileName,void(callback)(int,int)){
	callback(12, 24);

}

void main(){

	/**二级指针和多级指针**/
	int num = 12;
	int* p = &num;

	int** s_p = &p;  //对一级指针取地址 

	printf("********************");
	printf("p的值为，s_p的值：%p，%p", p, s_p);  	//0x003afee0,	0x003afed4 {0x003afee0 {12}}	

	//通过二级指针 怎么获取最终的值

	printf("获取最终的的值：%d\n", **s_p);


	/**数组和数组指针（重点）*******************/

	//遍历数组 ，Linux系统上会有问题
	int arr[] = { 1, 2, 3, 4 };
	for (int i = 0; i < 4; i++){
		printf("%d\n", arr[i]);

	}
	// c、c++正确的写法
	int i = 0;
	for (; i < 4; i++){
		printf("%d\n", arr[i]);

	}
	printf("arr=%p\n", arr);
	printf("&arr=%p\n", &arr);
	printf("arr[0]的地址%p\n", &arr[0]);


	//如何获取数组的指针  
	int* arr_p = arr; //数组指针指的是首地址
	//做一系列的操作 
	printf("*arr_p=%d\n", *arr_p);
	//对指针进行++
	arr_p++;

	printf("*arr_p=%d\n", *arr_p);


	/**采用指针遍历数组循环赋值**/

	int arr1[] = { 1, 2, 3, 4 };
	int* arr_p1 = arr1;

	int j = 0;
	for (; j < 4; j++){
		printf("%d\n", *(arr_p1 + j));

	}


	int arr2[4];
	int* arr_p2 = arr2;
	for (int i = 0; i < 4; i++){
		*(arr_p2 + i) = i;
	}

	int m = 0;
	for (; m < 4; m++){
		printf("%d\n", *(arr_p2 + m));

	}

	/**指针和数组的几种写法**/

	int arr3[] = { 11, 22, 33, 44 };

	int* arr_p3 = arr3;

	int n = 0;
	for (; n < 4; n++){
		printf("%d\n", *(arr3 + n));
		printf("%d\n", arr_p3[n]);

	}

	/*指针为什么要有类型？指针就是一块地址*/
	/*函数指针（回调）*/

	//add(1, 2);
	//方法指针怎么定义？方法的返回（方法的名称）（方法的参数）


	opreate(add,1, 2);
	opreate(mins,1, 2);

	compress("1.png",call_back);
	getchar(); //暂停


}