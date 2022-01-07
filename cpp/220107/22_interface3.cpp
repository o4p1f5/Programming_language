#include <iostream>
#include <vector>
using namespace std;

// 약한 결합 만들기
// 1) interface : 순수가상함수로만 이루어진 클래스 // 교체 가능
// 2) 블랙박스를 이용하는 코드로 만들기
// 3) 카메라 클래스를 블랙박스 클래스에 상속받게 함
// => 인터페이스는 하면 복잡도가 올리감, 속도 느려짐
class BlackBoxCamera // interface 혹은 프로토콜
{
    public:
    virtual ~BlackBoxCamera() {}
    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
    // 인터페이스를 사용하는 클래스는 변경이 쉽지만 인터페이스 자체를 수정하면 모든 것에 함수 재정의 등 동작을 해줘야한다
    // => 인터페이스에 기분구현을 할 수 있게 해줌
};

// 다른 작성방법
/*
struct BlackBoxCamera // interface
{
    virtual ~BlackBoxCamera() {}
    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};
*/

class Car 
{
    BlackBoxCamera* pCamera;
    public:
    Car(BlackBoxCamera* p) : pCamera(p)
    {
    }
    void Start()
    {
        pCamera ->StartRecord();
    }
    void Stop()
    {
        pCamera ->StopRecord();
    }
};


class Camera : public BlackBoxCamera
{
    public:
    void StartRecord() override
    {
        cout << "Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera : public BlackBoxCamera
{
    public:
    void StartRecord() override
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "[HD]Stop Record" << endl;
    }
};


int main()
{
    // OCP : 모든 것을 수정하는 것이 아니라 하나만 변경해도 쉽게 수정할 수 있다
    HDCamera cam; // cam의 클래스 자료형만 변경해주면 출력이 Camera -> [HD]Camera로 바뀜
    Car car(&cam);

    car.Start();
    car.Stop();
}