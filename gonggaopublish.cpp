#include "gonggaopublish.h"
#include "ui_gonggaopublish.h"

GonggaoPublish::GonggaoPublish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GonggaoPublish)
{
    ui->setupUi(this);

    connect(ui->btn_cancel,&QPushButton::clicked,this,[=](){
        emit toMain();
    });
}


GonggaoPublish::~GonggaoPublish()
{
    delete ui;
}
