#include <iostream>
#include <iomanip>

int main()
{
    int n = 42;
    std::cout << n << std::endl;
    std::cout << std::hex << n << std::endl; // 16진수 2a
    std::cout << std::uppercase << n << std::endl; // 2A
    std::cout << std::oct << n << std::endl; // 8진수
    std::cout << std::dec << n << std::endl; // 다시 10진수 표현
    // 한번 변경된 내용은 다시 변경하기까지 상태가 유지된다.
    std::cout << std::setw(4) << n << std::endl; // 칸을 4개 만들어 뒷칸부터 출력
    std::cout << std::setw(4) << std::setfill('0') << n << std::endl; // 남은 칸에 0을 채움
}