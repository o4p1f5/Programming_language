#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point() {cout << "Point()"<<endl;}
    Point(int a, int b) {cout << "Point(int, int)"<<endl;}
    ~Point() {cout << "~Point()"<<endl;}
    Point(const Point&rhs) {cout << "Point(const Point&)"<<endl;}
    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

// 복사생성자 호출 경우

// 1) 메인문 변수 생성
/*
int main()
{
    Point p1; // 기본생성자 호출
    Point p2(p1); // 복사생성자 호출
    Point p3 = p1; // 복사생성자 호출 // 위와 동일
    Point p4{p1}; // 복사생성자 호출
    Point p5 = {p1}; // 복사생성자 호출

    p2.Print();
    p3.Print();
}
*/

// 2) 함수 전달
/*
void foo(Point p) // 복사생성자 호출 // 값에 의한 전달일 때
{
    // 함수를 빠져나올 때 만들어졌던 객체 p가 삭제되면서 소멸자 호출
}
void foo1(const Point &p) // 복사생성자 호출하지 않음 // 참조에 의한 전달일 때
{
    // 소멸자 호출 X
    // 참조를 사용하는게 좋음
}

int main()
{
    Point p1;
    foo(p1);
    foo2(p1);
    // 메인문이 끝날 때 객체 p1의 소멸자 호출
}
*/

// 3) 함수가 객체를 값으로 반환할 때
Point p; // 기본 생성자
// 프로그램이 끝나면 소멸자
Point foo()
{
    printf("foo\n");
    return p; // 복사 생성자 (반환용 임시 객체 생성)
}
Point &foo2() // 참조이용
{
    printf("foo2\n");
    return p; // 복사생성자가 호출되지않음
}

int main()
{
    foo(); // 리턴 값으로 돌아온 객체는 복사생성자로 새로 만들어진 임시객체가 전달됨
    // 반환용 임시객체는 함수 호출문장 끝에서 소멸자 호출
    printf("---------\n");
    foo2();
}