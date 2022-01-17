#include <iostream>
#include <cstring> // char 형 배열의 문자열을 다루기위한 함수 제공
#include <string> // string형 객체를 다루기 위한 클래스틀 선언
#pragma warning (disable : 4996)
using namespace std;

////3 // 두 개의 정수 중 큰 수 출력
//int main()
//{
//	int a(0); // 한 정수를 입력받을 변수 선언
//	int b(0); // 한 정수를 입력받은 변수 선언
//	cout << "두 수를 입력하라>>"; // 두 수를 입력받을 문구 출력
//	cin >> a >> b; // 입력받은 수를 차례대로 변수에 저장
//	if (a > b) // a가 b보다 크다면
//	{
//		cout << "큰 수 = " << a; // "큰 수 = (a에 들어있는 정수)" 출력
//	}
//	else // 아니라면
//		cout << "큰 수 = " << b; // "큰 수 = (b에 들어있는 정수)" 출력
//
//	return 0;
//}

////4 // 소수점을 가지는 5개의 실수를 입력받아 제일 큰 수 출력
//int main()
//{
//	double str[5]{0}; // 5개의 실수를 입력받을 배열 선언
//	cout << "5 개의 실수를 입력하라>>"; // 실수를 입력받을 문구 출력
//	for (int i = 0; i < 5; i++) // 실수를 입력받기 위한 반복문
//	{
//		cin >> str[i]; // 입력된 실수를 차례대로 배열에 저장
//	}
//	double a(str[0]); // 실수형 변수 a를 배열의 1번째 원소로 초기화
//	for (int i = 0; i < 5; i++) // 가장 큰 수를 찾기 위한 반복문
//	{
//		if (a < str[i]) // 현재 a의 값보다 str[i] 원소가 크다면
//		{
//			a = str[i]; // a에 str[i]의 값을 저장
//		}
//	}
//
// // 다른 방식 반복문
// double a(str[0]);
// for (int i = 0; i < 5; i++) // 실수를 입력받기 위한 반복문
//	{
//		cin >> str[i]; // 입력된 실수를 차례대로 배열에 저장
//       if (a < str[i]) // 현재 a의 값보다 str[i] 원소가 크다면
//		{
//			a = str[i]; // a에 str[i]의 값을 저장
//		}
//	}
//
//	cout << "제일 큰 수 = " << a; // a에 저장된 제일 큰 수 출력
//	return 0;
//}

////5-1 // char형 배열 // 입력된 문자열 중 x의 개수를 세는 코드
//int main()
//{
//	char str[100] = { 0 }; // 문자열을 입력받을 char형 배열 선언
//	int cnt = 0; // x의 개수를 셀 변수 선언
//
//	cout << "문자들을 입력하라(100개 미만)." << endl; // 문자열을 입력받기위한 문구 출력
//	cin.getline(str, 100, '\n'); // 입력받은 문자열을 str배열에 저장하고 구분자를 \n로 설정
//
//	for (int i = 0; i < (int)strlen(str); i++) // 입력받은 문자열에 x가 몇개 있는지 판단하는 반복문
//	{
//		if (str[i] == 'x') // 배열 원소가 x일 때 마다
//			cnt++; // cnt의 수 up
//	}
//
//	cout << "x의 개수는 " << cnt << endl; // x의 개수가 몇개인지 출력
//	return 0;
//}

//// 5-2 // string // 입력된 문자열 중 x의 개수를 세는 코드
//int main()
//{
//	string str; // string 배열 선언
//	int cnt = 0; // x의 개수를 셀 변수 선언
//
//	cout << "문자들을 입력하라(100개 미만)." << endl; // 문자열을 입력받기 위한 문구 출력
//	getline(cin, str, '\n'); // cin버퍼에 입력받은 문자열을 str배열에 저장, 구분자를 \n으로 설정
//	for (int i = 0; i < (int)str.size(); i++) // 입력받은 문자열에 x가 몇개 있는지 판단하는 반복문
//	{
//		if (str[i] == 'x') // 배열 원소가 x일 때 마다
//			cnt++; // cnt의 수 up
//	}
//	cout << "x의 개수는 " << cnt << endl; // x의 개수가 몇개인지 출력
//	return 0;
//}

//// 7-1 // char배열 // "yes"가 입력될 때까지 종료하지 않는 프로그램
//int main()
//{
//	char str[100] = { 0 }; // 문자열을 입력받을 char배열 선언
//	while (true) // 무한 반복문
//	{
//		cout << "종료하고싶으면 yes를 입력하세요>>"; // 문자열을 입력받을 문구 출력
//		cin.getline(str, 100, '\n'); // 입력받은 문자열을 str에 저장, 구분자를 \n로 설정
//		if (!strcmp(str, "yes")) // 입력받은 문자열과 "yes" 가 같다면 0출력, 조건문에 !가 붙었기때문에 true로 취급
//		{
//			cout << "종료합니다..."; // 같다면 종료합니다... 출력 후 while문을 빠져나옴
//			break;
//		}
//	}
//	return 0;
//}

