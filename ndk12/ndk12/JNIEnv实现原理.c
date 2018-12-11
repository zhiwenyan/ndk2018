#include <stdlib.h>
#include <stdio.h>

//定义一个结构体指针别名
typedef const struct JNINativeInterface *JNIEnv;

//模拟一个结构体
struct JNINativeInterface
{
	//结构体的方法指针
	char*(*NewStringUTF)(JNIEnv*, char*);

};
char* NewStringUTF(JNIEnv* env, char* c_str){
	return c_str;
}
char*  Java_com_steven_getSingnturePassword(JNIEnv* env){
	return (*env)->NewStringUTF(env, "fumi88");

}
void main(){

	//构建JNIEnv* 对象
	struct JNINativeInterface nativeInterface;
	nativeInterface.NewStringUTF=NewStringUTF;
	//传给Java_com_steven_ndk12_NDKSimple_getSingnturePassword的参数是JNIEnv*
	JNIEnv env = &nativeInterface;  //一级指针
	JNIEnv* jniEnv = &env;  //二级指针
	//把 jniEnv对象传给 Java_com_steven_getSingnturePassword
	char* jstring = Java_com_steven_getSingnturePassword(jniEnv);
	//jstring 通过JNIEnv 传给Java层
	printf("jstring=%s\n",jstring);
	getchar();
}