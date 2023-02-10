#include <iostream>
#include <string>
#include <memory>
#include <locale>
#include <ctime> // #include <time.h>
using namespace std;

////3-1 // []를 이용한 코드
// int main()
//{
//	string str; // string 문자열 선언
//	int cnt = 0; // 문자 a의 개수를 세는 변수 선언
//
//	cout << "문자열 입력>> ";
//	getline(cin, str, '\n'); // cin을 통해 입력받은 문자열을 str에 저장
//	// 구분자는 \n으로 한다
//
//	for (int i = 0; i < (int)str.length(); i++)
//	{
//		if (str[i] == 'a') // str의 i번째 인덱스에 있는 문자열이 문자 a와 같다면
//		{
//			cnt++; // cnt에 1을 더한다
//		}
//	}
//	cout << "문자 a는 " << cnt << "개 있습니다."; // 구한 a의 개수를 출력
//     return 0;
// }

////3-2 // find() 함수를 이용한 코드
// int main()
//{
//	string str; // string 문자열 선언
//	int index = 0; // find함수를 통해 얻은 a의 위치 인덱스값을 저장할 변수
//	int cnt = 0; // 문자 a의 개수를 세는 변수 선언
//
//	cout << "문자열 입력>> ";
//	getline(cin, str, '\n'); // cin을 통해 입력받은 문자열을 str에 저장
//	// 구분자는 \n으로 한다
//
//	for (int i = 0; i < (int)str.length(); i++)
//	{
//		index = str.find('a', index); // find() 함수를 이용해 str문자열에서 a의 인덱스값을 변수 index에 저장
//		// 찾는 위치의 시작은 현재 index의 인덱스부터 시작한다.
//		if (index == -1) // str에 a와 같은 문자가 없다면
//			break; // for문을 빠져나옴
//		else // str에 a와 같은 문자가 있다면
//			cnt++; // cnt값 1 증가
//
//		index++; // a의 인덱스 위치를 받은 index의 다음 인덱스부터 a를 찾기위해 index값 1 증가
//	}
//	cout << "문자 a는 " << cnt << "개 있습니다."; // 찾은 a의 개수를 출력
//     return 0;
// }

////5 // 난수 // rand() % size // 문자 char형 정수 연산 가능
// int main()
//{
//	string str; // string 문자열 선언
//	int index = 0;  // 랜덤으로 뽑힌 문자가 들어가기위한 인덱스값을 저장할 변수
//	char ch = 0; // 랜덤으로 뽑힌 문자를 저장할 수 있는 변수
//	srand((unsigned)time(0)); // 시작할 때마다, 다음 랜덤수를 발생시키기 위한 seed 설정
//	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
//	while (true)
//	{
//		cout << ">>";
//		getline(cin, str, '\n'); // cin을 통해 입력받은 문자열을 str에 저장
//		// 구분자는 \n으로 한다
//		if (str == "exit") // 만약 str에 문자열 exit이 입력됐다면
//		{
//			break; // while문을 빠져나옴
//		}
//		index = rand() % (int)str.length(); // 0에서 입력받은 문자열의 길이 사이의 수 중 랜덤으로 수를 뽑음
//		ch = 'a' + rand() % 26; // 알파벳 26글자 중 하나의 문자를 랜덤으로 뽑아 ch에 저장
//		str[index] = ch; // str의 index번째 인덱스에 랜덤으로 뽑힌 ch 문자를 저장
//		cout << str << endl; // 바뀐 문자열을 출력
//	}
//	return 0;
// }

////6 // 입력한 문자열 거꾸로 출력
//// 인덱스 반대로 출력 // for문 사용
// int main()
//{
//	string str; // string 문자열 선언
//	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
//	while (true)
//	{
//		cout << ">>";
//		getline(cin, str, '\n'); // cin을 통해 입력받은 문자열을 str에 저장
//		// 구분자는 \n으로 한다
//		if (str == "exit") // 만약 str에 문자열 exit이 입력됐다면
//		{
//			break; // while문을 빠져나옴
//		}
//		for (int i = str.length(); i >= 0; i--) // str에 입력된 문자열의 길이 값인 인덱스부터 인덱스 0까지 출력
//		{
//			cout << str[i];
//		}
//		cout << endl;
//	}
// }

