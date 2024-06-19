#ifndef PLAY_THREAD_H
#define PLAY_THREAD_H

#include <QObject>
#include <QThread>
#include <SDL2/SDL.h>
#include <QDebug>
#include <QFile>

class Play_Thread : public QThread
{
public:
    Play_Thread(QObject* prant = nullptr);
    void run() override;
};

#endif // PLAY_THREAD_H
