#include "yuechepublish.h"
#include "ui_yuechepublish.h"

YuechePublish::YuechePublish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YuechePublish)
{
    ui->setupUi(this);

    connect(ui->btn_cancel,&QPushButton::clicked,this,[=](){
        emit toMain();
    });
}

YuechePublish::~YuechePublish()
{
    delete ui;
}
