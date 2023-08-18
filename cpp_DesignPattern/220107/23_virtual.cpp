#include <iostream>
#include <vector>
using namespace std;

class Animal
{
    int age;
    public:
    virtual void ~Animal() {}
    virtual void Cry()
    {
        cout << "Animal Cry" << endl;
    }
};

class Dog : public Animal
{
    int color;
    public:
    void Cry() override
    {
        cout << "Dog Cry" << endl;
    }
};

int main()
{
    Animal a;
    cout << sizeof(a) << endl; // 4byte // 가상함수 후 -> 16byte
    // 가상 소멸자를 생성해도 16tyte
    // 가상함수를 하나라도 가지고 있으면 객체 크기가 8byte 증가 
    // -> Animal의 가상함수의 주소을 가리키는 포인터(*vftable)

    Dog d; // *vftable이 Dog의 가상함수 주소 가리킴
    cout << sizeof(d) << endl; // 8byte // 가상함수 후 -> 16byte

}