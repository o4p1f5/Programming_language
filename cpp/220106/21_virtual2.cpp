#include <iostream>
#include <string>
using namespace std;

class Animal
{
    int age;
};

class Dog : public Animal
{
    int color;
};

int main()
{
    Dog d;
    Animal* p = &d; // 업 캐스팅

    Animal* p1 = new Dog; // 업 캐스팅

    // Dog* pDog = p1; // 다운 캐스팅
    // 오류 -> 자식 클래스는 여러개 있을 수 있기 때문에 어떤 자료형으로 캐스팅할건지 보여줘야함
    Dog* pDog = static_cast<Dog*> (p1); // 명시적으로 캐스팅 해줘야함

}