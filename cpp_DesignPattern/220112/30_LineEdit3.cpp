#include <iostream>
#include <string>
using namespace std;

// Windows - getch(비표준 함수)
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
// 에코 없이 입력하면 바로 결과가 나오는 처리 방식
int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
//--------

// 2) 변하는 것을 다른 클래스로 뽑아낸다.
// => 교체가능한 인터페이스 기반 클래스로 뽑아낸다 : Sterategy Pattern(전략 패턴)
// => 실행시간에 정책 변경 가능
// => Validator의 정책을 다른 클래스 에서도 재사용 가능

// 새로운 정책의 LineEdit가 필요하면,
// 정책 클래스를 Validator의 인터페이스를 기반으로 만들어주며 됨

// Validation 정책에 관한 인터페이스 설계
struct Validatior{
    virtual ~Validatior() {}

    virtual bool Validate(const std::string& s, char c) =0;
    virtual bool IsComplete(const std::string& s) =0;
};

class LineEdit {
    std::string data;
    Validatior* pValidatior;
public:
    LineEdit() : pValidatior(nullptr)
    {
    }
    void SetValidator(Validatior* p) {pValidatior = p;}
    std::string GetData()
    {
        data.clear();

        while (1) {
            char c = getch();

            if (c == '\n' && (pValidatior == nullptr || pValidatior->IsComplete(data)))
                break;

            if (pValidatior == nullptr || pValidatior->Validate(data, c)) 
            {
                data.push_back(c);
                cout << c;
            }
        }

        cout << endl;
        return data;
    }
};

class LimitDigitValidator : public Validatior
{
    int limit;
    public :
    LimitDigitValidator(int n) :limit(n)
    {
    }

    bool Validate(const std::string& s, char c) override
    {
        return s.size() < limit && isdigt(c);
    }
    bool IsComplete(const std::string& s) override
    {
        return s.size() == limit;
    }
};

int main()
{
    LineEdit edit;

    LimitDigitValidator v(5); // 숫자를 5개까지만 입력할 수 있게 제한을 줌
    edit.SetValidator(&v);

    while (1) {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}