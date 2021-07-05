#ifndef RIZHIPUBLISH_H
#define RIZHIPUBLISH_H

#include <QWidget>

namespace Ui {
class RizhiPublish;
}

class RizhiPublish : public QWidget
{
    Q_OBJECT

public:
    explicit RizhiPublish(QWidget *parent = nullptr);
    ~RizhiPublish();

private:
    Ui::RizhiPublish *ui;

signals:
    void toMain();
};

#endif // RIZHIPUBLISH_H
