#include <iostream>
using namespace std;

// 오버라이딩 // 추상클래스 - 객체를 만들 수 없음

////1 
//class Converter // 순수가상함수를 가진 추상클래스 - 객체만들 수 없음
//{
//protected:
//	double ratio;
//	virtual double convert(double src) = 0; // src를 다른 단위로 변환한다. // 가상함수
//	virtual string getSourceString() = 0; // src 단위 명칭 // 가상함수
//	virtual string getDestString() = 0; // dest 단위 명칭 // 가상함수
//public:
//	Converter(double ratio) {this->ratio = ratio;} // Converter클래스의 생성자
//	void run() // 명령창에 떠야하는 내용들을 담고 있는 함수
//	{
//		double src; // 변환됐으면 하는 값을 받는 지역변수
//		// 가상함수를 호출하면 파생클래스의 오버라이딩된 함수를 호출
//		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
//		// 변환 전의 단위 이름을 getSourceString()를 이용해 출력하고
//		// 변환 후의 단위 이름을 getDestString()을 이용해 출력한다
//		cout << getSourceString() << "을 입력하세요>> ";
//		cin >> src; // 변환하고자 하는 수를 입력하면
//		cout << "변환 결과 :" << convert(src) << getDestString() << endl; 
//		// convert함수에 넘겨줘 변환한다 // 이때 기본클래스는 순수가상함수를 가진 추상클래스이기때문에 파생클래스에 오버라이딩된 함수를 실행한다
//	}
//};
//class WonToDollar : public Converter // Converter클래스를 상속받은 파생클래스
//{
//public:
//	WonToDollar(double ratio) : Converter(ratio)// 컴파일러가 자동으로 Converter의 기본생성자 호출
//	{
//		// WonToDollar는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	// 가상함수를 오버라이딩하지않으면 추상클래스를 상속받은 파생클래스는 추상클래스가 돼서 객체를 선언할 수 없다.
//	// 오버라이딩할때는 virtual 생략
//	virtual double convert(double src) // 추상클래스의 가상함수 오버라이딩
//	{
//		// 1달러 = 1010원 // 입력받은 수의 단위를 변환하는 함수로 재정의
//		return src / ratio;
//	}
//	virtual string getSourceString() // 추상클래스의 가상함수 오버라이딩
//	{
//		return "원"; // 변환되기전의 단위의 명칭을 반환하는 함수로 재정의
//	}
//	virtual string getDestString() // 추상클래스의 가상함수 오버라이딩
//	{
//		return "달러"; // 변환된 단위의 명칭을 반환하는 함수로 재정의
//	}
//};
//int main()
//{
//	WonToDollar wd(1010); // 추상클래스를 상속받은 파생클래스는 추상클래스가 된다 -> 가상함수를 재정의하면 해결됨
//	wd.run(); // 기반클래스의 run 호출 // pubic이라 접근 가능
//}

////2 // 1번 이용
//class Converter
//{
//protected:
//	double ratio;
//	virtual double convert(double src) = 0; // src를 다른 단위로 변환한다. // 가상함수
//	virtual string getSourceString() = 0; // src 단위 명칭 // 가상함수
//	virtual string getDestString() = 0; // dest 단위 명칭 // 가상함수
//public:
//	Converter(double ratio) { this->ratio = ratio; } // Converter클래스의 생성자
//	void run() // 명령창에 떠야하는 내용들을 담고 있는 함수
//	{
//		double src; // 변환됐으면 하는 값을 받는 지역변수
//		// 가상함수를 호출하면 파생클래스의 오버라이딩된 함수를 호출
//		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
//		// 변환 전의 단위 이름을 getSourceString()를 이용해 출력하고
//		// 변환 후의 단위 이름을 getDestString()을 이용해 출력한다
//		cout << getSourceString() << "을 입력하세요>> ";
//		cin >> src; // 변환하고자 하는 수를 입력하면
//		cout << "변환 결과 :" << convert(src) << getDestString() << endl;
//		// convert함수에 넘겨줘 변환한다 // 이때 기본클래스는 순수가상함수를 가진 추상클래스이기때문에 파생클래스에 오버라이딩된 함수를 실행한다
//	}
//};
//class KmToMile : public Converter // Converter클래스를 상속받은 파생클래스
//{
//public:
//	KmToMile(double ratio) : Converter(ratio)// 컴파일러가 자동으로 Converter의 기본생성자 호출
//	{
//		// KmToMile는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	// 가상함수를 오버라이딩하지않으면 추상클래스를 상속받은 파생클래스는 추상클래스가 돼서 객체를 선언할 수 없다.
//	// 오버라이딩할때는 virtual 생략
//	virtual double convert(double src) // 추상클래스의 가상함수 오버라이딩
//	{
//		// 1mile은 1.609344km // 입력받은 수의 단위를 변환하는 함수로 재정의
//		return src / ratio;
//	}
//	virtual string getSourceString() // 추상클래스의 가상함수 오버라이딩
//	{
//		return "Km"; // 변환되기전의 단위의 명칭을 반환하는 함수로 재정의
//	}
//	virtual string getDestString() // 추상클래스의 가상함수 오버라이딩
//	{
//		return "Mile"; // 변환된 단위의 명칭을 반환하는 함수로 재정의
//	}
//};
//int main()
//{
//	KmToMile toMile(1.609344);
//	toMile.run();
//}

