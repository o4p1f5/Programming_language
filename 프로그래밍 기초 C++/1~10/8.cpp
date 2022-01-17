#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
// 참조전달 참조반환 복사생성자
// 참조리턴 - 반환되는 공간의 공유를 의미함
// 복사생성자 - 얕은 복사
//            - 깊은 복사 : 동적할당 시 사용 // string 으로 하면 얕은복사여도 상관 X
//           : 객체를 매개변수에 넘겨줄때, 객체를 반환할때, 동일한 클래스 자료형의 객체를 대입하는 경우 등 호출
// 상수공간 변경 금지 - const
// 복사생성자 - 깊은 복사로 만들기

////6
//char& find(char a[], char c, bool& success) // 참조를 이용해서 찾은 문자의 인덱스공간을 참조로 반환
//{
//	int i = 0;
//	while (1)
//	{
//		if (a[i] == '\0') // 문자열 a가 끝나면 while 끝냄
//		{
//			break;
//		}
//		if (a[i] == c) // 문자열 a에 'M'이 있다면
//		{
//			success = true; // 참조변수 success를 true로 바꾸고
//			return a[i]; // 문자공간을 참조반환
//		}
//		i++;
//	}
//	return a[0]; // 의미없는 반환 // b가 flase이기 때문에 코드에 문제가 되지않음
//}
//int main()
//{
//	char s[] = "Mike"; // char 문자열 선언
//	bool b = false; // 문자열에서 M을 발견할 수 있을지 아는 bool형 변수 선언
//	char& loc = find(s, 'M', b); // 반환된 공간을 참조
//	if (b == false) // b가 false라면
//	{
//		cout << "M을 발견할 수 없다." << endl; // M을 찾을 수 없다고 출력
//		return 0;
//	}
//	loc = 'm'; // 참조된 공간을 M -> m 으로 변경
//	cout << s << endl; // 완성된 문자열 출력
//}

////7 // push 넣은 값 // pop 나오는 값
//class MyIntStack // 클래스 MyIntStack
//{
//	int p[10]; // 크기가 10인 배열 p
//	int tos; // 인덱스를 알려주는 멤버변수
//public: // 공개
//	MyIntStack() // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // 배열의 모든 인덱스를 1로 초기화
//	}
//	bool push(int n) // stack에 수를 집어넣는 멤버함수
//	{
//		if (tos >= 10) // 인덱스값이 10보다 크거나 같으면
//		{
//			return false; // false 반환
//		}
//		else // 아니라면
//		{
//			p[tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//			return true;
//		}
//	}
//	bool pop(int& n) // stack에 쌓인 수를 거꾸로 꺼내는 멤버함수
//	{
//		if (tos == 0) // 스텍 출력이 끝나면 
//		{
//			return false; // false 반환
//		}
//		else // 아니라면
//		{
//			n = p[--tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//			return true;
//		}
//	}
//};
//int main()
//{
//	MyIntStack a; // 클래스 MyIntStack 의 객체 a 선언
//	for (int i = 0; i < 11; i++) // 11개를 푸시하면, 마지막에는 stack full이 된다.
//	{
//		if (a.push(i))
//			cout << i << ' '; // 푸시된 값 에코
//		else cout << endl << i + 1 << " 번째 stack full" << endl;
//		// stack이 다 차면 다 찼다고 출력
//	}
//	int n;
//	for (int i = 0; i < 11; i++) // 11개를 팝하면, 마지막에는 stack empty가 된다.
//	{
//		if (a.pop(n)) // n을 참조한다
//			cout << n << ' '; // 공유된 공간에 저장된 수들을 출력 // 팝 한 값 출력
//		else cout << endl << i + 1 << " 번째 stack empty";
//		// stack에서 다 빠지면 다 빠졌다고 출력
//	}
//	cout << endl;
//}

