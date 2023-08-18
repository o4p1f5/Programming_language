#include <iostream>
using namespace std;

class Test
{
    int x;
    public:
    const int *getAddress() const
    {
        return &x; // x의 타입은 const int 타입, 반환자료형이 잘못됨
    }

    //const 함수중복 가능
    void foo()
    {
        cout << "foo" << endl;
    }
    void foo() const
    {
        cout << "const foo" << endl;
    }
    void goo() const;
};

void Test::goo() const {}

int main()
{
    Test t1;
    // const Test t2; // 상수는 반드시 초기화 시켜줘야 함

    t1.foo(); // foo 호출
    //t2.foo(); // const함수 foo 호출
}