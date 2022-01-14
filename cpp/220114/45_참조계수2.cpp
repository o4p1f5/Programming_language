#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 경우가 매우 많다
// => new를 통해 객체를 생성

class Image
{
    int mCount;
    public:
    Image() : mCount(0)
    {
    }
    ~Image() {cout << "Image 파괴" << endl; }
    void AddRef() { ++mCount; }
    void Release()
    {
        if(--mCount == 0)
        delete this;
    }
    void Draw() { cout << "Image Draw" << endl; }
};

// Image*를 바로 사용하면 참조 계수를 직접 관리해야 한다.
// 불편하므로, 참조 계수를 자동으로 관리하는 클래스를 만들자.
class ImegeProxy
{
    Image* image;
    public:
    ImegeProxy(Image* p) : image(p)
    {
        image->AddRef(); // 규칙 1)
    }

    ImegeProxy(const ImegeProxy& rhs) : image(rhs.image) // 규칙 2)
    {
        image->AddRef();
    }

    // 복사생성자를 만들면 대입 연산자도 만들어야됨
    ImegeProxy& operator=(const ImegeProxy& rhs)
    {
        if(image != rhs.image)
        {
        image->Release();
        image = rhs.image;
        image->AddRef();
        }
        return *this;
    }

    // 규칙 3)
    ~ImegeProxy() {image->Release();}

    // 진짜 Image* 처럼 동작해야한다 => 연산자 오버로딩을 통해 ->, * 연산을 제공
    inline Image* operator->() {return image;}
    inline Image& operator*() {return *image;}
};

// 위의  클래스처럼 참조 계수 기반의 코드를 사용하는 규칙
int main()
{
    ImegeProxy p1 = new Image;
    ImegeProxy p2 = p1;

    p1->Draw();
    p2->Draw();

    // 모든 규칙이 대리자 ImegeProxy 클래스에 의해 수행됨

    /*
    Image* p1 = new Image;
    p1->AddRef(); // 규칙 1) 객체를 만들면 참조 계수 증가
    
    Image* p2 = p1;
    p2->AddRef(); // 규칙 2) 객체 포인터를 복사하면 참조 계수 증가

    // 규칙 3) 포인터를 더이상 사용하지 않을 때, 참조 계수 감소
    p1->Release();
    p2->Release();
    // p1->Release(); // 문제 발생
    */
}