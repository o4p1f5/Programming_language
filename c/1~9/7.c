#include <stdio.h>
#pragma warning (disable : 4996)

////1
//int LeapYear(int y) // 윤년인지 판단하기 위한 함수 정의
//{
//	if (y % 4 == 0) // 변수 y를 식대로 계산했을 때 윤년인지 판단하는 조건문
//	{
//		if (y % 100 == 0) // 참으로 나왔을 시 변수 y를 식대로 계산했을 때 윤년인지 판단하는 조건문
//		{
//			if (y % 400 == 0) // 참으로 나왔을 시 변수 y를 식대로 계산했을 때 윤년인지 판단하는 조건문
//			{
//				return 1; // 참이면 윤년으로 판단하고 함수를 호출할 때 1을 출력
//			}
//			else // 거짓이라면
//			{
//				return 0; // 평년으로 판단하고 함수를 호출할 때 0 출력
//			}
//		}
//		else // 변수 y를 100을 나눈 나머지가 0이 아니라면 윤년으로 판단
//		{
//			return 1; // 함수를 호출할 때 1 출력
//		}
//	}
//	else // 변수 y를 4로 나눈 나머지가 0이 아니라면 평년으로 판단
//	{
//		return 0; // 함수를 호출할 때 0 출력
//	}
//}
//int main() // 메인함수 선언
//{
//	int year = 0; // 정수형 변수 year 선언
//	printf("년 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
//	scanf("%d", &year); // 입력된 값을 변수year에 저장
//	if (LeapYear(year) == 0) // LeapYear함수에 변수 year를 대입했을 때 출력되는 값이 0이라면 참
//		printf("%d 년은 평년\n", year); // printf함수를 이용해 %d에 입력받았던 변수 year의 값을 대입 후 콘솔창에 출력
//	else //  LeapYear함수에 변수 year를 대입했을 때 출력되는 값이 1이라면 거짓으로 판단
//		printf("%d 년은 윤년\n", year); // printf함수를 이용해 %d에 입력받았던 변수 year의 값을 대입 후 콘솔창에 출력
//	return 0; // 메인함수의 종료를 알림
//}

////2
//int main() // 메인함수 선언
//{
//	int n1 = 0, n2 = 0, n3 = 0; // 정수형 변수 n1,n2.n3 선언
//	printf("세 정수 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
//	scanf("%d %d %d", &n1, &n2, &n3); // 입력받은 세 수를 차례대로 변수에 저장
//
//	if (n1 > n2) // n1의 값이 n2보다 큰 값인지 판단
//	{
//		if (n1 > n3) // 참이라면 n1의 값이 n3보다 큰 값인지 판단
//			printf("정수 %d, %d, %d 중 가장 큰 수는 %d", n1, n2, n3, n1); // 크다면 printf함수를 이용해 %d에 변수의 값을 차례대로 넣은 후 콘솔창에 띄움
//		else // n1 이 n3보다 작다면 거짓으로 판단
//			printf("정수 %d, %d, %d 중 가장 큰 수는 %d", n1, n2, n3, n3); // printf함수를 이용해 %d에 변수의 값을 차례대로 넣은 후 콘솔창에 띄움
//	}
//	else // n1의 값이 n2보다 작다면 거짓으로 판단
//	{
//		if (n2 > n3) // n2의 값이 n3보다 큰 값인지 판단
//			printf("정수 %d, %d, %d 중 가장 큰 수는 %d", n1, n2, n3, n2); // 크다면 printf함수를 이용해 %d에 변수의 값을 차례대로 넣은 후 콘솔창에 띄움
//		else // n2의 값이 n3보다 작다면 거짓으로 판단
//			printf("정수 %d, %d, %d 중 가장 큰 수는 %d", n1, n2, n3, n3); // printf함수를 이용해 %d에 변수의 값을 차례대로 넣은 후 콘솔창에 띄움
//	}
//	return 0; // 메인함수 종료
//
//}

