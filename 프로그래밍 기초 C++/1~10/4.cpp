#include <iostream>                           
#include <string>      
#include <cstdlib>  // #include <stdlib.h> // ���а����Լ� - ��  = > ���� -> stdlib
#include <ctime>    // #include <time.h>
#pragma warning (disable : 4996)               
using namespace std;

////6 // 5���ڵ� �̿� //������� X // ������ ¦���� // �Լ����� while�� if(n%2==0) = ¦�� �ƴϸ� ���� �ٽ� �̱�
//class EvenRandom // EvenRandom Ŭ���� ����
//{
//public: // ����
//	EvenRandom() // �⺻������
//	{
//		srand((unsigned)time(NULL)); // ������ ���带 �ð��� ���� ��������ִ� �Լ�
//		// ��ü�� ������ �� ���带 ��������༭ ��ü���� �ٸ� ���尪�� ���� ��
//	}
//	int next(); // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ�
//	int nextIntRange(int a, int b); // 2 ~ 10 ���� �� �������� ������ �̴� �Լ�
//};
//int EvenRandom::next() // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ� ����
//{
//	while (true)
//	{
//		int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//		if (n % 2 == 0) // �� ���� ¦�����
//		{
//			return n; // ���� n ��ȯ
//		}
//	}
//}
//int EvenRandom::nextIntRange(int mn, int mx) // 2 ~ 10 ���� �� �������� ������ �̴� �Լ� ����
//{
//	int range = (mx - mn) + 1; // �Է¹��� �� �ΰ��� ���� �� �ִ� ���� ������ ������ ����
//	while (true)
//	{
//		int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//		if (n % 2 == 0) // �� ���� ¦�����
//		{
//			return n; // ���� n ��ȯ
//		}
//	}
//}
//int main()
//{
//	EvenRandom r; // EvenRandom Ŭ���� ��ü r ����
//	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl; // ���������� �̴´ٴ� ���� ���
//	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//	{
//		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
//		cout << n << ' '; // �� ������������ ���
//	}
//	cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl; // 2 ~ 10 ������ ���������� �̴´ٴ� ���� ���
//	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//	{
//		int n = r.nextIntRange(2, 10); // ����Լ��� ȣ���� 2���� 10 ������ ������ ������ ��ȯ�޾� ���� n�� ����
//		cout << n << ' '; // �� ������������ ���
//	}
//	cout << endl;
//}

////7 // 5���ڵ��̿� //������� �ϳ� bool��// ¦������ Ȧ���� �������� 
//class SelectableRandom // SelectableRandom Ŭ���� ����
//{
//	bool sel; // ������� - ������ ���� // ¦�� Ȧ���� �Ǵ��ϱ� ���� bool�� ����
//	// true�� ¦��, false�� Ȧ��
//public:
//	SelectableRandom() // �⺻ ������
//	{
//		sel = true; // sel�� true ��, ¦���� ����
//		srand((unsigned)time(NULL)); // ������ ���带 �ð��� ���� ��������ִ� �Լ�
//	}
//	SelectableRandom(bool s) // ������
//	{
//		sel = s; // �Է¹��� true�� false�� sel�� ����
//		srand((unsigned)time(NULL)); // ������ ���带 �ð��� ���� ��������ִ� �Լ�
//	}
//	int next(); // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ�
//	int nextIntRange(int a, int b); // 2 ~ 9 ���� �� �������� ������ �̴� �Լ�
//};
//int SelectableRandom::next() // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ� ����
//{
//	if (sel == true) // sel�� true��
//	{
//		while (true) // ¦�� �����߻���
//		{
//			int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//			if (n % 2 == 0) // �� ���� ¦�����
//			{
//				return n; // ���� n ��ȯ
//			}
//		}
//	}
//	else if (sel == false) // sel�� false���
//	{
//		while (true) // Ȧ�� �����߻���
//		{
//			int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//			if (n % 2 == 1) // �� ���� Ȧ�����
//			{
//				return n; // ���� n ��ȯ
//			}
//		}
//	}
//}
//int SelectableRandom::nextIntRange(int mn, int mx) // 2 ~ 9 ���� �� �������� ������ �̴� �Լ� ����
//{
//	int range = (mx - mn) + 1; // �Է¹��� �� �ΰ��� ���� �� �ִ� ���� ������ ������ ����
//	if (sel == true) // sel�� true���
//	{
//		while (true) // ¦�� �����߻���
//		{
//			int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//			if (n % 2 == 0) // �� ���� ¦�����
//			{
//				return n; // ���� n ��ȯ
//			}
//		}
//	}
//	else if (sel == false) // sel�� false���
//	{
//		while (true) // �Ǽ� �����߻���
//		{
//			int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//			if (n % 2 == 1) // �� ���� Ȧ�����
//			{
//				return n; // ���� n ��ȯ
//			}
//		}
//	}
//}
//
//int main()
//{
//	SelectableRandom evenRandom; // ¦�� �����߻��� // SelectableRandom Ŭ���� ��ü evenRandom ����
//	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl; // ���������� �̴´ٴ� ���� ���
//	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//	{
//		int n = evenRandom.next(); // ����Լ��� ȣ���� 0���� RAND_MAX(32767) ������ ������ ������ ��ȯ�޾� ���� n�� ����
//		cout << n << ' '; // �� ������������ ���
//	}
//	SelectableRandom oddRandom(false); // Ȧ�� �����߻��� // SelectableRandom Ŭ���� ��ü oddRandom ����
//	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl; // 2 ~ 9 ������ ���������� �̴´ٴ� ���� ���
//	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//	{
//		int n = oddRandom.nextIntRange(2, 9); // ����Լ��� ȣ���� 2���� 9 ������ ������ ������ ��ȯ�޾� ���� n�� ����
//		cout << n << ' '; // �� ������������ ���
//	}
//	cout << endl;
//}

