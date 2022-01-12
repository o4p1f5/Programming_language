#include <iostream>
using namespace std;

// 이미 C++ 표준에 범용함수포인터타입이 존재한다.
#include <functional>

void foo()
{
    cout << "foo" << endl;
}

class Dialog
{
    public:
    void Open() { cout << "Dialog Open" << endl;}
};

class MenuItem {
    std::string title;

    function<void()> pCommand;

public:
    MenuItem(const std::string& s)
        : title(s)
    {
    }

    void SetCommand(function<void()> p)
    {
        pCommand = p;
    }

    virtual void Command()
    {
        pCommand();
    }
};

int main()
{
    Dialog dlg;

    MenuItem m1("foo");
    MenuItem m2("Dialog open");

    m1.SetCommand(&foo);
    m2.SetCommand(bind(&Dialog::Open, &dlg));

    m1.Command();
    m2.Command();

    /*
    function<void()>f;
    f = &foo;
    f(); // 호출식 // 연산자 오버로딩으로 되어있음

    Dialog dlg;
    f = bind(&Dialog::Open, &dlg); // cmd와 같은 역할
    f();
    */
}