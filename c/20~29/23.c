#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable : 4996)
// 문자열관련함수
// 동적할당

////1 // 문자열의 개수 판단 프로그램
//int main()
//{
//	char* str = (char*)calloc(50,sizeof(char)); // 문자열을 받을 배열을 힙영역에 할당하고 그 공간의 시작주소를 str에 저장
//	if (!str) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str == 0 이라면 종료
//	}
//
//	puts("문자열 입력 :"); // 문자열 입력을 알리는 문자열 출력
//	gets(str); // 문자열을 입력받아 str이 가리키는 힙영역의 공간에 저장
//	int n = strlen(str); // 문자열의 개수를 판단하는 함수를 사용하여 그 개수를 변수 n에 저장
//	char* cstr = (char*)calloc(50, sizeof(char)); // sprintf 사용을 위한 공간을 힙영역 할당하고 그 주소를 cstr에 저장
//	if (!cstr) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // cstr == 0 이라면 종료
//	}
//	sprintf(cstr, "입력된 문자열 : %s의 글자의 수는 %d", str, n); // sprintf를 이용해서 출력해야될 문자열을 cstr에 저장
//	puts(cstr); // cstr의 문자열 출력
//
//	free(str); // 힙영역 해제
//	str = NULL; // str을 0으로 초기화
//	free(cstr); // 힙영역 해제
//	cstr = NULL; // cstr을 0으로 초기화
//}

////2 두 문자열이 같은지 비교하는 프로그램
//int main()
//{
//	char* str1 = (char*)calloc(50,sizeof(char)); // 첫번째 문자열을 받기 위한 배열을 힙영역에 할당하고 그 공간의 시작주소를 str1에 저장
//	char* str2 = (char*)calloc(50,sizeof(char)); // 두번째 문자열을 받기 위한 배열을 힙영역에 할당하고 그 공간의 시작주소를 str2에 저장
//	if (!str1) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str1 == 0 이라면 종료
//	}
//	if (!str2) // // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str2 == 0 이라면 종료
//	}
//
//	puts("첫번째 문자열 입력 : "); // 첫번째 문자열 입력을 알리는 문자열 출력
//	gets(str1); // 입력받은 문자열을 str1일 가리키는 힙영역 공간에 저장
//	puts("두번째 문자열 입력 : "); // 두번째 문자열 입력을 알리는 문자열 출력
//	gets(str2); // 입력받은 문자열을 str2일 가리키는 힙영역 공간에 저장
//	int ret = strcmp(str1, str2); // str1이 가리키는 문자열과 str2가 가리키는 문자열이 같은지 판단하는 함수 사용
//	if (ret == 0) // 같다면 ret에 0이 저장됨
//		puts("두 문자열은 같습니다."); // 같다는 문자열 출력
//	else // 틀리다면 양수가 음수가 저장됨
//		puts("두 문자열은 다릅니다."); // 다르다는 문자열 출력
//
//	free(str1); // 힙영역 해제
//	str1 = NULL; // str1을 0으로 초기화
//	free(str2); // 힙영역 해제
//	str2 = NULL; // str2을 0으로 초기화
//}

////3 문자열을 입력받아 소문자를 대문자로 대문자를 소문자로 변경하는 프로그램
//int main()
//{
//	char* str1 = (char*)calloc(50, sizeof(char)); // 문자열을 받기 위한 배열을 힙영역에 할당하고 그 공간의 시작주소를 str1에 저장
//	
//	if (!str1) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str1 == 0 이라면 종료
//	}
//
//	puts("문자열 입력 : "); // 문자열 입력을 알리는 문자열 출력
//	gets(str1); // 입력받은 문자열을 str1이 가리키는 힙영역 공간에 저장
//	
//	puts("변경전"); // '변경전' 출력
//	puts(str1); // 문자열을 출력
//
//	int len = strlen(str1); // 문자열 저장
//	for (int i = 0; i < len ;i++) // 소대문자 판단
//	{
//		int n = str1[i]; // int형 변수에 str1의 i번째 원소를 저장
//		if (islower(n)) // 그 원소가 소문자라면
//		{
//			str1[i] -= 32; // 32를 빼서 아스키코드값을 대문자로 바꾼다
//		}
//		else if (isupper(n)) // 그 원소가 대문자라면
//		{
//			str1[i] += 32; // 32를 더해서 아스키코드값을 소문자로 바꾼다
//		}
//	}
//	puts("변경후"); // '변경후' 출력
//	puts(str1); // 문자열을 출력
//
//	free(str1); // 힙영역 해제
//	str1 = NULL; // str1을 0으로 초기화
//}

