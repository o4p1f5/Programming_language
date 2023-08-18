#include <iostream>
#include <string>
using namespace std;

// 디자인 패턴에서 변하는 것을 인터페이스 기반 클래스로 만들어서 교체하는 패턴은
// 세가지이다.
// 1) 전략 패턴 : 정책을 캡슐화
// 2) 상태 패턴 : 상태 변경에 따른 동작을 정의한 클래스를 캡슐화
// 3) 빌더 패턴 : 동일한 구축 공정으로 객체를 만들지만, 각 공정에 따라서 표현이 달라지는 객체를 만들때 사용한다.

using Character = std::string;

// 축구 게임의 캐릭터를 만드는 공정은 변하지 않는다.
struct Builder
{
    virtual ~Builder() {}
    virtual void CreatHead() = 0;
    virtual void CreatUniform() = 0;
    virtual void CreatShoe() = 0;

    virtual Character GetResult() = 0;
};

class Director
{
    Builder* pBuilder = nullptr;

    public:
    void SetBuilder(Builder* p) {pBuilder = p;}
    Character Construct()
    {
        // 얼굴, 몸통, 신발
        pBuilder->CreatHead();
        pBuilder->CreatUniform();
        pBuilder->CreatShoe();

        return pBuilder->GetResult();
    }
};

class Korea : public Builder
{
    Character c;
    public:
    void CreatHead() override
    {
        c += "검은머리\n";
    }
    void CreatUniform() override
        {
        c += "빨간 유니폼\n";
    }
    void CreatShoe() override
        {
        c += "아디다스\n";
    }
    Character GetResult() override
    {
        return c;
    }
};

class England : public Builder
{
    Character c;
    public:
    void CreatHead() override
    {
        c += "노란머리\n";
    }
    void CreatUniform() override
        {
        c += "흰 유니폼\n";
    }
    void CreatShoe() override
        {
        c += "나이키\n";
    }
    Character GetResult() override
    {
        return c;
    }
};

int main()
{
    Korea k;
    England e;

    Director d;
    d.SetBuilder(&k);
    cout << d.Construct() << endl;

    d.SetBuilder(&e);
    cout << d.Construct() << endl;
}