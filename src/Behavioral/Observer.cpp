#include "../../include/Behavioral/Observer.h"

void Subject::Attach(Observer* observer)
{
    observers.push_back(observer);
}

void Subject::setState(int value)
{
    state = value;
    Notify();
}

int Subject::getState()
{
    return this->state;
}

void Subject::Notify()
{
    for (int i=0; i< observers.size(); i++)
    {
        observers[i]->Update(state);
    }
}

void ConcreteObserver::Update(int value)
{
    cout<<"New Update: "<<value<<endl;
}