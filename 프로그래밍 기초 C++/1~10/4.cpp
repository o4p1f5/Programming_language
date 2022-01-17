#include <iostream>                           
#include <string>      
#include <cstdlib>  // #include <stdlib.h> // 수학관련함수 - 값  = > 정수 -> stdlib
#include <ctime>    // #include <time.h>
#pragma warning (disable : 4996)               
using namespace std;

////6 // 5번코드 이용 //멤버변수 X // 난수를 짝수로 // 함수에서 while로 if(n%2==0) = 짝수 아니면 난수 다시 뽑기
//class EvenRandom // EvenRandom 클래스 생성
//{
//public: // 공개
//	EvenRandom() // 기본생성자
//	{
//		srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
//		// 객체가 생성될 때 씨드를 변경시켜줘서 객체마다 다른 씨드값을 갖게 함
//	}
//	int next(); // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수
//	int nextIntRange(int a, int b); // 2 ~ 10 까지 중 랜덤으로 정수를 뽑는 함수
//};
//int EvenRandom::next() // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수 정의
//{
//	while (true)
//	{
//		int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//		if (n % 2 == 0) // 그 수가 짝수라면
//		{
//			return n; // 정수 n 반환
//		}
//	}
//}
//int EvenRandom::nextIntRange(int mn, int mx) // 2 ~ 10 까지 중 랜덤으로 정수를 뽑는 함수 정의
//{
//	int range = (mx - mn) + 1; // 입력받은 수 두개로 뽑을 수 있는 랜덤 정수의 범위를 정함
//	while (true)
//	{
//		int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//		if (n % 2 == 0) // 그 수가 짝수라면
//		{
//			return n; // 정수 n 반환
//		}
//	}
//}
//int main()
//{
//	EvenRandom r; // EvenRandom 클래스 객체 r 선언
//	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl; // 랜덤정수를 뽑는다는 문구 출력
//	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//	{
//		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
//		cout << n << ' '; // 각 랜덤정수들을 출력
//	}
//	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl; // 2 ~ 10 사이의 랜덤정수를 뽑는다는 문구 출력
//	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//	{
//		int n = r.nextIntRange(2, 10); // 멤버함수를 호출해 2에서 10 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//		cout << n << ' '; // 각 랜덤정수들을 출력
//	}
//	cout << endl;
//}

////7 // 5번코드이용 //멤버변수 하나 bool형// 짝수인지 홀수를 뽑을건지 
//class SelectableRandom // SelectableRandom 클래스 생성
//{
//	bool sel; // 멤버변수 - 데이터 은닉 // 짝수 홀수를 판단하기 위한 bool형 변수
//	// true면 짝수, false면 홀수
//public:
//	SelectableRandom() // 기본 생성자
//	{
//		sel = true; // sel을 true 즉, 짝수로 설정
//		srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
//	}
//	SelectableRandom(bool s) // 생성자
//	{
//		sel = s; // 입력받은 true나 false를 sel에 저장
//		srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
//	}
//	int next(); // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수
//	int nextIntRange(int a, int b); // 2 ~ 9 까지 중 랜덤으로 정수를 뽑는 함수
//};
//int SelectableRandom::next() // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수 정의
//{
//	if (sel == true) // sel이 true면
//	{
//		while (true) // 짝수 랜덤발생기
//		{
//			int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//			if (n % 2 == 0) // 그 수가 짝수라면
//			{
//				return n; // 정수 n 반환
//			}
//		}
//	}
//	else if (sel == false) // sel이 false라면
//	{
//		while (true) // 홀수 랜덤발생기
//		{
//			int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//			if (n % 2 == 1) // 그 수가 홀수라면
//			{
//				return n; // 정수 n 반환
//			}
//		}
//	}
//}
//int SelectableRandom::nextIntRange(int mn, int mx) // 2 ~ 9 까지 중 랜덤으로 정수를 뽑는 함수 정의
//{
//	int range = (mx - mn) + 1; // 입력받은 수 두개로 뽑을 수 있는 랜덤 정수의 범위를 정함
//	if (sel == true) // sel이 true라면
//	{
//		while (true) // 짝수 랜덤발생기
//		{
//			int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//			if (n % 2 == 0) // 그 수가 짝수라면
//			{
//				return n; // 정수 n 반환
//			}
//		}
//	}
//	else if (sel == false) // sel이 false라면
//	{
//		while (true) // 훌수 랜덤발생기
//		{
//			int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//			if (n % 2 == 1) // 그 수가 홀수라면
//			{
//				return n; // 정수 n 반환
//			}
//		}
//	}
//}
//
//int main()
//{
//	SelectableRandom evenRandom; // 짝수 랜덤발생기 // SelectableRandom 클래스 객체 evenRandom 생성
//	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl; // 랜덤정수를 뽑는다는 문구 출력
//	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//	{
//		int n = evenRandom.next(); // 멤버함수를 호출해 0에서 RAND_MAX(32767) 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//		cout << n << ' '; // 각 랜덤정수들을 출력
//	}
//	SelectableRandom oddRandom(false); // 홀수 랜덤발생기 // SelectableRandom 클래스 객체 oddRandom 생성
//	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl; // 2 ~ 9 사이의 랜덤정수를 뽑는다는 문구 출력
//	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//	{
//		int n = oddRandom.nextIntRange(2, 9); // 멤버함수를 호출해 2에서 9 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//		cout << n << ' '; // 각 랜덤정수들을 출력
//	}
//	cout << endl;
//}

