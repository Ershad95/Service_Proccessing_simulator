#include "customeedt.h"

CustomeEDT::CustomeEDT(QWidget *parent) : QLineEdit(parent)
{

}

void CustomeEDT::mousePressEvent(QMouseEvent *ev)
{
    emit click();
}
