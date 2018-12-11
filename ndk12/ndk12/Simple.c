//引入头文件
#include "com_steven_ndk12_NDKSimple.h"
#include "com_steven_ndk12_NDKSimple1.h"


//JNIEXPORT jni 开发的一个关键字，不能少（编译能通过）标记为该方法可以外部调用
//jstring 代表java中的String 
//JNICALL 也是一个关键字 可以少的 代表jni调用
//JNIEnv 这个是c和java的相互调用的桥梁
//jobject java传递下来的对象，就是本项目中JniSimple Java中的对象
//jclass java传递下来的class对象
JNIEXPORT jstring JNICALL Java_com_steven_ndk12_NDKSimple_getSingnturePassword
(JNIEnv * env, jobject jobj){
	return (*env)->NewStringUTF(env, "fumi88");
}

JNIEXPORT void JNICALL Java_com_steven_ndk12_NDKSimple1_changeName
(JNIEnv * env, jobject jobj){
	// 获取 name 属性然后修改为 Jac
	// 3.获取 jclass 
	jclass j_clz = (*env)->GetObjectClass(env, jobj);
	// 获取 jfieldId (JNIEnv *env, jclass clazz, const char *name, const char *sig)
	// name 获取哪个属性的属性名 
	// 2.sig 属性的签名  Ljava/lang/String; 字段描述符
	jfieldID j_fid = (*env)->GetFieldID(env, j_clz, "name", "Ljava/lang/String;");
	
	// 1.获取 name 属性的值
	jstring j_str = (*env)->GetObjectField(env, jobj, j_fid);

	// 打印字符串 jstring -> c_str
	char* c_str = (*env)->GetStringUTFChars(env, j_str, NULL);

	printf("name is %s", c_str);

	// 修改成 jack
	jstring jackName = (*env)->NewStringUTF(env, "Jack");
	(*env)->SetObjectField(env, jobj, j_fid, jackName);
}
JNIEXPORT void JNICALL Java_com_steven_ndk12_NDKSimple1_changeAge
(JNIEnv * env, jclass jclz){
	//首先获取原来的age值

	jfieldID j_fid = (*env)->GetStaticFieldID(env, jclz, "age", "I");

	//static获取静态的
	int old_age=(*env)->GetStaticIntField(env, jclz, j_fid);

	//jint->int
	old_age += 12;
	//静态的属性值
	(*env)->SetStaticIntField(env,jclz,j_fid,old_age);

}