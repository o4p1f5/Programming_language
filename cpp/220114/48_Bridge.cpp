#include <iostream>
using namespace std; 

struct MP3
{
    virtual ~MP3() {}
    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;
    // 인터페이스의 문제점 : 기능을 추가하는 순간 인터페이스가 깨진다
    // => 인터페이스의 구현부(SmartPhone)와 인터페이스(MP3)를 분리해서
    //    상호 독립적인 업데이트가 가능하게 하자.
    // => Bridge Pattern
};

class Person
{
    MP3* mp3;
    public:
    Person(MP3* p) : mp3(p)
    {}
    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
    }
};

class SmartPhone : public MP3
{
    public:
    void Play() override
    {
        cout << "SmartPhone Play Music" << endl;
    }
    void Stop() override
    {
        cout << "SmartPhone Stop Music" << endl;
    }
};

// SOLID(객체 지향 5대 원칙)
// 1) SRP : 단 하나의 책임을 가져야한다
// 2) OCP : 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다
// 3) LSP : 자식의 공통된 기능은 부모로부터 비롯되어야한다 => 상속의 목적은 "다형성"
// 4) ISP : 범용 인터페이스보다는 세분화된 인터페이스가 좋다.
// 5) DIP : "약한 결함" => 다른 클래스를 이용할때 구체적인 타입이 아니라 인터페이스나 추상 클래스를 이용해야한다.

int main()
{
    SmartPhone phone;
    Person person(&phone);

    person.PlayMusic();
}