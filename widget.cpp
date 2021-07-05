#include "widget.h"
#include "ui_widget.h"
#include "mypushbutton.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击综合显示0页
//    connect(ui->btn_zonghe,&QPushButton::clicked,this,[=](){
//        ui->stackedWidget->setCurrentIndex(0);
//    });
    //点击日志显示1页
    connect(ui->btn_rizhi,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //点击公告显示2页
    connect(ui->btn_gonggao,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    //点击约车显示3页
    connect(ui->btn_yueche,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    //构建发布详情页，位置与主页面一致
    gonggaopub = new GonggaoPublish;
    gonggaopub->setParent(this);
    gonggaopub->hide();
    gonggaopub->move(ui->widget->x(),ui->widget->y()+9);

    rizhipub = new RizhiPublish;
    rizhipub->setParent(this);
    rizhipub->hide();
    rizhipub->move(ui->widget->x(),ui->widget->y()+9);

    yuechepub = new YuechePublish;
    yuechepub->setParent(this);
    yuechepub->hide();
    yuechepub->move(ui->widget->x(),ui->widget->y()+9);


    //设置详情页标题返回主页面
    connect(gonggaopub,&GonggaoPublish::toMain,this,[=](){
        gonggaopub->hide();
        ui->widget->show();
    });

    connect(rizhipub,&RizhiPublish::toMain,this,[=](){
        rizhipub->hide();
        ui->widget->show();
    });

    connect(yuechepub,&YuechePublish::toMain,this,[=](){
        yuechepub->hide();
        ui->widget->show();
    });

    gonggaovec.resize(5);
    for(int i = 0;i < 5;i++)
    {
        gonggaovec[gonggaovec.size()-1-i] = new Gonggao;
        gonggaovec[gonggaovec.size()-1-i]->setParent(ui->scrollAreaWidgetContents_3);
        gonggaovec[gonggaovec.size()-1-i]->move(9,9+209*i);

        connect(gonggaovec[gonggaovec.size()-1-i],&Gonggao::toConcrete,this,[=](){
            ui->widget->hide();
            gonggaopub->show();
        });
    }

    rizhivec.resize(5);
    for(int i = 0;i < 5;i++)
    {
        rizhivec[rizhivec.size()-1-i] = new Rizhi;
        rizhivec[rizhivec.size()-1-i]->setParent(ui->scrollAreaWidgetContents_2);
        rizhivec[rizhivec.size()-1-i]->move(9,9+209*i);

        connect(rizhivec[rizhivec.size()-1-i],&Rizhi::toConcrete,this,[=](){
            ui->widget->hide();
            rizhipub->show();
        });
    }

    yuechevec.resize(5);
    for(int i = 0;i < 5;i++)
    {
        yuechevec[yuechevec.size()-1-i] = new Yueche;
        yuechevec[yuechevec.size()-1-i]->setParent(ui->scrollAreaWidgetContents_4);
        yuechevec[yuechevec.size()-1-i]->move(9,9+209*i);

        connect(yuechevec[yuechevec.size()-1-i],&Yueche::toConcrete,this,[=](){
            ui->widget->hide();
            yuechepub->show();
        });

    }

    MyPushButton *btn_zonghe = new MyPushButton("://点赞 (2).png","://点赞 (1).png");
    btn_zonghe->setParent(ui->widget);//设置他的依赖框架
    btn_zonghe->move(180,60);//移动他的位置

    connect(btn_zonghe,&QPushButton::clicked,this,[=](){
        btn_zonghe->zoom1();
        btn_zonghe->zoom2();
        QTimer::singleShot(500,this,[=](){});//实现延迟500ms后再进行以下操作
        ui->stackedWidget->setCurrentIndex(0);
    });

    MyPushButton *btn_rizhi = new MyPushButton("://点赞 (2).png","://点赞 (1).png");
    btn_rizhi->setParent(ui->widget);//设置他的依赖框架
    btn_rizhi->move(290,60);//移动他的位置

    connect(btn_rizhi,&QPushButton::clicked,this,[=](){
        btn_rizhi->zoom1();
        btn_rizhi->zoom2();
        QTimer::singleShot(500,this,[=](){});//实现延迟500ms后再进行以下操作
        ui->stackedWidget->setCurrentIndex(0);
    });

    MyPushButton *btn_yueche = new MyPushButton("://点赞 (2).png","://点赞 (1).png");
    btn_yueche->setParent(ui->widget);//设置他的依赖框架
    btn_yueche->move(650,60);//移动他的位置

    connect(btn_yueche,&QPushButton::clicked,this,[=](){
        btn_yueche->zoom1();
        btn_yueche->zoom2();
        QTimer::singleShot(500,this,[=](){});//实现延迟500ms后再进行以下操作
        ui->stackedWidget->setCurrentIndex(0);
    });




}

Widget::~Widget()
{
    delete ui;
}

