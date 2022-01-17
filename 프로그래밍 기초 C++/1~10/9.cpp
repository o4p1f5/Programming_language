#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 1-1 // �Լ� �ߺ�
int add(int* arr, int n)  // �迭 a�� ������ ��� ���� �� ����
{
	int sum = 0; // ���� ���� ������ ����
	for (int i = 0; i < n; i ++)
	{
		sum += arr[i]; // arr�� i��° ���� sum�� ���簪�� ����
	}
	return sum; // ����� ���� sum�� �� ��ȯ
}
int add(int* arr1, int n, int* arr2) // �迭 a�� b�� ������ ��� ���� �� ����
{
	int sum = 0; // ���� ���� ������ ����
	for (int i = 0; i < n; i++)
	{
		sum += arr1[i]; // arr1�� i��° ���� sum�� ���簪�� ���� 
		sum += arr2[i]; // arr2�� i��° ���� sum�� ���簪�� ����
	}
	return sum; // ����� ���� sum�� �� ��ȯ
}
int main()
{
	int a[] = { 1,2,3,4,5 }; // �迭 a�� �� �ʱ�ȭ
	int b[] = { 6,7,8,9,10 }; // �迭 b�� �� �ʱ�ȭ
	int c = add(a, 5); // �迭 a�� ���� ��� ���� ���� c�� ����
	int d = add(a, 5, b); // �迭 a�� b�� ���� ��� ���� ���� d�� ����
	cout << c << endl; // c�� �� ���
	cout << d << endl; // d�� �� ���
}

//// 1-2 // ����Ʈ�Ű�����
//int add(int* arr1, int n, int* arr2 = 0) // arr2�� ����Ʈ�Ű������� �����ؼ� ���� ���� �Էµ��� ������ �ƹ��͵� ����Ű�� �ʴ� ���·� ������
//{
//	int sum = 0; // ���� ���� ������ ����
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr1[i]; // arr1�� i��° ���� ���� sum�� ���� ���ؼ� �ٽ� sum�� ����
//		if (arr2) // arr2�� �ּҰ��� �Էµƴٸ�
//			sum += arr2[i]; // arr2�� i��° ���� ���� sum�� ���� ���ؼ� �ٽ� sum�� ���� 
//	}
//	return sum; // ���� �������� ����
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5 }; // �迭 a�� �� �ʱ�ȭ
//	int b[] = { 6,7,8,9,10 }; // �迭 b�� �� �ʱ�ȭ
//	int c = add(a, 5); // �迭 a�� ���� ��� ���� ���� c�� ����
//	int d = add(a, 5, b); // �迭 a�� b�� ���� ��� ���� ���� d�� ����
//	// b�� �ּҸ� �Ѱ������ν� ����Ʈ�Ű������� ���� 0 -> b�� �ּҷ� �ٲ���
//	cout << c << endl; // c�� �� ���
//	cout << d << endl; // d�� �� ���
//}

//// 2-1 // ������ �ߺ�
//class Person // Ŭ���� Person
//{
//	int id;
//	double weight;
//	string name;
//public:
//	Person() // �⺻������ // �ƹ��͵� �Է¹��� �ʾ����� ȣ��Ǵ� ������
//	{
//		id = 1; weight = 20.5; name = "Grace";
//		// id�� 1��, weight�� 20.5��, name�� Grace�� �⺻������
//	}
//	Person(int id, string name) // �Ű������� �ִ� ������ 1
//	{
//		this->id = id; // �Է¹��� ������ id�� �ʱ�ȭ
//		this->name = name; // �Է¹��� ���ڿ��� name�� �ʱ�ȭ
//		weight = 20.5; // weight�� 20.5�� �⺻ ����
//	}
//	Person(int id, string name, double weight) // �Ű������� �ִ� ������ 2
//	{
//		this->id = id; // �Է¹��� ������ id�� �ʱ�ȭ
//		this->name = name; // �Է¹��� ���ڿ��� name�� �ʱ�ȭ
//		this->weight = weight; // �Է¹��� �Ǽ��� weight�� �ʱ�ȭ
//	}
//	void show() // ��ü�� ���� ���
//	{
//		cout << id << ' ' << weight << ' ' << name << endl;
//	}
//};
//int main()
//{
//	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
//	// grace ��ü - �⺻������ ȣ�� // ashley ��ü - id�� name�� 2, Ashley�� �ʱ�ȭ
//	// helen ��ü - id�� name�� weight�� 3, Helen, 32.5�� �ʱ�ȭ
//	grace.show(); // ��ü grace�� ���� ���
//	ashley.show(); // ��ü ashley�� ���� ���
//	helen.show(); // ��ü helen�� ���� ���
//}

