#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// AddRectCommand와 AddCircleCommand의 로직이 너무 동일하다
// 공통성과 가변성의 원리에 따라 나눠줘서 관리해주면 좋다 
// => 팩토리 메소드 패턴(Factory Method Pattern) : 템플릿 메소드 패턴의 모양인데,
//                                              : 자식이 재정의하는 가상함수가 정책이나
//                                              : 알고리즘의 변경이 아닌 객체 생성일때의 패턴
// Factory : 객체 생성

class Shape
{
    public:
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape{
    public :
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape{
    public:
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

// 명령에 대한 인터페이스
struct Command
{
    virtual ~Command() {}

    virtual void Execute() = 0;

    // 인터페이스에 새로운 기능을 추가할 땐, 인터페이스에 기본 구현을 제공하는 것이 좋다.
    virtual void Undo() {} 
    virtual bool CanUndo() {return false;}
};

class AddCommand : public Command
{
    vector<Shape*>& v;
    public:
    AddCommand(vector<Shape*>& p) : v(p)
    {}

    virtual Shape* CreateShape() = 0;

    void Execute () override 
    {
        v.push_back(CreateShape());
    }

    bool CanUndo() override {return true;}

    void Undo()
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class AddRectCommand : public AddCommand
{
    public:
    AddRectCommand(vector<Shape*>& p) : AddCommand(p)
    {}
    Shape* CreateShape() override
    {
        return new Rect;
    }
};

class AddCircleCommand : public AddCommand
{
    public:
    AddCircleCommand(vector<Shape*>& p) : AddCommand(p)
    {}
    Shape* CreateShape() override
    {
        return new Circle;
    }
};

class DrawCommand : public Command // 낙장불입의 명령 // 취소될 수 없음 // Undo X
{
    vector<Shape*>& v;
    public:
    DrawCommand(vector<Shape*>& p) : v(p)
    {}
    void Execute () override 
    {
        for(auto e : v)
        e->Draw();
    }
};

class MacroCommand : public Command// 재귀적 합성 사용 -> Composite Pattern
{
    vector<Command*> v; // 여러개의 문장을 한번에 저장
    public:
    void AddCommand(Command* p) 
    {
        v.push_back(p);
    }
    void Execute() override
    {
        for (auto e : v)
        {
            e->Execute();
        }
    }
};

int main()
{
    vector<Shape*> v;

    MacroCommand mc;
    mc.AddCommand(new AddRectCommand(v));
    mc.AddCommand(new AddCircleCommand(v));
    mc.Execute();

    Command* pCommand = nullptr;

    stack<Command*> undo;

    while (1) 
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1) 
        {
            pCommand = new AddRectCommand(v);
        } 
        else if (cmd == 2) 
        {
            pCommand = new AddCircleCommand(v);
        } 
        else if (cmd == 9) 
        {
            pCommand = new DrawCommand(v);
        }
        else if (cmd == 0) // undo 기능
        {
            Command* p = undo.top(); // 가장 최근 명령 가져옴
            p->Undo(); // 삭제
            undo.pop(); // 스택에서 삭제

            delete p;
            continue;
        }
        if(pCommand)
        {
            pCommand->Execute();
            if(pCommand->CanUndo())
            {
                undo.push(pCommand);
            }
            else
            {
                delete pCommand;
            }
        }
    }
}