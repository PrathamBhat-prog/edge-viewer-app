#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "NativeLib"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALLJava_com_example_edgeviewer_MainActivity_stringFromJNI
        (JNIEnv* env, jobject thiz){

    LOGI("JNI function called successfully!");

    std::string message = "Hello from C++ (JNI is working!)";
    return env->NewStringUTF(message.c_str());
}
