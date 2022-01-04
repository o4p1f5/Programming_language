// C++ 변수의 특징
// C++11 부터는 2진수 표기가 가능하다. 자릿수 표기도 가능.
// C언어에서는 변수선언을 중간에 할 수 없지만 C++에서는 가능하다.
#include <iostream>
/*
int main()
{
    int n1 = 0xfa; // 11111010
    int n2 = 0b11111010; // 2진수 표현가능
    int n3 = 0b1111'1010; // 자릿수 표기가능
    std::cout << n1 << ", " << n2 << ", " << n3 << std::endl;
}*/

// 구조체(struct) : 사용자 정의 타입을 만들어 사용

struct Point
{
    //C++에서부터는 구조체를 만들때 초기값지정이 가능하다.
    int x = 10;
    int y = 20;
};

int main()
{
    struct Point p1; // C언어 방식
    Point p2; // C++에서는 struct를 붙이지 않아도 된다.
    // 컴파일 시, g++ (소스파일) -std=c++14 로 작성하여 컴파일해야 경고가 안뜬다.
    std::cout << p1.x << ", " << p1.y << std::endl;
}