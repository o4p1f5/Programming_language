#include <iostream>
using namespace std;

class Point
{
    public:
    int x = 0;
    int y = 0;

    // 컴파일이 만드는 대입 연산자 => 얉은 복사
    // => 클래스에 포인터 멤버가 있으면 문제발생
    // => 멤버함수 구현만 허용

    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }
};

int main()
{
    Point p1;
    Point p2 = p1; // 초기화 -> 복사 생성자

    p2 = p1; // 대입 연산자 // 컴파일러 자동 제공
    // p2.operator=(p1)

    int a =0, b=0,c=0;
    a=b=c=20; // c=20 -> b=c -> a=b
    // 대입 연산자가 자기참조하게 만들어줌
}
