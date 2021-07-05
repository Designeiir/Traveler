#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QEvent>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QPushButton *parent = nullptr);
    MyPushButton(QString normalImg,QString aboveImg="");

    QString normalImgPath;//保存用户传入的默认显示路径
    QString aboveImgPath;//保存鼠标在上面的显示路径

    void iconShow(QString path);//显示图片

    void zoom1();//向下跳
    void zoom2();//向上跳
    void zoom(int upy=0,int dpy=0);//跳转函数

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:

};

#endif // MYPUSHBUTTON_H
