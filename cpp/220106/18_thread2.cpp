#include <iostream>
// #include <thread> // c++11
#include <pthread.h>
using namespace std;

// 스레드 특성
// 1) pthread_create : 스레드를 생성하고 스레드가 만들어져서 시작할 함수를 지정
// 2) 스레드는 자신만의 스택을 가지고 있다
// 3) 모든 스레드는 같은 프로세스 내에서 동작, 데이터를 쉽게 공유가능
// 4) 프로세스가 처음 만들어졌을 때, main 함수를 실행하는 흐름을 "메인 스레드" 라 함
// 5) 메인 함수가 반환하면 프로세스 종료, 메인함수의 반환은 프로세스의 모든 스레드 종료
// 6) pthread_join 함수를 통해 스레드종료까지 대기
// 7) 두 개 이상의 스레드가 sum이라는 메모리에 연산을 동시에 수행할 경우, 레이스 컨디션 발생
//    -> sum에 +1을 하는 연산은 원자적이지 않음 = 쪼개지지않음
//    => 연산 중 누락이 발생 -> 동기화시켜줌 : 두 개의 스레드가 하나의 연산에 동시에 접근하기않게 해줌

int sum = 0;

// 7) 상호 배제
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

// lock이 할 때마다 걸려 성능이 좋지않은 코드
/*
void* thread_routine(void *arg) 
{
    printf("%s\n", (char*)arg);
    for (int i = 0; i < 1000000; ++i) 
    {
        pthread_mutex_lock(&g_mutex);
        sum += 1; // 7) 임계영역 : 오직 하나의 스레드만 접근가능하도록 해줘야함
                  //             -> 상호 배제 : Mutex
        pthread_mutex_unlock(&g_mutex);
    }
    return nullptr;
}
*/

// 이를 보완한 코드
void* thread_routine(void *arg) 
{
    printf("%s\n", (char*)arg);
    int local = 0;
    for (int i = 0; i < 1000000; ++i) 
    {
        local += 1;
    }
    pthread_mutex_lock(&g_mutex);
    sum += local;
    pthread_mutex_unlock(&g_mutex);
    
    return nullptr;
}

// 프로세스가 처음 만들어졌을 때, main 함수를 실행하는 흐름을 "메인 스레드" 라 함
int main()
{
    cout << "main thread start" << endl;
    pthread_t thread[2]; // 스레드의 핸들 // pthread_create를 다루기 위한 선언
    for(int i=0;i<2;++i)
    {
        const char* arg = i==0 ? "A" : "B";
        pthread_create(&thread[i], nullptr, &thread_routine, (void*)arg)/* arg에 전달 */;
    }

    // getchar(); // 메인함수의 반환 방지
    // 6)
    for(int i=0;i<2;++i)
    {
        pthread_join(thread[i], nullptr);
    }

    printf("sum : %d\n", sum); // sum이 제대로 나오지 않는 이유 7)
}