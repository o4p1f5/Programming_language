#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

// {} 범위를 나타내는 스코프 연산자 -> 안에 기능 구현
// return 뒤에 오는 숫자의 자료형에 맞춰서 main함수의 반환자료형(ex. int)이 정해짐 

////1
//int Add(int a,int b) // 정수형 변수 a,b의 더한 값을 구하는 함수
//{
//	int c = a + b; // 정수형 변수 c에 변수 a,b를 이용한 수식의 계산 값을 대입
//	return c; // 함수를 호출할때 변수 c의 값을 출력
//}
//
//int Sub(int a,int b) // 정수형 변수 a,b의 뺀 값을 구하는 함수
//{
//	int c = a - b; // 정수형 변수 c에 변수 a,b를 이용한 수식의 계산 값을 대입
//	return c; // 함수를 호출할때 변수 c의 값을 출력
//}
//
//int Mul(int a,int b) // 정수형 변수 a,b의 곱한 값을 구하는 함수
//{
//	int c = a * b; // 정수형 변수 c에 변수 a,b를 이용한 수식의 계산 값을 대입
//	return c; // 함수를 호출할때 변수 c의 값을 출력
//}
//
//int main() // 메인함수를 선언
//{
//	int a = 0, b = 0; // 정수형 변수 a,b 선언
//	printf("정수 두개 입력 :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//	scanf("%d %d", &a, &b); // scanf함수를 이용해 입력받은 정수를 변수 a,b에 순서대로 저장
//
//	printf("%d + %d = %d\n", a, b, Add(a, b)); // printf함수를 이용해 %d에 순서대로 a,b와 앞서 선언한 Add함수에 scanf를 통해 입력받은 a,b의 값을 대입해서 얻은 값을 대입한다.
//
//	printf("%d - %d = %d\n", a, b, Sub(a, b)); // printf함수를 이용해 %d에 순서대로 a,b와 앞서 선언한 Sub함수에 scanf를 통해 입력받은 a,b의 값을 대입해서 얻은 값을 대입한다.
//
//	printf("%d X %d = %d\n", a, b, Mul(a, b)); // printf함수를 이용해 %d에 순서대로 a,b와 앞서 선언한 Mul함수에 scanf를 통해 입력받은 a,b의 값을 대입해서 얻은 값을 대입한다.
//
//	return 0; // 메인함수의 종료를 알림
//}

////2
//double FtoC(double F) // 화씨온도를 섭씨온도로 바꿔주는 함수
//{
//    double C = (5.0 / 9.0) * (F - 32); // 실수형 변수 C에 변수 F를 이용한 수식의 계산 값을 저장
//    return C;  // 함수를 호출할때 변수 C의 값을 출력
//}
//double CtoF(double C) // 섭씨온도를 화씨온도로 바꿔주는 함수
//{
//    double F = (9.0 / 5.0) * C + 32.0; // 실수형 변수 F에 변수 C를 이용한 수식의 계산 값을 저장
//    return F; // 함수를 호출할때 변수 F의 값을 출력
//}
//int main() // 메인함수 선언
//{
//    double F = 0, C = 0; // 실수형 변수 F,C 선언
//    printf("화씨 온도 입력 :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//    scanf("%lf", &F); // scanf함수를 이용해 입력받은 실수를 변수 F에 저장
//
//    C = FtoC(F); // 변수 C에 FtoC에 위에서 받은 F의 값을 넣어 계산한 값을 대입
//
//    printf("화씨 온도 %.0lf는 섭씨 온도 %lf \n", F, C); // printf함수를 이용해 %lf에 순서대로 F와 C를 대입한다.
//
//    printf("섭씨 온도 입력 :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//    scanf("%lf", &C); // scanf함수를 이용해 입력받은 실수를 변수 C에 저장
//
//    printf("섭씨 온도 %lf는 화씨 온도 %lf \n", C, CtoF(C)); // printf함수를 이용해 %lf에 순서대로 C와 앞서 선언한 CtoF함수에 scanf를 통해 입력받은 C의 값을 대입해서 얻은 값을 대입한다.
//
//    return 0; // 메인함수의 종료를 알림
//}

