#include <stdlib.h>
#include <stdio.h>

//����һ���ṹ��ָ�����
typedef const struct JNINativeInterface *JNIEnv;

//ģ��һ���ṹ��
struct JNINativeInterface
{
	//�ṹ��ķ���ָ��
	char*(*NewStringUTF)(JNIEnv*, char*);

};
char* NewStringUTF(JNIEnv* env, char* c_str){
	return c_str;
}
char*  Java_com_steven_getSingnturePassword(JNIEnv* env){
	return (*env)->NewStringUTF(env, "fumi88");

}
void main(){

	//����JNIEnv* ����
	struct JNINativeInterface nativeInterface;
	nativeInterface.NewStringUTF=NewStringUTF;
	//����Java_com_steven_ndk12_NDKSimple_getSingnturePassword�Ĳ�����JNIEnv*
	JNIEnv env = &nativeInterface;  //һ��ָ��
	JNIEnv* jniEnv = &env;  //����ָ��
	//�� jniEnv���󴫸� Java_com_steven_getSingnturePassword
	char* jstring = Java_com_steven_getSingnturePassword(jniEnv);
	//jstring ͨ��JNIEnv ����Java��
	printf("jstring=%s\n",jstring);
	getchar();
}