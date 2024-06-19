#include "widget.h"
#include "ui_widget.h"
#include <QFile>
extern "C"
{
    #include <libavdevice/avdevice.h>
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1、注册输入设备
    avdevice_register_all();
    showFlag = true;
    this->sub_thread = new SubThread(this);
    connect(this, &QWidget::destroyed, [=](){
        this->sub_thread->set_status_flag(true);
        this->sub_thread ->exit();
        this->sub_thread ->wait();
    });
    // 开辟线程资源
//    this->play_thread = new Play_Thread;
    this->play_thread = new Play_Thread(this);

    connect(this, &QWidget::destroyed, [=](){
        play_thread -> exit();
        play_thread ->wait();
    });




}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(showFlag)
    {
        this->sub_thread->set_status_flag(false);
        this->sub_thread->start();
        ui->pushButton->setText("停止录音");
        showFlag =false;
    }
    else
    {
        ui->pushButton->setText("开始录音");
        this->sub_thread->set_status_flag(true);
        this->sub_thread->exit();
        this->sub_thread->wait();
        showFlag = true;
    }
}

void Widget::on_pushButton_2_clicked()
{
    play_thread -> start();

}
