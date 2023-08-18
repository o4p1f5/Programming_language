#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
    public:
    virtual void Cry() 
    {
        cout << "Animal cry" << endl;
    }
};

class Dog : public Animal 
{
    public:
    /*
    virtual void Cry() // 선언과 구현부를 구분할 땐 선언에만 써줌
    {
        cout << "Dog cry" << endl;
    }
    */
    virtual void Cry() override;
    // c++11 에서는 부모로부터 오버라이딩 한 함수라는 표시 생김
    // 선언에만 써줌
    // 부모 클래스에 그 함수가 없거나 함수의 이름이 틀리거나 
    // 부모클래스의 함수가 가상함수가 아니면 오류발생
    // override를 써준 상태에선 virtual를 빼도 됨
};

void Dog::Cry()
{
    cout << "Dog cry" << endl;
}

int main()
{
    Animal* p = new Dog;
    p->Cry();
}