#include <iostream>
#include <vector>
using namespace std;

// 부모타입을 통해 자식 클래스를 동시에 다룰 수 있다.
class Shape
{
public:
    virtual ~Shape() { cout << "~Shape" << endl; }
    // Shape의 객체가 생성되지 않으면, 아래 함수 필요 없음
    // 부모클래스에서 구현을 제공할 필요없고 자식이 반드시 오버라이딩해야하는 상황이면
    // => 순수 가상 함수 생성
    // : 순수가상함수를 1개 이상 가지고 있는 클래스는 "추상 클래스"가 됨
    // 추상 클래스는 객체를 가질 수 없음.
    
    /*
    virtual void Draw()
    {
        cout << "Shape draw" << endl;
    }
    */
    virtual void Draw() = 0; // 순수 가상 함수
};

class Rect : public Shape
{
public:
    ~Rect() { cout << "~Rect" << endl; }
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape
{
public:
    ~Circle() { cout << "~Circle" << endl; }
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

int main()
{
    vector<Shape*> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);

    for(int i = 0; i < v.size(); ++i)
    {
        v[i]->Draw();// Draw를 사용하려면 자식클래스가 아닌 부모 클래스에 있어야한다.
        // Shape Draw 호출 // v의 자료형이 Shape*라서 -> 가상함수로 만들어줘야 각 클래스의 함수 출력됨
    }

    // 더 간결히 쓰는 법
    for(Shape* p : v)
    {
        p->Draw();
    }

    for(Shape* p : v)
    {
        delete p; // 소멸자도 가상함수
    }
}