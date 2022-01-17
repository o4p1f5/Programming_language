#include <iostream>
#include <string>
using namespace std;
// 연산자 중복 - 클래스에서 연산자를 사용할 수 있도록 구현
// 멤버함수(객체 접근) or friend 함수(일반함수 접근)
// 모든 문제 멤버함수와 friend 함수로 구현

////1-1 // 멤버함수 이용
//class Book
//{
//	string title; // 책 이름을 담을 string 변수
//	int price; // 책 가격을 담을 변수
//	int pages; // 책 페이지 수를 담을 변수
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트매개변수를 이용해 작성한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 책의 정보를 출력하는 멤버함수
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 책의 제목을 출력할 멤버함수
//	Book operator+=(int money) // += 연산자를 정의한 멤버함수
//	{
//		price += money; // 입력받은 money를 현재 price에 더한 수를 price에 다시 저장
//		return *this; // 변경된 객체(a)를 반환 // 복사생성
//	}
//	Book operator-=(int money) // -= 연산자를 정의한 멤버함수
//	{
//		price -= money; // 입력받은 money를 현재 price에서 뺀 수를 price에 다시 저장
//		return *this; // 변경된 객체(b)를 반환 // 복사생성
//	}
//};
//int main()
//{
//	Book a("청춘", 20000, 300), b("미래", 30000, 500); // 객체 a와 b의 객체 정보 입력
//	a += 500; // a.operator+=(500); // operator+=(a,500);
//	b -= 500; // b.operator-=(500); // operator-=(b,500);
//	a.show(); // 객체 a의 정보 출력
//	b.show(); // 객체 b의 정보 출력
//}

////1-2 // 프렌드함수 이용
//class Book
//{
//	string title; // 책 이름을 담을 string 변수
//	int price; // 책 가격을 담을 변수
//	int pages; // 책 페이지 수를 담을 변수
//public: 
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트매개변수를 이용해 작성한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 책의 정보를 출력하는 멤버함수
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 책의 제목을 출력할 멤버함수
//	friend Book operator+=(Book& op1, int money); // 일반함수 operator+=를 프렌드화함
//	friend Book operator-=(Book& op1, int money); // 일반함수 operator-=를 프렌드화함
//};
//Book operator+=(Book& op1, int money) // 멤버함수의 경우와 달리 함수를 호출하는 객체의 정보가 바뀌지 않음
//{
//	// 참조 매개변수를 이용해 함수를 호출하는 객체의 정보도 바꿔줌
//	op1.price += money; // 입력받은 money를 op1의 price에 더한 수를 op1의 price에 다시 저장 
//	return op1; // op1 반환
//}
//Book operator-=(Book& op1, int money) // 멤버함수의 경우와 달리 함수를 호출하는 객체의 정보가 바뀌지 않음
//{
//	// 참조 매개변수를 이용해 함수를 호출하는 객체의 정보도 바꿔줌
//	op1.price -= money; // 입력받은 money를 op1의 price에서 뺀 수를 op1의 price에 다시 저장 
//	return op1; // op1 반환
//}
//int main()
//{
//	Book a("청춘", 20000, 300), b("미래", 30000, 500); // 객체 a와 b의 객체 정보 입력
//	a += 500; // a.operator+=(500); // operator+=(a,500);
//	b -= 500; // b.operator-=(500); // operator-=(b,500);
//	a.show(); // 객체 a의 정보 출력
//	b.show(); // 객체 b의 정보 출력
//}

