// 멤버 함수 포인터 이야기

#include <iostream>
using namespace std;

void foo() // void() 타입
{
    printf("foo\n");
}

class Dialog 
{
public:
    void Close() // void Close(Dialog* const this)
    {
        cout << "Dialog close" << endl;
    }

    static void foo() // void foo()
    {
        cout << "Dialog foo" << endl;
    }
};

int main()
{
    void(*f) () = &foo;
    (*f)(); // foo 함수 작동

    // void(*f) () = &Dialog::Close;
    // 오류 // 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.

    void(*f) () = &Dialog::foo;
    (*f)(); // Dialog foo 함수 작동
    // 일반 함수 포인터에 정적 멤버 함수의 주소를 담을 수 있다.

    Dialog dlg; 

    // 1) 직접적인 호출
    dlg.Close();

    // 멤버 함수 포인터를 만드는 방법
    // => 멤버 함수 포인터 타입을 별도로 제공한다.
    void (Dialog::*mp)() = &Dialog::Close;
    // 어떤 클래스의 멤버함수인지 명시적으로 작성
    // (*mp)(); 
    // 오류 발생 // 멤버 함수 호출은 객체가 필요하다.
    // => 객체가 필요하다.

    //  .* : 멤버 함수 포인터 참조 연산자
    // 2) 멤버함수포인터를 이용한 간접적인 호출
    (dlg.*mp)();

    // ->* : 객체가 포인터인 경우 멤버 함수 포인터 참조 연산자
    Dialog* pDialog = new Dialog;
    (pDialog->*mp)();

    void (*f)() = &Dialog::foo;
    (*f)();
}