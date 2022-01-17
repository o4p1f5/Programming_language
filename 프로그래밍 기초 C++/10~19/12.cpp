#include <iostream>
using namespace std;
// 상속 - 접근지정자에 따라 접근할 수 있는 경우와 아닌 경우 찾기

////1 // Circle 클래스를 상속받은 NamedCircle클래스 만들기
//class Circle // 원 만드는 클래스
//{
//	int radius; // 반지름
//public:
//	Circle(int radius = 0) { this->radius = radius; } // 생성자 
//	int getRadius() { return radius; } // radius 출력
//	void setRadius(int radius) { this->radius = radius;} // radius 값 변경
//	double getArea() { return 3.14 * radius * radius; } // 면적
//}; 
//class NamedCircle : public Circle // Circle에 이름을 붙이는 클래스 // 기반클래스 - Circle , 파생클래스 - NamedCircle
//{
//	string name; // 원의 이름
//public:
//	NamedCircle(int radius, string name) : Circle(radius) // 기반클래스 생성자를 파생클래스의 생성자에서 직접 호출하게끔 함
//	{
//		this->name = name; // 매개변수로 입력받은 radius로는 Circle 멤버변수 초기화
//		// 입력받은 문자열로는 NamedCircled의 멤버변수 초기화
//		// 기반클래스 생성자부터 호출 후 파생클래스 생성자 호출
//	}
//	void show()
//	{
//		cout << "반지름이 " << getRadius() << "인 " << name << endl;
//	}
//};
//int main()
//{
//	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
//	waffle.show();
//}

////2 // 1번을 가지고 배열을 만들어서 동작하게 함
//class Circle // 원 만드는 클래스
//{
//	int radius; // 반지름
//public:
//	Circle(int radius = 0) { this->radius = radius; } // 생성자
//	int getRadius() { return radius; } // radius 출력
//	void setRadius(int radius) { this->radius = radius; } // radius 값 변경
//	double getArea() { return 3.14 * radius * radius; } // 면적
//};
//class NamedCircle : public Circle // Circle에 이름을 붙이는 클래스 // 기반클래스 - Circle , 파생클래스 - NamedCircle
//{
//	string name; // 원의 이름
//public:
//	NamedCircle(int radius = 0, string name = " ") : Circle(radius) // 기반클래스 생성자를 파생클래스의 생성자에서 직접 호출하게끔 함
//	{
//		this->name = name; // 매개변수로 입력받은 radius로는 Circle 멤버변수 초기화
//		// 입력받은 문자열로는 NamedCircled의 멤버변수 초기화
//	}
//	void setNamedCircle(int n, string name) { setRadius(n); this->name = name; } // radius는 private이므로 멤버함수로 접근
//	string getName() { return name; } // 원 이름을 출력
//	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
//};
//int main()
//{
//	NamedCircle pizza[5]; // 원의 이름과 반지름 길이 정보를 갖는 객체를 5개의 배열로 만듬
//	// 객체배열은 반드시 기본생성자가 호출
//
//	//NamedCircle a; int n(0);  string name; // 가장 큰 원의 정보를 가질 객체와 각 원의 이름과 반지름길이를 입력받을 변수 선언
//	//cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	cout << i + 1 << ">> ";
//	//	cin >> n >> name; // 입력받은 반지름길이와 원 이름을 변수에 저장
//	//	pizza[i].setNamedCircle(n, name); // 입력받은 내용들을 객체의 내용을 변경하는 함수의 매개변수로 전달
//	//	if (a.getArea() < pizza[i].getArea()) // NamedCircle클래스의 객체는 Circle클래스한테 상속받았기 때문에 public으로 지정된 getArea 함수 사용 가능
//	//		a = pizza[i]; // 객체의 정보를 얕은 복사함
//	//}
//	//cout << "가장 면적이 큰 피자는 " << a.getName() << "입니다."; // 가장 큰 원의 정보를 받은 객체 a의 원 이름을 함수를 통해 출력
//	int radius = 0; string name; double area = 0; int max_area_index = 0; // 가장 큰 원의 정보를 가질 객체와 각 원의 이름과 반지름길이를 입력받을 변수 선언
//	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << i + 1 << ">> ";
//		cin >> radius >> name; // 입력받은 반지름길이와 원 이름을 변수에 저장
//		pizza[i].setNamedCircle(radius, name); // 입력받은 내용들을 객체의 내용을 변경하는 함수의 매개변수로 전달
//		if (area < pizza[i].getArea()) // NamedCircle클래스의 객체는 Circle클래스한테 상속받았기 때문에 public으로 지정된 getArea 함수 사용 가능
//		{
//			area = pizza[i].getArea();
//			max_area_index = i;
//		}
//	}
//	cout << "가장 면적이 큰 피자는 " << pizza[max_area_index].getName() << "입니다."; // 가장 큰 원의 정보를 받은 객체 a의 원 이름을 함수를 통해 출력
//}

