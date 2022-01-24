#ifndef PROCESS_H
#define PROCESS_H


#include "QString"
#include "QDebug"
#include <QObject>
#include <QWidget>


enum State{
    Creation,
    Ready,
    Running,
    Terminate,
    Block,
    Susspend,
    Wakup
};

enum Mode{
    KernelMode,
    UserMode
};


class Process
{
public:
    Process(int Id);
    Process(int ID,State s , Mode m , int ram);

    void setState(State state);
    void setMode(Mode m);
    void setRam(int Ram);
    void Dispach();
    void TimeOut();

    State GetState();
    Mode GetMode();
    int GetID();
    int GetRam();
    int getExeTime();
//    void move(int x,int y);
//    void move(int x,int y,int x2,int y2);

private:
    State state;
    Mode  mode;

    int Id;
    int Ram;
    int ExecuteTime;

    QString Stack_seg;
    QString Data_seg;
    QString Code_seg;
};

#endif // PROCESS_H

