#include <stdio.h>
#pragma warning (disable : 4996)

//1 복소수
typedef struct _complex // typedef를 사용해서 구조체 정의
{
	double real; // 복소수의 실수부
	double image; // 복소수의 허수부
} Complex; // struct _complex == Complex
// 새로운 자료형 'Complex'
int main()
{
	Complex Z1 = { 0 , 0 }; // 첫번째 복소수를 받기 위한 변수 선언
	Complex Z2 = { 0 , 0 }; // 두번째 복소수를 받기 위한 변수 선언
	Complex Z = { 0 , 0 }; // 두 복소수를 더하고 곱한 값을 받기 위한 변수 선언

	printf("첫번째 복소수 입력 :"); // 첫번째 복소수의 입력을 받기 위해 문구 출력
	scanf("%lf %lf", &Z1.real, &Z1.image); // 입력받은 수를 Z1의 real과 Z1의 image에 저장
	printf("두번째 복소수 입력 :"); // 두번째 복소수의 입력을 받기 위해 문구 출력
	scanf("%lf %lf", &Z2.real, &Z2.image); // 입력받은 수를 Z2의 real과 Z2의 image에 저장

	Z.real = Z1.real + Z2.real; // Z1과 Z2의 실수부를 더한 값을 Z의 실수부에 저장한다.
	Z.image = Z1.image + Z2.image; // Z1과 Z2의 허수부를 더한 값을 Z의 허수부에 저장한다.

	if (Z.image < 0) // 허수부의 깔끔한 음수 표시를 위해 조건문 사용
		printf("두 복소수의 합은 %.2lf - j %.2lf\n", Z.real, -Z.image); // 허수부가 음수라면 이 문구 출력
	else
		printf("두 복소수의 합은 %.2lf + j %.2lf\n", Z.real, Z.image); // 허수부가 양수라면 이 문구 출력

	Z.real = Z1.real * Z2.real - Z1.image * Z2.image; // Z1과 Z2의 곱셈과정에서 얻게 되는 실수부를 Z의 실수부에 저장
	Z.image = Z1.real * Z2.image + Z1.image * Z2.real; // Z1과 Z2의 곱셈과정에서 얻게 되는 허수부를 Z의 허수부에 저장

	if (Z.image < 0) // 허수부의 깔끔한 음수 표시를 위해 조건문 사용
		printf("두 복소수의 곱은 %.2lf - j %.2lf", Z.real, -Z.image); // 허수부가 음수라면 이 문구 출력
	else
		printf("두 복소수의 곱은 %.2lf + j %.2lf", Z.real, Z.image); // 허수부가 양수라면 이 문구 출력
	return 0;
}

