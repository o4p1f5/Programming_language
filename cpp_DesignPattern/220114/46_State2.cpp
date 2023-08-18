#include <iostream>
using namespace std;

// 방법 1) 아이템 종류에 따른 조건 분기
// 문제점 : OCP 만족 X, 신규 아이템이 추가되면 조건 분기문이 계속 추가되거나 수정되어야한다.

class Charcter
{
    int gold;
    int item;

    public:
    void SetItem(int i) { item = i;}

    void Run()
    {
        if(item == 1)
        cout << "Run" << endl;
        else if( item == 2)
        cout << "Fast Run" << endl;
        else if(item == 3)
        cout << "Slow Run" << endl;
    }
    void Attack()
    {
        cout << "Attack" << endl;
    }
};

int main()
{
    Charcter c;
    c.SetItem(3); // item == 3

    c.Run();
    // c.Attack();
}