////9 // 관계연산자 = 이용해서 같은 문자열 찾기
// class Person // 클래스 Person
//{
//	string name; // 이름을 받는 멤버변수
//	string tel; // 전화번호를 받는 멤버변수
// public:
//	Person()
//	{
//		name = " ";
//		tel = " ";
//	} // 기본생성자
//	string getName() { return name; } // 멤버변수 name을 반환하는 멤버함수
//	string getTel() { return tel; } // 멤버변수 tel을 반환하는 멤버함수
//	void set(string name, string tel) // 매개변수로 멤버변수의 값을 변환하는 멤버함수
//	{
//		this->name = name; // 입력받은 매개변수 name의 값을 this포인터가 알려주는
//		// 멤버변수 name에 저장
//		this->tel = tel; // 입력받은 매개변수 tel의 값을 this포인터가 알려주는
//		// 멤버변수 tel에 저장
//	}
// };
// int main()
//{
//	Person person[3]; // 클래스 Person 객체 배열 person 선언
//	string name; // 이름을 담는 string 변수 선언
//	string tel; // 전화번호를 담는 string 변수 선언
//
//	cout << "이름과 전화번호를 입력해 주세요" << endl;
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		cout << "사람 " << i + 1 << ">> ";
//		cin >> name >> tel; // 입력받은 이름을 name에 저장 // 입력받은 전화번호를 tel에 저장
//		person[i].set(name, tel); // 입력받은 문자열들을 매개변수로 넘겨
//		// i번째 객체의 name과 tel에 저장
//	}
//	cout << "모든 사람의 이름은 ";
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		cout << person[i].getName() << ' '; // i번째 객체의 name을 출력
//	}
//	cout << endl << "전화번호를 검색합니다. 이름을 입력하세요>>";
//	cin >> name; // 찾고자하는 사람의 이름을 입력받아 name에 저장
//
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		if (name == person[i].getName()) // 입력받은 name의 문자열과 i번째 객체의 name이 동일하다면
//		{
//			cout << "전화 번호는 " << person[i].getTel(); // i번째 객체의 tel을 출력
//			break;
//		}
//	}
//	return 0;
// }

////10 // 생성자에서 동적할당
// // 다른 클래스의 클래스의 객체나 포인터변수가 올수있음을 유념
// class Person // 클래스 person 선언
//{
//	string name; // 가족 구성원의 이름을 담을 멤버변수 선언
// public:
//	Person() {}; // 기본 생성자
//	Person(string name) { this->name = name; } // 매개변수가 있는 생성자
//	string getName() { return name;} // 가족 구성원 이름을 반환하는 함수
//	void setname(string name) { this->name = name; } // 입력받은 문자열로 멤버변수 name을 변환
//};
//
// class Family // 클래스 Family 선언
//{
//	Person* p; // Person 배열 포인터
//	int size; // Person 배열의 크기, 가족 구성원의 수
//	string name; // 가족의 대표 이름
// public:
//	Family() // 기본 생성자
//	{
//		p = NULL; // 배열 포인터가 가리키는 곳은 없다
//		size = 0; // 0으로 초기화
//		name = " ";
//	}
//	Family(string name, int size) // 매개변수가 있는 생성자
//	{
//		this->size = size; // 입력받은 size를 객체의 size 멤버변수에 저장
//		while (true)
//		{
//			p = new Person[this->size]; // 입력받은 size만큼 Person 배열을 동적할당해 그 주소를 p에 저장
//			if (!p) // p가 0이라면 // 동적할당이 정상적으로 진행되지않았다면
//			{
//				continue; // while문 처음으로 돌아가서 다시 동적할당을 받음
//			}
//			else // 제대로 동적할당이 됐다면
//			{
//				break; // while문 빠져나옴
//			}
//		}
//		this->name = name; // 입력받은 문자열을 객체의 name 멤버변수에 저장
//	}
//	void show() // 가족이 몇명이며 가족 구성원이 누구누구인지 출력하는 멤버함수
//	{
//		cout << name << "가족은 다음과 같이 " << size << "명 입니다." << endl;
//		for (int i = 0; i < size; i++)
//		{
//			cout << p[i].getName() << "    "; // p가 가리키는 Person 배열의 i번째 객체의
//			// 이름을 호출
//		}
//	}
//	void setName(int i, string name) // Person 배열에 가족 구성원 이름을 채우는 멤버함수
//	{
//		p[i].setname(name); // p가 가리키는 Person배열의 i번째 객체의 멤버변수 name을
//		// 매개변수 name의 문자열로 변경
//	}
//	~Family() // 소멸자 // p가 사라질 때 호출
//	{
//		if (p)
//		{
//			delete[]p; // p가 가리키는 동적할당 공간을 삭제
//		}
//		p = NULL; // p가 아무곳도 가리키지 않음을 말함
//	}
//};
// int main()
//{
//	Family* simpson = new Family("Simpson", 3); // 클래스 Family의 객체공간을 동적할당하고
//	// 그 주소를 객체포인터 simson에 저장 // 매개변수가 있는 생성자 호출
//	if (!simpson) // simpson이 0이라면 // 동적할당이 정상적으로 진행되지않았다면
//	{
//		return 0; // 메인함수를 끝냄
//	}
//	simpson->setName(0, "Mr. Simpson"); // p가 가리키는 Person 배열의 0번째 객체의 멤버변수 name에
//	// 문자열 "Mr. Simpson" 저장
//	simpson->setName(1, "Mrs. Simpson"); // p가 가리키는 Person 배열의 1번째 객체의 멤버변수 name에
//	// 문자열 "Mrs. Simpson" 저장
//	simpson->setName(2, "Bart Simpson"); // p가 가리키는 Person 배열의 2번째 객체의 멤버변수 name에
//	// 문자열 "Bart Simpson" 저장
//	simpson->show(); // p가 가리키는 Person배열을 출력해서 가족구성원을 보여줌
//	delete simpson; // simpson이 가리키는 동적할당 공간을 삭제
//	simpson = NULL; // simpson이 아무곳도 가리키지 않음을 알림
//}

