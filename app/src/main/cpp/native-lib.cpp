#include <jni.h>
#include <string>
extern "C" {
#include "libavcodec/avcodec.h"
JNIEXPORT jstring JNICALL
Java_com_opengl_videoplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    hello+=avcodec_configuration();
    return env->NewStringUTF(hello.c_str());
}
}