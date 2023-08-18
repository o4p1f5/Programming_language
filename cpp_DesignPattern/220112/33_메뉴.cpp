#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Composite Pattern
// 1) MenuItem(개별 객체) / PopupMenu(복합 객체)
// 2) 복합 객체는 개별객체와 복합 객체 모두 보관가능
// => 복합 객체와 개별 객체가 공통 부모를 가지고 있어야한다.
// 3) 복합 객체의 사용법이 동일해야한다. 그 사용법은 부모 클래스에 기반해야한다.

class BaseMenu // MenuItem과 PopupMenu의 공통 분모
// 두 클래스의 공통 기능이 부모클래스로부터 비롯되어야한다.
{
    std::string title;
    public:
    BaseMenu(const std::string& s) : title(s)
    {
    }
    virtual ~BaseMenu() {}
    std::string GetTitle() const {return title;}

    virtual void Command() = 0;
};

class MenuItem : public BaseMenu
{
    public:
    ~MenuItem() {}
    MenuItem(const std::string& s) : BaseMenu(s)
    {}

    void Command() override
    {
        cout << "메뉴 선택됨 : " << GetTitle() <<endl;
        getchar();
        getchar();
    }
};

// PopupMenu는 MenuItem도 가지고 있고, PopupMenu도 가지고 있어야한다

class PopupMenu : public BaseMenu
{
    std::vector<BaseMenu*> v; 
    public:
    PopupMenu(const std::string&s) : BaseMenu(s)
    {}
    ~PopupMenu()
    {
        for(auto e:v)
        {
            delete e;
        }
    }
    void AddMenu(BaseMenu* p)
    {
        v.push_back(p);
    }

    //자신의 모든 메뉴를 화면에 보여준다.
    void Command() override
    {
        while(1)
        {
            system("clear");
            int size = v.size();
            for(int i=0;i<size ; ++i)
            {
                cout << i + 1 << ". " << v[i]-> GetTitle() << endl;
            }
            cout << size + 1 << ". 상위 메뉴로" << endl;
        
        cout << "메뉴를 선택하세요 >>";
        int cmd;
        cin >> cmd;

        if(cmd == size +1)
        { 
            break; 
        }
        if(cmd < 1 || cmd > size + 1)
        {
            continue;
        }
        v[cmd - 1] -> Command(); // 다형성
        }
    }
};

int main()
{
    PopupMenu* menubar = new PopupMenu("Menubar");
    PopupMenu* file = new PopupMenu("파일");
    PopupMenu* edit = new PopupMenu("편집");
    menubar->AddMenu(file);
    // menubar->AddMenu(edit);
    file->AddMenu(edit);

    file->AddMenu(new MenuItem("새 파일"));
    file->AddMenu(new MenuItem("저장"));
    file->AddMenu(new MenuItem("불러오기"));

    edit->AddMenu(new MenuItem("잘라내기"));
    edit->AddMenu(new MenuItem("복사"));
    edit->AddMenu(new MenuItem("붙여넣기"));

    menubar->Command();
}