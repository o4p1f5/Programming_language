#include <iostream>

void foo(int* x, int n)
{
    for(int i=0; i<n;i++)
    {
        std::cout << x[i] << std::endl;
    }
}
void goo(int(*p)[2]) // int 두 칸 배열을 가리키는 포인터(8바이트)
// int*p[2] 라고 쓰면 int*p [2] 로 포인터배열이 된다. [int*][int*] (16바이트)
{

}
/*
int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10}; // x는 int형 배열 10개 // x의 타입은 int[10]
    foo(x,10);

    int y[3] = {1,2,3} ; // y의 타입은 int[3] // x와 y는 타입이 다르다.
    // 함수에서 배열을 호출할 때 int *x로 표현되는 이유
    // : C++ 함수는 배열을 인자로 전달받을 때, decay(부식)를 수행한다.
    // decay(부식) => 배열의 첫번째 원소의 시작 주소가 전달된다.
    foo(y,3);
    auto a = y[0]; // a의 자료형을 우항의 타입과 동일하게 함(컴파일 타임에) // int
    auto p = &y[0]; // int*
    // 반드시 우항이 있어야 사용할 수 있는 코드

    int z[3][2]; // z의 타입 : int[3][2] : 행렬 : [int[2]][int[2]][int[2]]
    goo(z);
}*/

void hoo(int (*p)[3])
{

}

typedef int (*POINTER)[3]; // 기존타입의 별칭을 만들어서 사용할 수 있게 함
void goo (POINTER p) // hoo와 동일한 함수
{

}

// C++11에서는 typedef 말고, using을 통해서 타입의 별칭을 만들 수 있다.
// -> 가독성이 좋고, typedef는 템플릿의 문법에서는 사용할 수 없다.
using POINTER2 = int(*) [3];
void xoo (POINTER2 p) // hoo와 동일한 함수
{

}

int main()
{
    int x[2][3];
    hoo(x);
    goo(x);
    xoo(x);
}