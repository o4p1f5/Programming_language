/*
마이크로프로세서에서 잘쓰는 전처리기
#define F_CPU 16000000L
#include <abr/io.h>
#include <avr/delay.h>
*/

// xxx.h // 헤더 // 함수 선언
// xxx.c // #include "xxx.h" // 함수 정의
// main문에서 // 함수 호출

/*
c언어라서
초기화 -> 데이터처리 순으로 작성

정수형 출력 : %d
4바이트 정수형 : int
1바이트 정수형 : unsigned char : 0 ~ 255

실수형 출력 : %f
4바이트 실수형 : float
8바이트 실수형 : double

문자 출력 : %c
문자열 출력 : %s

연산시 자료형 

char 배열 : 크기는 원하는 수 + 1 : 마지막에 '\0' 자동으로 붙음

자료형 출력 %와 나머지연산자 %를 함께 사용해야하는경우, 
나머지연산자를 %%로 사용

while문 많이 씀 

%- : 왼쪽정렬
%(숫자) : 숫자만큼 자리 차지
%(숫자) : 숫자만큼 자리 차지 : 빈곳은 0으로 채워짐
*/

/*
for문 활용
ex) 217을 2진수로 변환
원리 : 217 = 0xd9 = 0b11011001
        : 217 % 2 = 1
        : (217 / 2) % 2 = 108 % 2 = 0b1101100 % 2 = 0
        : (217 / 4) % 2 = 54 % 2 = 0b110110 % 2 = 0
        : (217 / 8) % 2 = 27 % 2 = 0b11011 % 2 = 1
        : (217 / 16) % 2 = 13 % 2 = 0b1101 % 2 = 1
        : (217 / 32) % 2 = 6 % 2 = 0b110 % 2 = 0
        : (217 / 64) % 2 = 3 % 2 = 0b11 % 2 = 1
        : (217 / 128) % 2 = 1 % 2 = 0b1 % 2 = 1

코드 1 :
int main() 
{
char binary[9]; // 변환된 이진수값을 받을 문자열
int div = 1; // 배수표시
int num = 217; // 변환될 정수
for(int i = 0; i <8; i++)
{
     int residue = (int)(num / div) % 2; // (217 / n) % 2 식
     if (residue == 1) 
          binary[7-i] = '1';
     else
          binary[7-i] = '0';
     div *= 2;
}
binary[8] = NULL ; // 문자 배열의 8번째 인덱스에 NULL 입력 // string end 
// + 인덱스는 0부터 시작
printf( " %3d : = 0x%02x = 0b%s\n", num, num, binary);
// 정수의 16진수는 %x로 출력 // 2진수는 위의 계산값을 담은 배열을 출력

return 0;
}

코드 2 : 간단하게 변경
int main() 
{
char binary[9]; // 변환된 이진수값을 받을 문자열
int div = 1; // 배수표시
int num = 217; // 변환될 정수
for(int i = 0; i <8; i++)
{
     binary[7-i] = ((num / div) % 2) ? '1' : '0' ;
     div *= 2;
}
binary[8] = NULL ; // 문자 배열의 8번째 인덱스에 NULL 입력 // string end 
// + 인덱스는 0부터 시작
printf( " %3d : = 0x%02x = 0b%s\n", num, num, binary);
// 정수의 16진수는 %x로 출력 // 2진수는 위의 계산값을 담은 배열을 출력

return 0;
}

코드 3 : 더 간단하게 변경
int main() 
{
char binary[9]; // 변환된 이진수값을 받을 문자열
int num = 217; // 변환될 정수
for(int i = 0; i <8; i++)
{
     binary[7-i] = ((num / ( 1 << i )) % 2) ? '1' : '0' ; 
     // 시프트 연산자로 더욱 간단히 정리
}
binary[8] = NULL ; // 문자 배열의 8번째 인덱스에 NULL 입력 // string end 
// + 인덱스는 0부터 시작
printf( " %3d : = 0x%02x = 0b%s\n", num, num, binary);
// 정수의 16진수는 %x로 출력 // 2진수는 위의 계산값을 담은 배열을 출력

return 0;
}
*/

