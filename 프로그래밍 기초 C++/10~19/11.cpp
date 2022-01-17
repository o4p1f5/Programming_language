#include <iostream>
using namespace std;

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

////8-1 // 멤버함수 이용 // 단항 연산자 - 전위, 후위
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//	Circle operator++() // 전위++ 구현
//	{
//		this->radius++;
//		return *this; // a 반환
//	}
//	Circle operator++(int n) // 후위++ 구현
//	{
//		Circle tmp = *this; // 바뀌기 전 a의 값 저장
//		this->radius++; // a 변경
//		return tmp; // 바뀌기 전의 값을 반환해 b에 복사생성
//	}
//};
//int main()
//{
//	Circle a(5), b(4); // 객체 a,b 생성
//	++a; // 전위 // a.operator++(); 
//	b = a++; // 후위 // b = a.operator++(0); 
//	a.show(); b.show();
//}

////8-2 // 프렌드 함수
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//	friend Circle operator++(Circle& op); // 전위 ++연산자 정의 // 일반함수 -> 프렌드함수
//	friend Circle operator++(Circle& op, int n); // 후위 ++연산자 정의 // 일반함수 -> 프렌드함수
//};
//Circle operator++(Circle &op) // 참조 // 참조안하면 복사생성으로 메인문의 객체값 바뀌지 않음
//{
//	// 전위++ 구현 // 객체 a 참조
//	op.radius++; // a 변경
//	return op; // a 참조 반환
//}
//Circle operator++(Circle &op, int n) // 참조 // 참조안하면 복사생성으로 메인문의 객체값 바뀌지 않음
//{
//	// 후위++ 구현 // 객체 a 참조
//	Circle tmp = op; // 바뀌기 전 a의 값 저장
//	op.radius++; // a 변경
//	return tmp; // 바뀌기 전의 값을 반환해 b에 복사생성
//}
//int main()
//{
//	Circle a(5), b(4); // 객체 a,b 생성
//	++a; // 전위 // operator++(a); 
//	b = a++; // 후위 // b = operator++(a,0); 
//	a.show(); b.show();
//}

////9 // 프렌드함수만 가능
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " 인 원" << endl; }
//	friend Circle operator+(int n, Circle op);
//};
//Circle operator+(int n, Circle op) // a의 값 바뀌면 안되므로 참조 X // 복사생성
//{
//	//op.radius = op.radius + n; // op의 반지름에 n을 더한 값을 op의 반지름에 저장
//	//return op; // 객체 op 반환
//	Circle tmp;
//	tmp.radius = n + op.radius;
//	return tmp;
//}
//int main()
//{
//	Circle a(5), b(4); // 객체 a,b 생성
//	b = 1 + a; // b = operator+(1,a) // b = 1.operator+(a) 는 1이 객체가 아니므로 불가능 - 멤버함수로 연산자 구현할 수 없다.
//	// b의 반지름을 a의 반지름에 1을 더한 것으로 변경 // 반환된 객체를 복사생성
//	a.show(); b.show();
//}

