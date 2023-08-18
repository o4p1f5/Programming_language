#include <iostream>
using namespace std;

// 2. 템플릿 기반 컨테이너
// 장점 : 타입 안정성이 뛰어나고, 객체뿐만 아니라 표준 타입도 저장가능하고
//        꺼낼 때 캐스팅도 필요하지 않는다.
// 단점 : 템플릿이므로 여러가지 타입을 동시에 사용하면, list의 기계 코드가 많아진다. 
//        코드 메모리 사용량 오버헤드 존재

template <typename T>
struct Node
{
    T data;
    Node* next;
    public:
    Node(const T& a, Node* n) : data(a), next(n)
    {}
};

template <typename T>
class Slist
{
    Node<T>* head;
    public:
    Slist() : head(nullptr)
    {}

    void push_front(const T& a)
    {
        head = new Node<T>(a, head);
    }
    const T& front() {return head->data;}
};

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30); // head가 가리키는 곳

    int n = s.front();
    cout << n << endl;
}