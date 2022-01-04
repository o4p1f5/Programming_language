#include <iostream>
using namespace std;

// C++11에서는 포인터 0일 나타내는 nullptr를 제공합니다.

int main()
{
    // int *p = 0; 
    int *p = nullptr; // -> 0을 포인터롤 형변환
    // int a = nullptr; 에러발생
    bool b(nullptr); // 직접 초기화시 nullptr을 bool의 자동형변환 가능
}