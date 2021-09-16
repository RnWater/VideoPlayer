//
// Created by Henry on 2021/9/14.
//

#include "IDecode.h"
#include "XLog.h"
void IDecode::Update(XData pkt) {
    if (pkt.isAudio != isAudio) {
        return;
    }
    while (!isExit) {
        packsMutex.lock();
        if (packs.size() < maxList) {
            packs.push_back(pkt);
            packsMutex.unlock();
            break;
        }
        packsMutex.unlock();
        XSleep(1);
    }
}
void IDecode::Clear() {
    packsMutex.lock();
    while (!packs.empty()) {
        packs.front().Drop();
        packs.pop_front();
    }
    pts=0;
    synPts=0;
    packsMutex.unlock();
}
void IDecode::Main() {
    while (!isExit) {
        if (isPause) {
            XSleep(2);
            continue;
        }
        packsMutex.lock();
        if (!isAudio && synPts > 0) {
            if (synPts < pts) {
                packsMutex.unlock();
                XSleep(1);
                continue;
            }
        }
        if (packs.empty()) {
            packsMutex.unlock();
            XSleep(1);
            continue;
        }
        XData pack = packs.front();
        packs.pop_front();
        if (this->SendPacket(pack)) {
            while (!isExit) {
                XData frame=ReceiveFrame();
                if (!frame.data)break;
                pts=frame.pts;
                this->Notify(frame);
            }
        }
        pack.Drop();
        packsMutex.unlock();
    }
}