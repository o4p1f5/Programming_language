#include <iostream>
using namespace std;

// 3. Thin 템플릿
// 1) void* 기반으로 만들기

struct Node
{
    void* data;
    Node* next;
    public:
    Node(void* a, Node* n) : data(a), next(n)
    {}
};

class SlistImpl // Impl : 내부적으로 구현하겠다
{
    Node* head;
    public:
    SlistImpl() : head(nullptr)
    {}

    void push_front( void* a)
    {
        head = new Node(a, head);
    }
    void* front() {return head->data;}
};

// SlistImpl를 직접 사용할 경우, 캐스팅에 대한 코드가 불편
// => 사용자가 편리하게 사용할 수 있도록 Template으로 자식 클래스를 제공
// => Thin Template => inline을 사용할 경우, 치환된느 함수에 대해서 코드 메모리에 존재하지 않는다
// => SlistImpl의 구현을 물려받지만, 인터페이스는 물려받지 않아야한다 => public -> private

template <typename T> // 캐스팅 코드를 자동으로 생성해준다.
class Slist : private SlistImpl
{
    public:
    inline void push_front(const T& a)
    {
        // &a => const T* =>  void* [X]
        // &a => const T* => const_cast => T* => void* [O]
        SlistImpl::push_front(const_cast<T*>(&a));
    }
    inline T& front()
    {
        // void* => static_cast => T* => * => T&
        return *(static_cast<T*>(SlistImpl::front()));
    }
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