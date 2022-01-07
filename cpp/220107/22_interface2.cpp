#include <iostream>
#include <vector>
using namespace std;

class Camera
{
    public:
    void StartRecord() 
    {
        cout << "Start Record" << endl;
    }

    void StopRecord()
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera
{
    public:
    void StartRecord() 
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord()
    {
        cout << "[HD]Stop Record" << endl;
    }
};

class Car // Camera에 강하게 결합됨 // 새로운 정보로 업데이트하기 어려움
// => 약한 결합 만들기
{
    Camera* pCamera;
    public:
    Car(Camera* p) : pCamera(p)
    {
        pCamera ->StartRecord();
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

int main()
{
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}