//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XPARAMETER_H
#define VIDEOPLAYER_XPARAMETER_H

struct AVCodecParameters;
class XParameter {
public:
    AVCodecParameters *para=0;
    int channels=2;
    int sample_rate=44100;
};


#endif //VIDEOPLAYER_XPARAMETER_H
