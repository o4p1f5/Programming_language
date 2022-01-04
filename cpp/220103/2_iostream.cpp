// 2_iostream.cpp
// C++ 표준 입출력
// 1. C언어의 표준 입출력 함수
//    -> scanf, printf
// C++의 표준 입출력 함수
#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n; // C언어의 &n 처럼 주소를 보내지않아도 직접 처리할 수 있다.
                   // 따로 자료형을 표현하지않아도 된다.
    std::cout << "out : " << n << std::endl; // std::endl
}