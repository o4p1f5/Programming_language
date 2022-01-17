#include <stdio.h> // 표준입출력 헤더
#include <math.h>  // 수학 관련 표준라이브러리 
#pragma warning (disable:4996) //scanf_s 신경 X

// 간접참조
// 포인터 변수의 사용

////1
//int main()
//{
//	int a = 0; // 변수 a선언
//	int b = 0; // 변수 b선언
//	int* p1 = &a; // a의 주소를 받을 포인터 변수 p1 선언
//	int* p2 = &b; // b의 주소를 받을 포인터 변수 p2 선언
//
//	printf("정수 두개 입력 :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%d %d", p1, p2); // 입력된 정수를 차례로 변수 a,b(p1,p2는 a,b의 주소를 가리킴)에 저장
//
//	printf("%d + %d = %d \n", *p1, *p2, *p1 + *p2); // *p1은 a를 가리키고 *p2는 b를 가리킴
//
//	printf("%d - %d = %d \n", *p1, *p2, *p1 - *p2); // *p1은 p1에 저장된 주소값을 갖는 변수에 저장된 값을 말한다.
//
//	printf("%d X %d = %d \n", *p1, *p2, *p1 * *p2); // 마찬가지로 *p2도 p2에 저장된 주소가 가르키는 b의 값을 말한다. 
//
//	return 0; // main 함수의 종료를 알림
//}

////2
//int main()
//{
//	double C = 0, F = 0; // 실수형 변수 C,F 선언
//	double* p1 = &C; // C의 주소값을 받는 포인터변수 p1 선언
//	double* p2 = &F; // F의 주소값을 받는 포인터변수 p2 선언
//
//	printf("화씨 온도 입력 :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", p2); // 입력된 수를 F(p2는 F의 주소를 가리킴)에 저장
//
//	*p1 = (5.0 / 9.0) * (*p2 - 32.0); // 대입 연산자를 이용해 화씨온도를 섭씨온도로 변화하는 식의 값을 *p1이 가르키는 C에 저장
//
//	printf("화씨 온도 %.0lf는 섭씨 온도 %lf 이다.\n", *p2, *p1); // 큰 따옴표 속 %lf 포인터변수 *p2,*p1이 가리키는 변수에 저장된 값을 차례로 대입 후 출력
//	return 0; // main 함수의 종료를 알림
//}

////3
//int main()
//{
//	double cm = 0, inch = 0; // 실수형 변수 cm,inch 선언
//	double* p1 = &cm; // cm의 주소를 받을 포인터변수 p1 선언
//	double* p2 = &inch; // inch의 주소를 받을 포인터변수 p2 선언
//	 
//	printf("길이 입력(cm) :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", p1); // 입력된 수를 변수 cm(p1은 cm의 주소를 가리킴)에 저장
//
//	*p2 = *p1 / 2.54; // 대입연산자를 이용해 cm를 inch로 환산하는 식의 값을 *p2가 가리키는inch에 저장
//	printf("%lf Cm는 %lf Inch \n", *p1, *p2); // 큰 따옴표 속 %lf 변수 *p1이 가리키는 cm와 *p2가 가리키는 inch에 저장된 값을 차례로 대입 후 출력
//
//	printf("길이 입력(inch) :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", p2); // 입력된 수를 변수 inch(p2는 inch의 주소를 가리킴)에 저장
//
//	*p1 = *p2 * 2.54; // 대입연산자를 이용해 inch를 cm로 환산하는 식의 값을 *p1이 가리키는 cm에 저장
//	printf("%lf Inch는 %lf Cm", *p2, *p1); // 큰 따옴표 속 %lf 변수 *p2가 가리키는 inch와 *p1이 가리키는 cm에 저장된 값을 차례로 대입 후 출력
//
//	return 0; // main 함수의 종료를 알림
//}

////4
//int main()
//{
//	double l = 0, r = 0, pi = 3.141592; // 실수형 변수 l, r, pi선언
//	double* pl = &l; // ㅣ의 주소를 저장하는 포인터변수 pl 선언
//	double* pr = &r; // r의 주소를 저장하는 포인터변수 pr 선언
//	double* ppi = &pi; // pi의 주소를 저장하는 포인터변수 ppi 선언
//
//	printf("원의 반지름 입력 : "); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf이용 
//	scanf("%lf", pr); // 콘솔창에 적힌 수를 변수 r(pr은 r의 주소를 가리킴)에 저장
//
//	*pl = 2.0 * *ppi * *pr; // 변수 *pl이 가리키는 l에 *ppi가 가리키는 pi와 *pr이 가리키는 r을 이용한 수식의 계산값을 저장
//	printf("반지름 %lf 원의 둘레 : %lf\n", *pr, *pl); // 큰 따옴표 속 두 개의 %lf에 변수를 차례대로 참조 후 콘솔창에 띄움(*pr은 r을 가리키고 *pl은 l을 가리킨다.)
//
//	double area = *ppi * *pr * *pr; // 실수형 변수 area를 선언 (수식이 변수 area에 저장)
//	double* pa = &area; // area의 주소를 저장할 포인터변수 pa 선언
//
//	printf("반지름 %lf 원의 면적 : %lf\n", *pr, *pa); // 큰 따옴표 속 두 개의 %lf에 변수를 차례대로 참조 후 콘솔창에 띄움(*pr은 r을 가리키고 *pa는 area를 가리킨다.)
//
//	return 0; // main 함수의 종료를 알림
//}

//5
int main() 
{
	double pi = 3.141592, r = 0; // 실수형 변수 pi, r 선언
	double* ppi = &pi; // pi의 주소를 저장할 포인터변수 ppi 선언
	double* pr = &r; // r의 주소를 저장할 포인터변수 pr 선언

	printf("구의 반지름 입력 : "); // 콘솔창에 큰 따옴표 속 말을 띄우기 위해 printf 사용
	scanf("%lf", pr); // 콘솔창에 입력된 수를 변수 r(pr은 r의 주소를 가리킴)에 저장 

	double V = (4.0 / 3.0) * *ppi * *pr * *pr * *pr; // 실수형 변수 V 선언 (수식은 변수 안에 저장)
	double* pv = &V; // V의 주소를 저장할 포인터변수 pv 선언
	printf("반지름 %lf 구의 체적 : %lf\n", *pr, *pv); // 큰 따옴표 속 두 개의 %lf에 변수를 차례대로 참조 후 콘솔창에 띄움(*pr은 r을 가리키고 *pv는 V를 가리킨다.)

	double S = 4.0 * *ppi * *pr * *pr; // 실수형 변수 S 선언 (수식은 변수 안에 저장)
	double* ps = &S; // S의 주소를 저장할 포인터변수 ps 선언
	printf("반지름 %lf 구의 표면적 : %lf\n", *pr, *ps); // 큰 따옴표 속 두 개의 %lf에 변수를 차례대로 참조 후 콘솔창에 띄움(*pr은 r을 가리키고 *ps는 S를 가리킨다.)

	return 0; // 메인함수의 종료 알림
}
