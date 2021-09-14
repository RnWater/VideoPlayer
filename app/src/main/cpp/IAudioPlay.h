//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IAUDIOPLAY_H
#define VIDEOPLAYER_IAUDIOPLAY_H
#include "IObserver.h"
#include "XParameter.h"
#include <list>

class IAudioPlay: public IObserver {
public:
    virtual void Update(XData data);
    virtual XData GetData();
    virtual bool  StartPlay(XParameter out)=0;
    virtual void Close()=0;
    virtual void Clear()=0;
    int maxFrame=100;
    int pts=0;
protected:
    std::list<XData> frames;
    std::mutex framesMutex;
};


#endif //VIDEOPLAYER_IAUDIOPLAY_H