////2-1 // 멤버함수 이용
//class Book
//{
//	string title; // 책의 이름
//	int price; // 책 가격
//	int pages; // 책의 가격
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트매개변수를 이용한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 책의 정보 출력
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 책 제목 출력
//	bool operator==(int price) // ==연산자 정의 - 가격
//	{
//		if(this->price == price) // 입력받은 price가 함수를 호출한 객체의 price와 같다면
//			return true; // true 반환
//		else // 같지 않다면
//			return false; // false 반환 
//	}
//	bool operator==(string title) // ==연산자 정의 - 제목
//	{
//		if (this->title == title) // 입력받은 title이 함수를 호출한 객체의 title과 같다면
//			return true; // true 반환
//		else // 같지 않다면
//			return false; // false 반환
//	}
//	bool operator==(Book op2) // ==연산자 정의 - 객체
//	{
//		if (this->title == op2.title && price == op2.price && pages == op2.pages)
//			// 두 객체의 모든 정보가 동일하다면 
//			return true; // true 반환
//		else // 아니면 
//			return false; // false 반환
//	}
//};
//int main()
//{
//	Book a("명품 C++", 30000, 500), b("고급 C++", 30000, 500); // 객체의 정보 입력
//	if (a == 30000)cout << "정가 30000원" << endl; // a의 price가 30000이라면 true
//	// a.operator==(30000); // operator==(a,30000);
//	if (a == "명품 C++")cout << "명품 C++ 입니다" << endl; // a의 title이 명품C++이라면 true
//	// a.operator==("명품 C++"); // operator==(a,"명품 C++");
//	if (a == b)cout << "두 책이 같은 책입니다." << endl; // a와 b의 모든 요소가 같다면 true
//	// a.operator==(b); // operator==(a,b);
//}

