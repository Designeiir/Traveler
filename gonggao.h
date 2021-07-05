#ifndef GONGGAO_H
#define GONGGAO_H

#include <QWidget>
#include "mypushbutton_2.h"

namespace Ui {
class Gonggao;
}

class Gonggao : public QWidget
{
    Q_OBJECT

public:
    explicit Gonggao(QWidget *parent = nullptr);
    ~Gonggao();

private:
    Ui::Gonggao *ui;
    MyPushButton_2 *btn_cantuan = NULL;

signals:
    void toConcrete();
};

#endif // GONGGAO_H
