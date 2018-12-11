#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){

	/*//打开一个文件 （文件名，模式）
	char* fileName = "C:\\Users\\fumi_it1\\Desktop\\test.txt";
	FILE* fp = fopen(fileName, "r");

	if (!fp){
		printf("文件打开失败！");
		//退出程序
		exit(0);
	}
	char buffer[10];
	//缓冲区buffer 长度10，文件指针
	while (fgets(buffer,10,fp)){
		printf("%s",buffer);
	}
	//关闭文件
	fclose(fp);*/


	//文件的复制  

	/*char* fileName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle.png";
	char* fileCopyName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle1.png";


	FILE *file = fopen(fileName, "rb");// 流指针
	FILE *file_copy = fopen(fileCopyName, "wb");// 新建一个文件 0kb 

	if (!file || !file_copy){
		printf("文件打开失败");
		exit(0);// 退出程序
	}

	// size_t fread(void          *buffer, size_t size, size_t count, FILE          *stream);
	int buffer[512];// 2048 = 4*514
	int len;
	printf("%d", sizeof buffer);
	while ((len = fread(buffer, sizeof(int), 512, file)) != 0){
		fwrite(buffer, sizeof(int), len, file_copy);
	}

	fclose(file);
	fclose(file_copy);*/

	//获取文件大小
	char* fileName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle.png";

	FILE *file = fopen(fileName, "rb");// 流指针

	if (!file){
		printf("文件打开失败");
		exit(0);// 退出程序
	}
	// 没有一个函数是可以直接拿文件大小
	// 思路：将文件的指针移动到最后，然后再去计算偏移量
	// 三个参数  SEEK_SET（开头）, SEEK_CUR（当前）, SEEK_END（移动到最后）
	fseek(file, 0, SEEK_END);

	// 计算偏移的位置,ftell 从 0 开始统计到当前（SEEK_END）
	long file_size = ftell(file);

	printf("文件大小：%ld", file_size);

	fclose(file);
	getchar();
}