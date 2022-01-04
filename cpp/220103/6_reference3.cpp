#include <iostream>
#include <string>
using namespace std;

struct User // 사용자 정의 자료형은 오버헤드가 발생하기 쉬움
{
    std::string name;
    int age;
};

void printUser(const User &user) // void printUser(User user) 오버헤드 발생 
// & : 복사에 의한 오버헤드를 없앨 수 있지만 메인문의 변수 값이 변경될 수 있다.
//   : 따라서 함수 구현 시, 값이 변경되지않게 const & 를 사용
{
    cout << user.name << ", " << user.age << endl;
    // user.age += 10; -> 컴파일 오류
}

int main()
{
    User user{"Tom", 42};
    printUser(user);
}