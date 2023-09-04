#include "Example.h"

Logger::Logger(){}

Logger::~Logger(){}

Logger* Logger::Instance = NULL; 

Logger* Logger::GetInstance()
{
    if(Instance == NULL)
    {
        Instance = new Logger();
    }
    return Instance;
}

void Logger::Log(const string& message)
{
    this->mess = message;
    cout<<"\n\tLog: "<<message<<endl;
}

string Logger::GetMess()
{
    return mess;
}