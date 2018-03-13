#include <jni.h>
#include <string>
#include <string.h>
#include "MD5.h"
#include<stdlib.h>
#define LOG_TAG "System.out.c"
#include <cctype>
#include <algorithm>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  __VA_ARGS__)
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_jerome_jni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_jerome_jni_MainActivity_getMd5(JNIEnv *env, jobject, jstring str) {
    const char *originStr;
    //将jstring转化成char *类型
    originStr = env->GetStringUTFChars(str, false);


    MD5 md5 = MD5(originStr);
    std::string md5Result = md5.hexdigest();

    transform(md5Result.begin(), md5Result.end(), md5Result.begin(), toupper);

   // transform(md5Result.begin(), md5Result.end(), md5Result.begin(), ::toupper);
    //将char *类型转化成jstring返回给Java层
    return env->NewStringUTF(md5Result.c_str());
}

char *Join1(char *a, char *b) {
    char *c = (char *) malloc(strlen(a) + strlen(b) + 1); //局部变量，用malloc申请内存
    if (c == NULL) exit (1);
    char *tempc = c; //把首地址存下来
    while (*a != '\0') {
        *c++ = *a++;
    }
    while ((*c++ = *b++) != '\0') {
        ;
    }
    //注意，此时指针c已经指向拼接之后的字符串的结尾'\0' !
    return tempc;//返回值是局部malloc申请的指针变量，需在函数调用结束后free之
}

