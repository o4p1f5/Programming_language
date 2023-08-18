#include <iostream>
using namespace std;

class Car 
{
    int color; // 멤버데이터 변수는 공유되지 않는다 => 인스턴트 변수
    static int cnt; // 정적 멤버 데이터 변수 // Car 클래스의 모든 객체가 공유하는 데이터 변수
    // 소스파일에 있어야 됨 // 클래스 외부에서 초기화 => int Car::cnt = 0;
    // 객체를 따로 만들지않아도 메모리에 존재(전역변수와 수명 동일)
    // 전역변수와 달리 접근 지정자 사용 가능
    // 객체의 크기에 포함되지않음 : 포함되면 4+4=8byte로 나와야하지만
    //                             포함되지않으므로 sizeof(Car)하면 4byte 나옴
    // 외부에서 수정할 수 없도록 private로 지정하는 것이 좋음 -> 정적멤버함수로만 수정
public:
    // int cnt; // 다른 객체과 공유되지않음
    static int getCount() // 정적 멤버 함수 -> 객체 없이 호출가능 // 접근 지정자 사용가능
    {
        return cnt;
    }

    Car()
    {
        ++cnt;
    }
    ~Car()
    {
        --cnt;
    }
};

int Car::cnt = 0;

int main()
{
    Car c1,c2;
    // cout << Car::cnt/* 권장하는 방식 */ /* 다른 방식 : c1.cnt */ << endl;
    // static int cnt; 가 public일때 사용 가능한 줄
    cout << c1.getCout() << endl;
}