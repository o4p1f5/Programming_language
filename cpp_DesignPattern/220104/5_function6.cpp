#include <iostream>
using namespace std;

// 함수 포인터
// 함수의 주소를 참조하는 포인터
// 함수포인터를 이용해 함수를 호출할 수 있다.
// 함수포인터를 사용하는 이유 -> 
// 함수의 중복 -> 자료형과 이름이 같은 함수는 매개변수의 자료형에 의해 구분됨.

int add(int a,int b)
{
    return a+b;
}

/*int (*foo()) (int a, int b) // 한눈에 잘 들어오지않음
{
    return &add;
}*/
// -> 간결하게 표현 using 
using FP = int(*p2)(int s, int b);

FP foo()
{
    return &add;
}

// ** C++11 - trailing return type
// => 함수를 만드는 새로운 문법을 제공합니다.
auto sub1(int a, int b) -> int
{
    return a-b;
}
auto foo2() -> int (*) (int a, int b)
{
    return &add;
}

/*
int main()
{
    int a;
    int* p = &a;
    int(*p2)(int s, int b)= &add; // int*p2(int s, int b)로 쓰면 p2라는 함수가 만들어짐
    // 함수포인터의 표현
    cout << (*p2)(10,20) << endl;
}
*/

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i=0;i<10;i++)
    {
        cout << x[i] << endl;
    }

    //C++11 - ranged for
    for(int n : x) // 배열 x에서 원소 하나씩 꺼내서 n에 전달
    {
        cout << n << endl;
    }
}