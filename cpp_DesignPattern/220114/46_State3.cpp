#include <iostream>
using namespace std;

// 방밥 2) 변하는 것을 가상함수로 만든다.

class Character
{
    int item;
    public:
    int gold = 0; 
    virtual void Run()
    {
        cout << "Run" << endl;
    }

    virtual void Attack()
    {
        cout << "Attack" << endl;
    }
};

// 아이템의 획득에 따라 동작을 변경하기 위해, 상속을 사용한다

class FastRunCharacter : public Character
{
    public:
    void Run () override {cout << "Fast Run" << endl;}
};

class SlowRunCharacter : public Character
{
    public:
    void Run () override {cout << "Slow Run" << endl;}
};

int main()
{
    Character* current;

    Character c;

    current = &c;
    current->gold = 100;
    cout << current->gold << endl;
    current->Run();

    FastRunCharacter fc;
    current = &fc;
    cout << current->gold << endl;
    // 동작 뿐 아니라 상태도 변경된다. gold는 공유되어야 한다.

    current->Run();

    SlowRunCharacter sc;
    current = &sc;
    cout << current->gold << endl;
    current->Run();
}