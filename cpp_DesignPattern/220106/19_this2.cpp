#include <iostream>
#include <string>
using namespace std;

/*
class User
{
    string name;
    int age;
public:
    // 초기화 리스트에서 this->xxx 형식으로 초기화 불가능
    // -> 멤버 데이터는 이름 뒤에 언더스코어 형식을 권장함
    User(const string& name, int age)
    {
    }

    // User(const string& a, int b) : name(a), age(b) {}
    void set(const string& name, int age)
    // 멤버 변수 이름과 매개변수 이름이 같을 때, this 사용
    {
        this->name = name;
        this->age = age;
    }
};
*/

// => 보완
/*
class User
{
    string name_; // 언더스코어 형식
    int age_;
public:
    User(const string& name, int age) : name_(name), age_(age) {} 
    // 초기리스트 사용가능

    void set(const string& name, int age)
    // 언더스코어 이용으로 this 사용 X
    {
        name_ = name;
        age_ = age;
    }
};

int main()
{
    User user1("Tom", 42);
}
*/

// this 활용
// 1)

class User
{
    string name_;
    string address_;
    string phone_;
public:
    User* SetName(const string& name) { name_=name; return this; }
    User* SetAddress(const string& address) { address_=address; return this; }
    User* SetPhone(const string& phone) { phone_=phone; return this; }
    void Print()
    {
        cout << name_ << endl << address_ << endl  << phone_ << endl;
    }
};

int main()
{
    User user;
    user.SetName("Tom")-> SetAddress("Seoul")-> SetPhone("010-1234-5678");
    user.Print();
}


// 2)
/*
class User
{
    string name_;
    string address_;
    string phone_;
public:
    User& SetName(const string& name) { name_=name; return *this; }
    User& SetAddress(const string& address) { address_=address; return *this; }
    User& SetPhone(const string& phone) { phone_=phone; return *this; }
    void Print()
    {
        cout << name_ << endl << address_ << endl  << phone_ << endl;
    }
};

int main()
{
    User user;
    user.SetName("Tom"). SetAddress("Seoul"). SetPhone("010-1234-5678");
    user.Print();
}
*/