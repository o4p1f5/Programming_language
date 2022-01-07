#include <iostream>
using namespace std;

// 소멸자
// 모든 객체가 생성될 때, 생성자가 호출되고 메모리에서 소멸될 때 소멸자가 호출
// 1. 함수 이름은 ~클래스 이름()
// 2. 반환 X, 매개변수 X
// 3. 오버로딩 X, 오직 한개만 제공
// 4. 자동으로 제공가능
// 5. 생성자에서 자원을 획득한 경우, 소멸자를 통해 자원을 반납해야됨

// 자원 => 메모리, 파일, 프로세스, 스레드, 락...

class User
{
    char* name;
public:
    User(const char* s)
    {
        cout << "메모리 할당" << endl;
        name = new char[std::strlen(s) + 1];
        strcpy(name, s);
    }
    ~User()
    {
        cout << "메모리 해지" << endl;
        delete[] name;
    }
}

int main()
{
    User user("홍길동"); // 메모리 할당, 메모리 해지 출력
}