////8 // 7번 응용 // 동적할당 // 생성자 - 동적할당 // 소멸자 // 복사생성자 - 깊은복사
//class MyIntStack // 클래스 MyIntStack
//{
//	int* p; // 스택 메모리로 사용할 포인터
//	int size; // 스택의 최대 크기
//	int tos; // 스택의 탑을 가리키는 인덱스
//public: // 공개
//	MyIntStack() // 기본생성자
//	{
//		tos = 0; // 0으로 초기화
//		size = 0; // 0으로 초기화
//		p = NULL; // p가 가리키는 공간이 없음을 의미 // p = nullptr;
//	}
//	MyIntStack(int size) // 매개변수가 있는 생성자
//	{
//		this->size = size; // 함수를 호출한 객체의 size를 매개변수 size로 초기화
//		tos = 0; // tos를 0으로 초기화
//		p = new int[this->size](); // p에 크기가 객체의 size만큼인 동적할당 배열공간의 주소 저장
//	}
//	MyIntStack(const MyIntStack& s) // 복사생성자
//	{
//		this->size = s.size; // 함수를 호출한 객체의 size를 참조매개변수 객체의 size로 초기화
//		this->tos = s.tos; // 함수를 호출한 객체의 tos를 참조매개변수 객체의 tos로 초기화
//		p = new int[this->size](); // // p에 크기가 객체의 size만큼인 동적할당 배열공간의 주소 저장
//		for (int i = 0; i < size; i++)
//		{
//			p[i] = s.p[i]; // 동적할당 배열공간에 참조객체의 동적할당 배열공간의 수를 저장
//		}
//	}
//	~MyIntStack() // 소멸자
//	{
//		if (p) // p가 할당된 공간을 가리키고 있다면
//			delete[] p; // 그 공간을 삭제
//		p = nullptr;
//	}
//	bool push(int n) // stack에 수를 집어넣는 멤버함수
//	{
//		if (tos > size) // 인덱스값이 10보다 크거나 같으면 // 스택이 꽉 차 있으면
//		{
//			return false; // false 반환
//		}
//		else // 아니라면
//		{
//			p[tos++] = n; // tos 후위연산 // 배열 p의 tos번 공간에 n의 값 저장
//			return true; // 스택이 꽉 차 있지 않으면 true 리턴
//		}
//	}
//	bool pop(int& n) // stack에 쌓인 수를 거꾸로 꺼내는 멤버함수
//	{
//		if (tos < 0) // 스텍 출력이 끝나면 // 스택이 비어있다면
//		{
//			return false; // false 반환
//		}
//		else // 아니라면
//		{
//			n = p[--tos]; // tos 전위연산 // 배열 p의 tos - 1 번 공간에 있는 값을 n에 저장
//			return true; // 스택이 비어 있지 않다면 true 리턴
//		}
//	}
//};
//int main()
//{
//	MyIntStack a(10); // 클래스 MyIntStack의 객체 a 생성
//	a.push(10); // a.p[0]에 10 저장
//	a.push(20); // a.p[1]에 20 저장
//	MyIntStack b = a; // 복사 생성 // a의 정보를 b에 그대로 저장해서 b 객체 만듬
//	b.push(30); // b.p[2]에 30 저장 // b.p[0]에는 복사생성자로 인해 10이 있음
//				                    // b.p[1]에는 복사생성자로 인해 20이 있음
//	int n;
//	a.pop(n); // 스택 a 팝
//	cout << "스택 a에서 팝한 값 " << n << endl; // a.p[1] 출력
// 	b.pop(n); // 스택 b 팝
//	cout << "스택 b에서 팝한 값 " << n << endl; // b.p[2] 출력
//}

////9
//class Acuumulator // 클래스 Acuumulator
//{
//	int value; // 멤버함수 value 선언
//public: // 공개
//	Acuumulator() // 기본생성자
//	{
//		value = 0;
//	}
//	Acuumulator(int value) // 매개 변수 value로 멤버 value를 초기화한다
//	{
//		this->value = value; // 매개변수로 받은 value로 함수를 호출한 객체의 value를 초기화
//	}
//	Acuumulator& add(int n) // 함수를 호출하는 객체를 계속 참조할 수 있음
//		// value에 n을 더해 값을 누적한다
//	{
//		this->value += n; // 매개변수 n의 값을 value의 현재값에 더함
//		return *this; // 호출한 객체 자체를 참조반환
//	}
//	int get() // value를 리턴
//	{
//		return value; // 누적된 값 value를 리턴한다
//	}
//};
//int main()
//{
//	Acuumulator acc(10); // 객체 acc의 value를 10으로 초기화
//	acc.add(5).add(6).add(7); // 호출할 때마다 객체자체를 참조해서 연속으로 참조할 수 있음
//	// acc의 value 멤버가 28이 된다
//	cout << acc.get(); // 객체 acc의 value를 출력 // 28 출력
//}

