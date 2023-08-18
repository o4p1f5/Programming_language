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

// Validation 정책은 변경 가능해야한다
// => 변하는 것은 가상함수로 뽑아낸다(Template Method Pattern)

// 가변성을 캡슐화하는 방법
// 1) 가상함수로 캡슐화, 오버라이딩
class LineEdit
{
    std:: string data;
    // 변하는 않는 코드에서 변해야하는것이 있다면 변해야 하는것을 가상함수로 뽑아낸다
    virtual bool validate(char c) 
    { 
        return isdigit(c);
    } 
    public :
    std:: string GetData()
    {
        data.clear();
        while(1)
        {
            // char c = getchar();
            char c = getch();
            if(c='\n')
                break;
            if(validate(c))
            {
                data.push_bake(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

// 이제 정책을 변경하고 싶다면, 파생 클래스에서 가상 함수를 재정의
class AddressLineEdit : public LineEdit {
public:
    bool validate(char c) override
    {
        return true;
    }
};

// Template Method
// 1) 런타임에 정책을 변경할 수 없다.
// 2) 다른 종류의 클래스에서 해당 정책을 재사용할 수 없다.

int main()
{
    // LineEdit edit;
    AddressLineEdit edit;
    while (1) 
    {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}