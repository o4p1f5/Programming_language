#include <iostream>
using namespace std;

////1 // c1 c2 값 바꾸기
//class Circle // Circle 클래스
//{
//	int radius;
//public:
//	Circle() { radius = 1;}
//	Circle(int radius) { this->radius = radius;}
//	double getArea()
//	{
//		return 3.14 * radius * radius;
//	}
//	int getRadius()
//	{
//		return radius;
//	}
//};
//
//void swap(Circle& n1, Circle& n2) // 두 객체를 참조에 의한 호출해 공유된 공간의 값을 변경
//{
//	Circle tmp = n1; // 새로 만들어진 객체에 n1을 복사하고
//	n1 = n2; // n1에 n2를 대입
//	n2 = tmp; // 아까 복사된 n1을 다시 n2에 복사해서 두 객체의 값을 교환
//}
//
//int main()
//{
//	int n(0), m(0); // 두 원의 반지름을 입력받기 위한 변수 두개 선언
//	cout << "두 원의 반지름 값 입력 >> "; // 두 원의 반지름을 입력받음
//	cin >> n >> m;
//	Circle c1(n), c2(m); // 입력받은 반지름값을 c1, c2에 차례로 저장
//	cout << "변경 전 반지름 값 출력 " << c1.getRadius() << " " << c2.getRadius() << endl;
//	// swap함수를 지나기 전 두 객체의 반지름값 출력
//	swap(c1, c2); // 두 객체를 교환함
//	cout << "변경 후 반지름 값 출력 " << c1.getRadius() << " " << c2.getRadius() << endl;
//	// swap함수를 지난 후 두 객체의 반지름값 출력
//}

////2 // 함수에서 반환하지않아도 값이 변경되어야한다
//// void half(int & n)
//void half(double& n) // 변수 n의 반값을 구하기 위해 참조에 의한 호출을 한 함수
//{
//	n = n / 2.0; // n의 값을 2로 나눈 값을 n에 저장
//}
//int main()
//{
//	double n = 20; // 실수형 변수 n의 값을 20.0으로 초기화
//	half(n); // n의 값을 참조에 의한 전달함
//	cout <<  n; // n의 반값을 출력
//}

////3 // test 1, text 2를 합쳐서 text3에 대입
//// 텍스트 1,2 는 값에 의한 전달 텍스트 3는 참조전달
//void combine(string s1, string s2, string& s3) // text1,text2는 값에 의한 전달을 하고 text3는 참조에 의한 전달함
//{
//	s3 = s1 + " " + s2; // 두 문자열을 더한 값을 text3와 공간을 공유하는 s3에 저장
//}
//int main()
//{
//	string text1("I love you"), text2 = ("very much"); // string객체 text1과 string객체 text2를 초기화
//	string text3; // string객체 text3 기본생성
//	combine(text1, text2, text3); // combine 함수 호출
//	cout << text3; // "I love you wery much" 출력
//}

////4 // 평균
//bool bigger(int a, int b, int& big) // x ,y 값을 값에 의한 전달하고 big을 참조에 의한 전달함
//{
//	if (a == b) // a와 b가 같다면
//	{
//		return true; // true반환
//	}
//	else // 같지 않다면
//	{
//		if (a > b) // a가 b보다 크다면
//		{
//			big = a; // big에 a 저장
//		}
//		else // b가 a보다 크다면
//			big = b; // big에 b 저장
//		return false; // false 반환
//	}
//}
//int main()
//{
//	int x, y, big; // 두 정수를 받기 위한 변수 x, y 와 큰수를 받기 위한 big 선언
//	bool b; // 두 수가 같은지 판단을 받기 위한 불 변수 선언
//	cout << "두 정수를 입력하세요>> ";
//	cin >> x >> y; // 두 정수를 입력받음
//	b = bigger(x, y, big); // 두 수가 같다면 true가 반환되고 다르다면 false가 반환됨
//	if (b) // true가 반환됐다면
//		cout << "same" << endl; // 두 수가 같다는 뜻으로 same 출력
//	else // false가 반환됐다면
//		cout << "큰 수는 " << big << endl; // 두 수가 다르다는 뜻임으로 변경됐던 big 값 출력
//}

////5 // 클래스가 동작하게끔 변경
//class Circle // CIrcle 클래스
//{
//	int radius;
//public:
//	Circle(int r) { radius = r; }
//	int getRadius() { return radius; }
//	void setRadius(int r) { radius = r; }
//	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
//};
//void increaseBy(Circle& a, Circle b) // 객체 x를 참조에 의한 전달로 a와 공간을 공유하고 하고
//// 객체 y의 값은 값에 의한 전달받음
//{
//	int r = a.getRadius() + b.getRadius(); // a의 즉, x의 반지름과 b의 반지름을 더한 값을 r에 저장
//	a.setRadius(r); // 객체 a의 반지름을 r로 변경
//}
//int main()
//{
//	Circle x(10), y(5); // 객체 x와 y의 값을 10과 5로 초기화
//	increaseBy(x, y); // x 객체를 참조에 의한 전달하고 y객체를 값에 의한 전달함
//	x.show(); // x 객체의 반지름을 멤버함수 show()로 출력
//}