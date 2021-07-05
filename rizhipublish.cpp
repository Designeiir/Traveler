#include "rizhipublish.h"
#include "ui_rizhipublish.h"

RizhiPublish::RizhiPublish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RizhiPublish)
{
    ui->setupUi(this);

    connect(ui->btn_cancel,&QPushButton::clicked,this,[=](){
        emit toMain();
    });
}

RizhiPublish::~RizhiPublish()
{
    delete ui;
}
