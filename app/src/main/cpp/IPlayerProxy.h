//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IPLAYERPROXY_H
#define VIDEOPLAYER_IPLAYERPROXY_H
#include "IPlayer.h"
#include <mutex>
class IPlayerProxy : public IPlayer{
public:
    static IPlayerProxy *Get(){
        static IPlayerProxy px;
        return &px;
    }
    void Init(void *vm = 0);
    virtual bool Open(const char *path);
    virtual bool Seek(double pos);
    virtual void Close();
    virtual bool Start();
    virtual void InitView(void *win);
    virtual void SetPause(bool isP);
    virtual bool IsPause();
    virtual double PlayPos();

protected:
    IPlayerProxy();
    IPlayer *player=0;
    std::mutex mux;
};


#endif //VIDEOPLAYER_IPLAYERPROXY_H
