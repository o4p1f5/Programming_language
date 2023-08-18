// 1_namespace2.cpp
#include <iostream>
// 1. 전체 이름을 사용하는 방법(가장 권장하시는 방법)
// ex) std::cout, std::endl, std::printf
// 2. using 선언을 이용하는 방식
// using std::cout; using std::endl;
// 3. using 지시어
// using namespace std; 
// std를 열어버렸으므로 namespace가 의미없어짐. 실제 제품코드를 만들때는 절대 사용하면 안됨
// int count; // using namespace std; 를 사용하면 충돌발생함 
int main()
{
    // count = 10; // std::count() 로 사용가능
    std::cout << "Hello, cpp" << std::endl
              << "Hello, cpp" << std::endl;
}