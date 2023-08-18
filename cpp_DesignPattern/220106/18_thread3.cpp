#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
void foo()
{
    cout << "foo" << endl;
}

int main()
{
    cout << "main thread" << endl;
    thread t1(&foo);

    t1.join(); // 스레드 종료 전까지 프로세서 종료 방지
}
*/
int sum =0;
mutex m;

void thread_routine(const char* name) 
{
    cout << name << endl;
    for(int i=0;i<100000;++i)
    {
        m.lock();
        sum += 1;
        m.unlock();
    }
}

int main()
{
    thread t1(&thread_routine, "A");
    thread t2(&thread_routine, "B");

    t1.join();
    t2.join();

    cout << "sum : " << sum << endl;
}