//////3
//class LoopAdder // 추상클래스
//{
//	string name; // 루프의 이름
//	int x, y, sum; // x에서 y까지의 합은 sum
//	void read(); // x,y 값을 읽어 들이는 함수
//	void write(); // sum을 출력하는 함수
//protected:
//	LoopAdder(string name = "") // 루프의 이름을 받는다. 초깃값은 ""
//	{
//		this->name = name;
//		x = 0; y = 0; sum = 0;
//	}
//	int getX() { return x; }
//	int getY() { return y; }
//	virtual int calculate() = 0; // 순수가상함수, 루프를 돌며 합을 구하는 함수
//public :
//	void run(); // 연산을 진행하는 함수
//};
//void LoopAdder::read() // x,y 입력
//{
//	cout << name << ":" << endl;
//	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
//	cin >> x >> y;
//}
//void LoopAdder::write() // 결과 sum 출력
//{
//	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다." << endl;
//}
//void LoopAdder::run()
//{
//	read(); // x,y를 읽는다.
//	sum = calculate(); // 파생클래스의 calculate 호출 // 이때 sum은 LoopAdder의 멤버변수
//	// 루프를 돌면서 계산한다.
//	write(); // 결과 sum을 출력한다.
//}
//class ForLoopAdder : public LoopAdder
//{
//public:
//	ForLoopAdder(string name) : LoopAdder(name) {} 
//	int calculate()
//	{
//		int sum = 0; // 이때 sum은 지역변수
//		for (int i = getX(); i <= getY(); i++)
//		{
//			sum += i;
//		}
//		return sum;
//	}
//};
//int main()
//{
//	ForLoopAdder forLoop("For Loop");
//	forLoop.run();
//}

