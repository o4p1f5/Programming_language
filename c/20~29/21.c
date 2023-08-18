#include <stdio.h>
#pragma warning (disable : 4996)

//1 // 행렬의 크기를 입력하여 그 크기에 맞는 원소들을 입력받은 다음 이를 출력 
void InputMatrix(int(*parr)[10], int row, int col) // 원소를 입력받기 위한 함수
{
	for (int i = 0; i < row; i++) // 각 행과 열에 원소를 입력받기 위한 반복문 // 행
	{
		for (int j = 0; j < col; j++) // 열
		{
			printf("%d 행 %d 열 원소 입력 :", i + 1, j + 1); // 입력을 받기위한 문구 출력
			scanf("%d", parr[i][j]); // i행과 j열에 입력받은 수를 저장 // (*(parr + i) + j) == &arr[i][j]
		}
	}
}
void OutputMatrix(int(*parr)[10], int row, int col) // 원소를 출력하기 위한 함수
{
	for (int i = 0; i < row; i++) // 행
	{
		for (int j = 0; j < col; j++) // 열
		{
			printf("%4d", parr[i][j]); // 각 행과 열의 원소 출력 // *(*(parr + i) + j) == arr[i][j]
		}
		printf("\n"); // 한줄 띄움
	}
}

int main()
{
	while (1) // 행렬의 크기가 0 0 이 되면 종료
	{
		int arr[10][10] = { 0 }; // 행과 열의 크기가 10인 배열 선언
		int* parr = arr;
		int x = 0; // 행을 뜻하는 변수 선언
		int y = 0; // 열을 뜻하는 변수 선언

		printf("행렬의 크기 입력 : "); // 행렬의 크기를 입력받기 위한 문구 출력
		scanf("%d %d", &x, &y); // 행과 열의 크기를 각각 입력받아 변수에 저장

		if (x == 0 || y == 0) // 그 수들이 0인지 판단
		{
			printf("종료"); // 0이라면 '종료'를 출력하고
			return 0; // 메인문 종료
		}

		InputMatrix(parr, x, y); // 원소를 입력받기 위해 InputMatrix 함수 호출

		printf("\n 입력된 행렬\n"); // 행렬의 출력을 알리는 문구 출력
		OutputMatrix(parr, x, y); // 원소를 출력하기 위해 OutputMatrix 함수 호출

		printf("\n"); 
	}
}

