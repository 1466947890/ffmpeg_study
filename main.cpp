#include "widget.h"
#include <QApplication>
#include <QThread>




void initFFmpeg() {
    // 设置 FFmpeg 日志级别
//    av_log_set_level(AV_LOG_VERBOSE);

    // 注册所有的音频和视频解码器和格式

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    qDebug() << avcodec_version();
//    avcodec_version();


    Widget w;
    w.show();

    return a.exec();
}


