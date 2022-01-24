#include "process.h"
#include "qdebug.h"
Process::Process(int Id)
{
    this->Id=Id;
}

Process::Process(int ID, State s, Mode m, int ram)
{
    Id=ID;
    state=s;
    mode=m;
    Ram=ram;
}
void Process::setState(State state)
{
    this->state=state;
}

void Process::setRam(int Ram)
{
    this->Ram=Ram;
}

void Process::Dispach()
{
    this->ExecuteTime = 3+qrand()%10;
}
void Process::TimeOut()
{
    this->ExecuteTime=0;
}

int Process::GetID()
{
    return Id;
}

int Process::GetRam()
{
    return Ram;
}

int Process::getExeTime()
{
    return ExecuteTime;
}



State Process::GetState()
{
    return state;
}

Mode Process::GetMode()
{
    return mode;
}
