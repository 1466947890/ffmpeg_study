#include "play_thread1.h"

Play_Thread1::Play_Thread1(QObject *parent) : QThread(parent)
{

}

void Play_Thread1::run()
{
    SDL_version version;
    SDL_VERSION(&version)
    qDebug() << version.major << version.minor << version.patch;

    SDL_Init(SDL_INIT_AUDIO);

}
