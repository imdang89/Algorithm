#include "lib.h"
#include "Example.h"
#include "include/Behavioral/Observer.h"
#include "include/Algorithm/Sorting.h"
#include "include/Algorithm/Searching.h"
#include "SmartPointer.h"
#include "include/Algorithm/Stack.h"
#include <thread>

void demoThread()
{
    cout<<"Thread 1 dang chay\n";
}

int main()
{
    thread t_thread1(demoThread);
    t_thread1.join();



    return 0;
}