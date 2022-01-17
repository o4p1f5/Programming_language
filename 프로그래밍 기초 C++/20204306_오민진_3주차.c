 #include <stdio.h> // 표준입출력 헤더
#include <math.h>  // 수학 관련 표준라이브러리 
#pragma warning (disable:4996) //scanf_s 신경 X

////1
//int main()
//{
//	int a = 0, b = 0, c = 0; // 정수형 변수 a,b,c 선언
//	printf("정수 두개 입력 :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%d %d", &a, &b); // 입력된 정수를 차례로 변수 a,b에 저장
//
//	c = a + b; // 대입 연산자를 이용해 a+b의 값을 c에 저장
//	printf("%d + %d = %d \n", a, b, c); // 큰 따옴표 속 %d에 변수a, b, c에 저장된 값을 차례로 대입 후 출력
//
//	printf("%d - %d = %d \n", a, b, a - b); // 큰 따옴표 속 %d에 변수a, b에 저장된 값과 a+b를 계산한 값을 차례로 대입 후 출력
//
//	printf("%d * %d = %d \n", a, b, a * b); // 큰 따옴표 속 %d에 변수a, b에 저장된 값과 a*b를 계산한 값을 차례로 대입 후 출력
//
//	return 0; // main 함수의 종료를 알림
//}


////2
//int main()
//{
//	double C = 0, F = 0; // 실수형 변수 C,F 선언
//
//	printf(" 화씨 온도 입력 :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", &F); // 입력된 수를 변수 F에 저장
//
//	C = (5.0 / 9.0) * (F - 32.0); // 대입 연산자를 이용해 화씨온도를 섭씨온도로 변화하는 식의 값을 C에 저장
//
//	printf("화씨 온도 %lf는 섭씨 온도 %lf 이다.\n", F, C); // 큰 따옴표 속 %lf 변수 F,C에 저장된 값을 차례로 대입 후 출력
//	return 0; // main 함수의 종료를 알림
//}

////3
//int main()
//{
//	double cm = 0, inch = 0; // 실수형 변수 cm,inch 선언
//	printf("길이 입력(cm) :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", &cm); // 입력된 수를 변수 cm에 저장
//
//	inch = cm / 2.54; // 대입연산자를 이용해 cm을 inch로 환산하는 식의 값을 inch에 저장
//	printf("%lf Cm는 %lf Inch \n", cm, inch); // 큰 따옴표 속 %lf 변수 cm,inch에 저장된 값을 차례로 대입 후 출력
//
//	printf("길이 입력(inch) :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
//	scanf("%lf", &inch); // 입력된 수를 변수 inch에 저장
//
//	cm = inch * 2.54; // 대입연산자를 이용해 inch을 cm로 환산하는 식의 값을 cm에 저장
//	printf("%lf Inch는 %lf Cm", inch, cm); // 큰 따옴표 속 %lf 변수 inch,cm에 저장된 값을 차례로 대입 후 출력
//
//	return 0; // main 함수의 종료를 알림
//
//}

//4
int main()
{
	double a = 0, b = 0; // 실수형 변수 a,b 선언
	printf("직각 삼각형의 밑변과 높이를 입력 :"); // 콘솔창에 큰 따옴표 속 말이 뜰 수 있게 printf사용
	scanf("%lf %lf", &a, &b); // 입력된 수를 차례로 변수 a,b에 저장

	double c = sqrt(a * a + b * b); // 직각삼각형의 빗변을 구하는 식을 실수형 변수 c에 저장

	printf("밑변 %lf 높이 %lf의 직각 삼각형의 빗변은 %lf 입니다.", a, b, c); // 큰 따옴표 속 %lf에 변수a,b,c에 저장된 값을 차례로 대입 후 출력

	return 0; // main 함수의 종료를 알림

}