#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    Animal()
    {

    }
};

class Dog  : public Animal{
    public :
    Dog() : Animal()
    {

    }
};

int main()
{
    Animal a; // 생성자 접근 불가능
    Dog d; 
    // 가능 -> Dog 생성자 호출 -> Animal 생성자 호출 -> Animal 생성자 동작 -> Dog 생성자 동작
}