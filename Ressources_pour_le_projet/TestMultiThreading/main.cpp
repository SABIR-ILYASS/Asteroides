#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void processing1(mutex &m)
{
    for (int i=0;i<10;i++) {
        m.lock();
        cout<<"thread 1:"<<i<<endl;
        m.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void processing2(mutex &m)
{
    string letters="ABCDEFGHIJ";
    for (char letter : letters) {
        m.lock();
        cout<<"thread 2:"<<letter<<endl;
        m.unlock();
        this_thread::sleep_for(chrono::milliseconds(15));
    }
}



int main()
{
    // declares the mutex to protect concurrent cout
    mutex mutx;

    // starts the two threads
    thread th1([&mutx](){processing1(mutx);});
    thread th2([&mutx](){processing2(mutx);});

    // wait for the end
    th1.join();
    th2.join();

    return 0;
}
