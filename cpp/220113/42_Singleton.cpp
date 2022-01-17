#include <iostream>
using namespace std;

// 의도 : 오직 한개의 객체만 만들 수 있고, 어디에서든 동일한 방법으로 객체를 얻을 수 있게 하는 패턴
// Singleton == 전역객체 : 단, 전역객체의 생성자는 언제 호출되는지 모르지만 Singleton은 내부 정적 객체를 사용하기때문에
//                      GetInstance의 호출로 인해 생성과 소멸을 알 수 있다.

// Singleton을 만드는 첫번째 방법 - 정적 멤버함수
class Cursor
{
    Cursor() {} // 규칙 1) private 생성자

    // 규칙 3) 복사와 대입을 금지
    Cursor(const Cursor&) = delete;
    Cursor& operator=(cosnt Cursor&) = delete;

    public:
    // 규칙 2) 오직 한 개만 만드는 정적 멤버함수
    static Cursor& GetInstance()
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    // Cursor c;
    // Cursor* p = new Cursor;

    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    // Cursor c3 = Cursor::GetInstance(); // 복사
    // c3 = Cursor::GetInstance(); // 대입

    cout << &c1 << endl;
    cout << &c2 << endl;
}