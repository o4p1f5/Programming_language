#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 업캐스팅 활용

// 1) 같은 부모를 가지는 클래스를 처리하는 함수
class Animal
{
    int age;
};

class Dog : public Animal
{
    int color;
};

class Cat : public Animal 
{

};

/*
bool IsOlderThan10YearsOld(Dog* p)
{
    return p->age > 10;
}
bool IsOlderThan10YearsOld(Cat* p)
{
    return p->age > 10;
}
*/

// => 두 함수를 하나의 함수로 만들 수 있다.
bool IsOlderThan10YearsOld(Animal* p)
{
    return p->age > 10;
}

/*
int main()
{
    vector<Dog*> v1; // Dog 타입만 보관가능

    Dog d;
    Cat c;

    vector<Animal*> v2; // 2) Animal의 모든 파생 클래스 타입도 보관가능
    v2.push_back(&d);
    v2.push_back(&c);

    IsOlderThan10YearsOld(&d);
    IsOlderThan10YearsOld(&c);
}
*/

// 파일과 폴더의 공통의 부모가 존재하면, 하나의 컨테이너를 통해 관리하는 것이 가능
class Item {};

class File : public Item {};
class Folder : public Item
{
    vector<Item*> v;
};