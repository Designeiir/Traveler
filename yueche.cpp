#include "yueche.h"
#include "ui_yueche.h"

Yueche::Yueche(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yueche)
{
    ui->setupUi(this);

    connect(ui->toolbtn_title,&QToolButton::clicked,this,[=](){
        emit toConcrete();
    });

    btn_yueche = new MyPushButton_2("://点赞 (2).png","://点赞 (1).png");
    btn_yueche->setParent(this);
    btn_yueche->move(680,170);

    connect(btn_yueche,&QPushButton::clicked,this,[=](){
        btn_yueche->zoom1();
        btn_yueche->zoom2();
    });
}

Yueche::~Yueche()
{
    delete ui;
}
