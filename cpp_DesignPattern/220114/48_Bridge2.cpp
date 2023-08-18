#include <iostream>
using namespace std;

struct MP3
{
    virtual ~MP3() {}
    virtual void Play() = 0;
    virtual void Stop() = 0;
};

class MP3Bridge
{
    MP3* pImp; // 구현
    // 컴파일러 방화벽 // 컴파일 속도 최적화
    // => Exceptional C++
    
    public:
    MP3Bridge(MP3* p) : pImp(p)
    {
    } 
    void Play() {pImp->Play();}
    void Stop() {pImp->Stop();}

    void PlayOneMinute()
    {
        pImp->Play();
        cout << "1분 후" << endl;
        pImp->Stop();
    }
};

// 사용자가 인터페이스를 직접 사용하게 하지 않고, 
// 중간층을 도입하면 변화에 쉽게 대응할 수 있다. => Bridge Pattern
class Person
{
    MP3Bridge* mp3;
    public:
    Person(MP3Bridge* p) : mp3(p)
    {}
    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();

        mp3->PlayOneMinute();
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

int main()
{
    SmartPhone phone;

    MP3Bridge mp3(&phone);

    Person person(&mp3);

    person.PlayMusic();
}