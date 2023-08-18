#include <iostream>
using namespace std;
// 생성자
//  - 객체가 생성되면 초기화를 위해 자동으로 호출되는 함수
//  - 클래스 이름과 동일하고, 반환타입을 표기하지 않습니다.
//  - 생성자 오버로딩이 가능합니다.
//   > 다른 타입의 파라미터를 가지는 생성자를 여러개 제공하는 것이 가능합니다.
//  - 사용자가 만들지 않으면, 컴파일러가 인자가 없는 생성자를 하나 제공합니다.
//   => 기본 생성자(default constructor)

// 상태
// => 멤버 데이터 변수
// : 외부에서 조작할 수 없도록 만드는 것이 좋다.
// 행위 : 멤버함수 / 메소드
// => 멤버 데이터 변수를 조작하는 다양한 함수를 제공

// 생성자 예시
// 객체를 힙에 생성할 때, nem는 생성자가 호출되지만, malloc은 생성자가 호출되지않음
// => 소멸자도 동일
class Point
{
    int x;
    int y;
public:
    Point() // 기본 생성자
    {
        cout << "Point()" << endl;
        x=0;
        y=0;
    }
    Point(int a, int b)
    {
        cout << "Point(int, int)" << endl;
        x=a;
        y=b;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
};
/*
int main()
{
    Point x[3]; // 기본 생성자 3번 호출
    // 기본 생성자가 없으면  Point x[3] = {  Point (10,20), Point(20,30)};로
    // 명시적으로 초기화 해줘야함
    Point p1;
    Point p2(10,20;

    Point *p3 = new Point(10,20); // 생성자 호출
    delete p3; // 소멸자 호출
}
*/

class Rect
{
    Point p1;
    Point p2;
public :
    Rect() 
    {
        cout << "Rect()" << endl;
    }
    ~Rect() 
    {
        cout << "~Rect()" << endl;
    }
};

int main()
{
     Rect r;
}