////13
// class Histogram // 클래스 Histogram 선언
//{
//	string text; // 문자열을 받을 멤버변수
//	int alpha[26]; // a부터 z까지를 나타내는 int형 배열 // 각 알파벳의 갯수를 저장
// public:
//	Histogram(string text) // 매개변수가 있는 생성자
//	{
//		this->text = text; // 문자열 복사 가능 // 입력받은 문자열로 객체의 text멤버변수를 초기화
//		memset(alpha, 0, sizeof(int) * 26); // 배열 alpha의 크기만큼을 0으로 초기화
//	}
//	void put(string text) // 문자열을 합치는 멤버함수
//	{
//		this->text += text; // 복합대입연산자로 문자열 합치기 가능
//		// 입력받은 문자열을 기존에 있던 객체의 멤버함수 text의 문자열에 추가
//	}
//	void putc(char ch) // 문자와 문자열이 합쳐짐을 보여주는 멤버함수
//	{
//		text += ch; // 문자도 합쳐짐
//		// 입력받은 문자를 기존의 객체 멤버함수 text 문자열에 추가
//	}
//	void print() // 문자열에 각 알파벳이 얼마씩 있는 출력하는 멤버함수
//	{
//		cout << text << endl << endl; // 현재 객체의 text에 있는 문자열 출력
//		int cnt(0); // 문자열 중 알파벳이 몇 개 인지 세어주는 변수 선언
//		for (int i = 0; i < (int)text.length(); i++) // text문자열의 길이만큼 반복문
//		{
//			if (isalpha(text[i])) // text 문자열의 i번째 인덱스에 있는게 알바벳인가?
//			{
//				cnt++; // 맞다면 cnt 1 증가
//				char ch = tolower(text[i]); // text 문자열의 i번째 알파벳이 대문자라면
//				// 소문자로 바꿔서 ch에 저장
//				alpha[(int)(ch - 'a')]++; // ch의 알파벳에서 'a'만큼을 빼면 0 ~ 25 사이의 수가 나온다
//				// 0 ~ 25 를 a 부터 z라 생각하고 그 자리에 1을 증가시킴으로 text[i]의 알파벳이 무엇인지 알림
//			}
//		}
//		cout << "총 알파벳 " << cnt << endl << endl; // 문자열 중 총 알파벳의 개수를 출력
//		for (int i = 0; i < 26; i++)
//		{
//			cout << (char)(i + 'a') << "(" << alpha[i] << ") : ";
//			// 알파벳 무엇이고 몇개 있는지 출력하고
//			for (int j = 0; j < alpha[i]; j++) // 그 개수만큼 *을 출력
//			{
//				cout << '*';
//			}
//			cout << endl;
//		}
//	}
// };
// int main()
//{
//	Histogram elvisHisto("Wise men say, only fools rush in But I cna't help, ");
//	// 클래스 Histogram 객체 elvisHisto 선언 // 매개변수가 있는 생성자 호출
//	elvisHisto.put("falling in love with you"); // 문자열을 객체의 text에 추가
//	elvisHisto.putc('-'); // 문자를 객체의 text에 추가
//	elvisHisto.put("Elvis Presley"); // 문자열을 객체의 text에 추가
//	elvisHisto.print(); // 알파벳을 찾은 결과 출력
// }