////8
//class Integer // Integer 클래스 선언
//{
//	int integer; // 멤버변수 - 데이터 은닉 // int형 정수들을 담기 위한 변수
//public:
//	Integer() // 기본 생성자
//	{
//		integer = 0; // integer을 0으로 초기화
//	}
//	Integer(int n) // 생성자
//	{
//		integer = n; // 입력받은 정수 n을 integer에 저장
//	}
//	Integer(string c) // 생성자
//	{
//		int i = stoi(c); // 입력받은 문자열을 정수형으로 바꿔주는 함수 stoi
//		integer = i; // 바뀐 정수를 integer에 저장
//	}
//	void set(int n); // 입력받은 수를 integer에 저장하기 위한 함수
//	int get(); // 함수가 호출되면 integer 반환
//	bool isEven(); // 함수가 호출되면 true 반환
//};
//void Integer::set(int n) // 입력받은 정수 n을 integer에 저장
//{
//	integer = n;
//}
//int Integer::get() // integer을 반환
//{
//	return integer;
//}
//bool Integer::isEven() // 짝수면 true를 반환
//{
//	if (integer % 2 == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	Integer n(30); // Integer 클래스 객체 n 생성
//	cout << n.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//	n.set(50); // 멤버함수 set을 호출하여 integer에 50 저장
//	cout << n.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//
//	Integer m("300"); // Integer 클래스 객체 m 생성 // string형 문자열을 줌
//	cout << m.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//	cout << m.isEven(); // 멤버함수 inEven을 호출하여 true(정수로 1) 출력
//}

