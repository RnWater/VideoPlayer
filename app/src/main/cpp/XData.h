//
// Created by Henry on 2021/9/14.
//

#ifndef VIDEOPLAYER_XDATA_H
#define VIDEOPLAYER_XDATA_H
enum XDataType{
    AV_PACKET_TYPE=0,
    U_CHAR_TYPE=1
};
struct XData {
    int type=0;
    int pts=0;
    unsigned char *data=0;
    unsigned char *datas[8]={0};
    int size=0;
    bool isAudio= false;
    int width=0,height=0;
    int format=0;
    bool Alloc(int size,const char *data=0);
    void Drop();
};
#endif //VIDEOPLAYER_XDATA_H
