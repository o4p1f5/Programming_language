#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
// 힙 영역의 사용

////1 // 두 정수를 더하는 프로그램
//int main()
//{
//	int* pn1 = (int*)calloc(1, sizeof(int)); // 한 정수를 입력받을 int형 공간을 힙영역에 할당하고 그 주소를 pn1에 저장
//	int* pn2 = (int*)calloc(1, sizeof(int)); // 한 정수를 입력받을 int형 공간을 힙영역에 할당하고 그 주소를 pn2에 저장
//	
//	if (!pn1) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // pn1 == 0 이라면 종료
//	}
//	if (!pn2) // // 제대로 할당이 되었는지 확인
//	{
//		return 0; // pn2 == 0 이라면 종료
//	}
//
//	printf("두 정수 입력 :"); // 두 정수를 입력 받기 위한 문구 출력
//	scanf("%d %d", pn1, pn2); // 입력받은 두 수를 힙영역의 공간의 주소를 갖고있는 변수를 이용해 힙 영역의 두 공간에 저장
//
//	printf("%d + %d = %d", *pn1, *pn2, *pn1 + *pn2); // 힙영역의 공간을 가리키고 있는 두 변수를 이용해 각 정수를 출력하고, 그 둘의 덧셈값을 출력
//
//	free(pn1); // 힙영역 해제
//	pn1 = NULL; // pn1을 0으로 초기화
//	free(pn2); // 힙영역 해제
//	pn2 = NULL; // pn2를 0으로 초기화
//	return 0;
//}

////2 // 가변길이 배열
//void InputArr(int * p,int n) // 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < n; i++) // 각 행과 열에 원소를 입력받기 위한 반복문
//	{
//		printf("배열 A[%d] :", i); // 입력을 받기위한 문구 출력
//		scanf("%d", p + i); // 입력받은 수를 p가 가리키는 n칸 짜리 공간에 저장 // p + i == &p[i]
//	}
//}
//void OutputArr(int* p, int n) // 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < n; i++) // 행
//	{
//		printf("%4d", *(p + i)); // *(p + i) == p[i]
//	}
//}
//int main()
//{
//	int* p = (int*)calloc(1, sizeof(int)); // // 정수를 입력받을 int형 공간을 힙영역에 할당하고 그 주소를 p에 저장
//	if (!p) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // p == 0 이라면 종료
//	}
//	int n = 0; // 배열의 크기를 입력받을 변수 선언
//	while (1)
//	{
//		printf("배열의 크기 입력 :"); // 배열의 크기를 입력받기위한 문구 출력
//		scanf("%d", &n); // 입력받은 수를 변수 n에 저장
//		if (n <= 0) // n이 0보다 작거나 같으면 
//		{
//			return 0; // 종료
//		}
//		
//		int* tmp = (int*)realloc(p, n * sizeof(int)); // 메모리 누수 확인을 위해 p에 새로 할당된 공간의 주소를 넣기 전 미리 주소를 받기 위한 변수선언
//		if (p != tmp) // realloc 사용 시 메모리 누수를 방지하기 위한 확인
//		{
//			free(p); // p에 할당되었던 힙영역 공간을 해제하고
//			p = tmp; // tmp에 할당되었던 공간의 주소를 p에 저장
//		}
//
//		printf("배열 A의 크기는 %d\n", n); // 입력받은 배열의 크기가 얼마인지 다시 한번 알리기 위해 출력
//		InputArr(p, n); // 원소를 입력받기 위해 InputArr 함수 사용
//		printf("배열 A의 원소 :\n"); // 출력을 알리는 문구 출력
//		OutputArr(p, n); // 원소를 출력하기 위해 OutputArr 함수 사용
//
//	    free(p); // 힙영역 해제
//	    p = NULL; // p을 0으로 초기화
//		printf("\n");
//	}
//}

