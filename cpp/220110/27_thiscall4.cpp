#include <iostream>
using namespace std;

// g++ 27_thiscall4.cpp -lpthread // 라이브러리 연동
/*
#include <pthread.h>

void* foo(void* arg)
{
    cout << "foo" << endl;
    return 0;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);

    pthread_join(thread, nullptr);

    cout << "main end" << endl;
}
*/

// 스레드 클래스를 설계
//  Thread 라이브러리를 사용하는 방법.
class Thread 
{
    pthread_t thread; // 스레드 제어 핸들
public:
    virtual ~Thread() { }
    // 모든 부모 클래스는 가상 소멸자를 제공.

    void run()
    {
        // 스레드 생성
        pthread_create(&thread, nullptr, &_threadLoop, this);
        // 일반 함수 포인터에 멤버 함수 포인터는 담을 수 없지만,
        // 정적 멤버 함수 포인터는 담을 수 있다.
        // => _threadLoop라는 정적멤버함수 만들기
    }

    static void* _threadLoop(void* arg) // run()에서 arg에 this 전달
    {
        Thread* self = static_cast<Thread*>(arg); // 캐스팅
        // 정적 멤버 함수안에서 일반 멤버 함수를 호출하는 방법.
        self->threadLoop();

        return 0;
    }

    void join()
    {
        pthread_join(thread, nullptr);
    }

    // virtual bool threadLoop() { return false; }
    virtual bool threadLoop() = 0; // 순수가상함수
};

class MyThread : public Thread 
{
public:
    bool threadLoop() override
    {
        cout << "MyThread threadLoop" << endl;
        return true;
    }
};

int main()
{
    MyThread t;
    t.run(); // 이 순간 스레드가 생성되어서, 가상함수인 threadLoop()를 수행해야 한다.

    t.join();
}