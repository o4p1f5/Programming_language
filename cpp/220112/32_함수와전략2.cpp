#include <iostream>
using namespace std;

void foo() {}
inline void goo() {}
// 인라인 함수는 함수 포인터에 담아서 호출할 수 없다. (함수 포인터 -> 실행시간)

int main()
{
    foo();
    goo();

    void(*f) () = &foo;
    f = &goo;

    // 함수포인터를 통해 호출 : f가 어떤 함수를 가르킬지 컴파일 시간에 판단 X
    (*f)();
    f();
}