////10-1 // 멤버함수
//class Statistics // 통계를 내는 클래스
//{
//	int* p; // 배열을 동적할당할 때 주소를 받을 포인터 변수
//	int size; // 인덱스
//	int capacity; // 동적할당될 공간의 수
//public:
//	Statistics(int size = 0, int capacity = 10)
//	{
//		// 디폴트 매개변수를 이용한 생성자
//		this->size = size;
//		this->capacity = capacity;
//		p = new int[capacity];
//	}
//	Statistics(Statistics& s) // 복사생성자
//	{
//		this->size = s.size; // s의 정보 넘김
//		this->capacity = s.capacity;
//		this->p = new int[this->capacity]; // 전달받은 capacity만큼 새롭게 동적할당 후 p에 주소 저장 
//		for (int i = 0; i < this->size; i++) // 현재의 최종 인덱스 길이까지 반복문
//			p[i] = s.p[i]; // p의 배열공간에 객체 s의 배열공간에 저장된 수 저장
//	}
//	~Statistics() // 소멸자
//	{
//		if (p) // 동적할당 받은 p의 공간 삭제
//			delete[] p;
//	}
//	bool operator!() // ! 연산자 정의
//	{
//		if (!size)
//			return true; // 동적할당받은 공간에 입력받은 수가 하나도 없음을 의미
//		else
//			return false; // 동적할당받은 공간에 수가 입력되어있음을 의미
//	}
//	Statistics& operator<<(int op) // << 연산자 정의 // 입력받은 x배열의 수들을 
//	{
//		p[size++] = op; // 객체 stat의 size번째 인덱스에 하나씩 저장 // size가 증가하므로 인덱스를 늘려감
//		return *this; // 변한 객체를 참조 반환
//	}
//	void operator~() // ~ 연산자 정의 // 소멸자 X // p출력
//	{
//		for (int i = 0; i < size; i++)
//			cout << p[i] << " "; // p가 가리키는 공간에 저장된 수들을 출력
//		cout << endl;
//	}
//	void operator>>(int& avg) // >> 연산자 정의 // p가 가리키는 공간의 모든 수 더함
//	{
//		// avg 참조
//		int sum = 0;
//		for (int i = 0; i < size; i++)
//			sum += p[i]; // 모든 수의 합
//		avg = sum / size; // 합을 최종인덱스의 수로 나눠줘 평균을 구함
//	}
//};
//int main()
//{
//	Statistics stat; // size는 0이고, 배열공간을 10만큼 동적할당하고 그 주소를 p에 저장
//	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
//	// stat.operator!(); 
//	// stat의 size가 0이라면 => stat에 아직 들어간 수가 없다면 true 반환
//
//	int x[5];
//	cout << "5 개의 정수를 입력하라>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]에 정수 입력
//
//	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다. // stat.operator<<(x[i])
//	stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다.
//	//stat.operator<<(100).operator<<(200) // 참조를 꼭 해야 연산자를 연속으로 사용하는 기능을 사용할 수 있음
//	
//	~stat; // stat.operator~(); // 통계 데이터를 모두 출력
//
//	int avg;
//	stat >> avg; // stat.operator>(avg); // 통계 객체로부터 평균을 받는다.
//	cout << "avg = " << avg << endl; // 평균 출력
//}

////10-2 // 프렌드함수 이용
//class Statistics
//{
//	int* p; // 배열을 동적할당할 때 주소를 받을 포인터 변수
//	int size; // 인덱스
//	int capacity; // 동적할당될 공간의 수
//public:
//	Statistics(int size = 0, int capacity = 10)
//	{
//		// 디폴트 매개변수를 이용한 생성자
//		this->size = size;
//		this->capacity = capacity;
//		p = new int[capacity];
//	}
//	Statistics(Statistics& s) // 복사생성자
//	{
//		this->size = s.size; // s의 정보 넘김
//		this->capacity = s.capacity; // 현재의 최종 인덱스 길이까지 반복문 
//		this->p = new int[this->capacity]; // 전달받은 capacity만큼 새롭게 동적할당 후 p에 주소 저장 
//		for (int i = 0; i < this->size; i++) // 현재의 최종 인덱스 길이까지 반복문
//			p[i] = s.p[i]; // p의 배열공간에 객체 s의 배열공간에 저장된 수 저장
//	}
//	~Statistics() // 소멸자
//	{
//		if (p) // 동적할당 받은 p의 공간 삭제
//			delete[] p;
//	}
//	friend bool operator!(Statistics op); // ! 연산자 정의
//	friend Statistics& operator<<(Statistics& op1, int op2); // << 연산자 정의
//	friend void operator~(Statistics op); // ~ 연산자 정의
//	friend void operator>>(Statistics op, int& avg); // >> 연산자 정의
//};
//bool operator!(Statistics op) // ! 연산자 정의
//{
//	if (!op.size) // 아직 객체에 들어간 수가 없다면
//		return true; // true 반환
//	else // 들어간 수가 하나라고 있디면
//		return false; // false 반환
//}
//Statistics& operator<<(Statistics& op1, int op2) // 공간을 공유하려면 유지되는 공간을 공유해야한다
//{
//	op1.p[op1.size++] = op2; // 입력받은 op2를 op1의 p가 가리키는 힙 공간의 size 인덱스에 저장
//	return op1; // 참조 반환
//}
//void operator~(Statistics op) // ~ 연산자 정의
//{
//	for (int i = 0; i < op.size; i++)
//		cout << op.p[i] << " "; // 객체 op의 p가 가리키는 힙공간의 수 출력
//	cout << endl;
//}
//void operator>>(Statistics op, int& avg) // >> 연산자 정의
//{
//	int sum = 0;
//	for (int i = 0; i < op.size; i++)
//		sum += op.p[i]; // 객체 op의 수 모두 더함
//	avg = sum / op.size; // 모두 더한 수를 op의 size(현재 수가 저장되어있는 공간의 마지막 인덱스)로 나눠 평균값을 구함
//}
//int main()
//{
//	Statistics stat; // size는 0이고, 배열공간을 10만큼 동적할당하고 그 주소를 p에 저장
//	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
//	// stat.operator!(); // operator!(stat);
//	// stat의 size가 0이라면 => stat에 아직 들어간 수가 없다면 true 반환
//
//	int x[5];
//	cout << "5 개의 정수를 입력하라>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]에 정수 입력
//
//	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다.
//	// operator<<(stat, x[i]);
//
//	stat << 100 << 200; // 100, 200을 통계 객체에 삽입한다.
//	//stat.operator<<(100).operator<<(200) // 참조를 꼭 해야 연산자를 연속으로 사용하는 기능을 사용할 수 있음
//	
//	~stat; // stat.operator~(); //operator~(stat) // 통계 데이터를 모두 출력
//
//	int avg;
//	stat >> avg; // stat.operator>(avg); // operator(stat,avg); // 통계 객체로부터 평균을 받는다.
//	cout << "avg = " << avg << endl; // 평균 출력
//}

