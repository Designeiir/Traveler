#include "mypushbutton.h"
#include<QIcon>
#include<QPropertyAnimation>//动画特效头文件
#include<QRect>
#include<QDebug>

MyPushButton::MyPushButton(QString normalImg,QString aboveImg)
{
    this->normalImgPath = normalImg;
    this->aboveImgPath = aboveImg;
    iconShow(normalImgPath);
}

void MyPushButton::iconShow(QString path)
{
    QPixmap pix;
        bool ret=pix.load(path);
        if(!ret){
            qDebug()<<"图片加载失败";
            return;
        }

    this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
    this->setStyleSheet("QPushButton{border:0px;}");//设置不规则图片样式
    this->setIcon(pix);//设置图标
    this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小
}

void MyPushButton::zoom(int upy, int dpy)
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");//创建动态对象
        animation->setDuration(200);//设置动画时间间隔
        //QRect(this->x(),this-y(),this->width(),this->height());
        animation->setStartValue(QRect(QPoint(this->x(),this->y()+upy),QPoint(this->width(),this->height())));//起始位置
        animation->setEndValue(QRect(QPoint(this->x(),this->y()+dpy),QPoint(this->width(),this->height())));//起始位置
        animation->setEasingCurve(QEasingCurve::OutBounce);//设置弹跳效果
        animation->start();//设置开始弹跳
}

void MyPushButton::zoom1()
{
    zoom(0,5);
}

void MyPushButton::zoom2()
{
    zoom(5,0);
}

void MyPushButton::enterEvent(QEvent *event)
{
    if(this->aboveImgPath!="")
    {
        iconShow(aboveImgPath);
    }
    return QPushButton::enterEvent(event);
}

void MyPushButton::leaveEvent(QEvent *event)
{
    if(this->normalImgPath!="")
    {
        iconShow(normalImgPath);
    }
    return QPushButton::leaveEvent(event);
}

