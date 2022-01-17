#include <stdio.h>
#pragma warning (disable : 4996)

//1 // 학생의 성적을 계산하는 프로그램
typedef struct s_core // 학생들의 정보를 담을 구조체 선언
{
	char name[3]; // 학생들의 이름
	int korean; // 국어성적
	int english; // 영어성적
	int math; // 수학성적
	int total; // 총점
	double average; // 평균
}Score; // Score라는 새로운 자료형 생성
void InputScore(Score* arr, int n) // 학생들의 정보를 입력받기 위한 함수
{
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 학생 정보 입력\n", i + 1); // 입력 시작
		printf("이름 :"); scanf("%s", &(arr + i)->name); // 입력받은 이름을 자료형이 Score인 arr[i]의 name에 저장
		printf("국어 :"); scanf("%d", &(arr + i)->korean); // 입력받은 국어성적을 자료형이 Score인 arr[i]의 korean에 저장
		printf("영어 :"); scanf("%d", &(arr + i)->english); // 입력받은 영어성적을 자료형이 Score인 arr[i]의 english에 저장
		printf("수학 :"); scanf("%d", &(arr + i)->math); // 입력받은 수학성적을 자료형이 Score인 arr[i]의 math에 저장
		(arr + i)->total = (arr + i)->korean + (arr + i)->english + (arr + i)->math; // arr[i]의 korean과 english와 math를 모두 더한 값을 arr[i]의 total에 저장
		(arr + i)->average = ((double)(arr + i)->total / 3.00); // 세 과목의 평균을 구한 값을 arr[i]의 average에 저장
	}
}
void PrnScore(Score* arr, int n) // 전체 학생들의 성적을 출력하는 함수
{
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 학생 정보 이름 : %s 국어 : %3d 영어 : %3d 수학 : %3d 총점 : %3d 평균 : %.2lf\n", i + 1, (arr + i)->name, (arr + i)->korean, (arr + i)->english, (arr + i)->math, (arr + i)->total, (arr + i)->average);
	    // 세 학생의 정보를 모두 출력
	}
}
int FindScore(Score* arr, char* name, int n) // 원하는 학생의 정보를 출력하는 함수
{
	for (int i = 0; i < n; i++)
	{
		int ret = strcmp((arr + i)->name, name); // 원래 arr에 있는 이름 중 입력받은 name과 같은 이름이 있는지 판단하는 문자열 함수 사용
		// 같으면 ret에 0 저장, 다르면 ret에 0이 아닌 수 저장
		if (ret == 0) // 이름이 같은 게 있다면
		{
			// 그 학생의 정보 출력
			printf("%s 학생 정보 이름 : %s 국어 : %d 영어 : %d 수학 : %d 총점 : %d 평균 : %.2lf\n", (arr + i)->name, (arr + i)->name, (arr + i)->korean, (arr + i)->english, (arr + i)->math, (arr + i)->total, (arr + i)->average);
			return 1; // 1을 내보냄
		}
		else if (ret != 0) // 이름이 같은 게 없다면
		{
			continue; // 다음 인덱스의 이름과 비교
		}
	}
	printf("%s 학생은 없습니다.\n", name); // 같은 이름이 없어 반복문을 빠져나오게 된다면 name과 같은 이름이 없다고 출력
	return -1; // 1을 내보냄
}
int main()
{
	Score arr[3] = { 0 }; // 학생들의 정보를 담을 구조체 배열 arr 선언
	int sel = 0; // 몇 번을 탐색할 것인지 알아낼 변수 선언
	while (1)
	{
		printf("==============================\n"); // 구분선 출력
		printf("1 . 학생 정보 입력\n"); // 1번은 학생의 정보 입력
		printf("2 . 학생 정보 확인\n"); // 2번은 학생의 정보 전체 확인
		printf("3 . 학생 정보 찾기\n"); // 3번은 원하는 학생의 정보 출력
		printf("4 . 종료\n"); // 4번은 프로그램 종료
		printf("==============================\n"); // 구분선 출력
		printf(">> "); // 번호를 받기 위한 구분부호 출력
		scanf("%d", &sel); // 탐색할 번호를 sel에 저장
		if (sel == 1) // sel이 1이라면
		{
			printf("학생 정보 입력\n"); // 학생들의 정보를 입력받기 위한 문구 출력
			InputScore(arr, 3); // InputScore 함수를 이용하여 학생들의 정보를 입력받음
		}
		else if (sel == 2) // sel이 2이라면
		{
			PrnScore(arr, 3); // 모든 학생의 정보를 출력
		}
		else if (sel == 3) // sel이 3이라면
		{
			while (1) // 원하는 학생의 정보 출력
			{
				char name[10] = { 0 }; // 찾고싶은 학생의 이름을 저정할 문자열 배열
				printf("찾고 싶은 학생 이름 :"); // 이름을 입력받은 문구 출력
				scanf("%s", name); // 입력받은 이름을 name에 저장
				int cnt = FindScore(arr, name, 3); // FindScore 함수를 이용하여 입력받은 이름과 원래 arr에 저장되있던 이름들과 같은 것이 있는지 판단하여
				// 같은 게 있다면 그 학생의 정보를 출력하고 cnt에 1을 저장
				// 같은 게 없다면 cnt에 -1을 저장
				if (cnt == 1) // cnt가 1이라면
				{
					break; // while문 빠져나옴
				}
				else if (cnt == -1) // cnt가 -1이라면
				{
					continue; // 찾고 싶은 이름을 다시 입력받으러 while문의 처음으로 돌아감
				}
			}
		}
		else // sel이 1,2,3이 아니라면
		{
			printf("종료\n"); // 프로그램 종료를 알리는 문구 출력
			break; // while문 빠져나옴
		}
	}
	return 0; // main문 종료
}