////8
//class Integer // Integer Ŭ���� ����
//{
//	int integer; // ������� - ������ ���� // int�� �������� ��� ���� ����
//public:
//	Integer() // �⺻ ������
//	{
//		integer = 0; // integer�� 0���� �ʱ�ȭ
//	}
//	Integer(int n) // ������
//	{
//		integer = n; // �Է¹��� ���� n�� integer�� ����
//	}
//	Integer(string c) // ������
//	{
//		int i = stoi(c); // �Է¹��� ���ڿ��� ���������� �ٲ��ִ� �Լ� stoi
//		integer = i; // �ٲ� ������ integer�� ����
//	}
//	void set(int n); // �Է¹��� ���� integer�� �����ϱ� ���� �Լ�
//	int get(); // �Լ��� ȣ��Ǹ� integer ��ȯ
//	bool isEven(); // �Լ��� ȣ��Ǹ� true ��ȯ
//};
//void Integer::set(int n) // �Է¹��� ���� n�� integer�� ����
//{
//	integer = n;
//}
//int Integer::get() // integer�� ��ȯ
//{
//	return integer;
//}
//bool Integer::isEven() // ¦���� true�� ��ȯ
//{
//	if (integer % 2 == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	Integer n(30); // Integer Ŭ���� ��ü n ����
//	cout << n.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//	n.set(50); // ����Լ� set�� ȣ���Ͽ� integer�� 50 ����
//	cout << n.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//
//	Integer m("300"); // Integer Ŭ���� ��ü m ���� // string�� ���ڿ��� ��
//	cout << m.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//	cout << m.isEven(); // ����Լ� inEven�� ȣ���Ͽ� true(������ 1) ���
//}

