#include <iostream>                           
#include <string>      
#include <cstdlib>  // #include <stdlib.h> // 수학관련함수 - 값  = > 정수 -> stdlib
#include <ctime>    // #include <time.h>
#pragma warning (disable : 4996)               
using namespace std;
// 기본생성자 습관화

////1
//class Tower // Tower 클래스 생성
//{
//private: // 데이터 은닉
//	int height; // 멤버변수
//public: // 공개
//	Tower(); // 기본생성자
//	Tower(int h); // 정수형 매개변수 하나를 받는 생성자
//	int getHeight(); // 높이를 호출하는 멤버함수
//};
//Tower::Tower() // 기본 생성자
//{
//	height = 1; // 멤버변수를 1로 초기화
//}
//Tower::Tower(int h) // 매개변수가 있는 생성자
//{
//	height = h; // 멤버변수를 입력받은 h로 초기화
//}
//int Tower::getHeight() // 높이를 알리는 멤버함수 정의
//{
//	return height; // 높이를 반환
//}
//int main() 
//{
//	Tower myTower; // 생성자를 통해 height값이 1로 초기화된 객체
//	Tower seoulTower(100); // 생성자를 통해 height값이 100으로 초기화된 객체
//	cout << "높이는 " << myTower.getHeight() << "미터" << endl; // 객체 myTower의 멤버함수를 호출하면서 높이가 얼만지 알림
//	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl; // 객체 seoulTower의 멤버함수를 호출하면서 높이가 얼만지 알림
//}

////2 // class Date // 생성자(년 월 일)// show 함수 // 멤버변수 출력 함수
//class Date // Date 클래스 생성
//{
//private: // 데이터 은닉
//		int year; // 년을 뜻하는 멤버변수
//		int month; // 월을 뜻하는 멤버변수
//		int day; // 일을 뜻하는 멤버변수
//public: // 공개
//	Date(); // 기본생성자
//	Date(int y, int m, int d); // 정수형 매개변수를 세개받는 생성자
//	Date(string date); // string형 매개변수를 하나받는 생성자
//	void show(); // 멤버변수들을 출력하는 함수
//	int getYear(); // 멤버변수 year값을 호출하는 함수
//	int getMonth(); // 멤버변수 month값을 호출하는 함수
//	int getDay(); // 멤버변수 day값을 호출하는 함수
//};
//Date::Date() // 기본 생성자
//{
//	year = 0; // 멤버변수 year을 0으로 초기화
//	month = 0; // 멤버변수 month을 0으로 초기화
//	day = 0; // 멤버변수 day을 0으로 초기화
//}
//Date::Date(int y, int m, int d) // 매개변수가 있는 생성자
//{ 
//	year = y; // 멤버변수 year을 입력받은 y로 초기화
//	month = m; // 멤버변수 month을 입력받은 m로 초기화
//	day = d; // 멤버변수 day을 입력받은 d로 초기화
//}
//Date::Date(string date) // 문자열 매개변수를 받는 생성자
//{
//	int index1 = date.find("/"); // 문자 /를 사용한 문자열 인덱스의 번호저장
//	string y = date.substr(0,index1); // 0 - 시작값 // index1 - 갯수
//	year = stoi(y); // string 객체형 문자열을 int 로 바꿔라
//	int index2 = date.find("/", index1 + 1); // index1 다음부터 찾아라
//	string m = date.substr(index1 + 1, index2 - index1 - 1);
//	// index1 = 4 , index2 = 6, 6 - 4 - 1 = 1 , 
//	// 처음 찾았던 인덱스에 하나를 더한 5부터 1을 더한 인덱스 6의 문자열을 (string형)m에 저장
//	month = stoi(m); // string 객체형 문자열을 int 로 바꿔라
//	string d = date.substr(index2 + 1, date.length()); // 인덱스 7부터 끝까지의 문자열을 (string형)d에 저장
//	day = stoi(d); // string 객체형 문자열을 int 로 바꿔라
//}
//void Date::show() // 멤버변수를 멤버함수를 통해 안전히 출력하는 방법
//{
//	cout << year << "년" << month << "월" << day << "일" << endl; // 멤버변수들을 차례로 문자열과 함께 출력
//}
//int Date::getYear() // 멤버변수 year값을 반환하는 함수 정의
//{
//	return year;
//}
//int Date::getMonth() // 멤버변수 month값을 반환하는 함수 정의
//{
//	return month;
//}
//int Date::getDay() // 멤버변수 day값을 반환하는 함수 정의
//{
//	return day;
//}
//
//int main()
//{
//	Date birth(2014, 3, 20); // 생성자를 통해 입력된 정수들로 멤버변수 year, month, day를 차례대로 초기화하는 객체
//	Date independanceday("1945/8/15"); // 생성자를 통해 입력된 문자열로 멤버변수 year, month, day를 초기화하는 객체
//	independanceday.show(); // 객체 independanceday의 멤버변수들을 출력하는 멤버함수 호출
//	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
//	// 객체 birth의 멤버함수를 호출하면서 멤버변수들을 출력
//}

