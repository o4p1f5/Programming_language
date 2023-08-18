#include <iostream>
using namespace std;

// 오름차순 정렬 

// 버블 정렬 코드
// => 성능은 좋지 않지만 가장 간단하게 정렬할 수 있는 코드
// => 내림차순으로 정렬하려고 하면 함수를 바꿔야 함
// => 공통성과 가변성 분리 => 일반함수에서 변하는 것을 함수인자(함수 포인터)로 뽑아낸다
/*
void Sort(int* x, int n) // 배열의 첫 주소와 배열의 길이
{
    for(int i= 0; i<n-1 ; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(x[i] > x[j])
            swap(x[i], x[j]);
        }
    }
}
int main()
{
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    Sort(x,10);

    for(int e : x)
    {
        cout << e << endl;
    }
}
*/

// 정책 정리
/*
bool cmp1(int a, int b) {return a>b;} // 오름차순
bool cmp2(int a, int b) {return a<b;} // 내림차순

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
int main()
{
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    // Sort(x,10);
    Sort(x, 10, &cmp1); // 오름차순
    Sort(x, 10, &cmp2); // 내림차순 
    for(int e : x)
    {
        cout << e << endl;
    }
}
*/

// 최적화
// inline 사용 불가능 => 일반함수는 런타임, inline은 컴파일타임
bool cmp1(int a, int b) {return a>b;} // 오름차순
bool cmp2(int a, int b) {return a<b;} // 내림차순

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
int main()
{
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    // Sort(x,10);
    Sort(x, 10, &cmp1); // 오름차순
    Sort(x, 10, &cmp2); // 내림차순 
    for(int e : x)
    {
        cout << e << endl;
    }
}