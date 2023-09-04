#pragma once
#include "lib.h"



class SmartPtr
{
    int *ptr;
    // for use of explicit keyword
    public:
        explicit SmartPtr(int*);
        ~SmartPtr();
        int& operator*();
};