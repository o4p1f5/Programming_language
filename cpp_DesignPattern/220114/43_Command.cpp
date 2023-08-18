#include <iostream>
#include <vector>
using namespace std;

// 추가된 요구사항 : undo, redo 기능 => 스택이용
// 명령을 하는 클래스를 만들어서 스택에 저장
// Command Pattern : 명령을 객체로 추상화 => undo같은 기능을 만드는 답

// 1. Undo의 동작은 가장 최근에 실행된 명령에 대한 반대 동작이 수행된다.
// 2. 명령을 객체로 추상화해서, 스택에 저장할 수 있어야 한다.

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

class AddRectCommand : public Command
{
    vector<Shape*>& v;
    public:
    AddRectCommand(vector<Shape*>& p) : v(p)
    {}
    void Execute () override 
    {
        v.push_back(new Rect);
    }
    bool CanUndo() override {return true;}
    void Undo()
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class AddCircleCommand : public Command
{
    vector<Shape*>& v;
    public:
    AddCircleCommand(vector<Shape*>& p) : v(p)
    {}
    void Execute () override 
    {
        v.push_back(new Circle);
    }
    bool CanUndo() override {return true;}
    void Undo()
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
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

int main()
{
    vector<Shape*> v;
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

// Dry : 반복적인, 복사되는 행동을 하지마라. 유지 비용을 늘린다.
// 하지만 너무 복사에 신경쓰지마라. 과도한 추상화를 하면 더 복잡해짐
// 따라서 중복을 하는 것이 더 좋을 수도 있다.