#include "simulation.h"
#include "ui_simulation.h"
#include <qpropertyanimation.h>
#include "process.h"
#include "QString"
#include "QTimer"
QPropertyAnimation *animation5,*animation4,*animation3,*animation2,*animation1;
int ID[5];
QTimer *timer;
int counter=0;
Simulation::Simulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(HideTerminate()));
    ui->lblProc->hide();
    ui->lblProc2->hide();
    ui->lblProc3->hide();
    ui->lblProc4->hide();
    ui->lblProc5->hide();

    ui->tblInfo->hide();

    ui->prcIcon->hide();
    ui->prc2Icon->hide();
    ui->prc3Icon->hide();
    ui->prc4Icon->hide();
    ui->prc5Icon->hide();
}

Simulation::~Simulation()
{
    delete ui;
}


int width=800;


void Simulation::on_pushButton_clicked()
{
    ui->tblInfo->hide();
    ui->Terminate->hide();
    ui->lblProc->show();
    ui->lblProc2->show();
    ui->lblProc3->show();
    ui->lblProc4->show();
    ui->lblProc5->show();

    ui->prcIcon->show();
    ui->prc2Icon->show();
    ui->prc3Icon->show();
    ui->prc4Icon->show();
    ui->prc5Icon->show();
    animation5 = new QPropertyAnimation(ui->prc5Icon,"geometry");
    animation4 = new QPropertyAnimation(ui->prc4Icon,"geometry");
    animation3 = new QPropertyAnimation(ui->prc3Icon,"geometry");
    animation2 = new QPropertyAnimation(ui->prc2Icon,"geometry");
    animation1 = new QPropertyAnimation(ui->prcIcon,"geometry");

    animation5->setDuration(1000);
    animation5->setStartValue(QRect(0,0,0,0));
    animation5->setEndValue(QRect(220, 230, 51, 51));
    animation5->start();

    animation4->setDuration(560);
    animation4->setStartValue(QRect(0,0,0,0));
    animation4->setEndValue(QRect(80, 230, 51, 51));
    animation4->start();

    animation3->setDuration(300);
    animation3->setStartValue(QRect(0,0,0,0));
    animation3->setEndValue(QRect(150, 180, 51, 51));
    animation3->start();

    animation2->setDuration(500);
    animation2->setStartValue(QRect(0,0,0,0));
    animation2->setEndValue(QRect(220, 140, 51, 51));
    animation2->start();

    animation1->setDuration(700);
    animation1->setStartValue(QRect(0,0,0,0));
    animation1->setEndValue(QRect(80, 140, 51, 51));
    animation1->start();



    animation5 = new QPropertyAnimation(ui->lblProc,"geometry");
    animation4 = new QPropertyAnimation(ui->lblProc2,"geometry");
    animation3 = new QPropertyAnimation(ui->lblProc3,"geometry");
    animation2 = new QPropertyAnimation(ui->lblProc4,"geometry");
    animation1 = new QPropertyAnimation(ui->lblProc5,"geometry");

    animation5->setDuration(1000);
    animation5->setStartValue(QRect(0,0,0,0));
    animation5->setEndValue(QRect(90, 120, 41, 16));
    animation5->start();

    animation4->setDuration(560);
    animation4->setStartValue(QRect(0,0,0,0));
    animation4->setEndValue(QRect(230, 120, 41, 16));
    animation4->start();

    animation3->setDuration(300);
    animation3->setStartValue(QRect(0,0,0,0));
    animation3->setEndValue(QRect(150, 160, 41, 16));
    animation3->start();

    animation2->setDuration(500);
    animation2->setStartValue(QRect(0,0,0,0));
    animation2->setEndValue(QRect(90, 210, 41, 16));
    animation2->start();

    animation1->setDuration(1000);
    animation1->setStartValue(QRect(0,0,0,0));
    animation1->setEndValue(QRect(220, 210, 41, 16));
    animation1->start();


}