// 코드 4 :  훨씬 더 간단하게 변경
int main() 
{
char binary[9]; // 변환된 이진수값을 받을 문자열
int num = 217; // 변환될 정수
for(int i = 0; i <8; i++)
{
     binary[7-i] = (num & ( 1 << i )) ? '1' : '0' ; 
     // 비트연산자와 시프트 연산자로 더욱 간단히 정리
}
binary[8] = NULL ; // 문자 배열의 8번째 인덱스에 NULL 입력 // string end 
// + 인덱스는 0부터 시작
printf( " %3d : = 0x%02x = 0b%s\n", num, num, binary);
// 정수의 16진수는 %x로 출력 // 2진수는 위의 계산값을 담은 배열을 출력

return 0;
}

/* switch - case - defult */
/*
비트 쓰는 방식
0bXXXXXXXX
ex) 0b10111101

비트연산자(많이 다룸)
& : AND
| : OR
^ : XOR
~ : NOT : 1의 보수 취해주기
<< : 비트왼쪽으로 이동, 오른쪽 0 채움
>> : 비트오른쪽으로 이동, 왼쪽 0 채움
*/

/*
a++ 보다는 ++a이 더 유용
*/

/*
세트 : 바이트 내 특정 위치의 비트를 1로 설정
-> OR 연산 사용 : 특정 위치에 1로 OR 해주면 1로 무조건 바뀌기때문

ex) 원하는 위치의 LED 켜기
PA0 - LED0
PA1 - LED1
PA2 - LED2
PA3 - LED3
PA4 - LED4
PA5 - LED5
PA6 - LED6
PA7 - LED7

// PORTA = PORTA | 0x00000100; // 포트 A의 2번 위치가 무조건 1로 변하고 이를
                                                       // 포트 A에 다시 저장
// 0X00000001 << 2 = 0x00000100 이기 때문에 몇번 위치를 변경한 것인지 쉽게
PORTA = PORTA | (1 << 2);

클리어 : 바이트 내 특정 위치의 비트를 0으로 설정
-> AND 연산 사용 : 특정 위치에 0로 AND 해주면 0으로 무조건 바뀌기때문

ex) 원하는 위치의 LED 끄기
PA0 - LED0
PA1 - LED1
PA2 - LED2
PA3 - LED3
PA4 - LED4
PA5 - LED5
PA6 - LED6
PA7 - LED7

// PORTA = PORTA & 0x11111011; // 포트 A의 2번 위치가 무조건 0로 변하고 이를
                                                         // 포트 A에 다시 저장
// ~(0X00000001 << 2) = 0x11111011 이기 때문에 몇번 위치를 변경한 것인지 쉽게
 PORTA = PORTA & ~ (1 << 2);

반전  : 바이트 내 특정 위치의 비트를 0과 1로 반전
-> XOR 사용( x ^ 0 = x , x ^ 1 = ~x) : 특정 위치에 1로 XOR 해주면 그 수는 반전됨

ex) 원하는 위치의 반전
PA0 - LED0
PA1 - LED1
PA2 - LED2
PA3 - LED3
PA4 - LED4
PA5 - LED5
PA6 - LED6
PA7 - LED7

// PORTA = PORTA ^ 0x00000100; // 포트 A의 2번 위치가 반전                                                       
                                                       // 이를 포트 A에 다시 저장
// 0X00000001 << 2 = 0x00000100 이기 때문에 몇번 위치를 변경한 것인지 쉽게
PORTA = PORTA ^ (1 << 2);

검사 / 읽기 : 바이트 내 특정 위치의 비트값을 읽음
-> AND 연산 사용 : 특정 위치에 1로 AND 해주면 그 값이 나오기때문에 읽기가능

ex) 기본 예시
if ((REG & 0x20) == 0x20) // REG & 0x20 하면 그 값이 2의 배수로 나옴
{
     // 비트가 1인 경우
}
else
{
     // 비트가 0인 경우
}

ex) 이진수로 바꿔주는 예시
if ((REG & 0x20 >> 5) == 1) // 2의 배수값을 시프트해줘 1 또는 0으로 바꿔줌
{
     // 비트가 1인 경우
}
else
{
     // 비트가 0인 경우
}

ex) 가장 직관적인 예시
if (((REG >> 5) & 0x01 == 1) // 검사하고싶은 위치의 비트를 1번자리로 옮겨 검사
// 원하는 비트의 위치를 5가 써있는 곳을 변경해서 알려줌
{
     // 비트가 1인 경우
}
else
{
     // 비트가 0인 경우
}
*/

/*
Online C Compiler : 따로 다운받지않고 사용할 수 있는 c언어 검사프로그램
: 기본기능확인
*/
