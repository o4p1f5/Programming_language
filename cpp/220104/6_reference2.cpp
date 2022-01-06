#include <iostream>
using namespace std;

void inc(int x)
// 값에 의한 호출
{
    ++x; // 지역변수 x의 변환
}
void inc1(int *x)
//주소에 의한 호출
{
    ++(*x); // 지역변수 x의 변환
}
void inc2(int &x) // n의 메모리에 공간에 x라는 새로운 이름이 생김
// 참조에 의한 호출
{
    ++x;
}

void foo(int x[5]) // int x[5]를 그냥 포인터 int* x로 읽어 크기가 8byte로 나옴 // 배열의 첫 주소가 전달되기 때문
// 매개변수에 배열의 크기도 함께 알려줘야한다.
{
    prinnf("foo : sizeof(%1d)\n",sizeof(x));
}

void foo2(int (&x)[5]) // ** 참조는 decay가 안되기때문에 배열의 첫주소가 아닌 배열 그 자체의 크기가 출력됨.
{
    prinnf("foo : sizeof(%1d)\n",sizeof(x));
}

int main()
{
    int n = 10;
    inc(n); // n의 값을 복사해서 건내주므로 main문의 n의 값을 변하지 않음
    inc1(&n); // n의 주소를 건내주므로 메인문의 n의 값이 변화함
    inc2(n); // 참조에 의한 변화이므로 n에도 영향이 간다.
    cout << n << endl;

    int x[5];
    prinnf("main : sizeof(%1d)\n",sizeof(x));

    foo(x); // 배열의 첫 원소 주소 전달
    foo2(x); // 참조는 첫 원소의 주소를 전달하는 것이 아닌 별칭을 만들어주는것
}