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
} info;// ������һ���ṹ�� ���� info



//typedef struct AndroidBitmapInfo
//{
	//int width;
	//int height;
	//int format;
//};// ������һ���ṹ��ȡ��һ������ AndroidBitmapInfo ���ṹ��������� ����

void AndroidBitmap_getInfo(AndroidBitmapInfo* bitmapInfo){
	// ͨ��ָ���ڷ������渳ֵ
	bitmapInfo->width = 200;
	bitmapInfo->height = 200;
}

void main(){


	int a = 100;

	//�޸�a��ֵ 

	a = 200;
	printf("%p\n", &a);   //200
	
	change1(a); //a������ֵ��ֵ����number������number������һ�������У�number��һ���µı���
	
	printf("a=%d\n",a);

	change2(&a); //a�ĵ�ֵַ��ֵ����number������number������һ�������У�number��һ���µı���

	printf("a=%d\n", a);


	// 2��ָ���Ӹ�ֵ�����壬��ʵ����Ϊ�������������м�Ӹ�ֵ

	//����������ʱ���벻��ָ�룬ָ��������кܶ࣬����һ�־���ͨ������ȥ�޸�ֵ
	change2(&a); 

	//ͨ��ָ��ȥ��ֵ
	// ͨ��ָ���Ӹ�ֵ�ܳ���

	struct AndroidBitmapInfo android_bitmap_info;
	AndroidBitmap_getInfo(&android_bitmap_info);

	printf("width = %d, height = %d", android_bitmap_info.width, android_bitmap_info.height);


	// ����������ʱ���벻��ָ�룬ָ����ֵ������кܶ࣬����һ�־���ͨ������ȥ�޸�ֵ
	// 1.��ȡBitmap��Ϣ
	 //AndroidBitmapInfo android_bitmap_info; // �ṹ��
	// AndroidBitmap_getInfo(env, bitmap, &android_bitmap_info); // ͨ�� getInfo ����ȥ��ȡ Bitmap ������
	// ��ȡbitmap�� ���ߣ�format
	 int bitmap_width = android_bitmap_info.width;
	 int bitmap_height = android_bitmap_info.height;

	// c �� java �ķ�����ͬ���ڣ�c ���Դ�����ĵ�ַ�ڷ�������ȥ��ֵ��java һ�㶼��ͨ������ֵ

	// ģ��һ��ָ�뷽����ֵ��д�����ܳ��ã�
	// java д��
	// AndroidBitmapInfo android_bitmap_info = AndroidBitmap_getInfo(env, bitmap);

	getchar();
}