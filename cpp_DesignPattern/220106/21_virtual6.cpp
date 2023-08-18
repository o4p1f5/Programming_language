#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base 
{
    public:
    Base() {cout << "Base()" << endl;}
    virtual ~Base() {cout << "~Base()" << endl;}
};

class Derived : public Base
{
    public:
    Derived() {cout << "Derived()" << endl;}
    virtual ~Derived() {cout << "~Derived()" << endl;}
};

int main()
{
    Base* p = naw Derived; // Derived의 소멸자는 동작하지않음 // 메모리 누수
    delete p; // 정적바인딩으로 인해 delete 할 때 Base의 소멸자 호출
    // => virtual을 사용하여 소멸자들을 가상함수로 만들어줌
}