////3 // class Account // 생성자 이름(string) 계좌번호 잔액 // 저금 함수 // 소유주 이름 반환 함수 // 잔액표시 함수
//class Account // Account 클래스 생성
//{
//private: // 데이터 은닉
//	string name; // 계좌주인의 이름을 받을 string형 멤버변수
//	int id;  // 계좌번호를 받을 멤버변수
//	int balance; // 잔액을 나타내는 멤버변수
//public: // 공개
//	Account(); // 기본 생성자
//	Account(string n, int a, int b); // string형과 정수형 두개  총 세개의 매개변수를 받을 생성자
//	void deposit(int n); // 저금하는 멤버함수 // 인라인 함수 - 선언부에서 함수 정의
//	string getOwner(); // 계좌주인의 이름을 반환하는 멤버함수
//	int inquiry(); // 잔액을 조회하는 멤버함수
//	int withdraw(int n); // 출금하는 멤버함수
//};
//inline Account::Account() // 기본 생성자
//{
//	name = "NULL"; // 멤버변수 name을 NULL로 초기화
//	id = 0; balance = 0; // 멤버변수 id와 balance를 0으로 초기화
//}
//inline Account::Account(string n, int a, int b) // 매개변수가 있는 생성자
//{
//	name = n; // 문자열 매개변수 name에 입력받은 n의 문자열을 저장
//	id = a; // 입력받은 a를 id에 저장
//	balance = b; // 입력받은 b를 balance에 저장
//}
//inline void Account::deposit(int n) // 저금하는 멤버함수 정의
//{
//	balance += n; // 입력받은 n을 원래 balance 값에 더해서 저장
//}
//inline string Account::getOwner() // 계좌주인의 이름을 반환하는 함수 정의
//{
//	return name; // 멤버변수 name 반환
//}
//inline int Account::inquiry() // 잔액을 조회하는 함수 정의
//{
//	return balance; // 멤버변수 balance 반환
//}
//inline int Account::withdraw(int n) // 출금하는 함수 정의
//{
//	balance -= n; // 입력받은 n을 원래 balance의 값에서 빼고 그 값을 저장
//	return balance; // 멤버변수 balance 반환
//}
//int main()
//{
//	Account a("kitae", 1, 5000); // 생성자를 통해 입력된 값들로 멤버변수 name, id, balance를 차례대로 초기화하는 객체
//	a.deposit(50000); // 멤버함수를 호출해 잔액에 50000원을 저금 
//	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
//	// 멤버함수들을 호출해 계좌주인의 이름과 잔액 조회한 값을 출력
//	int money = a.withdraw(20000);	// 20000원 출금. withdraw()는 출금한 실제 금액 리턴
//	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
//	// 멤버함수들을 호출해 계좌주인의 이름과 잔액 조회한 값을 출력 
//}

