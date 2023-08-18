#include <iostream>
#include <vector>
using namespace std;

class A
{
    public : 
    virtual void foo(int a =10)
    { cout << "A: " << a << endl; }
};

class B : public A
{
    public : 
    void foo(int a =20) override
    { cout << "B: " << a << endl; }
};

int main()
{
    A a;
    a.foo(); // A: 10

    B b;
    b.foo(); // B : 20

    A* p = new B;
    p->foo(); // B : 10 ???
    // 가상 함수는 런타임에, 디폴트 매개변수는 컴파일타임에 동작
    // => 가상함수에 되도록이면 기본 인자를 사용하지 말자. 사용했다면 오버라이딩할 때 변경하지말자.
}