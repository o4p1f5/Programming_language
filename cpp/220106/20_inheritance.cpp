#include <iostream>
#include <string>
using namespace std;

// 상속 : 공통의 속성을 관리하는 것이 편리하다
/*
class Student
{
    string name;
    int age;
    int id;
};

class Professor
{
    string name;
    int age;
    int major;
};
*/

// 공통의 속성을 가진 타입을 설계한다

// Base 클래스
class User
{
    string name;
    int age;
};

// Sub 클래스
class Student : public User
{
    int id;
};

class Professor : public User
{
    int major;
};