////3 // 앞과 동일 // 기반은 제공 // 파생만들기 // 접근이 가능하고 불가능한 경우 찾기
//class Point // 기반클래스
//{ 
//	int x, y;
//public:
//	Point(int x, int y) { this->x = x; this->y = y; } // 매개변수를 가진 생성자
//	int getX() { return x; } // x의 위치 출력
//	int getY() { return y; } // y의 위치 출력
//protected: // 외부접근 불가능 // 파생클래스에서만 접근가능
//	void move(int x, int y) { this->x = x; this->y = y; } 
//	// x와 y의 위치를 변경하는 멤버함수
//};
//class ColorPoint : public Point // Point클래스를 상속받은 파생클래스 ColorPoint
//{
//	string color;
//public:
//	ColorPoint(int x, int y, string color) : Point(x, y) // 기반클래스의 생성자 호출부터 함 // 그 후 파생클래스의 생성자 호출 
//	{
//		// 입력받은 x,y는 기반클래스의 생성자에 전달되고
//		this->color = color; // 입력받은 문자열은 color에 저장됨
//	}
//	void setPoint(int x, int y) // 포인트 위치를 변경하는 함수
//	{
//		move(x, y); // 기반클래스에 protected로 지정되어있어서 파생클래스에선 접근할 수 있지만 외부에선 접근 불가능
//	}
//	void setColor(string color) // color를 변경하는 함수
//	{
//		this->color = color;
//	}
//	void show() // 클래스가 가진 색과 그 위치를 출력
//	{
//		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
//	}
//};
//int main()
//{
//	ColorPoint cp(5, 5, "RED"); // ColorPoint클래스 객체 cp 선언 // 전달된 정수 두개는 x,y에 차례대로 저장 // 문자열은 color에 저장
//	cp.setPoint(10, 20); // x,y를 변경시킬 함수 호출
//	cp.setColor("BLUE"); // 색을 RED에서 BLUE로 변경하기위해 함수 호출
//	cp.show(); // 객체에 저장된 정보들을 출력
//}

