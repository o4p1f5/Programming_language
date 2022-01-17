#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 1-1 // 함수 중복
int add(int* arr, int n)  // 배열 a의 정수를 모두 더한 값 리턴
{
	int sum = 0; // 더한 값을 저장할 변수
	for (int i = 0; i < n; i ++)
	{
		sum += arr[i]; // arr의 i번째 수를 sum의 현재값에 더함
	}
	return sum; // 계산이 끝난 sum의 값 반환
}
int add(int* arr1, int n, int* arr2) // 배열 a와 b의 정수를 모두 더한 값 리턴
{
	int sum = 0; // 더한 값을 저장할 변수
	for (int i = 0; i < n; i++)
	{
		sum += arr1[i]; // arr1의 i번째 수를 sum의 현재값에 더함 
		sum += arr2[i]; // arr2의 i번째 수를 sum의 현재값에 더함
	}
	return sum; // 계산이 끝난 sum의 값 반환
}
int main()
{
	int a[] = { 1,2,3,4,5 }; // 배열 a의 값 초기화
	int b[] = { 6,7,8,9,10 }; // 배열 b의 값 초기화
	int c = add(a, 5); // 배열 a의 값을 모두 더한 값을 c에 저장
	int d = add(a, 5, b); // 배열 a와 b의 값을 모두 더한 값을 d에 저장
	cout << c << endl; // c의 값 출력
	cout << d << endl; // d의 값 출력
}

//// 1-2 // 디폴트매개변수
//int add(int* arr1, int n, int* arr2 = 0) // arr2를 디폴트매개변수로 설정해서 따로 값이 입력되지 않으면 아무것도 가리키지 않는 상태로 설정함
//{
//	int sum = 0; // 더한 값을 저장할 변수
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr1[i]; // arr1의 i번째 수를 현재 sum의 값에 더해서 다시 sum에 저장
//		if (arr2) // arr2에 주소값이 입력됐다면
//			sum += arr2[i]; // arr2의 i번째 수를 현재 sum의 값에 더해서 다시 sum에 저장 
//	}
//	return sum; // 더한 최종값을 리턴
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5 }; // 배열 a의 값 초기화
//	int b[] = { 6,7,8,9,10 }; // 배열 b의 값 초기화
//	int c = add(a, 5); // 배열 a의 값을 모두 더한 값을 c에 저장
//	int d = add(a, 5, b); // 배열 a와 b의 값을 모두 더한 값을 d에 저장
//	// b의 주소를 넘겨줌으로써 디폴트매개변수의 값을 0 -> b의 주소로 바꿔줌
//	cout << c << endl; // c의 값 출력
//	cout << d << endl; // d의 값 출력
//}

//// 2-1 // 생성자 중복
//class Person // 클래스 Person
//{
//	int id;
//	double weight;
//	string name;
//public:
//	Person() // 기본생성자 // 아무것도 입력받지 않았을때 호출되는 생성자
//	{
//		id = 1; weight = 20.5; name = "Grace";
//		// id를 1로, weight를 20.5로, name을 Grace로 기본설정함
//	}
//	Person(int id, string name) // 매개변수가 있는 생성자 1
//	{
//		this->id = id; // 입력받은 정수로 id를 초기화
//		this->name = name; // 입력받은 문자열로 name을 초기화
//		weight = 20.5; // weight를 20.5로 기본 설정
//	}
//	Person(int id, string name, double weight) // 매개변수가 있는 생성자 2
//	{
//		this->id = id; // 입력받은 정수로 id를 초기화
//		this->name = name; // 입력받은 문자열로 name을 초기화
//		this->weight = weight; // 입력받은 실수로 weight를 초기화
//	}
//	void show() // 객체의 정보 출력
//	{
//		cout << id << ' ' << weight << ' ' << name << endl;
//	}
//};
//int main()
//{
//	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
//	// grace 객체 - 기본생성자 호출 // ashley 객체 - id와 name을 2, Ashley로 초기화
//	// helen 객체 - id와 name과 weight를 3, Helen, 32.5로 초기화
//	grace.show(); // 객체 grace의 정보 출력
//	ashley.show(); // 객체 ashley의 정보 출력
//	helen.show(); // 객체 helen의 정보 출력
//}

