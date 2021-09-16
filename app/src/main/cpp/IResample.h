//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IRESAMPLE_H
#define VIDEOPLAYER_IRESAMPLE_H
#include "XParameter.h"
#include "IObserver.h"

class IResample : public IObserver{
public:
    virtual bool  Open(XParameter in,XParameter out=XParameter())=0;
    virtual XData Resample(XData inData)=0;
    virtual void Close()=0;
    virtual void Update(XData data);
    int outChannels=2;
    int outFormat=1;
};


#endif //VIDEOPLAYER_IRESAMPLE_H
