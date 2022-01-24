#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_click();
    void on_Exit_clicked();
    void on_txtCpu_textEdited(const QString &arg1);

    void on_txtRam_textEdited(const QString &arg1);

    void on_txtCore_textEdited(const QString &arg1);

    void on_txtStack_textEdited(const QString &arg1);

    void on_txtCode_textEdited(const QString &arg1);

    void on_txtData_textEdited(const QString &arg1);

    void PRGS();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