//// 2-2 // 디폴트 매개 변수
//class Person // 클래스 Person
//{
//	int id;
//	double weight;
//	string name;
//public:
//	Person(int id = 1, string name = "Grace", double weight = 20.5)
//	{
//		// 디폴트 매개변수를 가진 생성자
//		// id나 name, weight의 값이 따로 입력되지않으면 디폴트된 값으로 초기화
//		this->id = id; // 따로 값이 입력되지않으면 1로 초기화
//		this->name = name; // 따로 값이 입력되지않으면 Grace로 초기화
//		this->weight = weight; // 따로 값이 입력되지않으면 20.5로 초기화
//	}
//	void show() // 객체의 정보 출력
//	{
//		cout << id << ' ' << weight << ' ' << name << endl;
//	}
//};
//int main()
//{
//	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
//	// grace 객체 - 디폴트값으로 멤버변수 초기화 
//	// ashley 객체 - id와 name을 2, Ashley로 초기화 - weight는 디폴트값으로 초기화
//	// helen 객체 - id와 name과 weight를 3, Helen, 32.5로 초기화
//	grace.show(); // 객체 grace의 정보 출력
//	ashley.show(); // 객체 ashley의 정보 출력
//	helen.show(); // 객체 helen의 정보 출력
//}

//// 3-1 // big 함수 중복
//int big(int n1, int n2)
//{
//	// n1과 n2 중 큰 값을 다른 변수에 저장,
//	// 그 변수가 최대값 100보다 작다면 변수값 반환, 크다면 100 리턴
//
//	int max = 0; // 더 큰 값을 저장할 변수
//	if (n1 > n2) // n2보다 n1이 크다면
//		max = n1; // max에 n1 저장
//	else // 작다면
//		max = n2; // max에 n2 저장
//	if (max < 100) // max 값이 100보다 작다면
//		return max; // max값 반환
//	else // 크다면 
//		return 100; // 최대값 100 반환
//
//	// 교수님이 하신 코드
//	//if (n1 > n2)
//	//{
//	//	if (n1 < 100)
//	//		return n1;
//	//	else
//	//		return 100;
//	//}
//	//else
//	//{
//	//	if (n2 < 100)
//	//		return n2;
//	//	else
//	//		return 100;
//	//}
//}
//int big(int n1, int n2, int n3)
//{
//	// n1과 n2 중 큰 값을 다른 변수에 저장,
//	// 그 변수가 최대값 n3보다 작다면 변수값 반환, 크다면 n3 리턴
//	int max = 0; // 더 큰 값을 저장할 변수
//	if (n1 > n2) // n2보다 n1이 크다면
//		max = n1; // max에 n1 저장
//	else // 작다면
//		max = n2; // max에 n2 저장
//	if (max < n3) // max 값이 n3보다 작다면
//		return max; // max값 반환
//	else // 크다면 
//		return n3; // 최대값 n3 반환
//}
//int main()
//{
//	int x = big(3, 5); // 3과 5 중 큰 값 5는 최대값 100보다 작으므로 , 5 리턴
//	int y = big(300, 60); // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100리턴
//	int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
//	cout << x << ' ' << y << ' ' << z << endl;
//}

//// 3-2 // 디폴트매개변수
//int big(int n1, int n2, int n3 = 100)
//{
// 	// n1과 n2 중 큰 값을 다른 변수에 저장,
//	// 그 변수가 최대값 n3보다 작다면 변수값 반환, 크다면 n3 리턴
//	// n3의 값이 따로 입력되지 않으면 100으로 기본 설정
//	int max = 0; // 더 큰 값을 저장할 변수
//	if (n1 > n2) // n2보다 n1이 크다면
//		max = n1; // max에 n1 저장
//	else // 작다면
//		max = n2; // max에 n2 저장
//	if (max < n3) // max 값이 n3보다 작다면
//		return max; // max값 반환
//	else // 크다면 
//		return n3; // 최대값 n3 반환
//}
//int main()
//{
//	int x = big(3, 5); // 3과 5 중 큰 값 5는 최대값 100보다 작으므로 , 5 리턴
//	int y = big(300, 60); // 300과 60 중 큰 값 300이 최대값 100보다 크므로, 100리턴
//	int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
//	cout << x << ' ' << y << ' ' << z << endl;
//}