////9 // �ڵ��Ȱ���ʿ�X // �Ҹ��� �ʿ� - ���X
//class Oval // Oval Ŭ���� ����
//{
//	int width; // �簢���� �ʺ��� �Է¹��� �������
//	int height; // �簢���� ���̸� �Է¹��� �������
//public:
//	Oval() // �⺻������
//	{
//		width = 1; height = 1; // �ʺ�� ���� ���� 1�� �ʱ�ȭ
//	}
//	Oval(int width, int height) // ������  // this ������ = ��ü �ڱ� �ڽ��� ����Ű�� ������
//	{
//		this->width = width; this->height = height; // �ʺ�� ���� ������ �Է¹��� w,h�� ���� ����
//	} //  main���� ���� ���� this�� b�� ����Ű�� �����Ͱ� ��
//	~Oval() // �Ҹ���
//	{
//		cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl;
//		// �Ҹ�Ǵ� Ŭ������ ���� �ʺ�� ���� ���� ���� ���
//        // ������ ��ü ������ �ݴ�� �Ҹ�
//	}
//	int getWidth(); // Ÿ���� �ʺ� �����ϴ� ��� �Լ�
//	int getHeight(); // Ÿ���� ���̸� �����ϴ� ��� �Լ�
//	void set(int w, int h); // �Է¹��� ���� width�� height�� �����ϴ� ����Լ�
//	void show(); // ������ Ÿ���� �ʺ�� ���̸� ����ϴ� ����Լ�
//};
//int Oval::getWidth() // Ÿ���� �ʺ� �����ϴ� ��� �Լ�
//{
//	return width;
//}
//int Oval::getHeight() // Ÿ���� ���̸� �����ϴ� ��� �Լ�
//{
//	return height;
//}
//void Oval::set(int w, int h) // �Է¹��� ���� width�� height�� �����ϴ� ����Լ�
//{
//	width = w; 
//	height = h;
//}
//void Oval::show() // ������ Ÿ���� �ʺ�� ���̸� ����ϴ� ����Լ�
//{
//	cout << "width = " <<width << ", height = "<< height << endl;
//}
//
//int main()
//{
//	Oval a, b(3, 4); // Oval Ŭ���� ��ü a�� b ����
//	a.set(10, 20); // ����Լ� set�� ȣ���ؼ� ��ü a�� width,height�� 10,20�� ����
//	a.show(); // ����Լ� show�� ȣ���ؼ� ���� ��ü a Ÿ���� �ʺ�� ���̸� ���
//	cout << b.getWidth() << ", " << b.getHeight() << endl; 
//	// ����Լ� getWidth�� getHeight�� ȣ���ؼ� ��ü b�� ���� �ʺ�� ���� ���
//}

//10 // Ŭ���� ������
class Add // Add Ŭ���� ����
{
	int a; // ������� a
	int b; // ������� b
public: 
	Add() // �⺻������ 
	{
		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
	}
	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
	int calculate(); // �������� �����ϴ� ����Լ�
};
void Add::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
{
	a = x, b = y;
}
int Add::calculate() // a�� b�� ���갪�� ����
{
	return a + b;
}
class Sub // Sub Ŭ���� ����
{
	int a; // ����Լ� a
	int b; // ����Լ� b
public:
	Sub() // �⺻������
	{
		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
	}
	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
	int calculate(); // �������� �����ϴ� ����Լ�
};
void Sub::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
{
	a = x, b = y;
}
int Sub::calculate() // a�� b�� ���갪�� ����
{
	return a - b;
}
class Mul // Mul Ŭ���� ���� 
{
	int a; // ����Լ� a
	int b; // ����Լ� b
public:
	Mul() // �⺻������
	{ 
		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
	}
	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
	int calculate(); // �������� �����ϴ� ����Լ�
};
void Mul::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
{
	a = x, b = y;
}
int Mul::calculate() // a�� b�� ���갪�� ����
{
	return a * b;
}
class Div // Div Ŭ���� ����
{
	int a; // ����Լ� a
	int b; // ����Լ� b
public:
	Div() // �⺻������
	{
		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
	}
	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
	int calculate(); // �������� �����ϴ� ����Լ�
};
void Div::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
{
	a = x, b = y;
}
int Div::calculate() // a�� b�� ���갪�� ����
{
	return a / b;
}

int main() 
{
	Add a; // Add Ŭ���� ��ü a ����
	Sub s; // Sub Ŭ���� ��ü s ����
	Mul m; // Mul Ŭ���� ��ü m ����
	Div d; // Div Ŭ���� ��ü d ����

	while (true) 
	{
		// ȭ�鿡 ������Ʈ�� ����ϰ� Ű����� �� ������ �����ڸ� �Է¹޴´�.
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		int x, y; // ������� a, b�� ������ �� ���� �������� ����
		char c; // � ������ ���� �������ִ� char���� ����
		cin >> x >> y >> c; // �Է¹��� ���� ���ڸ� ���ʴ�� �����鿡 ����
		switch (c) // ����ġ��
		{
		case '+': 	a.setValue(x, y); cout << a.calculate(); break;
			// char������ +�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
		case '-': 	s.setValue(x, y); cout << s.calculate(); break;
			// char������ -�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
		case '*': 	m.setValue(x, y); cout << m.calculate(); break;
			// char������ *�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
		case '/': 	d.setValue(x, y); cout << d.calculate(); break;
			// char������ /�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
		}
		cout << endl;
	}
}