////3
//int FindLastDay(int n) // 월을 입력받아 마지막 일을 구해주는 함수 선언
//{
//	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12) // 입력받은 월이 1,3,5,7,8,10,12월 중 하나라면
//	{ 
//		return 31; // 마지막 일을 31일로 판단해서 함수를 호출할 때 31을 출력
//	}
//	else if (n == 4 || n == 6 || n == 9 || n == 11) // 그게 아니라 입력받은 월이 4,6,9,11월 중 하나라면
//	{
//		return 30; // 마지막 일을 30일로 판단해서 함수를 호출할 때 30을 출력
//	}
//	else // 위에 제시된 월이 아니라면
//		return 28; // 마지막 일을 28일로 판단해서 함수를 호출할 때 28을 출력
//
//}
//int main() // 메인함수 선언
//{
//	int n = 0; // 정수형 변수 n 선언
//	printf("월 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
//	scanf("%d", &n); // scanf를 이용해 입력받은 수를 변수 n에 저장
//
//	printf("%d월의 마지막 일은 %d", n,FindLastDay(n)); // printf함수를 이용해 %d에 차례로 변수 n과 FindLastDay함수에 n을 대입해 계산 후 나온 값을 대입한다. 
//
//	return 0; // 메인함수의 종료
//}

////4
//int DayOfWeek(int Y, int M, int D) // 년 월 일을 이용해 그날의 요일을 구하는 함수 선언
//{ 
//	int YA = Y / 100; // 변수 YA에 변수 Y를 100을 나눈 값을 대입
//	int YB = Y % 100; // 변수 YA에 변수 Y를 100으로 나눴을 때 나오는 나머지 값을 대입
//	int H = (D + ((13 * (M + 1)) / 5) + YB + (YB / 4) + (YA / 4) - 2 * YA) % 7; // 독일 첼러 합동식에 주어진 변수들을 이용해 계산했을 때 나오는 값을 변수 H에 대입 
//	
//	return H; // 함수를 호출할 때 변수 H값을 출력
//}
//
//int main() // 메인함수 선언
//{
//	int Y = 0, M = 0, D = 0; // 정수형 변수 Y,M,D 선언
//	printf("년 월 일 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
//	scanf("%d %d %d", &Y, &M, &D); // scanf함수를 이용해 입력받은 세 수를 차례대로 변수에 저장
//	int H = DayOfWeek(Y, M, D); // DayOfWeek함수에 변수 Y,M,D를 대입했을 때 나오는 값을 정수형 변수 H에 대입
//	if (H == 0) // 변수 H의 값이 0과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 토요일",Y,M,D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else if (H == 1) // 거짓이라면 변수 H의 값이 1과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 일요일", Y, M, D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else if (H == 2) // 거짓이라면 변수 H의 값이 2과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 월요일", Y, M, D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else if (H == 3) // 거짓이라면 변수 H의 값이 3과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 화요일", Y, M, D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else if (H == 4) // 거짓이라면 변수 H의 값이 4과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 수요일", Y, M, D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else if (H == 5) // 거짓이라면 변수 H의 값이 5과 같은지 판단
//		printf("%d 년 %d 월 %d 일은 목요일", Y, M, D); // 참이라면 printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	else // 전부 거짓이라면
//		printf("%d 년 %d 월 %d 일은 금요일", Y, M, D); // printf함수를 이용해 %d에 변수를 차례대로 대입 후 출력
//	
//	return 0; // 메인함수 종료
//}

//5
double BMI(double kg, double m) // 비만지수를 구하는 함수 선언
{
	double bmi = kg / (m * m); // 변수 kg,m을 이용한 식의 계산값을 실수형 변수 bmi에 저장

	return bmi; // 함수를 호출할 때 변수 bmi의 값을 출력
}

