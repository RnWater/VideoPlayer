cmake_minimum_required(VERSION 3.10.2)
project("videoplayer")

#添加头文件路径
include_directories(../../../myJni/include)
#设置ffmpeg库路径变量
set(FF ${CMAKE_CURRENT_SOURCE_DIR}/../../../myJni/${ANDROID_ABI})
#set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../myJni/include)

add_library(avcodec SHARED IMPORTED)
add_library(avformat SHARED IMPORTED)
add_library(avutil SHARED IMPORTED)
add_library(avfilter SHARED IMPORTED)
add_library(avdevice SHARED IMPORTED)
add_library(swscale SHARED IMPORTED)
add_library(swresample SHARED IMPORTED)

set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION ${FF}/libavcodec.so)
set_target_properties(avformat PROPERTIES IMPORTED_LOCATION ${FF}/libavformat.so)
set_target_properties(avutil PROPERTIES IMPORTED_LOCATION ${FF}/libavutil.so)
set_target_properties(swscale PROPERTIES IMPORTED_LOCATION ${FF}/libswscale.so)
set_target_properties(swresample PROPERTIES IMPORTED_LOCATION ${FF}/libswresample.so)
set_target_properties(avdevice PROPERTIES IMPORTED_LOCATION ${FF}/libavdevice.so)
set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION ${FF}/libavfilter.so)


add_library( # Sets the name of the library.
        native-lib
        SHARED
        native-lib.cpp
        IDemux.cpp
        FFDemux.cpp
        XData.cpp
        XLog.cpp
        XThread.cpp
        IObserver.cpp
        FFDecode.cpp
        IDecode.cpp
        XParameter.cpp
        IVideoView.cpp
        GLVideoView.cpp
        XTexture.cpp
        XEGL.cpp
        XShader.cpp
        FFResample.cpp
        IResample.cpp
        SLAudioPlay.cpp
        IAudioPlay.cpp
        IPlayer.cpp
        IPlayerBuilder.cpp
        FFPlayerBuilder.cpp
        IPlayerProxy.cpp

        )
find_library(
        log-lib
        log )
target_link_libraries(
        native-lib
        GLESv2 EGL OpenSLES
        android
        avcodec avformat avutil swscale swresample avfilter avdevice
        ${log-lib})
