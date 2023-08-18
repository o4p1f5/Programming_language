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
    /*
    double d = 3.14;
    // int * p = &d; // 에러 발생 // 자료형 오류
    */

    Dog d;
    Animal* p = &d; // 가능 -> 암묵적인 변환 허용 // 업캐스팅
    // 상속 : is-a 관계 성립 : 자식 클래스 is a 부모클래스
    // => Dog is a Animal // 모든 언어에서 작용
}