//// 2-2 // ����Ʈ �Ű� ����
//class Person // Ŭ���� Person
//{
//	int id;
//	double weight;
//	string name;
//public:
//	Person(int id = 1, string name = "Grace", double weight = 20.5)
//	{
//		// ����Ʈ �Ű������� ���� ������
//		// id�� name, weight�� ���� ���� �Էµ��������� ����Ʈ�� ������ �ʱ�ȭ
//		this->id = id; // ���� ���� �Էµ��������� 1�� �ʱ�ȭ
//		this->name = name; // ���� ���� �Էµ��������� Grace�� �ʱ�ȭ
//		this->weight = weight; // ���� ���� �Էµ��������� 20.5�� �ʱ�ȭ
//	}
//	void show() // ��ü�� ���� ���
//	{
//		cout << id << ' ' << weight << ' ' << name << endl;
//	}
//};
//int main()
//{
//	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
//	// grace ��ü - ����Ʈ������ ������� �ʱ�ȭ 
//	// ashley ��ü - id�� name�� 2, Ashley�� �ʱ�ȭ - weight�� ����Ʈ������ �ʱ�ȭ
//	// helen ��ü - id�� name�� weight�� 3, Helen, 32.5�� �ʱ�ȭ
//	grace.show(); // ��ü grace�� ���� ���
//	ashley.show(); // ��ü ashley�� ���� ���
//	helen.show(); // ��ü helen�� ���� ���
//}

//// 3-1 // big �Լ� �ߺ�
//int big(int n1, int n2)
//{
//	// n1�� n2 �� ū ���� �ٸ� ������ ����,
//	// �� ������ �ִ밪 100���� �۴ٸ� ������ ��ȯ, ũ�ٸ� 100 ����
//
//	int max = 0; // �� ū ���� ������ ����
//	if (n1 > n2) // n2���� n1�� ũ�ٸ�
//		max = n1; // max�� n1 ����
//	else // �۴ٸ�
//		max = n2; // max�� n2 ����
//	if (max < 100) // max ���� 100���� �۴ٸ�
//		return max; // max�� ��ȯ
//	else // ũ�ٸ� 
//		return 100; // �ִ밪 100 ��ȯ
//
//	// �������� �Ͻ� �ڵ�
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
//	// n1�� n2 �� ū ���� �ٸ� ������ ����,
//	// �� ������ �ִ밪 n3���� �۴ٸ� ������ ��ȯ, ũ�ٸ� n3 ����
//	int max = 0; // �� ū ���� ������ ����
//	if (n1 > n2) // n2���� n1�� ũ�ٸ�
//		max = n1; // max�� n1 ����
//	else // �۴ٸ�
//		max = n2; // max�� n2 ����
//	if (max < n3) // max ���� n3���� �۴ٸ�
//		return max; // max�� ��ȯ
//	else // ũ�ٸ� 
//		return n3; // �ִ밪 n3 ��ȯ
//}
//int main()
//{
//	int x = big(3, 5); // 3�� 5 �� ū �� 5�� �ִ밪 100���� �����Ƿ� , 5 ����
//	int y = big(300, 60); // 300�� 60 �� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100����
//	int z = big(30, 60, 50); // 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
//	cout << x << ' ' << y << ' ' << z << endl;
//}

//// 3-2 // ����Ʈ�Ű�����
//int big(int n1, int n2, int n3 = 100)
//{
// 	// n1�� n2 �� ū ���� �ٸ� ������ ����,
//	// �� ������ �ִ밪 n3���� �۴ٸ� ������ ��ȯ, ũ�ٸ� n3 ����
//	// n3�� ���� ���� �Էµ��� ������ 100���� �⺻ ����
//	int max = 0; // �� ū ���� ������ ����
//	if (n1 > n2) // n2���� n1�� ũ�ٸ�
//		max = n1; // max�� n1 ����
//	else // �۴ٸ�
//		max = n2; // max�� n2 ����
//	if (max < n3) // max ���� n3���� �۴ٸ�
//		return max; // max�� ��ȯ
//	else // ũ�ٸ� 
//		return n3; // �ִ밪 n3 ��ȯ
//}
//int main()
//{
//	int x = big(3, 5); // 3�� 5 �� ū �� 5�� �ִ밪 100���� �����Ƿ� , 5 ����
//	int y = big(300, 60); // 300�� 60 �� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100����
//	int z = big(30, 60, 50); // 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
//	cout << x << ' ' << y << ' ' << z << endl;
//}

