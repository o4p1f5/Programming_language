#include <iostream>
using namespace std;

// Stack
// 1) 전역변수와 전역함수를 이용한 스택
/*
int buff[10];
int idx = 0;

void push(int v)
{
    buff[idx++]=v;
}

int pop()
{
    return buff[--idx];
}

int main()
{
    push(10);
    push(20);

    cout << pop() << endl;
    cout << pop() << endl;
} => 번거러움이 있는 코드
*/

// 2) 