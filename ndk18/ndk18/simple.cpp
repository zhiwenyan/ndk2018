#include <stdio.h>
#include <stdlib.h>



void setName(char** str){
	*str = "steven";
	//ָ��������ϸ�ֵ���ı����ָ���ָ��

}

/*void main(){

	// 1��ָ��ʹ�õ�ע������  
	char* name = "Steven";
	char* tempName = name;

	//�����ӡ  
	for (int i = 0; i < 6; i++){
		printf("%c\n", *tempName);
		tempName++;

	}

	printf("name=%s\n", name);

	//д����û������
	char* str = NULL;
	//ǿ��һ�����ָ�������ָ����ָ����ڴ������������ͬ�ĸ���

	setName(&str);

	printf("str=%s\n",str);
	getchar();
}*/

//const �ؼ��� ��c��c++ �������� 

/*void main(){
	//����
	const int number = 100;
	printf("number=%s\n", number);

	//����ָ��(����ָ��ĳ����ǲ����޸ĵ�)
	const int* number_p = &number;

	//*number_p = number;

	//ָ�볣��(ֵ���ܸģ�ָ��Ҳ���ɸ�)
	int number3;
	int* const number3 = &number3;




	getchar();
}*/

void print(char** str, int length){
	for (int i = 0; i < length; i++)
	{
		printf("%s\n", str[i]);

	}
}

//����ָ����ڴ�ģ��  �����Կ�����ά���飩
//ָ�����飺����ָ��ָ���������Ԫ���׵�ַ
void main(){
	char* name = "steven";
	char** nameP = &name;
	
	//���������ַ�����������
	//��һ�ֶ��巽ʽ  
	//char** username = {"aa","bb"};

	char* username[10] = { { "aaa" }, {"bbb"} };
	for (int i = 0; i <2; i++)
	{
		printf("%s\n",username[i]);
	}
	print(username, 2);

	//�ڶ��ֶ��巽ʽ �����ά����
	char username1[10][30] = { { "aaa" }, { "bbb" }, { "ccc" } };

	for (int i = 0; i <3; i++)
	{
		printf("%s\n", username1[i]);
	}

	//print(username1, 3); //Ϊʲô���У������ָ��Ĳ�����һ��

	getchar();
}