////2 복소수 덧셈, 뺄셈, 곱셈, 나눗셈, 켤레 계산
//typedef struct _complex // typedef를 사용해서 구조체 정의
//{
//	double real; // 복소수의 실수부
//	double image; // 복소수의 허수부
//} Complex; // struct _complex == Complex
//// 새로운 자료형 'Complex'
//Complex AddComplex(Complex Z1, Complex Z2) // 덧셈
//{
//	Complex Z = { 0 , 0 }; // 두 복소수를 더한 값을 받기 위한 변수 선언
//	Z.real = Z1.real + Z2.real; // Z1과 Z2의 실수부를 더한 값을 Z의 실수부에 저장한다.
//	Z.image = Z1.image + Z2.image; // Z1과 Z2의 허수부를 더한 값을 Z의 허수부에 저장한다.
//	return Z; // Z 반환
//}
//Complex SubComplex(Complex Z1, Complex Z2) // 뺄셈
//{
//	Complex Z = { 0 , 0 }; // 두 복소수를 뺀 값을 받기 위한 변수 선언
//	Z.real = Z1.real - Z2.real; // Z1과 Z2의 실수부를 뺀 값을 Z의 실수부에 저장한다.
//	Z.image = Z1.image - Z2.image; // Z1과 Z2의 허수부를 뺀 값을 Z의 허수부에 저장한다.
//	return Z; // Z 반환
//}
//Complex ConjugateComplex(Complex Z3) // 켤레복소수
//{
//	Z3.image = -Z3.image; // 허수부의 부호만 바꾼다.
//	return Z3; // Z 반환
//}
//Complex MulComplex(Complex Z1, Complex Z2) // 곱셈
//{
//	Complex Z = { 0 , 0 }; // 두 복소수를 곱한 값을 받기 위한 변수 선언
//	Z.real = Z1.real * Z2.real - Z1.image * Z2.image; // Z1과 Z2의 곱셈과정에서 얻게 되는 실수부를 Z의 실수부에 저장
//	Z.image = Z1.real * Z2.image + Z1.image * Z2.real; // Z1과 Z2의 곱셈과정에서 얻게 되는 허수부를 Z의 허수부에 저장
//	return Z; // Z 반환
//}
//Complex DivComplex(Complex Z1, Complex Z2) // 나눗셈
//{
//	Complex Z = { 0 , 0 }; // 두 복소수를 나눈 값을 받기 위한 변수 선언 
//	Complex conjugateZ2 = ConjugateComplex(Z2); // 유리화를 위해 분모의 켤레복소수를 구함
//	double den = (Z2.real * Z2.real) + (Z2.image * Z2.image); // 분모의 복소수와 켤레복소수를 곱한 값을 저장
//	Complex MulZ1conZ2 = MulComplex(Z1, conjugateZ2); // 분자의 복소수와 분모의 켤레복소수를 곱한 값을 저장
//	Z.real = MulZ1conZ2.real / den; // 분자의 실수부를 분모로 나눈 수를 Z의 실수부에 저장
//	Z.image = MulZ1conZ2.image / den; // 분자의 허수부를 분모로 나눈 수를 Z의 허수부에 저장
//	return Z; // Z 반환
//}
//void ComplexPrn(Complex Z3)
//{
//	if (Z3.image < 0) // 허수부의 깔끔한 음수 표시를 위해 조건문 사용
//		printf("% .2lf - j %.2lf\n", Z3.real, -Z3.image); // 허수부가 음수라면 이 문구 출력
//	else
//		printf("% .2lf + j %.2lf\n", Z3.real, Z3.image); // 허수부가 양수라면 이 문구 출력
//}
//int main()
//{
//	Complex Z1 = { 0 , 0 }; // 첫번째 복소수를 받기 위한 변수 선언
//	Complex Z2 = { 0 , 0 }; // 두번째 복소수를 받기 위한 변수 선언
//	Complex Z3 = { 0 , 0 }; // 두 복소수를 계산 값을 받기 위한 변수 선언
//
//	printf("복소수 입력 :"); // 첫번째 복소수의 입력을 받기 위해 문구 출력
//	scanf("%lf %lf", &Z1.real, &Z1.image); // 입력받은 수를 Z1의 real과 Z1의 image에 저장
//	printf("복소수 입력 :"); // 두번째 복소수의 입력을 받기 위해 문구 출력
//	scanf("%lf %lf", &Z2.real, &Z2.image); // 입력받은 수를 Z2의 real과 Z2의 image에 저장
//
//	Z3 = AddComplex(Z1, Z2); // 두 복소수의 덧셈 값을 저장
//	printf("복소수의 합은            "); // 합의 결과를 출력함을 알리는 문구 출력
//	ComplexPrn(Z3); // 복소수 출력
//	Z3 = SubComplex(Z1, Z2); // 두 복소수의 뺄셈 값을 저장
//	printf("복소수의 차는            "); // 차의 결과를 출력함을 알리는 문구 출력
//	ComplexPrn(Z3); // 복소수 출력
//	Z3 = ConjugateComplex(Z1); // Z1복소수의 켤레복소수 계산 값을 저장
//	printf("복소수의 켤레는          "); // 켤레복소수를 출력함을 알리는 문구 출력
//	ComplexPrn(Z3); // 복소수 출력
//	Z3 = MulComplex(Z1, Z2); // 두 복소수의 곱셈 값을 저장
//	printf("복소수의 곱은            "); // 곱의 결과를 출력함을 알리는 문구 출력
//	ComplexPrn(Z3); // 복소수 출력
//	Z3 = DivComplex(Z1, Z2); // 두 복소수의 나눗셈 값을 저장
//	printf("복소수의 나누기는        "); // 나눗셈의 결과를 출력함을 알리는 문구 출력
//	ComplexPrn(Z3); // 복소수 출력
//	return 0;
//}

////3 학생의 성적을 계산하는 프로그램
//typedef struct _score // typedef를 사용해서 구조체 정의
//{
//	char name[3]; // 학생들의 이름
//	int korean; // 국어성적
//	int english; // 영어성적
//	int math; // 수학성적
//	int total; // 총점
//	double average; // 평균
//} SCORE; // struct _score == SCORE
//// 새로운 자료형 'SCORE'
//int main()
//{
//	SCORE A[3] = { {"KBH",100,95,90,0,0},{"SCH",96,87,90,0,0},{"LSH",78,67,87,0,0} }; // 구조체 배열 // 세 학생의 이름과 국어성적,영어성적,수학성적만 입력해둠
//	for (int i = 0; i < 3; i++) // 총점, 평균 계산, 출력
//	{
//		A[i].total = A[i].korean + A[i].english + A[i].math; // 각 배열의 국어와 영어와 수학 성적을 더해 총점 값을 구함
//		A[i].average = ((double)A[i].total / 3.00); // 각 배열의 총점을 3으로 나눠 평균 값을 구함
//		printf("이름 : %.3s 국어 : %3d 영어 : %d 수학 : %d 총점 : %d 평균 : %.2lf\n", A[i].name, A[i].korean, A[i].english, A[i].math, A[i].total, A[i].average);
//		// 각 배열의 멤버 변수들을 순서대로 대입하여 출력
//	}
//	return 0;
//}
