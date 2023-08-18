#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

////1 // 배열 중 각 정수가 몇개씩 있는지 판단하는 프로그램
//int main() // 메인함수 선언
//{
//	int num[20] = { 1, 2, 3, 4, 5, 0, 2, 4, 7, 8, 6, 8, 3, 6, 9, 3, 2, 5, 3, 8 }; // 배열 num을 '1, 2, 3, 4, 5, 0, 2, 4, 7, 8, 6, 8, 3, 6, 9, 3, 2, 5, 3, 8'로 초기화 
//	int count[20] = { 0 }; // 판단된 수를 저장하게 될 배열 count의 수를 0으로 초기화
//	for (int n = 0; n < sizeof(num) / sizeof(int); n++) // 각 정수가 몇개씩 있는지 판단하는 프로그램
//	{
//		count[num[n]]++; // 배열 num의 n번째 인덱스에 있는 수를 배열 count의 인덱스번호로 해서 count의 각 정수를 증가시킴
//	}
//	for (int i = 0; i < 10; i++) // 배열 count의 수를 차례대로 출력 
//	{
//		printf("숫자 %d는 %d개\n", i, count[i]); // %d에 i와 count i번째 인덱스의 수를 대입 후 출력
//	}
//	return 0; // 메인함수 종료
//}

////2 // 배열 num[10]의 원소 중 0이 아닌 원소가 무엇인지 알아내는 프로그램
//int main() // 메인함수 선언
//{
//	int num[10] = { 2, 0, 5, 9, 0, 1, 4, 3, 0, 0 }; // // 배열 num을 '2, 0, 5, 9, 0, 1, 4, 3, 0, 0'로 초기화 
//	int cnt = 0; // 0이 아닌 원소가 몇개인지 세기 위한 변수 cnt 선언
//
//	for (int i = 0; i < 10; i++) // 배열에 0이 아닌 원소가 몇개인지 판단하기위한 반복문
//	{
//		if (!(0 == num[i])) // 배열 num의 i번째 인덱스가 0과 같지 않다면 
//		{
//			cnt++; // cnt에 1 더함
//		}
//	}
//	printf("배열 num[10]의 원소 중 0이 아닌 원소는 %d 개 입니다.\n",cnt); // %d에 cnt의 값을 대입한 후 문구를 출력
//	printf("0이 아닌 원소는 인덱스는 다음과 같습니다.\n"); // '0이 아닌 원소는 인덱스는 다음과 같습니다.'을 출력 후 줄을 바꿈
//
//	for (int i = 0; i < 10; i++) // 배열에 0이 아닌 원소를 판단하기위한 반복문
//	{
//		if (!(0 == num[i])) // 배열 num의 i번째 인덱스가 0과 같지 않다면 
//		{
//			printf("num[%d]   ", i); // 그 i를 출력
//		}
//	}
//	return 0; // 메인함수 종료 
//}

////3 // 원하는 숫자를 입력하여 그 숫자가 배열의 몇번째 요소인지 찾아주는 프로그램
//int main() // 메인함수 선언
//{
//	while (1) // break를 만나기 전까지 무한 반복
//	{
//		int num[10] = { 1 , 5, 9 , 4 , 3, 8, 2, 7, 6, 0 }; // 배열 num을 '1 , 5, 9 , 4 , 3, 8, 2, 7, 6, 0'로 초기화 
//		int n = 0; // 프로그래머가 입력한 수를 받을 변수 n 선언
//		printf("원하는 숫자 입력(0~9) :"); // '원하는 숫자 입력(0~9) :'출력
//		scanf("%d", &n); // 입력한 수를 변수 n에 대입
//
//		if (n < 0) // n이 음수라면
//		{
//			printf("찾는 숫자가 없습니다."); // '찾는 숫자가 없습니다.' 출력
//			break; // while문 종료
//		}
//
//	    for (int i = 0; i < 10; i++)
//		{
//			if (n == num[i])
//			{
//				printf("숫자 %d는 배열의 %d번째 요소에 있습니다.\n", n, i+1);
//			}
// 		}
//		continue;
//	}
//  return 0;
//}

