#ifndef RIZHI_H
#define RIZHI_H

#include <QWidget>
#include "rizhipublish.h"
#include "mypushbutton_2.h"

namespace Ui {
class Rizhi;
}

class Rizhi : public QWidget
{
    Q_OBJECT

public:
    explicit Rizhi(QWidget *parent = nullptr);
    ~Rizhi();

private:
    Ui::Rizhi *ui;
    MyPushButton_2 *btn_like;

signals:
    void toConcrete();
};

#endif // RIZHI_H