////11-1 // 멤버함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//class Stack // 클래스 Stack
//{
//	int p[10]; // 크기가 10인 배열 p
//	int tos; // 인덱스를 알려주는 멤버변수
//public: // 공개
//	Stack() // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // 배열의 모든 인덱스를 1로 초기화
//	}
//	Stack& operator<< (int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//	{
//		p[tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//		return *this; // 바뀐 객체 리턴
//	}
//	bool operator! () // !연산자 정의 // stack에 수가 없다면 true 반환
//	{
//		if (tos == 0) // 스텍 출력이 끝나면 
//			return true; // true 반환
//		else
//			return false; // stack에 수가 남아있다면 false 반환
//	}
//	void operator>> (int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//	{
//		n = p[--tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//	}
//};
//int main()
//{
//	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // 팝을 위한 반복문
//	{
//		if (!stack) break; // 스택 empty // stack.operator!()
//		int x = 0; // 팝된 정수를 저장할 변수
//		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//// 교수님 방식 11-1 // 멤버함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//class Stack // 클래스 Stack
//{
//	int size;
//	int* mem;
//	int tos;
//public: // 공개
//	Stack(int size = 10) // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		this->size = size;
//		mem = new int[size]();
//	}
//	~Stack()
//	{
//		if (mem)
//			delete[] mem;
//	}
//	Stack& operator<< (int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//	{
//		mem[tos++] = n;
//		return *this; // this => 객체 stack
//	}
//	bool operator! () // !연산자 정의 // stack에 수가 없다면 true 반환
//	{
//		if (tos <= 0) // 스텍 출력이 끝나면 
//			return true; // true 반환
//		else
//			return false; // stack에 수가 남아있다면 false 반환
//	}
//	Stack& operator>> (int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//	{
//		n = mem[--tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//		return *this;
//	}
//};
//int main()
//{
//	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // 팝을 위한 반복문
//	{
//		if (!stack) break; // 스택 empty // stack.operator!()
//		int x = 0; // 팝된 정수를 저장할 변수
//		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