////4
//class Point // 기반클래스
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }// 매개변수를 가진 생성자
//	int getX() { return x; } // x의 위치 출력
//	int getY() { return y; } // y의 위치 출력
//protected: // 외부접근 불가능 // 파생클래스에서만 접근가능
//	void move(int x, int y) { this->x = x; this->y = y; }
//	// x와 y의 위치를 변경하는 멤버함수
//};
//class ColorPoint : public Point // Point클래스를 상속받은 파생클래스 ColorPoint
//{
//	string color;
//public:
//	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) // 기반클래스의 생성자 호출부터 함 // 그 후 파생클래스의 생성자 호출 
//	{
//		// 디폴트값을 지정
//		// 입력받은 x,y는 기반클래스의 생성자에 전달되고
//		this->color = color; // 입력받은 문자열은 color에 저장됨
//	}
//	void setPoint(int x, int y) // 포인트 위치를 변경하는 함수
//	{
//		move(x, y); // 기반클래스에 protected로 지정되어있어서 파생클래스에선 접근할 수 있지만 외부에선 접근 불가능
//	}
//	void setColor(string color) // color를 변경하는 함수
//	{
//		this->color = color;
//	}
//	void show() // 클래스가 가진 색과 그 위치를 출력
//	{
//		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
//	}
//};
//int main()
//{
//	ColorPoint zeroPoint; // BLACK 색에 (0,0) 위치의 점 // 아무것도 입력받지 않았을때 디폴트값을 확인하기 위한 객체
//	zeroPoint.show(); // zeroPoint를 출력한다.
//
//	ColorPoint cp(5, 5); // x,y값은 있지만 color에 들어갈 문자열이 없기 때문에 (5,5) 위치에 color가 디폴트값인 BLACK으로 초기화된 객체 선언
//	cp.setPoint(10, 20); // x,y를 변경시킬 함수 호출
//	cp.setColor("BLUE"); // 색을 BLACK에서 BLUE로 변경하기위해 함수 호출
//	cp.show(); // 객체에 저장된 정보들을 출력
//}

////5 // 기반클래스 // Queue = first in first out // enqueue, dequeue 
//class BaseArray
//{
//	int capacity; // 배열의 크기
//	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
//protected: // 파생클래스 접근 가능 // 외부접근X
//	BaseArray(int capacity = 100) // 생성자
//	{
//		this->capacity = capacity;
//		mem = new int[capacity]();
//	}
//	~BaseArray() { delete[] mem; } // 소멸자 // 모든 요소들의 실행이 끝나면 마지막으로 큐의 수들이 저장되어있던 힙공간 제거
//	void put(int index, int val) { mem[index] = val; } // 할당받은 힙 배열공간의 index에 val을 저장
//	int get(int index) { return mem[index]; } // 할당받은 힙 배열공간의 index를 출력
//	int getCapacity() { return capacity; } // 배열의 크기 출력
//};
//class MyQueue : public BaseArray // BaseArray클래스를 상속받은 파생클래스 MyQueue
//{
//	int head; // 큐의 머리
//	int tail; // 큐의 꼬리
//	int size; // 큐에 있는 수의 갯수를 세는 변수
//public:
//	MyQueue(int capacity) : BaseArray(capacity) // 매개변수로 입력받은 수는 기반클래스의 생성자에 전달
//	{
//		// MyQueue 클래스의 멤버는 아무 수도 받지않고 모두 0으로 초기화한다.
//		head = 0; // 모두 0으로 초기화
//		tail = 0;
//		size = 0;
//	}
//	void enqueue(int n) // 큐에 입력할 때
//	{
//		put(tail++, n); // 꼬리의 위치에 입력받은 정수를 저장하는 BaseArray에서 상속받은 함수 put 호출
//		// 함수실행이 끝나면 tail의 수 증가
//		size++; // 현재 큐가 수를 얼마만큼 입력받았나를 기록
//	}
//	int capacity() // 큐의 총 용량 출력
//	{
//		return getCapacity(); // BaseArray클래스의 capacity에 직접 접근할 수 없기 때문에(private) 멤버함수를 이용한다.
//	}
//	int length() // 현재 큐에 들어있는 수의 갯수 출력
//	{
//		return size;
//	}
//	int dequeue() // 큐를 출력
//	{
//		size--; // 하나하나 수가 출력될때마다 큐에 들어있는 수의 갯수도 줄어드는 것을 의미
//		return get(head++); // 처음입력받았던 순서대로 수를 출력
//	}
//};
//int main()
//{
//	MyQueue mQ(100); // 큐의 총 용량을 100으로 정함
//	int n; // 큐에 들어갈 수를 입력받을 변수 선언
//	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> n;
//		mQ.enqueue(n); // 큐에 삽입
//	}
//	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
//	// 큐의 총 용량과 수가 나가기 전 큐의 크기 출력
//	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
//	while (mQ.length() != 0) // 현재 큐의 크기가 0이라면 반복문 종료
//	{
//		cout << mQ.dequeue() << " "; // 큐에서 제거하여 출력 // 출력할때마다 큐의 크기 줄어듬
//	}
//	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
//	// 모든 수가 빠져나가 0이된 큐의 상황 출력
//}

