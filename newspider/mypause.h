#ifndef MYPAUSE_H
#define MYPAUSE_H
#include <QThread>

class pause : QThread
{
public:
    static void setpause(int sec)
    {
        sec *= 1000;
        QThread::msleep(sec);
    }
};

#endif // MYPAUSE_H
