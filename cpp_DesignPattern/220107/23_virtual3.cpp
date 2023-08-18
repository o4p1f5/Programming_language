#include <iostream>
#include <vector>
using namespace std;

class A
{
    int a;
    public : 
    virtual void foo()
    { cout << "foo" << endl; }
};

class B
{
    int b;
    public : 
    virtual void goo()
    { cout << "goo" << endl; }
};

int main()
{
    A aaa;
    B* p = reinterpret_cast<B*> (& aaa);

    p->goo(); // 정적바인딩 -> goo함수 출력(B* 자료형)
    // 동적바인팅 -> foo함수 출력 (&aaa의 가상함수 테이블이 가리키는 함수)
}