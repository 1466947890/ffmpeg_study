#ifndef PLAY_THREAD_H
#define PLAY_THREAD_H

#include <QObject>
#include <QThread>
#include <SDL2/SDL.h>
#include <QDebug>
#include <QFile>

struct UserData
{
    int len;
    Uint8* data_ptr;
};

class Play_Thread : public QThread
{
public:
    Play_Thread(QObject* prant = nullptr);
    void run() override;
    ~Play_Thread() override;
private:
    UserData* user_data;
};

#endif // PLAY_THREAD_H
