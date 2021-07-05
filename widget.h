#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "information.h"
#include "gonggaopublish.h"
#include "gonggao.h"
#include "rizhipublish.h"
#include "yuechepublish.h"
#include "rizhi.h"
#include "yueche.h"
#include "mypushbutton.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Information *info = NULL;
    GonggaoPublish *gonggaopub = NULL;
    QVector<Gonggao*>gonggaovec;
    RizhiPublish *rizhipub = NULL;
    QVector<Rizhi*>rizhivec;
    YuechePublish *yuechepub = NULL;
    QVector<Yueche*>yuechevec;



};
#endif // WIDGET_H
