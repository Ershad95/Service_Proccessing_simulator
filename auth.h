#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = 0);
    ~Auth();

private slots:
    void animation_user();
    void animation_pass();
    void on_edtUser_textEdited(const QString &arg1);
    void on_edtPass_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void edit(int);

private:
    int x[2]{0,0};
    int y[2]{0,0};
    Ui::Auth *ui;

};

#endif // AUTH_H
