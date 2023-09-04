#include"../../include/Creational/Singleton.h"


Singleton::Singleton(){};

Singleton::~Singleton(){};

Singleton* Singleton::Instance = NULL;

Singleton* Singleton::GetInstance()
{
    if(Instance == NULL)
    {
        Instance = new Singleton();
    }
    return Instance;
}