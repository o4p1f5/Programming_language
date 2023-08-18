#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#pragma warning (disable : 4996)
using namespace std;

//////1-1
////int main()
////{
////	int a, b;
////	cout << "정수 두개 입력 :";
////	cin >> a >> b;
////	cout << a << " + " << b << " = " << a + b << endl;
////	cout << a << " - " << b << " = " << a - b << endl;
////	cout << a << " X " << b << " = " << a * b << endl;
////	return 0;
////}
//
//////1-2
////double FtoC(double n1)
////{
////	double n2 = 0;
////	n2 = 5.0 / 9.0 * (n1 - 32);
////	return n2;
////}
////double CtoF(double n1)
////{
////	double n2 = 0;
////	n2 = (n1 * (9.0 / 5.0)) + 32.0;
////	return n2;
////}
////int main()
////{
////	double n1,n2;
////	cout << "화씨 온도 입력 :";
////	cin >> n1;
////	cout << "화씨 온도 " << n1 << "는 섭씨온도 " << FtoC(n1) << " 이다." << endl;
////
////	cout << "섭씨 온도 입력 :";
////	cin >> n2;
////	cout << "섭씨 온도 " << n2 << "는 화씨온도 " << CtoF(n2) << " 이다.";
////	return 0;
////}
//
//////1-3
////double CmToInch(double n1)
////{
////	double n2;
////	n2 = n1 / 2.54;
////	return n2;
////}
////double InchToCm(double n1)
////{
////	double n2;
////	n2 = n1 * 2.54;
////	return n2;
////}
////int main()
////{
////	double n1, n2;
////	cout << "길이 입력(cm) :";
////	cin >> n1;
////	cout << n1 << " Cm는 " << CmToInch(n1) << " Inch" << endl;
////
////	cout << "길이 입력(inch) :";
////	cin >> n2;
////	cout << n2 << " Inch는 " << InchToCm(n2) << " Cm" << endl;
////}
//
//////1-4
////int main()
////{
////	double n1, n2;
////	cout << "직각 삼각형의 밑변과 높이를 입력 :";
////	cin >> n1 >> n2;
////	double root = sqrt((n1*n1)+(n2*n2));
////	cout << "밑변 " << n1 << " 높이 " << n2 << "의 직각 삼각형의 빗변은 " << root << " 입니다.";
////}
//
//////1-5
////int main()
////{
////	int num[20] = { 1,2,3,4,5,0,2,4,7,8,6,8,3,6,9,3,2,5,3,8 };
////	int cnt[10] = {};
////	for (int i = 0; i < 20; i++)
////	{
////		cnt[num[i]]++;
////	}
////	for (int i = 0; i < 10; i++)
////	{
////		cout << "숫자 " << i << "는 " << cnt[i] << "개" << endl;
////	}
////}

