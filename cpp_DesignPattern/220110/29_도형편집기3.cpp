#include <iostream>
#include <vector>
// #include <mutex>
using namespace std;

// 도형 편집기로 배우는 객체 지향 설계 개념
// 동기화 기능 추가
// 공통성과 가변성의 분리가 필요
// Template Method Pattern
// => 변하지 않는 전체 알고리즘은 부모가 비가상함수로 제공
// => 변해야하는 부분만 가상함수화 해서 자식이 변경할 수 있도록 설계
// => NVI(Non Virtual Interface)

class Mutex
{
    public:
    void lock()
    {
        cout << "동기화 시작" << endl;
    }
    void unlock()
    {
        cout << "동기화 종료" << endl;
    }
};

Mutex m;

class Shape
{
    public:
    void Draw()
    {
        m.lock();
        DrawTmpl();
        m.unlock();
    }
    virtual void DrawTmpl()
    {
        cout << "Shape Draw" << endl;
    }
    virtual Shape* Clone()
    {
        return new Shape(*this);
    }
};

class Rect : public Shape{
    public :
    void DrawTmpl() override
    {
        cout << "Rect draw" << endl;
    }
    Shape* Clone() override
    {
        return new Rect(*this);
    }
};

class Circle : public Shape{
    public:
    void DrawTmpl() override
    {
        cout << "Circle draw" << endl;
    }
    Shape* Clone() override
    {
        return new Circle(*this);
    }
};

int main()
{
    vector<Shape*> v;

    while (1) 
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1) 
        {
            v.push_back(new Rect);
        } 
        else if (cmd == 2) 
        {
            v.push_back(new Circle);
        } 
        else if (cmd == 8) 
        {
            cout << "몇 번째 도형을 복사할까요 >>";
            int k;
            cin >> k;
            v.push_back(v[k]->Clone());
        } 
        else if (cmd == 9) 
        {
            for (Shape* p : v) 
            {
                p->Draw();
            }
        }
    }
}