#include <iostream>
#include <string>
using namespace std;
// 상속과 생성자 소멸자

class Base
{
 public :
    Base() {cout << "Base()" << endl;}
    Base(int a) {cout << "Base(int)" << endl;}
    ~Base() {cout << "~Base()" << endl;}
}

class Derived : public Base
{
 public :
    Derived() {cout << "Derived()" << endl;}
    // Derived() : Base() {cout << "Derived()" << endl;}
    // => 컴파일러는 자식 클래스의 생성자에서 숨겨져있는 초기화 리스트를 통해 부모의 기본생성자를 호출한다
    Derived() : Base(42) {cout << "Derived()" << endl;}
    // 기본 생성자가 아니라면 명시적으로 작성해줘야함
    ~Derived() {cout << "~Derived()" << endl;}
}

int main()
{
    Derived d; // 부모 생성 -> 자식 생성 -> 자식 소멸 -> 부모 소멸
}