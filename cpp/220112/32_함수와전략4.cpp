#include <iostream>
using namespace std;

// 32_함수와전략.cpp 와 비교

// 함수
/*
void Sort(int* x, int n, bool(*cmp)(int a, int b)) // 함수 포인터 사용
{
    for(int i= 0; i<n-1 ; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            // if(x[i] > x[j])
            if(cmp(x[i], x[j]))
            swap(x[i], x[j]);
        }
    }
}
*/

// 함수객체를 이용함
template <typename T> 
// 함수포인터를 통해서만 정책을 전달하는 것이 아니라
// 함수 객체를 통해서도 정책을 전달하기 위한 사용
void Sort(int* x, int n, T cmp) // 함수 포인터 사용
{
    for(int i= 0; i<n-1 ; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            // if(x[i] > x[j])
            if(cmp(x[i], x[j]))
            swap(x[i], x[j]);
        }
    }
}

// 함수
bool cmp1(int a, int b) {return a>b;} // 오름차순
bool cmp2(int a, int b) {return a<b;} // 내림차순

// 함수 객체 : inline 사용 가능 => 오버헤드 없앰
struct Less
{
    inline bool operator() (int a, int b) const { return a > b;}
};
struct Greater
{
    inline bool operator() (int a, int b) const { return a < b;}
};

int main()
{
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    // Sort(x,10);
    Less less;
    Greater greater;

    // 함수 포인터로 전달 : 한 개의 생성된 함수를 공유해서 사용 가능 => 코드 메머리 사용량 절약
    //                   : 호출 오버헤드가 있음, 인라인 치환X
    Sort(x, 10, &cmp1); // 오름차순
    Sort(x, 10, &cmp2); // 내림차순

    // 함수 객체로 전달 : 정책이 호출되는 것이 아니라 인라인 치환 => 빠르다
    //                 : 코드를 생성한다.
    Sort(x, 10, less);
    Sort(x, 10, greater);

    for(int e : x)
    {
        cout << e << endl;
    }
}