// endl은 함수

/*
#include <iostream>
using namespace std;
ostream& xendl (ostream& os)
{
    os << '\n';
    return os;
}

int main()
{
    cout << endl;
    endl(cout);

    cout << xendl;
    xendl(cout);
}
*/

// 사용자가 endl에 대한 도구를 쉽게 만들어서 확장가능
// => endl같은 함수는 조작자 함수라고 함
/*
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
        ostream& operator<<(char c)
        {
            printf("%c", c);
            return *this;
        }
        ostream& operator<<(ostream& (*f) (ostream&))
        {
            f(*this);
            return *this;
        }
    };
    ostream& endl(ostream& os)
    {
        os << '\n';
        return os;
    }
    ostream cout;
}
*/
#include <iostream>

std::ostream& tab(std::ostream& os)
{
    os << '\t';
    return os;
}

std::ostream& menu(std::ostream& os)
{
    return os << "1. 짜장면" << std::endl
              << "2. 짬뽕" << std::endl
              << "3. 비빔밥" << std::endl;
}

int main()
{
    std::cout << tab << 42 << std::endl;

    std::cout << menu;
}