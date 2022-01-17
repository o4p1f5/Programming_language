#include <iostream>
#include <mutex>
using namespace std;

// Singleton을 만드는 두번째 방법 - 힙에 생성
// 문제점 : GetInstance() 호출이 스레드 안전하지 않다. => mutex 사용

class AutoLock
{
    std::mutex& mLock;
    public:
    inline AutoLock(std::mutex& m) : mLock(m)
    {
        mLock.lock();
    }
    inline ~AutoLock() { mLock.unlock(); }
};

class Cursor
{
    Cursor() {}
    Cursor(const Cursor&) = delete;
    Cursor& operator=(cosnt Cursor&) = delete;
    static Cursor* sInstance;
    static std::mutex sLock;

    public:
    /*
    static Cursor& GetInstance()
    {
       sLock.lock();
       if(sInstance == nullptr)
       sInstance = new Cursor; // 예외가능성 -> unlock을 호출하지않고 GetInstance를 빠져나옴
       // 데드락 위험성 => 예외 안전하게 사용하기 위해서, RAII를 이용
       // RAII(Resource Acquision is Initialize) : 생성자, 소멸자르 이용해 자원을 관리한다
       sLock.unlock();

       return *sInstance;
    }
    */

    /*
    static Cursor& GetInstance()
    {
       AutoLock al(sLock);
       // std::lock_guard<std::mutex> al(slock); // 표준 라이브러리 제공
       if(sInstance == nullptr)
       sInstance = new Cursor; 

       return *sInstance;
    }
    */
    
    // C++ 11 / 14
    static Cursor& GetInstance()
    {
        static Cursor* instance = new Cursor;
        return *instance;
    }
};

// 정적 멤버 변수는 반드시 외부선언이 필요하다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}