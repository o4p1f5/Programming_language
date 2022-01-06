#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    return b!= 0 ? gcd(b, a%b) : a;
}
// double gcd(double a, double b); // 1) 선언부만 작성
                                   // 다른 파일에 구현된 함수를 찾으려고 함
                                   // 따로 구현해주지않았으므로 링킹오류발생
                                   // 링킹오류로 실행파일 생성을 막음
                                   // 하지만 의도가 잘 들어나지 못함
                                
// double gcd(double a, double b) = delete; // 2) 함수를 삭제하는 문법          
                                            // 컴파일 오류 발생
                                            // 링킹오류를 발생시키는 것보다 의도가 잘 드러남

int main()
{
    cout << gcd(a,10) << endl;
    cout << gcd(2.2, 4.3) << endl; 
    // 자동형변환돼서 동작될 뿐 실제론 동작하면 안되는 코드
    // gcd 함수를 double에 대해서 사용할 수 없도록 하려면
    // 1) 의도적으로 함수의 선언부만 제공
    // 2) 함수를 삭제하는 문법      
}