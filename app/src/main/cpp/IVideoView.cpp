//
// Created by Henry on 2021/9/14.
//

#include "IVideoView.h"
#include "XLog.h"
void IVideoView::Update(XData data) {
    this->Render(data);
}