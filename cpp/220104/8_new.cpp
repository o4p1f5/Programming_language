#include <iostream>
using namespace std;

int g[1000000] = {1,2,3}; // 전역변수 -> 실행파일용량 너무 많이 든다.
                          // 함수가 전역변수에 의존할 경우, 함수의 재사용성이 떨어진다.
int add(int a, int b)
{
    return a+b;
}
void foo()
{
    int a; // 지역변수 -> 해당 함수 안에서만 유효 : 메모리 할당 해지의 비용이 없다.
    static int b; // 내부 정적 변수 -> 전역 변수와 동일한 영역에 할당
    // 해당함수가 실행되면 생성, 프로그램 종료될 때 사라짐
}
/*
int main()
{
    char str[] = "hello world show me the money"
    for(char*p = strtok(str, " "); p != NULL; p = strtook(NULL, " "))
    {
        printf("%s/n",p); // 더이상 걸러낸 토큰이 없으면 NULL 출력하고 끝남
    }
}
*/

// 동적 메모리 할당
// 힙에 할당, 개발자가 수명을 정함
// 메모리누수의 위험, 성능 오버헤드가 있음

int main()
{
    int *p = static_cast<int *>(malloc(sizeof(int))); // malloc 함수
    // malloc은 메모리 크기를 인자로 전달  // 캐스팅 필요
    *p = 20;
    cout << *p << endl;

    free(p);

    int *p1 = new int; // new 연산자 이용 // 메모리크기를 타입으로 전달
    // 전달받은 타입의 주소를 반환하기 때문에 별도의 캐스팅이 필요하지 않다

    delete p1; // delete 연산자 이용 // free와 동일한 기능

    int* arr = static_cast<int *>(malloc(sizeof(int) * 5));
    arr[0] =10;
    cout << arr[0] << endl;
    free(arr);
    
    arr = new int[5];
    delete[] arr;
}

