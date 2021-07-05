#ifndef GONGGAOPUBLISH_H
#define GONGGAOPUBLISH_H

#include <QWidget>

namespace Ui {
class GonggaoPublish;
}

class GonggaoPublish : public QWidget
{
    Q_OBJECT

public:
    explicit GonggaoPublish(QWidget *parent = nullptr);
    ~GonggaoPublish();

private:
    Ui::GonggaoPublish *ui;

signals:
    void toMain();
};

#endif // GONGGAOPUBLISH_H
