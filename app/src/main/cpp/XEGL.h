//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XEGL_H
#define VIDEOPLAYER_XEGL_H


class XEGL {
public:
    virtual bool Init(void *win)=0;
    virtual void Close()=0;
    virtual void Draw()=0;
    static XEGL *Get();

protected:
    XEGL(){}
};


#endif //VIDEOPLAYER_XEGL_H
