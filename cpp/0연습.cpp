////#include <iostream>                           
////#include <string>      
////#include <cstdlib>  // #include <stdlib.h> // 수학관련함수 - 값  = > 정수 -> stdlib
////#include <ctime>    // #include <time.h>
////#pragma warning (disable : 4996)               
////using namespace std;
////
////////6 // 5번코드 이용 //멤버변수 X // 난수를 짝수로 // 함수에서 while로 if(n%2==0) = 짝수 아니면 난수 다시 뽑기
//////class EvenRandom // EvenRandom 클래스 생성
//////{
//////public: // 공개
//////	EvenRandom() // 기본생성자
//////	{
//////		srand((unsigned)time(NULL)); // 난수의 씨드를 시간에 따라 변경시켜주는 함수
//////		// 객체가 생성될 때 씨드를 변경시켜줘서 객체마다 다른 씨드값을 갖게 함
//////	}
//////	int next(); // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수
//////	int nextIntRange(int a, int b); // 2 ~ 10 까지 중 랜덤으로 정수를 뽑는 함수
//////};
//////int EvenRandom::next() // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수 정의
//////{
//////	while (true)
//////	{
//////		int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//////		if (n % 2 == 0) // 그 수가 짝수라면
//////		{
//////			return n; // 정수 n 반환
//////		}
//////		else
//////		{
//////			continue; // 짝수가 아니라면 다시 뽑기
//////		}
//////	}
//////}
//////int EvenRandom::nextIntRange(int mn, int mx) // 2 ~ 10 까지 중 랜덤으로 정수를 뽑는 함수 정의
//////{
//////	int range = (mx - mn) + 1; // 입력받은 수 두개로 뽑을 수 있는 랜덤 정수의 범위를 정함
//////	while (true)
//////	{
//////		int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//////		if (n % 2 == 0) // 그 수가 짝수라면
//////		{
//////			return n; // 정수 n 반환
//////		}
//////		else
//////		{
//////			continue; // 짝수가 아니라면 다시 뽑기
//////		}
//////	}
//////}
//////int main()
//////{
//////	EvenRandom r; // EvenRandom 클래스 객체 r 선언
//////	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl; // 랜덤정수를 뽑는다는 문구 출력
//////	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//////	{
//////		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
//////		cout << n << ' '; // 각 랜덤정수들을 출력
//////	}
//////	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl; // 2 ~ 10 사이의 랜덤정수를 뽑는다는 문구 출력
//////	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//////	{
//////		int n = r.nextIntRange(2, 10); // 멤버함수를 호출해 2에서 10 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//////		cout << n << ' '; // 각 랜덤정수들을 출력
//////	}
//////	cout << endl;
//////}
////
////////7 // 5번코드이용 //멤버변수 하나 bool형// 짝수인지 홀수를 뽑을건지 
//////class SelectableRandom // SelectableRandom 클래스 생성
//////{
//////	bool sel; // 멤버변수 - 데이터 은닉 // 짝수 홀수를 판단하기 위한 bool형 변수
//////	// true면 짝수, false면 홀수
//////public:
//////	SelectableRandom() // 기본 생성자
//////	{
//////		sel = true; // sel을 true 즉, 짝수로 설정
//////	}
//////	SelectableRandom(bool s) // 생성자
//////	{
//////		sel = s; // 입력받은 true나 false를 sel에 저장
//////	}
//////	int next(); // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수
//////	int nextIntRange(int a, int b); // 2 ~ 9 까지 중 랜덤으로 정수를 뽑는 함수
//////};
//////int SelectableRandom::next() // 0 ~ RAND_MAX 까지 중 랜덤으로 정수를 뽑는 함수 정의
//////{
//////	if (sel == true) // sel이 true면
//////	{
//////		while (true) // 짝수 랜덤발생기
//////		{
//////			int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//////			if (n % 2 == 0) // 그 수가 짝수라면
//////			{
//////				return n; // 정수 n 반환
//////			}
//////			else
//////			{
//////				continue; // 짝수가 아니라면 다시 뽑기
//////			}
//////		}
//////	}
//////	else if (sel == false) // sel이 false라면
//////	{
//////		while (true) // 홀수 랜덤발생기
//////		{
//////			int n = rand();// 랜덤으로 수를 뽑아 정수형 변수 n에 저장
//////			if (n % 2 == 1) // 그 수가 홀수라면
//////			{
//////				return n; // 정수 n 반환
//////			}
//////			else
//////			{
//////				continue; // 홀수가 아니라면 다시 뽑기
//////			}
//////		}
//////	}
//////}
//////int SelectableRandom::nextIntRange(int mn, int mx) // 2 ~ 9 까지 중 랜덤으로 정수를 뽑는 함수 정의
//////{
//////	int range = (mx - mn) + 1; // 입력받은 수 두개로 뽑을 수 있는 랜덤 정수의 범위를 정함
//////	if (sel == true) // sel이 true라면
//////	{
//////		while (true) // 짝수 랜덤발생기
//////		{
//////			int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//////			if (n % 2 == 0) // 그 수가 짝수라면
//////			{
//////				return n; // 정수 n 반환
//////			}
//////			else
//////			{
//////				continue; // 짝수가 아니라면 다시 뽑기
//////			}
//////		}
//////	}
//////	else if (sel == false) // sel이 false라면
//////	{
//////		while (true) // 훌수 랜덤발생기
//////		{
//////			int n = mn + (rand() % range); // mn와 mn 사이의 랜덤 정수를 변수 n에 저장한다.
//////			if (n % 2 == 1) // 그 수가 홀수라면
//////			{
//////				return n; // 정수 n 반환
//////			}
//////			else
//////			{
//////				continue; // 홀수가 아니라면 다시 뽑기
//////			}
//////		}
//////	}
//////}
//////
//////int main()
//////{
//////	SelectableRandom evenRandom; // 짝수 랜덤발생기 // SelectableRandom 클래스 객체 evenRandom 생성
//////	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl; // 랜덤정수를 뽑는다는 문구 출력
//////	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//////	{
//////		int n = evenRandom.next(); // 멤버함수를 호출해 0에서 RAND_MAX(32767) 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//////		cout << n << ' '; // 각 랜덤정수들을 출력
//////	}
//////	SelectableRandom oddRandom(false); // 홀수 랜덤발생기 // SelectableRandom 클래스 객체 oddRandom 생성
//////	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl; // 2 ~ 9 사이의 랜덤정수를 뽑는다는 문구 출력
//////	for (int i = 0; i < 10; i++) // 랜덤 정수 10개를 뽑기 위해 반복문 사용
//////	{
//////		int n = oddRandom.nextIntRange(2, 9); // 멤버함수를 호출해 2에서 9 사이의 랜덤한 정수를 반환받아 변수 n에 저장
//////		cout << n << ' '; // 각 랜덤정수들을 출력
//////	}
//////	cout << endl;
//////}
////
////////8
//////class Integer // Integer 클래스 선언
//////{
//////	int integer; // 멤버변수 - 데이터 은닉 // int형 정수들을 담기 위한 변수
//////public:
//////	Integer() // 기본 생성자
//////	{
//////		integer = 0; // integer을 0으로 초기화
//////	}
//////	Integer(int n) // 생성자
//////	{
//////		integer = n; // 입력받은 정수 n을 integer에 저장
//////	}
//////	Integer(string c) // 생성자
//////	{
//////		int i = stoi(c); // 입력받은 문자열을 정수형으로 바꿔주는 함수 stoi
//////		integer = i; // 바뀐 정수를 integer에 저장
//////	}
//////	void set(int n); // 입력받은 수를 integer에 저장하기 위한 함수
//////	int get(); // 함수가 호출되면 integer 반환
////////	bool isEven(); // 함수가 호출되면 true 반환
//////};
//////void Integer::set(int n) // 입력받은 정수 n을 integer에 저장
//////{
//////	integer = n;
//////}
//////int Integer::get() // integer을 반환
//////{
//////	return integer;
//////}
//////bool Integer::isEven() // true를 반환
//////{
//////	return true;
//////}
//////
//////int main()
//////{
//////	Integer n(30); // Integer 클래스 객체 n 생성
//////	cout << n.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//////	n.set(50); // 멤버함수 set을 호출하여 integer에 50 저장
//////	cout << n.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//////
//////	Integer m("300"); // Integer 클래스 객체 m 생성 // string형 문자열을 줌
//////	cout << m.get() << ' '; // 멤버함수 get을 호출하여 integer 출력
//////	cout << m.isEven(); // 멤버함수 inEven을 호출하여 true(정수로 1) 출력
//////}
////
////////9 // 코드분활할필요X // 소멸자 필요 - 기능X
//////class Oval // Oval 클래스 생성
//////{
//////	int width; // 사각형의 너비값을 입력받을 멤버변수
//////	int height; // 사각형의 높이를 입력받을 멤버변수
//////public:
//////	Oval() // 기본생성자
//////	{
//////		width = 1; height = 1; // 너비와 높이 값을 1로 초기화
//////	}
//////	Oval(int w, int h) // 생성자
//////	{
////////		width = w; height = h; // 너비와 높이 변수에 입력받은 w,h의 값을 저장
//////	}
//////	~Oval() // 소멸자
//////	{
//////		cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
//////		// 소멸되는 클래스의 현재 너비와 현재 높이 값을 출력
//////        // 생성된 객체 순서의 반대로 소멸
//////	}
//////	int getWidth(); // 타원의 너비를 리턴하는 멤버 함수
//////	int getHeight(); // 타원의 높이를 리턴하는 멤버 함수
//////	void set(int w, int h); // 입력받은 수를 width와 height에 저장하는 멤버함수
//////	void show(); // 현재의 타원의 너비와 높이를 출력하는 멤버함수
//////};
//////int Oval::getWidth() // 타원의 너비를 리턴하는 멤버 함수
//////{
//////	return width;
//////}
//////int Oval::getHeight() // 타원의 높이를 리턴하는 멤버 함수
//////{
//////	return height;
//////}
//////void Oval::set(int w, int h) // 입력받은 수를 width와 height에 저장하는 멤버함수
//////{
//////	width = w; 
//////	height = h;
//////}
//////void Oval::show() // 현재의 타원의 너비와 높이를 출력하는 멤버함수
//////{
//////	cout << "width = " <<width << ", height = "<< height << endl;
//////}
//////
//////int main()
//////{
//////	Oval a, b(3, 4); // Oval 클래스 객체 a와 b 생성
//////	a.set(10, 20); // 멤버함수 set을 호출해서 객체 a의 width,height에 10,20을 저장
//////	a.show(); // 멤버함수 show를 호출해서 현재 객체 a 타원의 너비와 높이를 출력
//////	cout << b.getWidth() << ", " << b.getHeight() << endl; 
//////	// 멤버함수 getWidth와 getHeight를 호출해서 객체 b의 현재 너비와 높이 출력
//////}
////
//////10 // 클래스 여러개
////class Add // Add 클래스 선언
////{
////	int a; // 멤버변수 a
////	int b; // 멤버변수 b
////public:
////	Add() // 기본생성자 
////	{
////		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
////	}
////	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
////	int calculate(); // 연산결과를 리턴하는 멤버함수
////};
////void Add::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
////{
////	a = x, b = y;
////}
////int Add::calculate() // a와 b의 연산값을 리턴
////{
////	return a + b;
////}
////class Sub // Sub 클래스 생성
////{
////	int a; // 멤버함수 a
////	int b; // 멤버함수 b
////public:
////	Sub() // 기본생성자
////	{
////		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
////	}
////	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
////	int calculate(); // 연산결과를 리턴하는 멤버함수
////};
////void Sub::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
////{
////	a = x, b = y;
////}
////int Sub::calculate() // a와 b의 연산값을 리턴
////{
////	return a - b;
////}
////class Mul // Mul 클래스 생성 
////{
////	int a; // 멤버함수 a
////	int b; // 멤버함수 b
////public:
////	Mul() // 기본생성자
////	{
////		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
////	}
////	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
////	int calculate(); // 연산결과를 리턴하는 멤버함수
////};
////void Mul::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
////{
////	a = x, b = y;
////}
////int Mul::calculate() // a와 b의 연산값을 리턴
////{
////	return a * b;
////}
////class Div // Div 클래스 생성
////{
////	int a; // 멤버함수 a
////	int b; // 멤버함수 b
////public:
////	Div() // 기본생성자
////	{
////		a = 1; b = 1; // 멤버변수 a와 b를 1로 초기화
////	}
////	void setValue(int x, int y); // 입력받은 수로 멤버변수 초기화하는 멤버함수
////	int calculate(); // 연산결과를 리턴하는 멤버함수
////};
////void Div::setValue(int x, int y) // 입력받은 정수 x, y를 멤버변수 a,b에 저장 
////{
////	a = x, b = y;
////}
////int Div::calculate() // a와 b의 연산값을 리턴
////{
////	return a / b;
////}
////
////int main()
////{
////	Add a; // Add 클래스 객체 a 선언
////	Sub s; // Sub 클래스 객체 s 선언
////	Mul m; // Mul 클래스 객체 m 선언
////	Div d; // Div 클래스 객체 d 선언
////
////	while (true)
////	{
////		// 화면에 프롬프트를 출력하고 키보드로 두 정수와 연산자를 입력받는다.
////		cout << "두 정수와 연산자를 입력하세요>>";
////		int x, y; // 멤버변수 a, b에 저장할 두 개의 정수변수 선언
////		char c; // 어떤 연산을 할지 구분해주는 char변수 선언
////		cin >> x >> y >> c; // 입력받은 수와 문자를 차례대로 변수들에 저장
////		switch (c) // 스위치문
////		{
////		case '+': 	a.setValue(x, y); cout << a.calculate(); break;
////			// char변수에 +가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
////			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
////		case '-': 	s.setValue(x, y); cout << s.calculate(); break;
////			// char변수에 -가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
////			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
////		case '*': 	m.setValue(x, y); cout << m.calculate(); break;
////			// char변수에 *가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
////			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
////		case '/': 	d.setValue(x, y); cout << d.calculate(); break;
////			// char변수에 /가 저장되었다면 멤버함수 setValue와 calculate를 호출해서 
////			// x,y를 객체 a의 a,b에 저장하고, 그 연산값을 출력한다.
////		}
////		cout << endl;
////	}
////}
////
////#include <iostream>
////using namespace std;
////
////////3-1 // 멤버함수 이용
//////class Book
//////{
//////	string title; // 책의 이름
//////	int price; // 책 가격
//////	int pages; // 책의 가격
//////public:
//////	Book(string title = " ", int price = 0, int pages = 0)
//////	{
//////		// 디폴트매개변수를 이용한 생성자
//////		this->title = title; this->price = price; this->pages = pages;
//////	}
//////	void show() // 책의 정보 출력
//////	{
//////		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//////	}
//////	string getTitle() { return title; } // 책 제목 출력
//////	bool operator!() // ! 연산자 정의
//////	{
//////		if(!price) // 객체의 price가 0이라면 ! 연산자를 만나 0이 아닌 수가 된다
//////			return true; // true 반환
//////		else // 0이 아닌 다른 값이라면 ! 연산자를 만나 0이 된다
//////			return false; // false 반환 
//////	}
//////};
//////int main()
//////{
//////	Book book("벼룩시장", 0, 50); // 객체 정보 입력 // 가격 : 0
//////	if (!book) cout << "공짜다" << endl; // book의 가격이 0원이라면 '공짜다' 출력
//////    // book.operator!();
//////}
////
////////3-2 // 프렌드 함수 이용
//////class Book
//////{
//////	string title; // 책 제목
//////	int price; // 책 가격
//////	int pages; // 책 페이지 수
//////public:
//////	Book(string title = " ", int price = 0, int pages = 0)
//////	{
//////		// 디폴트 매개변수를 이용한 생성자
//////		this->title = title; this->price = price; this->pages = pages;
//////	}
//////	void show() // 객체의 정보 모두 출력
//////	{
//////		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//////	}
//////	string getTitle() { return title; } // 제목 출력
//////	friend bool operator!(Book op1); // 연산자 ! 를 정의한 일반함수 프렌드화
//////};
//////bool operator!(Book op1) // ! 연산자 정의 // 복사 생성자 // 참조 필요없음
//////{
//////	if (!op1.price) // 객체의 price가 0이라면 ! 연산자를 만나 0이 아닌 수가 된다
//////		return true; // true 반환
//////	else // 0이 아닌 다른 값이라면 ! 연산자를 만나 0이 된다
//////		return false; // false 반환 
//////}
//////int main()
//////{
//////	Book book("벼룩시장", 0, 50); // 객체 정보 입력 // 가격 : 0
//////	if (!book) cout << "공짜다" << endl; // book의 가격이 0원이라면 '공짜다' 출력
//////    // operator!(book); 
//////}
////
////////8-1 // 멤버함수 이용 // 단항 연산자 - 전위, 후위
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//////	Circle operator++() // 전위++ 구현
//////	{
//////		this->radius++;
//////		return *this; // a 반환
//////	}
//////	Circle operator++(int n) // 후위++ 구현
//////	{
//////		Circle tmp = *this; // 바뀌기 전 a의 값 저장
//////		this->radius++; // a 변경
//////		return tmp; // 바뀌기 전의 값을 반환해 b에 복사생성
//////	}
//////};
//////int main()
//////{
//////	Circle a(5), b(4); // 객체 a,b 생성
//////	++a; // 전위 // a.operator++(); 
//////	b = a++; // 후위 // b = a.operator++(0); 
//////	a.show(); b.show();
//////}
////
////////8-2 // 프렌드 함수
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//////	friend Circle operator++(Circle& op); // 전위 ++연산자 정의 // 일반함수 -> 프렌드함수
//////	friend Circle operator++(Circle& op, int n); // 후위 ++연산자 정의 // 일반함수 -> 프렌드함수
//////};
//////Circle operator++(Circle &op) // 참조 // 참조안하면 복사생성으로 메인문의 객체값 바뀌지 않음
//////{
//////	// 전위++ 구현 // 객체 a 참조
//////	op.radius++; // a 변경
//////	return op; // a 참조 반환
//////}
//////Circle operator++(Circle &op, int n) // 참조 // 참조안하면 복사생성으로 메인문의 객체값 바뀌지 않음
//////{
//////	// 후위++ 구현 // 객체 a 참조
//////	Circle tmp = op; // 바뀌기 전 a의 값 저장
//////	op.radius++; // a 변경
//////	return tmp; // 바뀌기 전의 값을 반환해 b에 복사생성
//////}
//////int main()
//////{
//////	Circle a(5), b(4); // 객체 a,b 생성
//////	++a; // 전위 // operator++(a); 
//////	b = a++; // 후위 // b = operator++(a,0); 
//////	a.show(); b.show();
//////}
////
////////9 // 프렌드함수만 가능
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//////	friend Circle operator+(int n, Circle op);
//////};
//////Circle operator+(int n, Circle op) // a의 값 바뀌면 안되므로 참조 X // 복사생성
//////{
//////	op.radius = op.radius + n; // op의 반지름에 n을 더한 값을 op의 반지름에 저장
//////	return op; // 객체 op 반환
//////}
//////int main()
//////{
//////	Circle a(5), b(4); // 객체 a,b 생성
//////	b = 1 + a; // b = operator+(1,a) // b = 1.operator+(a) 는 1이 객체가 아니므로 불가능 - 멤버함수로 연산자 구현할 수 없다.
//////	// b의 반지름을 a의 반지름에 1을 더한 것으로 변경 // 반환된 객체를 복사생성
//////	a.show(); b.show();
//////}
////
////////10-1 // 멤버함수
//////class Statistics // 통계를 내는 클래스
//////{
//////	int* p; // 배열을 동적할당할 때 주소를 받을 포인터 변수
//////	int size; // 인덱스
//////	int capacity; // 동적할당될 공간의 수
//////public:
//////	Statistics(int size = 0, int capacity = 10)
//////	{
//////		// 디폴트 매개변수를 이용한 생성자
//////		this->size = size;
//////		this->capacity = capacity;
//////		p = new int[capacity];
//////	}
//////	Statistics(Statistics& s) // 복사생성자
//////	{
//////		this->size = s.size; // s의 정보 넘김
//////		this->capacity = s.capacity;
//////		this->p = new int[this->capacity]; // 전달받은 capacity만큼 새롭게 동적할당 후 p에 주소 저장 
//////		for (int i = 0; i < this->size; i++) // 현재의 최종 인덱스 길이까지 반복문
//////			p[i] = s.p[i]; // p의 배열공간에 객체 s의 배열공간에 저장된 수 저장
//////	}
//////	~Statistics() // 소멸자
//////	{
//////		if (p) // 동적할당 받은 p의 공간 삭제
//////			delete[] p;
//////	}
//////	bool operator!() // ! 연산자 정의
//////	{
//////		if (!size)
//////			return true; // 동적할당받은 공간에 입력받은 수가 하나도 없음을 의미
//////		else
//////			return false; // 동적할당받은 공간에 수가 입력되어있음을 의미
//////	}
//////	Statistics& operator<<(int op) // << 연산자 정의 // 입력받은 x배열의 수들을 
//////	{
//////		p[size++] = op; // 객체 stat의 size번째 인덱스에 하나씩 저장 // size가 증가하므로 인덱스를 늘려감
//////		return *this; // 변한 객체를 참조 반환
//////	}
//////	void operator~() // ~ 연산자 정의 // 소멸자 X // p출력
//////	{
//////		for (int i = 0; i < size; i++)
//////			cout << p[i] << " "; // p가 가리키는 공간에 저장된 수들을 출력
//////		cout << endl;
//////	}
//////	void operator>>(int& avg) // >> 연산자 정의 // p가 가리키는 공간의 모든 수 더함
//////	{
//////		// avg 참조
//////		int sum = 0;
//////		for (int i = 0; i < size; i++)
//////			sum += p[i]; // 모든 수의 합
//////		avg = sum / size; // 합을 최종인덱스의 수로 나눠줘 평균을 구함
//////	}
//////};
//////int main()
//////{
//////	Statistics stat; // size는 0이고, 배열공간을 10만큼 동적할당하고 그 주소를 p에 저장
//////	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
//////	// stat.operator!(); 
//////	// stat의 size가 0이라면 => stat에 아직 들어간 수가 없다면 true 반환
//////
//////	int x[5];
//////	cout << "5 개의 정수를 입력하라>>";
//////	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]에 정수 입력
//////
//////	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다. // stat.operator<<(x[i])
//////	stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다.
//////	//stat.operator<<(100).operator<<(200) // 참조를 꼭 해야 연산자를 연속으로 사용하는 기능을 사용할 수 있음
//////	
//////	~stat; // stat.operator~(); // 통계 데이터를 모두 출력
//////
//////	int avg;
//////	stat >> avg; // stat.operator>(avg); // 통계 객체로부터 평균을 받는다.
//////	cout << "avg = " << avg << endl; // 평균 출력
//////}
////
////////10-2 // 프렌드함수 이용
//////class Statistics
//////{
//////	int* p; // 배열을 동적할당할 때 주소를 받을 포인터 변수
//////	int size; // 인덱스
//////	int capacity; // 동적할당될 공간의 수
//////public:
//////	Statistics(int size = 0, int capacity = 10)
//////	{
//////		// 디폴트 매개변수를 이용한 생성자
//////		this->size = size;
//////		this->capacity = capacity;
//////		p = new int[capacity];
//////	}
//////	Statistics(Statistics& s) // 복사생성자
//////	{
//////		this->size = s.size; // s의 정보 넘김
//////		this->capacity = s.capacity; // 현재의 최종 인덱스 길이까지 반복문 
//////		this->p = new int[this->capacity]; // 전달받은 capacity만큼 새롭게 동적할당 후 p에 주소 저장 
//////		for (int i = 0; i < this->size; i++) // 현재의 최종 인덱스 길이까지 반복문
//////			p[i] = s.p[i]; // p의 배열공간에 객체 s의 배열공간에 저장된 수 저장
//////	}
//////	~Statistics() // 소멸자
//////	{
//////		if (p) // 동적할당 받은 p의 공간 삭제
//////			delete[] p;
//////	}
//////	friend bool operator!(Statistics op); // ! 연산자 정의
//////	friend Statistics& operator<<(Statistics& op1, int op2); // << 연산자 정의
//////	friend void operator~(Statistics op); // ~ 연산자 정의
//////	friend void operator>>(Statistics op, int& avg); // >> 연산자 정의
//////};
//////bool operator!(Statistics op) // ! 연산자 정의
//////{
//////	if (!op.size) // 아직 객체에 들어간 수가 없다면
//////		return true; // true 반환
//////	else // 들어간 수가 하나라고 있디면
//////		return false; // false 반환
//////}
//////Statistics& operator<<(Statistics& op1, int op2) // 공간을 공유하려면 유지되는 공간을 공유해야한다
//////{
//////	op1.p[op1.size++] = op2; // 입력받은 op2를 op1의 p가 가리키는 힙 공간의 size 인덱스에 저장
//////	return op1; // 참조 반환
//////}
//////void operator~(Statistics op) // ~ 연산자 정의
//////{
//////	for (int i = 0; i < op.size; i++)
//////		cout << op.p[i] << " "; // 객체 op의 p가 가리키는 힙공간의 수 출력
//////	cout << endl;
//////}
//////void operator>>(Statistics op, int& avg) // >> 연산자 정의
//////{
//////	int sum = 0;
//////	for (int i = 0; i < op.size; i++)
//////		sum += op.p[i]; // 객체 op의 수 모두 더함
//////	avg = sum / op.size; // 모두 더한 수를 op의 size(현재 수가 저장되어있는 공간의 마지막 인덱스)로 나눠 평균값을 구함
//////}
//////int main()
//////{
//////	Statistics stat; // size는 0이고, 배열공간을 10만큼 동적할당하고 그 주소를 p에 저장
//////	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
//////	// stat.operator!(); // operator!(stat);
//////	// stat의 size가 0이라면 => stat에 아직 들어간 수가 없다면 true 반환
//////
//////	int x[5];
//////	cout << "5 개의 정수를 입력하라>>";
//////	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]에 정수 입력
//////
//////	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다.
//////	// operator<<(stat, x[i]);
//////
//////	stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다.
//////	//stat.operator<<(100).operator<<(200) // 참조를 꼭 해야 연산자를 연속으로 사용하는 기능을 사용할 수 있음
//////	
//////	~stat; // stat.operator~(); //operator~(stat) // 통계 데이터를 모두 출력
//////
//////	int avg;
//////	stat >> avg; // stat.operator>(avg); // operator(stat,avg); // 통계 객체로부터 평균을 받는다.
//////	cout << "avg = " << avg << endl; // 평균 출력
//////}
////
////////11-1 // 멤버함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//////class Stack // 클래스 Stack
//////{
//////	int p[10]; // 크기가 10인 배열 p
//////	int tos; // 인덱스를 알려주는 멤버변수
//////public: // 공개
//////	Stack() // 기본생성자
//////	{
//////		tos = 0; // 0으로 초기화
//////		for (int i = 0; i < 10; i++)
//////			p[i] = 0; // 배열의 모든 인덱스를 1로 초기화
//////	}
//////	Stack& operator<< (int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//////	{
//////		p[tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//////		return *this; // 바뀐 객체 리턴
//////	}
//////	bool operator! () // !연산자 정의 // stack에 수가 없다면 true 반환
//////	{
//////		if (tos == 0) // 스텍 출력이 끝나면 
//////			return true; // true 반환
//////		else
//////			return false; // stack에 수가 남아있다면 false 반환
//////	}
//////	void operator>> (int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//////	{
//////		n = p[--tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//////	}
//////};
//////int main()
//////{
//////	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//////	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//////						   // stack.operator<<(3).operator<<(5).operator<<(10);
//////	while (true) // 팝을 위한 반복문
//////	{
//////		if (!stack) break; // 스택 empty // stack.operator!()
//////		int x = 0; // 팝된 정수를 저장할 변수
//////		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x)
//////		cout << x << ' ';
//////	}
//////	cout << endl;
//////}
////
////////11-2 // 프렌드 함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//////class Stack // 클래스 Stack
//////{
//////	int p[10]; // 크기가 10인 배열 p
//////	int tos; // 인덱스를 알려주는 멤버변수
//////public: // 공개
//////	Stack() // 기본생성자
//////	{
//////		tos = 0; // 0으로 초기화
//////		for (int i = 0; i < 10; i++)
//////			p[i] = 0; // 배열의 모든 인덱스를 1로 초기화
//////	}
//////	friend Stack& operator<< (Stack& op, int n); // <<연산자 프렌드화
//////	friend bool operator! (Stack op); // !연산자 프렌드화
//////	friend void operator>> (Stack& op, int& n); // >>연산자 프렌드화
//////};
//////Stack& operator<< (Stack& op, int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//////{
//////	// op의 멤버변수들이 변경되어야하므로 참조매개변수를 사용해야 됨
//////	op.p[op.tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//////	return op; // 바뀐 객체 리턴
//////}
//////bool operator! (Stack op) // !연산자 정의 // stack에 수가 없다면 true 반환
//////{
//////	// operator>>함수에서 변경된 tos를 이용해 판단해야 됨
//////	if (op.tos == 0) // 스텍 출력이 끝나면 
//////		return true; // true 반환
//////	else
//////		return false; // stack에 수가 남아있다면 false 반환
//////}
//////void operator>> (Stack& op, int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//////{
//////	n = op.p[--op.tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//////}
//////int main()
//////{
//////	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//////	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//////						   // stack.operator<<(3).operator<<(5).operator<<(10);
//////	while (true) // 팝을 위한 반복문
//////	{
//////		if (!stack) break; // 스택 empty // stack.operator!() // operator!(stack);
//////		int x = 0; // 팝된 정수를 저장할 변수
//////		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x); // operator>>(stack,x);
//////		cout << x << ' ';
//////	}
//////	cout << endl;
//////}
////
////////12-1 // 멤버함수 이용 // 복사생성자 - 깊은 복사 // 연산자 정리 // 동적할당 // 총 정리문제
//////class SortedArray
//////{
//////    int size; // 현재 배열의 크기
//////    int* p; // 정수 배열에 대한 포인터
//////    void sort() // 정수 배열을 오름차순으로 정렬
//////    {
//////        for (int i = 0; i < size; i++)
//////        {
//////            for (int j = 0; j < size - 1; j++) 
//////            {
//////                if (p[j] > p[j + 1]) // p[j]가 p[j+1]보다 클 때 // 큰 수를 뒤로 보내기
//////                {
//////                    int n1 = p[j]; // 원래 p[j]를 n1에 저장
//////                    p[j] = p[j + 1]; // p[j]에 p[j+1] 저장
//////                    p[j + 1] = n1; // p[j+1]에 원래 p[j] 저장
//////                }
//////            }
//////        }
//////    }
//////public:
//////    SortedArray() // p는 NULL로 size는 0으로 초기화 // 기본생성자
//////    {
//////        p = nullptr; // p가 아무것도 가리키지 않음
//////        size = 0;
//////    }
//////    SortedArray(SortedArray& src) // 복사 생성자 // 깊은복사
//////    {
//////        size = src.size; // 복사하고자 하는 객체의 size 복사
//////        if (!size) // size가 0이라면
//////            p = nullptr; // p가 아무것도 가리키지 않음
//////        else
//////            p = new int[size]; // size값을 복사받았다면 그만큼 새로운 공간 동적할당
//////        for (int i = 0; i < size; i++)
//////            p[i] = src.p[i]; // 복사하고자하는 객체의 힙 공간 수를 this의 동적할당 공간에 저장
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////    }
//////    SortedArray(int p[], int size) // 매개변수가 있는 생성자, 정수 배열과 크기를 전달받음
//////    {
//////        this->size = size;
//////        this->p = new int[size]; 
//////        for (int i = 0; i < size; i++)
//////            this->p[i] = p[i];
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////    }
//////    ~SortedArray() // 소멸자
//////    {
//////        if (p)
//////            delete[] p; // 동적할당된 공간을 삭제
//////        p = nullptr; // p가 아무것도 가리키지않음을 뜻함
//////    }
//////    SortedArray operator+(SortedArray& op2) // 현재 배열에 op2 배열 추가 //+연산자 정의
//////    {
//////        SortedArray c; // 두 객체를 붙인 모든 값이 복사될 객체를 하나 더 생성
//////        c.size = this->size + op2.size; // 두 객체의 size를 더한 값을 c의 size에 저장
//////        c.p = new int[c.size](); // 저장된 size만큼 새로운 공간을 동적할당함
//////        for (int i = 0; i < this->size; i++) // c.size만큼 반복문을 돌리면 힙 영역 메모리 침범 발생
//////            c.p[i] = this->p[i]; // 인덱스 0~2까지 객체 a의 배열 값 c의 배열에 저장
//////        for (int i = 0; i < op2.size; i++)
//////            c.p[i + this->size] = op2.p[i]; // 인덱스 3~6까지 객체 b의 배열 값 c의 배열에 저장
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////        return c; // 객체 a와 b를 합한 값을 가진 객체 c를 반환 // 복사 생성
//////    }
//////    SortedArray& operator=(const SortedArray& op2) // 현재 배열에 op2 배열 복사 // = 연산자 정의
//////    {
//////        // op2의 값을 =연산자를 호출한 객체에 복사
//////        this->size = op2.size;
//////        this->p = new int[this->size]; // 주소만 복사 X , 소멸 시 얕은 복사처럼 작용 (두 객체가 하나의 힙공간을 가리켜서)
//////        for (int i = 0; i < this->size; i++)
//////            this->p[i] = op2.p[i];
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////        return *this; // 참조반환
//////    }
//////    void show() // 배열의 원소 출력
//////    {
//////        cout << "배열 출력 :";
//////        for (int i = 0; i < size; i++)
//////            cout << p[i] << ' ';
//////        cout << endl;
//////    }
//////};
//////int main()
//////{
//////    int n[] = { 2,20,6 };
//////    int m[] = { 10,7,8,30 };
//////    SortedArray a(n, 3), b(m, 4), c; // 객체값 결정
//////
//////    c = a + b; // +,= 연산자 작성 필요 // a.operator+(b); // c.operator=(a+b);
//////    // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
//////    // = 연산자 재정의 이유 : 기본적으로 컴파일러가 생성하는 =연산자는 얕은 복사만 가능 -> 깊은 복사를 할 수 있게 재정의 해줘야함
//////    // (디폴트 대입연산자가 클래스 내에 있기 때문에 복사생성자를 재정의해주는 것과 같이 대입연산자를 깊은 복사하기 위해 재정의하려면 클래스내에 멤버함수로 재정의해줘야만 한다.)
//////    a.show(); b.show(); c.show();
//////}
////
////////12-2 // 프렌드함수 이용 // 복사생성자 - 깊은 복사 // 연산자 정리 // 동적할당 // 총 정리문제
//////class SortedArray
//////{
//////    int size; // 현재 배열의 크기
//////    int* p; // 정수 배열에 대한 포인터
//////    void sort() // 정수 배열을 오름차순으로 정렬
//////    {
//////        for (int i = 0; i < size; i++)
//////        {
//////            for (int j = 0; j < size - 1; j++)
//////            {
//////                if (p[j] > p[j + 1]) // p[j]가 p[j+1]보다 클 때 // 큰 수를 뒤로 보내기
//////                {
//////                    int n1 = p[j]; // 원래 p[j]를 n1에 저장
//////                    p[j] = p[j + 1]; // p[j]에 p[j+1] 저장
//////                    p[j + 1] = n1; // p[j+1]에 원래 p[j] 저장
//////                }
//////            }
//////        }
//////    }
//////public:
//////    SortedArray() // p는 NULL로 size는 0으로 초기화 // 기본생성자
//////    {
//////        p = nullptr; // p가 아무것도 가리키지 않음
//////        size = 0;
//////    }
//////    SortedArray(SortedArray& src) // 복사 생성자 // 깊은복사
//////    {
//////        size = src.size; // 복사하고자 하는 객체의 size 복사
//////        if (!size) // size가 0이라면
//////            p = nullptr; // p가 아무것도 가리키지 않음
//////        else
//////            p = new int[size]; // size값을 복사받았다면 그만큼 새로운 공간 동적할당
//////        for (int i = 0; i < size; i++)
//////            p[i] = src.p[i]; // 복사하고자하는 객체의 힙 공간 수를 this의 동적할당 공간에 저장
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////    }
//////    SortedArray(int p[], int size) // 매개변수가 있는 생성자, 정수 배열과 크기를 전달받음
//////    {
//////        this->size = size;
//////        this->p = new int[size];
//////        for (int i = 0; i < size; i++)
//////            this->p[i] = p[i];
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////    }
//////    ~SortedArray() // 소멸자
//////    {
//////        if (p)
//////            delete[] p; // 동적할당된 공간을 삭제
//////        p = nullptr; // p가 아무것도 가리키지않음을 뜻함
//////    }
//////    void show() // 배열의 원소 출력
//////    {
//////        cout << "배열 출력 :";
//////        for (int i = 0; i < size; i++)
//////            cout << p[i] << ' ';
//////        cout << endl;
//////    }
//////    SortedArray& operator=(const SortedArray& op2) // 현재 배열에 op2 배열 복사 // = 연산자 정의
//////    {
//////        // op2의 값을 =연산자를 호출한 객체에 복사
//////        this->size = op2.size;
//////        this->p = new int[this->size]; // 주소만 복사 X , 소멸 시 얕은 복사처럼 작용 (두 객체가 하나의 힙공간을 가리켜서)
//////        for (int i = 0; i < this->size; i++)
//////            this->p[i] = op2.p[i];
//////        sort(); // 정수 배열을 오름차순으로 정렬
//////        return *this; // 참조반환
//////    }
//////    friend SortedArray operator+(SortedArray& op1, SortedArray& op2);
//////};
//////SortedArray operator+(SortedArray& op1, SortedArray& op2) // 현재 배열에 op2 배열 추가 //+연산자 정의
//////{
//////    SortedArray c; // 두 객체를 붙인 모든 값이 복사될 객체를 하나 더 생성
//////    c.size = op1.size + op2.size; // 두 객체의 size를 더한 값을 c의 size에 저장
//////    c.p = new int[c.size](); // 저장된 size만큼 새로운 공간을 동적할당함
//////    for (int i = 0; i < op1.size; i++) // c.size만큼 반복문을 돌리면 힙 영역 메모리 침범 발생
//////        c.p[i] = op1.p[i]; // 인덱스 0~2까지 객체 a의 배열 값 c의 배열에 저장
//////    for (int i = 0; i < op2.size; i++)
//////        c.p[i + op1.size] = op2.p[i]; // 인덱스 3~6까지 객체 b의 배열 값 c의 배열에 저장
//////    c.sort(); // 정수 배열을 오름차순으로 정렬
//////    return c; // 객체 a와 b를 합한 값을 가진 객체 c를 반환 // 복사 생성
//////}
//////int main()
//////{
//////    int n[] = { 2,20,6 };
//////    int m[] = { 10,7,8,30 };
//////    SortedArray a(n, 3), b(m, 4), c; // 객체값 결정
//////
//////    c = a + b; // +,= 연산자 작성 필요 
//////               // a.operator+(b); // c.operator=(a+b);
//////               // operator+(a,b); // operator=(c,a+b); - 멤버함수 불가능 - 12-1 488,489에 설명됨
//////    // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
//////
//////    a.show(); b.show(); c.show();
//////}
//
////#include <iostream>
////using namespace std;
////
////////1 // Circle 클래스를 상속받은 NamedCircle클래스 만들기
//////class Circle // 원 만드는 클래스
//////{
//////	int radius; // 반지름
//////public:
//////	Circle(int radius = 0) { this->radius = radius; } // 생성자 
//////	int getRadius() { return radius; } // radius 출력
//////	void setRadius(int radius) { this->radius = radius; } // radius 값 변경
//////	double getArea() { return 3.14 * radius * radius; } // 면적
//////};
//////class NamedCircle : public Circle // Circle에 이름을 붙이는 클래스 // 기반클래스 - Circle , 파생클래스 - NamedCircle
//////{
//////	string name; // 원의 이름
//////public:
//////	NamedCircle(int radius, string name) : Circle(radius) // 기반클래스 생성자를 파생클래스의 생성자에서 직접 호출하게끔 함
//////	{
//////		this->name = name; // 매개변수로 입력받은 radius로는 Circle 멤버변수 초기화
//////		// 입력받은 문자열로는 NamedCircled의 멤버변수 초기화
//////		// 기반클래스 생성자부터 호출 후 파생클래스 생성자 호출
//////	}
//////	void show()
//////	{
//////		cout << "반지름이 " << getRadius() << "인 " << name << endl;
//////	}
//////};
//////int main()
//////{
//////	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
//////	waffle.show();
//////}
////
////////2 // 1번을 가지고 배열을 만들어서 동작하게 함
//////class Circle // 원 만드는 클래스
//////{
//////	int radius; // 반지름
//////public:
//////	Circle(int radius = 0) { this->radius = radius; } // 생성자
//////	int getRadius() { return radius; } // radius 출력
//////	void setRadius(int radius) { this->radius = radius; } // radius 값 변경
//////	double getArea() { return 3.14 * radius * radius; } // 면적
//////};
//////class NamedCircle : public Circle // Circle에 이름을 붙이는 클래스 // 기반클래스 - Circle , 파생클래스 - NamedCircle
//////{
//////	string name; // 원의 이름
//////public:
//////	NamedCircle(int radius = 0, string name = " ") : Circle(radius) // 기반클래스 생성자를 파생클래스의 생성자에서 직접 호출하게끔 함
//////	{
//////		this->name = name; // 매개변수로 입력받은 radius로는 Circle 멤버변수 초기화
//////		// 입력받은 문자열로는 NamedCircled의 멤버변수 초기화
//////	}
//////	void setNamedCircle(int n, string name) { setRadius(n); this->name = name; } // radius는 private이므로 멤버함수로 접근
//////	string getName() { return name; } // 원 이름을 출력
//////	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
//////};
//////int main()
//////{
//////	NamedCircle pizza[5]; // 원의 이름과 반지름 길이 정보를 갖는 객체를 5개의 배열로 만듬
//////	NamedCircle a; int n(0);  string name; // 가장 큰 원의 정보를 가질 객체와 각 원의 이름과 반지름길이를 입력받을 변수 선언
//////	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cout << i + 1 << ">> ";
//////		cin >> n >> name; // 입력받은 반지름길이와 원 이름을 변수에 저장
//////		pizza[i].setNamedCircle(n, name); // 입력받은 내용들을 객체의 내용을 변경하는 함수의 매개변수로 전달
//////		if (a.getArea() < pizza[i].getArea()) // NamedCircle클래스의 객체는 Circle클래스한테 상속받았기 때문에 public으로 지정된 getArea 함수 사용 가능
//////			a = pizza[i]; // 객체의 정보를 얕은 복사함
//////	}
//////	cout << "가장 면적이 큰 피자는 " << a.getName() << "입니다."; // 가장 큰 원의 정보를 받은 객체 a의 원 이름을 함수를 통해 출력
//////}
////
////////3 // 앞과 동일 // 기반은 제공 // 파생만들기 // 접근이 가능하고 불가능한 경우 찾기
//////class Point // 기반클래스
//////{ 
//////	int x, y;
//////public:
//////	Point(int x, int y) { this->x = x; this->y = y; } // 매개변수를 가진 생성자
//////	int getX() { return x; } // x의 위치 출력
//////	int getY() { return y; } // y의 위치 출력
//////protected: // 외부접근 불가능 // 파생클래스에서만 접근가능
//////	void move(int x, int y) { this->x = x; this->y = y; } 
//////	// x와 y의 위치를 변경하는 멤버함수
//////};
//////class ColorPoint : public Point // Point클래스를 상속받은 파생클래스 ColorPoint
//////{
//////	string color;
//////public:
//////	ColorPoint(int x, int y, string color) : Point(x, y) // 기반클래스의 생성자 호출부터 함 // 그 후 파생클래스의 생성자 호출 
//////	{
//////		// 입력받은 x,y는 기반클래스의 생성자에 전달되고
//////		this->color = color; // 입력받은 문자열은 color에 저장됨
//////	}
//////	void setPoint(int x, int y) // 포인트 위치를 변경하는 함수
//////	{
//////		move(x, y); // 기반클래스에 protected로 지정되어있어서 파생클래스에선 접근할 수 있지만 외부에선 접근 불가능
//////	}
//////	void setColor(string color) // color를 변경하는 함수
//////	{
//////		this->color = color;
//////	}
//////	void show() // 클래스가 가진 색과 그 위치를 출력
//////	{
//////		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
//////	}
//////};
//////int main()
//////{
//////	ColorPoint cp(5, 5, "RED"); // ColorPoint클래스 객체 cp 선언 // 전달된 정수 두개는 x,y에 차례대로 저장 // 문자열은 color에 저장
//////	cp.setPoint(10, 20); // x,y를 변경시킬 함수 호출
//////	cp.setColor("BLUE"); // 색을 RED에서 BLUE로 변경하기위해 함수 호출
//////	cp.show(); // 객체에 저장된 정보들을 출력
//////}
////
////////4
//////class Point // 기반클래스
//////{
//////	int x, y;
//////public:
//////	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }// 매개변수를 가진 생성자
//////	int getX() { return x; } // x의 위치 출력
//////	int getY() { return y; } // y의 위치 출력
//////protected: // 외부접근 불가능 // 파생클래스에서만 접근가능
//////	void move(int x, int y) { this->x = x; this->y = y; }
//////	// x와 y의 위치를 변경하는 멤버함수
//////};
//////class ColorPoint : public Point // Point클래스를 상속받은 파생클래스 ColorPoint
//////{
//////	string color;
//////public:
//////	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) // 기반클래스의 생성자 호출부터 함 // 그 후 파생클래스의 생성자 호출 
//////	{
//////		// 디폴트값을 지정
//////		// 입력받은 x,y는 기반클래스의 생성자에 전달되고
//////		this->color = color; // 입력받은 문자열은 color에 저장됨
//////	}
//////	void setPoint(int x, int y) // 포인트 위치를 변경하는 함수
//////	{
//////		move(x, y); // 기반클래스에 protected로 지정되어있어서 파생클래스에선 접근할 수 있지만 외부에선 접근 불가능
//////	}
//////	void setColor(string color) // color를 변경하는 함수
//////	{
//////		this->color = color;
//////	}
//////	void show() // 클래스가 가진 색과 그 위치를 출력
//////	{
//////		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
//////	}
//////};
//////int main()
//////{
//////	ColorPoint zeroPoint; // BLACK 색에 (0,0) 위치의 점 // 아무것도 입력받지 않았을때 디폴트값을 확인하기 위한 객체
//////	zeroPoint.show(); // zeroPoint를 출력한다.
//////
//////	ColorPoint cp(5, 5); // x,y값은 있지만 color에 들어갈 문자열이 없기 때문에 (5,5) 위치에 color가 디폴트값인 BLACK으로 초기화된 객체 선언
//////	cp.setPoint(10, 20); // x,y를 변경시킬 함수 호출
//////	cp.setColor("BLUE"); // 색을 BLACK에서 BLUE로 변경하기위해 함수 호출
//////	cp.show(); // 객체에 저장된 정보들을 출력
//////}
////
////////5 // 기반클래스 // Queue = first in first out // enqueue, dequeue 
//////class BaseArray
//////{
//////	int capacity; // 배열의 크기
//////	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
//////protected: // 파생클래스 접근 가능 // 외부접근X
//////	BaseArray(int capacity = 100) // 생성자
//////	{
//////		this->capacity = capacity;
//////		mem = new int[capacity]();
//////	}
//////	~BaseArray() { delete[] mem; } // 소멸자 // 모든 요소들의 실행이 끝나면 마지막으로 큐의 수들이 저장되어있던 힙공간 제거
//////	void put(int index, int val) { mem[index] = val; } // 할당받은 힙 배열공간의 index에 val을 저장
//////	int get(int index) { return mem[index]; } // 할당받은 힙 배열공간의 index를 출력
//////	int getCapacity() { return capacity; } // 배열의 크기 출력
//////};
//////class MyQueue : public BaseArray // BaseArray클래스를 상속받은 파생클래스 MyQueue
//////{
//////	int head; // 큐의 머리
//////	int tail; // 큐의 꼬리
//////	int size; // 큐에 있는 수의 갯수를 세는 변수
//////public:
//////	MyQueue(int capacity) : BaseArray(capacity) // 매개변수로 입력받은 수는 기반클래스의 생성자에 전달
//////	{
//////		// MyQueue 클래스의 멤버는 아무 수도 받지않고 모두 0으로 초기화한다.
//////		head = 0; // 모두 0으로 초기화
//////		tail = 0;
//////		size = 0;
//////	}
//////	void enqueue(int n) // 큐에 입력할 때
//////	{
//////		put(tail++, n); // 꼬리의 위치에 입력받은 정수를 저장하는 BaseArray에서 상속받은 함수 put 호출
//////		// 함수실행이 끝나면 tail의 수 증가
//////		size++; // 현재 큐가 수를 얼마만큼 입력받았나를 기록
//////	}
//////	int capacity() // 큐의 총 용량 출력
//////	{
//////		return getCapacity(); // BaseArray클래스의 capacity에 직접 접근할 수 없기 때문에(private) 멤버함수를 이용한다.
//////	}
//////	int length() // 현재 큐에 들어있는 수의 갯수 출력
//////	{
//////		return size;
//////	}
//////	int dequeue() // 큐를 출력
//////	{
//////		size--; // 하나하나 수가 출력될때마다 큐에 들어있는 수의 갯수도 줄어드는 것을 의미
//////		return get(head++); // 처음입력받았던 순서대로 수를 출력
//////	}
//////};
//////int main()
//////{
//////	MyQueue mQ(100); // 큐의 총 용량을 100으로 정함
//////	int n; // 큐에 들어갈 수를 입력받을 변수 선언
//////	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cin >> n;
//////		mQ.enqueue(n); // 큐에 삽입
//////	}
//////	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//////	// 큐의 총 용량과 수가 나가기 전 큐의 크기 출력
//////	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
//////	while (mQ.length() != 0) // 현재 큐의 크기가 0이라면 반복문 종료
//////	{
//////		cout << mQ.dequeue() << " "; // 큐에서 제거하여 출력 // 출력할때마다 큐의 크기 줄어듬
//////	}
//////	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
//////	// 모든 수가 빠져나가 0이된 큐의 상황 출력
//////}
////
////////6 // stack
//////class BaseArray
//////{
//////	int capacity; // 배열의 크기
//////	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
//////protected: // 파생클래스 접근 가능 // 외부접근X
//////	BaseArray(int capacity = 100) // 생성자
//////	{
//////		this->capacity = capacity;
//////		mem = new int[capacity]();
//////	}
//////	~BaseArray() { delete[] mem; } // 소멸자 // 모든 요소들의 실행이 끝나면 마지막으로 큐의 수들이 저장되어있던 힙공간 제거
//////	void put(int index, int val) { mem[index] = val; } // 할당받은 힙 배열공간의 index에 val을 저장
//////	int get(int index) { return mem[index]; } // 할당받은 힙 배열공간의 index를 출력
//////	int getCapacity() { return capacity; } // 배열의 크기 출력
//////};
//////class MyStack : public BaseArray // BaseArray클래스를 상속받은 파생클래스 MyStack
//////{
//////	int stack; // 입력받고 출력해야하는 수의 위치
//////	int size; // 스택에 있는 수의 갯수를 세는 변수
//////public:
//////	MyStack(int capacity) : BaseArray(capacity) // 매개변수로 입력받은 수는 기반클래스의 생성자로 전달된다.
//////	{
//////		// MyQueue 클래스의 멤버는 아무 수도 받지않고 모두 0으로 초기화한다.
//////		stack = 0; // 모두 0으로 초기화
//////		size = 0;
//////	}
//////	void push(int n) // 스택에 입력할 때
//////	{
//////		put(stack++, n); // 동적할당된 힙공간에 차곡차곡 수를 쌓음
//////		// 함수실행이 끝나면 stack의 수 증가
//////		size++; // 현재 스택에 수가 얼마만큼 있나를 기록
//////	}
//////	int capacity() // 스택의 총 용량 출력
//////	{
//////		return getCapacity(); // BaseArray클래스의 capacity에 직접 접근할 수 없기 때문에 멤버함수를 이용한다.
//////	}
//////	int length() // 현재 스택에 들어있는 수의 갯수 출력
//////	{
//////		return size;
//////	}
//////	int pop() // 쌓여있는 수를 위에서부터(가장 나중에 들어간 수부터) 팝한다
//////	{
//////		size--; // 하나하나 수가 출력될때마다 스택에 들어있는 수의 갯수도 줄어드는 것을 의미
//////		return get(--stack); // 늦게 들어간 순서대로 수를 출력 
//////	}
//////};
//////int main()
//////{
//////	MyStack mStack(100); // 스택의 총 용량 전달
//////	int n; // 스택에 들어갈 수를 입력받을 변수
//////	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cin >> n;
//////		mStack.push(n); // 입력받은 수를 멤버함수를 이용해 스택에 차곡차곡 저장
//////	}
//////	cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
//////	// 스택의 총 용량과 현재 스택에 수가 얼마만큼 쌓였는지 출력
//////	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
//////	while (mStack.length() != 0) // 스택의 크기가 0이 될 때까지 반복문 돌림
//////	{
//////		cout << mStack.pop() << ' '; // 가장 나중에 수부터 차례대로 수를 꺼낸다. // 가장 처음에 들어간 수가 가장 나중에 나오게 된다. // 입력의 역순으로 출력
//////	}
//////	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
//////	// 수가 모두 빠져나간 스택의 크기 출력
//////}
////
////////8 // 그림의 구조가 정확히 동작하도록 만들어라 // 멤버에 대한 설명 있음
//////class Print
//////{
//////	string model; // 모델명
//////	string manufacturer; // 제조사
//////	int printedCount; // 인쇄 매수
//////	int availablecount; // 인쇄 종이 잔량
//////protected:
//////	Print(string model = NULL, string manufacturer = NULL, int printedCount = 0, int availablecount = 0)
//////	{
//////		// 모델명과 제조사, 인쇄종이잔량을 전달받아 초기화하는 생성자
//////		this->model = model;
//////		this->manufacturer = manufacturer;
//////		this->printedCount = printedCount;
//////		this->availablecount = availablecount;
//////	}
//////	bool print(int pages) // 프린트할 매수를 입력받으면
//////	{
//////		printedCount = pages; // 인쇄매수를 뜻하는 printedCount에 저장하고,
//////		if (availablecount < printedCount) // 현재 종이 잔량이 인쇄할 매수보다 적은지 우선적으로 확인한다.
//////		{
//////			return false; // 작다면 인쇄 실패
//////		}
//////		else // 작지않다면
//////		{
//////			availablecount -= printedCount; // 현재 종이 잔량에서 인쇄할 매수의 양을 빼 프린트했음을 표현함
//////			return true; // 프린트에 성공했음을 알림
//////		}
//////	}
//////	// 멤버 출력
//////	void get() { cout << model << " ," << manufacturer << " ,남은 종이 " << availablecount << "장 ,"; }
//////};
//////class InkJetPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 InkJetPrint
//////{
//////	int availableInk; // 잉크 잔량
//////public:
//////	InkJetPrint(string model = "Officejet V40", string manufacturer = "HP", int printedCount = 0, int availablecount = 5, int availableInk = 10) : Print(model, manufacturer, printedCount, availablecount) 
//////	{
//////		// 잉크젯프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//////		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//////		// 다른 정보들이 모두 입력된 후에 잉크 잔량을 초기화함
//////		this->availableInk = availableInk;
//////	}
//////	bool printInkJet(int pages) // 입력받은 pages만큼 프린트하는 멤버함수
//////	{
//////		if (print(pages)) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//////		{
//////			availableInk -= pages; // pages만큼의 프린트를 하기위해 pages만큼의 잉크를 사용했음을 의미
//////			return true; // 프린트 성공
//////		}
//////		else // 프린트가 불가능한 상황이라면
//////		{
//////			return false; // 프린트 실패
//////		}
//////	}
//////	void getInkJetPrint() { get(); cout << "남은 잉크 " << availableInk << endl; } // 잉크젯 프린트의 정보 출력
//////};
//////class LaserPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 LaserPrint
//////{
//////	int availableToner; // 토너 잔량
//////public:
//////	LaserPrint(string model = "SCX-6x45", string manufacturer = "삼성전자", int printedCount = 0, int availablecount = 3, int availableToner = 20) : Print(model, manufacturer, printedCount, availablecount) 
//////	{
//////		// 레이저 프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//////		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//////		// 다른 정보들이 모두 입력된 후에 토너 잔량을 초기화함
//////		this->availableToner = availableToner;
//////	}
//////	bool printLaser(int pages) // 입력받은 pages만큼 프린트하는 멤버함수
//////	{
//////		if (print(pages)) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//////		{
//////			int Toner = pages / 2;
//////			availableToner -= Toner; // pages만큼의 프린트를 하기위해 pages만큼의 토너를 사용했음을 의미
//////			return true; // 프린트 성공
//////		}
//////		else // 프린트가 불가능한 상황이라면
//////		{
//////			return false; // 프린트 실패
//////		}
//////	}
//////	void getLaserPrint() { get(); cout << "남은 토너 " << availableToner << endl; }// 레이저 프린터의 정보 출력
//////};
//////int main()
//////{
//////	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
//////	InkJetPrint* p1 = new InkJetPrint; // Print의 파생클래스 InkJetPrint의 객체포인터 p1 동적 생성
//////	LaserPrint* p2 = new LaserPrint; // Print의 파생클래스 LaserPrint의 객체포인터 p2 동적 생성
//////	cout << "잉크젯 : "; p1->getInkJetPrint(); // 잉크젯 프린터의 정보출력
//////	cout << "레이저 : "; p2->getLaserPrint(); // 레이저 프린터의 정보출력
//////	string s = "y"; // 계속 프린트할 것인지 판단하는 부분에서 필요한 변수
//////	int p, pages; // 어떤 프린터를 사용할 것인지, 얼만큼을 프린트할 것 인지를 입력받을 변수
//////	while (s != "n") // s가 "n"이라면 반복문 멈춤
//////	{
//////		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
//////		cin >> p >> pages; // 사용할 프린터의 번호와 매수를 입력받음
//////		if (p == 1) // 사용할 프린터가 잉크젯 프린터라면
//////		{
//////			if (p1->printInkJet(pages)) // printInkJet함수를 이용해 종이 잔량이 매수보다 작은지 // 프린트가 가능한지 판단
//////			{
//////				cout << "프린트하였습니다." << endl; // 가능하면 
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트가 된 후의 프린터들의 상태 출력
//////			}
//////			else // 불가능하면 // 프린트하려는 매수보다 현재 잔량이 적다면 
//////			{
//////				cout << "용지가 부족하여 프린트할 수 없습니다." << endl; // 할 수 없음을 알림
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트를 실패한 프린터들의 상태 출력
//////			}
//////		}
//////		else // 사용할 프린터가 레이저 프린터라면
//////		{
//////			if (p2->printLaser(pages)) // printLaser함수를 이용해 종이 잔량이 매수보다 작은지 // 프린트가 가능한지 판단
//////			{
//////				cout << "프린트하였습니다." << endl; // 가능하면
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트가 된 후의 프린터들의 상태 출력
//////			}
//////			else // 불가능하면 // 프린트하려는 매수보다 현재 잔량이 적다면 
//////			{
//////				cout << "용지가 부족하여 프린트할 수 없습니다." << endl; // 할 수 없음을 알림
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트를 실패한 프린터들의 상태 출력
//////			}
//////		}
//////		cout << "계속 프린트 하시겠습니까(y/n)>>"; // 계속 할 것이라면
//////		cin >> s; // s에 "y"저장 - 반복문 반복 // 계속 안할거면 s에 "n"저장 - 반복문 중단 
//////	}
//////	if (p1) // 객체포인터 p1이 할당받은 공간이 있다면
//////	{
//////		delete p1; // p1이 가리키는 공간을 삭제함
//////		p1 = nullptr; // p1이 아무곳도 가리키지 않음을 의미
//////	}
//////	if (p2) // 객체포인터 p2가 할당받은 공간이 있다면
//////	{
//////		delete p2; // p2가 가리키는 공간을 삭제함
//////		p2 = nullptr; // p2가 아무곳도 가리키지 않음을 의미
//////	}
//////}

#include <iostream>
void h(int* a) { *a = -*a; }
int ar[] = { 0,1,3,5,7 };
int& f(int n)
{
	return ar[n];
}
class Sample
{
public:
	static int a;
	int b;
	void f();
	static void h();
};
int Sample::a;
int main()
{
	Sample sample;
	sample.b = 5;
	sample.a = 5;
	Sample::f();
	Sample::h();
	//int n = 5;
	//h(&n);
	//std::cout << n;
	//f(0) = 100;
	//f(0) = f(1) + f(2) + f(3) + f(4);
	//int& v = f(2); v++;
	//for (int i = 0; i < 5; i++)
	//	std::cout << ar[i];
}