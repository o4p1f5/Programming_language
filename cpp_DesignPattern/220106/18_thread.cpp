#include <iostream>
// #include <thread> // c++11
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *foo(void *foo)
{
    for(int i=0;i<10000000; ++i)
    {
        usleep(200000);
        cout << "foo" << endl;
    }

    return nullptr;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);
    // 컴파일 시 두 반복문이 동시에 동작 => 스레드
    for(int i=0;i<10000000; ++i)
    {
        usleep(100000);
        cout << i << endl;
    }
}

// g++ 18_thread.cpp -lpthread // 라이브러리 프로그램