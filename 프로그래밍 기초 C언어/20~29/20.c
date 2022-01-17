#include <stdio.h>
#pragma warning (disable : 4996)

////1 // 입력받은 정수배열을 정순출력 , 역순출력
//void InputIntArr(int* arr, int n) // 배열에 정수 입력받기
//{
//	for (int i = 0; i < n; i++) // arr[0] ~ arr[n-1]까지 수 넣기 
//	{
//		printf("배열 %d번째 원소 입력 :", i + 1); // arr[i] 배열에 
//		scanf("%d", arr + i); // 입력받은 수 대입 // arr + i == &arr[i]
//	}
//}
//
//void OutputIntArr(int* arr, int n) // 배열을 정순으로 추력
//{
//	for (int i = 0; i < n; i++) // 입력을 전부 받은 배열을 
//	{
//		printf("%4d", *(arr + i)); // 정순으로 출력 // *(arr + i) == arr[i]
//	}
//}
//
//void InvOutputIntArr(int* arr, int n) // 배열을 역순으로 출력
//{
//	for (int i = n - 1; i >= 0; i--) // 입력을 전부 받은 배열을
//	{
//		printf("%4d", *(arr + i)); // 역순으로 출력 // *(arr + i) == arr[i]
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//		int arr[10] = { 0 }; // 수를 입력받을 1차원 배열 선언
//		int n = 0; // 얼마만큼 수를 받을지 알려주기 위한 변수 선언
//
//		printf("정수의 수 입력 :"); // 정수의 수를 입력받기 위한 문구 출력
//		scanf("%d", &n); // 입력받은 수를 변수 n에 저장
//
//		if (n == 0) // 정수의 수가 0이면
//		{
//			printf("종료"); // 종료 문구를 띄운 후
//			break; // while문을 빠져나옴
//		}
//
//		printf("정수 %d개 입력\n", n); // 정수를 몇개 입력받을건지 알려주는 문구 출력
//        InputIntArr(arr, n); // 배열에 수를 입력받기 위한 함수 호출
//
//		printf("입력된 정수 출력\n"); // 정순출력을 알리기 위한 문구 출력
//		OutputIntArr(arr, n); // 배열을 정순으로 출력하기 위한 함수 호출
//
//		printf("\n입력된 정수 역 출력\n"); // 역순출력을 알리기 위한 문구 출력
//		InvOutputIntArr(arr, n); // 배열을 역순으로 출력하기 위한 함수 호출
//
//		printf("\n"); // 줄 띄움
//	}
//	return 0; // 메인문 종료
//}

