#ifndef SUBTHREAD_H
#define SUBTHREAD_H

#include <QThread>
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavdevice/avdevice.h>
    #include <libavutil/avutil.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/imgutils.h>
}


class SubThread : public QThread
{
public:
    SubThread(QObject* parent = nullptr);
    void run() override;
    void set_status_flag(bool flag);

private:
    bool status_flag;
};

#endif // SUBTHREAD_H
