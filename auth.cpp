#include "auth.h"
#include "ui_auth.h"
#include <QPropertyAnimation>
#include "QTimer"
#include "QLineEdit"
#include "mainwindow.h"
QTimer *userMove,*passMove;
QLineEdit *username,*password;
Auth::Auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auth)
{

    userMove = new QTimer(this);
    passMove = new QTimer(this);

    ui->setupUi(this);

    username = ui->edtUser;
    password = ui->edtPass;


    connect(userMove,SIGNAL(timeout()),SLOT(animation_user()));
    connect(passMove,SIGNAL(timeout()),SLOT(animation_pass()));

    x[0]=ui->lblUSer->x();
    y[0]=ui->lblUSer->y();

    x[1]=ui->lblPAss->x();
    y[1]=ui->lblPAss->y();
}

Auth::~Auth()
{
    delete ui;
}



void Auth::on_edtUser_textEdited(const QString &arg1)
{

    userMove->setInterval(10);
    userMove->start();
}
void Auth::on_edtPass_textEdited(const QString &arg1)
{

    passMove->setInterval(10);
    passMove->start();
}

//--------------SLOT----------------


void Auth::animation_user(){

    if(username->text().isEmpty()){

        if(ui->lblUSer->y()<260)
            ui->lblUSer->move(x[0],y[0]++);
        else
        {
            userMove->stop();
            ui->lblUSer->setStyleSheet("color:red");
            username->setStyleSheet("border-color:red;color:red");

        }
    }
    else
    {
        if(ui->lblUSer->y()>235)
            ui->lblUSer->move(x[0],y[0]--);
        else{
            userMove->stop();
            ui->errorUser->hide();
            ui->lblUSer->setStyleSheet("color:green");
            username->setStyleSheet("border-color:green;color:green");
        }}
}
void Auth::animation_pass(){
    if(password->text().isEmpty()){

        if(ui->lblPAss->y()<340)
            ui->lblPAss->move(x[1],y[1]++);
        else{
            passMove->stop();
            ui->lblPAss->setStyleSheet("color:red");
            password->setStyleSheet("border-color:red;color:red");
        }
    }
    else
    {
        if(ui->lblPAss->y()>315)
            ui->lblPAss->move(x[1],y[1]--);
        else{
            passMove->stop();
            ui->errorPass->hide();
            ui->lblPAss->setStyleSheet("color:green");
            password->setStyleSheet("border-color:green;color:green");
        }
    }
}



void Auth::on_pushButton_clicked()
{
    if(username->text()=="Ershad" && password->text()=="Raoufi")
    {
        this->close();
        MainWindow *main = new MainWindow();
        main->show();
    }
    else
    {
        ui->edtUser->text()=="Ershad" ? ui->errorUser->hide() : ui->errorUser->show();
        ui->edtPass->text()=="Raoufi" ? ui->errorPass->hide() : ui->errorPass->show();
    }
}

void Auth::on_pushButton_2_clicked()
{
    QApplication::exit();
}