////2-2 // 프렌드 함수 이용
//class Book
//{
//	string title; // 책 제목
//	int price; // 책 가격
//	int pages; // 책 페이지 수
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{ 
//		// 디폴트 매개변수를 이용한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 객체의 정보 모두 출력
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 제목 출력
//	friend bool operator==(Book op1, int op2); // 가격에 대한 연산자 == 프렌드화
//	friend bool operator==(Book op1, string op2); // 제목에 대한 연산자 == 프렌드화
//	friend bool operator==(Book op1, Book op2); // 객체에 대한 연산자 == 프렌드화
//};
//bool operator==(Book op1, int op2) // 참조 할 필요 X
//{
//	if (op1.price == op2) // 객체 op1의 price가 op2와 같다면
//		return true; // true 반환
//	else // 같지 않다면
//		return false; // false 반환
//}
//bool operator==(Book op1, string op2) // 참조 할 필요 X
//{
//	if (op1.title == op2) // 객체 op1의 title이 op2와 같다면
//		return true;
//	else
//		return false;
//}
//bool operator==(Book op1, Book op2) // 참조 할 필요 X
//{
//	if (op1.title == op2.title && op1.price == op2.price && op1.pages == op2.pages)
//		return true; // true 반환
//	else // 같지 않다면
//		return false; // false 반환
//}
//int main()
//{
//	Book a("명품 C++", 30000, 500), b("고급 C++", 30000, 500); // 객체 정보 입력
//	if (a == 30000)cout << "정가 30000원" << endl; // a의 price가 30000이라면 true
//	// a.operator==(30000); // operator==(a,30000);
//	if (a == "명품 C++")cout << "명품 C++ 입니다" << endl; // a의 title이 명품C++이라면 true
//	// a.operator==("명품 C++"); // operator==(a,"명품 C++");
//	if (a == b)cout << "두 책이 같은 책입니다." << endl; // a와 b의 모든 요소가 같다면 true
//	// a.operator==(b); // operator==(a,b);
//}

////3-1 // 멤버함수 이용
//class Book
//{
//	string title; // 책의 이름
//	int price; // 책 가격
//	int pages; // 책의 가격
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트매개변수를 이용한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 책의 정보 출력
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 책 제목 출력
//	bool operator!() // ! 연산자 정의
//	{
//		if(!price) // 객체의 price가 0이라면 ! 연산자를 만나 0이 아닌 수가 된다
//			return true; // true 반환
//		else // 0이 아닌 다른 값이라면 ! 연산자를 만나 0이 된다
//			return false; // false 반환 
//	}
//};
//int main()
//{
//	Book book("벼룩시장", 0, 50); // 객체 정보 입력 // 가격 : 0
//	if (!book) cout << "공짜다" << endl; // book의 가격이 0원이라면 '공짜다' 출력
//    // book.operator!();
//}

////3-2 // 프렌드 함수 이용
//class Book
//{
//	string title; // 책 제목
//	int price; // 책 가격
//	int pages; // 책 페이지 수
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트 매개변수를 이용한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 객체의 정보 모두 출력
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 제목 출력
//	friend bool operator!(Book op1); // 연산자 ! 를 정의한 일반함수 프렌드화
//};
//bool operator!(Book op1) // ! 연산자 정의 // 복사 생성자 // 참조 필요없음
//{
//	if (!op1.price) // 객체의 price가 0이라면 ! 연산자를 만나 0이 아닌 수가 된다
//		return true; // true 반환
//	else // 0이 아닌 다른 값이라면 ! 연산자를 만나 0이 된다
//		return false; // false 반환 
//}
//int main()
//{
//	Book book("벼룩시장", 0, 50); // 객체 정보 입력 // 가격 : 0
//	if (!book) cout << "공짜다" << endl; // book의 가격이 0원이라면 '공짜다' 출력
//    // operator!(book); 
//}

////4 // friend 함수 이용 // < 연산자 // title 비교
//class Book
//{
//	string title; // 책 이름을 담을 string 변수
//	int price; // 책 가격을 담을 변수
//	int pages; // 책 페이지 수를 담을 변수
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// 디폴트매개변수를 이용해 작성한 생성자
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // 책의 정보를 출력하는 멤버함수
//	{
//		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
//	}
//	string getTitle() { return title; } // 책의 제목을 출력할 멤버함수
//	friend bool operator<(string op1, Book op2); // < 연산자를 정의한 일반함수를 프렌드화 함
//};
//bool operator<(string op1, Book op2) // < 연산자를 정의한 일반함수
//{
//	if (op1 < op2.title) // op2의 title이 입력받은 문자열보다 사전적으로 뒤에 있다면
//		return true; // true 반환
//	else // 입력받은 문자열이 더 뒤에 있다면
//		return false; // false 반환
//}
//int main()
//{
//	Book a("청춘", 20000, 300); // 객체 a 정보 입력
//	string b;
//	cout << "책 이름을 입력하세요>>";
//	getline(cin, b); // 책 이름을 입력받음
//	if (b < a) // operator<(b,a); 
//    // b.operator<(a); //b는 객체는 맞지만 클래스가 string과 Book으로 다르다 // 멤버함수로 구현 불가능
//	// 입력받은 책 이름과 객체 a의 제목 중 어떤 문자열이 사전적으로 뒤에 있나 판단
//	// 객체의 제목이 입력받은 문자열보다 더 뒤에 있다면 true 반환
//		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
//}

////5-1 // 멤버함수이용 // 4장 실습문제 1 // + 연산자 // == 연산자 // 멤버 // friend
//class Color // 클래스 Color 생성
//{
//	int red; // 멤버변수 red 생성
//	int green; // 멤버변수 green 생성
//	int blue; // 멤버변수 blue 생성
//public: // 공개
//	Color() // 기본생성자
//	{
//		red = 0; green = 0; blue = 0;
//	}
//	Color(int r, int g, int b) // 매개변수가 있는 생성자
//	{
//		red = r; green = g; blue = b; // 매개변수로 멤버변수 초기화
//	}
//	void setColor(int r, int g, int b) // 매개변수로
//	{
//		red = r; green = g; blue = b; // 멤버변수 세팅
//	}
//	void show() // 현재 멤버변수 출력
//	{
//		cout << red << ' ' << green << ' ' << blue << endl;
//	}
//	Color operator+(Color op1) // + 연산자 정의 // 복사생성(매개변수)
//	{
//		Color tmp; // 더한 값을 저장할 객체 생성 
//		tmp.red = red + op1.red; // 함수를 호출한 객체(red)의 red와 op1(blue)의 red를 합해 tmp의 red에 저장
//		tmp.green = green + op1.green; // 함수를 호출한 객체의 green와 op1의 green를 합해 tmp의 green에 저장
//		tmp.blue = blue + op1.blue; // 함수를 호출한 객체의 blue와 op1의 blue를 합해 tmp의 blue에 저장
//		return tmp; // 객체 tmp 반환
//	}
//	bool operator==(Color op1) // == 연산자 정의
//	{
//		if (red == op1.red && green == op1.green && blue == op1.blue)
//			// 함수를 호출한 객체와 op1의 모든 정보가 같다면
//			return true; // true 반환
//		else // 같지 않은게 하나라도 있다면
//			return false; // flase 반환
//	}
//};
//int main()
//{
//	Color red(255, 0, 0), blue(0, 0, 255), c;
//	c = red + blue; // red.operator+(blue); // operator+(red,blue); // 복사생성
//	c.show(); // red의 멤버변수들과 blue의 멤버변수들을 합한 값을 c에 저장 후 c의 정보 출력
//
//	Color fuchsia(255, 0, 255); // 푸크시아 꽃의 색 정보를 가진 객체 fuchsia생성
//	if (c == fuchsia) // 보라색 정보를 가진 객체 c의 멤버변수들과 fuchsia 객체의 멤버변수들이 모두 같다면
//		// c.operator==(fuchsia); // operator==(c,fuchsia);
//      cout << "보라색 맞음"; // true 반환 // fuchsia는 보라색꽃
//	else // 하나라도 같지 않다면
//		cout << "보라색 아님"; // flase 반환 // fuchsia는 보라색꽃이 아님
//}

////5-2 // 프렌드 함수 이용
//class Color // 클래스 Color 생성
//{
//	int red; // 멤버변수 red 생성
//	int green; // 멤버변수 green 생성
//	int blue; // 멤버변수 blue 생성
//public: // 공개
//	Color() // 기본생성자
//	{
//		red = 0; green = 0; blue = 0;
//	}
//	Color(int r, int g, int b) // 매개변수가 있는 생성자
//	{
//		red = r; green = g; blue = b; // 매개변수로 멤버변수 초기화
//	}
//	void setColor(int r, int g, int b) // 매개변수로
//	{
//		red = r; green = g; blue = b; // 멤버변수 세팅
//	}
//	void show() // 현재 멤버변수 출력
//	{
//		cout << red << ' ' << green << ' ' << blue << endl;
//	}
//	friend Color operator+(Color op1, Color op2);
//	friend bool operator==(Color op1, Color op2);
//};
//Color operator+(Color op1, Color op2) // + 연산자 정의
//{
//	Color tmp; // 더한 값을 저장할 객체 생성 
//	tmp.red = op2.red + op1.red; // 함수를 호출한 객체의 red와 op1의 red를 합해 tmp의 red에 저장
//	tmp.green = op2.green + op1.green; // 함수를 호출한 객체의 green와 op1의 green를 합해 tmp의 green에 저장
//	tmp.blue = op2.blue + op1.blue; // 함수를 호출한 객체의 blue와 op1의 blue를 합해 tmp의 blue에 저장
//	return tmp; // 객체 tmp 반환
//}
//bool operator==(Color op1, Color op2) // == 연산자 정의
//{
//	if (op2.red == op1.red && op2.green == op1.green && op2.blue == op1.blue)
//		// 함수를 호출한 객체와 op1의 모든 정보가 같다면
//		return true; // true 반환
//	else // 같지 않은게 하나라도 있다면
//		return false; // flase 반환
//}
//int main()
//{
//	Color red(255, 0, 0), blue(0, 0, 255), c;
//	c = red + blue; // red.operator+(blue); // operator+(red,blue);
//	c.show(); // red의 멤버변수들과 blue의 멤버변수들을 합한 값을 c에 저장 후 c의 정보 출력
//
//	Color fuchsia(255, 0, 255); // 푸크시아 꽃의 색 정보를 가진 객체 fuchsia생성
//	if (c == fuchsia) // 보라색 정보를 가진 객체 c의 멤버변수들과 fuchsia 객체의 멤버변수들이 모두 같다면
//		// c.operator==(fuchsia); // operator==(c,fuchsia);
//		cout << "보라색 맞음"; // true 반환 // fuchsia는 보라색꽃
//	else // 하나라도 같지 않다면
//		cout << "보라색 아님"; // flase 반환 // fuchsia는 보라색꽃이 아님
//}

////6-1 // 멤버함수 이용
//class Matrix // 2차원 행렬을 추상화한 Matrix 클래스
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// 디폴드 매개변수를 이용한 생성자
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2차월 행렬 출력
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	Matrix operator+(Matrix op2) // + 연산자 정의
//	{
//		Matrix tmp; // 더한 값을 저장할 새로운 객체 생성
//		for (int i = 0; i < 4; i++)
//		{
//			tmp.n[i] = n[i] + op2.n[i]; // 함수를 호출한 객체의 배열과 op2의 배열을 더한 값을 tmp 배열에 저장
//		}
//		return tmp; // tmp 반환
//	}
//	Matrix operator+=(Matrix op2) // += 연산자 정의
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			n[i] += op2.n[i]; // 함수를 호출한 객체의 배열 원소와 op2의 배열 원소를 더한값을 다시 함수를 호출한 객체의 배열에 저장
//		}
//		return *this; // 함수를 호출한 객체 반환
//	}
//	bool operator==(Matrix op2) // == 연산자 정의
//	{
//		bool same = true; // 두 객체의 배열 중 다른 원소가 있다면 두 객체의 배열은 같지 않으므로
//		// 이를 판단하기 위한 변수
//		for (int i = 0; i < 4; i++)
//		{
//			if (n[i] != op2.n[i]) // 두 객체의 배열 중 i번째 원소가 같지 않다면
//			{
//				same = false; // same 변수를 false로 변경하고
//				break; // 반복문을 빠져나옴
//			}
//		}
//		return same; // same 반환
//	}
//};
//int main()
//{
//	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
//	c = a + b; // c = a.operator+(b); // operator+(a,b);
//	a += b; // a.operator+=(b);  // operator+=(a,b);
//	a.show(); b.show(); c.show(); 
//	if (a == c) // a.operator==(c); // operator==(a,c);
//		cout << "a and c are the same" << endl;
//}

////6-2 // 프렌드 함수 이용
//class Matrix // 2차원 행렬을 추상화한 Matrix 클래스
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// 디폴드 매개변수를 이용한 생성자
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2차월 행렬 출력
//	{ 
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	friend Matrix operator+(Matrix op1, Matrix op2); // + 연산자를 정의한 일반함수 프렌드화
//	friend Matrix operator+=(Matrix& op1, Matrix op2); // +=연산자를 정의한 일반함수 프렌드화
//	friend bool operator==(Matrix op1, Matrix op2); // == 연산자를 정의한 일반함수 프렌드화
//};
//Matrix operator+(Matrix op1, Matrix op2) // + 연산자 정의
//{
//	Matrix tmp; // 두 객체를 더한 값을 저장할 새로운 객체 생성
//	for (int i = 0; i < 4; i++)
//	{
//		tmp.n[i] = op1.n[i] + op2.n[i];
//		// op1의 배열 원소와 op2의 배열 원소를 더한 값을 tmp의 배열에 저장
//	}
//	return tmp; // tmp 반환
//}
//Matrix operator+=(Matrix& op1, Matrix op2) // 객체 a의 값이 변경되어야하므로 참조매개변수 op1사용
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op1.n[i] += op2.n[i]; // 두 객체의 배열 원소를 더한 값을 op1의 배열에 저장
//	}
//	return op1; // op1 반환
//}
//bool operator==(Matrix op1, Matrix op2) // == 연산자 정의
//{
//	bool same = true; // 두 객체의 배열 중 다른 원소가 있다면 두 객체의 배열은 같지 않으므로
//	// 이를 판단하기 위한 변수
//	for (int i = 0; i < 4; i++)
//	{
//		if (op1.n[i] != op2.n[i]) // 두 객체의 배열 중 다른 부분이 있다면
//		{
//			same = false; // same을 false로 변경
//			break; // 반복문을 빠져나옴
//		}
//	}
//	return same; // same 반환
//}
//int main()
//{
//	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
//	c = a + b; // c = a.operator+(b); // operator+(a,b);
//	a += b; // a.operator+=(b);  // operator+=(a,b);
//	a.show(); b.show(); c.show(); 
//	if (a == c) // a.operator==(c); // operator==(a,c);
//		cout << "a and c are the same" << endl;
//}

////7-1 // 멤버함수 이용 // 6번 응용 // >> , << 연산자
//class Matrix // 2차원 행렬을 추상화한 Matrix 클래스
//{
//	int n[4]; 
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// 디폴드 매개변수를 이용한 생성자
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2차원 행렬 출력
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	void operator>>(int op1[]) // >> 연산자 정의
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			op1[i] = n[i]; // op1 배열에 함수를 호출한 객체의 n배열 i번째 원소 복사
//		}
//	}
//	void operator<<(int op1[]) // << 연산자 정의
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			n[i] = op1[i]; // 함수를 호출한 객체의 n배열 i번째 원소에 op1 배열 복사
//		}
//	}
//};
//int main()
//{
//	Matrix a(4, 3, 2, 1), b; // 객체 설정
//	int x[4], y[4] = { 1,2,3,4 }; // 2차원 행렬의 4개의 원소 값
//	a >> x; // a의 각 원소를 배열 x에 복사, x[]는 {4,3,2,1}
//	// a.operator>>(x); // operator>>(a,x);
//	b << y; // 배열 y의 원소값을 b의 각 원소에 설정
//	// b.operator<<(y); // operator<<(b,y);
//
//	for (int i = 0; i < 4; i++)
//		cout << x[i] << ' '; // x[] 출력
//	cout << endl;
//	b.show(); // b 객체의 원소 출력
//}

////7-2 // 프렌드함수 이용
//class Matrix
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// 디폴드 매개변수를 이용한 생성자
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2차원 행렬 출력
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	friend void operator>>(Matrix op1, int op2[]);
//	friend void operator<<(Matrix& op1, int op2[]);
//};
//void operator>>(Matrix op1, int op2[]) // >> 연산자 정의
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op2[i] = op1.n[i]; // op1 배열에 함수를 호출한 객체의 n배열 i번째 원소 복사
//	}
//}
//void operator<<(Matrix& op1, int op2[]) // << 연산자 정의 // 참조 필요 // 참조 X시, 복사생성된 객체의 값을 바꾸는것이라 메인문의 객체값 바뀌지 않음
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op1.n[i] = op2[i]; // 함수를 호출한 객체의 n배열 i번째 원소에 op1 배열 복사
//	}
//}
//int main()
//{
//	Matrix a(4, 3, 2, 1), b; // 객체 설정
//	int x[4], y[4] = { 1,2,3,4 }; // 2차원 행렬의 4개의 원소 값
//	a >> x; // a의 각 원소를 배열 x에 복사, x[]는 {4,3,2,1}
//	// a.operator>>(x); // operator>>(a,x);
//	b << y; // 배열 y의 원소값을 b의 각 원소에 설정
//	// b.operator<<(y); // operator<<(b,y);
//
//	for (int i = 0; i < 4; i++)
//		cout << x[i] << ' '; // x[] 출력
//	cout << endl;
//	b.show(); // b 객체의 원소 출력
//}