#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){

	/*//��һ���ļ� ���ļ�����ģʽ��
	char* fileName = "C:\\Users\\fumi_it1\\Desktop\\test.txt";
	FILE* fp = fopen(fileName, "r");

	if (!fp){
		printf("�ļ���ʧ�ܣ�");
		//�˳�����
		exit(0);
	}
	char buffer[10];
	//������buffer ����10���ļ�ָ��
	while (fgets(buffer,10,fp)){
		printf("%s",buffer);
	}
	//�ر��ļ�
	fclose(fp);*/


	//�ļ��ĸ���  

	/*char* fileName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle.png";
	char* fileCopyName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle1.png";


	FILE *file = fopen(fileName, "rb");// ��ָ��
	FILE *file_copy = fopen(fileCopyName, "wb");// �½�һ���ļ� 0kb 

	if (!file || !file_copy){
		printf("�ļ���ʧ��");
		exit(0);// �˳�����
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

	//��ȡ�ļ���С
	char* fileName = "C:\\Users\\fumi_it1\\Desktop\\TheadLifeCycle.png";

	FILE *file = fopen(fileName, "rb");// ��ָ��

	if (!file){
		printf("�ļ���ʧ��");
		exit(0);// �˳�����
	}
	// û��һ�������ǿ���ֱ�����ļ���С
	// ˼·�����ļ���ָ���ƶ������Ȼ����ȥ����ƫ����
	// ��������  SEEK_SET����ͷ��, SEEK_CUR����ǰ��, SEEK_END���ƶ������
	fseek(file, 0, SEEK_END);

	// ����ƫ�Ƶ�λ��,ftell �� 0 ��ʼͳ�Ƶ���ǰ��SEEK_END��
	long file_size = ftell(file);

	printf("�ļ���С��%ld", file_size);

	fclose(file);
	getchar();
}