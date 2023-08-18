#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    Point(const Point&rhs) : x(rhs.x), y(rhs.y) {} // 모든 멤버데이터 복사
    // 기본생성자는 다른 생성자가 따로 지정되어있지않으면 자동으로 생성되지만
    // 다른 생성자(ex. 복사생성자)가 지정되어있으면 생성되지않음
    // 복사생성자도 다른 생성자가 따로 지정되어있지않으면 기본생성자랑 같이 자동으로 생성된다.

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point p1;
    Point p2(10,20);
    Point p3(p2); // Point(const Point&) => 복사 생성자를 자동으로 생성

    p2.Print();
    p3.Print();
}