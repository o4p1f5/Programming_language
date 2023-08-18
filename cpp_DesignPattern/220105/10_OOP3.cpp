#include <iostream>
using namespace std;
// 클래스도 템플릿으로 만들 수 있다.
// 단, 타입 추론이 불가능해서 명시적으로 타입을 지정해줘야함

template <typename T>

class Stack 
{
private:
    T * buff;
    int idx;
public:
Stack(int sz = 10) // 생성자
{
    idx = 0;
    buff = new T[sz];
}
~Stack()
{
    delete[] buff;
}
     void push(const T &v)
     {
         buff[idx++]=v;
     }
     T pop()
     {
         return buff[--idx];
     }
};

strust Complex
{

};
Stack <Complex> s4;

Stack <int>s1; // T -> int

int main()
{
    Stack<long> s2(100); // T-> long
    Stack<double> s3(100); // T -> double
    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}