////2 // 배열의 큰 수와 작은 수를 찾는 프로그램
//void InputDoubleArr(double* arr, int n) // 배열에 실수 입력받기
//{
//	for (int i = 0; i < n; i++) // arr[0] ~ arr[n-1] 까지 입력받기
//	{
//		printf("배열 %d번째 원소 입력 :", i + 1); // arr[i]에
//		scanf("%lf", arr + i); // 입력받은 수 저장 // arr + i == &arr[i]
//	}
//}
//
//void OutputDoubleArr(double* arr, int n) // 입력을 전부 받은 배열을 출력
//{
//	for (int i = 0; i < n; i++) // arr[0] ~ arr[n-1] 배열 출력
//	{
//		printf("%6.2lf", *(arr + i)); // *(arr + i) == arr[i]
//	}
//	printf("\n"); // 줄 띄움
//}
//
//double MaxNumArr(double* arr, int n) // 가장 큰 수를 찾는 함수
//{
//	double MAXn = *(arr + 0); // 가장 큰 수를 입력받기 위한 실수형 변수 선언
//	for (int i = 0; i < n; i++) // 가장 큰 수를 찾기 위한 반복문
//	{
//		if (*(arr + i) > MAXn) // 배열의 i번째 수가 변수 MAXn에 있는 수보다 큰 지 판단 
//		{
//			MAXn = *(arr + i); // 크다면 그 수를 변수 MAXn에 저장
//		}
//	}
//	return MAXn; // 함수가 호출이 될 때, MAXn을 출력
//}
//
//double MinNumArr(double* arr, int n) // 가장 작은 수를 찾는 함수
//{
//	double minn = *(arr + 0); // 가장 작은 수를 입력받기 위한 실수형 변수 선언
//	for (int i = 0; i < n; i++) // 가장 작은 수를 알아보기 위한 반복문
//	{
//		if (*(arr + i) < minn) // 배열의 i번째 수가 변수 minn에 있는 수보다 작은지 판단
//		{
//			minn = *(arr + i); // 작다면 그 수를 변수 minn에 저장
//		}
//	}
//	return minn; // 함수가 호출이 될 때, minn을 출력
//}
//
//int main()
//{
//	while (1)
//	{
//		double arr[10] = { 0 }; // 수를 입력받기 위한 1차원 배열 선언
//		int n = 0; // 그 수를 얼마만큼 입력받을지를 알기 위한 변수 선언
//
//		printf("실수의 수 입력 :"); // 실수의 수를 입력받기 위한 문구 출력
//		scanf("%d", &n); // 입력된 수를 n에 저장
//
//		if (n == 0) // 만약 n이 0이라면 
//		{
//			printf("종료"); // 종료를 띄우고
//			break; // while문을 빠져나옴
//		}
//		printf("실수 %d개 입력\n", n); // 실수를 몇개 입력받을 건지 출력
//
//		InputDoubleArr(arr, n); // 배열에 실수를 입력받기 위한 함수 호출
//
//		printf("입력된 실수\n"); // 출력을 알리는 문구 출력
//		OutputDoubleArr(arr, n); // 배열을 출력하기 위한 함수 호출
//
//		printf("가장 큰 실수 %5.2lf", MaxNumArr(arr, n)); // MaxNumArr(arr, n)함수를 이용해 배열 중 가장 큰 수를 출력
//		printf(" 가장 작은 실수 %5.2lf\n", MinNumArr(arr, n)); // MinNumArr(arr, n)함수를 이용해 배열 중 가장 작은 수를 출력
//	}
//	return 0; // 메인문 종료
//}

////3 // 입력받은 수 오름차순 정리
//void InputIntArr(int* arr, int n) // 배열에 정수 입력받기
//{
//	for (int i = 0; i < n; i++) // arr[0] ~ arr[n-1]까지 입력받기 
//	{
//		printf("배열의 arr[%d] 입력 :", i); // arr[i]에
//		scanf("%d", arr + i); // 입력된 값을 저장 // arr + i == &arr[i]
//	}
//}
//
//void OutputIntArr(int* arr, int n) // 배열을 순서대로 출력
//{
//	for (int i = 0; i < n; i++) // arr[0] ~ arr[n-1] 배열 출력
//	{
//		printf("%4d", *(arr + i)); // *(arr + i) == arr[i]
//	}
//}
//
//void ArrAscentSort(int* arr, int n) // 배열을 오름 차순으로 정리
//{
//	int num = 0;
//	for (int j = 0; j < n - 1; j++) // arr[j]의 수를
//	{
//		for (int i = 0; i < n - 1; i++) // arr[0] ~ arr[n-2]까지의 수와 비교한다
//		{
//			if (*(arr + i) > * (arr + (i + 1))) // arr[i]의 수가 arr[i+1]보다 더 크면
//			{
//				num = *(arr + i); // arr[i]의 수를 num에 넣어두고
//				*(arr + i) = *(arr + (i + 1)); // arr[i]에 arr[i+1]를 넣은 후
//				*(arr + (i + 1)) = num; // arr[i+1]에 원래 arr[i]의 수가 들어간다 = 큰 수들이 뒤로 밀린다
//			} 
//		}
//	}
//}
//
//int main()
//{
//	while (1)
//	{ 
//		int arr[10] = { 0 }; // 수를 입력받을 1차원 배열 선언
//		int n = 0; // 그 수를 얼마만큼 받을건지 알려주는 변수 선언
//
//		printf("정수의 수 입력:"); // 정수의 수를 입력받기 위한 문구 출력
//		scanf("%d", &n); // 입력받은 수를 n에 저장
//
//		if (n == 0) // 만약 n이 0이라면
//		{
//			printf("종료"); // 종료를 출력하고
//			break; // while문을 빠져나옴
//		}
//
//		printf("정수 %d개 입력\n", n); // 정수를 몇개 입력받는지 알리는 문구 출력
//
//		InputIntArr(arr, n); // 배열에 정수를 입력하기 위한 함수 호출
//
//		printf("정렬 전\n"); // 오름 차순 정렬 전임을 알리는 문구 출력
//		OutputIntArr(arr, n); // 정렬 전 배열을 출력하기 위한 함수 호출
//
//		ArrAscentSort(arr, n); // 배열을 오름 차순으로 정리하기 위한 함수 호출
//		printf("\n정렬 후\n"); // 오름 차순 정렬 후임을 알리는 문구 출력
//		OutputIntArr(arr, n); // 정렬 후 배열을 출력하기 위한 함수 호출
//
//		printf("\n"); // 줄을 띄움
//	}
//	return 0; // 메인문 종료
//}