////4 // class CoffeeMachine // 생성자 커피량 물 설탕 // 멤버함수
//class CoffeeMachine // CoffeeMachine 클래스 생성
//{
//private : // 데이터 은닉
//	int coffee; // 커피량 멤버변수
//	int water; // 물량 멤버변수
//	int sugar; // 설탕량 멤버변수
//public: // 공개
//	CoffeeMachine(); // 기본생성자
//	CoffeeMachine(int c, int w, int s); // 정수형 세개의 매개변수를 받는 생성자
//	void show(); // 커피와 물,설탕의 잔여량을 보여주는 멤버함수
//	void drinkEspresso(); // 에스프레소를 만드는 멤버함수
//	void drinkAmericano(); // 아메리카노를 만드는 멤버함수
//	void drinkSugarCoffee(); // 설탕커피를 만드는 멤버함수
//	void fill(); // 커피와 물,설탕을 10씩 채우는 멤버함수
//};
//CoffeeMachine::CoffeeMachine() // 기본 생성자
//{
//	coffee = 0; water = 0; sugar = 0; // 커피와 물, 설탕을 0으로 초기화
//}
//CoffeeMachine::CoffeeMachine(int c, int w, int s) // 매개변수가 있는 생성자
//{
//	coffee = c; water = w; sugar = s; // 입력받은 수들을 이용해 커피와 물,설탕을 초기화
//}
//void CoffeeMachine::show() // 커피와 물,설탕의 잔여량을 보여주는 멤버함수 정의
//{
//	cout << "커피 머신 상태, 커피:" << coffee << "  물:" << water << "    설탕:" << sugar << endl;
//	// 멤버변수들을 이용해 잔여량 출력
//}
//void CoffeeMachine::drinkEspresso() // 에스프레소를 만드는 멤버함수 정의
//{
//	coffee -= 1; // 멤버변수 coffee의 값을 1만큼 감소
//	water -= 1; // 멤버변수 water의 값을 1만큼 감소
//}
//void CoffeeMachine::drinkAmericano() // 아메리카노를 만드는 멤버함수 정의
//{
//	coffee -= 1; // 멤버변수 coffee의 값을 1만큼 감소
//	water -= 2; // 멤버변수 water의 값을 2만큼 감소
//}
//void CoffeeMachine::drinkSugarCoffee() // 설탕커피를 만드는 멤버함수 정의
//{
//	coffee -= 1; // 멤버변수 coffee의 값을 1만큼 감소
//	water -= 2; // 멤버변수 water의 값을 2만큼 감소
//	sugar -= 1; // 멤버변수 sugar의 값을 1만큼 감소
//}
//void CoffeeMachine::fill() // // 커피와 물,설탕의 양을 10씩 채우는 멤버함수 정의
//{
//	coffee += 10; // 멤버함수 coffee의 값을 10만큼 증가
//	water += 10; // 멤버함수 water의 값을 10만큼 증가
//	sugar += 10; // 멤버함수 sugar의 값을 10만큼 증가
//}
//int main()
//{
//	CoffeeMachine java(5, 10, 6); // 생성자를 통해 입력된 값들로 멤버변수 coffee, water, sugar를 차례대로 초기화하는 객체
//	java.drinkEspresso(); // 멤버함수를 호출해 coffee 1 소비, water 1 소비
//	java.show(); // 멤버함수를 호출해 현재 coffeeMachine의 상태 출력
//	java.drinkAmericano(); // 멤버함수를 호출해 coffee 1 소비, water 2 소비
//	java.show(); // 멤버함수를 호출해 현재 coffeeMachine의 상태 출력
//	java.drinkSugarCoffee(); // 멤버함수를 호출해 coffee 1 소비, water 2 , sugar 1 소비
//	java.show(); // 멤버함수를 호출해 현재 coffeeMachine의 상태 출력
//	java.fill(); // 멤버함수를 호출해 coffee 10 소비, water 10 , sugar 10 채우기
//	java.show(); // 멤버함수를 호출해 현재 coffeeMachine의 상태 출력
//}

//5 // 멤버변수 필요 X // 멤버함수 // next()함수 구현
class Random // Random 클래스 생성
{
public: // 공개
	Random(); // 기본생성자
	int next(); // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수
	int nextIntRange(int a, int b); // 2 ~ 4 까지 중 랜덤으로 정수를 뽑는 함수
};
Random::Random() // 기본 생성자
{
	srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
	// 객체가 생성될 때 씨드를 변경시켜줘서 객체마다 다른 씨드값을 갖게 함
}
int Random::next() // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수 정의
{
	int n = rand(); // 랜덤으로 수를 뽑아 정수형 변수 n에 저장
	return n; // 정수 n 반환
}
int Random::nextIntRange(int mn, int mx) // 2 ~ 4 까지 중 랜덤으로 정수를 뽑는 함수 정의
{
	int range = (mx - mn) + 1; // 입력받은 수 두개로 뽑을 수 있는 랜덤 정수의 범위를 정함
	return mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 리턴한다 
}
int main() 
{
	Random r; // Random 클래스 객체 r 선언
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl; // 랜덤정수를 뽑는다는 문구 출력
	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
	{
		int n = r.next(); // 멤버함수를 호출해 0에서 RAND_MAX(32767) 사이의 랜덤한 정수를 반환받아 변수 n에 저장
		cout << n << ' '; // 각 랜덤정수들을 출력
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl; // 2 ~ 4 사이의 랜덤정수를 뽑는다는 문구 출력
	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
	{
		int n = r.nextIntRange(2, 4); // 멤버함수를 호출해 2에서 4 사이의 랜덤한 정수를 반환받아 변수 n에 저장
		cout << n << ' '; // 각 랜덤정수들을 출력
	}
	cout << endl;
}