////9 // 코드분활할필요X // 소멸자 필요 - 기능X
//class Oval // Oval 클래스 생성
//{
//	int width; // 사각형의 너비값을 입력받을 멤버변수
//	int height; // 사각형의 높이를 입력받을 멤버변수
//public:
//	Oval() // 기본생성자
//	{
//		width = 1; height = 1; // 너비와 높이 값을 1로 초기화
//	}
//	Oval(int width, int height) // 생성자  // this 연산자 = 객체 자기 자신을 가리키는 포인터
//	{
//		this->width = width; this->height = height; // 너비와 높이 변수에 입력받은 w,h의 값을 저장
//	} //  main문에 따라 지금 this는 b를 가리키는 포인터가 됨
//	~Oval() // 소멸자
//	{
//		cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
//		// 소멸되는 클래스의 현재 너비와 현재 높이 값을 출력
//        // 생성된 객체 순서의 반대로 소멸
//	}
//	int getWidth(); // 타원의 너비를 리턴하는 멤버 함수
//	int getHeight(); // 타원의 높이를 리턴하는 멤버 함수
//	void set(int w, int h); // 입력받은 수를 width와 height에 저장하는 멤버함수
//	void show(); // 현재의 타원의 너비와 높이를 출력하는 멤버함수
//};
//int Oval::getWidth() // 타원의 너비를 리턴하는 멤버 함수
//{
//	return width;
//}
//int Oval::getHeight() // 타원의 높이를 리턴하는 멤버 함수
//{
//	return height;
//}
//void Oval::set(int w, int h) // 입력받은 수를 width와 height에 저장하는 멤버함수
//{
//	width = w; 
//	height = h;
//}
//void Oval::show() // 현재의 타원의 너비와 높이를 출력하는 멤버함수
//{
//	cout << "width = " <<width << ", height = "<< height << endl;
//}
//
//int main()
//{
//	Oval a, b(3, 4); // Oval 클래스 객체 a와 b 생성
//	a.set(10, 20); // 멤버함수 set을 호출해서 객체 a의 width,height에 10,20을 저장
//	a.show(); // 멤버함수 show를 호출해서 현재 객체 a 타원의 너비와 높이를 출력
//	cout << b.getWidth() << ", " << b.getHeight() << endl; 
//	// 멤버함수 getWidth와 getHeight를 호출해서 객체 b의 현재 너비와 높이 출력
//}

//10 // 클래스 여러개
class Add // Add 클래스 선언
{
	int a; // 멤버변수 a
	int b; // 멤버변수 b
public: 
	Add() // 기본생성자 
	{
		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
	}
	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
	int calculate(); // 연산결과를 리턴하는 멤버함수
};
void Add::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
{
	a = x, b = y;
}
int Add::calculate() // a와 b의 연산값을 리턴
{
	return a + b;
}
class Sub // Sub 클래스 생성
{
	int a; // 멤버함수 a
	int b; // 멤버함수 b
public:
	Sub() // 기본생성자
	{
		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
	}
	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
	int calculate(); // 연산결과를 리턴하는 멤버함수
};
void Sub::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
{
	a = x, b = y;
}
int Sub::calculate() // a와 b의 연산값을 리턴
{
	return a - b;
}
class Mul // Mul 클래스 생성 
{
	int a; // 멤버함수 a
	int b; // 멤버함수 b
public:
	Mul() // 기본생성자
	{ 
		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
	}
	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
	int calculate(); // 연산결과를 리턴하는 멤버함수
};
void Mul::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
{
	a = x, b = y;
}
int Mul::calculate() // a와 b의 연산값을 리턴
{
	return a * b;
}
class Div // Div 클래스 생성
{
	int a; // 멤버함수 a
	int b; // 멤버함수 b
public:
	Div() // 기본생성자
	{
		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
	}
	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
	int calculate(); // 연산결과를 리턴하는 멤버함수
};
void Div::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
{
	a = x, b = y;
}
int Div::calculate() // a와 b의 연산값을 리턴
{
	return a / b;
}

int main() 
{
	Add a; // Add 클래스 객체 a 선언
	Sub s; // Sub 클래스 객체 s 선언
	Mul m; // Mul 클래스 객체 m 선언
	Div d; // Div 클래스 객체 d 선언

	while (true) 
	{
		// 화면에 프롬프트를 출력하고 키보드로 두 정수와 연산자를 입력받는다.
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y; // 멤버변수 a, b에 저장할 두 개의 정수변수 선언
		char c; // 어떤 연산을 할지 구분해주는 char변수 선언
		cin >> x >> y >> c; // 입력받은 수와 문자를 차례대로 변수들에 저장
		switch (c) // 스위치문
		{
		case '+': 	a.setValue(x, y); cout << a.calculate(); break;
			// char변수에 +가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
		case '-': 	s.setValue(x, y); cout << s.calculate(); break;
			// char변수에 -가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
		case '*': 	m.setValue(x, y); cout << m.calculate(); break;
			// char변수에 *가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
		case '/': 	d.setValue(x, y); cout << d.calculate(); break;
			// char변수에 /가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
		}
		cout << endl;
	}
}