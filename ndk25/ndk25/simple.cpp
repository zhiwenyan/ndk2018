#include <iostream>

using namespace std;


//ģ�庯��
template <typename T>
T add(T number1, T number2){
	cout << "ģ�庯��" << endl;
	return number1 + number2;
}

//����ͨ������ģ�庯��ͬʱ���ڵ�ʱ�򣬻����ȵ�����ͨ����
//��ͨ����
int add(int number1, int number2){
	cout << "��ͨ����" << endl;

	return number1 + number2;

}
//1�������ʱ��c��c++���������cpp��c�ļ�����һЩ�Ż���ģ�庯����
//2��java��small->class ,Ҳ������c/c++

//so�Ǻ��ѷ�����ģ���java��ȫ Ϊɶ��
//small �﷨


//ģ����
template <class T>
class Callback{
public:
	void onError(){}
	void onSuccess(T result){
		cout << result << endl;
	}
};
template <class T>

//ģ����̳У�����Ҳ��ģ����
class HttpCallback :public Callback<T>{

};


void main(){
	int sum = add(1, 2);

	Callback<int>* callback = new Callback<int>();
	callback->onSuccess(12);
	HttpCallback<int>* httpCallback = new HttpCallback<int>();
	httpCallback->onSuccess(22);
	getchar();
}