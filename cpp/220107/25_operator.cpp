#include <iostream>
using namespace std;

// operator : 연산자

class Point
{
    private:
    int x;
    int y;
    public:
    Point (int a, int b) : x(a), y(b)
    {
        
    }

    Point Add( const Point& rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    // friend 사용
    /*
    Point operator+(const Point& rhs) // 연산자 오버로딩
    {
        return Point(x + rhs.x, y + rhs.y);
    }
    int GetX() const { return x;} // friend보다 안좋은 이유
                                  // friend는 선언한 함수만 x,y 접근 가능하지만
                                  // public한 멤버함수를 이용하면 아무나 멤버변수 상태를 알 수 있음
    int Gety() const { return y;}
    */
    friend Point operator+(const Point& lhs, const Point& rhs);

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

// friend 사용
/*
Point operator+(const Point& lhs, const Point& rhs) // 연산자 오버로딩
{
    // return Point(lhs.x + rhs.x, lhs.y + rhs.y); // 클래스 변수 접근 불가
    return Point(lhs.Getx() + rhs..Getx(), lhs.Gety() + rhs.Gety());
}
*/
Point operator+(const Point& lhs, const Point& rhs) // 연산자 오버로딩
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y); // 클래스 변수 접근 불가
}

int main()
{
    Point p1(1,1);
    Point p2(1,10);

    Point p3 = p1 + p2; // 오류 
    // Point p3 = p1.operator+(p2);
    // Point p3 = operator+(p1, p2);
    // 연산자 오버로딩 해주면 사용 가능
    // 1) 멤버변수 출력하는 멤버함수 이용
    // 2) friend 이용

    // Add 함수 만들기
    // Point p3 = p1.Add(p2);
    p3.Print();
}