//// 7-2 // string // "yes"가 입력될 때까지 종료하지 않는 프로그램
//int main()
//{
//	string str; // 문자열을 입력받을 string 배열 선언
//	while (true) // 무한 반복문
//	{
//		cout << "종료하고싶으면 yes를 입력하세요>>"; // 문자열을 입력받을 문구 출력
//		getline(cin, str, '\n'); // cin버퍼에 입력된 문자열을 str에 저장, 구분자를 \n로 설정
//		if (str == "yes") // 입력받은 문자열과 "yes" 가 같다면
//		{
//			cout << "종료합니다..."; // 종료합니다... 출력 후 while 문 빠져나옴
//			break;
//		}
//	}
//	return 0;
//}

//// 8-1 // char배열 // 가장 긴 이름 판별
//int main()
//{
//	char str1[100] = { 0 }; // 이름들을 입력받을 문자열 선언
//	char str2[100] = { 0 }; // 가장 긴 이름을 저장할 배열 선언
//
//	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
//	// 5명의 이름을 입력받을 문구 출력
//
//	for (int i = 0; i < 5; i++) // 5명의 이름을 입력받고 가장 긴 이름을 찾아낼 반복문
//	{
//		cin.getline(str1, 100, ';'); // 입력받은 문자열을 차례대로 str1에 저장, 구분자는 ;
//		if (strlen(str1) > strlen(str2)) // str1의 길이와 str2의 길이를 비교한 후 str1의 길이가 길다면
//		{
//			strcpy(str2, str1); // str1의 문자열을 str2에 저장
//		}
//		cout << i + 1 << " : " << str1 << endl; // 입력받은 이름들을 출력
//	}
//  // 다른 방법
//  int max_len = 0;
//  for (int i = 0; i < 5; i++)
//  {
//	    cin.getline(str1, 100, ';');
//	    int len = (int)strlen(str1);
//	    if (max_len < len)
//	    {
//		    max_len = len;
//		    strcpy(str2, str1);
//	    }
//  }
//	cout << "가장 긴 이름은 " << str2; // 가장 긴 이름을 출력
//}

//// 8-2 // string // 가장 긴 이름 판별
//int main()
//{
//	string str1; // 이름들을 입력받을 문자열 선언
//	string str2; // 가장 긴 이름을 저장할 배열 선언
//
//	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
//	// 5명의 이름을 입력받을 문구 출력
//
//	for (int i = 0; i < 5; i++) // 5명의 이름을 입력받고 가장 긴 이름을 찾아낼 반복문
//	{
//		getline(cin, str1, ';'); // cin버퍼에 입력된 문자열을 str1에 저장, 구분자는 ;
//		if (str1.size() > str2.size()) // str1의 길이와 str2의 길이를 비교한 후 str1의 길이가 길다면
//		{
//			str2 = str1; // str1의 문자열을 str2에 저장
//		}
//		cout << i + 1 << " : " << str1 << endl; // 입력받은 이름들을 출력
//	} 
//  int max_len = 0;
//  for (int i = 0; i < 5; i++)
//  {
//	    getline(cin, str1, ';');
//	    int len = (int)str1.size();
//	    if (max_len < len)
//	    {
//		    max_len = len;
//		    str2 = str1;
//	    }
//  }
//	cout << "가장 긴 이름은 " << str2; // 가장 긴 이름을 출력
//}

//// 10-1 // char배열 // 입력받은 문자열의 부분 문자열을 차례대로 출력
//int main()
//{
//	char str[100] = { 0 }; // 문자열을 입력받을 배열 선언
//	cout << "문자열 입력>>"; // 문자열을 입력받을 문구 출력
//	cin.getline(str, 10, '\n'); // 입력된 문자열을 str에 저장, 구분자는 \n
//
//	for (int i = 0; i < (int)strlen(str); i++) // 입력받은 문자열의 부분문자열들을 순서대로 출력
//	{
//		for (int j = 0; j <= i; j++) // i가 증가할때마다 출력되는 부분배열 증가
//			cout << str[j];
//		cout << endl;
//	}
//	return 0;
//}

//// 10-2 // string // 입력받은 문자열의 부분 문자열을 차례대로 출력
//int main()
//{
//	string str; // 문자열을 입력받을 배열 선언
//	cout << "문자열 입력>>"; // 문자열을 입력받을 문구 출력
//	getline(cin, str, '\n'); // cin버퍼에 입력된 문자열을 str에 저장, 구분자는 \n
//
//	for (int i = 0; i < (int)str.size(); i++) // 입력받은 문자열의 부분문자열들을 순서대로 출력
//	{
//		for (int j = 0; j <= i; j++) // i가 증가할때마다 출력되는 부분배열 증가
//			cout << str[j]; 
//		cout << endl;
//	}
//	return 0;
//}