//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XLOG_H
#define VIDEOPLAYER_XLOG_H
class XLog {
};
#ifdef ANDROID
#include <android/log.h>
#define XLOGE(...) __android_log_print(ANDROID_LOG_ERROR,"VideoPlayer",__VA_ARGS__)
#else
#define XLOGE(...) printf("VideoPlayer",__VA_ARGS__)
#endif
#endif //VIDEOPLAYER_XLOG_H
