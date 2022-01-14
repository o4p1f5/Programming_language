#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unistd.h> // sleep(l);
using namespace std;

// 플라이 웨이트(Flyweight / 경량) 패턴
// : 속성이 동일한 객체가 다수 생성된다면, 하나의 객체를 공유해서 사용하자.

class Image
{
    std::string url;
    // 사용자는 Image 객체를 마음대로 생성할 수 없다.
    Image(const std::string& s) : url(s) 
    {
        cout << "Loading from " << url << endl;
        sleep(3);
    }
    friend class ImageFactory;
public:
    void Draw() { cout << "Draw Imapg : " << url << endl;}
};

// Factory : 객체생성역할
// 팩토리 클래스(싱글톤)
// : 이미지 객체의 생성 책임을 하나의 클래스를 통해 중앙 집중적으로 관리할 수 있다.
class ImageFactory
{
    private:
    ImageFactory() {}
    ImageFactory(const ImageFactory&) = delete;
    ImageFactory& operator=(const ImageFactory&) = delete;

    std::map<std::string, Image*> cache;

    public:
    Image* CreateImage(const std::string& url)
    {
        if(cache[url] == nullptr)
        {
            cache[url] = new Image(url);
        }
        return cache[url];
    }
    static ImageFactory& GetInstance()
    {
        static ImageFactory instance;
        return instance;
    }
};

int main()
{
    ImageFactory& factory = ImageFactory::GetInstance();

    Image* img1 = factory.CreateImage("https://a.com/images/a.png");
    img1->Draw();

    Image* img2 = factory.CreateImage("https://a.com/images/a.png");
    img2->Draw();
}