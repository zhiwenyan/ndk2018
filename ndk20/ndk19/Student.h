class Student{
private:    //私有 包装  影响下面所有的属性
	char* name;
	int age;



public:
	void setAge(int age);
	void setName(char* name);
	int getAge();
	char* getName();
	};