////6 // stack
//class BaseArray
//{
//	int capacity; // 배열의 크기
//	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
//protected: // 파생클래스 접근 가능 // 외부접근X
//	BaseArray(int capacity = 100) // 생성자
//	{
//		this->capacity = capacity;
//		mem = new int[capacity]();
//	}
//	~BaseArray() { delete[] mem; } // 소멸자 // 모든 요소들의 실행이 끝나면 마지막으로 큐의 수들이 저장되어있던 힙공간 제거
//	void put(int index, int val) { mem[index] = val; } // 할당받은 힙 배열공간의 index에 val을 저장
//	int get(int index) { return mem[index]; } // 할당받은 힙 배열공간의 index를 출력
//	int getCapacity() { return capacity; } // 배열의 크기 출력
//};
//class MyStack : public BaseArray // BaseArray클래스를 상속받은 파생클래스 MyStack
//{
//	int stack; // 입력받고 출력해야하는 수의 위치
//	int size; // 스택에 있는 수의 갯수를 세는 변수
//public:
//	MyStack(int capacity) : BaseArray(capacity) // 매개변수로 입력받은 수는 기반클래스의 생성자로 전달된다.
//	{
//		// MyQueue 클래스의 멤버는 아무 수도 받지않고 모두 0으로 초기화한다.
//		stack = 0; // 모두 0으로 초기화
//		size = 0;
//	}
//	void push(int n) // 스택에 입력할 때
//	{
//		put(stack++, n); // 동적할당된 힙공간에 차곡차곡 수를 쌓음
//		// 함수실행이 끝나면 stack의 수 증가
//		size++; // 현재 스택에 수가 얼마만큼 있나를 기록
//	}
//	int capacity() // 스택의 총 용량 출력
//	{
//		return getCapacity(); // BaseArray클래스의 capacity에 직접 접근할 수 없기 때문에 멤버함수를 이용한다.
//	}
//	int length() // 현재 스택에 들어있는 수의 갯수 출력
//	{
//		return size;
//	}
//	int pop() // 쌓여있는 수를 위에서부터(가장 나중에 들어간 수부터) 팝한다
//	{
//		size--; // 하나하나 수가 출력될때마다 스택에 들어있는 수의 갯수도 줄어드는 것을 의미
//		return get(--stack); // 늦게 들어간 순서대로 수를 출력 
//	}
//};
//int main()
//{
//	MyStack mStack(100); // 스택의 총 용량 전달
//	int n; // 스택에 들어갈 수를 입력받을 변수
//	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> n;
//		mStack.push(n); // 입력받은 수를 멤버함수를 이용해 스택에 차곡차곡 저장
//	}
//	cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
//	// 스택의 총 용량과 현재 스택에 수가 얼마만큼 쌓였는지 출력
//	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
//	while (mStack.length() != 0) // 스택의 크기가 0이 될 때까지 반복문 돌림
//	{
//		cout << mStack.pop() << ' '; // 가장 나중에 수부터 차례대로 수를 꺼낸다. // 가장 처음에 들어간 수가 가장 나중에 나오게 된다. // 입력의 역순으로 출력
//	}
//	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
//	// 수가 모두 빠져나간 스택의 크기 출력
//}

