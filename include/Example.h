#pragma once
#include <iostream>
#include <string>
using namespace std;

class Logger
{
    private:
        string mess=" ";
        Logger();
        ~Logger();
        static Logger* Instance;
    public:
        static Logger *GetInstance();
        void Log(const string&);
        string GetMess();
        
};

class Myvector
{
    private:
        int data[3] = {1,2,3};
    public:
        int* begin()
        {
            return data;
        }
    int* end()
    {
        return data+100;
    }
};



class Base
{
    public:
        virtual void Display()
        {
            cout<<"Base\n";
        }
};

class Chil: public Base
{
    public:
        void Display() override
        {
            cout<<"Chil\n";
        }
};





