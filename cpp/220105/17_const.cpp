#include <iostream>
using namespace std;

// 상수 멤버 함수
class Point
{
    int x,y;
public:
    Point(int a, int b) : x(a), y(b) {}
    void move (int d)
    {
        x += d;
        y += d;
    }
    void print() const // 상수 멤버 함수
    // 함수안의 데이터가 상수가 됨 // 데이터 변경 불가
    {
        // x+= 1; // 변경불가
        cout << x << ", " << y << endl;
    }
};


void foo(const Point &p1) // 객체를 함수에 전달할 때, const&를 통해 전달
// 전달된 객체는 상수취급
{
    // p1.move(10); // 상수멤버함수만 호출가능해서 컴파일 오류발생
    p1.print();
}


int main()
{
    // const Point p(20,30); 
    // ** 상수 멤버함수가 필요한 이유 : 상수 객체는 상수 멤버 함수만 호출가능
    Point p(20,30);
    p.move(10);
    p.print();
    foo(p);
}