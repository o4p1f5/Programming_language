#include <iostream>
using namespace std;

// 예외를 던질 때, 예외 전용 클래스를 만들어서 사용

void goo1(); // 반환값이 없다
 
void goo2() noexcept; // 예외가 발생하지 않는다

class MemortException : public std::exception
{
    public :
    char const* what() const noexcept override
    {
        return "메모리 할당 오류";
    }
};
void foo(int a)
{
    if(a<0)
    {
        throw MemortException();
    }
}

int main()
{
    try{
    foo(-100);
    } catch (const MemortException& e)
    {
        cout << e.what() << endl;
    }
}
