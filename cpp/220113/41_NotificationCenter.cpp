// 41_NotificationCenter.cpp

#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <string>
using namespace std;

class NotificationCenter
{
    public:
    using HANDLER = function<void()>;

    std::map<std::string, std::vector<HANDLER>> notifiMap; // 문자열로 된 식별자 하나에 함수를 여러개 넣을 수 있다.

    void AddObserver(const std::string&name , HANDLER h)
    {
        notifiMap[name].push_back(h);
    }
    void PostNotification(const std::string& name)
    {
        vector<HANDLER>& v = notifiMap[name];
        for(auto f : v)
        {
            f();
        }
    }
};

void foo() {cout << "foo" << endl;}

class Dialog
{
    public:
    void Close() {cout << "Dialog Close" << endl;}
};

// C++ Callback을 등록하는 2가지 형태
// 1) 인터페이스 기반 객체로 등록 : 전통적인 객체지향 설계방식
//   ex) 관찰자 패턴, 리스너
// 2) 함수 포인터 기반의 핸들러 방식
//   ex) NotificationCenter

int main()
{
    NotificationCenter center;

    center.AddObserver("BATTERT", &foo);

    Dialog dlg;
    center.AddObserver("BATTERT", bind(&Dialog::Close, &dlg));

    center.PostNotification("BATTERT");
}