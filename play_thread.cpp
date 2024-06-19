#include "play_thread.h"

Play_Thread::Play_Thread(QObject* parent) : QThread(parent)
{

}

int bufferLen;
char* bufferData;



void _audioCallback (void *userdata,
                     Uint8 * stream,
                     int len)
{
    // 清空缓冲区
    SDL_memset(stream, 0, len);

    if(bufferLen == 0)
    {
        return;
    }
    // 每次获取一下len的长度
    len = (len > bufferLen) ? bufferLen : len;
    // 填充数据buffer
    SDL_MixAudio(stream, (Uint8*) bufferData, len, SDL_MIX_MAXVOLUME);

    // 指针要进行移动。
    bufferData += len;

    bufferLen -= len;


};

void Play_Thread::run()
{
//    SDL_version version;
//    SDL_VERSION(&version)
//    qDebug() << version.major << version.minor << version.patch;

    // 1.SDL中分成了各种各样的子系统
    // 1、初始化音频子系统：
    SDL_Init(SDL_INIT_AUDIO);
    // 2、确定要播放的音频的相关参数
    SDL_AudioSpec spc;
    spc.freq = 44100;
    spc.format = AUDIO_S16LSB;
    spc.channels = 2;
    spc.callback = _audioCallback;
    spc.samples = 1024;

    // 打开文件
    QFile file("./test.pcm");
    qDebug() << file.size();
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen())
    {
        qDebug() << "文件打开失败";
        SDL_Quit();
        return;
    }

    // 打开音频设备
    SDL_OpenAudio(&spc, nullptr);
    // 播放音频（或以后的视频）都是通过推流和拉流实现
    // PUSH：程序主动推送数据给设备
    // PULL：音频设备主动向程序拉取数据

    SDL_PauseAudio(0); // 0为播放，1为暂停

    char audio_buffer[4096];
    // 读取文件数据
    while(!isFinished())
    {
        bufferLen = file.read(audio_buffer, sizeof(char[4096]));
        if(bufferLen <= 0)
        {
            break; // 代表到了文件尾
        }
        bufferData = audio_buffer;
        // 休眠，让这个线程休眠，等待下次拉取
        while (bufferLen > 0) {
            SDL_Delay(1);
        }
    }





}
