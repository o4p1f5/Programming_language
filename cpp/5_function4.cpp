#include <iostream>
using namespace std;

// 템플릿 : 새로운 자료형을 만든다.
template <typename T>
/* int square(int a) // 함수의 타입만 다를 뿐 두 함수의 기능은 동일하다.
// 사용자가 템플릿을 제공하면 컴파일러가 코드를 컴파일할때
// 어떤 타입의 함수가 필요한지 조사해서 실제 함수를 생성해준다.
{
    return a*a;
}
double square(double a)
{
    return a*a;
} */

T square(T a) // 템플릿으로 지정한 새로운 자료형 T
// 템플릿 대신 class를 사용해도 된다.
{
    return a*a;
}

int main()
{
    cout << square(3) << endl;
    cout << square(3.14) << endl;
} 
