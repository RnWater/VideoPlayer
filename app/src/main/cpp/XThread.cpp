//
// Created by Henry on 2021/9/14.
//

#include "XThread.h"
#include "XLog.h"
#include <thread>
using namespace std;
void XSleep(int mis){
    chrono::milliseconds du(mis);
    this_thread::sleep_for(du);
}
void XThread::SetPause(bool isP) {
    isPause=isP;
    for (int i = 0; i < 10; ++i) {
        if (isPausing == isP) {
            break;
        }
        XSleep(10);
    }
}
bool XThread::Start() {
    isExit= false;
    isPause=false;
    thread th(&XThread::ThreadMain,this);
    th.detach();
    return true;
}
void XThread::ThreadMain() {
    isRunning=true;
    XLOGE("线程函数进入");
    Main();
    XLOGE("线程函数退出");
    isRunning=false;
}