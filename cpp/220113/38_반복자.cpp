#include <iostream>
using namespace std;

// 반복자(Iterator Pattern) : 컨테이너 요소를 순회하는 객체를 반복자라고 함

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
class SlistIterator
{
    Node<T>* current;
    public:
    SlistIterator(Node<T>* p = nullptr) : current(p)
    {}
    inline SlistIterator& operator++() 
    { 
        current = current->next;
        return *this;
    }
    inline T& operator*() { return current->data;}
    inline bool operator==(const SlistIterator& t) { return current == t.current;}
    inline bool operator!=(const SlistIterator& t) { return current != t.current;}
};

// 모든 컨테이너의 설계자는 자신의 처음과 끝다음을 가리키는 반복자를 꺼내는 연산 제공
// => 자신의 이터레이터 타입을 컨테이너 내부 타입의 이름을 통해 알려야한다.

template <typename T>
class Slist
{
    Node<T>* head;
    public:
    using iterator = SlistIterator<T>;
    Slist() : head(nullptr)
    {}

    SlistIterator<T> begin() {return SlistIterator<T>(head);}
    SlistIterator<T> end() {return SlistIterator<T>();}

    void push_front(const T& a)
    {
        head = new Node<T>(a, head);
    }
    const T& front() {return head->data;}
};

#include <list>

int main()
{
    // Slist<int> s;
    list<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    // SlistIterator<int> sp = s.begin();
    // Slist<int>:::iterator sp = s.begin();
    list<int>::iterator sp = s.begin();
    cout << *sp << endl;

    ++sp;
    cout << *sp << endl;

    int x[5] = { 1,2,3,4,5};
    int *p = x;
    int *p2 = x + 1;

    ++p;
    if(p == p2)
    {
        cout << "같은 위치" << endl; 
    }
    cout << *p << endl;
}

/*
#include <list>

template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
    ++first;

    // return first == last ? nullptr : first;
    return first;
}

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    Slist<int>:::iterator p = xfind(s.begin(), s.end(),20);
    if(p != s.end())
    {
        cout << *p << endl;
    }
}
*/