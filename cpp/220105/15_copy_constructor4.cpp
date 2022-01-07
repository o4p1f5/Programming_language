#include <iostream>
using namespace std;

class User
{
    char *name;
    int age;
    // 2) 참조계수 관리 변수
    /*
    int *ref;
    */
public:
    User(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        //2)
        /*
        ref = new int; // 참조계수변수를 힙공간에 할다
        *ref = 1; // 1로 초기화
        */
    }
    // 얕은 복사 => 오류 발생
    User(const User &n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // 해결책
    // 1) 깊은 복사 필요 -> 복잡
    /*
    User(const User &n) : age(n.age)
    {
        name = new char[strlen(n.anme) + 1]; // 새로운 공간 생성
        strcpy(name, n.name);
    }
    */

    // 2) 참조계수 기반 수명 관리 -> 포인터 계수대로 참조계수를 변경, 0이 되면 공간 소멸
    /*
    User(const User &n) : name(n.name), age(n.age), ref(n.ref)
    {
        ++(*ref);
    }
    */

    // 3) 복사 금지 => 복사를 시도하면 컴파일 오류가 발생하게 함
    // User(const User &n) = delete;

    ~User()
    {
        delete[] name;
        // 2)
        /*
        if( --(*ref) == 0)
        {
            delete[] name;
            delete ref;
        }
        */
    }
};

int main()
{
    User user("Yoon", 42);
    User user2(user); // 오류 발생 -> 컴파일러가 주는 기본 복사생성자는 힙 공간을 옮길 수행능력이 없다.
    // -> user과 user2가 같은 공간을 가리킴
    // 메모리 누수 : user2가 소멸할 공간이 user이 소멸될때 소멸되기 때문에 오류 발생
}