////4 // 클래스 생성자 중복 -> 디폴트로 간소화 - 생성자를 하나로 만들기
//class MyVector
//{
//	int* mem;
//	int size;
//public:
//	MyVector(int n = 100, int val = 0); // 디폴트 매개변수를 가진 생성자
//	~MyVector() { if(mem) delete[] mem; } // 소멸자
//	void show() // 멤버변수 mem의 값을 출력하는 멤버함수
//	{
//		for (int i = 0; i < size; i++)
//			cout << mem[i];
//	}
//};
//MyVector::MyVector(int n, int val) // 디폴트 매개변수를 가진 생성자 // 선언문에서만 디폴트하기
//{
//	// 따로 입력된 수가 없다면 n을 100으로 , val을 0으로 기본설정
//	mem = new int[n];
//	size = n;
//	for (int i = 0; i < size; i++) mem[i] = val;
//}
//int main() // 테스트 프로그램
//{
//	MyVector a; // 기본 설정으로 생성자 호출
//	MyVector b(5); // n을 5로, val을 기본설정으로 하는 생성자 호출
//	MyVector c(5, 3); // n를 5로, val을 3으로 하는 생성자 호출
//	a.show();  cout << endl;  b.show(); cout << endl;  c.show();
//	// 각 객체의 멤버변수 출력해서 생성자가 잘 돌아가는지 확인함
//}

////5 // 동일한 크기로 배열을 변환하는 다음 2개의 static 멤버함수를 가진 ArrayUtility클래스를 만들어라.
//class ArrayUtility
//{
//public: // 공개
//	static void intToDouble(int source[], double dest[], int size) // 매개변수 - 주소연산
//	{
//		// int[]을 double[]로 변환
//		for (int i = 0; i < size; i++)
//		{
//			dest[i] = (double)source[i]; 
//			// 입력받은 source문자열을 double형으로 강제형변환해서 dest 문자열에 대입
//		}
//	}
//	static void doubleToint(double source[], int dest[], int size)
//	{
//		// double[]을 int[]로 변환
//		for (int i = 0; i < size; i++)
//		{
//			dest[i] = (int)source[i];
//			// 입력받은 source문자열을 int형으로 강제형변환해서 dest 문자열에 대입
//		}
//	}
//};
//int main()
//{
//	int x[] = { 1,2,3,4,5 }; // 정수형 문자열 x를 {}의 값으로 초기화
//	double y[5]; // 실수형 문자열 y 선언	
//	double z[] = { 9.9,8.8,7.7,6.6,5.6 }; // 실수형 문자열 z를 {}의 값으로 초기화
//
//	ArrayUtility::intToDouble(x, y, 5); // static멤버함수로 형변환된 x 문자열을 y문자열에 저장
//	for (int i = 0; i < 5; i++) cout << y[i] << ' ';
//	cout << endl;
//
//	ArrayUtility::doubleToint(z, x, 5); // static멤버함수로 형변환된 z 문자열을 x문자열에 저장
//	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
//	cout << endl;
//}

