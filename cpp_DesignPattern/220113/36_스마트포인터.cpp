#include <iostream>
using namespace std;

// 스마트 포인터 => 포인터 역할을 하는 클래스를 만든다.
// => 임의의 객체가 다른 클래스의 포인터의 역할을 하는 것
// => 프록시 패턴(Proxy Pattern) : 대리자 패턴
// 장점 : 진짜 포인터가 아니라, 객체이다 => 생성/소멸/대입/복사 등의 모든 과정에 대한 제어가 가능
//                                        대표적인 활용이 소멸자에서의 자동삭제기능이다

class Car
{
    public:
    ~Car() { cout << "Car 객체 파괴" << endl;}
    void Go() { cout << "Car go" << endl;}
};

// Car에 대해서만 동작
/*
class Ptr
{
    Car* obj;
    public:
    Ptr(Car* p = nullptr) : obj(p) {}
    ~Ptr() {delete obj;}    

    Car* operator->() { return obj; }
    Car& operator*() { return *obj; }
};
*/

// 모든 클래스에 대해 작동하게 변경
template <typename T>
class Ptr
{
    T* obj;
    public:
    Ptr(T* p = nullptr) : obj(p) {}
    ~Ptr() {delete obj;}    

    T* operator->() { return obj; }
    T& operator*() { return *obj; }
};


int main()
{
    //Car* p = new Car;
    //p->Go();

    // Ptr p = new Car;
    Ptr<Car> p = new Car; // template 사용 시 표기

    // 연산자 오버로딩으로 재정의 해줘야 객체가 포인터처럼 사용될 수 있다.
    p->Go(); // Car* operator->() {}
    (*p).Go(); // Car& operator*() {}

    delete p;
}

/*
// 표준 라이브러리 사용
#include <memory>
// unique_ptr<>
// shared_ptr<>

int main()
{
    std::unique_ptr<Car> p(new Car);
    std::shared_ptr<Car> p1(new Car);
    p->Go();
    (*p).Go();
}
*/