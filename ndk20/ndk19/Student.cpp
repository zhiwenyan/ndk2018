#include "Student.h"
//дʵ��
void Student::setAge(int age){
	this->age = age;
}
void Student::setName(char* name){
	this->name = name;
}
int Student::getAge(){
	return this->age;
}
char* Student::getName(){
	return this->name;
}