////4 // Ŭ���� ������ �ߺ� -> ����Ʈ�� ����ȭ - �����ڸ� �ϳ��� �����
//class MyVector
//{
//	int* mem;
//	int size;
//public:
//	MyVector(int n = 100, int val = 0); // ����Ʈ �Ű������� ���� ������
//	~MyVector() { if(mem) delete[] mem; } // �Ҹ���
//	void show() // ������� mem�� ���� ����ϴ� ����Լ�
//	{
//		for (int i = 0; i < size; i++)
//			cout << mem[i];
//	}
//};
//MyVector::MyVector(int n, int val) // ����Ʈ �Ű������� ���� ������ // ���𹮿����� ����Ʈ�ϱ�
//{
//	// ���� �Էµ� ���� ���ٸ� n�� 100���� , val�� 0���� �⺻����
//	mem = new int[n];
//	size = n;
//	for (int i = 0; i < size; i++) mem[i] = val;
//}
//int main() // �׽�Ʈ ���α׷�
//{
//	MyVector a; // �⺻ �������� ������ ȣ��
//	MyVector b(5); // n�� 5��, val�� �⺻�������� �ϴ� ������ ȣ��
//	MyVector c(5, 3); // n�� 5��, val�� 3���� �ϴ� ������ ȣ��
//	a.show();  cout << endl;  b.show(); cout << endl;  c.show();
//	// �� ��ü�� ������� ����ؼ� �����ڰ� �� ���ư����� Ȯ����
//}

////5 // ������ ũ��� �迭�� ��ȯ�ϴ� ���� 2���� static ����Լ��� ���� ArrayUtilityŬ������ ������.
//class ArrayUtility
//{
//public: // ����
//	static void intToDouble(int source[], double dest[], int size) // �Ű����� - �ּҿ���
//	{
//		// int[]�� double[]�� ��ȯ
//		for (int i = 0; i < size; i++)
//		{
//			dest[i] = (double)source[i]; 
//			// �Է¹��� source���ڿ��� double������ ��������ȯ�ؼ� dest ���ڿ��� ����
//		}
//	}
//	static void doubleToint(double source[], int dest[], int size)
//	{
//		// double[]�� int[]�� ��ȯ
//		for (int i = 0; i < size; i++)
//		{
//			dest[i] = (int)source[i];
//			// �Է¹��� source���ڿ��� int������ ��������ȯ�ؼ� dest ���ڿ��� ����
//		}
//	}
//};
//int main()
//{
//	int x[] = { 1,2,3,4,5 }; // ������ ���ڿ� x�� {}�� ������ �ʱ�ȭ
//	double y[5]; // �Ǽ��� ���ڿ� y ����	
//	double z[] = { 9.9,8.8,7.7,6.6,5.6 }; // �Ǽ��� ���ڿ� z�� {}�� ������ �ʱ�ȭ
//
//	ArrayUtility::intToDouble(x, y, 5); // static����Լ��� ����ȯ�� x ���ڿ��� y���ڿ��� ����
//	for (int i = 0; i < 5; i++) cout << y[i] << ' ';
//	cout << endl;
//
//	ArrayUtility::doubleToint(z, x, 5); // static����Լ��� ����ȯ�� z ���ڿ��� x���ڿ��� ����
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
//	// s1�� s2�� ������ ���ο� �迭�� ���������ϰ� ������ ����
//	// �� �迭�� ��ģ �迭�� ������� size�� �ι踸ŭ�� �迭������ �����Ҵ�
//	int* n = new int[(2 * size)]();
//	if (!n)
//		return nullptr;
//	for (int i = 0; i < size; i++)
//	{
//		n[i] = s1[i]; // n�� 0~4������ �ε��������� s1 �迭 ����
//		n[i + size] = s2[i]; // n�� 5~9������ �ε��������� s2�迭 ����
//	}
//	return n; // n�� ������ �ִ� �ּҰ� ��ȯ // ���� n�� ����� // �������� ������� ����
//}
//
//int* remove(const int s1[], const int s2[], int size, int& retSize)
//{
//	// s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���������Ͽ� ����
//	// �̶�, s1�� s2�� �迭������ ���� ���ϸ� �ȵ� -> ������ ����ϰ� �� ��� ���
//	bool* same_check = new bool[size](); // bool�� �迭������ ���������ؼ� s1�� s2�� ������찡 �ִ��� �Ǵ�
//	if (!same_check)
//		return nullptr;
//	int cnt = 0; // retSize�� ���� ����
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (s1[i] == s2[j]) // s2[i]�� ���� s1[i]�� ������
//			{
//				same_check[i] = true; // same_check[i] ������ 1(true) ����
//				cnt++; // ���� ���� �ִ� ��� �ϳ� ����
//				break;
//			}
//		}
//	}
//	retSize = size - cnt; // �� �迭�� ũ�⿡�� ���� ��츦 ���� �ٸ� ����� ���� ���´�
//	int* m = new int[retSize](); // s1�迭���� s2�迭�� ���� ���� �� ���� ������ ���ο� �迭������ �����Ҵ�
//	if (!m)
//		return nullptr;
//	cnt = 0; // ������ �ٸ� �뵵�� �����ϱ� ���� 0���� �ʱ�ȭ
//	for (int i = 0; i < size; i++)
//	{
//		if (same_check[i] == false) // same_check �迭�� i��°�� 0(flase)�� �ִٸ� // s1�� s2�� ���� ���� �ε������
//			m[cnt++] = s1[i]; // m�� cnt��° ������ s1�� i��° �� ���� // cnt�� ���� s1�� s2�� �ٸ� ����� ���� m�� �������� �����ϰ� ��
//	}
//
//	if (same_check) // �����Ҵ�� same_check �迭 ������ ����� ���ٸ� delete
//		delete[] same_check;
//
//	if (retSize) // s1�迭�� s2�迭�� ���� ���� ���� �ִٸ�
//		return m; // m�� ������ �ִ� �ּ� ��ȯ // ���� m�� ����� // �������� ������� ����
//	else
//		return NULL; // s1�迭�� s2�迭�� ��� ���ٸ� NULL ��ȯ
//}
//
//int main() 
//{
//	int x[5], y[5];
//
//	cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // �迭 x�� �� �Է�
//
//	cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
//	for (int i = 0; i < 5; i++) cin >> y[i]; // �迭 y�� �� �Է�
//
//	int* p = ArrayUtility2::concat(x, y, 5); // �� �迭�� ���ļ� ���� �Ҵ���� ������ ����
//	cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
//	for (int i = 0; i < 10; i++) cout << p[i] << ' '; // �迭 p�� i��° �� ���
//	cout << endl;
//
//	int retSize(0); 
//	int* q = ArrayUtility2::remove(x, y, 5, retSize); // x�迭�� y�迭�� ���� ����ִٸ� �� ���� �� ���ο� �迭�� �����Ҵ�� ������ ����
//	// retSize�� ���������̹Ƿ� �Լ� ������ �ٲ�� ���ι������� �ٲ��.
//	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
//	for (int i = 0; i < retSize; i++) cout << q[i] << ' ';
//	cout << endl;
//
//	if(p)
//		delete[] p; // concat�Լ����� �����Ҵ��� ������ delete
//	if(q)
//		delete[] q; // remove�Լ����� �����Ҵ��� ������ delete
//}

