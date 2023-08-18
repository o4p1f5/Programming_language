#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 클래스
class RefBase
{
    int mCount;
    public:
    RefBase() : mCount(0)
    {
    }
    virtual ~RefBase() {cout << "RefBase 파괴" << endl; }
    void AddRef() { ++mCount; }
    void Release()
    {
        if(--mCount == 0)
        delete this;
    }
};

class Image : public RefBase
{
    public:
    void Draw() { cout << "Image Draw" << endl; }
};

template <typename T>
class Ptr
{
    T* obj;
    public:
    inline Ptr(T* p) : obj(p)
    {
        obj->AddRef(); // 규칙 1)
    }

    inline Ptr(const Ptr& rhs) : obj(rhs.obj) // 규칙 2)
    {
        obj->AddRef();
    }

    // 복사생성자를 만들면 대입 연산자도 만들어야됨
    inline T& operator=(const Ptr& rhs)
    {
        if(obj != rhs.obj)
        {
        obj->Release();
        obj = rhs.obj;
        obj->AddRef();
        }
        return *this;
    }

    inline ~Ptr() {obj->Release();}

    inline T* operator->() {return obj;}
    inline T& operator*() {return *obj;}
};

class Car : public RefBase
{
    public:
    ~Car()     
    {
        cout << "~Car" << endl;
    }
    void Go()
    {
        cout << "Car Go" << endl;
    }
};

int main()
{
    Ptr<Image> p1 = new Image;
    Ptr<Image> p2 = p1;

    p1->Draw();
    p2->Draw();

    Ptr<Car> p3 = new Car;
    p3->Go();
}