////11-2 // 프렌드 함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//class Stack // 클래스 Stack
//{
//	int p[10]; // 크기가 10인 배열 p
//	int tos; // 인덱스를 알려주는 멤버변수
//public: // 공개
//	Stack() // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // 배열의 모든 인덱스를 1로 초기화
//	}
//	friend Stack& operator<< (Stack& op, int n); // <<연산자 프렌드화
//	friend bool operator! (Stack op); // !연산자 프렌드화
//	friend void operator>> (Stack& op, int& n); // >>연산자 프렌드화
//};
//Stack& operator<< (Stack& op, int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//{
//	// op의 멤버변수들이 변경되어야하므로 참조매개변수를 사용해야 됨
//	op.p[op.tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//	return op; // 바뀐 객체 리턴
//}
//bool operator! (Stack op) // !연산자 정의 // stack에 수가 없다면 true 반환
//{
//	// operator>>함수에서 변경된 tos를 이용해 판단해야 됨
//	if (op.tos == 0) // 스텍 출력이 끝나면 
//		return true; // true 반환
//	else
//		return false; // stack에 수가 남아있다면 false 반환
//}
//void operator>> (Stack& op, int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//{
//	n = op.p[--op.tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//}
//int main()
//{
//	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // 팝을 위한 반복문
//	{
//		if (!stack) break; // 스택 empty // stack.operator!() // operator!(stack);
//		int x = 0; // 팝된 정수를 저장할 변수
//		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x); // operator>>(stack,x);
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//// 교수님 방식 11-2 // friend함수 이용 // 10번과 유사 // 스택클래스 만든거 이용 // 동적할당 X
//class Stack // 클래스 Stack
//{
//	int size;
//	int* mem;
//	int tos;
//public: // 공개
//	Stack(int size = 10) // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		this->size = size;
//		mem = new int[size]();
//	}
//	~Stack()
//	{
//		if (mem)
//			delete[] mem;
//	}
//	friend Stack& operator<< (Stack& op1, int n);
//	friend bool operator! (Stack& op);
//	friend Stack& operator>> (Stack& op1, int& n);
//};
//Stack& operator<< (Stack &op1,int n) // <<연산자 정의 // 참조리턴해서 그 전 연산자 호출을 객체자체로 만들어줌
//{
//	op1.mem[op1.tos++] = n;
//	return op1; // 참조 - 객체 stack
//}
//bool operator! (Stack& op) // !연산자 정의 // stack에 수가 없다면 true 반환
//{
//	// 매개변수에 &를 붙여야하는 이유 
//	//- 복사생성자를 호출하지 않게 해줘야함 
//	//- 참조로 만들어주면 함수를 빠져나와도 소멸자가 호출되지 않아 데이터 유지됨 
//	//- 참조를 하지 않으면 복사생성자를 따로 만들지 않았기때문에 얕은 복사가 이뤄지고 소멸자가 호출되었을때 오류가 발생함
//	if (op.tos <= 0) // 스텍 출력이 끝나면 
//		return true; // true 반환
//	else
//		return false; // stack에 수가 남아있다면 false 반환
//}
//Stack& operator>> (Stack& op1,int& n) // >>연산자 정의 // 스택의 탑에 있는 정수 팝 
//{
//	n = op1.mem[--op1.tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//	return op1;
//}
//
//int main()
//{
//	Stack stack; // 10개의 배열공간을 가진 객체 stack 생성
//	stack << 3 << 5 << 10; // 3,5,10을 순서대로 푸시 // 연산자 연속 출력
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // 팝을 위한 반복문
//	{
//		if (!stack) break; // 스택 empty // stack.operator!()
//		int x = 0; // 팝된 정수를 저장할 변수
//		stack >> x; // 스택의 탑에 있는 정수 팝 // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

