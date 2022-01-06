#include <iostream>
using namespace std;

// C언어의 캐스팅 - 무조건 작동하진 않기때문에 위험성이 있다
/*
int main()
{
    double d = 3.4;
    int n =d; // 자동형변환
    // int *p = &d; -> double*를 자동형변화해 주진 못함
    int *p = (int*) &d; // 캐스팅연산을 이용해 형변화해줌
}*/

// 문제점
/*
int main()
{
    int n =0;
    double *p = (double*) &n;
    *p = 3.14; // 포인터의 메모리크기는 4byte, double은 8byte 이므로, 크기 오류 발생
    // 위험한 연산
}
*/

// C++ 4가지의 캐스팅 - c언어의 문제점 보완
// 1) static_cast : 가장 기본적인 연산자 : 컴파일 과정에서 캐스팅 수행 : 위험한 캐스팅은 걸러줌
/*
int main()
{
    int n =0;
    void*p =&n; // void * : 모든 타입의 주소를 담을 수 있는 포인터 // 참조대상의 크기를 몰라 참조연산은 불가능
    int * pi = static_cast<int *>(p); // void* -> int* 가능
    double *pd = static_cast<double *>(pi); // int* -> double* 불가능 // 4byte -> 8byte
    // 2) reinterpret_cast
    double *pd1 = reinterpret_cast<double*>(pi); // int* -> double* 가능 // 4byte -> 8byte
}
*/
// 3) const_cast : 메모리의 상수성을 제거
/*
int main()
{
    const int n = 10;
    int *p = &n; // const int* -> int* 자동형변환 불가능
    int *p = const_cast<int *>(&n);
}
// 4) dynamic_cast 
