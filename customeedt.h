#ifndef CUSTOMEEDT_H
#define CUSTOMEEDT_H
#include "QLabel"
#include <QWidget>
#include "QLineEdit"
#include "QtEvents"
#include "QMouseEvent"

class CustomeEDT : public QLineEdit
{
    Q_OBJECT
public:
    CustomeEDT(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);

signals:
    void click();

};

#endif // CUSTOMEEDT_H
