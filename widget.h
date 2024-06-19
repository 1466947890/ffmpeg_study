#ifndef WIDGET_H
#define WIDGET_H


#include <QDebug>
#include <QBuffer>
#include <QWidget>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <subthread.h>
#include <play_thread.h>
#include <play_thread1.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    bool showFlag; // 作为一个标志
    SubThread* sub_thread;
    Play_Thread* play_thread;
    Play_Thread1* play_thread1;

};
#endif // WIDGET_H
