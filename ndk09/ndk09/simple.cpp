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
//�ַ�����ȡ //steven
char* substr(char *str,int start, int end){
	//����һ���ַ���ȥ�洢���ǵ�����
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
	//�ַ����Ķ��� 

	//��һ�� �ַ�������
	char str[] = {'s','t','e','v','e','n','\0','1'};
	//�ַ����Ľ�β��'\0'
	printf("%s\n", str);
	//�ڶ���  
	char *str1 = "steven";
	printf("%s\n",str1);

	//���� һ�����޸�char str[] һ�������޸�char *str1.

	//��ȡ�ַ������� strlen
	char *name = "steven is man";
	printf("��ȡ�ַ�������=%d\n", strlen(str));

	//�ַ�������ת�� atoi �������ת����Ϊ0 ���������������ֲ���ת���Ļ����޳� 12xxxx->12
	char *number = "12";
	printf("�ַ�������ת��=%d\n", atoi(number));

	//�ַ����Ƚ�  
	char *ch1 = "Steven";
	char *ch2 = "steven";
	//���ִ�Сдstrcmp �����ִ�Сд c strcmpi c++ _strcmpi android ndk strcasecmp
	int rc = strcmp(ch1, ch2);
	if (rc == 0)
		printf("[%s] equals [%s]\n", ch1, ch2);
	else if (rc < 0)
		printf("[%s] precedes [%s]\n", ch1, ch2);
	else if (rc > 0)
		printf("[%s] follows [%s]\n", ch1,ch2);


	char *sub = "i";
	//�ַ������� ���� ƴ�ӡ����ҡ���ȡ

	//�����ַ�����һ�γ��ֵ�λ�ã�λ��ָ�룩,���û���ҵ�����null
	char* pos = strstr(name, sub);
	printf("%s\n", pos);
	int position = pos - name;
	printf("λ��=%d\n" , position);

	if (pos){
		printf("����");
	}
	else {
		printf("������");
	}
	//�ַ���ƴ��
	

	// char *str2 = strcat(str1,number);
	// printf("strcat=%s\n", str2);

	//�ַ�����ȡ

	char *sub1 = substr(str1, 2, 5);
	printf("�ַ�����ȡ=%s\n", sub1);
	//һ��Ҫfree ����Ϊsub1�Ƕ�̬�����ڴ棬

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