#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point() {cout << "Point()"<<endl;}
    Point(int a, int b) : x(a), y(b) {cout << "Point(int, int)"<<endl;}
    ~Point() {cout << "~Point()"<<endl;}
    Point(const Point&rhs) {cout << "Point(const Point&)"<<endl;}
    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

Point p(1,2);
Point foo()
{
    printf("foo\n");
    return p; 
}
Point &foo2() 
{
    printf("foo2\n");
    return p; 
}
Point &foo3() 
{
    Print x;
    return x;
    // x는 함수가 끝나면 사라지는 메모리
    // => 사라지는 메모리에 대한 참조를 반환하는 것은 미정의 사항
}


int main()
{
    // foo().x = 10; // 반환된 임시객체는 수정이 불가능하다.

    foo2().x = 10; // 참조를 이용한 함수이므로 임시객체가 없다. // 오류가 생기지 않음
}