#include "com_steven_ndk15_Simple1.h"
#include <stdlib.h>

int compare(const int* number1,const int* number2){
	return *number1 - *number2;
}
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_sort
(JNIEnv * env, jclass jclz, jintArray jarray){
	//��jarray �������� 

	//void qsort(void * _Base, size_t _NumOfElements, size_t _SizeOfElements, int(* _PtFuncCompare)(const void *, const void *))

	jint* intArray=(*env)->GetIntArrayElements(env, jarray, NULL);
	jint length = (*env)->GetArrayLength(env,jarray);
	//��һ��������void*������׵�ַ  
	//�ڶ�������: �����С�ĳ���
	//����������������Ԫ���������͵Ĵ�С
	//���ĸ������������һ���ȽϷ�����Compareable��
	qsort(intArray, length, sizeof(int), compare);
	//0������ͬ�������ݸ�jarray�������ͷ���Դ
	(*env)->ReleaseIntArrayElements(env, jarray, intArray, 0);
	


	//ͬ����������� ��java���� intArray������jarray
}
//Native�㹹��java����
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_localRef
(JNIEnv *env, jclass jclz){
	//��native�㹹��java���󣬲�������ô����
	//native�㿪�ٵ��ڴ���˭�������ܿ��ٶ��  
	//�ַ�����ȡ��String���� 
	jclass j_clz = (*env)->FindClass(env, "java/lang/String");
	jmethodID j_mid = (*env)->GetMethodID(env, j_clz, "<init>", "()V");
	jobject j_str = (*env)->NewObject(env, j_clz, j_mid);
	//j_str = "sss";
	//printf("%s\n",j_str);
	//jobject ����ʹ���ˣ�Ҫ����javaGC��Դ��
	(*env)->DeleteLocalRef(env, j_str);
	//ɾ���˲�����ʹ���ˣ�c��C++����Ҫ�Լ��ͷ��ڴ棨��̬���ٲ���Ҫ����̬������Ҫ��
}

//ȫ������
jstring globalRef;
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_saveGlobalRef
(JNIEnv *env, jclass jclz, jstring jstr){
	//����ȫ�ֱ���,����������Ҫʹ��

	//NewGlobalRef newһ��ȫ�ֵ�����
	globalRef=(*env)->NewGlobalRef(env, jstr);
}
//���������Ҫ�õ�ȫ������
JNIEXPORT jstring JNICALL Java_com_steven_ndk15_Simple1_getGlobalRef
(JNIEnv * env, jclass jclz){
	return globalRef;

}
//�ͷ�ȫ������
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_deleteGlobalRef
(JNIEnv * env, jclass jclz){
	//�ֶ��ͷ���
	(*env)->DeleteGlobalRef(env, globalRef);
}



static  jfieldID j_name_fid = NULL;
static  jfieldID j_name_fid1 = NULL;
static  jfieldID j_name_fid2 = NULL;

//���صľ�̬����
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_staticLocalCache
(JNIEnv *env, jclass j_clz, jstring jstr){
	//���صľ�̬����
	/*static jfieldID j_fieldId = NULL;  //�ֲ����棬���������ε��ã���Ҫ������ȡjfieldID
	if (j_fieldId == NULL){
		j_fieldId = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");
	}
	else{
		printf("j_fieldId not null\n");
	} 

	(*env)->SetStaticObjectField(env, j_clz, j_fieldId, jstr);*/

	(*env)->SetStaticObjectField(env, j_clz, j_name_fid, jstr);

}
//ȫ�ֵľ�̬���棬�ڹ��캯���г�ʼ����ʱ���ȥ����
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_initStaticCache
(JNIEnv * env, jclass j_clz){
	//��ʼ��
	j_name_fid = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");
	j_name_fid1 = (*env)->GetStaticFieldID(env, j_clz, "name1", "Ljava/lang/String;");
	j_name_fid2 = (*env)->GetStaticFieldID(env, j_clz, "name2", "Ljava/lang/String;");
}


//jni �쳣����
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_exception
(JNIEnv * env, jclass j_clz){
	jfieldID j_fid = (*env)->GetStaticFieldID(env, j_clz, "name3", "Ljava/lang/String;");

	//�ü��ַ�ʽ
	//1�����ȴ�ʩ   name3 ��name
	//1 ��û���쳣
	jthrowable j_throwable=(*env)->ExceptionOccurred(env);
	/*if (j_throwable){
		//���쳣���Ȱ��쳣���
		printf("���쳣��");
		(*env)->ExceptionClear(env);
		//ȥ��name��ֵ
		j_fid = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");

	}*/
	//2�����java����һ���쳣  
	if (j_throwable){
		printf("���쳣��");
		(*env)->ExceptionClear(env);
		//throw ��java��һ��throwable�쳣
		jclass no_such_thtrowable = (*env)->FindClass(env,"java/lang/NoSuchFieldException");
		(*env)->ThrowNew(env, j_clz, "NoSuchFieldException name3");
		return;
	}

	jstring name=	(*env)->NewStringUTF(env,"StevenYan");
	(*env)->SetStaticObjectField(env, j_clz, j_fid, name);

}