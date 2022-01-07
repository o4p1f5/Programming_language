#include <iostream>
using namespace std;

class Sample
{
    int data = 42; // C++11부터 멤버 변수 초기화 가능
    static int cnt;
    static const int data2 = 100; // 상수 정적 멤버변수는 초기화 가능
public:
    static void foo()
    {
        // data = 0; // 객체가 없어도 동작하는 함수이기때문에 오로지 정적멤버변수만 접근 가능
        cnt = 0;
    }
};

int Sample:: cnt = 0;