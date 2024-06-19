#include "subthread.h"
#include <QFile>
#include <QDebug>


SubThread::SubThread(QObject* parent) : QThread(parent)
{
    status_flag = false;
}

void SubThread::run()
{
    // 2、获取输入格式
    const AVInputFormat* fmt = av_find_input_format("dshow");
    // 3、定义格录制音频格式的上下文;
    AVFormatContext* ctx = nullptr;
//    const char*  audio_device= "audio=麦克风阵列 (适用于数字麦克风的英特尔® 智音技术)";
    const char*  audio_device= "audio=插孔麦克风 (Realtek(R) Audio)";
    // 插孔麦克风 (Realtek(R) Audio)
    // 4、打开输入设备
    avformat_open_input(&ctx, audio_device, fmt, nullptr);
    // 5、定义一个文件来保存所采集的音频数据;
    QFile file("./test.pcm");
    file.open(QIODevice::WriteOnly);
    if(!file.isOpen())
    {
        qDebug() << "文件没有打开";
    }

    // 6、采集音频数据
    AVPacket pkt;
//    int count = 20;
    av_read_frame(ctx, &pkt);
    while(!status_flag  && av_read_frame(ctx, &pkt) == 0)
    {
        file.write((const char*)pkt.data, pkt.size);
    }
    // 7、释放所用到的资源
    file.close();
    avformat_close_input(&ctx);
}

void SubThread::set_status_flag(bool flag)
{
    this->status_flag = flag;
}
