#include "rizhi.h"
#include "ui_rizhi.h"
#include <QToolButton>


Rizhi::Rizhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rizhi)
{
    ui->setupUi(this);
    connect(ui->toolbtn_title,&QToolButton::clicked,this,[=](){
        emit toConcrete();
    });

    btn_like = new MyPushButton_2("://点赞 (2).png","://点赞 (1).png");
    btn_like->setParent(this);
    btn_like->move(680,170);

    connect(btn_like,&QPushButton::clicked,this,[=](){
        btn_like->zoom1();
        btn_like->zoom2();
    });
}

Rizhi::~Rizhi()
{
    delete ui;
}