////12-1 // 멤버함수 이용 // 복사생성자 - 깊은 복사 // 연산자 정리 // 동적할당 // 총 정리문제
//class SortedArray
//{
//    int size; // 현재 배열의 크기
//    int* p; // 정수 배열에 대한 포인터
//    void sort() // 정수 배열을 오름차순으로 정렬 // private - 클래스 외부에서 접근 불가능
//    {
//        for (int i = 0; i < size; i++) // 버블정렬
//        {
//            for (int j = 0; j < size - 1; j++) 
//            {
//                if (p[j] > p[j + 1]) // p[j]가 p[j+1]보다 클 때 // 큰 수를 뒤로 보내기
//                {
//                    int n1 = p[j]; // 원래 p[j]를 n1에 저장
//                    p[j] = p[j + 1]; // p[j]에 p[j+1] 저장
//                    p[j + 1] = n1; // p[j+1]에 원래 p[j] 저장
//                }
//            }
//        }
//    }
//public:
//    SortedArray() // p는 NULL로 size는 0으로 초기화 // 기본생성자
//    {
//        p = nullptr; // p가 아무것도 가리키지 않음
//        size = 0;
//    }
//    SortedArray(SortedArray& src) // 복사 생성자 // 깊은복사
//    {
//        size = src.size; // 복사하고자 하는 객체의 size 복사
//        if (!src.size) // size가 0이라면
//            p = nullptr; // p가 아무것도 가리키지 않음
//        else
//            p = new int[size](); // size값을 복사받았다면 그만큼 새로운 공간 동적할당
//        for (int i = 0; i < size; i++)
//            p[i] = src.p[i]; // 복사하고자하는 객체의 힙 공간 수를 this의 동적할당 공간에 저장
//        sort(); // 정수 배열을 오름차순으로 정렬
//    }
//    SortedArray(int p[], int size) // 매개변수가 있는 생성자, 정수 배열과 크기를 전달받음
//    {
//        this->size = size;
//        /*this->p = new int[size]; */
//        if (!size) // size가 0이라면
//            this->p = nullptr; // p가 아무것도 가리키지 않음
//        else 
//        {
//            this->p = new int[size](); // size값을 복사받았다면 그만큼 새로운 공간 동적할당
//            if (p)
//            {
//                for (int i = 0; i < size; i++)
//                    this->p[i] = p[i];
//            }
//        }
//        sort(); // 정수 배열을 오름차순으로 정렬
//    }
//    ~SortedArray() // 소멸자
//    {
//        if (p)
//            delete[] p; // 동적할당된 공간을 삭제
//        p = nullptr; // p가 아무것도 가리키지않음을 뜻함
//    }
//    SortedArray operator+(SortedArray& op2) // 현재 배열에 op2 배열 추가 //+연산자 정의
//    {
//        SortedArray c; // 두 객체를 붙인 모든 값이 복사될 객체를 하나 더 생성
//        // c.p,7 이렇게 디버깅하면 힙공간의 내용확인 가능
//        c.size = this->size + op2.size; // 두 객체의 size를 더한 값을 c의 size에 저장
//        c.p = new int[c.size](); // 저장된 size만큼 새로운 공간을 동적할당함
//        for (int i = 0; i < this->size; i++) // c.size만큼 반복문을 돌리면 힙 영역 메모리 침범 발생
//            c.p[i] = this->p[i]; // 인덱스 0~2까지 객체 a의 배열 값 c의 배열에 저장
//        for (int i = 0; i < op2.size; i++)
//            c.p[i + this->size] = op2.p[i]; // 인덱스 3~6까지 객체 b의 배열 값 c의 배열에 저장
//        c.sort(); // 정수 배열을 오름차순으로 정렬
//        return c; // 객체 a와 b를 합한 값을 가진 객체 c를 반환 // 복사 생성
//    }
//    SortedArray& operator=(const SortedArray& op2) // 현재 배열에 op2 배열 복사 // = 연산자 정의
//    {
//        // 클래스의 멤버함수로만 만들 수 있다.
//        // op2의 값을 =연산자를 호출한 객체에 복사
//        if (p)
//            delete[] p;
//        this->size = op2.size;
//        if (!size)
//            this->p = nullptr;
//        else
//        {
//            this->p = new int[this->size]; // 주소만 복사 X , 소멸 시 얕은 복사처럼 작용 (두 객체가 하나의 힙공간을 가리켜서)
//            for (int i = 0; i < this->size; i++)
//                this->p[i] = op2.p[i];
//        }
//        sort(); // 정수 배열을 오름차순으로 정렬
//        return *this; // 참조반환
//    }
//    void show() // 배열의 원소 출력
//    {
//        cout << "배열 출력 :";
//        for (int i = 0; i < size; i++)
//            cout << p[i] << ' ';
//        cout << endl;
//    }
//};
//int main()
//{
//    int n[] = { 2,20,6 };
//    int m[] = { 10,7,8,30 };
//    SortedArray a(n, 3), b(m, 4), c; // 객체값 결정
//
//    c = a + b; // +,= 연산자 작성 필요 // a.operator+(b); // c.operator=(a+b);
//    // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
//    // = 연산자 재정의 이유 : 기본적으로 컴파일러가 생성하는 =연산자는 얕은 복사만 가능 -> 깊은 복사를 할 수 있게 재정의 해줘야함
//    // (디폴트 대입연산자가 클래스 내에 있기 때문에 복사생성자를 재정의해주는 것과 같이 대입연산자를 깊은 복사하기 위해 재정의하려면 클래스내에 꼭 멤버함수로만 재정의해줘야만 한다. - 일반함수의 프렌드함수화 불가능)
//    // 디폴트 대입연산자가 호출될 때는 복사생성자가 호출되지 않는다.
//    // point& operator=(point & p) // 디폴트 대입연산자 = 기본할당대입연산자
//    a.show(); b.show(); c.show();
//}

