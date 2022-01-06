#include <iostream>
using namespace std;

// Stack
// 1) 전역변수와 전역함수를 이용한 스택

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
} // => 번거러움이 있는 코드


// 2) stack 이용
/*
struct Stack
{
    int buff[10];
    int idx;
};

void push(Stack *s, int v)
{
    s->buff[(s->idx)++]=v;
}

int pop(Stack *s)
{
    return s->buff[--(s->idx)];
}
Stack s1;

int main()
{
    Stack s2;

    s1.idx = 0;
    s2.idx = 0;

    push(&s1, 10);
    push(&s2, 20);

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}
*/

// 3) 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자.
/*
struct Stack
{
    int buff[10];
    int idx;
     void push(int v)
     {
         buff[idx++]=v;
     }
     int pop(Stack *s)
     {
         return buff[--idx];
     }
};

Stack s1;

int main()
{
    Stack s2;

    s1.idx = 0;
    s2.idx = 0;

    s1.push(10);
    s2.push(20);

    cout << s1.pop(&s1) << endl;
    cout << s2.pop(&s2) << endl;
}
*/


// 4) 구조체 내부의 데이터를 외부에서 함부로 조작할 수 없도록 정보 은닉이 필요
//  -> 접근 지정자
/*
struct Stack 
{
private:
    int buff[10];
    int idx;
public:
     void push(int v)
     {
         buff[idx++]=v;
     }
     int pop(Stack *s)
     {
         return buff[--idx];
     }
};

Stack s1;

int main()
{
    Stack s2;

    s1.idx = 0;
    s2.idx = 0;

    s1.push(10);
    s2.push(20);

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}
*/

//5 생성자
/*
class Stack 
{
private:
    int buff[10];
    int idx;
public:
Stack() // 생성자
{
    cout << "Stack()" << endl;
    idx = 0;
}
void init()
{
    idx =0;
}
     void push(int v)
     {
         buff[idx++]=v;
     }
     int pop(Stack *s)
     {
         return buff[--idx];
     }
};

Stack s1;

int main()
{
    Stack s2;
    s1.push(10);
    s2.push(20);

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}
*/

// 6) 사용자가 스택의 크기를 결정할 수 있도록 함
// 생성자는 오버로딩 가능 // 생성자는 인자가 있어도 없어도 됨
/*
class Stack 
{
private:
    int * buff;
    int idx;
public:
Stack(int sz = 10) // 생성자
{
    idx = 0;
    buff = new int[sz];
}
     void push(int v)
     {
         buff[idx++]=v;
     }
     int pop()
     {
         return buff[--idx];
     }
};

Stack s1;

int main()
{
    Stack s2(100);
    Stack s3(100);
    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}*/

// 7) 소멸자 : 반환타입 표기 X : 인자를 가질 수 없다.
/*
class Stack 
{
private:
    int * buff;
    int idx;
public:
Stack(int sz = 10) // 생성자
{
    idx = 0;
    buff = new int[sz];
}
~Stack() // 소멸자
{
    delete[] buff;
}
     void push(int v)
     {
         buff[idx++]=v;
     }
     int pop()
     {
         return buff[--idx];
     }
};

Stack s1;

int main()
{
    Stack s2(100);
    Stack s3(100);
    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}*/