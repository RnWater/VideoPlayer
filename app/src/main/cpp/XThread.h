//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XTHREAD_H
#define VIDEOPLAYER_XTHREAD_H
void XSleep(int mis);
class XThread {
public:
    virtual bool Start();
    virtual void Stop();
    virtual void SetPause(bool isP);
    virtual bool IsPause(){
        isPausing = isPause;
        return isPause;
    }
    //入口主函数
    virtual void Main();
protected:
    bool isExit= false;
    bool isRunning= false;
    bool isPause= false;
    bool isPausing= false;
private:
    void ThreadMain();
};


#endif //VIDEOPLAYER_XTHREAD_H
