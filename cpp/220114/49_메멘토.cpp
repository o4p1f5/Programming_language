#include <iostream>
#include <vector>
using namespace std;

// 캡슐화 정책을 깨뜨리지 않고, 객체상태 저장과 복원의 기능을 제공한다.
// => 메멘토 패턴 : 저장해야하는 상태를 별도의 클래스를 통해 캡슐화

class User
{
    int level;
    int x;
    int y;
    int exp;

    struct MemontoState // 저장해야하는 상태를 별도의 클래스로 캡슐화해서 사용
    {
    int level;
    int x;
    int y;
    int exp;
    };

    std::vector<MemontoState*> saved;

    public:
    // Save : 저장된 시점에 대한 토큰을 반환
    // Load : 토큰을 통해 해당 시점으로 복원이 가능
    int Save() 
    {
        MemontoState* state = new MemontoState { level, x, y, exp} ;
        saved.push_back(state);

        return saved.size() - 1; 
    }

    void Load(int token) 
    {
        MemontoState* state = saved[token];

        level = state->level;
        x = state->x;
        y = state->y;
        exp = state->exp;
    }

    void SetLevel(int l) {level = l;}

    void SetXY(int a, int b)
    {
        x=a; y=b;
    }
    void SetExp(int e) {exp = e;}

    void Print() const
    {
        cout << level << ", " << x << ", " << y << ", " << exp << endl;
    }
};

int main()
{
    User user;
    user.SetLevel(10);
    user.SetXY(0, 50);
    user.SetExp(1000);
    user.Print();

    int token = user.Save();
    user.SetLevel(20);
    user.SetXY(0, 0);
    user.SetExp(0);
    user.Print();

    user.Load(token);
    user.Print();
}