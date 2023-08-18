#include <iostream>
using namespace std;

// 반복자 설계 방법
// 1) C++ : 연산자 오버로딩, begin / end
// 2) 인터페이스 기반으로 약속

// 반복자(Iterator Pattern) : 컨테이너의 내부구조에 상관없이 요소를 열거하는 객체를 의미

template <typename T>
struct Node
{
    T data;
    Node* next;
    public:
    Node(const T& a, Node* n) : data(a), next(n)
    {}
};

// 반복자가 구현해야하는 인터페이스
template <typename T>
struct Iterator
{
    virtual ~Iterator() {}

    //다음 요소가 존재하는지 확인
    virtual bool HasNext() = 0;
    // 현재 값을 반환, 다음 위치로 이동
    virtual T& Next() = 0;
};

template <typename T>
class SlistIterator : public Iterator<T>
{
    Node<T>* current;
    public:
    SlistIterator(Node<T>* p=nullptr) : current(p) {}

    bool HasNext() override {return current != nullptr;}

    T& Next() override
    {
        Node<T>* temp = current;
        current = current->next;
        return temp->data;
    }
};

// 컨테이너가 구현해야하는 인터페이스
template <typename T>
struct Iterable
{
    virtual ~Iterable() {}
    virtual Iterator<T>* GetIterator() = 0;
};

template <typename T>
class Slist : public Iterable<T>
{
    Node<T>* head;
    public:
    Iterator<T>* GetIterator() override
    {
        return new SlistIterator<T>(head);
    }
    Slist() : head(nullptr)
    {}

    void push_front(const T& a)
    {
        head = new Node<T>(a, head);
    }
    const T& front() {return head->data;}
};

#include <list>
#include <vector>

int main()
{
    list<int> l = {1,2,3,4,5};
    vector<int> v = {5,4,3,2,1};

    auto p = l.begin(); 
    while (p != l.end())
    {
        cout << *p << endl;
        p++;
    }

    auto p1 = v.begin(); 
    while (p1 != v.end())
    {
        cout << *p1 << endl;
        p1++;
    }

    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    Iterator<int>* iter = s.GetIterator();
    while (iter->HasNext())
    {
        cout << iter->Next() << endl;
    }
}