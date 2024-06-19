#ifndef WIDGET_H
#define WIDGET_H


#include <QDebug>
#include <QBuffer>
#include <QWidget>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <subthread.h>
//#include <subauth.h>





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

private:
    Ui::Widget *ui;
    bool showFlag; // 作为一个标志
    SubThread* sub_thread;
};
#endif // WIDGET_H
