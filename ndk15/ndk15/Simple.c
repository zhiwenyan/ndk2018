#include "com_steven_ndk15_Simple1.h"
#include <stdlib.h>

int compare(const int* number1,const int* number2){
	return *number1 - *number2;
}
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_sort
(JNIEnv * env, jclass jclz, jintArray jarray){
	//对jarray 进行排序 

	//void qsort(void * _Base, size_t _NumOfElements, size_t _SizeOfElements, int(* _PtFuncCompare)(const void *, const void *))

	jint* intArray=(*env)->GetIntArrayElements(env, jarray, NULL);
	jint length = (*env)->GetArrayLength(env,jarray);
	//第一个参数：void*数组的首地址  
	//第二个参数: 数组大小的长度
	//第三个参数：数组元素数据类型的大小
	//第四个参数：数组的一个比较方法（Compareable）
	qsort(intArray, length, sizeof(int), compare);
	//0：代表同步给数据给jarray，并且释放资源
	(*env)->ReleaseIntArrayElements(env, jarray, intArray, 0);
	


	//同步数组的数据 给java数组 intArray并不是jarray
}
//Native层构建java对象
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_localRef
(JNIEnv *env, jclass jclz){
	//在native层构建java对象，不用了怎么管理
	//native层开辟的内存由谁管理，你能开辟多大  
	//字符串截取，String对象 
	jclass j_clz = (*env)->FindClass(env, "java/lang/String");
	jmethodID j_mid = (*env)->GetMethodID(env, j_clz, "<init>", "()V");
	jobject j_str = (*env)->NewObject(env, j_clz, j_mid);
	//j_str = "sss";
	//printf("%s\n",j_str);
	//jobject 不在使用了，要回收javaGC的源码
	(*env)->DeleteLocalRef(env, j_str);
	//删除了不能在使用了，c和C++都需要自己释放内存（静态开辟不需要，动态开辟需要）
}

//全局引用
jstring globalRef;
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_saveGlobalRef
(JNIEnv *env, jclass jclz, jstring jstr){
	//保存全局变量,其它方法需要使用

	//NewGlobalRef new一个全局的引用
	globalRef=(*env)->NewGlobalRef(env, jstr);
}
//这个方法需要用到全局引用
JNIEXPORT jstring JNICALL Java_com_steven_ndk15_Simple1_getGlobalRef
(JNIEnv * env, jclass jclz){
	return globalRef;

}
//释放全局引用
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_deleteGlobalRef
(JNIEnv * env, jclass jclz){
	//手动释放下
	(*env)->DeleteGlobalRef(env, globalRef);
}



static  jfieldID j_name_fid = NULL;
static  jfieldID j_name_fid1 = NULL;
static  jfieldID j_name_fid2 = NULL;

//本地的静态缓存
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_staticLocalCache
(JNIEnv *env, jclass j_clz, jstring jstr){
	//本地的静态缓存
	/*static jfieldID j_fieldId = NULL;  //局部缓存，这个方法多次调用，不要反复获取jfieldID
	if (j_fieldId == NULL){
		j_fieldId = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");
	}
	else{
		printf("j_fieldId not null\n");
	} 

	(*env)->SetStaticObjectField(env, j_clz, j_fieldId, jstr);*/

	(*env)->SetStaticObjectField(env, j_clz, j_name_fid, jstr);

}
//全局的静态缓存，在构造函数中初始化的时候会去缓存
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_initStaticCache
(JNIEnv * env, jclass j_clz){
	//初始化
	j_name_fid = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");
	j_name_fid1 = (*env)->GetStaticFieldID(env, j_clz, "name1", "Ljava/lang/String;");
	j_name_fid2 = (*env)->GetStaticFieldID(env, j_clz, "name2", "Ljava/lang/String;");
}


//jni 异常处理
JNIEXPORT void JNICALL Java_com_steven_ndk15_Simple1_exception
(JNIEnv * env, jclass j_clz){
	jfieldID j_fid = (*env)->GetStaticFieldID(env, j_clz, "name3", "Ljava/lang/String;");

	//好几种方式
	//1、补救措施   name3 拿name
	//1 有没有异常
	jthrowable j_throwable=(*env)->ExceptionOccurred(env);
	/*if (j_throwable){
		//有异常，先把异常清除
		printf("有异常！");
		(*env)->ExceptionClear(env);
		//去拿name的值
		j_fid = (*env)->GetStaticFieldID(env, j_clz, "name", "Ljava/lang/String;");

	}*/
	//2、想给java层抛一个异常  
	if (j_throwable){
		printf("有异常！");
		(*env)->ExceptionClear(env);
		//throw 给java层一个throwable异常
		jclass no_such_thtrowable = (*env)->FindClass(env,"java/lang/NoSuchFieldException");
		(*env)->ThrowNew(env, j_clz, "NoSuchFieldException name3");
		return;
	}

	jstring name=	(*env)->NewStringUTF(env,"StevenYan");
	(*env)->SetStaticObjectField(env, j_clz, j_fid, name);

}