////4 // 문자열을 입력받아 그 문자열에 몇개의 문자로 구성되어있는지 알고, 소문자는 대문자로 대문자는 소문자로 바꾸기 위한 프로그램
//int StrLen(char* arr, int n) // 문자열의 길이를 세기 위한 함수 
//{
//	int str = 0; // 문자들의 개수를 셀 변수 선언
//
//	for (int i = 0; i < n; i++) // 문자들의 개수를 세기 위한 반복문
//	{
//		if (*(arr + i) == '\0') // *(arr + i)에 저장된 문자가 \0이라면 // *(arr + i) == arr[i]
//		{
//			break; // 반복문 종료
//		}
//		else // 아니라면 
//		{
//			str += 1; // 문자들의 개수를 하나씩 셈
//		}
//	}
//	return str; // 함수가 호출될 때, 총 알게된 문자열의 길이를 출력
//}
//
//void CharacterConversion(char* arr, int n) // 소 -> 대 , 대 -> 소 함수
//{
//	for (int i = 0; i < n; i++) // 문자열의 i번째 원소가 소문자인지 대문자인지 판단하고 소문자라면 대문자로 대문자라면 소문자로 바꾸기위한 반복문 
//	{
//		if (*(arr + i) >= 'a' && *(arr + i) <= 'z') // 소문자인지 판단 // *(arr + i) == arr[i]
//		{
//			*(arr + i) -= 32; // 맞다면 소문자를 대문자로 바꿔준다. // *(arr + i) == arr[i]
//		}
//		else if (*(arr + i) >= 'A' && *(arr + i) <= 'Z') // 대문자인지 판단 // *(arr + i) == arr[i]
//		{
//			*(arr + i) += 32; // 맞다면 대문자를 소문자로 바꿔준다. // *(arr + i) == arr[i]
//		}
//		else if (*(arr + i) == '\0')
//			break;
//	}
//}
//
//int main()
//{
//	char arr[50] = { 0 }; // 문자열을 입력받을 배열을 넉넉히 50만큼 선언
//
//	printf("문자열 입력 :"); // 문자열을 입력받기 위한 문구를 출력
//	scanf("%s", arr); // 입력받은 문자열을 배열 arr에 저장
//
//	printf("입력된 문자열은 %d개의 문자로 구성\n%s", StrLen(arr, 50), arr); // StrLen(arr, 50) 함수를 이용해 입력받은 문자열이 몇개의 문자로 구성되어 있는지를 출력하고 , 그 문자열이 변환되기 전의 모습을 출력
//
//	CharacterConversion(arr, 50); // 소문자는 대문자로 대문자는 소문자로 바꾸기 위해 CharacterConversion(arr, 50) 함수호출
//	printf("\n변경 후 문자열\n%s", arr); // 변환된 문자열을 출력한다.
//	return 0; // 메인함수 종료
//}