////2 // 두 행렬의 덧셈과 뺄셈
//void InputMatrix(int(*P)[10], int x, int y) // 행렬 A나 B의 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < x; i++) // 행
//	{
//		for (int j = 0; j < y; j++) // 열
//		{
//			printf("%d 행 %d 열 원소 입력 :", i + 1, j + 1); // 각 원소를 받기 위한 문구 출력
//			scanf("%d", (*(P + i) + j)); // 입력받은 수를 i행 j열에 저장 // (*(P + i) + j) == &P[i][j]
//		}
//	}
//}
//void OutputMatrix(int(*PC)[10], int ax, int ay) // 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < ay; j++) // 열
//		{
//			printf("%5d", *(*(PC + i) + j)); // 각 행과 열의 원소 출력 // *(*(PC + i) + j) == C[i][j]
//		}
//		printf("\n"); // 한줄 띄움
//	}
//}
//void AddMatrix(int(*PA)[10], int(*PB)[10], int(*PC)[10], int ax, int ay) // 행렬의 덧셈 계산 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < ay; j++) // 열
//		{
//			*(*(PC + i) + j) = *(*(PA + i) + j) + *(*(PB + i) + j); // 두 행렬의 같은 행과 열 원소를 더한 수를 C행렬 저장 
//			// *(*(PC + i) + j) == C[i][j] //  *(*(PA + i) + j) == A[i][j] //  *(*(PB + i) + j) == B[i][j]
//		}
//	}
//}
//void SubMatrix(int(*PA)[10], int(*PB)[10], int(*PC)[10], int ax, int ay) // 행렬의 뺄셈 계산 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < ay; j++) // 열
//		{
//			*(*(PC + i) + j) = *(*(PA + i) + j) - *(*(PB + i) + j); // 두 행렬의 같은 행과 열 원소를 뺀 수를 C행렬 저장 
//			// *(*(PC + i) + j) == C[i][j] //  *(*(PA + i) + j) == A[i][j] //  *(*(PB + i) + j) == B[i][j]
//		}
//	}
//}
//
//int main()
//{
//	while (1) // 두 행렬의 행과 열 크기가 0이거나 두 행렬의 크기가 다르면 종료 
//	{
//		int A[10][10] = { 0 }; // A행렬 선언
//		int B[10][10] = { 0 }; // B행렬 선언
//		int C[10][10] = { 0 }; // C행렬 선언
//		int ax = 0; // A행렬의 행을 받기 위한 변수 선언
//		int ay = 0; // A행렬의 열을 받기 위한 변수 선언 
//		int bx = 0; // B행렬의 행을 받기 위한 변수 선언
//		int by = 0; // B행렬의 열을 받기 위한 변수 선언
//
//		printf("행렬의 덧셈 뺄셈 연산\n"); // 연산의 시작을 알림
//
//		printf("행렬 A의 크기 입력 : "); // A행렬의 크기를 입력받기 위한 문구 출력
//		scanf("%d %d", &ax, &ay); // 각 수를 행과 열 변수에 저장
//		if (ax == 0 || ay == 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		printf("행렬 B의 크기 입력 : "); // B행렬의 크기를 입력받기 위한 문구 출력
//		scanf("%d %d", &bx, &by); // 각 수를 행과 열 변수에 저장
//		if (bx == 0 || by == 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		if (!(ax == bx || ay == by)) // 두 행렬의 행과 열의 크기가 다르다면 
//		{
//			printf("행렬의 덧셈과 뺄셈을 할 수 없습니다.\n 종료"); // 계산을 할 수 없음을 알리는 문구 출력
//			return 0; // 메인문 종료
//		}
//
//		printf("행렬 A 입력\n"); // A의 원소를 입력받기 위한 문구 출력
//		InputMatrix(A, ax, ay); // InputMatrix 함수를 호출하여 행렬 A의 원소 입력
//		printf("행렬 B 입력\n"); // B의 원소를 입력받기 위한 문구 출력
//		InputMatrix(B, bx, by); // InputMatrix 함수를 호출하여 행렬 B의 원소 입력
//
//		AddMatrix(A, B, C, ax, ay); // 행렬의 덧셈을 하기 위해 AddMatrix 함수 호출
//		printf("\n 행렬의 덧셈 결과\n"); // 덧셈 결과 출력을 알리는 문구 출력
//		OutputMatrix(C, ax, ay); // 행렬 출력을 위해 OutputMatrix 함수 호출
//
//		SubMatrix(A, B, C, ax, ay); // 행렬의 뺄셈을 하기 위해 SubMatrix 함수 호출
//		printf("\n 행렬의 뺄셈 결과\n"); // 뺄셈 결과 출력을 알리는 문구 출력
//		OutputMatrix(C, ax, ay); // 행렬 출력을 위해 OutputMatrix 함수 호출
//
//		printf("\n");
//	}
//}

