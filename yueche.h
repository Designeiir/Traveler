#ifndef YUECHE_H
#define YUECHE_H

#include <QWidget>
#include "mypushbutton_2.h"

namespace Ui {
class Yueche;
}

class Yueche : public QWidget
{
    Q_OBJECT

public:
    explicit Yueche(QWidget *parent = nullptr);
    ~Yueche();

private:
    Ui::Yueche *ui;
    MyPushButton_2 *btn_yueche = NULL;

signals:
    void toConcrete();
};

#endif // YUECHE_H
