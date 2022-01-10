// #include <iostream>
// using namespace std;

// cout은 객체이다
// #include <iostream> 속의 std::ostream cout; 전역객체

/*
int main()
{
    int n =10;
    double d = 3.14;

    cout << n;
    // cout.operator<<(n) // cout.operator<<(int)
    cout << endl;
    cout << d;
    // cout.operator<<(d) // cout.operator<<(double)
    cout << endl;
}
*/

#include <stdio.h>

namespace std
{
    class ostream
    {
    public:
        ostream& operator<<(int n)
        {
            printf("%d", n);
            return *this;
        }
        ostream& operator<<(const char* s)
        {
            printf("%s", s);
            return *this;
        }
        ostream& operator<<(double d)
        {
            printf("%lf", d);
            return *this;
        }
    };
    ostream cout;
}

int main()
{
    std::cout << 42;
    std::cout << ", ";
    std::cout << 3.14;

    std::cout << 42 << ", " << 3.14;
}