////10 // append 함수 전역함수 - 참조리턴
//class Buffer // 클래스 Buffer
//{
//	string text; // string형 문자열 text
//public: // 공개
//	Buffer() // 기본생성자
//	{
//		text = '0';
//	}
//	Buffer(string text) // 매개변수가 있는 생성자
//	{
//		this->text = text; // 입력받은 문자열로 객체의 text 초기화
//	}
//	void add(string next) // 입력받은 문자열을 객체의 text에 추가
//	{
//		text += next;
//	}
//	void print()
//	{
//		cout << text << endl; // text를 출력하는 멤버함수
//	}
//};
//Buffer& append(Buffer& b, string a) // buf와 공간공유하는 b의 멤버함수 호출
//{
//	b.add(a); // 문자열 a를 add 멤버함수를 이용해 추가
//	return b; // buf와 공간공유하는 b를 참조리턴
//}
//
//int main()
//{
//	Buffer buf("Hello"); // Hello로 buf의 멤버변수 초기화
//	Buffer& temp = append(buf, "Guys"); // buf , b와 같은 공간에 temp라는 이름을 붙임
//	temp.print(); // temp의 문자열 출력
//	buf.print(); // buf의 문자열 출력
//}

////11 // (1)번만 하기 // 복사생성자 만들기 - 깊은 복사
// string 사용 시 얕은 복사 가능, 소멸자 필요 X,  복사생성자 따로 만들 필요 X
//class Book // 클래스 Book
//{
//	char* title; // 제목 문자열
//	int price; // 가격
//public:
//	Book() // 기본생성자
//	{
//		title = NULL;
//		price = 0;
//	}
//	Book(const char* title, int price) // 매개변수가 있는 생성자
//	{ 
//		int len = strlen(title); // 입력받은 문자열의 크기
//		this->title = new char[len + 1](); // 그 크기보다 하나 큰 공간을 힙할당
//		strcpy(this->title, title); // 함수를 호출한 객체의 title에 입력받은 문자열 저장
//		this->price = price; // 함수를 호출한 객체의 price에 입력받은 수 대입
//	}
//	Book(Book& b) // 복사생성자 - 깊은 복사
//	{
//		this->price = b.price;  // 함수를 호출한 객체의 price에 참조된 cpp의 price 저장
//		int len = strlen(b.title); // 참조된 cpp의 title의 길이
//		this->title = new char[len + 1](); // 그 길이보다 하나 큰 만큼 힙공간 할당
//		strcpy(this->title, b.title); // 새로 할당된 공간에 cpp의 title 복사
//	}
//	~Book() // 소멸자
//	{
//		if (title) // title이 할당된 공간을 가리킨다면
//			delete[] title; // title이 가리키는 공간을 삭제
//		title = nullptr;
//	}
//	void set(const char* title, int price) // 입력된 문자열로 title 재설정
//	{
//		this->price = price; // 함수를 호출한 객체의 price를 입력받은 수로 변경
//		if (this->title) // 멤버변수 title에 할당된 메모리가 있으면
//		{
//			delete[] this->title; // 그 공간 삭제
//			this->title = NULL;
//		}
//		this->title = new char[strlen(title) + 1](); // 매개변수의 크기보다 하나 큰 만큼의 배열공간을 할당함
//		strcpy(this->title, title); // 입력받은 책이름을 저장
//	}
//	void show() // 객체의 멤버변수 출력
//	{
//		cout << title << ' ' << price << "원" << endl;
//	}
//};
//int main()
//{
//	Book cpp("명품C++", 10000); // 클래스 Book 객체 cpp선언
//	Book java = cpp; // cpp와 같은 객체 java 선언 // 복사생성자 호출
//	java.set("명품자바", 12000); // java의 문자열을 명품자바로 바꾸고 가격을 변경하기
//	cpp.show(); // cpp의 멤버변수 출력
//	java.show(); // jave의 변경된 멤버변수 출력
//}