////3 // 두 행렬의 곱 계산 
//void InputMatrix(int(*P)[10], int x, int y) // 행렬 A나 B의 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < x; i++) // 행
//	{
//		for (int j = 0; j < y; j++) // 열
//		{
//			printf("%d 행 %d 열 원소 입력 :", i + 1, j + 1); // 각 원소를 받기 위한 문구 출력
//			scanf("%d", (*(P + i) + j)); // 입력받은 수를 i행 j열에 저장 // (*(P + i) + j) == &P[i][j]
//		}
//	}
//}
//void OutputMatrix(int(*PC)[10], int ax, int by) // 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < by; j++) // 열
//		{
//			printf("%5d", *(*(PC + i) + j)); // 각 행과 열의 원소 출력 // *(*(PC + i) + j) == C[i][j]
//		}
//		printf("\n"); // 한줄 띄움
//	}
//}
//void MulMatrix(int(*PA)[10], int(*PB)[10], int(*PC)[10], int ax, int by, int ay) // 행렬의 덧셈 계산 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < by; j++) // 열
//		{
//			for (int k = 0; k < ay; k++) // 앞 행렬의 열과 뒷 행렬의 행
//			{
//				*(*(PC + i) + j) = *(*(PC + i) + j) + (*(*(PA + i) + k) * *(*(PB + k) + j)); // 계산 된 값을 C행렬 저장 
//				// *(*(PC + i) + j) == C[i][j] //  *(*(PA + i) + j) == A[i][j] //  *(*(PB + i) + j) == B[i][j]
//			}
//		}
//	}
//}
//
//int main()
//{
//	while (1) // 두 행렬의 행과 열 크기가 0이거나 앞행렬의 열 크기와 뒤행렬의 행 크기가 다르면 종료 
//	{
//		int A[10][10] = { 0 }; // A행렬 선언
//		int B[10][10] = { 0 }; // B행렬 선언
//		int C[10][10] = { 0 }; // C행렬 선언
//		int ax = 0; // A행렬의 행을 받기 위한 변수 선언
//		int ay = 0; // A행렬의 열을 받기 위한 변수 선언 
//		int bx = 0; // B행렬의 행을 받기 위한 변수 선언
//		int by = 0; // B행렬의 열을 받기 위한 변수 선언
//		printf("행렬의 곱셈 연산\n"); // 연산의 시작을 알림
//
//		printf("행렬 A의 크기 입력 : "); // A행렬의 크기를 입력받기 위한 문구 출력
//		scanf("%d %d", &ax, &ay); // 각 수를 행과 열 변수에 저장
//		if (ax == 0 || ay == 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		printf("행렬 B의 크기 입력 : "); // B행렬의 크기를 입력받기 위한 문구 출력
//		scanf("%d %d", &bx, &by); // 각 수를 행과 열 변수에 저장
//		if (bx == 0 || by == 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		if (!(ay == bx)) // 앞행렬의 열 크기와 뒤행렬의 행 크기가 다르면
//		{
//			printf("행렬의 곱셈을 할 수 없습니다.\n 종료"); // 계산을 할 수 없음을 알리는 문구 출력
//			return 0; // 메인문 종료
//		}
//
//        printf("행렬 A 입력\n"); // A의 원소를 입력받기 위한 문구 출력
//		InputMatrix(A, ax, ay); // 행렬 A에 원소를 입력하기 위해 InputMatrix 함수 호출
//		printf("행렬 B 입력\n"); // B의 원소를 입력받기 위한 문구 출력
//		InputMatrix(B, bx, by); // 행렬 B에 원소를 입력하기 위해 InputMatrix 함수 호출
//
//		MulMatrix(A, B, C, ax, by, ay); // 행렬의 곱셈 계산을 위해 MulMatrix 함수 호출 // ay == bx
//
//		printf("\n 행렬의 곱셈 결과\n"); // 곱셈 결과 출력을 알리는 문구 출력
//		OutputMatrix(C, ax, by); // 곱셈 결과 출력을 위해 OutputMatrix 함수 호출
//
//		printf("\n");
//	}
//}

