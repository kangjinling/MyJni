#include <jni.h>
#include <string>
#include <string.h>
#include "MD5.h"
#include<stdlib.h>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  __VA_ARGS__)
#define LOG_TAG   "lib_native_log"
#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
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
    // 自定义秘钥
    char* jstr2 = "zha{ng.**]*jiaxc2@[]q9[qa*-_?!~%cha^#=o.co}|";
    //将jstring转化成char *类型
    originStr = env->GetStringUTFChars(str, false);
    //拼接两个字符串
    strcat((char *) originStr, jstr2);
    MD5 md5 = MD5(originStr);
    std::string md5Result = md5.hexdigest();
    // 转换成大写
    transform(md5Result.begin(), md5Result.end(), md5Result.begin(), toupper);

    LOGI("=====",md5Result.c_str());

   // transform(md5Result.begin(), md5Result.end(), md5Result.begin(), ::toupper);
    //将char *类型转化成jstring返回给Java层
    return env->NewStringUTF(md5Result.c_str());
}


