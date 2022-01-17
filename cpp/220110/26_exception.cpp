#include <iostream>
using namespace std;

// 예외 : 오류 처리
// C언어에서의 오류 처리 방법 -> 반환값을 통해 처리
//                           -> 반환된 값이 실패를 나타내는 것인지, 연산의 결과인지 구분하기 어렵다.
//                           -> 함수가 오류를 반드시 처리하라고 강제화할 방법이 없다.

int foo(int a)
{
    if(a<0)
    {
        return -1; // 실패할 경우의 반환
    }

    return 0;
}

// C++의 예외처리방식

int goo(int a)
{
    if(a<0)
    {
        throw 1; // 실패할 경우, 예외를 던짐.
    }
    return 0;
}

/*
int main()
{
    int ret1 = g00(-100); // 비정상 종료가 일어남
    // 함수가 예외를 던지면 반드시 예외를 처리해야함
    // => 처리하지않으면 프로그램 강제로 종료됨.
    int ret2 = foo(-100);
    if(ret2 == -1)
    {
        printf("foo 함수가 실패했습니다.");
    }
}
*/

// goo의 예외처리
int main()
{
    try{
    int ret1 = goo(-100);
    cout << "result: " << ret1 << endl;
    } catch(int n) {// int형 예외를 catch함
    } catch (double d) { // double 형 예외 처리}
    } catch (...) {//  모든 종류의 예외를 캐치}
    }
    cout << "main end.." << endl;
}