////12-2 // 프렌드함수 이용 // 복사생성자 - 깊은 복사 // 연산자 정리 // 동적할당 // 총 정리문제
//class SortedArray
//{
//    int size; // 현재 배열의 크기
//    int* p; // 정수 배열에 대한 포인터
//    void sort() // 정수 배열을 오름차순으로 정렬
//    {
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < size - 1; j++)
//            {
//                if (p[j] > p[j + 1]) // p[j]가 p[j+1]보다 클 때 // 큰 수를 뒤로 보내기
//                {
//                    int n1 = p[j]; // 원래 p[j]를 n1에 저장
//                    p[j] = p[j + 1]; // p[j]에 p[j+1] 저장
//                    p[j + 1] = n1; // p[j+1]에 원래 p[j] 저장
//                }
//            }
//        }
//    }
//public:
//    SortedArray() // p는 NULL로 size는 0으로 초기화 // 기본생성자
//    {
//        p = nullptr; // p가 아무것도 가리키지 않음
//        size = 0;
//    }
//    SortedArray(SortedArray& src) // 복사 생성자 // 깊은복사
//    {
//        size = src.size; // 복사하고자 하는 객체의 size 복사
//        if (!size) // size가 0이라면
//            p = nullptr; // p가 아무것도 가리키지 않음
//        else
//            p = new int[size]; // size값을 복사받았다면 그만큼 새로운 공간 동적할당
//        for (int i = 0; i < size; i++)
//            p[i] = src.p[i]; // 복사하고자하는 객체의 힙 공간 수를 this의 동적할당 공간에 저장
//        sort(); // 정수 배열을 오름차순으로 정렬
//    }
//    SortedArray(int p[], int size) // 매개변수가 있는 생성자, 정수 배열과 크기를 전달받음
//    {
//        this->size = size;
//        this->p = new int[size];
//        for (int i = 0; i < size; i++)
//            this->p[i] = p[i];
//        sort(); // 정수 배열을 오름차순으로 정렬
//    }
//    ~SortedArray() // 소멸자
//    {
//        if (p)
//            delete[] p; // 동적할당된 공간을 삭제
//        p = nullptr; // p가 아무것도 가리키지않음을 뜻함
//    }
//    void show() // 배열의 원소 출력
//    {
//        cout << "배열 출력 :";
//        for (int i = 0; i < size; i++)
//            cout << p[i] << ' ';
//        cout << endl;
//    }
//    SortedArray& operator=(const SortedArray& op2) // 현재 배열에 op2 배열 복사 // = 연산자 정의
//    {
//        // op2의 값을 =연산자를 호출한 객체에 복사
//        this->size = op2.size;
//        this->p = new int[this->size]; // 주소만 복사 X , 소멸 시 얕은 복사처럼 작용 (두 객체가 하나의 힙공간을 가리켜서)
//        for (int i = 0; i < this->size; i++)
//            this->p[i] = op2.p[i];
//        sort(); // 정수 배열을 오름차순으로 정렬
//        return *this; // 참조반환
//    }
//    friend SortedArray operator+(SortedArray& op1, SortedArray& op2);
//};
//SortedArray operator+(SortedArray& op1, SortedArray& op2) // 현재 배열에 op2 배열 추가 //+연산자 정의
//{
//    SortedArray c; // 두 객체를 붙인 모든 값이 복사될 객체를 하나 더 생성
//    c.size = op1.size + op2.size; // 두 객체의 size를 더한 값을 c의 size에 저장
//    c.p = new int[c.size](); // 저장된 size만큼 새로운 공간을 동적할당함
//    for (int i = 0; i < op1.size; i++) // c.size만큼 반복문을 돌리면 힙 영역 메모리 침범 발생
//        c.p[i] = op1.p[i]; // 인덱스 0~2까지 객체 a의 배열 값 c의 배열에 저장
//    for (int i = 0; i < op2.size; i++)
//        c.p[i + op1.size] = op2.p[i]; // 인덱스 3~6까지 객체 b의 배열 값 c의 배열에 저장
//    c.sort(); // 정수 배열을 오름차순으로 정렬
//    return c; // 객체 a와 b를 합한 값을 가진 객체 c를 반환 // 복사 생성
//}
//int main()
//{
//    int n[] = { 2,20,6 };
//    int m[] = { 10,7,8,30 };
//    SortedArray a(n, 3), b(m, 4), c; // 객체값 결정
//
//    c = a + b; // +,= 연산자 작성 필요 
//               // a.operator+(b); // c.operator=(a+b);
//               // operator+(a,b); // operator=(c,a+b); - 멤버함수 불가능 - 12-1 488,489에 설명됨
//    // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
//
//    a.show(); b.show(); c.show();
//}

