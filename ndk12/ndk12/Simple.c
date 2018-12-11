//����ͷ�ļ�
#include "com_steven_ndk12_NDKSimple.h"
#include "com_steven_ndk12_NDKSimple1.h"


//JNIEXPORT jni ������һ���ؼ��֣������٣�������ͨ�������Ϊ�÷��������ⲿ����
//jstring ����java�е�String 
//JNICALL Ҳ��һ���ؼ��� �����ٵ� ����jni����
//JNIEnv �����c��java���໥���õ�����
//jobject java���������Ķ��󣬾��Ǳ���Ŀ��JniSimple Java�еĶ���
//jclass java����������class����
JNIEXPORT jstring JNICALL Java_com_steven_ndk12_NDKSimple_getSingnturePassword
(JNIEnv * env, jobject jobj){
	return (*env)->NewStringUTF(env, "fumi88");
}

JNIEXPORT void JNICALL Java_com_steven_ndk12_NDKSimple1_changeName
(JNIEnv * env, jobject jobj){
	// ��ȡ name ����Ȼ���޸�Ϊ Jac
	// 3.��ȡ jclass 
	jclass j_clz = (*env)->GetObjectClass(env, jobj);
	// ��ȡ jfieldId (JNIEnv *env, jclass clazz, const char *name, const char *sig)
	// name ��ȡ�ĸ����Ե������� 
	// 2.sig ���Ե�ǩ��  Ljava/lang/String; �ֶ�������
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");
	
	// 1.��ȡ name ���Ե�ֵ
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// ��ӡ�ַ��� jstring -> c_str
	char* c_str = (*env)->GetStringUTFChars(env, j_str, NULL);

	printf("name is %s", c_str);

	// �޸ĳ� jack
	jstring jackName = (*env)->NewStringUTF(env, "Jack");
	(*env)->SetObjectField(env, jobj, j_fid, jackName);
}
JNIEXPORT void JNICALL Java_com_steven_ndk12_NDKSimple1_changeAge
(JNIEnv * env, jclass jclz){
	//���Ȼ�ȡԭ����ageֵ

	jfieldID j_fid = (*env)->GetStaticFieldID(env, jclz, "age", "I");

	//static��ȡ��̬��
	int old_age=(*env)->GetStaticIntField(env, jclz, j_fid);

	//jint->int
	old_age += 12;
	//��̬������ֵ
	(*env)->SetStaticIntField(env,jclz,j_fid,old_age);

}