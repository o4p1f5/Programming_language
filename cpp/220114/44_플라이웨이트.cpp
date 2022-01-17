#include <iostream>
#include <vector>
#include <string>
#include <unistd.h> // sleep(l);
using namespace std;

// 플라이 웨이트(Flyweight / 경량) 패턴
// : 속성이 동일한 객체가 다수 생성된다면, 하나의 객체를 공유해서 사용하자.

class Image
{
    std::string url;
    public:
    Image(const std::string& s) : url(s)
    {
        cout << "Loading from " << url << endl;
        sleep(3);
    }

    void Draw() { cout << "Draw Imapg : " << url << endl;}
};

int main()
{
    Image* img1 = new Image("https://a.com/images/a.png");
    img1->Draw();

    Image* img2 = new Image("https://a.com/images/a.png");
    img2->Draw();

}