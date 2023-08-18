#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

////1
//int main() // 메인 함수 시작
//{
//	int num = 0; // 정수형 변수 num 선언
//	printf("천단위 정수 입력 :"); // printf함수를 이용해 콘솔창에 글 띄움
//	scanf("%d", &num); // scanf함수를 통해 입력된 수를 변수에 저장
//	int thous = num / 1000; // 정수형 변수 thous를 선언하면서 변수 num을 사용한 수식계산값을 대입
//	int a = num % 1000; // 정수형 변수 a를 선언하면서 변수 num을 사용한 수식계산값을 대입
//	int hund = a / 100; // 정수형 변수 hund를 선언하면서 변수 a를 사용한 수식계산값을 대입
//	int b = a % 100; // 정수형 변수 b를 선언하면서 변수 a를 사용한 수식계산값을 대입
//	int ten = b / 10; // 정수형 변수 ten을 선언하면서 변수 b를 사용한 수식계산값을 대입
//	int c = b % 10; // 정수형 변수 c를 선언하면서 변수 b를 사용한 수식계산값을 대입
//	int one = c / 1; // 정수형 변수 one을 선언하면서 변수 c를 사용한 수식계산값을 대입
//
//	printf("%d는 %d천 %d백 %d십 %d 입니다.", num, thous, hund, ten, one); // printf함수를 이용해 콘솔창에 글을 띄움, %d에 변수를 차례로 참조
//
//	return 0; // 메인 함수 종료
//}

////2
//int main() // 메인 함수의 시작
//{
//	int sec = 0; // 정수형 변수 sec 선언
//	printf("초를 입력 :"); // printf함수를 이용해 콘솔창에 글 띄움
//	scanf("%d", &sec); // scanf함수를 통해 입력된 수를 변수에 저장
//	int h = sec / 3600; // 정수형 변수 h를 선언하면서 변수 sec를 사용한 수식계산값을 대입
//	int a = sec % 3600; // 정수형 변수 a를 선언하면서 변수 sec를 사용한 수식계산값을 대입
//	int m = a / 60; // 정수형 변수 m를 선언하면서 변수 a를 사용한 수식계산값을 대입
//	int s =  a % 60; // 정수형 변수 s를 선언하면서 변수 a를 사용한 수식계산값을 대입
//	
//	printf("%d초는 %d 시간 %d 분 %d 초입니다.", sec, h, m, s); // printf함수를 이용해 콘솔창에 글을 띄움, %d에 변수를 차례로 참조
//	return 0; //메인 함수 종료
//
//}

////3
//int main() // 메인 함수의 시작을 알림
//{
//	double a = 0, b = 0, c = 0; // 실수형 변수 a,b,c를 선언
//	printf("삼각형의 세변의 길이 입력 :"); // printf함수를 이용해 콘솔창에 글 띄움
//	scanf("%lf %lf %lf", &a, &b, &c); // scanf함수를 통해 입력된 수를 차례로 변수에 저장
//	double s = (a + b + c) / 2; // 실수형 변수 s를 선언하면서 a,b,c를 이용한 수식계산값을 대입
//	double S = sqrt(s * (s - a) * (s - b) * (s - c)); // 실수형 변수 S를 선언하면서 s,a,b,c를 이용한 수식계산값을 대입
//
//	printf("세변의 길이 %.2lf, %.2lf, %.2lf의 넓이 : %.4lf", a, b, c, S); // printf함수를 이용해 콘솔창에 글을 띄움, %.2lf에 변수를 차례로 참조
//
//	return 0; // 메인 함수의 종료
//}
//
////4
//int main() // 메인 함수 입력
//{
//	double a = 0, b = 0, c = 0; // 실수형 변수 a,b,c 선언
//	printf("2차 방정식의 a b c 계수 입력 :"); // printf함수를 이용해 콘솔창에 글 띄움
//	scanf("%lf %lf %lf", &a, &b, &c); // scanf함수를 통해 입력된 수를 차례로 변수에 저장
//	double X1 = (-b + sqrt((b * b) - 4 * a * c)) / 2 * a; // 실수형 변수 X1를 선언하면서 변수 a,b,c를 이용한 수식계산값을 대입
//	double X2 = (-b - sqrt((b * b) - 4 * a * c)) / 2 * a; // 실수형 변수 X2를 선언하면서 변수 a,b,c를 이용한 수식계산값을 대입
//
//	printf("X1 = %.2lf   X2 = %.2lf", X1, X2); // printf함수를 이용해 콘솔창에 글을 띄움, %.2lf에 변수를 차례로 참조
//
//	return 0; // 메인 함수 종료
//}

5
int main() // 메인 함수 입력
{
	int num = 0; // 정수형 변수 num 선언
  printf("거스름돈 입력 :"); // printf함수를 이용해 콘솔창에 글 띄움
	scanf("%d", &num); // scanf함수를 통해 변수 num에 입력된 정수 저장
  int thous = num / 1000; // 정수형 변수 thous를 선언하면서 변수 num을 이용한 수식계산값을 대입 
	int a = num % 1000; // 정수형 변수 a를 선언하면서 변수 num을 이용한 수식계산값을 대입
	int fivehund = a / 500; // 정수형 변수 fivehund를 선언하면서 변수 a를 이용한 수식계산값을 대입
	int b = a % 500; // 정수형 변수 b를 선언하면서 변수 a를 이용한 수식계산값을 대입
	int hund = b / 100; // 정수형 변수 hund를 선언하면서 변수 b를 이용한 수식계산값을 대입
	int c = b % 100; // 정수형 변수 c를 선언하면서 변수 b를 이용한 수식계산값을 대입
	int one = c / 1; // 정수형 변수 one를 선언하면서 변수 c를 이용한 수식계산값을 대입
	
	printf("거스름돈 %d를 위한 화폐의 개수\n\t1000원 : %d\n", num, thous); // printf함수를 사용해 콘솔창에 글을 뜨게함. %d에 변수를 차례로 참조
	printf("\t 500원 : %d\n", fivehund); // printf함수를 사용해 콘솔창에 글을 뜨게함. %d에 변수를 참조
	printf("\t 100원 : %d\n", hund); //printf함수를 사용해 콘솔창에 글을 뜨게함. %d에 변수를 참조
	printf("\t   1원 : %d\n", one); //printf함수를 사용해 콘솔창에 글을 뜨게함. %d에 변수를 참조

	return 0; //메인함수의 끝을 알림.
}
