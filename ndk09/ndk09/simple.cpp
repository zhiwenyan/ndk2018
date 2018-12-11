#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strlen_(char *str){
	int length = 0;
	while (*str != '\0'){
		str++;
		length++;
	}
	return length;
}
//字符串截取 //steven
char* substr(char *str,int start, int end){
	//开辟一个字符串去存储我们的数据
	int length = end - start;
	str += start;
	char  *sub = (char*)malloc(length*sizeof(char));
	for (int i = 0; i < length; i++){
		sub[i] = *str;
		str++;
	}
	sub[length] = '\0';
	return sub;
}
void lower(char *dest,char *source){

}
void main(){
	//字符串的定义 

	//第一种 字符串数组
	char str[] = {'s','t','e','v','e','n','\0','1'};
	//字符串的结尾是'\0'
	printf("%s\n", str);
	//第二种  
	char *str1 = "steven";
	printf("%s\n",str1);

	//区别 一个能修改char str[] 一个不能修改char *str1.

	//获取字符串长度 strlen
	char *name = "steven is man";
	printf("获取字符串长度=%d\n", strlen(str));

	//字符串类型转换 atoi 如果不能转换就为0 后面其它不是数字不能转换的话会剔除 12xxxx->12
	char *number = "12";
	printf("字符串类型转换=%d\n", atoi(number));

	//字符串比较  
	char *ch1 = "Steven";
	char *ch2 = "steven";
	//区分大小写strcmp 不区分大小写 c strcmpi c++ _strcmpi android ndk strcasecmp
	int rc = strcmp(ch1, ch2);
	if (rc == 0)
		printf("[%s] equals [%s]\n", ch1, ch2);
	else if (rc < 0)
		printf("[%s] precedes [%s]\n", ch1, ch2);
	else if (rc > 0)
		printf("[%s] follows [%s]\n", ch1,ch2);


	char *sub = "i";
	//字符串查找 包含 拼接、查找、截取

	//返回字符串第一次出现的位置（位置指针）,如果没有找到返回null
	char* pos = strstr(name, sub);
	printf("%s\n", pos);
	int position = pos - name;
	printf("位置=%d\n" , position);

	if (pos){
		printf("包含");
	}
	else {
		printf("不包含");
	}
	//字符串拼接
	

	// char *str2 = strcat(str1,number);
	// printf("strcat=%s\n", str2);

	//字符串截取

	char *sub1 = substr(str1, 2, 5);
	printf("字符串截取=%s\n", sub1);
	//一定要free ，因为sub1是动态开辟内存，

	char* ch = "ssss";
	printf("%s\n", ch);


	free(sub1);

	char* ch11 = "s";
	char* ch22 = "s";
	if (ch11 == ch22){
		printf("=");
	}

	getchar();
}