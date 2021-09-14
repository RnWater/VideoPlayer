//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_IOBSERVER_H
#define VIDEOPLAYER_IOBSERVER_H
#include "XData.h"
#include "XThread.h"
#include <vector>
#include <mutex>

class IObserver: public XThread{
public:
    virtual void Update(XData data){};
    void AddObs(IObserver *obs);
    void Notify(XData data);

protected:
    std::vector<IObserver *>obss;
    std::mutex mux;
};


#endif //VIDEOPLAYER_IOBSERVER_H
