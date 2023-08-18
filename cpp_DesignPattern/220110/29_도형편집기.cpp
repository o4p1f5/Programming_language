#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체 지향 설계 개념
// => 모든 도형은 타입화하면 편하다
// => 모든 도형의 공통부모가 있다면 모든 도형을 묶어서 관리할 수 있다.
// => 모든 자식의 공통 특징이 있다면 반드시 부모에도 있어야한다
// => 부모의 함수 중 자식이 재정의하는 모든 함수는 반드시 가상함수이어야 한다.

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
        else if (cmd == 9) 
        {
            for (Shape* p : v) 
            {
                p->Draw(); // 가상함수로 만들어진 v의 자료형을 판단해서
                // 그 클래스의 Draw 함수 호출
            }
        }
    }
}