////7 // �ڵ� ���۵ǰ� �����
//class Random
//{
//public:
//	static void seed() { srand((unsigned)time(0)); } // �׻� �ٸ� �������� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
//	static int nextInt(int min = 0, int max = 32767) // min�� max ������ ���� ���� ����
//	{
//		// min�� ���� �Է¾ȵǸ� 0���� max���� // max�� ���� �Է¾ȵǸ� min���� 32767����
//		/*int n = ( rand() % max ) + min;*/
//		int range = max - min;
//		int n = rand() % (range + 1) + min;
//		return n;
//	}
//	static char nextAlphabet() // ���� ���ĺ� ���� ����
//	{
//		int upper = rand() % 2; // 1 �̸� �빮��, 0 �̸� �ҹ���
//		char ch = 0;
//		// ���ĺ��� �� 26���� ����, ������ 26���� ���� �������� 0 ~ 25 �� �ϳ�
//		if (upper) // �빮��
//			ch = rand() % 26 + 'A'; // ���� ������ 'A'�� ���ϸ� �빮�ڸ� ����
//		else // �ҹ���
//			ch = rand() % 26 + 'a'; // ���� ������ 'a'�� ���ϸ� �ҹ��ڸ� ����
//		return ch; // ���� ���ĺ� ��ȯ
//	}
//	static double nextDouble() // 0���� ũ�ų� ���� 1���� ���� ���� �Ǽ� ����
//	{
//		//    rand() =>  0 ~ RAND_MAX ������ ���� �߻�
//		//    ������ RAND_MAX�� ������ 0 ~ 1 ������ �Ǽ� 
//		//    rand()�� ����, RAND_MAX�� ����
//		// ���� / ���� => ���� : ���� ����ȯ ���� ������ 0�ƴϸ� 1�� ����
//		double n = (double)rand() / (double)RAND_MAX;
//		return n; // ���� �Ǽ� ��ȯ
//	}
//};
//int main() 
//{
//	Random::seed(); // ���� ������ ���� seed �Լ� ȣ�� // static�� ��ü���� Ŭ������ ���� ����
//	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
//	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
//	// nextInt�Լ��� �̿��� 1 ~ 100 ������ �������� 10�� ���
//	cout << endl;
//
//	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
//	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
//	// nextAlphabet�Լ��� �̿��� 10���� ���� ���ĺ� ���
//	cout << endl;
//
//	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
//	// nextDouble�Լ��� �̿��� 10���� ���� �Ǽ� ���
//	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
//	cout << endl;
//	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
//	cout << endl;
//}