#include "gonggao.h"
#include "ui_gonggao.h"
#include <QToolButton>
#include "mypushbutton_2.h"

Gonggao::Gonggao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gonggao)
{
    ui->setupUi(this);

    connect(ui->toolbtn_title,&QToolButton::clicked,this,[=](){
        emit toConcrete();
    });

    btn_cantuan = new MyPushButton_2("://点赞 (2).png","://点赞 (1).png");
    btn_cantuan->setParent(this);
    btn_cantuan->move(680,170);

    connect(btn_cantuan,&QPushButton::clicked,this,[=](){
        btn_cantuan->zoom1();
        btn_cantuan->zoom2();
    });
}

Gonggao::~Gonggao()
{
    delete ui;
}
