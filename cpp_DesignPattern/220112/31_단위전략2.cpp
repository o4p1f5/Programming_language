#include <iostream>
using namespace std;

// Tempalte 기반의 정책교체
// => Policy Based Design(단위 전략)
// 장점 : 가상함수가 아니라 인라인 함수라서 호출에 따른 성능저하가 없다
// 단점 : Template 인자이므로, 실행시간에 종책교체가 불가능함, 컴파일할 때 정책이 결정된다.
// => 정책을 담은 코드를 컴파일 시간에 생성하는 기술

// 스레드의 정책을 가지는 정책 클래스 만들기

class SingleThread
{
    public:
    inline void Lock() {}
    inline void Unlock() {}
};

class MultiThread
{
    public:
    inline void Lock() {cout << "동기화 시작" << endl;}
    inline void Unlock() {cout << "동기화 종료" << endl;}
};

template <typename T, typename ThreadModel = SingleThread>
class List : public ThreadModel
{
    public : 
    void push_front(const T& a)
    {
        ThreadModel::Lock();
        cout << "데이터 삽입" << endl;
        ThreadModel::unlock();
    }
};

List<int, MultiThread> s1;

int main()
{
    // List<int, SingleThread> s2;
    List<int> s2;
    s1.push_front(10);
    s2.push_front(20);
}