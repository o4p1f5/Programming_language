#include <iostream>
using namespace std;

// 일반 함수 포인터와 멤버함수 포인터는 다른 개념
// => 간접층의 원리 : 소프트웨어의 난제는 간접층을 도입함으로써 문제를 해결할 수 있다

// 3. FunctionCommand와 MemberCommand의 공통부모 설계
struct ICommand
{
    virtual ~ICommand() {}
    virtual void Execute() =0;
};

// 1. 일반 함수 포인터 역할을 수행하는 클래스를 설계
class FunctionCommand : public ICommand
{
    public:
    using HANDLER = void (*)(); // 유용
    HANDLER handler;

    FunctionCommand(HANDLER h) : handler(h)
    {}
    void Execute() override { (*handler)(); }
};

// 2. 멤버함수포인터 역할을 수행하는 클래스 설계
// => 모든 클래스 타입의 멤버함수를 참조할 수 있어야한다. => 템플릿
template <typename T>
class MemberCommand : public ICommand
{
    public:
    using HANDLER = void (T::*)();
    HANDLER handler;
    T * object;

    MemberCommand(HANDLER h, T* o) : handler(h) , object(o)
    {}

    void Execute() override {(object->*handler)();}
};

void foo() {cout << "foo" << endl;}

class Dialog
{
    public:
    void Open() {cout << "Dialog Open" << endl;}
};

// 4. 클래스를 생성하는 함수 템플릿
template <typename T>
MemberCommand <T>*cmd(void (T::*h)(),T* obj)
{
    return new MemberCommand<T>(h, obj);
}

// 5. FunctionCommand를 생성하는함수
FunctionCommand* cmd(void (*f)())
{
    return new FunctionCommand(f);
}

int main()
{
    Dialog dlg;
    // 클래스 템플릿은 타입 추론 불가능 -> 명시적으로 지정
    MemberCommand<Dialog> f2 (&Dialog::Open, &dlg);
    f2.Execute();

    FunctionCommand f1(&foo);
    f1.Execute();

    // 공통부모
    ICommand* fp = new FunctionCommand(&foo);
    fp->Execute();

    // 5. 얘도 복잡해 보인다 -> FunctionCommand를 생성하는함수도 제공
    ICommand* fp1 = cmd(&foo);
    fp->Execute();

    fp = new MemberCommand<Dialog> (&Dialog::Open, &dlg);
    fp->Execute();

    // 4. 클래스 템플릿 때문에 명시적으로 지정해줘야하는 것이 불편 => 클래스를 생성하는 함수 템플릿을 제공
    fp = cmd(&Dialog::Open, &dlg);
    fp->Execute();
}

// 메뉴이벤트에 적용
/*
class MenuItem
{
    std::string title;
    ICommand* pCommand;
    public:
    MenuItem(const std::string& s) : title(s), pCommand(nullptr) {}

    void SetCommand(ICommand* p)
    {
        pCommand = p;
    }

    virtual void Command()
    {
        // cout << title << " 메뉴가 선택됨" << endl;
        if(pCommand)
        pCommand->Execute();
    }
};

int main()
{
    MenuItem m1("저장");
    MenuItem m2("불러오기");

    m1.SetCommand(cmd(&foo));

    Dialog dlg;
    m2.SetCommand(cmd(&Dialog::Open, &dlg));

    m1.Command();
    m2.Command();
}
*/