#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)


////1
//double KineticEnergy(double kg, double ms) // 변수 kg,ms를 이용해 운동에너지를 구하는 함수
//{
//	double E = 1.0 / 2.0 * kg * ms * ms; // 변수 kg와 ms를 잉요한 식의 계산값을 저장
//	return E; // 함수를 호출할 때 변수 E에 저장된 값을 출력
//}
// 
//int main() // 메인함수의 시작을 알림
//{
//	double kg = 0, ms = 0; // 실수형 변수 kg,ms 선언
//	printf("질량(kg)과 속력 (m/s) 입력 :"); // printf함수를 잉요해 글을 콘솔창에 띄움
//	scanf("%lf %lf", &kg, &ms); // scanf를 이용해 입력받은 수를 차례대로 변수 kg,ms에 저장
//
//	printf("질량 %.2lfkg이고 속력 %.2lf m/s의 물체의 운동에너지 : %.2lf [J]", kg, ms, KineticEnergy(kg, ms)); // 변수 kg,ms와 함수  KineticEnergy에 변수 kg,ms를 대입해 얻은 값을 %.2lf에 차례대로 대입 후 printf함수를 이용해 콘솔창에 띄움
//
//	return 0; // 메인함수의 종료를 알림
//}

////2
//double Density(double g, double cm3) // 변수 g,cm3를 이용해 밀도를 구하는 함수 
//{
//	double D = g / cm3; // 변수 g,cm3를 이용한 식의 계산값을 저장
//	return D; // 함수를 호출할 때 변수 D에 저장된 값을 출력
//}
//
//int main() // 메인함수의 시작을 알림
//{
//	double g = 0, cm3 = 0; // 실수형 변수 g,cm3를 선언
//	printf("질량(g)과 부피(cm^3) 입력 :"); // printf함수를 잉요해 글을 콘솔창에 띄움
//	scanf("%lf %lf", &g, &cm3); // scanf함수를 이용해 입력받은 수를 차례대로 변수 g,cm3에 저장
//
//	printf("질량 %.2lfg이고 부피 %.2lf cm^3의 밀도 %.2lf [g/cm^3]", g, cm3, Density(g, cm3)); // 변수 g,cm3의 값과 함수 Density에 변수 g,cm3를 대입해 계산한 값을 %.2lf에 차례로 대입 후 printf함수를 이용해 콘솔창에 띄움.
//	return 0; // 메인함수의 종료를 알림
//}

////3
//double HMStoSec(double h, double m, double s) // 변수 h,m,s를 이용해 동영상의 재생시간이 총 몇초인지 구하는 함수
//{
//	double H = h * 3600.0; // 변수 h를 이용한 계산 값을 저장
//	double M = m * 60.0; // 변수 m을 이용한 식의 계산 값을 저장
//	double P = H + M + s; // 변수 H,M,s를 이용한 식의 계산 값을 저장
//	return P; // 함수를 호출할때 변수 P에 있는 값을 출력
//}
//
//int main() // 메인 함수의 시작을 알림
//{
//	double h = 0, m = 0, s = 0; // 실수형 변수 h,m,s선언
//	printf("재생시간 시 분 초 입력 :"); // printf함수를 이용해 글을 콘솔창에 띄움.
//	scanf("%lf %lf %lf", &h, &m, &s); // scanf를 이용해 입력된 값을 변수 h,m,s에 차례대로 저장한다.
//
//	printf("재생시간은 총 %.0lf초", HMStoSec(h, m, s)); // 함수 HMStoSec에 변수 h,m,s를 대입해 얻은 값을 %.0lf에 대입한 후 printf함수를 이용해 콘솔창에 띄운다.
//
//	return 0; // 메인함수의 종료를 알림
//}

//4
double ElectricCharge(double w, double kWh) // 변수 w,kWh를 이용해 전기요금을 계산하는 함수
{
	double EW = w + (kWh * 190.0); // 변수 w,kWh를 이용한 식의 계산 값을 변수 EW에 대입
	return EW; // 함수를 호출할때 변수 EW의 값을 출력
}

int main() // 메인함수의 시작을 알림
{
	double w, kWh = 0; // 실수형 변수 w,kWh를 선언
	printf("기본요금 :"); // printf함수를 이용해 글을 콘솔창에 띄움.
	scanf("%lf", &w); // scanf함수를 이용해 입력받은 값을 변수 w에 저장
	printf("월 사용량(kwh) :"); // printf함수를 이용해 글을 콘솔창에 띄움.
	scanf("%lf", &kWh); // scanf함수를 이용해 입력받은 값을 변수 kWh에 저장

	printf("전기요금 %.0lf 원", ElectricCharge(w, kWh)); // ElectricCharge함수에 변수 w,kWh를 대입했을때 나오는 값을 .0lf에 대입한후 printf함수를 이용해 콘솔창에 글을 띄운다.

	return 0; // 메인함수의 종료를 알림
}
