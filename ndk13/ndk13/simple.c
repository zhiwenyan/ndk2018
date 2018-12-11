#include "com_steven_ndk13_Simple1.h"


JNIEXPORT void JNICALL Java_com_steven_ndk13_Simple1_callMethodCallback
(JNIEnv *env, jclass j_clz){
	//ȥ����GetUUID�ķ���
	//2����ȡjmethodID
	jmethodID j_methid_id = (*env)->GetStaticMethodID(env, j_clz, "getUUID", "()Ljava/lang/String;");
	//1������getUUID����
	jstring j_str=(*env)->CallStaticObjectMethod(env,j_clz, j_methid_id);

	//��java��Stringת�� c���Ե�char*
	char* c_uuid = (*env)->GetStringUTFChars(env,j_str,NULL);

	printf("c_uuid=%s\n",c_uuid);
	//�ͷ���Դ
	(*env)->ReleaseStringChars(env, j_str, c_uuid);
}


JNIEXPORT jobject JNICALL Java_com_steven_ndk13_Simple1_createPoint
(JNIEnv * env, jclass jclz){
	//jclass������simple1

	//native����java��Point����
	//FindClass ͨ��ȫ�����ҵ�Point���class
	jclass point_clz = (*env)->FindClass(env, "com/steven/ndk13/Point");
	//��ȡ���캯�� ����java���Point���� ���캯����ʼ<init> (II)V ˵�������������ʲô��˼(II)���������int���͵� V�Ǵ���void
	jmethodID j_mid = (*env)->GetMethodID(env, point_clz, "<init>", "(II)V");
	jobject j_point=(*env)->NewObject(env, point_clz, j_mid,11,22);

	
	//��ϰһ�£����¸�y��ֵ������set����
	j_mid = (*env)->GetMethodID(env, point_clz, "setY", "(I)V");
	//CallVoidMethod ���÷���
	(*env)->CallVoidMethod(env, j_point,j_mid, 32);

	//��ҵ��ֱ�Ӹ����Ը�ֵ
	jfieldID j_field = (*env)->GetFieldID(env, point_clz, "x", "I");

	//jint point_x = (*env)->GetIntField(env,j_point,j_field);
	//point_x = +30;

	(*env)->SetIntField(env, j_point, j_field, 30);
	return j_point;
}

void main(){
	//���������޸�  
	const int number1 = 1;
	int number2 = 2;
	int number3 = 3;
	//����ָ��
	const int* n_p = &number2;
	n_p = &number1;
	printf("n_p=%p",n_p);
	//����ָ���ֵ�����޸ĵģ����ǵ�ַ�����޸ĵ�
	//*n_p = 5;
	//ָ�볣��
	int* const n_p1 = &number1;
	//��ַ�ǲ��ܱ��޸ĵ�
	//n_p1 = &number2;  
	//ָ�볣����ֵ�ǿ����޸ĵ�
	*n_p1 = number2;
	getchar();
}