////교수님이 작성하신 12번 - 프렌드함수 이용
//class SortedArray {
//	int size; // 현재 배열의 크기
//	int* p; // 정수 배열에 대한 포인터
//	void sort() // 정수 배열을 오름차순으로 정렬
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size - 1; j++)
//			{
//				if (p[j] > p[j + 1])
//				{
//					int tmp = p[j];
//					p[j] = p[j + 1];
//					p[j + 1] = tmp;
//				}
//			}
//		}
//	}
//public:
//	SortedArray() // p는 NULL로 size는 0으로 초기화
//	{
//		size = 0;
//		p = nullptr;
//	}
//	SortedArray(SortedArray& src) // 복사 생성자
//	{
//		this->size = src.size;
//		if (src.size == 0)
//		{
//			this->p = nullptr;
//		}
//		else
//		{
//			this->p = new int[size]();
//			for (int i = 0; i < size; i++)
//				p[i] = src.p[i];
//		}
//		sort();
//	}
//	SortedArray(int p[], int size) // 생성자. 정수 배열과 크기를 전달받음
//	{
//		this->size = size;
//		if (size == 0)
//		{
//			this->p = nullptr;
//		}
//		else
//		{
//			this->p = new int[size]();
//			if (p)
//			{
//				for (int i = 0; i < size; i++)
//					this->p[i] = p[i];
//			}
//		}
//		sort();
//	}
//	~SortedArray() // 소멸자
//	{
//		if (p)
//			delete[] p;
//	}
//	/*SortedArray operator + (SortedArray& op2)
//	{
//		SortedArray tmp(0, this->size + op2.size);
//		for (int i = 0; i < size; i++)
//			tmp.p[i] = p[i];
//		for (int i = 0; i < op2.size; i++)
//			tmp.p[i + size] = op2.p[i];
//
//		tmp.sort();
//		return tmp;
//	}*/
//	SortedArray& operator = (const SortedArray& op2) // 현재 배열에 op2 배열을 복사
//	{
//		if (p)
//			delete[] p;
//
//		this->size = op2.size;
//		if (size == 0)
//			this->p = nullptr;
//		else
//		{
//			this->p = new int[size]();
//			for (int i = 0; i < size; i++)
//				this->p[i] = op2.p[i];
//
//		}
//		return *this;
//	}
//	void show() // 배열의 원소 출력
//	{
//		cout << "배열 출력 : ";
//		for (int i = 0; i < size; i++)
//			cout << p[i] << " ";
//		cout << endl;
//	}
//	friend SortedArray operator + (SortedArray& op1, SortedArray& op2);
//};
//
//SortedArray operator + (SortedArray& op1,SortedArray& op2)
//{
//	SortedArray tmp(0, op1.size + op2.size);
//	for (int i = 0; i < op1.size; i++)
//		tmp.p[i] = op1.p[i];
//	for (int i = 0; i < op2.size; i++)
//		tmp.p[i + op1.size] = op2.p[i];
//
//	tmp.sort();
//	return tmp;
//}
//int main()
//{
//	int n[] = { 2, 20, 6 };
//	int m[] = { 10, 7, 8, 30 };
//	SortedArray a(n, 3), b(m, 4), c;
//
//	c = a + b; // +, = 연산자 작성 필요
//			   // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
//
//	//operator+(a,b)
//
//
//	a.show();
//	b.show();
//	c.show();
//}
