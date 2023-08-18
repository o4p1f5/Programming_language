#include <iostream>
using namespace std;
//4장 1,2,4,7,8

////1 // 생성자 // 값 바꿈 // 결과 보여줌
//// 주어진 조건에 맞게 메인문 작성
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
//};
//
//int main()
//{
//	Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
//	Color* p; // Color 타입의 포인터 변수 p 선언 // 생성자 호출 X
//	p = &screenColor; // p가 screenColor의 주소를 가지도록 코드 작성
//	(*p).show(); // p와 show()를 이용하여 screenColor 색 출력
//
//	Color colors[3]; // Color의 일차원 배열 colors 선언, 원소는 3개 // 객체배열 기본생성자 반드시 필요
//	p = colors; // p가 colors 배열을 가리키도록 코드 작성
//	// p와 setcolor()를 이용하여 colors[0], colors[1], colors[2]가
//	// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
//	p[0].setColor(255, 0, 0); // 배열 인덱스 0 = 빨강
//	p[1].setColor(0, 255, 0); // 배열 인덱스 1 = 초록
//	p[2].setColor(0, 0, 255); // 배열 인덱스 2 = 파랑
//
//	for (int i = 0; i < 3; i++)
//	{
//		(p + i)->show(); // p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력
//		// p[i].show(); // (*(p+i)).show();
//	}
//}

////2
//// 정수 5칸 배열 - 동적할당 // 입력받기
//// 평균만들기 예시 활용
//int main()
//{
//	int* p = new int[5](); // 정수 공간 5개를 배열로 동적할당
//	if (!p) // p가 제대로 공간을 할당받지 못했다면
//	{
//		cout << "메모리를 할당할 수 없습니다.";
//		return 0; // 프로그램 종료
//	}
//	int sum(0); // 평균을 구하기 위한 변수 sum 선언
//	cout << "정수 5개 입력>> "; // 징수 입력 문구
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> p[i]; // 입력받은 정수를 p의 i번째 인덱스에 저장
//		sum += p[i]; // 그 수를 sum 변수의 현재값에 더함
//	}
//	cout << "평균 " << (double)sum / 5.0; // 현재 sum의 값을 5로 나눔
//	delete[] p; // 동적할당된 배열 공간을 지움
//	p = NULL; // p가 가리키는 곳이 없음을 말함
//}

////4
//class Sample // 클래스 Sample 선언
//{
//	int* p; // 정수형 포인터 p 선언
//	int size; // 배열의 크기를 담을 변수 선언
//public: // 공개
//	Sample() // 기본 생성자 // 필수
//	{
//		size = 1;
//		p = new int[1]; // 공간이 1인 배열을 힙영역에 동적할당하고 그 시작주소를 포인터 p에 저장
//	}
//	Sample(int n) // 매개변수를 가진 생성자
//	{
//		size = n; // 배열의 크기를 n으로 정하고
//		p = new int[n]; // n만큼의 배열을 힙영역에 동적할당 한 후, 그 시작주소를 포인터 p에 저장
//	}
//	void read() // 동적할당받은 정수 배열 p의 i번 인덱스에 입력받은 수 저장
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cin >> p[i];
//		}
//	}
//	void write() // 배열 p를 출력
//	{
//		for (int i = 0; i < size; i++) // 배열의 크기는 size만큼
//		{
//			cout << p[i] << " ";
//		}
//		cout << endl;
//	}
//	int big() // 배열에서 가장 큰 수 출력
//	{
//		int mx = 0; // 가장 큰 수를 받을 변수 선언
//		for (int i = 0; i < size; i++)
//		{
//			if (mx < p[i]) // 현재 mx의 수보다 배열 p의 i번째 인덱스의 수가 더 크면
//			{
//				mx = p[i]; // i번째 인덱스의 수를 mx에 저장
//			}
//		}
//		return mx; // 최종 가장 큰 수 반환
//	}
//	~Sample() // 소멸자
//	{
//		if (p) // p가 가리키는 공간이 있다면 // p에 주소값이 들어있다면
//		{
//			delete[] p; // 그 p가 가리키는 동적할당 공간을 삭제
//		}
//		p = NULL; // p가 가리키는 공간이 없음을 말함
//	}
//};
//int main()
//{
//	Sample s(10); // Sample형 객체 s를 선언하고 s의 size값을 10으로 함
//	// 10개의 배열을 동적할당한 후 p에 그 시작주소를 저장
//	s.read(); // 객체 s의 p가 가리키는 배열공간에 수를 입력
//	s.write(); // 객체 s의 p가 가리키는 배열공간의 수를 출력
//	cout << "가장 큰 수는 " << s.big() << endl; // 배열 중 가장 큰 수 출력
//	// 소멸자를 호출시켜 포인터 p가 가리키는 배열공간 삭제, p의 값을 NULL로 지정
//}

