// 1_namespace.cpp
// C언어의 문제점 : 이름 충돌 
// -> 코드를 공유하고 이를 배합하는 과정에서 같은 이름의 함수나 클래스가 충돌하는 경우가 생김
// namespace의 장점 : 이름 충돌을 막음
//                 :프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있다.
//                 : C++ 표준에서 제공하는 모든 요소들은 std의 이름 공간 안에 존재한다.
#include <iostream>

namespace Audio
{
    void init()
    {
        std::cout << "Audio::init" << std::endl;
    }
}

namespace Video
{
    void init()
    {
        std::cout << "Video::init" << std::endl;
    }
}

void init()
{
    std::cout << "Global init" << std::endl;
}

int main()
{
    // 이름공간의 함수들은 호출 시 이름을 명시해줘야 함
    Audio::init(); // ::은 이름 공간 지정연산자
    Video::init();
    init(); // 전역함수 호출
}