////4 // 행렬의 전치
//void InputMatrix(int(*PA)[10], int ax, int ay) // 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < ax; i++) // 각 행과 열에 원소를 입력받기 위한 반복문 // 행
//	{
//		for (int j = 0; j < ay; j++) // 열
//		{
//			printf("%d 행 %d 열 원소 입력 :", i + 1, j + 1); // 입력을 받기위한 문구 출력
//			scanf("%d", (*(PA + i) + j)); // i행과 j열에 입력받은 수를 저장 // (*(PA + i) + j) == &A[i][j]
//		}
//	}
//}
//void OutputMatrix1(int(*PA)[10], int ax, int ay) // 전치 전 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < ay; j++) // 열
//		{
//			printf("%4d", *(*(PA + i) + j)); // 각 행과 열의 원소 출력 // *(*(PA + i) + j) == A[i][j]
//		}
//		printf("\n"); // 한줄 띄움
//	}
//}
//void OutputMatrix2(int(*PA)[10], int ax, int ay, int mxy) // 전치 후 원소를 출력하기 위한 함수
//{
//	if (!(mxy == 0)) // 만약 행이 열보다 큰 행렬이었다면
//	{
//		ay = mxy; // mxy에 넣었던 원래 ay의 값을 돌려줌
//	}
//	for (int i = 0; i < ay; i++) // 행
//	{
//		for (int j = 0; j < ax; j++) // 열
//		{
//			printf("%4d", *(*(PA + i) + j)); // 각 행과 열의 원소 출력 // *(*(PA + i) + j) == A[i][j]
//		}
//		printf("\n"); // 한줄 띄움
//	}
//}
//void TransposeMatrix(int(*PA)[10], int ax, int ay) // 행렬의 전치를 위한 함수
//{
//	int M = 0; // 계산을 위해 A의 i행j열의 수를 옮겨 받을 변수 선언
//	for (int i = 0; i < ax; i++) // 행 
//	{
//		for (int j = 0; j < ay; j++) // 열 // 만약 행이 열보다 큰 행렬이라면 크기가 행과 같음
//		{
//			if (i < j) // j가 i보다 클때
//			{
//				M = *(*(PA + i) + j); // A의 i행j열 원소를 M에 저장
//				*(*(PA + i) + j) = *(*(PA + j) + i); // 대각원소를 중심으로 반대의 행,열에 있는 원소를 저장
//				*(*(PA + j) + i) = M; // A의 j행i열에 M이 가진 수 저장
//				// *(*(PA + i) + j) == A[i][j] // *(*(PA + j) + i) == A[j][i]
//			}
//		}
//	}
//}
//
//int main()
//{
//	while (1) // 행의 크기와 열의 크기가 0이면 종료
//	{
//		int A[10][10] = { 0 }; // A행렬 선언
//		int mxy = 0; // 행이 열보다 큰 행렬일 경우 계산을 위한 변수
//		int ax = 0; // A행렬의 행을 받기 위한 변수 선언
//		int ay = 0; // A행렬의 열을 받기 위한 변수 선언 
//
//		printf("행렬의 전치 연산\n"); // 연산의 시작을 알림
//
//		printf("행렬 A의 크기 입력 : "); // A행렬의 크기를 입력받기 위한 문구 출력
//		scanf("%d %d", &ax, &ay); // 각 수를 행과 열 변수에 저장
//		if (ax == 0 || ay == 0) // 만약 그 수들이 0이라면
//		{ 
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//
//		printf("행렬 A 입력\n"); // 행렬의 원소 입력을 알림
//		InputMatrix(A, ax, ay); // 행렬에 원소를 입력하기 위해 InputMatrix 함수 호출
//
//		printf("\n 행렬 전치 전 원소\n"); // 전치 전 원소의 출력을 알리는 문구 출력
//		OutputMatrix1(A, ax, ay); // 전치 전 원소를 출력하기위해 OutputMatrix1 함수 호출
//
//		if (ax > ay) // 만약 행의 크기가 열보다 크다면
//		{
//			mxy = ay; // mxy변수에 원래 열의 크기를 저장
//			ay = ax; // 열의 크기를 행과 같게 만든다
//		}
//		TransposeMatrix(A, ax, ay); // 행렬의 전치를 위해 TransposeMatrix 함수 호출
//
//		printf("\n 행렬 전치 후 원소\n"); // 전치 후 원소의 출력을 알리는 문구 출력 
//		OutputMatrix2(A, ax, ay, mxy); // 전치 후 원소를 출력하기 위해 OutputMatrix2 함수 호출
//
//		printf("\n");
//	}
//}
