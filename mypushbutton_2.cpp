#include "mypushbutton_2.h"
#include<QIcon>
#include<QPropertyAnimation>//动画特效头文件
#include<QRect>
#include<QDebug>


MyPushButton_2::MyPushButton_2(QString normalImg,QString changedImg)
{
    normalImagPath = normalImg;
    changedImagPath = changedImg;
    isOdd = 0;
    iconShow(normalImagPath);
}

void MyPushButton_2::iconShow(QString path)
{
    QPixmap pix;
       bool ret=pix.load(path);
       if(!ret){
           qDebug()<<"图片加载失败";
           return;
       }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton_2::zoom1()
{
   zoom(0,5);
}

void MyPushButton_2::zoom2()
{
    zoom(5,0);
}

void MyPushButton_2::zoom(int upy,int dpy)
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");//创建动态对象
    animation->setDuration(200);//设置动画时间间隔
    //QRect(this->x(),this-y(),this->width(),this->height());
    animation->setStartValue(QRect(QPoint(this->x(),this->y()+upy),QPoint(this->width(),this->height())));//起始位置
    animation->setEndValue(QRect(QPoint(this->x(),this->y()+dpy),QPoint(this->width(),this->height())));//起始位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置弹跳效果
    animation->start();//设置开始弹跳
}

void MyPushButton_2::mousePressEvent(QMouseEvent *e)
{
    if(this->changedImagPath!=""){//传入的按下图片不为空，说明需要有按下状态切换图片
        isOdd = !isOdd;
        if(isOdd){
            iconShow(this->changedImagPath);
        }
        else
        {
            iconShow(this->normalImagPath);
        }
    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);

}
