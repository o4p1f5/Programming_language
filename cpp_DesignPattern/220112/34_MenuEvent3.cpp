#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 2. 함수 포인터 기반의 이벤트 처리 방법 => 핸들러 기반 이벤트 처리 방법
// => 자바를 제외한 모든 플랫폼에서 사용
// => 일반함수와 멤버함수를 묶어서 관리할 수 있는 범용함수포인터개념을 제공

class Dialog
{
    public:
    void Open() { cout << "Dialog Open" << endl;}
    void Close() { cout << "Dialog Close" << endl;}
};

// 문제점
// 1) Dialog 멤버함수만 사용가능 (강한 결합)
// 2) 일반 함수도 사용할 수 없다.

class MenuItem
{
    std::string title;
    // 멤버함수포인터
    void (Dialog::*handler)();
    Dialog* object;

    public:
    void SetHandler(void (Dialog::*h)(), Dialog* obj)
    {
        handler = h;
        object = obj;
    }

    MenuItem(const std::string& s) : title(s), handler(nullptr), object(nullptr) 
    {}

    virtual void Command()
    {
        cout << title << " 메뉴가 선택됨" << endl;
        // 메뉴가 선택된 사실을 다시 외부에 알려야한다.
        // => 객체가 외부로 이벤트를 발생한다
        if(object == nullptr || handler == nullptr)
        return;

        (object->*handler)();
    }
};

int main()
{
    /*
    Dialog dlg;
    Dialog* p = &dlg;

    void(Dialog::*fp) () = &Dialog::Open;
    (dlg.*fp)();
    fp = &Dialog::Close;
    (dlg.*fp)();

    (p->*fp)();
    */

    Dialog dlg;

    MenuItem m1("저장");
    MenuItem m2("불러오기");

    m1.SetHandler(&Dialog::Open, &dlg);
    m2.SetHandler(&Dialog::Close, &dlg);

    m1.Command();
    m2.Command();
}