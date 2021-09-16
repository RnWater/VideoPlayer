//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IDECODE_H
#define VIDEOPLAYER_IDECODE_H
#include "XParameter.h"
#include "IObserver.h"
#include <list>

class IDecode : public IObserver{
public:
    virtual bool Open(XParameter parameter,bool isHard=false)=0;
    virtual void Close()=0;
    virtual void Clear();
    virtual bool SendPacket(XData pkt)=0;
    virtual XData ReceiveFrame()=0;
    virtual void Update(XData pkt);
    bool isAudio=false;
    int maxList=100;//最大的队列缓冲
    int synPts=0;//同步时间，再次打开文件要清理
    int pts=0;
protected:
    virtual void Main();
    std::list<XData> packs;
    std::mutex packsMutex;
};


#endif //VIDEOPLAYER_IDECODE_H
