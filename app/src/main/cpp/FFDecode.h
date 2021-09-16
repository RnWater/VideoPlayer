//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_FFDECODE_H
#define VIDEOPLAYER_FFDECODE_H
#include "XParameter.h"
#include "IDecode.h"
struct AVCodecContext;
struct AVFrame;
class FFDecode: public IDecode {
public:
    static void InitHard(void *vm);
    virtual bool Open(XParameter para,bool isHard= false);
    virtual void Close();
    virtual void Clear();
    virtual bool SendPacket(XData pkt);
    virtual XData ReceiverFrame();
protected:
    AVCodecContext *codec=0;
    AVFrame *frame=0;
    std::mutex mux;
};


#endif //VIDEOPLAYER_FFDECODE_H