////3 // 정수를 입력받아 가장 큰 수와 작은 수를 찾는 프로그램
//void InputArr(int * p,int n) // 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < n; i++) // 각 행과 열에 원소를 입력받기 위한 반복문
//	{
//		printf("배열 [%d] 원소 입력 :", i); // 입력을 받기위한 문구 출력
//		scanf("%d", p + i); // 입력받은 수를 p가 가리키는 n칸 짜리 공간에 저장 // p + i == p[i]
//	}
//}
//void OutputArr(int* p, int n) // 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < n; i++) // 행
//	{
//		printf("%5d", *(p + i)); // *(p + i) == &p[i]
//	}
//	printf("\n");
//}
//int MaxNum(int* p, int n) // 가장 큰 수를 찾는 함수
//{
//	int MAXn = *(p + 0); // 가장 큰 수를 입력받기 위한 정수형 변수 선언
//	for (int i = 0; i < n; i++) // 가장 큰 수를 찾기 위한 반복문
//	{
//		if (*(p + i) > MAXn) // 배열의 i번째 수가 변수 MAXn에 있는 수보다 큰 지 판단 
//		{
//			MAXn = *(p + i); // 크다면 그 수를 변수 MAXn에 저장
//		}
//	}
//	return MAXn; // 함수가 호출이 될 때, MAXn을 출력
//}
//int MinNum(int* p, int n) // 가장 작은 수를 찾는 함수
//{
//	int minn = *(p + 0); // 가장 작은 수를 입력받기 위한 정수형 변수 선언
//	for (int i = 0; i < n; i++) // 가장 작은 수를 알아보기 위한 반복문
//	{
//		if (*(p + i) < minn) // 배열의 i번째 수가 변수 minn에 있는 수보다 작은지 판단
//		{
//			minn = *(p + i); // 작다면 그 수를 변수 minn에 저장
//		}
//	}
//	return minn; // 함수가 호출이 될 때, minn을 출력
//}
//
//int main()
//{
//	int* p = (int*)calloc(1, sizeof(int)); // // 정수를 입력받을 int형 공간을 힙영역에 할당하고 그 주소를 p에 저장
//	if (!p) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // p == 0 이라면 종료
//	}
//	int n = 0; // 배열의 크기를 입력받을 변수 선언
//	while (1)
//	{
//		printf("정수의 수 입력 :"); // 배열의 크기를 입력받기위한 문구 출력
//		scanf("%d", &n); // 입력받은 수를 변수 n에 저장
//		if (n <= 0) // n이 0보다 작거나 같으면 
//		{
//			return 0; // 종료
//		}
//		int* tmp = (int*)realloc(p, n * sizeof(int)); // 메모리 누수 확인을 위해 p에 새로 할당된 공간의 주소를 넣기 전 미리 주소를 받기 위한 변수선언
//		if (p != tmp) // realloc 사용 시 메모리 누수를 방지하기 위한 확인
//		{
//			free(p); // p에 할당되었던 힙영역 공간을 해제하고
//			p = tmp; // tmp에 할당되었던 공간의 주소를 p에 저장
//		}
//		InputArr(p, n); // 원소를 입력받기 위해 InputArr 함수 사용
//		printf("입력된 배열의 원소\n"); // 출력을 알리는 문구 출력
//		OutputArr(p, n); // 원소를 출력하기 위해 OutputArr 함수 사용
//		MaxNum(p, n); // 가장 큰 수를 찾기 위해 MaxNum 함수 이용
//		MinNum(p, n); // 가장 작은 수를 찾기 위해 MinNum 함수 이용
//		printf("가장 큰수 %d", MaxNum(p, n)); // MaxNum(p, n)함수를 이용해 배열 중 가장 큰 수를 출력
//		printf(" 가장 작은 수 %d\n", MinNum(p, n)); // MinNum(p, n)함수를 이용해 배열 중 가장 작은 수를 출력
//	    free(p); // 힙영역 해제
//	    p = NULL; // p을 0으로 초기화
//	}
//}

