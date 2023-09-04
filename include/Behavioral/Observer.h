#pragma once
#include "../lib.h"

class Observer
{
    public:
        virtual void Update(int value) =0;
};

class Subject
{
    private:
        int state;
        vector<Observer*> observers;
    public:
        void Attach(Observer*);
        void setState(int);
        int getState();
        void Notify();
};

class ConcreteObserver : public Observer
{
    public:
        void Update(int);
};