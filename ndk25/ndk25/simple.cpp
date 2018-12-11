#include <iostream>

using namespace std;


//模板函数
template <typename T>
T add(T number1, T number2){
	cout << "模板函数" << endl;
	return number1 + number2;
}

//当普通函数和模板函数同时存在的时候，会优先调用普通函数
//普通函数
int add(int number1, int number2){
	cout << "普通函数" << endl;

	return number1 + number2;

}
//1、编译的时候c和c++编译器会对cpp，c文件会做一些优化（模板函数）
//2、java有small->class ,也会生成c/c++

//so是很难反编译的，比java安全 为啥？
//small 语法


//模板类
template <class T>
class Callback{
public:
	void onError(){}
	void onSuccess(T result){
		cout << result << endl;
	}
};
template <class T>

//模板类继承，子类也是模板类
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