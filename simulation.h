#ifndef SIMULATION_H
#define SIMULATION_H

#include <QWidget>

namespace Ui {
class Simulation;
}

class Simulation : public QWidget
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void HideTerminate();

private:
    Ui::Simulation *ui;
};

#endif // SIMULATION_H
