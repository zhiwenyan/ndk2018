#include "com_steven_ndk13_Simple1.h"


JNIEXPORT void JNICALL Java_com_steven_ndk13_Simple1_callMethodCallback
(JNIEnv *env, jclass j_clz){
	//去调用GetUUID的方法
	//2、获取jmethodID
	jmethodID j_methid_id = (*env)->GetStaticMethodID(env, j_clz, "getUUID", "()Ljava/lang/String;");
	//1、调用getUUID方法
	jstring j_str=(*env)->CallStaticObjectMethod(env,j_clz, j_methid_id);

	//将java的String转成 c语言的char*
	char* c_uuid = (*env)->GetStringUTFChars(env,j_str,NULL);

	printf("c_uuid=%s\n",c_uuid);
	//释放资源
	(*env)->ReleaseStringChars(env, j_str, c_uuid);
}


JNIEXPORT jobject JNICALL Java_com_steven_ndk13_Simple1_createPoint
(JNIEnv * env, jclass jclz){
	//jclass对象是simple1

	//native构建java层Point对象
	//FindClass 通过全类名找到Point这个class
	jclass point_clz = (*env)->FindClass(env, "com/steven/ndk13/Point");
	//获取够造函数 构建java层的Point对象 构造函数初始<init> (II)V 说明下这个具体是什么意思(II)代表参数是int类型的 V是代表void
	jmethodID j_mid = (*env)->GetMethodID(env, point_clz, "<init>", "(II)V");
	jobject j_point=(*env)->NewObject(env, point_clz, j_mid,11,22);

	
	//练习一下，重新给y赋值，调用set方法
	j_mid = (*env)->GetMethodID(env, point_clz, "setY", "(I)V");
	//CallVoidMethod 调用方法
	(*env)->CallVoidMethod(env, j_point,j_mid, 32);

	//作业：直接给属性赋值
	jfieldID j_field = (*env)->GetFieldID(env, point_clz, "x", "I");

	//jint point_x = (*env)->GetIntField(env,j_point,j_field);
	//point_x = +30;

	(*env)->SetIntField(env, j_point, j_field, 30);
	return j_point;
}

void main(){
	//常量不能修改  
	const int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	//常量指针
	const int* n_p = &number2;
	n_p = &number1;
	printf("n_p=%p",n_p);
	//常量指针的值不能修改的，但是地址可以修改的
	//*n_p = 5;
	//指针常量
	int* const n_p1 = &number1;
	//地址是不能被修改的
	//n_p1 = &number2;  
	//指针常量的值是可以修改的
	*n_p1 = number2;
	getchar();
}