////6 // static
//class ArrayUtility2
//{
//public:
//	static int* concat(int s1[], int s2[], int size);
//	static int* remove(const int s1[], const int s2[], int size, int& retSize);
//};
//
//int* concat(int s1[], int s2[], int size)
//{
//	// s1과 s2를 연결한 새로운 배열을 동적생성하고 포인터 리턴
//	// 두 배열을 합친 배열을 담기위해 size의 두배만큼의 배열공간을 동적할당
//	int* n = new int[(2 * size)]();
//	if (!n)
//		return nullptr;
//	for (int i = 0; i < size; i++)
//	{
//		n[i] = s1[i]; // n의 0~4까지의 인덱스공간에 s1 배열 복사
//		n[i + size] = s2[i]; // n의 5~9까지의 인덱스공간에 s2배열 복사
//	}
//	return n; // n이 가지고 있는 주소값 반환 // 변수 n은 사라짐 // 힙공간은 사라지지 않음
//}
//
//int* remove(const int s1[], const int s2[], int size, int& retSize)
//{
//	// s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적생성하여 리턴
//	// 이때, s1과 s2의 배열공간의 수가 변하면 안됨 -> 다음에 사용하게 될 경우 고려
//	bool* same_check = new bool[size](); // bool형 배열공간을 동적생성해서 s1과 s2가 같은경우가 있는지 판단
//	if (!same_check)
//		return nullptr;
//	int cnt = 0; // retSize를 위한 변수
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (s1[i] == s2[j]) // s2[i]의 수가 s1[i]에 있으면
//			{
//				same_check[i] = true; // same_check[i] 공간을 1(true) 저장
//				cnt++; // 같은 수가 있는 경우 하나 증가
//				break;
//			}
//		}
//	}
//	retSize = size - cnt; // 한 배열의 크기에서 같은 경우를 빼면 다른 경우의 수만 남는다
//	int* m = new int[retSize](); // s1배열에서 s2배열과 같은 수를 뺀 수를 저장할 새로운 배열공간을 동적할당
//	if (!m)
//		return nullptr;
//	cnt = 0; // 변수를 다른 용도로 재사용하기 위해 0으로 초기화
//	for (int i = 0; i < size; i++)
//	{
//		if (same_check[i] == false) // same_check 배열의 i번째에 0(flase)가 있다면 // s1과 s2가 같지 않은 인덱스라면
//			m[cnt++] = s1[i]; // m의 cnt번째 공간에 s1의 i번째 수 저장 // cnt로 인해 s1과 s2가 다른 경우의 수만 m에 차곡차곡 저장하게 됨
//	}
//
//	if (same_check) // 동적할당된 same_check 배열 공간이 만들어 졌다면 delete
//		delete[] same_check;
//
//	if (retSize) // s1배열과 s2배열의 같지 않은 수가 있다면
//		return m; // m이 가지고 있는 주소 반환 // 변수 m은 사라짐 // 힙공간은 사라지지 않음
//	else
//		return NULL; // s1배열과 s2배열이 모두 같다면 NULL 반환
//}
//
//int main() 
//{
//	int x[5], y[5];
//
//	cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // 배열 x의 값 입력
//
//	cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";
//	for (int i = 0; i < 5; i++) cin >> y[i]; // 배열 y의 값 입력
//
//	int* p = ArrayUtility2::concat(x, y, 5); // 두 배열을 합쳐서 새로 할당받은 공간에 저장
//	cout << "합친 정수 배열을 출력한다" << endl;
//	for (int i = 0; i < 10; i++) cout << p[i] << ' '; // 배열 p의 i번째 수 출력
//	cout << endl;
//
//	int retSize(0); 
//	int* q = ArrayUtility2::remove(x, y, 5, retSize); // x배열에 y배열의 수가 들어있다면 그 수를 뺀 새로운 배열을 동적할당된 공간에 저장
//	// retSize는 참조전달이므로 함수 내에서 바뀌면 메인문에서도 바뀐다.
//	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
//	for (int i = 0; i < retSize; i++) cout << q[i] << ' ';
//	cout << endl;
//
//	if(p)
//		delete[] p; // concat함수에서 동적할당한 공간을 delete
//	if(q)
//		delete[] q; // remove함수에서 동적할당한 공간을 delete
//}

////7 // 코드 동작되게 만들기
//class Random
//{
//public:
//	static void seed() { srand((unsigned)time(0)); } // 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
//	static int nextInt(int min = 0, int max = 32767) // min과 max 사이의 랜덤 정수 리턴
//	{
//		// min이 따로 입력안되면 0부터 max까지 // max가 따로 입력안되면 min부터 32767까지
//		/*int n = ( rand() % max ) + min;*/
//		int range = max - min;
//		int n = rand() % (range + 1) + min;
//		return n;
//	}
//	static char nextAlphabet() // 랜덤 알파벳 문자 리턴
//	{
//		int upper = rand() % 2; // 1 이면 대문자, 0 이면 소문자
//		char ch = 0;
//		// 알파벳은 총 26개의 문자, 난수를 26으로 나눈 나머지는 0 ~ 25 중 하나
//		if (upper) // 대문자
//			ch = rand() % 26 + 'A'; // 나온 난수에 'A'를 더하면 대문자만 나옴
//		else // 소문자
//			ch = rand() % 26 + 'a'; // 나온 난수에 'a'를 더하면 소문자만 나옴
//		return ch; // 나온 알파벳 반환
//	}
//	static double nextDouble() // 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴
//	{
//		//    rand() =>  0 ~ RAND_MAX 사이의 난수 발생
//		//    난수를 RAND_MAX로 나누면 0 ~ 1 사이의 실수 
//		//    rand()는 정수, RAND_MAX도 정수
//		// 정수 / 정수 => 정수 : 강제 형변환 하지 않으면 0아니면 1이 나옴
//		double n = (double)rand() / (double)RAND_MAX;
//		return n; // 나온 실수 반환
//	}
//};
//int main() 
//{
//	Random::seed(); // 씨드 설정을 위해 seed 함수 호출 // static은 객체없이 클래스로 접근 가능
//	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
//	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
//	// nextInt함수를 이용해 1 ~ 100 사이의 랜덤정수 10개 출력
//	cout << endl;
//
//	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
//	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
//	// nextAlphabet함수를 이용해 10개의 랜덤 알파벳 출력
//	cout << endl;
//
//	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
//	// nextDouble함수를 이용해 10개의 랜덤 실수 출력
//	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
//	cout << endl;
//	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
//	cout << endl;
//}