#ifndef PLAY_THREAD1_H
#define PLAY_THREAD1_H

#include <QObject>
#include <QThread>
#include <SDL2/SDL.h>
#include <QDebug>

class Play_Thread1 : public QThread
{
    Q_OBJECT
public:
    explicit Play_Thread1(QObject *parent = nullptr);
    void run() override;

signals:

public slots:
};

#endif // PLAY_THREAD1_H
