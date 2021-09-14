//
// Created by Henry on 2021/9/14.
//

#include "XTexture.h"
#include "XLog.h"
#include "XEGL.h"
#include "XShader.h"
#include <mutex>
class CXTexture: public XTexture{
public:
    XShader sh;
    XTextureType type;
    std::mutex mux;
    virtual void Drop() {
        mux.lock();
        XEGL::Get()->Close();
        sh.Close();
        mux.unlock();
        delete this;
    }

    virtual bool Init(void *win, XTextureType type = X_TEXTURE_YUV_420p) {
        mux.lock();
        XEGL::Get()->Close();
        sh.Close();
        this->type=type;
        if (!win) {
            mux.unlock();
            return false;
        }
        if (!XEGL::Get()->Init(win)) {
            mux.unlock();
            return false;
        }
        sh.Init((XShaderType)type);
        mux.unlock();
        return true;
    }
    virtual void Draw(unsigned char **data, int width, int height) {
        mux.lock();
        sh.GetTexture(0,width,height,data[0]);//Y
        if (type == X_TEXTURE_YUV_420p) {
            sh.GetTexture(1, width / 2, height / 2, data[1]);//U
            sh.GetTexture(2,width/2,height/2,data[2]);//V
        } else {
            sh.GetTexture(1,width/2,height/2,data[1],true);//UV
        }
        sh.Draw();
        XEGL::Get()->Draw();
        mux.unlock();
    }
};
XTexture *XTexture::Create() {
    return new CXTexture();
}