int main() // 메인함수 선언
{
	double kg = 0, m = 0; // 실수형 변수 kg,m 선언

	printf("몸무게(kg) 키(m) 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
	scanf("%lf %lf",&kg,&m); // 입력받은 두 수를 scanf함수를 이용해 차례대로 변수 kg,m에 저장

	double bmi = BMI(kg, m); // BMI함수에 변수 kg,m를 대입해서 얻은 값을 변수bmi에 저장

	if (bmi < 20) // bmi의 값이 20 미만인지 판단
		printf("저체중"); // 참이라면 콘솔창에 "저체중" 띄움
	else if (bmi >= 20 && bmi < 25) // 거짓이라면 bmi의 값이 20 이상 25 미만인지 판단
	    printf("정상"); // 참이라면 콘솔창에 "정상" 띄움
	else if (bmi >= 25 && bmi < 30) // 거짓이라면 bmi의 값이 25 이상 30 미만인지 판단
		printf("비만"); // 참이라면 콘솔창에 "비만" 띄움
	else if (bmi >= 30 && bmi < 40) // 거짓이라면 bmi의 값이 30 이상 40 미만인지 판단
		printf("과비만"); // 참이라면 콘솔창에 "과비만" 띄움
	else // 전부 거짓이라면 
		printf("고도비만"); // 콘솔창에 "고도비만" 띄움

	return 0; //메인함수 종료 
}

////6
//int main() // 메인함수 선언
//{
//	int score = 0; // 정수형 변수 score 선언
//	printf("점수 입력 :"); // printf함수를 이용해 콘솔창에 글을 띄움
//	scanf("%d", &score); // 입력받은 수를 변수 score에 저장한다
//
//	if (score >= 95) // 점수가 95점 이상인지 판단
//		printf("학점 : A+\n"); // 참이라면 콘솔창에 "학점 : A+" 띄움
//	else if (score >= 90)// 점수가 90점 이상인지 판단
//		printf("학점 :A0\n"); // 참이라면 콘솔창에 "학점 : A0" 띄움
//	else if (score >= 85)// 점수가 85점 이상인지 판단
//		printf("학점 :B+\n"); // 참이라면 콘솔창에 "학점 : B+" 띄움
//	else if (score >= 80)// 점수가 80점 이상인지 판단
//		printf("학점 :B0\n"); // 참이라면 콘솔창에 "학점 : B0" 띄움
//	else if (score >= 75)// 점수가 75점 이상인지 판단
//		printf("학점 :C+\n"); // 참이라면 콘솔창에 "학점 : C+" 띄움
//	else if (score >= 70)// 점수가 70점 이상인지 판단
//		printf("학점 :C0\n"); // 참이라면 콘솔창에 "학점 : C0" 띄움
//	else if (score >= 65)// 점수가 65점 이상인지 판단
//		printf("학점 :D+\n"); // 참이라면 콘솔창에 "학점 : D+" 띄움
//	else if (score >= 60)// 점수가 60점 이상인지 판단
//		printf("학점 :D0\n"); // 참이라면 콘솔창에 "학점 : D0" 띄움
//	else // 다 거짓이라면
//		printf("학점 :F\n"); // 콘솔창에 "학점 : F" 띄움
//	
//	return 0; // 메인함수 종료
//}
//
////7
//int main() // 메인함수 선언
//{
//	int a = 0, b = 0, c = 0; // 정수형 변수 a,b,c 선언
//
//	printf("삼각형의 세 변 길이 입력 :"); // printf함수르 이용해 콘솔창에 글을 띄움
//	scanf("%d %d %d", &a, &b, &c); // 입력받은 수를 a,b,c에 차례로 저장
//
//	if (a + b < c || b + c < a || a + c < b) // 두 변의 길이 합이 한 변의 길이보다 작은지 판단
//		printf("삼각형 아님"); // 참이라면 콘솔창에 "삼각형 아님" 띄움
//	else if (a == b && a == c && b ==c) // 거짓이라면 세변의 길이가 모두 같은 지 판단
//		printf("정삼각형"); // 참이라면  콘솔창에 "정삼각형" 띄움
//	else if (a == b || a == c || b == c) // 거짓이라면 두 변의 길이가 같은 지 판단
//		printf("이등변삼각형"); // 참이라면 콘솔창에 "이등변삼각형" 띄움
//	else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) // 거짓이라면 두변의 제곱의 합이 한 변의 제곱값과 같은지 판단
//		printf("직각삼각형"); // 참이라면 콘솔창에 "직각삼각형" 띄움
//	else // 다 거짓이라면
//		printf("일반삼각형"); // 콘솔창에 "일반삼각형" 띄움
//
//	return 0; // 메인함수 종료
//}