////4 // 2차원 배열
//void MatrixInput(int** parr,int nx, int ny) // 원소를 입력받기 위한 함수
//{
//	for (int i = 0; i < nx; i++) // 행
//	{
//		for (int j = 0; j < ny; j++) // 열
//		{
//			printf("%d행 %d열 입력 : ", i + 1, j + 1); // 입력을 위한 문구 출력
//			scanf("%d", (*(parr + i) + j)); // (*(parr + i) + j) = &parr
//		}
//	}
//}
//void MatrixOutput(int** pc, int ax, int by) // 원소를 출력하기 위한 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < by; j++) // 열
//		{
//			printf("%5d", *(*(pc + i) + j)); // 각 행과 열의 원소 출력 // *(*(pc + i) + j) == pc[i][j]
//		}
//		printf("\n"); // 한줄 띄움
//	}
//}
//void MatrixMultiply(int** pa, int** pb, int** pc, int ax, int by, int ay) // 행렬의 곱셈 계산 함수
//{
//	for (int i = 0; i < ax; i++) // 행
//	{
//		for (int j = 0; j < by; j++) // 열
//		{
//			for (int k = 0; k < ay; k++) // 앞 행렬의 열과 뒷 행렬의 행
//			{
//				*(*(pc + i) + j) = *(*(pc + i) + j) + *(*(pa + i) + k) * *(*(pb + k) + j); // 계산 된 값을 pc행렬 저장 
//				// *(*(pc + i) + j) == pc[i][j] //  *(*(pa + i) + j) == pa[i][j] //  *(*(pb + i) + j) == pb[i][j]
//			}
//		}
//	}
//}
//int main()
//{
//	int ax = 0; // pa행렬 행
//	int ay = 0; // pa행렬 열
//	int bx = 0; // pb행렬 행
//	int by = 0; // pb행렬 열
//
//	while (1)
//	{
//		printf("A 행렬의 크기 입력 : "); // A행렬의 크기를 받기 위한 문구 출력
//		scanf("%d %d", &ax, &ay); // 입력받은 수를 ax,ay에 저장
//		if (ax <= 0 || ay <= 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		printf("B 행렬의 크기 입력 : "); // B행렬의 크기를 받기 위한 문구 출력
//		scanf("%d %d", &bx, &by); // 입력받은 수를 bx,by에 저장
//		if (bx <= 0 || by <= 0) // 만약 그 수들이 0이라면
//		{
//			printf("종료"); // '종료' 출력 후
//			return 0; // 메인문 종료
//		}
//		if (!(ay == bx)) // 앞행렬의 열 크기와 뒤행렬의 행 크기가 다르면
//		{
//			printf("\n두 행렬을 곱할 수 없습니다.\n"); // 계산을 할 수 없음을 알리는 문구 출력
//			printf("\n");
//			continue; // 다시 행렬의 크기 받으러감
//		}
//		printf("\n"); // 한줄 띄움
//		int** pa = (int**)calloc(ax, sizeof(int*)); // A행렬의 행의 주소를 담을 공간을 힙영역에 할당하고 그 주소를 pa에 저장
//		if (!pa) // 제대로 할당이 되었는지 확인
//		{
//			return 0; // pa == 0 이라면 종료
//		}
//		for (int i = 0; i < ax; i++) // 행의 주소를 담은 공간에
//		{
//			*(pa + i) = (int*)calloc(ay, sizeof(int)); // 입력받은 열의 크기에 따라 힙영역에 공간할당 후 저장
//		}
//
//		int** pb = (int**)calloc(bx, sizeof(int*)); // B행렬의 행의 주소를 담을 공간을 힙영역에 할당하고 그 주소를 pb에 저장
//		if (!pb) // 제대로 할당이 되었는지 확인
//		{
//			return 0; // pb == 0 이라면 종료
//		}
//		for (int i = 0; i < bx; i++) // 행의 주소를 담은 공간에
//		{
//			*(pb + i) = (int*)calloc(by, sizeof(int)); // 입력받은 열의 크기에 따라 힙영역에 공간할당 후 저장
//		}
//
//		int** pc = (int**)calloc(ax, sizeof(int*)); // C행렬의 행의 주소를 담을 공간을 힙영역에 할당하고 그 주소를 pc에 저장
//		if (!pc) // 제대로 할당이 되었는지 확인
//		{
//			return 0; // pc == 0 이라면 종료
//		}
//		for (int i = 0; i < ax; i++) // 행의 주소를 담은 공간에
//		{
//			*(pc + i) = (int*)calloc(by, sizeof(int)); // B행렬의 열의 크기에 따라 힙영역에 공간할당 후 저장
//		}
//		printf("A 행렬 입력\n"); // A행렬의 원소를 입력받기 위한 문구 출력
//		MatrixInput(pa, ax, ay); // 원소를 입력받기 위해 MatrixInput 함수 사용
//		printf("\n"); // 한줄 띄움
//		printf("B 행렬 입력\n"); // B행렬의 원소를 입력받기 위한 문구 출력
//		MatrixInput(pb, bx, by); // 원소를 입력받기 위해 MatrixInput 함수 사용
//		MatrixMultiply(pa, pb, pc, ax, by, ay); // 행렬의 곱셈을 위해 MatrixMultiply 함수 사용
//		printf("\n두 행렬의 곱셈 결과\n"); // 곱셈 결과 출력을 알리는 문구 출력
//		MatrixOutput(pc, ax, by); // 곱셈 결과 출력을 위해 MatrixOutput 함수 호출
//
//		for (int i = 0; i < ax; i++)
//		{
//			free(pa[i]); // A행렬의 열 공간 해제
//		}	
//		free(pa); // 힙영역 해제
//		pa = NULL; // pa을 0으로 초기화
//		for (int i = 0; i < bx; i++)
//		{
//			free(pb[i]); // B행렬의 열 공간 해제
//		}
//		free(pb); // 힙영역 해제
//		pb = NULL; // pb을 0으로 초기화
//		for (int i = 0; i < ax; i++)
//		{
//			free(pc[i]); // C행렬의 열 공간 해제
//		}
//		free(pc); // 힙영역 해제
//		pc = NULL; // pc을 0으로 초기화
//		printf("\n");
//	}
//	return 0;
//}

