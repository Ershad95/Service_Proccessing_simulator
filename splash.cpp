#include "splash.h"
#include "ui_splash.h"
#include "QPropertyAnimation"
#include "QTimer"
#include "auth.h"
#include "QString"

QTimer *showTimer=0;
int ShowCounter=4;
Splash::Splash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);
    showTimer = new QTimer(this);
    connect(showTimer,SIGNAL(timeout()),SLOT(ShowArrow()));

    QPropertyAnimation *anim = new QPropertyAnimation(ui->widget_4,"geometry");
    QPropertyAnimation *anim2 = new QPropertyAnimation(ui->widget_3,"geometry");
    QPropertyAnimation *anim3 = new QPropertyAnimation(ui->widget_6,"geometry");
    QPropertyAnimation *anim4 = new QPropertyAnimation(ui->widget,"geometry");


    showTimer->setInterval(1000);
    showTimer->start();


    anim->setLoopCount(-1);
    anim->setDuration(1500);
    anim->setStartValue(QRect(600,520,81,71));
    anim->setEndValue(QRect(480,400,81,71));
    anim->start();

    anim2->setLoopCount(-1);
    anim2->setDuration(1500);
    anim2->setStartValue(QRect(0,520,81,71));
    anim2->setEndValue(QRect(100,400,81,71));
    anim2->start();

    anim3->setLoopCount(-1);
    anim3->setDuration(1500);
    anim3->setStartValue(QRect(600,170,81,71));
    anim3->setEndValue(QRect(530,250,81,71));
    anim3->start();

    anim4->setLoopCount(-1);
    anim4->setDuration(1500);
    anim4->setStartValue(QRect(0,170,81,71));
    anim4->setEndValue(QRect(70,240,81,71));
    anim4->start();



}

Splash::~Splash()
{
    delete ui;
}

void Splash::ShowArrow()
{
    if(ShowCounter<=1)
    {
        showTimer->stop();
        Auth *auth = new Auth();
        this->close();
        auth->show();
    }
    else
    {
        --ShowCounter;
        ui->txtCounter->setText(QString::number(ShowCounter));
    }

}