////// 2-3
////int main()
////{
////	int a, b;
////	cout << "두 수를 입력하라>>";
////	cin >> a >> b;
////	cout << "큰 수 = ";
////	if (a > b)
////		cout << a;
////	else if (a < b)
////		cout << b;
////	else
////		cout << "없다. 두 수가 같음";
////}
//
////// 2-4
////int main()
////{
////	double num[5] = {};
////	double max;
////	cout << "5 개의 실수를 입력하라>>";
////	for (int i = 0; i < 5; i++)
////	{
////		cin >> num[i];
////	}
////	max = num[0];
////	for (int i = 0; i < 5; i++)
////	{
////		if (num[i] > max)
////			max = num[i];
////	}
////	cout << "제일 큰 수 = " << max;
////}
//
//////2-5 Hexadecimal x-exe y-axe
////int main()
////{
////	char num[100] = {};
////	int cnt = 0;
////	cout << "문자들을 입력하라(100개 미만)." << endl;
////	cin.getline(num, 100, '\n');
////	for (int i = 0; i < 100; i++)
////	{
////		if (num[i] == 'x')
////			cnt++;
////	}
////	cout << "x의 개수는 " << cnt;
////}
//
//////2-5' Hexadecimal x-exe y-axe
////int main()
////{
////	string str;
////	int cnt = 0;
////	cout << "문자들을 입력하라(100개 미만)." << endl;
////	getline(cin, str, '\n');
////	for (int i = 0; i < (int)str.size(); i++)
////	{
////		if (str[i] == 'x')
////			cnt++;
////	}
////	cout << "x의 개수는 " << cnt;
////}
//
//////2-7
////int main()
////{
////	char num[100] = {};
////	while (1)
////	{
////		cout << "종료하고싶은면 yes를 입력하세요>>";
////		cin.getline(num, 100, '\n');
////		if (!strcmp(num, "yes")) // 입력받은 문자열과 "yes" 가 같다면 0출력, 조건문에 !가 붙었기때문에 true로 취급
////		{
////			cout << "종료합니다..."; // 같다면 종료합니다... 출력 후 while문을 빠져나옴
////			break;
////		}
////	}
////}
//
//////2-7'
////int main()
////{
////	string str;
////	while (1)
////	{
////		cout << "종료하고싶은면 yes를 입력하세요>>";
////		getline(cin, str, '\n');
////		if (str == "yes") // 입력받은 문자열과 "yes" 가 같다면 0출력, 조건문에 !가 붙었기때문에 true로 취급
////		{
////			cout << "종료합니다..."; // 같다면 종료합니다... 출력 후 while문을 빠져나옴
////			break;
////		}
////	}
////}
//
//////2-8
////int main()
////{
////	char num[100] = {};
////	char str[100] = { 0 };
////	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
////	for (int i = 0; i < 5; i++) // 5명의 이름을 입력받고 가장 긴 이름을 찾아낼 반복문
////	{
////		cin.getline(num, 100, ';'); // 입력받은 문자열을 차례대로 str1에 저장, 구분자는 ;
////		if (strlen(num) > strlen(str)) // str1의 길이와 str2의 길이를 비교한 후 str1의 길이가 길다면
////		{
////			strcpy(str, num); // str1의 문자열을 str2에 저장
////		}
////		cout << i + 1 << " : " << num << endl; // 입력받은 이름들을 출력
////	}
////	cout << "가장 긴 이름은 " << str; // 가장 긴 이름을 출력
////}
//
//////2-8'
////int main()
////{
////	string num;
////	string str;
////	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
////	for (int i = 0; i < 5; i++) // 5명의 이름을 입력받고 가장 긴 이름을 찾아낼 반복문
////	{
////		getline(cin, num, ';'); // 입력받은 문자열을 차례대로 str1에 저장, 구분자는 ;
////		if (num.size() > str.size()) // str1의 길이와 str2의 길이를 비교한 후 str1의 길이가 길다면
////		{
////			str = num; // str1의 문자열을 str2에 저장
////		}
////		cout << i + 1 << " : " << num << endl; // 입력받은 이름들을 출력
////	}
////	cout << "가장 긴 이름은 " << str; // 가장 긴 이름을 출력
////}
//
//////2-10
////int main()
////{
////	char str[100] = {};
////	cout << "문자열 입력 >>";
////	cin.getline(str, 100);
////	for (int i = 0; i < (int)strlen(str); i++)
////	{
////		for (int j = 0; j <= i; j++)
////			cout << str[j];
////		cout << endl;
////	}
////}
//
//////2-10'
////int main()
////{
////	string str;
////	cout << "문자열 입력 >>";
////	getline(cin, str);
////	for (int i = 0; i < (int)str.size(); i++)
////	{
////		for (int j = 0; j <= i; j++)
////			cout << str[j];
////		cout << endl;
////	}
////}

//3-1
class Tower
{
	int Height;
	double* real;
	double* imag;
public:
	Tower(int n=0,double rm=0,double im=0) 
	{
		Height = n; 
		real = new double;
		*real = rm;
		imag = new double;
		*imag = im;
	}
	Tower(Tower& op)
	{
		Height = op.Height;
		real = new double;
		*real = *(op.real);
		imag = new double;
		*imag = *(op.imag);
	}
	int getHeight() { return  Height; }
};
int main()
{
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}