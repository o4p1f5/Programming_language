#include <iostream>
using namespace std;

// 증감(++ / -- ) 연산자

class Integer
{
    int value;
    public:
    Integer(int n = 0) : value(n)
    {}
    /*
    void Print() const
    {
        cout << value << endl;
    }
    */
    Integer& operator++() // 전위 연산
    {
        value += 1;
        return *this;
    }

    Integer operator++(int) // 후위 연산
    {
        Integer temp = *this;
        value += 1;

        return temp;
    }


    friend std::ostream& operator<< (std::ostream& os, const Integer& i);
};
std::ostream& operator<< (std::ostream& os, const Integer& i)
{
    return os << i.value << endl;
}

int main()
{
    int n1;
    cout << n1 << endl;

    n1++;
    ++n1;
    // 서로 성능 차이 X

    Integer n2;
    // n2.Print();
    cout << ++n2 << endl;
    
    n2++;
    ++n2;
    // 서로 성능 차이 O => 반환타입이 다르기 때문
}
