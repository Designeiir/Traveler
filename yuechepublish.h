#ifndef YUECHEPUBLISH_H
#define YUECHEPUBLISH_H

#include <QWidget>

namespace Ui {
class YuechePublish;
}

class YuechePublish : public QWidget
{
    Q_OBJECT

public:
    explicit YuechePublish(QWidget *parent = nullptr);
    ~YuechePublish();

private:
    Ui::YuechePublish *ui;

signals:
    void toMain();
};

#endif // YUECHEPUBLISH_H
