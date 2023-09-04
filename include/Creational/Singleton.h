#pragma once
#include "../lib.h"


/* đảm bảo rằng một lớp chỉ có duy nhất một thể hiện (instance)duy nhất 
và cung cấp một cách để truy cập đến thể hiện đó từ bất kỳ đâu trong chương trình.*/
class Singleton
{
    private:
        Singleton();
        ~Singleton();
        static Singleton *Instance;
    public:
        static Singleton *GetInstance();
};