#include <iostream>

struct Point
{
    int x,y;
};

/*int main() // C++14
{
    int n1 = 42; // 할당연산자 = 이용 : 복사 초기화
    int n2(42); // C++ 초기화 문법 // () : 직접 초기화
    std::cout << n1 << ", " << n2 << std::endl;

    // 배열과 구조체 초기화 방법
    Point p = {10,20};
    int x[3] = {10,20,30};

}*/

//C++11 : 일관된 방법을 통해 변수 초기화 가능
int main()
{
    int n1 = {0};// = : 복사 초기화
    int x1[3]={1,2,3};
    Point p1={10,20};

    int n2{0}; // 직접초기화 // 불필요한 복사를 줄이기 위해 직접 초기화 이용
    int x2[3]{1,2,3};
    Point p2{10,20};
    for(int i = 0; i < 3 ;i++)
    {
    std::cout << n1 << ", " << x1[i] << ", " << p1.x << ", " << p1.y << std::endl;
    }

    for(int i = 0; i < 3 ;i++)
    {
    std::cout << n2 << ", " << x2[i] << ", " << p2.x << ", " << p2.y << std::endl;
    }

    /*
    int n3 = 3.14; // warning 발생 - 자료형 오류
    std::cout << n3 << std::endl;

    int n4 {3.14}; // 데이터 손실이 발생하는 잘못된 초기화에 대해서 컴파일 오류(error)가 발생한다.
    std::cout << n4 << std::endl;

    char c1 = 300; // 오버플로우 발생 // warning
    char c2{300}; // 오버플로우를 컴파일 오류에서 확인
    */
}