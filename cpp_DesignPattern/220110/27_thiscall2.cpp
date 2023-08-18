#include <iostream>
using namespace std;

class Sample 
{
    int data;
public:
    void f1() // void f1(Sample* const this)
    {
        cout << "f1" << endl; // this 접근이 없으므로 프로그램 다운 X
    }

    int f2() // void f2(Sample* const this)
    {
        cout << "f2" << endl; // this 접근이 없으므로 프로그램 다운 X
        return 0;
    }

    /*
    int f3()
    {
        cout << "f3" << endl;
        return data; // this 접근하므로 프로그램 비정상 종료
        // c++의 특성
    }
    */

    /*
    int call_f3() // int call_f3(Sample* const this)
    {
        // C++ idioms
        // - C++에서 자주 사용되는 코드 기법.
        // this에 대해서 null 체크를 수행은 표준에서 권장하지않는다
        if (this) {
            return f3(); // this->f3()
        }

        return 0;
    }
    */

    // => 정적 멤버 함수를 통해 동일한 코드를 작성해야함
    // this를 self로 명시적으로 표현해줌
    static int call_f3(Sample* const self)
    {
        if (self) {
            return self->f3(); // this와 동일한 동작
        }

        return 0;
    }

protected:
    //  'this' pointer cannot be null in well-defined C++ code; pointer may be assumed to always convert to true [-Wundefined-bool-conversion]
    // 경고문 나옴

    int f3() // void f2(Sample* const this)
    {
        cout << "f3" << endl;
        return data; // return this->data
    }
};

int main()
{
    Sample* p = nullptr; // 메모리 할당 실패로 인해 nullptr 입니다.

    p->f1(); // Sample::f1(nullptr)
    // 출력으로 f1이 나옴
    p->f2();
    // 출력으로 f2가 나옴

    // p->f3(); // 프로그램 죽음 // protected로 막음
    p->call_f3(); // Sample::call_f3(p); // 안전한 호출

    Sample::call_f3(p);
}