void Simulation::on_pushButton_2_clicked()
{
    ui->tblInfo->setColumnCount(4);
    ui->tblInfo->setRowCount(5);
    ui->tblInfo->show();
    for(int i=0;i<ui->tblInfo->rowCount();i++)
    {
        ID[i] = 456+qrand()%456456;
    }

    for(int c=0;c<ui->tblInfo->columnCount();c++)
    {
        for(int r=0;r<ui->tblInfo->rowCount();r++)
        {
            switch (c) {
            case 0:
                ui->tblInfo->setItem(r,c,new QTableWidgetItem(QString::number(ID[c])));
                break;
            case 1:
                ui->tblInfo->setItem(r,c,new QTableWidgetItem(QString::number(100+qrand()%1000)));
                break;
            case 2:
                if((1+qrand()%10)%2==0)
                {
                    ui->tblInfo->setItem(r,c,new QTableWidgetItem("KernelMode"));
                }
                else
                {
                    ui->tblInfo->setItem(r,c,new QTableWidgetItem("UserMode"));
                }
                break;
            case 3:
                ui->tblInfo->setItem(r,c,new QTableWidgetItem(QString::number(100+qrand()%200)));
                break;
            }
        }


        animation1->setTargetObject(ui->prcIcon);
        animation1->setDuration(450);
        animation1->setStartValue(QRect(220,230,0,0));
        animation1->setEndValue(QRect(800,190 , 51, 51));
        animation1->start();

        animation2->setTargetObject(ui->prc2Icon);
        animation2->setDuration(500);
        animation2->setStartValue(QRect(220,230,0,0));
        animation2->setEndValue(QRect(720,190 , 51, 51));
        animation2->start();

        animation3->setTargetObject(ui->prc3Icon);
        animation3->setDuration(800);
        animation3->setStartValue(QRect(220,230,0,0));
        animation3->setEndValue(QRect(640,190 , 51, 51));
        animation3->start();

        animation4->setTargetObject(ui->prc4Icon);
        animation4->setDuration(300);
        animation4->setStartValue(QRect(220,230,0,0));
        animation4->setEndValue(QRect(560,190 , 51, 51));
        animation4->start();

        animation5->setTargetObject(ui->prc5Icon);
        animation5->setDuration(600);
        animation5->setStartValue(QRect(220,230,0,0));
        animation5->setEndValue(QRect(490,190 , 51, 51));
        animation5->start();


        animation1 = new QPropertyAnimation(ui->lblProc,"geometry");
        animation2 = new QPropertyAnimation(ui->lblProc2,"geometry");
        animation3 = new QPropertyAnimation(ui->lblProc3,"geometry");
        animation4 = new QPropertyAnimation(ui->lblProc4,"geometry");
        animation5 = new QPropertyAnimation(ui->lblProc5,"geometry");


        animation1->setDuration(450);
        animation1->setStartValue(QRect(220,230,0,0));
        animation1->setEndValue(QRect(800,170 , 41, 16));
        animation1->start();


        animation2->setDuration(500);
        animation2->setStartValue(QRect(220,230,0,0));
        animation2->setEndValue(QRect(720,170 , 41, 16));
        animation2->start();


        animation3->setDuration(800);
        animation3->setStartValue(QRect(220,230,0,0));
        animation3->setEndValue(QRect(640,170 , 41, 16));
        animation3->start();

        animation4->setDuration(300);
        animation4->setStartValue(QRect(220,230,0,0));
        animation4->setEndValue(QRect(560,170 , 41, 16));
        animation4->start();


        animation5->setDuration(600);
        animation5->setStartValue(QRect(220,230,0,0));
        animation5->setEndValue(QRect(490,170 , 41, 16));
        animation5->start();


    }

}

void Simulation::on_pushButton_3_clicked()
{

    ui->TimeTbl->setRowCount(2);
    ui->TimeTbl->setColumnCount(2);
    animation1->setTargetObject(ui->prcIcon);
    animation1->setDuration(1000);
    animation1->setStartValue(QRect(800,190,0,0));
    animation1->setKeyValueAt(0.3,QRect(1210,170,70,70));
    animation1->setEndValue(QRect(1220,520 , 45, 45));
    animation1->start();

    animation3->setTargetObject(ui->dispach);
    animation3->setDuration(1000);
    animation3->setStartValue(QRect(ui->dispach->x(),ui->dispach->y(),41,41));
    animation3->setKeyValueAt(0.5 ,QRect(ui->dispach->x(),ui->dispach->y(),91,101));
    animation3->setEndValue(QRect(ui->dispach->x(),ui->dispach->y() , 41, 41));
    animation3->start();

    for(int r=0;r<ui->TimeTbl->rowCount();r++)
    {
        for(int c=0;c<ui->TimeTbl->columnCount();c++)
        {
            if(c==0)
            {
                ui->TimeTbl->setItem(r,c,new QTableWidgetItem(QString::number(456+qrand()%456456)));
            }else
            {
                ui->TimeTbl->setItem(r,c,new QTableWidgetItem(QString::number(4+qrand()%10)));
            }

        }
    }


    animation2->setTargetObject(ui->prc2Icon);
    animation2->setDuration(1500);
    animation2->setStartValue(QRect(800,190,0,0));
    animation2->setKeyValueAt(0.3,QRect(1150,170,70,70));
    animation2->setEndValue(QRect(1150,520 , 45, 45));
    animation2->start();

    ui->lblProc->hide();
    ui->lblProc2->hide();


}

void Simulation::on_pushButton_4_clicked()
{
    ui->Terminate->show();
    animation1->setTargetObject(ui->prcIcon);
    animation1->setDuration(5000);
    animation1->setStartValue(QRect(ui->prcIcon->x(),ui->prcIcon->y(),45,45));
    animation1->setEndValue(QRect(1160 , 249, 45,45));
    animation1->start();

    timer->setInterval(500);
    timer->start();


}

void Simulation::HideTerminate()
{
    if(counter>3)
    {
        ui->Terminate->hide();
        ui->prcIcon->hide();
        timer->stop();
        counter=0;
    }else
    {
        counter++;
    }
}
