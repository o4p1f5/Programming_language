#include <iostream>
using namespace std;

// this : 멤버 함수를 호출한 객체의 주소가 전달됨
class Point
{
    int x;
    int y;

public:
    void set(int a,int b) // void set(Point* const this, int a,int b)
    {
        this->x=a;
        this->y=b;
    }

    void foo() // void foo(Point* const this)
    {
        cout << this << endl;
    }

    static void goo() // 정적멤버함수 -> this 사용X
    {
    }
    static int add(int a,int b) // 정적멤버함수 -> this 사용X
    {
        return a+b;
    }
    // Point::add의 타입 -> int (int, int)

    int hoo(int a, int b)
    {
        return a+b;
    }
    // hoo의 타입 -> int (Point* this, int, int)
};

int sub(int a,int b) // sub의 타입 -> int (int, int)
{
    return a-b;
}

int main()
{

    int (*fp)(int,int) = &Point::add;
    fp = &sub;

    Point p1;
    // 오류 fp = &p1.hoo(); 
    Point p2;

    p1.set(10,20); // Point::set(&p1, 10, 20);
    p2.set(20,30); // Point::set(&p2, 20, 30);
    
    cout << &p1 << endl;
    p1.foo();
    cout << &p2 << endl;
    p2.foo();
}