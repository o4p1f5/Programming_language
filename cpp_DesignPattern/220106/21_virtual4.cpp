#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
    public:
    /*
    void Cry() { cout << "Animal cry" << endl; }
    */
    // 정적바인딩을 동적바인딩으로 변경
    virtual void Cry() { cout << "Animal cry" << endl; }

};

class Dog : public Animal 
{
    // 기반클래스의 멤버함수를 자식 클래스에서 재정의 가능
    // 함수 오버라이딩 (not 오버로딩)
    public:
    /*
    void Cry()
    {
        cout << "Dog cry" << endl;
    }
    */
    // 정적바인딩을 동적바인딩으로 변경
    // virtual은 부모에만 써줘도 되지만 구분을 위해 써주는게 좋음
    virtual void Cry() // 재정의는 virtual일때만 해야됨
    {
        cout << "Dog cry" << endl;
    }
};

int main()
{
    Animal a;
    Dog d;

    Animal* p = &d; // 업캐스팅
    // p -> Cry(); // Animal의 Cry() 호출 // 정적바인딩
    // 어떤 함수를 호출할지 결정하는 것 = 바인딩
    // 1) 정적바인딩 : p의 타입을(Animal*)을 보고 Animal의 함수를 호출
    // 2) 동적바인딩 : 컴파일러가 실행 시간에 p의 타입을 조사해서 해당 타입의 함수를 호출
    //               : Dog의 함수 호출, 실행 시간에 결정되는 p의 타입에 따라 호출되는 함수가 달라짐

    p -> Cry(); // Dog의 Cry() 호출 : 멤버함수에 virtual을 해줘 동적바인딩
    a.Cry(); // Animal의 Cry()
    d.Cry(); // 함수 재정의 전 : Animal의 Cry(), 함수 재정의 후 : // Dog의 Cry()
}