#include <stdlib.h> 
#include <stdio.h> 
#include <windows.h>
void staticlloc(){
	int j = 0;
	int arr1[5]; //静态开辟
	for (; j < 5; j++){
		arr1[j] = j;
		printf("%d,%p\n", *(arr1 + j), (arr1 + j));
	}
}
void main(void)
{
	int i;

	printf("Ten random numbers from 0 to 99\n\n");
	for (i = 0; i<10; i++)
		printf("%d\n", rand() % 100);

	//Stack Overflow 栈溢出 如何判断一块内存中有没有写入数据 判NULL，判越界
	int arr[(int)((0.2) * 1024 * 1024)];//占用了多少内存？ int占用了4个字节 40M
	//重点：内存开辟
	//c 有分区 四驱模型，栈 堆 
	//栈：占用内存空间的大小  2M  开辟内存的方式是静态内存开辟 int arr[(int)((0.2) * 1024 * 1024)]，方法回收后自动回收 
	//堆：占用内存空间最大值 80%  开辟内存的方式是动态内存开辟 不会自动回收需要手动回收（内存不在使用是需要手动回收）
	while(true){
		Sleep(100);
		staticlloc();

	}
	//动态开辟内存
	int* arr2=(int*)malloc(10*1024*1024*sizeof(int));

	//第一个重要的方法：手动释放  free
	free(arr2);
	getchar();

}

