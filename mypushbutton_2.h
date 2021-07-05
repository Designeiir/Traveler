#ifndef MYPUSHBUTTON_2_H
#define MYPUSHBUTTON_2_H

#include <QPushButton>

class MyPushButton_2 : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton_2(QWidget *parent = nullptr);
    MyPushButton_2(QString normalImg,QString changedImg="");

    QString normalImagPath;
    QString changedImagPath;

    void iconShow(QString path);

    void zoom1();
    void zoom2();
    void zoom(int upy=0,int dpy=0);

    void mousePressEvent(QMouseEvent *e);


    bool isOdd;
signals:

};

#endif // MYPUSHBUTTON_2_H
