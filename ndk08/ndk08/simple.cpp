#include <stdlib.h> 
#include <stdio.h> 
#include <windows.h>
void staticlloc(){
	int j = 0;
	int arr1[5]; //��̬����
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

	//Stack Overflow ջ��� ����ж�һ���ڴ�����û��д������ ��NULL����Խ��
	int arr[(int)((0.2) * 1024 * 1024)];//ռ���˶����ڴ棿 intռ����4���ֽ� 40M
	//�ص㣺�ڴ濪��
	//c �з��� ����ģ�ͣ�ջ �� 
	//ջ��ռ���ڴ�ռ�Ĵ�С  2M  �����ڴ�ķ�ʽ�Ǿ�̬�ڴ濪�� int arr[(int)((0.2) * 1024 * 1024)]���������պ��Զ����� 
	//�ѣ�ռ���ڴ�ռ����ֵ 80%  �����ڴ�ķ�ʽ�Ƕ�̬�ڴ濪�� �����Զ�������Ҫ�ֶ����գ��ڴ治��ʹ������Ҫ�ֶ����գ�
	while(true){
		Sleep(100);
		staticlloc();

	}
	//��̬�����ڴ�
	int* arr2=(int*)malloc(10*1024*1024*sizeof(int));

	//��һ����Ҫ�ķ������ֶ��ͷ�  free
	free(arr2);
	getchar();

}