////4 // 비밀번호를 저장하고 확인할 수 있는 프로그램
//int main()
//{
//	char* str1 = (char*)calloc(50, sizeof(char)); // 비밀번호 셋팅을 위한 배열을 힙영역에 할당하고 그 공간의 시작주소를 str1에 저장
//	char* str2 = (char*)calloc(50, sizeof(char)); // 비밀번호 확인을 위한 배열을 힙영역에 할당하고 그 공간의 시작주소를 str2에 저장
//	char* cstr = (char*)calloc(50, sizeof(char)); // sprintf 사용을 위한 공간을 힙영역 할당하고 그 주소를 cstr에 저장
//	char* n = (char*)calloc(50, sizeof(char)); // 메뉴 중 몇번을 택할것인지 받는 공간을 힙영역에 할당하고 그 주소를 n에 저장
//	int cnt = 0; // 비밀번호 확인에서 쓰일 변수
//	if (!str1) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str1 == 0 이라면 종료
//	}
//	if (!str2) // // 제대로 할당이 되었는지 확인
//	{
//		return 0; // str2 == 0 이라면 종료
//	}
//	if (!cstr) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // cstr == 0 이라면 종료
//	}
//	if (!n) // 제대로 할당이 되었는지 확인
//	{
//		return 0; // n == 0 이라면 종료
//	}
//	while (1)
//	{ 
//		printf("======================================\n\t\tMENU\n======================================"); // 메뉴의 시작을 알림
//		puts("\n 1. 비밀번호 셋팅"); // 1번이 비밀번호 셋팅임을 알리는 문자열 출력
//		puts(" 2. 비밀번호 확인"); // 2번이 비밀번호 확인임을 알리는 문자열 출력
//		puts(" 3. 프로그램 종료\n>>"); // 3번이 프로그램 종료임을 알리는 문구 출력
//		gets(n); // 입력받은 수를 n이 가리키는 공간에 저장
//		if (!strcmp(n,"1")) // 1번을 선택한 경우
//		{
//			puts("새로운 비밀번호를 입력 :"); // 새로운비밀번호 입력을 알리는 문자열 출력
//			gets(str1); // 입력받은 문자열(비밀번호)를 str1이 가리키는 공간에 저장
//			int num = strlen(str1); // 비밀번호의 길이를 받기 위한 변수
//			sprintf(cstr, "비밀번호는 %d자리로 변경되었습니다",num); // sprintf를 이용해서 출력해야될 문자열을 cstr에 저장
//	        puts(cstr); // cstr의 문자열 출력
//		}
//		else if (!strcmp(n, "2")) // 2번을 선택한 경우
//		{
//			while (1) // 비밀번호를 틀려도 다시 입력받을 수 있게 무한반복
//			{
//				puts("비밀번호를 입력 :"); // 입력을 알리는 문자열 출력
//				if (cnt == 0) // 비밀번호입력을 처음받는거라면
//				 	getchar(str1); // puts에서 자동으로 입력되는 \n때문에 입력이 그냥 넘어가는것을 방지하기 위해 getchar함수를 씀
//				gets(str2); // 입력받은 문자열을 str2이 가리키는 공간에 저장
//				int ret = strcmp(str1, str2); // 두 문자열이 같은지 비교
//				if (ret == 0) // 같다면 0이 ret에 저장
//				{
//					puts("비밀번호가 맞습니다."); // 맞음을 알리는 문자열 출력
//					break; // while문을 빠져나옴
//				}
//				else // 다르다면 양수나 음수가 ret에 저장
//				{
//					puts("틀렸습니다. 다시 입력하세요."); // 틀림을 알리는 문자열 출력
//					cnt++; // 비밀번호를 다시 입력받을 땐 gets가 하나여도 되기때문에 하나를 없애준다
//					continue; // while문 처음으로 돌아감
//				}
//			}
//		}
//		else // 3번을 선택한 경우
//		{
//			puts("프로그램 종료"); // 프로그램 종료를 알리는 문구 출력
//			free(str1); // 힙영역 해제
//			str1 = NULL; // str1을 0으로 초기화
//			free(str2); // 힙영역 해제
//			str2 = NULL; // str2을 0으로 초기화
//			return 0;
//		}
//	}
//}