////12 // 11번과 동일 // 복사생성자 - 깊은 복사 // (1)만 하기
//class Dept // 클래스 Dept
//{
//	int size; // scores 배열의 크기
//	int* scores; // 동적할당받을 정수 배열의 주소
//public: // 공개
//	Dept() // 기본생성자
//	{
//		size = 0;
//		scores = NULL;
//	}
//	Dept(int size) // 매개변수가 있는 생성자
//	{
//		this->size = size; // 함수를 호출한 객체의 size를 입력받은 수로 초기화
//		scores = new int[size](); // size 만큼 배열 공간을 할당받음
//	}
//	Dept(const Dept& dept) // 복사 생성자
//	{
//		size = dept.size; // size 복사
//		scores = new int[size + 1](); // size보다 하나 크게 공간을 할당
//		for (int i = 0; i < this->size; i++) // size 만큼
//		{
//			scores[i] = dept.scores[i]; // 새로 할당받은 공간에 객체 dept의 배열공간 내용 복사
//		}
//	}
//	~Dept() // 소멸자
//	{
//		if (scores) // scores가 가리키는 공간이 있다면
//			delete[] scores; // 그 공간 삭제
//		scores = nullptr;
//	}
//	int getSize() // 멤버변수 출력하는 멤버함수
//	{
//		return size;
//	}
//	void read() // 입력받은 수들을 멤버변수의 scores가 가리키는 힙 배열공간에 저장
//	{
//		cout << "10개 점수 입력>> "; // 입력받기 위한 문구
//		for (int i = 0; i < size; i++) // size 만큼
//		{
//			cin >> scores[i]; // 수를 입력받아 배열의 i번째 공간에 저장
//		}
//	}
//	bool isOver60(int index) // 배열의 index번째 공간의 수가 60을 넘는다면
//	{
//		if (scores[index] > 60)
//		{
//			return true; // true 반환
//		} 
//		else // 넘지 않으면
//		{
//			return false; // false 반환
//		}
//	}
//};
//int countPass(Dept dept) // 일반함수 // 복사생성자 호출 // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
//{
//	int count = 0; // 60점 이상의 학생 수를 세는 변수
//	int n = dept.getSize(); // 객체 dept의 size를 n에 저장
//	for (int i = 0; i < n; i++) // n 만큼
//	{
//		if (dept.isOver60(i)) // isOver60함수를 호출해서 60점 이상의 학생의 수가 있다면
//			count++; // 카운트를 세고
//	} // 없다면 다시 반복문을 돈다
//	return count; // 반복문이 끝나면 최종 count값을 반환
//}
//// //복사 생성자 없이 진행되게 만들기
////int countPass(Dept & dept) // 일반함수 // 복사생성자 호출 // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
////{
////	int count = 0; // 60점 이상의 학생 수를 세는 변수
////	int n = dept.getSize(); // 객체 dept의 size를 n에 저장
////	for (int i = 0; i < n; i++) // n 만큼
////	{
////		if (dept.isOver60(i)) // isOver60함수를 호출해서 60점 이상의 학생의 수가 있다면
////			count++; // 카운트를 세고
////	} // 없다면 다시 반복문을 돈다
////	return count; // 반복문이 끝나면 최종 count값을 반환
////}
//int main()
//{
//	Dept com(10); // 클래스 Dept 객체 com 생성 // size값 10
//	com.read(); // com의 scores가 가리키는 배열 공간에  입력받은 수 저장
//	int n = countPass(com); // 복사생성자 호출 // 60점 이상의 점수를 가진 학생 수를 n에 저장
//	cout << "60점 이상은 " << n << "명";
//}