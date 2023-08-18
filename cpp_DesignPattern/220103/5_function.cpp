#include <iostream>

// default parameter : 함수에서 전달되는 인자가 없는 경우, 기본값을 사용한다.
// : 기본값을 지정할 때 뒤에서부터 지정해야한다.
// ex) void foo(int a = 10,int b, int c, int d) [X]
// : 함수를 선언과 구현을 분리하면 선언부에만 표기한다.

void foo(int a,int b, int c=5, int d=20); // 헤더파일에 존재

int main()
{
    foo(10,20,30,40);
    foo(20,30); // a=20,b=30,c=5,d=20이 된다.
}

void foo(int a,int b, int c, int d) // void foo(int a,int b, int c=10, int d=40) [x] -> 컴파일 오류 발생
// 소스파일에 존재 // void foo(int a,int b, int c /* = 5 */, int d/* = 20 */)
{
    cout << a << ", " << b << ", " << c << ", " << d << endl;
}