////8 // 그림의 구조가 정확히 동작하도록 만들어라 // 멤버에 대한 설명 있음
//class Print
//{
//	string model; // 모델명
//	string manufacturer; // 제조사
//	int printedCount; // 인쇄 매수
//	int availablecount; // 인쇄 종이 잔량
//protected:
//	Print(string model = NULL, string manufacturer = NULL, int printedCount = 0, int availablecount = 0)
//	{
//		// 모델명과 제조사, 인쇄종이잔량을 전달받아 초기화하는 생성자
//		this->model = model;
//		this->manufacturer = manufacturer;
//		this->printedCount = printedCount;
//		this->availablecount = availablecount;
//	}
//	bool print(int pages) // 프린트할 매수를 입력받으면
//	{
//		printedCount = pages; // 인쇄매수를 뜻하는 printedCount에 저장하고,
//		if (availablecount < printedCount) // 현재 종이 잔량이 인쇄할 매수보다 적은지 우선적으로 확인한다.
//		{
//			return false; // 작다면 인쇄 실패
//		}
//		else // 작지않다면
//		{
//			availablecount -= printedCount; // 현재 종이 잔량에서 인쇄할 매수의 양을 빼 프린트했음을 표현함
//			return true; // 프린트에 성공했음을 알림
//		}
//	}
//	// 멤버 출력
//	void get() { cout << model << " ," << manufacturer << " ,남은 종이 " << availablecount << "장 ,"; }
//};
//class InkJetPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 InkJetPrint
//{
//	int availableInk; // 잉크 잔량
//public:
//	InkJetPrint(string model = "Officejet V40", string manufacturer = "HP", int printedCount = 0, int availablecount = 5, int availableInk = 10) : Print(model, manufacturer, printedCount, availablecount) 
//	{
//		// 잉크젯프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//		// 다른 정보들이 모두 입력된 후에 잉크 잔량을 초기화함
//		this->availableInk = availableInk;
//	}
//	bool printInkJet(int pages) // 입력받은 pages만큼 프린트하는 멤버함수
//	{
//		if (print(pages)) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//		{
//			availableInk -= pages; // pages만큼의 프린트를 하기위해 pages만큼의 잉크를 사용했음을 의미
//			return true; // 프린트 성공
//		}
//		else // 프린트가 불가능한 상황이라면
//		{
//			return false; // 프린트 실패
//		}
//	}
//	void getInkJetPrint() { get(); cout << "남은 잉크 " << availableInk << endl; } // 잉크젯 프린트의 정보 출력
//};
//class LaserPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 LaserPrint
//{
//	int availableToner; // 토너 잔량
//public:
//	LaserPrint(string model = "SCX-6x45", string manufacturer = "삼성전자", int printedCount = 0, int availablecount = 3, int availableToner = 20) : Print(model, manufacturer, printedCount, availablecount) 
//	{
//		// 레이저 프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//		// 다른 정보들이 모두 입력된 후에 토너 잔량을 초기화함
//		this->availableToner = availableToner;
//	}
//	bool printLaser(int pages) // 입력받은 pages만큼 프린트하는 멤버함수
//	{
//		if (print(pages)) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//		{
//			int Toner = pages / 2;
//			availableToner -= Toner; // pages만큼의 프린트를 하기위해 pages만큼의 토너를 사용했음을 의미
//			return true; // 프린트 성공
//		}
//		else // 프린트가 불가능한 상황이라면
//		{
//			return false; // 프린트 실패
//		}
//	}
//	void getLaserPrint() { get(); cout << "남은 토너 " << availableToner << endl; }// 레이저 프린터의 정보 출력
//};
//int main()
//{
//	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
//	InkJetPrint* p1 = new InkJetPrint; // Print의 파생클래스 InkJetPrint의 객체포인터 p1 동적 생성
//	LaserPrint* p2 = new LaserPrint; // Print의 파생클래스 LaserPrint의 객체포인터 p2 동적 생성
//	cout << "잉크젯 : "; p1->getInkJetPrint(); // 잉크젯 프린터의 정보출력
//	cout << "레이저 : "; p2->getLaserPrint(); // 레이저 프린터의 정보출력
//	string s = "y"; // 계속 프린트할 것인지 판단하는 부분에서 필요한 변수
//	int p, pages; // 어떤 프린터를 사용할 것인지, 얼만큼을 프린트할 것 인지를 입력받을 변수
//	while (s != "n") // s가 "n"이라면 반복문 멈춤
//	{
//		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
//		cin >> p >> pages; // 사용할 프린터의 번호와 매수를 입력받음
//		if (p == 1) // 사용할 프린터가 잉크젯 프린터라면
//		{
//			if (p1->printInkJet(pages)) // printInkJet함수를 이용해 종이 잔량이 매수보다 작은지 // 프린트가 가능한지 판단
//			{
//				cout << "프린트하였습니다." << endl; // 가능하면 
//				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트가 된 후의 프린터들의 상태 출력
//			}
//			else // 불가능하면 // 프린트하려는 매수보다 현재 잔량이 적다면 
//			{
//				cout << "용지가 부족하여 프린트할 수 없습니다." << endl; // 할 수 없음을 알림
//				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트를 실패한 프린터들의 상태 출력
//			}
//		}
//		else // 사용할 프린터가 레이저 프린터라면
//		{
//			if (p2->printLaser(pages)) // printLaser함수를 이용해 종이 잔량이 매수보다 작은지 // 프린트가 가능한지 판단
//			{
//				cout << "프린트하였습니다." << endl; // 가능하면
//				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트가 된 후의 프린터들의 상태 출력
//			}
//			else // 불가능하면 // 프린트하려는 매수보다 현재 잔량이 적다면 
//			{
//				cout << "용지가 부족하여 프린트할 수 없습니다." << endl; // 할 수 없음을 알림
//				p1->getInkJetPrint(); p2->getLaserPrint(); // 프린트를 실패한 프린터들의 상태 출력
//			}
//		}
//		cout << "계속 프린트 하시겠습니까(y/n)>>"; // 계속 할 것이라면
//		cin >> s; // s에 "y"저장 - 반복문 반복 // 계속 안할거면 s에 "n"저장 - 반복문 중단 
//	}
//	if (p1) // 객체포인터 p1이 할당받은 공간이 있다면
//	{
//		delete p1; // p1이 가리키는 공간을 삭제함
//		p1 = nullptr; // p1이 아무곳도 가리키지 않음을 의미
//	}
//	if (p2) // 객체포인터 p2가 할당받은 공간이 있다면
//	{
//		delete p2; // p2가 가리키는 공간을 삭제함
//		p2 = nullptr; // p2가 아무곳도 가리키지 않음을 의미
//	}
//}

