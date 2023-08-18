#include <iostream>
using namespace std;

// 1. Object* 기반 컨테이너 
// -> 프로그램 내의 모든 클래스는 Object의 자식이어야한다
// -> Java나 C#에서는 자동으로 Object의 자식으로 생성된다.

// 문제점 : 컨테이너에 일반적으로 하나의 타입을 저장하는 것이 좋다
//         => 다른 종류의 타입을 넣어도 컴파일 오류가 발생 = 타입 안정성이 떨어짐
//        : 객체가 아닌 표준 타입을 저장할 수 없다.
//         => int, double, 등등 => 래퍼 클래스라는 개념이 필요(Java나 C#에서 제공)
//        : 데이터를 꺼내올 때마다 다운 캐스팅이 필요하다.
// 장점 : 템플릿 기반이 아니기 때문에 메모리 사용량이 효율적이다

class Integer : public Object
{
    int value;
    public:
    Integer(int n) : value(n) {}
    int GetValue() const {return value;}
}

class Object
{
    public:
    virtual ~Object() {}
};

class Dialog :  public Object
{};
class Rect :  public Object
{};

struct Node
{
    Object* data;
    Node* next;
    public:
    Node(Object* a, Node* n) : data(a), next(n)
    {}
};

class Slist
{
    Node* head;
    public:
    Slist() : head(nullptr)
    {}

    void push_front(Object* a)
    {
        head = new Node(a, head);
    }
    Object* front() {return head->data;}
};

int main()
{
    Slist s;

    s.push_front(new Dialog);
    s.push_front(new Rect);
    s.push_front(new Integer(42));

    Integer* p = dynamic_cast<Integer*>s.front(); // 반드시 다운 캐스팅이 필요하다
    if(p)
    {
        cout << p->GetValue() << endl;s
    }
    // 매우 번거로움
}