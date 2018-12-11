#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void main(){
	cout << "********vector******************" << endl;

	vector<int> v1;
	//插入数据  v1.begin()迭代器开始位置 
	v1.insert(v1.begin(),12);
	v1.insert(v1.begin(), 22);
	v1.insert(v1.begin(), 42);

	v1.insert(v1.end(), 88);
	//引用左值
	v1.front() = 99;
	//最后
	v1.back() = 66;

	v1.push_back(55);
	//移除最后一个元素，并没有返回值
	v1.pop_back();
	//获取数据  
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << endl;

	}
	cout  << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << endl;

	}
	cout << endl;

	vector<int>::const_iterator c_iter = v1.begin();   //获取const类型迭代器
	for (; c_iter != v1.end(); c_iter++)
	{
		cout << *c_iter << endl;
	}

	cout << "********stack******************" << endl;

	stack<int> s;
	//压栈
	s.push(1);
	s.push(2);
	s.push(3);

	//循环 迭代器、下标都不支持   
	//for (int i = 0; i < s.size(); i++){

	//}
	//返回栈顶元素
	int top = s.top();
	cout << top << endl;
	/*while (!s.empty()){
		int top = s.top;
		cout << top << endl;
		s.pop();
	}*/
	cout << "********queue******************" << endl;
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	q.front() = 6;
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	getchar();
}