////4 // 성적처리함수
//int main() // 메인함수 선언
//{
//	int num[3] = { 0 }; // 학번을 받을 배열 num을 3 크기만큼 선언
//	int language[3] = { 0 }; // 국어 점수를 받을 배열 language를 3크기만큼 선언 
//	int english[3] = { 0 }; // 영어 점수를 받을 배열 english를 3크기만큼 선언 
//	int math[3] = { 0 }; // 수학 점수를 받을 배열 math를 3크기만큼 선언
//	int total[3] = { 0 }; // 한사람의 국어,영어,수학 점수를 다 더한 총점을 받을 배열 total을 3만큼 선언
//	double average[3] = { 0 }; // 한사람의 총점을 3으로 나눈 값을 받을 배열 average를 3만큼 선언
//	int languageTotal = 0; // 세사람의 국어 총점을 담을 변수 languageTotal 선언
//    int englishTotal = 0; // 세사람의 영어 총점을 담을 변수 englishTotal 선언
//    int mathTotal = 0; // 세사람의 수학 총점을 담을 변수 mathTotal 선언
//
//	for (int i = 0; i < 3; i++) // 배열들에 값을 입력하는 반복문
//	{
//		printf("학번 국어 영어 수학 :"); // '학번 국어 영어 수학 :' 출력
//		scanf("%d %d %d %d", &num[i], &language[i], &english[i], &math[i]); // 프로그래머가 입력하는 수를 차례로 배열 num, language, english, math의 i번째 인덱스에 저장 
//	}
//	printf("\n학번   국어   영어   수학   총점   평균\n"); // 줄 바꾸고 '학번   국어   영어   수학   총점   평균' 출력 후 줄 바꿈
//
//	for (int i = 0; i < 3; i++) // 세사람의 총점과 평균을 구하기 위한 반복문
//	{
//		total[i] = language[i] + english[i] + math[i]; // language, english, math 배열의 i 번째 인덱스의 수를 다 더해서 total 배열의 i 번째 인덱스에 저장
// 		average[i] = (double)total[i] / 3; // 배열 total의 i 번째 인덱스의 값을 double로 강제형변환 시킨 후 3으로 나눈 값을 배열 average의 i 번째 인덱스에 저장
//
//		printf("%3d   %4d   %4d   %4d   %4d   %5.1lf\n", num[i], language[i], english[i], math[i], total[i], average[i]); // 모든 배열의 i번째 인덱스의 값들을 차례대로 출력
//		// 보기 좋음을 위해 %d에 출력을 바꿔주는 조합들을 추가
//	}
//	printf("\n과목별 총점 및 평균\n"); // 줄 바꾸고 '과목별 총점 및 평균'을 출력 후 줄 바꿈
//
//	for (int i = 0; i < 3; i++) // 모든 국어 점수의 총점을 구하는 반복문
//	{
//		languageTotal += language[i]; // 배열 language의 i번째 인덱스 값을 languageTotal 변수에 차례로 더함
//	}
//	printf(" 국어 총점 : %d 평균 : %.1lf\n", languageTotal, (double)languageTotal / 3); // 변수 languageTotal과 변수를 double로 강제형변환 후 3으로 나눈 값을 차례대로 %d에 대입하며 문구와 함께 출력 
//
//	for (int i = 0; i < 3; i++) // 모든 영어 점수의 총점을 구하는 반복문
//	{
//		englishTotal += english[i]; // 배열 english의 i번째 인덱스 값을 englishTotal 변수에 차례로 더함
//	}
//	printf(" 영어 총점 : %d 평균 : %.1lf\n", englishTotal, (double)englishTotal / 3); // 변수 englishTotal과 변수를 double로 강제형변환 후 3으로 나눈 값을 차례대로 %d에 대입하며 문구와 함께 출력 
//
//	for (int i = 0; i < 3; i++) // 모든 수학 점수의 총점을 구하는 반복문
//	{
//		mathTotal += math[i]; // 배열 math의 i번째 인덱스 값을 mathTotal 변수에 차례로 더함
//	}
//    printf(" 수학 총점 : %d 평균 : %.1lf\n", mathTotal, (double)mathTotal / 3); // 변수 mathTotal과 변수를 double로 강제형변환 후 3으로 나눈 값을 차례대로 %d에 대입하며 문구와 함께 출력 
//
//	return 0; // 메인 함수 종료
//}

////5 // 로또번호추첨
//int main() // 메인함수 선언
//{
//	printf("로또 번호\n"); // '로또번호' 띄우기
//	int rotto[7] = { 0 }; // 로또번호를 담을 배열 rotto를 크기 7만큼 선언
//	int num = 0; // 뽑힌 난수를 저장하는 변수 num 선언
//	int cnt = 0; // while문을 빠져나오기 위해 배열에 수가 몇 개 들어가는 지 알려주는 변수 cnt 선언
//	int m = 0; // 뽑힌 번호가 중복될때 다시 난수를 뽑기 위해 구분해주는 변수 m 선언
//
//	while (1)
//	{
//		int m = 0; // 변수 m의 값을 0으로 초기화
//
//		//난수뽑기
//		srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
//		num = rand() % 45 + 1; // 1 ~ 45 중 뽑힌 난수를 num에 저장
//
//		//중복된 수 찾기
//		for (int i = 0; i < 7; i++) // num의 수가 rotto 배열에 있는 수와 중복되는 게 있는지 일일히 비교하는 반복문
//		{
//			if (rotto[i] == num) // 만약 rotto 배열의 i번째에 저장된 수가 num과 같은 경우
//			{
//				m++; // m에 1을 더함 // 나중에 구분을 위해 변수의 값을 변경시킴
//				break; // for문을 빠져나옴
//			}
//		}
//		// 만약 rotto 배열의 i번째에 저장된 수가 num과 같아서 m의 값이 1 증가 했다면 다시 난수를 뽑으러 가야하기 때문에 구분을 위한 if문을 적어줌 
//		if (m == 0) // m의 값이 0이라면 // = num의 값이 rotto에 들어있는 값과 모두 다르다면
//		{
//			rotto[cnt] = num; // 그 num의 값을 rotto[cnt]에 넣어줌.
//			cnt++; // 난수가 들어갈 배열의 인덱스가 1씩 커져야하기때문에 cnt에 1을 더해줌.
//			// 그러면 배열에 중복되지 않은 난수가 차례대로 들어가게 됨.
//			// 이렇게 cnt의 값을 증가시켜 배열 안에 수가 다 들어가 있음을 판단하기 위함도 있음.
//		}
//
//		//while문 빠지기
//		if (cnt == 7) // 뽑힌 난수가 7개라면 // 배열에 모든 수가 들어갔다면
//		{
//			for (int i = 0; i < 7; i++) // 배열의 수를 차례대로 출력하기 위한 for문
//			{
//				if (i == 6) // 보너스 번호를 뽑기위한 조건문
//				{
//					printf("\n보너스 번호\n"); // '보너스 번호' 출력
//					printf("%d", rotto[6]); // 배열의 6번째 수를 출력한다.
//				}
//				else // 인덱스 번호가 0 ~ 5라면 
//				{
//					printf("%d\t", rotto[i]); // 배열을 차례대로 출력
//				}
//			}
//			break; // while문 빠지기
//		}
//    }
//	return 0; // 메인함수 종료
//}
