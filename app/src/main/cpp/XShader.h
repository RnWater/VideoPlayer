//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XSHADER_H
#define VIDEOPLAYER_XSHADER_H
#include <mutex>
enum XShaderType{
    X_SHADER_YUV_420p=0,//软解码和虚拟机
    X_SHADER_NV12=25,//手机
    X_SHADER_NV21=26//y4 vu1
};
class XShader {
public:
    virtual bool Init(XShaderType type = X_SHADER_YUV_420p);
    virtual void Close();
    virtual void GetTexture(unsigned int index,int width,int height,unsigned char *buf,bool isa=false);
    virtual void Draw();

protected:
    unsigned int vsh=0;
    unsigned int fsh=0;
    unsigned int program=0;
    unsigned int texts[100]={0};
    std::mutex mux;
};


#endif //VIDEOPLAYER_XSHADER_H
