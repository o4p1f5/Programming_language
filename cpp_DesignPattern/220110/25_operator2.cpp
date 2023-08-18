#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public :
    Point (int a, int b) : x(a), y(b)
    {}
    // firend를 이용한 일반함수
    friend Point operator+(const Point& lhs, const Point& rhs)
    {
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend int operator+(int a, const Point& b);
    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};
// 연산의 결과로 내부 멤버변수의 변경이 발생 => 멤버함수 이용
// 연산의 결과로 내부 멤버변수의 변경이 없다 => 일반 함수

// 연산자 재정의의 한개 이상의 인자는 반드시 사용자 정의 타입이어야한다
int operator+(int a, const Point& b)
{
    return a + b.x;
}
/*
int operator+(int a, int b)
{
    return a + b; // 오류
}
*/

// 인자의 개수를 변경할 수 없다.
// +, -, *, /, => 2개의 인자를 받는 일반함수 혹은 1개의 안자를 받는 멤버함수
// 연산자 우선순위 변경 불가능 ( 더하기연산보다 곱하기 연산이 빠르다)
// 새로운 연산자는 만들 수 없다.
// ::, ., *, ? => 재정의 불가능 연산자
// =, (), [], -> => 멤버함수로만 만들 수 있는 연산자

class MyVector
{
public:
    int operator[] (int index)
    {
        return 42;
    }
};

int main()
{
    MyVector v;
    cout << v[10] << endl;

    Point p1(10,10);
    Point p2(20,20);

    int result = 42 + p1;
    cout << result << endl;

    Point p3 = p1 + p2; // operator+(p1, p2) // p1.operator+(p2)
    p3.Print();
}