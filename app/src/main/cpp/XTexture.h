//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XTEXTURE_H
#define VIDEOPLAYER_XTEXTURE_H
enum XTextureType{
    X_TEXTURE_YUV_420p=0,//y4 u 1 v 1
    X_TEXTURE_NV12=25,//y4 uv1
    X_TEXTURE_NV21=26//y4 vu1
};
class XTexture {
public:
    static XTexture *Create();
    virtual bool Init(void *win, XTextureType type = X_TEXTURE_YUV_420p) = 0;
    virtual void Draw(unsigned char *data[],int width,int height)=0;
    virtual void Drop() = 0;
    virtual ~XTexture(){};
protected:
    XTexture(){};
};


#endif //VIDEOPLAYER_XTEXTURE_H
