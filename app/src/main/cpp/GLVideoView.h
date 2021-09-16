//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_GLVIDEOVIEW_H
#define VIDEOPLAYER_GLVIDEOVIEW_H
#include "XData.h"
#include "IVideoView.h"
class XTexture;
class GLVideoView : public IVideoView{
public:
    virtual void SetRender(void *win);

    virtual void Render(XData data);
    virtual void Close();

protected:
    void *view=0;
    XTexture *txt=0;
    std::mutex mux;
};


#endif //VIDEOPLAYER_GLVIDEOVIEW_H