////7
//// 반지름을 입력받아서 면적이 100보다 큰 원 찾기
//// this 포인터 // 생성자 // 객체배열 - 스택에
//// cnt - 100보다 큰 원 수 세기
//class Circle // 클래스 Circle 선언
//{
//	int radius; // 반지름
//public: // 공개
//	Circle() // 기본생성자
//	{
//		radius = 1; // 반지름 1
//	}
//	void setRadius(int radius) // 반지름의 값을 변환시키는 멤버함수
//	{
//		this->radius = radius; // 반지름을 매개변수값으로 초기화
//		// 멤버변수의 이름과 매개변수의 이름이 같을 경우, this포인터를 써서
//		// 무엇이 멤버함수를 호출한 객체의 멤버변수임을 알려줌
//	}
//	double getArea() // 원의 면적을 구하는 멤버함수
//	{
//		double Area = (double)radius * (double)radius * 3.14;
//		return Area; // 면적값을 반환
//	}
//};
//int main()
//{
//	Circle circle[3]; // Circle형 객체 배열 circle 선언 // 공간 3
//	int n(0);
//	int cnt(0);
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "원 " << i+1 << "의 반지름 >> "; 
//		cin >> n; // 입력받은 수를 n에 저장 // 입력된 수를 클래스의 멤버에 직접 입력못함
//		circle[i].setRadius(n); // 그 수로 circle 배열의 i번째 인덱스에 있는 radius의 값을 변환
//		if (circle[i].getArea() > 100) // radius의 값을 받은 인덱스의 면적이 100보다 크다면
//		{
//			cnt++; // 카운트 + 1 
//		}
//	}
//	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다."; 
//	// 최종적으로 나온 cnt의 값을 출력함으로써 면적이 100보다 큰 원의 개수를 알림
//}

//8
//7번 동적할당으로 풀기
class Circle // 클래스 Circle 선언
{
	int radius; // 반지름
public: // 공개
	Circle() // 기본생성자
	{
		radius = 1; // 반지름 1
	}
	void setRadius(int radius) // 반지름의 값을 변환시키는 멤버함수
	{
		this->radius = radius; // 반지름을 매개변수값으로 초기화
		// 멤버변수의 이름과 매개변수의 이름이 같을 경우, this포인터를 써서
		// 무엇이 멤버함수를 호출한 객체의 멤버변수임을 알려줌
	}
	double getArea() // 원의 면적을 구하는 멤버함수
	{
		double Area = (double)radius * (double)radius * 3.14;
		return Area; // 면적값을 반환
	}
};
int main()
{
	int n(0);
	int cnt(0);
	int num(0);
	cout << "원의 개수 >> "; 
	cin >> n; // 원하는 원의 개수를 입력해 n에 저장
	Circle* circle = new Circle[n]; // 그 n의 값만큼 Circle형 배열을 동적할당해서
	// Circle형 포인터 circle에 시작주소를 저장
	if (!circle) // circle의 동적할당이 제대로 되지 않았다면
	{
		cout << "메모리를 할당할 수 없습니다.";
		return 0; // 프로그램 종료
	}
	for (int i = 0; i < n; i++)
	{
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> num; // 원하는 원의 반지름값을 입력받아
		circle[i].setRadius(num); // circle 배열의 i번째 인덱스에 저장 // 멤버함수 이용
		if (circle[i].getArea() > 100) // circle 배열의 i번째 인덱스 반지름의 원이 100보다 큰 면적을 가진다면
		{
			cnt++; // 카운터 + 1
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";
	// 최종적으로 나온 cnt의 값을 출력함으로써 면적이 100보다 큰 원의 개수를 알림

	delete[] circle; // circle이 가리키는 힙 공간 삭제
	circle = NULL; // circle이 가리키는 공간은 없음을 말함
}