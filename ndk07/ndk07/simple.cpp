#include<stdio.h>
void add(int num1, int num2){
	printf("num1+num2=%d", (num1 + num2));
}
void mins(int num1, int num2){
	printf("num1-num2=%d", (num1 - num2));
}
/*����ָ�루�ص���*/
void opreate(void(method)(int,int),int num1,int num2){
	method(num1, num2);
}


//��������ѹ���ص�
void call_back(int current, int total){
	printf("ѹ���Ľ���%d/%d", current,total);
}
void compress(char* fileName,void(callback)(int,int)){
	callback(12, 24);

}

void main(){

	/**����ָ��Ͷ༶ָ��**/
	int num = 12;
	int* p = &num;

	int** s_p = &p;  //��һ��ָ��ȡ��ַ 

	printf("********************");
	printf("p��ֵΪ��s_p��ֵ��%p��%p", p, s_p);  	//0x003afee0,	0x003afed4 {0x003afee0 {12}}	

	//ͨ������ָ�� ��ô��ȡ���յ�ֵ

	printf("��ȡ���յĵ�ֵ��%d\n", **s_p);


	/**���������ָ�루�ص㣩*******************/

	//�������� ��Linuxϵͳ�ϻ�������
	int arr[] = { 1, 2, 3, 4 };
	for (int i = 0; i < 4; i++){
		printf("%d\n", arr[i]);

	}
	// c��c++��ȷ��д��
	int i = 0;
	for (; i < 4; i++){
		printf("%d\n", arr[i]);

	}
	printf("arr=%p\n", arr);
	printf("&arr=%p\n", &arr);
	printf("arr[0]�ĵ�ַ%p\n", &arr[0]);


	//��λ�ȡ�����ָ��  
	int* arr_p = arr; //����ָ��ָ�����׵�ַ
	//��һϵ�еĲ��� 
	printf("*arr_p=%d\n", *arr_p);
	//��ָ�����++
	arr_p++;

	printf("*arr_p=%d\n", *arr_p);


	/**����ָ���������ѭ����ֵ**/

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

	/**ָ�������ļ���д��**/

	int arr3[] = { 11, 22, 33, 44 };

	int* arr_p3 = arr3;

	int n = 0;
	for (; n < 4; n++){
		printf("%d\n", *(arr3 + n));
		printf("%d\n", arr_p3[n]);

	}

	/*ָ��ΪʲôҪ�����ͣ�ָ�����һ���ַ*/
	/*����ָ�루�ص���*/

	//add(1, 2);
	//����ָ����ô���壿�����ķ��أ����������ƣ��������Ĳ�����


	opreate(add,1, 2);
	opreate(mins,1, 2);

	compress("1.png",call_back);
	getchar(); //��ͣ


}