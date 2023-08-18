#include <iostream>
using namespace std;

/*
template <typename T>
clas List
{
    public:
    void push_front(const T&s) {}
};

List<int> st; // 전역변수 : 스레드 안전하게 접근할 수 있어야한다.
*/

// 1. 동기화 여부를 인터페이스 기반 다른 클래스로 분리 => 전략 패턴
struct Sync
{
    // 가상함수의 오버헤드가 많이 호출되는 경우 문제 발생
    virtual void Lock() =0;
    virtual void Unlock() =0;
};

template <typename T>
class List
{
    Sync* pSync = nullptr;
    public:
    void SetSync(Sync* p)
    { pSync = p; }
    void push_front(const T& a)
    {
        pSync->Lock();
        cout << "데이터 삽입" << endl;
        pSync->Unlock();
    }
};

class MultiThread : public Sync // 동기화 정책의 인터페이스를 구현하는 클래스
{
    public:
    void Lock() override
    {
        cout << "동기화 시작" << endl;
    }
    void Unlock() override
    {
        cout << "동기화 종료" << endl;
    }
};

class SingleThread : public Sync
{
    public:
    void Lock() override {}
    void Unlock() override {}
};

List<int> st;
MultiThread t;

int main()
{
    st.SetSync(&t);
    st.push_front(10);
}