//// 재풀이 // 접근지정자 파악 잘하기
//class Print
//{
//	string model; // 모델명
//	string manufacturer; // 제조사
//	int printedCount; // 인쇄 매수
//	int availablecount; // 인쇄 종이 잔량
//public:
//	Print(string model = NULL, string manufacturer = NULL, int availablecount = 0)
//	{
//		// 모델명과 제조사, 인쇄종이잔량을 전달받아 초기화하는 생성자
//		this->model = model;
//		this->manufacturer = manufacturer;
//		this->printedCount = 0;
//		this->availablecount = availablecount;
//	}
//protected:
//	int getPrintCount() { return printedCount; }
//	int getavailablecount() { return availablecount; }
//	void print() // 프린트할 매수를 입력받으면
//	{
//		availablecount--; printedCount++; // 현재 종이 잔량이 인쇄할 매수보다 적은지 우선적으로 확인한다.
//	}
//	// 멤버 출력
//	void show() { cout << model << " ," << manufacturer << " ,남은 종이 " << availablecount << "장 ,"; }
//};
//class InkJetPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 InkJetPrint
//{
//	int availableInk; // 잉크 잔량
//public:
//	InkJetPrint(string model, string manufacturer, int availablecount , int availableInk) : Print(model, manufacturer, availablecount)
//	{
//		// 잉크젯프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//		// 다른 정보들이 모두 입력된 후에 잉크 잔량을 초기화함
//		this->availableInk = availableInk;
//	}
//	void printInkJet(int pages = 1) // 입력받은 pages만큼 프린트하는 멤버함수
//	{
//		if (getavailablecount() < pages) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//		{
//			cout << "용지가 부족하여 출력할 수 없습니다." << endl;
//			return;
//		}
//		for (int i = 0; i < pages; i++)
//		{
//			print();
//			availableInk--;
//		}
//	}
//	void getInkJetPrint() { show(); cout << "남은 잉크 " << availableInk << endl; } // 잉크젯 프린트의 정보 출력
//};
//class LaserPrint : public Print // 기반클래스 Print를 상속받은 파생클래스 LaserPrint
//{
//	int availableToner; // 토너 잔량
//public:
//	LaserPrint(string model, string manufacturer, int availablecount, int availableToner) : Print(model, manufacturer, availablecount)
//	{
//		// 레이저 프린터의 모델명, 제조사, 인쇄종이잔량 정보는 Print생성자에 전달
//		// 기반클래스의 생성자가 실행되면 그 후 파생클래스의 생성자가 실행되기때문에
//		// 다른 정보들이 모두 입력된 후에 토너 잔량을 초기화함
//		this->availableToner = availableToner;
//	}
//	void printLaser(int pages = 1) // 입력받은 pages만큼 프린트하는 멤버함수
//	{
//		if (getavailablecount() < pages) // 기반클래스의 멤버함수 호출 // 프린트에 성공했다면
//		{
//			cout << "용지가 부족하여 출력할 수 없습니다." << endl;
//			return;
//		}
//		for (int i = 0; i < pages; i++)
//		{
//			print();
//			availableToner--;
//		}
//	}
//	void getLaserPrint() { show(); cout << "남은 토너 " << availableToner << endl; }// 레이저 프린터의 정보 출력
//};
//int main()
//{
//	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
//	InkJetPrint* p1 = new InkJetPrint("Officejet V40","HP",  5, 10); // Print의 파생클래스 InkJetPrint의 객체포인터 p1 동적 생성
//	LaserPrint* p2 = new LaserPrint("SCX-6x45","삼성전자", 3, 20); // Print의 파생클래스 LaserPrint의 객체포인터 p2 동적 생성
//	cout << "잉크젯 : "; p1->getInkJetPrint(); // 잉크젯 프린터의 정보출력
//	cout << "레이저 : "; p2->getLaserPrint(); // 레이저 프린터의 정보출력
//	string s = "y"; // 계속 프린트할 것인지 판단하는 부분에서 필요한 변수
//	int p, pages; // 어떤 프린터를 사용할 것인지, 얼만큼을 프린트할 것 인지를 입력받을 변수
//	while (true) // s가 "n"이라면 반복문 멈춤
//	{
//		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
//		cin >> p >> pages; // 사용할 프린터의 번호와 매수를 입력받음
//		switch (p)
//		{
//		case 1:
//			p1->printInkJet(pages);
//			break;
//		case 2:
//			p2->printLaser(pages);
//			break;
//		default:
//			cout << "잘못된 입력입니다." << endl;
//			continue;
//		}
//		p1->getInkJetPrint();
//		p2->getLaserPrint();
//		cout << "계속 프린트 하시겠습니까(y/n)>>"; // 계속 할 것이라면
//		cin >> s; // s에 "y"저장 - 반복문 반복 // 계속 안할거면 s에 "n"저장 - 반복문 중단 
//		if (s == "y")
//			continue;
//		else
//			break;
//	}
//	if (p1) // 객체포인터 p1이 할당받은 공간이 있다면
//	{
//		delete p1; // p1이 가리키는 공간을 삭제함
//		p1 = nullptr; // p1이 아무곳도 가리키지 않음을 의미
//	}
//	if (p2) // 객체포인터 p2가 할당받은 공간이 있다면
//	{
//		delete p2; // p2가 가리키는 공간을 삭제함
//		p2 = nullptr; // p2가 아무곳도 가리키지 않음을 의미
//	}
//}