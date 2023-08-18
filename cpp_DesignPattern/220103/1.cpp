/* (C언어 방식으로 작성한 코드)
 #include <stdio.h>

int main() 
{
    printf("Hello, C"\n);
}
*/

// 컴파일 방법 : g++ 1.cpp
//              clang++ 1.cpp
// 실행 방법 : ./a.out  (./ 는 현재 파일을 이용한다는 것을 알림)
//            ./a.exe

// 1. C++ 확장자
//   .cpp(가장 많이 사용), .cc(그다음 많이 사용), .cXX, .cp, .c++

// 2. C++ 컴파일러
// 1) clang++ 2) g++ 3) microsoft C++ Compiler

// 3. 표준(standard)를 생각하는 것이 중요하다. (언어를 배우기 위해선)
// -> 꾸준한 공부 필요, 하지만 새로 생기는 것들을 접하기 좋다
// -> C언어는 거의 변화가 없다. 
// C++ 1.0 - 98/03 (98년도 ~ 03년도)
// C++ 2.0 - 11/14 : Modern C++
// C++ 3.0 - 17/20

// C++ vs C언어
 #include <iostream> // C++ 방식에 맞춰 작성한 코드
 // C++ 표준 헤더 : 헤더 파일의 확장자가 없는 경우가 많다. ex) .h
 // C++ 에서 C 헤더를 사용하고 싶으면 #include <cstdio>
 #include <cstdio>
int main() 
{
    printf("Hello, C\n");
    std::cout << "Hello, C++" << std::endl;
}