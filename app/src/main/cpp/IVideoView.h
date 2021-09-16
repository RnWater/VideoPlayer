//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IVIDEOVIEW_H
#define VIDEOPLAYER_IVIDEOVIEW_H
#include "XData.h"
#include "IObserver.h"
class IVideoView : public IObserver {
public:
    virtual void SetRender(void *win)=0;

    virtual void Render(XData data) = 0;

    virtual void Update(XData data);

    virtual void Close() = 0;
};


#endif //VIDEOPLAYER_IVIDEOVIEW_H
