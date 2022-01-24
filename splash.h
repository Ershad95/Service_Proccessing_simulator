#ifndef SPLASH_H
#define SPLASH_H

#include <QWidget>

namespace Ui {
class Splash;
}

class Splash : public QWidget
{
    Q_OBJECT

public:
    explicit Splash(QWidget *parent = 0);
    ~Splash();

public slots:
    void ShowArrow();

private:
    Ui::Splash *ui;
};

#endif // SPLASH_H
