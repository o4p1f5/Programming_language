#include <stdio.h>
using namespace std;

struct AAA
{
    int a; // 4
    char b; // 1
    double c; // b 뒤에 3byte 비우고(패딩) 8
    // => 패딩이 생기는 이유 : 메모리를 4byte씩 끊어읽어서
};

struct BBB
{
    char a; 
    double b;
    int c;
    __attribute__((aligned(1),packed));
};

int main()
{
    printf("%ld\n", sizeof(struct AAA));
    printf("%ld\n", sizeof(struct BBB));
}