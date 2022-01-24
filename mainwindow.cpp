#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QPropertyAnimation>
#include <QDebug>
#include "simulation.h"
#include "customeedt.h"
#include "QTimer"


QTimer *prgsTimer;
int p=0;
QPropertyAnimation *anim = nullptr;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    anim = new QPropertyAnimation(ui->progressBar,"geometry");
    ui->statusBar->hide();
    prgsTimer = new QTimer(this);

    connect(ui->txtRam,SIGNAL(click()),SLOT(on_click()));
    connect(prgsTimer,SIGNAL(timeout()),SLOT(PRGS()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    if(ui->txtCode->text().length()!=0 &&
            ui->txtCore->text().length()!=0 &&
            ui->txtCpu->text().length()!=0 &&
            ui->txtData->text().length()!=0 &&
            ui->txtRam->text().length()!=0&&
            ui->txtStack->text().length()!=0){

        anim->setDuration(500);
        anim->setStartValue(QRect(150,800,331,23));
        anim->setEndValue(QRect(150,670,331,23));
        anim->start();


        prgsTimer->setInterval(30);
        prgsTimer->start();


    }

}



void MainWindow::on_Exit_clicked()
{
    QApplication::exit();
}


void MainWindow::on_click(){

}

void MainWindow::on_txtCpu_textEdited(const QString &arg1)
{
    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtCpu->backspace();
    }
    if(ui->txtCpu->text().isEmpty())
    {

        ui->lblCpu->setStyleSheet("color:red;");
        ui->icnCpu->setStyleSheet("image: url(:/icon/attantion.png);");
        ui->errCpu->setText("Please Enter a Number");
        ui->errCpu->setStyleSheet("color:red");
    }else
    {

        ui->lblCpu->setStyleSheet("color:green;");
        ui->errCpu->setText("Data is Valid ");
        ui->errCpu->setStyleSheet("color:green");
        ui->icnCpu->setStyleSheet("image: url(:/accept/acc.ico);");
    }
}

void MainWindow::on_txtRam_textEdited(const QString &arg1)
{
    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtRam->backspace();
    }
    if(ui->txtRam->text().isEmpty())
    {

        ui->lblRam->setStyleSheet("color:red;");
        ui->icnRam->setStyleSheet("image: url(:/icon/attantion.png);");
        ui->errRam->setText("Please Enter a Number");
        ui->errRam->setStyleSheet("color:red");
        ui->icnRam->show();
    }else
    {

        ui->lblRam->setStyleSheet("color:green;");
        ui->errRam->setText("Data is Valid");
        ui->errRam->setStyleSheet("color:green");
        ui->icnRam->setStyleSheet("image: url(:/accept/acc.ico);");
        ui->icnRam->show();
    }
}

void MainWindow::on_txtCore_textEdited(const QString &arg1)
{
    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtCore->backspace();
    }
    if(ui->txtCore->text().isEmpty())
    {

        ui->errCore->setText("Please Enter a Number");
        ui->errCore->setStyleSheet("color:red;");
        ui->lblCore->setStyleSheet("color:red;");
        ui->icnCore->setStyleSheet("image: url(:/icon/attantion.png);");
    }else
    {

        ui->errCore->setText("Data is Valid ");
        ui->errCore->setStyleSheet("color:green;");
        ui->lblCore->setStyleSheet("color:green;");
        ui->icnCore->setStyleSheet("image: url(:/accept/acc.ico);");
    }
}

void MainWindow::on_txtStack_textEdited(const QString &arg1)
{
    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtStack->backspace();
    }
    if(ui->txtStack->text().isEmpty())
    {

        ui->errStack->setText("Please EntePRGSr a Number");
        ui->errStack->setStyleSheet("color:red");
        ui->lblStack->setStyleSheet("color:red;");
        ui->icnStack->setStyleSheet("image: url(:/icon/attantion.png);");
    }else
    {

        ui->errStack->setText("Data is Valid ");
        ui->errStack->setStyleSheet("color:green");
        ui->lblStack->setStyleSheet("color:green;");
        ui->icnStack->setStyleSheet("image: url(:/accept/acc.ico);");
    }
}

void MainWindow::on_txtCode_textEdited(const QString &arg1)
{

    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtCode->backspace();
    }
    if(ui->txtCode->text().isEmpty())
    {
        ui->lblCode->setStyleSheet("color:red;");
        ui->icnCode->setStyleSheet("image: url(:/icon/attantion.png);");
        ui->errCode->setText("Please Enter a Number");
        ui->errCode->setStyleSheet("color:red");
    }else
    {

        ui->errCode->setText("Data is Valid ");
        ui->errCode->setStyleSheet("color:green");
        ui->lblCode->setStyleSheet("color:green;");
        ui->icnCode->setStyleSheet("image: url(:/accept/acc.ico);");
    }
}

void MainWindow::on_txtData_textEdited(const QString &arg1)
{
    if((arg1>="a" && arg1<="z") || (arg1>="A" && arg1<="Z"))
    {
        ui->txtData->backspace();
    }
    if(ui->txtData->text().isEmpty())
    {
        ui->errData->setText("Please Enter a Number");
        ui->errData->setStyleSheet("color:red");
        ui->lblData->setStyleSheet("color:red;");
        ui->icnData->setStyleSheet("image: url(:/icon/attantion.png);");
    }else
    {
        ui->errData->setText("Data is Valid ");
        ui->errData->setStyleSheet("color:green");
        ui->lblData->setStyleSheet("color:green;");
        ui->icnData->setStyleSheet("image: url(:/accept/acc.ico);");
    }
}

void MainWindow::PRGS()
{
    if(p<100)
        ui->progressBar->setValue(++p);
    else
    {
        prgsTimer->stop();
        this->close();
        Simulation *sim = new Simulation();
        sim->show();
    }
}
