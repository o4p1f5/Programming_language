#include <stdio.h>

namespace std
{
    class istream
    {
        public:
        istream& operator>>(int &n)
        {
            scanf("%d", &n);
            return *this;
        }
    };
    istream cin;
}

class Point
{
    int x;
    int y;
public :
    Point (int a, int b) : x(a), y(b)
    {}
    friend std::istream& operator>>(std::istream& is, Point& p);
};
std::istream& operator>>(std::istream& is, Point& p)
{
    return is >> p.x >> p.y;
}

int main()
{
    int n=0;
    std::cin >> n;

    Point p(10,20);
    std::cin >> p;
}