//5 // n X n 행렬의 역행렬 계산
void MatrixInput(double ** parr,int nx, int ny) // 원소를 입력받기 위한 함수
{
	for (int i = 0; i < nx; i++) // 행
	{
		for (int j = 0; j < ny; j++) // 열
		{
			printf("A[%d][%d] : ", i + 1, j + 1); // 원소를 입력받기 위한 문구 출력
			scanf("%lf", (*(parr + i) + j)); // (*(parr + i) + j) = &parr[i][j]
		}
	}
}
void MatrixOutput(double**parr, int nx, int ny) // 원소를 출력하기 위한 함수
{
	for (int i = 0; i < nx; i++) // 행
	{
		for (int j = 0; j < ny; j++) // 열
		{
			printf("%10.4lf", *(*(parr + i) + j)); // 각 행과 열의 원소 출력 // *(*(pc + i) + j) == pc[i][j]
		}
		printf("\n"); // 한줄 띄움
	}
}
void IdentityMatrix(double**parr, int nx) // n X n 에 따라 단위행렬
{
	for (int i = 0; i < nx; i++) // 행
	{
		for (int j = 0; j < nx; j++) // 열
		{
			if (i != j) // i,j가 다르면
				*(*(parr + i) + j) = 0; // 0 
			else
				*(*(parr + i) + j) = 1; // 대각원소면 1
		}
	}
}
void InverseMatrix(double** A, double** InvA, int n) // 행렬의 역행렬 계산
{
	for (int i = 0; i < n; i++) // n X n
	{
		double den = A[i][i]; // A행렬의 대각원소를 den에 저장
		for (int j = 0; j < n; j++) // 그 den으로 각 열에 나눠줌
		{
			A[i][j] /= den; // A행렬의 i행 j열을 den으로 나눔
			InvA[i][j] /= den; // InvA행렬의 i행 j열을 den으로 나눔
		}

		for (int j = 0; j < n; j++)
		{
			if (i == j) // 대각원소는 계산 X
				continue; // for문 다시 시작
			double mul = A[j][i]; // j가 i보다 큰 원소를 mul에 저장
			for (int k = 0; k < n; k++)
			{
				A[j][k] = A[i][k] * (-mul) + A[j][k]; // A행렬의 나머지 행을 정리함
				InvA[j][k] = InvA[i][k] * (-mul) + InvA[j][k]; // InvA행렬의 나머지 행을 정리함
			}
		}
	}
}
int main()
{
	while (1)
	{
		int nx = 0; // 정방행렬의 n크기를 받기 위한 변수 선언
		printf("정방 행렬의 크기 입력 : "); // 정방행렬의 크기를 입력받기 위한 문구 출력
		scanf("%d", &nx); // 입력받은 수를 nx에 저장
		if (nx <= 0) // 만약 그 수들이 0이나 음수라면
		{
			printf("종료"); // '종료' 출력 후
			return 0; // 메인문 종료
		}
		double** A = (double**)calloc(nx, sizeof(double*)); // 정방행렬의 행의 주소를 담을 공간을 힙영역에 할당하고 그 주소를 A에 저장
		if (!A) // 제대로 할당이 되었는지 확인
		{
			return 0; // pa == 0 이라면 종료
		}
		for (int i = 0; i < nx; i++) // 행의 주소를 담은 공간에
		{
			*(A + i) = (double*)calloc(nx, sizeof(double)); // A행렬의 열의 크기에 따라 힙영역에 공간할당 후 저장
		}
		double** InvA = (double**)calloc(nx, sizeof(double*)); // 정방행렬의 행의 주소를 담을 공간을 힙영역에 할당하고 그 주소를 InvA에 저장
		if (!A) // 제대로 할당이 되었는지 확인
		if (!InvA) // 제대로 할당이 되었는지 확인
		{
			return 0; // pa == 0 이라면 종료
		}
		for (int i = 0; i < nx; i++) // 행의 주소를 담은 공간에
		{
			*(InvA + i) = (double*)calloc(nx, sizeof(double)); // InvA행렬의 열의 크기에 따라 힙영역에 공간할당 후 저장
		}
		printf("행렬의 원소 입력\n"); // 정방행렬의 원소를 입력받기 위한 문구 출력
		MatrixInput(A, nx, nx); // 정방행렬에 원소를 입력받기 위해 MatrixInput 함수 사용
		IdentityMatrix(InvA, nx); // 단위행렬을 만들기 위해 IdentityMatrix 함수 사용
		printf("행렬 A의 원소 출력\n"); // 정방행렬의 원소를 출력하기 위한 문구 출력
		MatrixOutput(A, nx, nx); // 입력 결과 출력을 위해 MatrixOutput 함수 호출
		InverseMatrix(A,InvA,nx); // 역행렬 계산응 위해 InverseMatrix 함수 사용
		printf("행렬의 원소 출력\n"); // 역행렬 계산 결과 출력을 알리는 문구 출력
		MatrixOutput(InvA, nx, nx); // 역행렬 계산 결과 출력을 위해 MatrixOutput 함수 호출

		for (int i = 0; i < nx; i++)
		{
			free(*(A + i)); // A행렬의 열 공간 해제
		}	
		free(A); // 힙영역 해제
		A = NULL; // A를 0으로 초기화
	}
	return 0;
}