////4 // 3번은 while, do while로 바꾸기
//class LoopAdder // 추상클래스
//{
//	string name; // 루프의 이름
//	int x, y, sum; // x에서 y까지의 합은 sum
//	void read(); // x,y 값을 읽어 들이는 함수
//	void write(); // sum을 출력하는 함수
//protected:
//	LoopAdder(string name = "") // 루프의 이름을 받는다. 초깃값은 ""
//	{
//		this->name = name;
//		x = 0; y = 0; sum = 0;
//	}
//	int getX() { return x; }
//	int getY() { return y; }
//	virtual int calculate() = 0; // 순수가상함수, 루프를 돌며 합을 구하는 함수
//public:
//	void run(); // 연산을 진행하는 함수
//};
//void LoopAdder::read() // x,y 입력
//{
//	cout << name << ":" << endl;
//	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
//	cin >> x >> y;
//}
//void LoopAdder::write() // 결과 sum 출력
//{
//	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다." << endl;
//}
//void LoopAdder::run()
//{
//	read(); // x,y를 읽는다.
//	sum = calculate(); // run함수를 호출한 객체의 파생클래스의 calculate 호출 // 이때 sum은 LoopAdder의 멤버변수
//	// 루프를 돌면서 계산한다.
//	write(); // 결과 sum을 출력한다.
//}
//class WhileLoopAdder : public LoopAdder // 루프함수를 오버라이딩 -> while 반복문
//{
//public:
//	WhileLoopAdder(string name) : LoopAdder(name) {} // 생성자
//	// 입력받은 문자열을 추상클래스의 생성자에 전달하는 역할
//	int calculate()
//	{
//		int sum = 0; // 이때 sum은 지역변수
//		int i = getX(); // x를 i에 대입
//		while (i <= getY()) // i가 y가 되기전까지 while문 반복문
//		{
//			sum += i; // 현재 sum에 i를 더한 후 sum에 저장
//			i++; // i에 + 1
//		}
//		return sum; // x ~ y까지 더한 수를 반환
//	}
//};
//class DowhileLoopAdder : public LoopAdder // 루프함수를 오버라이딩 -> do - while 반복문
//{
//public:
//	DowhileLoopAdder(string name) : LoopAdder(name) {}
//	// 입력받은 문자열을 추상클래스의 생성자에 전달하는 역할
//	int calculate()
//	{
//		int sum = 0; // 이때 sum은 지역변수
//		int i = getX(); // x를 i에 대입
//		do{ 
//			sum += i; // 현재 sum에 i를 더한 후 sum에 저장
//			i++; // i에 + 1
//		} while (i <= getY()); // i가 y가 되기전까지 do - while문 반복문
//		return sum; // x ~ y까지 더한 수를 반환
//	}
//};
//int main()
//{
//	WhileLoopAdder whileLoop("While Loop"); // while문 돌리는 클래스
//	DowhileLoopAdder dowhileLoop("Do while Loop"); // do-while문 돌리는 클래스
//
//	whileLoop.run();
//	dowhileLoop.run();
//}//

////5 // and = && // or = || // xor = ^(비트 연산자 - 이때 bool형 자료형을 사용해야 xor의 기능을 함)
//class AbstractGate // 추상게이트
//{
//protected:
//	bool x, y; // 파생클래스만 접근 가능
//public:
//	void set(bool x, bool y) { this->x = x; this->y = y; }
//	virtual bool operation() = 0; // 가상함수 - 오버라이딩필요 // 연산함수
//};
//class ANDGate : public AbstractGate // 게이트의 AND연산을 수행하는 클래스
//{
//public:
//	bool operation() // 연산 // 오버라이딩 함수
//	{
//		//if (x && y) // AND 연산
//		//	return true; // 모두 1 일때 true 반환
//		//else
//		//	return false; // 아니면 false 반환
//		return x && y;
//	}
//};
//class ORGate : public AbstractGate // 게이트의 OR연산을 수행하는 클래스
//{
//public:
//	bool operation() // 연산 // 오버라이딩 함수
//	{
//		//if (x || y) // OR 연산
//		//	return true; // 1이 하나라도 있다면 true 반환
//		//else
//		//	return false;
//		return x || y;
//	}
//};
//class XORGate : public AbstractGate // 게이트의 XOR연산을 수행하는 클래스
//{
//public:
//	bool operation() // 연산 // 오버라이딩 함수
//	{
//		//if (x ^ y) // 비트 연산자 - bool형 자료형을 사용하면 xor의 기능을 함)
//		//	return true; // 1이 홀수 개 있는 경우
//		//else
//		//	return false;
//		return x ^ y;
//	}
//};
//int main()
//{
//	ANDGate andGate; // AND 계산 클래스의 객체
//	ORGate orGate; // OR 계산 클래스의 객체
//	XORGate xorGate; // XOR 계산 클래스의 객체
//
//	andGate.set(true, false); // 객체의 x,y에 0,1 저장
//	orGate.set(true, false); // 객체의 x,y에 0,1 저장
//	xorGate.set(true, false); // 객체의 x,y에 0,1 저장
//	cout.setf(ios::boolalpha); // 불린 값을 "true", "flase" 문자열로 출력할 것을 지시
//	cout << andGate.operation() << endl; // x,y의 AND 결과는 false
//	cout << orGate.operation() << endl; //  x,y의 OR 결과는 true
//	cout << xorGate.operation() << endl; // x,y의 XOR 결과는 true
//}

