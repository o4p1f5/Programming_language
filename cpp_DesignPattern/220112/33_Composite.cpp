#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. File / Folder
// => 공통의 부모 : Item
// => 다형성: GetSize()
//  * 폴더는 내부의 파일의 크기의 총 합을 통해 구해집니다.
//  * 파일은 자신의 크기 정보를 가지고 있습니다.

class Item 
{
    std::string title;
    public:
    Item(const std::string& s) : title(s)
    {
    }
    virtual ~Item() {}
    virtual int GetSize() const = 0;
    std::string GetTitle() const {return title;}
};

class File : public Item
{
    int fileSize;
    public:
    File(const std::string& s, int size) : Item(s), fileSize(size)
    {}
    ~File()
    {
        cout << GetTitle() << "파일 삭제" << endl;
    }

    int GetSize() const override
    {
        return fileSize;
    }
};

class Folder : public Item // 복합 객체
{
    std::vector<Item*> v; // 공통 부모 포함
    public:
    Folder(const std::string& s) : Item(s)
    {}
    ~Folder()
    {
        // 자신이 소유한 모든 개게에 대해서 메모리 해지해주어야한다.
        for(auto e:v)
        {
            delete e;
        }
        cout << GetTitle() << "폴더 삭제" << endl;
    }
    
    void AddItem(Item* p)
    {
        v.push_back(p);
    }

    int GetSize() const override
    {
        int sum = 0;
        for(auto e : v)
        {
            sum += e -> GetSize();
        }
        return sum;
    }
};

int main()
{
    Folder* fol1 = new Folder("ROOT");
    Folder* fol2 = new Folder("A");

    File* f1 = new File("a.txt", 10); // 이름, 크기
    File* f2 = new File("b.txt", 20);

    fol2->AddItem(f1);
    fol1->AddItem(f2);
    fol1->AddItem(fol2);
    cout << f2->GetSize() << endl;
    cout << fol2->GetSize() << endl;
    cout << fol1->GetSize() << endl;

    delete fol1;
}
