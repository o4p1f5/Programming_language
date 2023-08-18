#include <iostream>
#include <vector>
using namespace std;

// 도형 편집기로 배우는 객체 지향 설계 개념
// => 기능이 추가되어도, 기존코드는 수정되면 안된다.
// => OCP => 다형성은 OCP를 만족한다.
// 객체를 복사하는 기능을 다형성을 통해 구현하면 OCP 만족 가능
// => Prototpe Pattern : 기존에 존재하는 객체를 복제해서 새로운 객체를 만드는 패턴
// => Refactoring : 기존 코드의 기능을 변경하지 않고 유지보수가 가능하도록 구조 개선작업

class Shape
{
    public:
    virtual void Draw()
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
    void Draw() override
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
    void Draw() override
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
    // vector<Rect*> v; // OCP 만족 X
    // vector<Circle*> v;
    vector<Shape*> v;

    while (1) {
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

            /*
            // k번째 도형의 자료형 체크
            // OCP 만족 X
            
            if(typeid(*v[k]) == typeid(Rect))
            {
                Rect* p = static_cast<Rect*>(v[k]);
                v.push_back(new Rect(*v[k]));
            }
            else if (typeid(*v[k]) == typeid(Circle))
            {
                Circle* p = static_cast<Circle*>(v[k]);
                v.push_back(new Circle(*v[k]));
            }
            */
            v.push_back(v[k]->Clone());

        } 
        else if (cmd == 9) 
        {
            for (Shape* p : v) 
            {
                p->Draw();
            }
            // 다형성 이용해서 OCP 만족
        }
    }
}