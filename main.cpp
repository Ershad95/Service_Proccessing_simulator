#include "mainwindow.h"
#include <QApplication>
#include "splash.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Splash dialog;
    dialog.show();

    return a.exec();
}
