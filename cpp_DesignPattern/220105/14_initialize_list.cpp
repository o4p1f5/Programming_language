#include <iostream>
using namespace std;
// 초기화 리스트

class Point
{
    int x,y;
    const int c; // 반드시 초기화리스트를 사용해야하는 부분
    int &ra; // 반드시 초기화리스트를 사용해야하는 부분

public:
    Point(int a,int b) : x(a), y(b), c(42), ra(a) // 초기화 리스트 : 멤버 데이터의 값을 초기화
    {
    }
};

class Rect
{
    Point p1; 
public:
    Rect() : p1(10,20) {} // 기본 생성자가 제공되지 않는 멤버데이터에 대한 초기화 필요
};

int main()
{
    // const int c; // 오류 : 상수를 반드시 초기화 필요
    int a = 10; // 초기화
    int b;
    b = 10; // 대입
}