////3
//double CmToInch(double Cm) // Cm의 값을 Inch의 값으로 바꿔주는 함수
//{
//	double Inch = Cm / 2.54; // 실수형 변수 Inch에 Cm의 값을 이용한 수식의 계산 값을 저장
//	return Inch; // 함수를 호출할때 변수Inch의 값을 출력
//}
//
//double InchToCm(double Inch) // Inch의 값을 Cm의 값으로 바꿔주는 함수
//{
//	double Cm = Inch * 2.54; // 실수형 변수 Cm에 Inch의 값을 이용한 수식의 계산 값을 저장
//	return Cm; // 함수를 호출할때 변수Cm의 값을 출력
//}
//
//int main() // 메인함수 선언
//{
//	double Cm = 0, Inch = 0; // 실수형 변수 Cm와 Inch를 선언
//	printf("길이 입력(cm) :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//	scanf("%lf", &Cm); // scanf함수를 이용해 입력받은 실수를 변수 Cm에 저장
//
//	printf("%lf Cm는 %lf Inch\n", Cm, CmToInch(Cm)); // // printf함수를 이용해 %lf에 순서대로 Cm와 앞서 선언한 CmToInch함수에 scanf를 통해 입력받은 Cm의 값을 대입해서 얻은 값을 대입한다.
//
//	printf("길이 입력(Inch) :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//	scanf("%lf", &Inch); // scanf함수를 이용해 입력받은 실수를 변수 Inch에 저장
//
//	printf("%lf inch는 %lf Cm\n", Inch, InchToCm(Inch)); // printf함수를 이용해 %lf에 순서대로 Inch와 앞서 선언한 InchToCm함수에 scanf를 통해 입력받은 Inch의 값을 대입해서 얻은 값을 대입한다.
//
//	return 0; // 메인함수의 종료를 알림
//}

//4
double CircleLength(double r) // 원의 반지름을 이용해 원의 둘레를 구하는 함수 
{
	double pi = 3.141592; // 실수형 변수 pi 선언
	double l = 2 * pi * r * r; // 실수형 변수 l에 pi와 r을 이용한 수식의 계산 값을 저장
	return l; // 함수를 호출할때 변수 l에 들어간 값을 출력
}

double CircleArea(double r) // 원의 반지름을 이용해 원의 면적을 구하는 함수
{
	double pi = 3.141592; // 실수형 변수 pi 선언
	double area = pi * r * r; // 실수형 변수 area에 pi와r을 이용한 수식의 계산 값을 저장
	return area; // 함수를 호출할때 변수 area에 들어간 값을 출력
}

int main() // 메인 함수 선언
{                                     
	double pi = 3.141592; // 실수형 변수 pi를 선언
	double r = 0; // 실수형 변수 r을 선언

	printf("원의 반지름 입력 :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
	scanf("%lf", &r); // scanf함수를 이용해 입력받은 실수를 변수 r에 저장

	printf("반지름 %lf 원의 둘레 : %lf\n", r, CircleLength(r)); // printf함수를 이용해 %lf에 순서대로 r과 앞서 선언한 CircleLength함수에 scanf를 통해 입력받은 r의 값을 대입해서 얻은 값을 대입한다.
	printf("반지름 %lf 원의 면적 : %lf\n", r, CircleArea(r)); // printf함수를 이용해 %lf에 순서대로 r과 앞서 선언한 CircleArea함수에 scanf를 통해 입력받은 r의 값을 대입해서 얻은 값을 대입한다.

	return 0; // 메인 함수의 종료를 알림
}

//5
//double SphereVolume(double r) // 구의 반지름을 이용해 구의 부피를 구할 수 있는 함수 선언
//{
//	double pi = 3.141592; // 실수형 변수 pi를 선언
//	double V = (4.0 / 3.0) * pi * (r * r * r); // 실수형 변수 V에 r과 pi를 이용한 수식의 계산 값을 저장
//	return V; // 함수를 호출할때 변수 V안에 들어간 값을 출력
//}
//
//double SphereSurfaceArea(double r) // 구의 반지름을 이용해 구의 겉넓이을 구할 수 있는 함수 선언
//{
//	double pi = 3.141592; // 실수형 변수 pi를 선언
//	double S = 4.0 * pi * (r * r); // 실수형 변수 S에 r과 pi를 이용한 수식의 계산 값을 저장
//	return S; // 함수를 호출할때 변수 S안에 들어간 값을 출력
//}
//
//int main() // 메인 함수 선언
//{
//	double pi = 3.141592; // 실수형 변수 pi 선언
//	double r = 0; // 실수형 변수 r 선언
//	printf("구의 반지름 입력 :"); // printf함수를 이용해 콘솔창에 입력받을 수 있는 문구를 띄움
//	scanf("%lf", &r); // scanf함수를 이용해 입력받은 실수를 변수 r에 저장
//
//	printf("반지름 %lf 구의 체적 : %lf\n", r, SphereVolume(r)); // printf함수를 이용해 %lf에 순서대로 r과 앞서 선언한 SphereVolume함수에 scanf를 통해 입력받은 r의 값을 대입해서 얻은 값을 대입한다.
//
//	printf("반지름 %lf 구의 표면적 : %lf\n", r, SphereSurfaceArea(r)); // printf함수를 이용해 %lf에 순서대로 r과 앞서 선언한 SphereSurfaceArea함수에 scanf를 통해 입력받은 r의 값을 대입해서 얻은 값을 대입한다.
//
//	return 0; // 메인함수의 끝을 알림
//}
