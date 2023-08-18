#include <iostream>
#include <vector>
using namespace std;

// RTTI : Run Time Type Information
//      : 실행시간에 타입을 조사하는 기술

class Car
{
    public:
    virtual ~Car() {}
    int color = 200;
};

class Sedan : public Car
{
    public:
    int speed = 100;
};

void Go(Car* p)
{
    // p가 Sedan이면 speed 출력
    
    // 체크 없이 사용할 경우
    /*
    Sedan* s = static-cast<Sedan*> (p); // 객체가 Car일 때 자료형 파악 못함
    cout << "Speed : " << s->speed << endl;
    */

    // RTTI 사용 : 모든 타입은 자신의 타입의 정보를 가지고 있는 type_info 구조체 가짐
    /*
    const type_info& t = typeid(*p);
    cout << t.name() << endl;
    */
    // 문제점1 : type_info를 통해 얻을 수 있는 문자열의 이름이 표준화되지않음
    // -> 컴파일마다 다른 이름이 나옴
    const type_info& t1 = typeid(*p); // 객체를 통해 자료형 정보 얻기
    const type_info& t2 = typeid(Sedan); // 클래스를 통해 자료형 정보 얻기
    // 두 경우의 자료형이 같은 경우
    if(t1==t2) // 객체 p의 자료형이 Sedan인지 확인
    {
        cout << "p는 Sedan 타입입니다." << endl;
        Sedan* s = static_cast<Sedan*> (p);
        cout << "Speed : " << s->speed << endl;
    }
    else 
    {
        cout << "p는 Sedan 타입이 아닙니다." << endl;
    }
    // 문제점2 : type_info는 가상함수 테이블에 있음 -> 가상함수 정의 해줌
}

void Go2(Car* p)
{
    // 실행 시간에 하위 캐스팅을 타입 체크 수행 시 하고 싶다 => dynamic_cast
    // : 가상함수테이블 이용
    Sedan* s1= static_cast<Sedan*>(p);
    Sedan* s2= dynamic_cast<Sedan*>(p);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << endl;

    if(s2 != nullptr)
    {
        cout << "speed: " << s2->speed << endl;
    }
}

int main()
{
    Car c;
    Sedan s;

    Go(&c);
    Go(&s);
    Go2(&c);
    Go2(&s);
}