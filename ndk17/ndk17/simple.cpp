#include <stdio.h>
void change1(int number){
	number = 300;

	printf("%p\n", &number);
}


void change2(int* number){
	*number = 300;
}

struct AndroidBitmapInfo
{
	int width;
	int height;
	int format;
} info;// 定义了一个结构体 变量 info



//typedef struct AndroidBitmapInfo
//{
	//int width;
	//int height;
	//int format;
//};// 定义了一个结构体取了一个别名 AndroidBitmapInfo ，结构体的名字是 匿名

void AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
	// 通过指针在方法里面赋值
	bitmapInfo->width = 200;
	bitmapInfo->height = 200;
}

void main(){


	int a = 100;

	//修改a的值 

	a = 200;
	printf("%p\n", &a);   //200
	
	change1(a); //a变量的值赋值给了number变量，number是在另一个函数中，number是一个新的变量
	
	printf("a=%d\n",a);

	change2(&a); //a的地址值赋值给了number变量，number是在另一个函数中，number是一个新的变量

	printf("a=%d\n", a);


	// 2、指针间接赋值的意义，其实就是为了在其它方法中间接赋值

	//在做开发的时候，离不开指针，指针的意义有很多，其中一种就是通过方法去修改值
	change2(&a); 

	//通过指针去赋值
	// 通过指针间接赋值很常见

	struct AndroidBitmapInfo android_bitmap_info;
	AndroidBitmap_getInfo(&android_bitmap_info);

	printf("width = %d, height = %d", android_bitmap_info.width, android_bitmap_info.height);


	// 在做开发的时候，离不开指针，指针出现的意义有很多，其中一种就是通过方法去修改值
	// 1.获取Bitmap信息
	 //AndroidBitmapInfo android_bitmap_info; // 结构体
	// AndroidBitmap_getInfo(env, bitmap, &android_bitmap_info); // 通过 getInfo 方法去获取 Bitmap 的属性
	// 获取bitmap的 宽，高，format
	 int bitmap_width = android_bitmap_info.width;
	 int bitmap_height = android_bitmap_info.height;

	// c 和 java 的方法不同所在，c 可以传对象的地址在方法里面去赋值，java 一般都是通过返回值

	// 模拟一下指针方法赋值的写法（很常用）
	// java 写法
	// AndroidBitmapInfo android_bitmap_info = AndroidBitmap_getInfo(env, bitmap);

	getchar();
}