////7 // 순수가상함수가 아닌 가상함수 // 오버라이딩
//class Shape // 도형을 그리는 기반 클래스 // 순수가상함수를 가지지않았으므로 추상클래스는 아니다
//{
//protected:
//	string name; // 도형의 이름
//	int width, height; // 도형이 내접하는 사각형의 너비와 높이
//public:
//	Shape(string n = "", int w = 0, int h = 0) { name = n, width = w; height = h; }
//	// 기반 클래스의 생성자
//	virtual double getArea() { return 0; } // 도형의 넓이는 구하는 함수를 가상함수로 만든다 
//	// 함수를 호출시킨 객체의 클래스에 오버라이딩된 함수를 실행한다
//	string getName() { return name; } // 이름을 반환하는 함수
//};
//class Oval : public Shape // Shape를 상속받는 타원 클래스
//{
//public:
//	Oval(string n, int w, int h) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Oval는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 타원의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height * 3.14;
//	}
//};
//class Rect : public Shape // Shape를 상속받는 직사각형 클래스
//{ 
//public:
//	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Rect는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 직사각형의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height;
//	}
//};
//class Triangular : public Shape // Shape를 상속받는 삼각형 클래스
//{
//public:
//	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Triangular는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 삼각형의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height * 0.5;
//	}
//};
//int main()
//{
//	Shape* p[3]; // 기반클래스의 포인터배열
//	p[0] = new Oval("빈대떡", 10, 20); // 업캐스팅 // p[0]에 자료형이 Oval인 공간을 만들고 내용 저장
//	p[1] = new Rect("찰떡", 30, 40); // 업캐스팅 // p[1]에 자료형이 Rect인 공간을 만들고 내용 저장
//	p[2] = new Triangular("토스트", 30, 40); // 업캐스팅 // p[2]에 자료형이 Triangular인 공간을 만들고 내용 저장
//	for (int i = 0; i < 3; i++)
//		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
//	// p[i]->getName() 는 기반클래스의 함수를 호출
//	// p[i]->getArea()는 각 자료형의 오버라이딩된 함수 호출
//	for (int i = 0; i < 3; i++) delete p[i]; // 동적할당된 p[i]의 공간 삭제
//}

////8 // 7번에서 가상함수를 순수가상함수로 만들면 끝
//class Shape // 도형을 그리는 기반 클래스 // 순수가상함수를 가진 추상클래스
//{
//protected:
//	string name; // 도형의 이름
//	int width, height; // 도형이 내접하는 사각형의 너비와 높이
//public:
//	Shape(string n = "", int w = 0, int h = 0) { name = n, width = w; height = h; }
//	// 기반 클래스의 생성자
//	virtual double getArea() = 0; // 도형의 넓이는 구하는 함수를 순수가상함수로 만든다 
//	string getName() { return name; } // 이름을 반환하는 함수
//};
//class Oval : public Shape // Shape를 상속받는 타원 클래스
//{
//public:
//	Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Oval는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 타원의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height * 3.14;
//	}
//};
//class Rect : public Shape // Shape를 상속받는 직사각형 클래스
//{
//public:
//	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Rect는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 직사각형의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height;
//	}
//};
//class Triangular : public Shape // Shape를 상속받는 삼각형 클래스
//{
//public:
//	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// 컴파일러가 자동으로 Shape의 기본생성자 호출
//	{
//		// Triangular는 멤버변수 X , 생성자 기능 X -> 기반클래스의 생성자
//	}
//	double getArea() // 삼각형의 넓이를 구하는 함수로 기반클래스의 가상함수 오버라이딩
//	{
//		return (double)width * (double)height * 0.5;
//	}
//};
//int main()
//{
//	Shape* p[3]; // 기반클래스의 포인터배열
//	p[0] = new Oval("빈대떡", 10, 20); // 업캐스팅 // p[0]에 자료형이 Oval인 공간을 만들고 내용 저장
//	p[1] = new Rect("찰떡", 30, 40); // 업캐스팅 // p[1]에 자료형이 Rect인 공간을 만들고 내용 저장
//	p[2] = new Triangular("토스트", 30, 40); // 업캐스팅 // p[2]에 자료형이 Triangular인 공간을 만들고 내용 저장
//	for (int i = 0; i < 3; i++)
//		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
//	// p[i]->getName() 는 기반클래스의 함수를 호출
//	// p[i]->getArea()는 각 자료형의 오버라이딩된 함수 호출
//	for (int i = 0; i < 3; i++) delete p[i]; // 동적할당된 p[i]의 공간 삭제
//}