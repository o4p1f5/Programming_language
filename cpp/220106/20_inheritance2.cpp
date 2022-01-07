#include <iostream>
#include <string>
using namespace std;

// 상속과 접근 지정자

class User
{
    int age;
// protected:
//    string name; // 멤버변수는 private으로 지정하는게 좋음
    string name;
    protected:
    string GetName() const {return name;}
};

// Sub 클래스
class Student : public User
{
    int id;
public:
    void PrintName()
    {
        cout << /*name*/ Getname()/*부모 클래스의 수정이 있어도 영향 X*/ << endl;
    }
};

int main()
{
}

// SOLID -> 객체 지향 설계 5대 원칙
// 1) SRP : 단일 책임 원칙 -> 모둔 모듈은 단 하나의 책임을 가져야한다.
// 2) OCP : 개방 폐쇄 원칙 -> 수정에는 닫혀있고, 확장에는 열려 있어야 한다.
//                        -> 새로운 기능 추가되어도, 기존 코드는 수정되면 안된다. 
// 3) LSP 4) ISP 5) DIP