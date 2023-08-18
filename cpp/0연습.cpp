////#include <iostream>                           
////#include <string>      
////#include <cstdlib>  // #include <stdlib.h> // ���а����Լ� - ��  = > ���� -> stdlib
////#include <ctime>    // #include <time.h>
////#pragma warning (disable : 4996)               
////using namespace std;
////
////////6 // 5���ڵ� �̿� //������� X // ������ ¦���� // �Լ����� while�� if(n%2==0) = ¦�� �ƴϸ� ���� �ٽ� �̱�
//////class EvenRandom // EvenRandom Ŭ���� ����
//////{
//////public: // ����
//////	EvenRandom() // �⺻������
//////	{
//////		srand((unsigned)time(NULL)); // ������ ���带 �ð��� ���� ��������ִ� �Լ�
//////		// ��ü�� ������ �� ���带 ��������༭ ��ü���� �ٸ� ���尪�� ���� ��
//////	}
//////	int next(); // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ�
//////	int nextIntRange(int a, int b); // 2 ~ 10 ���� �� �������� ������ �̴� �Լ�
//////};
//////int EvenRandom::next() // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ� ����
//////{
//////	while (true)
//////	{
//////		int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//////		if (n % 2 == 0) // �� ���� ¦�����
//////		{
//////			return n; // ���� n ��ȯ
//////		}
//////		else
//////		{
//////			continue; // ¦���� �ƴ϶�� �ٽ� �̱�
//////		}
//////	}
//////}
//////int EvenRandom::nextIntRange(int mn, int mx) // 2 ~ 10 ���� �� �������� ������ �̴� �Լ� ����
//////{
//////	int range = (mx - mn) + 1; // �Է¹��� �� �ΰ��� ���� �� �ִ� ���� ������ ������ ����
//////	while (true)
//////	{
//////		int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//////		if (n % 2 == 0) // �� ���� ¦�����
//////		{
//////			return n; // ���� n ��ȯ
//////		}
//////		else
//////		{
//////			continue; // ¦���� �ƴ϶�� �ٽ� �̱�
//////		}
//////	}
//////}
//////int main()
//////{
//////	EvenRandom r; // EvenRandom Ŭ���� ��ü r ����
//////	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl; // ���������� �̴´ٴ� ���� ���
//////	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//////	{
//////		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
//////		cout << n << ' '; // �� ������������ ���
//////	}
//////	cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl; // 2 ~ 10 ������ ���������� �̴´ٴ� ���� ���
//////	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//////	{
//////		int n = r.nextIntRange(2, 10); // ����Լ��� ȣ���� 2���� 10 ������ ������ ������ ��ȯ�޾� ���� n�� ����
//////		cout << n << ' '; // �� ������������ ���
//////	}
//////	cout << endl;
//////}
////
////////7 // 5���ڵ��̿� //������� �ϳ� bool��// ¦������ Ȧ���� �������� 
//////class SelectableRandom // SelectableRandom Ŭ���� ����
//////{
//////	bool sel; // ������� - ������ ���� // ¦�� Ȧ���� �Ǵ��ϱ� ���� bool�� ����
//////	// true�� ¦��, false�� Ȧ��
//////public:
//////	SelectableRandom() // �⺻ ������
//////	{
//////		sel = true; // sel�� true ��, ¦���� ����
//////	}
//////	SelectableRandom(bool s) // ������
//////	{
//////		sel = s; // �Է¹��� true�� false�� sel�� ����
//////	}
//////	int next(); // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ�
//////	int nextIntRange(int a, int b); // 2 ~ 9 ���� �� �������� ������ �̴� �Լ�
//////};
//////int SelectableRandom::next() // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ� ����
//////{
//////	if (sel == true) // sel�� true��
//////	{
//////		while (true) // ¦�� �����߻���
//////		{
//////			int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//////			if (n % 2 == 0) // �� ���� ¦�����
//////			{
//////				return n; // ���� n ��ȯ
//////			}
//////			else
//////			{
//////				continue; // ¦���� �ƴ϶�� �ٽ� �̱�
//////			}
//////		}
//////	}
//////	else if (sel == false) // sel�� false���
//////	{
//////		while (true) // Ȧ�� �����߻���
//////		{
//////			int n = rand();// �������� ���� �̾� ������ ���� n�� ����
//////			if (n % 2 == 1) // �� ���� Ȧ�����
//////			{
//////				return n; // ���� n ��ȯ
//////			}
//////			else
//////			{
//////				continue; // Ȧ���� �ƴ϶�� �ٽ� �̱�
//////			}
//////		}
//////	}
//////}
//////int SelectableRandom::nextIntRange(int mn, int mx) // 2 ~ 9 ���� �� �������� ������ �̴� �Լ� ����
//////{
//////	int range = (mx - mn) + 1; // �Է¹��� �� �ΰ��� ���� �� �ִ� ���� ������ ������ ����
//////	if (sel == true) // sel�� true���
//////	{
//////		while (true) // ¦�� �����߻���
//////		{
//////			int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//////			if (n % 2 == 0) // �� ���� ¦�����
//////			{
//////				return n; // ���� n ��ȯ
//////			}
//////			else
//////			{
//////				continue; // ¦���� �ƴ϶�� �ٽ� �̱�
//////			}
//////		}
//////	}
//////	else if (sel == false) // sel�� false���
//////	{
//////		while (true) // �Ǽ� �����߻���
//////		{
//////			int n = mn + (rand() % range); // mn�� mn ������ ���� ������ ���� n�� �����Ѵ�.
//////			if (n % 2 == 1) // �� ���� Ȧ�����
//////			{
//////				return n; // ���� n ��ȯ
//////			}
//////			else
//////			{
//////				continue; // Ȧ���� �ƴ϶�� �ٽ� �̱�
//////			}
//////		}
//////	}
//////}
//////
//////int main()
//////{
//////	SelectableRandom evenRandom; // ¦�� �����߻��� // SelectableRandom Ŭ���� ��ü evenRandom ����
//////	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl; // ���������� �̴´ٴ� ���� ���
//////	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//////	{
//////		int n = evenRandom.next(); // ����Լ��� ȣ���� 0���� RAND_MAX(32767) ������ ������ ������ ��ȯ�޾� ���� n�� ����
//////		cout << n << ' '; // �� ������������ ���
//////	}
//////	SelectableRandom oddRandom(false); // Ȧ�� �����߻��� // SelectableRandom Ŭ���� ��ü oddRandom ����
//////	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl; // 2 ~ 9 ������ ���������� �̴´ٴ� ���� ���
//////	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
//////	{
//////		int n = oddRandom.nextIntRange(2, 9); // ����Լ��� ȣ���� 2���� 9 ������ ������ ������ ��ȯ�޾� ���� n�� ����
//////		cout << n << ' '; // �� ������������ ���
//////	}
//////	cout << endl;
//////}
////
////////8
//////class Integer // Integer Ŭ���� ����
//////{
//////	int integer; // ������� - ������ ���� // int�� �������� ��� ���� ����
//////public:
//////	Integer() // �⺻ ������
//////	{
//////		integer = 0; // integer�� 0���� �ʱ�ȭ
//////	}
//////	Integer(int n) // ������
//////	{
//////		integer = n; // �Է¹��� ���� n�� integer�� ����
//////	}
//////	Integer(string c) // ������
//////	{
//////		int i = stoi(c); // �Է¹��� ���ڿ��� ���������� �ٲ��ִ� �Լ� stoi
//////		integer = i; // �ٲ� ������ integer�� ����
//////	}
//////	void set(int n); // �Է¹��� ���� integer�� �����ϱ� ���� �Լ�
//////	int get(); // �Լ��� ȣ��Ǹ� integer ��ȯ
////////	bool isEven(); // �Լ��� ȣ��Ǹ� true ��ȯ
//////};
//////void Integer::set(int n) // �Է¹��� ���� n�� integer�� ����
//////{
//////	integer = n;
//////}
//////int Integer::get() // integer�� ��ȯ
//////{
//////	return integer;
//////}
//////bool Integer::isEven() // true�� ��ȯ
//////{
//////	return true;
//////}
//////
//////int main()
//////{
//////	Integer n(30); // Integer Ŭ���� ��ü n ����
//////	cout << n.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//////	n.set(50); // ����Լ� set�� ȣ���Ͽ� integer�� 50 ����
//////	cout << n.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//////
//////	Integer m("300"); // Integer Ŭ���� ��ü m ���� // string�� ���ڿ��� ��
//////	cout << m.get() << ' '; // ����Լ� get�� ȣ���Ͽ� integer ���
//////	cout << m.isEven(); // ����Լ� inEven�� ȣ���Ͽ� true(������ 1) ���
//////}
////
////////9 // �ڵ��Ȱ���ʿ�X // �Ҹ��� �ʿ� - ���X
//////class Oval // Oval Ŭ���� ����
//////{
//////	int width; // �簢���� �ʺ��� �Է¹��� �������
//////	int height; // �簢���� ���̸� �Է¹��� �������
//////public:
//////	Oval() // �⺻������
//////	{
//////		width = 1; height = 1; // �ʺ�� ���� ���� 1�� �ʱ�ȭ
//////	}
//////	Oval(int w, int h) // ������
//////	{
////////		width = w; height = h; // �ʺ�� ���� ������ �Է¹��� w,h�� ���� ����
//////	}
//////	~Oval() // �Ҹ���
//////	{
//////		cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl;
//////		// �Ҹ�Ǵ� Ŭ������ ���� �ʺ�� ���� ���� ���� ���
//////        // ������ ��ü ������ �ݴ�� �Ҹ�
//////	}
//////	int getWidth(); // Ÿ���� �ʺ� �����ϴ� ��� �Լ�
//////	int getHeight(); // Ÿ���� ���̸� �����ϴ� ��� �Լ�
//////	void set(int w, int h); // �Է¹��� ���� width�� height�� �����ϴ� ����Լ�
//////	void show(); // ������ Ÿ���� �ʺ�� ���̸� ����ϴ� ����Լ�
//////};
//////int Oval::getWidth() // Ÿ���� �ʺ� �����ϴ� ��� �Լ�
//////{
//////	return width;
//////}
//////int Oval::getHeight() // Ÿ���� ���̸� �����ϴ� ��� �Լ�
//////{
//////	return height;
//////}
//////void Oval::set(int w, int h) // �Է¹��� ���� width�� height�� �����ϴ� ����Լ�
//////{
//////	width = w; 
//////	height = h;
//////}
//////void Oval::show() // ������ Ÿ���� �ʺ�� ���̸� ����ϴ� ����Լ�
//////{
//////	cout << "width = " <<width << ", height = "<< height << endl;
//////}
//////
//////int main()
//////{
//////	Oval a, b(3, 4); // Oval Ŭ���� ��ü a�� b ����
//////	a.set(10, 20); // ����Լ� set�� ȣ���ؼ� ��ü a�� width,height�� 10,20�� ����
//////	a.show(); // ����Լ� show�� ȣ���ؼ� ���� ��ü a Ÿ���� �ʺ�� ���̸� ���
//////	cout << b.getWidth() << ", " << b.getHeight() << endl; 
//////	// ����Լ� getWidth�� getHeight�� ȣ���ؼ� ��ü b�� ���� �ʺ�� ���� ���
//////}
////
//////10 // Ŭ���� ������
////class Add // Add Ŭ���� ����
////{
////	int a; // ������� a
////	int b; // ������� b
////public:
////	Add() // �⺻������ 
////	{
////		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
////	}
////	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
////	int calculate(); // �������� �����ϴ� ����Լ�
////};
////void Add::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
////{
////	a = x, b = y;
////}
////int Add::calculate() // a�� b�� ���갪�� ����
////{
////	return a + b;
////}
////class Sub // Sub Ŭ���� ����
////{
////	int a; // ����Լ� a
////	int b; // ����Լ� b
////public:
////	Sub() // �⺻������
////	{
////		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
////	}
////	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
////	int calculate(); // �������� �����ϴ� ����Լ�
////};
////void Sub::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
////{
////	a = x, b = y;
////}
////int Sub::calculate() // a�� b�� ���갪�� ����
////{
////	return a - b;
////}
////class Mul // Mul Ŭ���� ���� 
////{
////	int a; // ����Լ� a
////	int b; // ����Լ� b
////public:
////	Mul() // �⺻������
////	{
////		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
////	}
////	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
////	int calculate(); // �������� �����ϴ� ����Լ�
////};
////void Mul::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
////{
////	a = x, b = y;
////}
////int Mul::calculate() // a�� b�� ���갪�� ����
////{
////	return a * b;
////}
////class Div // Div Ŭ���� ����
////{
////	int a; // ����Լ� a
////	int b; // ����Լ� b
////public:
////	Div() // �⺻������
////	{
////		a = 1; b = 1; // ������� a�� b�� 1�� �ʱ�ȭ
////	}
////	void setValue(int x, int y); // �Է¹��� ���� ������� �ʱ�ȭ�ϴ� ����Լ�
////	int calculate(); // �������� �����ϴ� ����Լ�
////};
////void Div::setValue(int x, int y) // �Է¹��� ���� x, y�� ������� a,b�� ���� 
////{
////	a = x, b = y;
////}
////int Div::calculate() // a�� b�� ���갪�� ����
////{
////	return a / b;
////}
////
////int main()
////{
////	Add a; // Add Ŭ���� ��ü a ����
////	Sub s; // Sub Ŭ���� ��ü s ����
////	Mul m; // Mul Ŭ���� ��ü m ����
////	Div d; // Div Ŭ���� ��ü d ����
////
////	while (true)
////	{
////		// ȭ�鿡 ������Ʈ�� ����ϰ� Ű����� �� ������ �����ڸ� �Է¹޴´�.
////		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
////		int x, y; // ������� a, b�� ������ �� ���� �������� ����
////		char c; // � ������ ���� �������ִ� char���� ����
////		cin >> x >> y >> c; // �Է¹��� ���� ���ڸ� ���ʴ�� �����鿡 ����
////		switch (c) // ����ġ��
////		{
////		case '+': 	a.setValue(x, y); cout << a.calculate(); break;
////			// char������ +�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
////			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
////		case '-': 	s.setValue(x, y); cout << s.calculate(); break;
////			// char������ -�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
////			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
////		case '*': 	m.setValue(x, y); cout << m.calculate(); break;
////			// char������ *�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
////			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
////		case '/': 	d.setValue(x, y); cout << d.calculate(); break;
////			// char������ /�� ����Ǿ��ٸ� ����Լ� setValue�� calculate�� ȣ���ؼ� 
////			// x,y�� ��ü a�� a,b�� �����ϰ�, �� ���갪�� ����Ѵ�.
////		}
////		cout << endl;
////	}
////}
////
////#include <iostream>
////using namespace std;
////
////////3-1 // ����Լ� �̿�
//////class Book
//////{
//////	string title; // å�� �̸�
//////	int price; // å ����
//////	int pages; // å�� ����
//////public:
//////	Book(string title = " ", int price = 0, int pages = 0)
//////	{
//////		// ����Ʈ�Ű������� �̿��� ������
//////		this->title = title; this->price = price; this->pages = pages;
//////	}
//////	void show() // å�� ���� ���
//////	{
//////		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//////	}
//////	string getTitle() { return title; } // å ���� ���
//////	bool operator!() // ! ������ ����
//////	{
//////		if(!price) // ��ü�� price�� 0�̶�� ! �����ڸ� ���� 0�� �ƴ� ���� �ȴ�
//////			return true; // true ��ȯ
//////		else // 0�� �ƴ� �ٸ� ���̶�� ! �����ڸ� ���� 0�� �ȴ�
//////			return false; // false ��ȯ 
//////	}
//////};
//////int main()
//////{
//////	Book book("�������", 0, 50); // ��ü ���� �Է� // ���� : 0
//////	if (!book) cout << "��¥��" << endl; // book�� ������ 0���̶�� '��¥��' ���
//////    // book.operator!();
//////}
////
////////3-2 // ������ �Լ� �̿�
//////class Book
//////{
//////	string title; // å ����
//////	int price; // å ����
//////	int pages; // å ������ ��
//////public:
//////	Book(string title = " ", int price = 0, int pages = 0)
//////	{
//////		// ����Ʈ �Ű������� �̿��� ������
//////		this->title = title; this->price = price; this->pages = pages;
//////	}
//////	void show() // ��ü�� ���� ��� ���
//////	{
//////		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//////	}
//////	string getTitle() { return title; } // ���� ���
//////	friend bool operator!(Book op1); // ������ ! �� ������ �Ϲ��Լ� ������ȭ
//////};
//////bool operator!(Book op1) // ! ������ ���� // ���� ������ // ���� �ʿ����
//////{
//////	if (!op1.price) // ��ü�� price�� 0�̶�� ! �����ڸ� ���� 0�� �ƴ� ���� �ȴ�
//////		return true; // true ��ȯ
//////	else // 0�� �ƴ� �ٸ� ���̶�� ! �����ڸ� ���� 0�� �ȴ�
//////		return false; // false ��ȯ 
//////}
//////int main()
//////{
//////	Book book("�������", 0, 50); // ��ü ���� �Է� // ���� : 0
//////	if (!book) cout << "��¥��" << endl; // book�� ������ 0���̶�� '��¥��' ���
//////    // operator!(book); 
//////}
////
////////8-1 // ����Լ� �̿� // ���� ������ - ����, ����
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//////	Circle operator++() // ����++ ����
//////	{
//////		this->radius++;
//////		return *this; // a ��ȯ
//////	}
//////	Circle operator++(int n) // ����++ ����
//////	{
//////		Circle tmp = *this; // �ٲ�� �� a�� �� ����
//////		this->radius++; // a ����
//////		return tmp; // �ٲ�� ���� ���� ��ȯ�� b�� �������
//////	}
//////};
//////int main()
//////{
//////	Circle a(5), b(4); // ��ü a,b ����
//////	++a; // ���� // a.operator++(); 
//////	b = a++; // ���� // b = a.operator++(0); 
//////	a.show(); b.show();
//////}
////
////////8-2 // ������ �Լ�
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//////	friend Circle operator++(Circle& op); // ���� ++������ ���� // �Ϲ��Լ� -> �������Լ�
//////	friend Circle operator++(Circle& op, int n); // ���� ++������ ���� // �Ϲ��Լ� -> �������Լ�
//////};
//////Circle operator++(Circle &op) // ���� // �������ϸ� ����������� ���ι��� ��ü�� �ٲ��� ����
//////{
//////	// ����++ ���� // ��ü a ����
//////	op.radius++; // a ����
//////	return op; // a ���� ��ȯ
//////}
//////Circle operator++(Circle &op, int n) // ���� // �������ϸ� ����������� ���ι��� ��ü�� �ٲ��� ����
//////{
//////	// ����++ ���� // ��ü a ����
//////	Circle tmp = op; // �ٲ�� �� a�� �� ����
//////	op.radius++; // a ����
//////	return tmp; // �ٲ�� ���� ���� ��ȯ�� b�� �������
//////}
//////int main()
//////{
//////	Circle a(5), b(4); // ��ü a,b ����
//////	++a; // ���� // operator++(a); 
//////	b = a++; // ���� // b = operator++(a,0); 
//////	a.show(); b.show();
//////}
////
////////9 // �������Լ��� ����
//////class Circle
//////{
//////	int radius;
//////public:
//////	Circle(int radius = 0) { this->radius = radius; }
//////	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//////	friend Circle operator+(int n, Circle op);
//////};
//////Circle operator+(int n, Circle op) // a�� �� �ٲ�� �ȵǹǷ� ���� X // �������
//////{
//////	op.radius = op.radius + n; // op�� �������� n�� ���� ���� op�� �������� ����
//////	return op; // ��ü op ��ȯ
//////}
//////int main()
//////{
//////	Circle a(5), b(4); // ��ü a,b ����
//////	b = 1 + a; // b = operator+(1,a) // b = 1.operator+(a) �� 1�� ��ü�� �ƴϹǷ� �Ұ��� - ����Լ��� ������ ������ �� ����.
//////	// b�� �������� a�� �������� 1�� ���� ������ ���� // ��ȯ�� ��ü�� �������
//////	a.show(); b.show();
//////}
////
////////10-1 // ����Լ�
//////class Statistics // ��踦 ���� Ŭ����
//////{
//////	int* p; // �迭�� �����Ҵ��� �� �ּҸ� ���� ������ ����
//////	int size; // �ε���
//////	int capacity; // �����Ҵ�� ������ ��
//////public:
//////	Statistics(int size = 0, int capacity = 10)
//////	{
//////		// ����Ʈ �Ű������� �̿��� ������
//////		this->size = size;
//////		this->capacity = capacity;
//////		p = new int[capacity];
//////	}
//////	Statistics(Statistics& s) // ���������
//////	{
//////		this->size = s.size; // s�� ���� �ѱ�
//////		this->capacity = s.capacity;
//////		this->p = new int[this->capacity]; // ���޹��� capacity��ŭ ���Ӱ� �����Ҵ� �� p�� �ּ� ���� 
//////		for (int i = 0; i < this->size; i++) // ������ ���� �ε��� ���̱��� �ݺ���
//////			p[i] = s.p[i]; // p�� �迭������ ��ü s�� �迭������ ����� �� ����
//////	}
//////	~Statistics() // �Ҹ���
//////	{
//////		if (p) // �����Ҵ� ���� p�� ���� ����
//////			delete[] p;
//////	}
//////	bool operator!() // ! ������ ����
//////	{
//////		if (!size)
//////			return true; // �����Ҵ���� ������ �Է¹��� ���� �ϳ��� ������ �ǹ�
//////		else
//////			return false; // �����Ҵ���� ������ ���� �ԷµǾ������� �ǹ�
//////	}
//////	Statistics& operator<<(int op) // << ������ ���� // �Է¹��� x�迭�� ������ 
//////	{
//////		p[size++] = op; // ��ü stat�� size��° �ε����� �ϳ��� ���� // size�� �����ϹǷ� �ε����� �÷���
//////		return *this; // ���� ��ü�� ���� ��ȯ
//////	}
//////	void operator~() // ~ ������ ���� // �Ҹ��� X // p���
//////	{
//////		for (int i = 0; i < size; i++)
//////			cout << p[i] << " "; // p�� ����Ű�� ������ ����� ������ ���
//////		cout << endl;
//////	}
//////	void operator>>(int& avg) // >> ������ ���� // p�� ����Ű�� ������ ��� �� ����
//////	{
//////		// avg ����
//////		int sum = 0;
//////		for (int i = 0; i < size; i++)
//////			sum += p[i]; // ��� ���� ��
//////		avg = sum / size; // ���� �����ε����� ���� ������ ����� ����
//////	}
//////};
//////int main()
//////{
//////	Statistics stat; // size�� 0�̰�, �迭������ 10��ŭ �����Ҵ��ϰ� �� �ּҸ� p�� ����
//////	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
//////	// stat.operator!(); 
//////	// stat�� size�� 0�̶�� => stat�� ���� �� ���� ���ٸ� true ��ȯ
//////
//////	int x[5];
//////	cout << "5 ���� ������ �Է��϶�>>";
//////	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]�� ���� �Է�
//////
//////	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�. // stat.operator<<(x[i])
//////	stat << 100 << 200; // 100, 200�� ��� ��ü�� �����Ѵ�.
//////	//stat.operator<<(100).operator<<(200) // ������ �� �ؾ� �����ڸ� �������� ����ϴ� ����� ����� �� ����
//////	
//////	~stat; // stat.operator~(); // ��� �����͸� ��� ���
//////
//////	int avg;
//////	stat >> avg; // stat.operator>(avg); // ��� ��ü�κ��� ����� �޴´�.
//////	cout << "avg = " << avg << endl; // ��� ���
//////}
////
////////10-2 // �������Լ� �̿�
//////class Statistics
//////{
//////	int* p; // �迭�� �����Ҵ��� �� �ּҸ� ���� ������ ����
//////	int size; // �ε���
//////	int capacity; // �����Ҵ�� ������ ��
//////public:
//////	Statistics(int size = 0, int capacity = 10)
//////	{
//////		// ����Ʈ �Ű������� �̿��� ������
//////		this->size = size;
//////		this->capacity = capacity;
//////		p = new int[capacity];
//////	}
//////	Statistics(Statistics& s) // ���������
//////	{
//////		this->size = s.size; // s�� ���� �ѱ�
//////		this->capacity = s.capacity; // ������ ���� �ε��� ���̱��� �ݺ��� 
//////		this->p = new int[this->capacity]; // ���޹��� capacity��ŭ ���Ӱ� �����Ҵ� �� p�� �ּ� ���� 
//////		for (int i = 0; i < this->size; i++) // ������ ���� �ε��� ���̱��� �ݺ���
//////			p[i] = s.p[i]; // p�� �迭������ ��ü s�� �迭������ ����� �� ����
//////	}
//////	~Statistics() // �Ҹ���
//////	{
//////		if (p) // �����Ҵ� ���� p�� ���� ����
//////			delete[] p;
//////	}
//////	friend bool operator!(Statistics op); // ! ������ ����
//////	friend Statistics& operator<<(Statistics& op1, int op2); // << ������ ����
//////	friend void operator~(Statistics op); // ~ ������ ����
//////	friend void operator>>(Statistics op, int& avg); // >> ������ ����
//////};
//////bool operator!(Statistics op) // ! ������ ����
//////{
//////	if (!op.size) // ���� ��ü�� �� ���� ���ٸ�
//////		return true; // true ��ȯ
//////	else // �� ���� �ϳ���� �ֵ��
//////		return false; // false ��ȯ
//////}
//////Statistics& operator<<(Statistics& op1, int op2) // ������ �����Ϸ��� �����Ǵ� ������ �����ؾ��Ѵ�
//////{
//////	op1.p[op1.size++] = op2; // �Է¹��� op2�� op1�� p�� ����Ű�� �� ������ size �ε����� ����
//////	return op1; // ���� ��ȯ
//////}
//////void operator~(Statistics op) // ~ ������ ����
//////{
//////	for (int i = 0; i < op.size; i++)
//////		cout << op.p[i] << " "; // ��ü op�� p�� ����Ű�� �������� �� ���
//////	cout << endl;
//////}
//////void operator>>(Statistics op, int& avg) // >> ������ ����
//////{
//////	int sum = 0;
//////	for (int i = 0; i < op.size; i++)
//////		sum += op.p[i]; // ��ü op�� �� ��� ����
//////	avg = sum / op.size; // ��� ���� ���� op�� size(���� ���� ����Ǿ��ִ� ������ ������ �ε���)�� ���� ��հ��� ����
//////}
//////int main()
//////{
//////	Statistics stat; // size�� 0�̰�, �迭������ 10��ŭ �����Ҵ��ϰ� �� �ּҸ� p�� ����
//////	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
//////	// stat.operator!(); // operator!(stat);
//////	// stat�� size�� 0�̶�� => stat�� ���� �� ���� ���ٸ� true ��ȯ
//////
//////	int x[5];
//////	cout << "5 ���� ������ �Է��϶�>>";
//////	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]�� ���� �Է�
//////
//////	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�.
//////	// operator<<(stat, x[i]);
//////
//////	stat << 100 << 200; // 100, 200�� ��� ��ü�� �����Ѵ�.
//////	//stat.operator<<(100).operator<<(200) // ������ �� �ؾ� �����ڸ� �������� ����ϴ� ����� ����� �� ����
//////	
//////	~stat; // stat.operator~(); //operator~(stat) // ��� �����͸� ��� ���
//////
//////	int avg;
//////	stat >> avg; // stat.operator>(avg); // operator(stat,avg); // ��� ��ü�κ��� ����� �޴´�.
//////	cout << "avg = " << avg << endl; // ��� ���
//////}
////
////////11-1 // ����Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//////class Stack // Ŭ���� Stack
//////{
//////	int p[10]; // ũ�Ⱑ 10�� �迭 p
//////	int tos; // �ε����� �˷��ִ� �������
//////public: // ����
//////	Stack() // �⺻������
//////	{
//////		tos = 0; // 0���� �ʱ�ȭ
//////		for (int i = 0; i < 10; i++)
//////			p[i] = 0; // �迭�� ��� �ε����� 1�� �ʱ�ȭ
//////	}
//////	Stack& operator<< (int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//////	{
//////		p[tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//////		return *this; // �ٲ� ��ü ����
//////	}
//////	bool operator! () // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//////	{
//////		if (tos == 0) // ���� ����� ������ 
//////			return true; // true ��ȯ
//////		else
//////			return false; // stack�� ���� �����ִٸ� false ��ȯ
//////	}
//////	void operator>> (int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//////	{
//////		n = p[--tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//////	}
//////};
//////int main()
//////{
//////	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//////	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//////						   // stack.operator<<(3).operator<<(5).operator<<(10);
//////	while (true) // ���� ���� �ݺ���
//////	{
//////		if (!stack) break; // ���� empty // stack.operator!()
//////		int x = 0; // �˵� ������ ������ ����
//////		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x)
//////		cout << x << ' ';
//////	}
//////	cout << endl;
//////}
////
////////11-2 // ������ �Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//////class Stack // Ŭ���� Stack
//////{
//////	int p[10]; // ũ�Ⱑ 10�� �迭 p
//////	int tos; // �ε����� �˷��ִ� �������
//////public: // ����
//////	Stack() // �⺻������
//////	{
//////		tos = 0; // 0���� �ʱ�ȭ
//////		for (int i = 0; i < 10; i++)
//////			p[i] = 0; // �迭�� ��� �ε����� 1�� �ʱ�ȭ
//////	}
//////	friend Stack& operator<< (Stack& op, int n); // <<������ ������ȭ
//////	friend bool operator! (Stack op); // !������ ������ȭ
//////	friend void operator>> (Stack& op, int& n); // >>������ ������ȭ
//////};
//////Stack& operator<< (Stack& op, int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//////{
//////	// op�� ����������� ����Ǿ���ϹǷ� �����Ű������� ����ؾ� ��
//////	op.p[op.tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//////	return op; // �ٲ� ��ü ����
//////}
//////bool operator! (Stack op) // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//////{
//////	// operator>>�Լ����� ����� tos�� �̿��� �Ǵ��ؾ� ��
//////	if (op.tos == 0) // ���� ����� ������ 
//////		return true; // true ��ȯ
//////	else
//////		return false; // stack�� ���� �����ִٸ� false ��ȯ
//////}
//////void operator>> (Stack& op, int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//////{
//////	n = op.p[--op.tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//////}
//////int main()
//////{
//////	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//////	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//////						   // stack.operator<<(3).operator<<(5).operator<<(10);
//////	while (true) // ���� ���� �ݺ���
//////	{
//////		if (!stack) break; // ���� empty // stack.operator!() // operator!(stack);
//////		int x = 0; // �˵� ������ ������ ����
//////		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x); // operator>>(stack,x);
//////		cout << x << ' ';
//////	}
//////	cout << endl;
//////}
////
////////12-1 // ����Լ� �̿� // ��������� - ���� ���� // ������ ���� // �����Ҵ� // �� ��������
//////class SortedArray
//////{
//////    int size; // ���� �迭�� ũ��
//////    int* p; // ���� �迭�� ���� ������
//////    void sort() // ���� �迭�� ������������ ����
//////    {
//////        for (int i = 0; i < size; i++)
//////        {
//////            for (int j = 0; j < size - 1; j++) 
//////            {
//////                if (p[j] > p[j + 1]) // p[j]�� p[j+1]���� Ŭ �� // ū ���� �ڷ� ������
//////                {
//////                    int n1 = p[j]; // ���� p[j]�� n1�� ����
//////                    p[j] = p[j + 1]; // p[j]�� p[j+1] ����
//////                    p[j + 1] = n1; // p[j+1]�� ���� p[j] ����
//////                }
//////            }
//////        }
//////    }
//////public:
//////    SortedArray() // p�� NULL�� size�� 0���� �ʱ�ȭ // �⺻������
//////    {
//////        p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//////        size = 0;
//////    }
//////    SortedArray(SortedArray& src) // ���� ������ // ��������
//////    {
//////        size = src.size; // �����ϰ��� �ϴ� ��ü�� size ����
//////        if (!size) // size�� 0�̶��
//////            p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//////        else
//////            p = new int[size]; // size���� ����޾Ҵٸ� �׸�ŭ ���ο� ���� �����Ҵ�
//////        for (int i = 0; i < size; i++)
//////            p[i] = src.p[i]; // �����ϰ����ϴ� ��ü�� �� ���� ���� this�� �����Ҵ� ������ ����
//////        sort(); // ���� �迭�� ������������ ����
//////    }
//////    SortedArray(int p[], int size) // �Ű������� �ִ� ������, ���� �迭�� ũ�⸦ ���޹���
//////    {
//////        this->size = size;
//////        this->p = new int[size]; 
//////        for (int i = 0; i < size; i++)
//////            this->p[i] = p[i];
//////        sort(); // ���� �迭�� ������������ ����
//////    }
//////    ~SortedArray() // �Ҹ���
//////    {
//////        if (p)
//////            delete[] p; // �����Ҵ�� ������ ����
//////        p = nullptr; // p�� �ƹ��͵� ����Ű�������� ����
//////    }
//////    SortedArray operator+(SortedArray& op2) // ���� �迭�� op2 �迭 �߰� //+������ ����
//////    {
//////        SortedArray c; // �� ��ü�� ���� ��� ���� ����� ��ü�� �ϳ� �� ����
//////        c.size = this->size + op2.size; // �� ��ü�� size�� ���� ���� c�� size�� ����
//////        c.p = new int[c.size](); // ����� size��ŭ ���ο� ������ �����Ҵ���
//////        for (int i = 0; i < this->size; i++) // c.size��ŭ �ݺ����� ������ �� ���� �޸� ħ�� �߻�
//////            c.p[i] = this->p[i]; // �ε��� 0~2���� ��ü a�� �迭 �� c�� �迭�� ����
//////        for (int i = 0; i < op2.size; i++)
//////            c.p[i + this->size] = op2.p[i]; // �ε��� 3~6���� ��ü b�� �迭 �� c�� �迭�� ����
//////        sort(); // ���� �迭�� ������������ ����
//////        return c; // ��ü a�� b�� ���� ���� ���� ��ü c�� ��ȯ // ���� ����
//////    }
//////    SortedArray& operator=(const SortedArray& op2) // ���� �迭�� op2 �迭 ���� // = ������ ����
//////    {
//////        // op2�� ���� =�����ڸ� ȣ���� ��ü�� ����
//////        this->size = op2.size;
//////        this->p = new int[this->size]; // �ּҸ� ���� X , �Ҹ� �� ���� ����ó�� �ۿ� (�� ��ü�� �ϳ��� �������� �����Ѽ�)
//////        for (int i = 0; i < this->size; i++)
//////            this->p[i] = op2.p[i];
//////        sort(); // ���� �迭�� ������������ ����
//////        return *this; // ������ȯ
//////    }
//////    void show() // �迭�� ���� ���
//////    {
//////        cout << "�迭 ��� :";
//////        for (int i = 0; i < size; i++)
//////            cout << p[i] << ' ';
//////        cout << endl;
//////    }
//////};
//////int main()
//////{
//////    int n[] = { 2,20,6 };
//////    int m[] = { 10,7,8,30 };
//////    SortedArray a(n, 3), b(m, 4), c; // ��ü�� ����
//////
//////    c = a + b; // +,= ������ �ۼ� �ʿ� // a.operator+(b); // c.operator=(a+b);
//////    // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
//////    // = ������ ������ ���� : �⺻������ �����Ϸ��� �����ϴ� =�����ڴ� ���� ���縸 ���� -> ���� ���縦 �� �� �ְ� ������ �������
//////    // (����Ʈ ���Կ����ڰ� Ŭ���� ���� �ֱ� ������ ��������ڸ� ���������ִ� �Ͱ� ���� ���Կ����ڸ� ���� �����ϱ� ���� �������Ϸ��� Ŭ�������� ����Լ��� ����������߸� �Ѵ�.)
//////    a.show(); b.show(); c.show();
//////}
////
////////12-2 // �������Լ� �̿� // ��������� - ���� ���� // ������ ���� // �����Ҵ� // �� ��������
//////class SortedArray
//////{
//////    int size; // ���� �迭�� ũ��
//////    int* p; // ���� �迭�� ���� ������
//////    void sort() // ���� �迭�� ������������ ����
//////    {
//////        for (int i = 0; i < size; i++)
//////        {
//////            for (int j = 0; j < size - 1; j++)
//////            {
//////                if (p[j] > p[j + 1]) // p[j]�� p[j+1]���� Ŭ �� // ū ���� �ڷ� ������
//////                {
//////                    int n1 = p[j]; // ���� p[j]�� n1�� ����
//////                    p[j] = p[j + 1]; // p[j]�� p[j+1] ����
//////                    p[j + 1] = n1; // p[j+1]�� ���� p[j] ����
//////                }
//////            }
//////        }
//////    }
//////public:
//////    SortedArray() // p�� NULL�� size�� 0���� �ʱ�ȭ // �⺻������
//////    {
//////        p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//////        size = 0;
//////    }
//////    SortedArray(SortedArray& src) // ���� ������ // ��������
//////    {
//////        size = src.size; // �����ϰ��� �ϴ� ��ü�� size ����
//////        if (!size) // size�� 0�̶��
//////            p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//////        else
//////            p = new int[size]; // size���� ����޾Ҵٸ� �׸�ŭ ���ο� ���� �����Ҵ�
//////        for (int i = 0; i < size; i++)
//////            p[i] = src.p[i]; // �����ϰ����ϴ� ��ü�� �� ���� ���� this�� �����Ҵ� ������ ����
//////        sort(); // ���� �迭�� ������������ ����
//////    }
//////    SortedArray(int p[], int size) // �Ű������� �ִ� ������, ���� �迭�� ũ�⸦ ���޹���
//////    {
//////        this->size = size;
//////        this->p = new int[size];
//////        for (int i = 0; i < size; i++)
//////            this->p[i] = p[i];
//////        sort(); // ���� �迭�� ������������ ����
//////    }
//////    ~SortedArray() // �Ҹ���
//////    {
//////        if (p)
//////            delete[] p; // �����Ҵ�� ������ ����
//////        p = nullptr; // p�� �ƹ��͵� ����Ű�������� ����
//////    }
//////    void show() // �迭�� ���� ���
//////    {
//////        cout << "�迭 ��� :";
//////        for (int i = 0; i < size; i++)
//////            cout << p[i] << ' ';
//////        cout << endl;
//////    }
//////    SortedArray& operator=(const SortedArray& op2) // ���� �迭�� op2 �迭 ���� // = ������ ����
//////    {
//////        // op2�� ���� =�����ڸ� ȣ���� ��ü�� ����
//////        this->size = op2.size;
//////        this->p = new int[this->size]; // �ּҸ� ���� X , �Ҹ� �� ���� ����ó�� �ۿ� (�� ��ü�� �ϳ��� �������� �����Ѽ�)
//////        for (int i = 0; i < this->size; i++)
//////            this->p[i] = op2.p[i];
//////        sort(); // ���� �迭�� ������������ ����
//////        return *this; // ������ȯ
//////    }
//////    friend SortedArray operator+(SortedArray& op1, SortedArray& op2);
//////};
//////SortedArray operator+(SortedArray& op1, SortedArray& op2) // ���� �迭�� op2 �迭 �߰� //+������ ����
//////{
//////    SortedArray c; // �� ��ü�� ���� ��� ���� ����� ��ü�� �ϳ� �� ����
//////    c.size = op1.size + op2.size; // �� ��ü�� size�� ���� ���� c�� size�� ����
//////    c.p = new int[c.size](); // ����� size��ŭ ���ο� ������ �����Ҵ���
//////    for (int i = 0; i < op1.size; i++) // c.size��ŭ �ݺ����� ������ �� ���� �޸� ħ�� �߻�
//////        c.p[i] = op1.p[i]; // �ε��� 0~2���� ��ü a�� �迭 �� c�� �迭�� ����
//////    for (int i = 0; i < op2.size; i++)
//////        c.p[i + op1.size] = op2.p[i]; // �ε��� 3~6���� ��ü b�� �迭 �� c�� �迭�� ����
//////    c.sort(); // ���� �迭�� ������������ ����
//////    return c; // ��ü a�� b�� ���� ���� ���� ��ü c�� ��ȯ // ���� ����
//////}
//////int main()
//////{
//////    int n[] = { 2,20,6 };
//////    int m[] = { 10,7,8,30 };
//////    SortedArray a(n, 3), b(m, 4), c; // ��ü�� ����
//////
//////    c = a + b; // +,= ������ �ۼ� �ʿ� 
//////               // a.operator+(b); // c.operator=(a+b);
//////               // operator+(a,b); // operator=(c,a+b); - ����Լ� �Ұ��� - 12-1 488,489�� �����
//////    // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
//////
//////    a.show(); b.show(); c.show();
//////}
//
////#include <iostream>
////using namespace std;
////
////////1 // Circle Ŭ������ ��ӹ��� NamedCircleŬ���� �����
//////class Circle // �� ����� Ŭ����
//////{
//////	int radius; // ������
//////public:
//////	Circle(int radius = 0) { this->radius = radius; } // ������ 
//////	int getRadius() { return radius; } // radius ���
//////	void setRadius(int radius) { this->radius = radius; } // radius �� ����
//////	double getArea() { return 3.14 * radius * radius; } // ����
//////};
//////class NamedCircle : public Circle // Circle�� �̸��� ���̴� Ŭ���� // ���Ŭ���� - Circle , �Ļ�Ŭ���� - NamedCircle
//////{
//////	string name; // ���� �̸�
//////public:
//////	NamedCircle(int radius, string name) : Circle(radius) // ���Ŭ���� �����ڸ� �Ļ�Ŭ������ �����ڿ��� ���� ȣ���ϰԲ� ��
//////	{
//////		this->name = name; // �Ű������� �Է¹��� radius�δ� Circle ������� �ʱ�ȭ
//////		// �Է¹��� ���ڿ��δ� NamedCircled�� ������� �ʱ�ȭ
//////		// ���Ŭ���� �����ں��� ȣ�� �� �Ļ�Ŭ���� ������ ȣ��
//////	}
//////	void show()
//////	{
//////		cout << "�������� " << getRadius() << "�� " << name << endl;
//////	}
//////};
//////int main()
//////{
//////	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
//////	waffle.show();
//////}
////
////////2 // 1���� ������ �迭�� ���� �����ϰ� ��
//////class Circle // �� ����� Ŭ����
//////{
//////	int radius; // ������
//////public:
//////	Circle(int radius = 0) { this->radius = radius; } // ������
//////	int getRadius() { return radius; } // radius ���
//////	void setRadius(int radius) { this->radius = radius; } // radius �� ����
//////	double getArea() { return 3.14 * radius * radius; } // ����
//////};
//////class NamedCircle : public Circle // Circle�� �̸��� ���̴� Ŭ���� // ���Ŭ���� - Circle , �Ļ�Ŭ���� - NamedCircle
//////{
//////	string name; // ���� �̸�
//////public:
//////	NamedCircle(int radius = 0, string name = " ") : Circle(radius) // ���Ŭ���� �����ڸ� �Ļ�Ŭ������ �����ڿ��� ���� ȣ���ϰԲ� ��
//////	{
//////		this->name = name; // �Ű������� �Է¹��� radius�δ� Circle ������� �ʱ�ȭ
//////		// �Է¹��� ���ڿ��δ� NamedCircled�� ������� �ʱ�ȭ
//////	}
//////	void setNamedCircle(int n, string name) { setRadius(n); this->name = name; } // radius�� private�̹Ƿ� ����Լ��� ����
//////	string getName() { return name; } // �� �̸��� ���
//////	void show() { cout << "�������� " << getRadius() << "�� " << name << endl; }
//////};
//////int main()
//////{
//////	NamedCircle pizza[5]; // ���� �̸��� ������ ���� ������ ���� ��ü�� 5���� �迭�� ����
//////	NamedCircle a; int n(0);  string name; // ���� ū ���� ������ ���� ��ü�� �� ���� �̸��� ���������̸� �Է¹��� ���� ����
//////	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cout << i + 1 << ">> ";
//////		cin >> n >> name; // �Է¹��� ���������̿� �� �̸��� ������ ����
//////		pizza[i].setNamedCircle(n, name); // �Է¹��� ������� ��ü�� ������ �����ϴ� �Լ��� �Ű������� ����
//////		if (a.getArea() < pizza[i].getArea()) // NamedCircleŬ������ ��ü�� CircleŬ�������� ��ӹ޾ұ� ������ public���� ������ getArea �Լ� ��� ����
//////			a = pizza[i]; // ��ü�� ������ ���� ������
//////	}
//////	cout << "���� ������ ū ���ڴ� " << a.getName() << "�Դϴ�."; // ���� ū ���� ������ ���� ��ü a�� �� �̸��� �Լ��� ���� ���
//////}
////
////////3 // �հ� ���� // ����� ���� // �Ļ������ // ������ �����ϰ� �Ұ����� ��� ã��
//////class Point // ���Ŭ����
//////{ 
//////	int x, y;
//////public:
//////	Point(int x, int y) { this->x = x; this->y = y; } // �Ű������� ���� ������
//////	int getX() { return x; } // x�� ��ġ ���
//////	int getY() { return y; } // y�� ��ġ ���
//////protected: // �ܺ����� �Ұ��� // �Ļ�Ŭ���������� ���ٰ���
//////	void move(int x, int y) { this->x = x; this->y = y; } 
//////	// x�� y�� ��ġ�� �����ϴ� ����Լ�
//////};
//////class ColorPoint : public Point // PointŬ������ ��ӹ��� �Ļ�Ŭ���� ColorPoint
//////{
//////	string color;
//////public:
//////	ColorPoint(int x, int y, string color) : Point(x, y) // ���Ŭ������ ������ ȣ����� �� // �� �� �Ļ�Ŭ������ ������ ȣ�� 
//////	{
//////		// �Է¹��� x,y�� ���Ŭ������ �����ڿ� ���޵ǰ�
//////		this->color = color; // �Է¹��� ���ڿ��� color�� �����
//////	}
//////	void setPoint(int x, int y) // ����Ʈ ��ġ�� �����ϴ� �Լ�
//////	{
//////		move(x, y); // ���Ŭ������ protected�� �����Ǿ��־ �Ļ�Ŭ�������� ������ �� ������ �ܺο��� ���� �Ұ���
//////	}
//////	void setColor(string color) // color�� �����ϴ� �Լ�
//////	{
//////		this->color = color;
//////	}
//////	void show() // Ŭ������ ���� ���� �� ��ġ�� ���
//////	{
//////		cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
//////	}
//////};
//////int main()
//////{
//////	ColorPoint cp(5, 5, "RED"); // ColorPointŬ���� ��ü cp ���� // ���޵� ���� �ΰ��� x,y�� ���ʴ�� ���� // ���ڿ��� color�� ����
//////	cp.setPoint(10, 20); // x,y�� �����ų �Լ� ȣ��
//////	cp.setColor("BLUE"); // ���� RED���� BLUE�� �����ϱ����� �Լ� ȣ��
//////	cp.show(); // ��ü�� ����� �������� ���
//////}
////
////////4
//////class Point // ���Ŭ����
//////{
//////	int x, y;
//////public:
//////	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }// �Ű������� ���� ������
//////	int getX() { return x; } // x�� ��ġ ���
//////	int getY() { return y; } // y�� ��ġ ���
//////protected: // �ܺ����� �Ұ��� // �Ļ�Ŭ���������� ���ٰ���
//////	void move(int x, int y) { this->x = x; this->y = y; }
//////	// x�� y�� ��ġ�� �����ϴ� ����Լ�
//////};
//////class ColorPoint : public Point // PointŬ������ ��ӹ��� �Ļ�Ŭ���� ColorPoint
//////{
//////	string color;
//////public:
//////	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) // ���Ŭ������ ������ ȣ����� �� // �� �� �Ļ�Ŭ������ ������ ȣ�� 
//////	{
//////		// ����Ʈ���� ����
//////		// �Է¹��� x,y�� ���Ŭ������ �����ڿ� ���޵ǰ�
//////		this->color = color; // �Է¹��� ���ڿ��� color�� �����
//////	}
//////	void setPoint(int x, int y) // ����Ʈ ��ġ�� �����ϴ� �Լ�
//////	{
//////		move(x, y); // ���Ŭ������ protected�� �����Ǿ��־ �Ļ�Ŭ�������� ������ �� ������ �ܺο��� ���� �Ұ���
//////	}
//////	void setColor(string color) // color�� �����ϴ� �Լ�
//////	{
//////		this->color = color;
//////	}
//////	void show() // Ŭ������ ���� ���� �� ��ġ�� ���
//////	{
//////		cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
//////	}
//////};
//////int main()
//////{
//////	ColorPoint zeroPoint; // BLACK ���� (0,0) ��ġ�� �� // �ƹ��͵� �Է¹��� �ʾ����� ����Ʈ���� Ȯ���ϱ� ���� ��ü
//////	zeroPoint.show(); // zeroPoint�� ����Ѵ�.
//////
//////	ColorPoint cp(5, 5); // x,y���� ������ color�� �� ���ڿ��� ���� ������ (5,5) ��ġ�� color�� ����Ʈ���� BLACK���� �ʱ�ȭ�� ��ü ����
//////	cp.setPoint(10, 20); // x,y�� �����ų �Լ� ȣ��
//////	cp.setColor("BLUE"); // ���� BLACK���� BLUE�� �����ϱ����� �Լ� ȣ��
//////	cp.show(); // ��ü�� ����� �������� ���
//////}
////
////////5 // ���Ŭ���� // Queue = first in first out // enqueue, dequeue 
//////class BaseArray
//////{
//////	int capacity; // �迭�� ũ��
//////	int* mem; // ���� �迭�� ����� ���� �޸��� ������
//////protected: // �Ļ�Ŭ���� ���� ���� // �ܺ�����X
//////	BaseArray(int capacity = 100) // ������
//////	{
//////		this->capacity = capacity;
//////		mem = new int[capacity]();
//////	}
//////	~BaseArray() { delete[] mem; } // �Ҹ��� // ��� ��ҵ��� ������ ������ ���������� ť�� ������ ����Ǿ��ִ� ������ ����
//////	void put(int index, int val) { mem[index] = val; } // �Ҵ���� �� �迭������ index�� val�� ����
//////	int get(int index) { return mem[index]; } // �Ҵ���� �� �迭������ index�� ���
//////	int getCapacity() { return capacity; } // �迭�� ũ�� ���
//////};
//////class MyQueue : public BaseArray // BaseArrayŬ������ ��ӹ��� �Ļ�Ŭ���� MyQueue
//////{
//////	int head; // ť�� �Ӹ�
//////	int tail; // ť�� ����
//////	int size; // ť�� �ִ� ���� ������ ���� ����
//////public:
//////	MyQueue(int capacity) : BaseArray(capacity) // �Ű������� �Է¹��� ���� ���Ŭ������ �����ڿ� ����
//////	{
//////		// MyQueue Ŭ������ ����� �ƹ� ���� �����ʰ� ��� 0���� �ʱ�ȭ�Ѵ�.
//////		head = 0; // ��� 0���� �ʱ�ȭ
//////		tail = 0;
//////		size = 0;
//////	}
//////	void enqueue(int n) // ť�� �Է��� ��
//////	{
//////		put(tail++, n); // ������ ��ġ�� �Է¹��� ������ �����ϴ� BaseArray���� ��ӹ��� �Լ� put ȣ��
//////		// �Լ������� ������ tail�� �� ����
//////		size++; // ���� ť�� ���� �󸶸�ŭ �Է¹޾ҳ��� ���
//////	}
//////	int capacity() // ť�� �� �뷮 ���
//////	{
//////		return getCapacity(); // BaseArrayŬ������ capacity�� ���� ������ �� ���� ������(private) ����Լ��� �̿��Ѵ�.
//////	}
//////	int length() // ���� ť�� ����ִ� ���� ���� ���
//////	{
//////		return size;
//////	}
//////	int dequeue() // ť�� ���
//////	{
//////		size--; // �ϳ��ϳ� ���� ��µɶ����� ť�� ����ִ� ���� ������ �پ��� ���� �ǹ�
//////		return get(head++); // ó���Է¹޾Ҵ� ������� ���� ���
//////	}
//////};
//////int main()
//////{
//////	MyQueue mQ(100); // ť�� �� �뷮�� 100���� ����
//////	int n; // ť�� �� ���� �Է¹��� ���� ����
//////	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cin >> n;
//////		mQ.enqueue(n); // ť�� ����
//////	}
//////	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//////	// ť�� �� �뷮�� ���� ������ �� ť�� ũ�� ���
//////	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
//////	while (mQ.length() != 0) // ���� ť�� ũ�Ⱑ 0�̶�� �ݺ��� ����
//////	{
//////		cout << mQ.dequeue() << " "; // ť���� �����Ͽ� ��� // ����Ҷ����� ť�� ũ�� �پ��
//////	}
//////	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
//////	// ��� ���� �������� 0�̵� ť�� ��Ȳ ���
//////}
////
////////6 // stack
//////class BaseArray
//////{
//////	int capacity; // �迭�� ũ��
//////	int* mem; // ���� �迭�� ����� ���� �޸��� ������
//////protected: // �Ļ�Ŭ���� ���� ���� // �ܺ�����X
//////	BaseArray(int capacity = 100) // ������
//////	{
//////		this->capacity = capacity;
//////		mem = new int[capacity]();
//////	}
//////	~BaseArray() { delete[] mem; } // �Ҹ��� // ��� ��ҵ��� ������ ������ ���������� ť�� ������ ����Ǿ��ִ� ������ ����
//////	void put(int index, int val) { mem[index] = val; } // �Ҵ���� �� �迭������ index�� val�� ����
//////	int get(int index) { return mem[index]; } // �Ҵ���� �� �迭������ index�� ���
//////	int getCapacity() { return capacity; } // �迭�� ũ�� ���
//////};
//////class MyStack : public BaseArray // BaseArrayŬ������ ��ӹ��� �Ļ�Ŭ���� MyStack
//////{
//////	int stack; // �Է¹ް� ����ؾ��ϴ� ���� ��ġ
//////	int size; // ���ÿ� �ִ� ���� ������ ���� ����
//////public:
//////	MyStack(int capacity) : BaseArray(capacity) // �Ű������� �Է¹��� ���� ���Ŭ������ �����ڷ� ���޵ȴ�.
//////	{
//////		// MyQueue Ŭ������ ����� �ƹ� ���� �����ʰ� ��� 0���� �ʱ�ȭ�Ѵ�.
//////		stack = 0; // ��� 0���� �ʱ�ȭ
//////		size = 0;
//////	}
//////	void push(int n) // ���ÿ� �Է��� ��
//////	{
//////		put(stack++, n); // �����Ҵ�� �������� �������� ���� ����
//////		// �Լ������� ������ stack�� �� ����
//////		size++; // ���� ���ÿ� ���� �󸶸�ŭ �ֳ��� ���
//////	}
//////	int capacity() // ������ �� �뷮 ���
//////	{
//////		return getCapacity(); // BaseArrayŬ������ capacity�� ���� ������ �� ���� ������ ����Լ��� �̿��Ѵ�.
//////	}
//////	int length() // ���� ���ÿ� ����ִ� ���� ���� ���
//////	{
//////		return size;
//////	}
//////	int pop() // �׿��ִ� ���� ����������(���� ���߿� �� ������) ���Ѵ�
//////	{
//////		size--; // �ϳ��ϳ� ���� ��µɶ����� ���ÿ� ����ִ� ���� ������ �پ��� ���� �ǹ�
//////		return get(--stack); // �ʰ� �� ������� ���� ��� 
//////	}
//////};
//////int main()
//////{
//////	MyStack mStack(100); // ������ �� �뷮 ����
//////	int n; // ���ÿ� �� ���� �Է¹��� ����
//////	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
//////	for (int i = 0; i < 5; i++)
//////	{
//////		cin >> n;
//////		mStack.push(n); // �Է¹��� ���� ����Լ��� �̿��� ���ÿ� �������� ����
//////	}
//////	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
//////	// ������ �� �뷮�� ���� ���ÿ� ���� �󸶸�ŭ �׿����� ���
//////	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
//////	while (mStack.length() != 0) // ������ ũ�Ⱑ 0�� �� ������ �ݺ��� ����
//////	{
//////		cout << mStack.pop() << ' '; // ���� ���߿� ������ ���ʴ�� ���� ������. // ���� ó���� �� ���� ���� ���߿� ������ �ȴ�. // �Է��� �������� ���
//////	}
//////	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
//////	// ���� ��� �������� ������ ũ�� ���
//////}
////
////////8 // �׸��� ������ ��Ȯ�� �����ϵ��� ������ // ����� ���� ���� ����
//////class Print
//////{
//////	string model; // �𵨸�
//////	string manufacturer; // ������
//////	int printedCount; // �μ� �ż�
//////	int availablecount; // �μ� ���� �ܷ�
//////protected:
//////	Print(string model = NULL, string manufacturer = NULL, int printedCount = 0, int availablecount = 0)
//////	{
//////		// �𵨸�� ������, �μ������ܷ��� ���޹޾� �ʱ�ȭ�ϴ� ������
//////		this->model = model;
//////		this->manufacturer = manufacturer;
//////		this->printedCount = printedCount;
//////		this->availablecount = availablecount;
//////	}
//////	bool print(int pages) // ����Ʈ�� �ż��� �Է¹�����
//////	{
//////		printedCount = pages; // �μ�ż��� ���ϴ� printedCount�� �����ϰ�,
//////		if (availablecount < printedCount) // ���� ���� �ܷ��� �μ��� �ż����� ������ �켱������ Ȯ���Ѵ�.
//////		{
//////			return false; // �۴ٸ� �μ� ����
//////		}
//////		else // �����ʴٸ�
//////		{
//////			availablecount -= printedCount; // ���� ���� �ܷ����� �μ��� �ż��� ���� �� ����Ʈ������ ǥ����
//////			return true; // ����Ʈ�� ���������� �˸�
//////		}
//////	}
//////	// ��� ���
//////	void get() { cout << model << " ," << manufacturer << " ,���� ���� " << availablecount << "�� ,"; }
//////};
//////class InkJetPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� InkJetPrint
//////{
//////	int availableInk; // ��ũ �ܷ�
//////public:
//////	InkJetPrint(string model = "Officejet V40", string manufacturer = "HP", int printedCount = 0, int availablecount = 5, int availableInk = 10) : Print(model, manufacturer, printedCount, availablecount) 
//////	{
//////		// ��ũ���������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//////		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//////		// �ٸ� �������� ��� �Էµ� �Ŀ� ��ũ �ܷ��� �ʱ�ȭ��
//////		this->availableInk = availableInk;
//////	}
//////	bool printInkJet(int pages) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//////	{
//////		if (print(pages)) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//////		{
//////			availableInk -= pages; // pages��ŭ�� ����Ʈ�� �ϱ����� pages��ŭ�� ��ũ�� ��������� �ǹ�
//////			return true; // ����Ʈ ����
//////		}
//////		else // ����Ʈ�� �Ұ����� ��Ȳ�̶��
//////		{
//////			return false; // ����Ʈ ����
//////		}
//////	}
//////	void getInkJetPrint() { get(); cout << "���� ��ũ " << availableInk << endl; } // ��ũ�� ����Ʈ�� ���� ���
//////};
//////class LaserPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� LaserPrint
//////{
//////	int availableToner; // ��� �ܷ�
//////public:
//////	LaserPrint(string model = "SCX-6x45", string manufacturer = "�Ｚ����", int printedCount = 0, int availablecount = 3, int availableToner = 20) : Print(model, manufacturer, printedCount, availablecount) 
//////	{
//////		// ������ �������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//////		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//////		// �ٸ� �������� ��� �Էµ� �Ŀ� ��� �ܷ��� �ʱ�ȭ��
//////		this->availableToner = availableToner;
//////	}
//////	bool printLaser(int pages) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//////	{
//////		if (print(pages)) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//////		{
//////			int Toner = pages / 2;
//////			availableToner -= Toner; // pages��ŭ�� ����Ʈ�� �ϱ����� pages��ŭ�� ��ʸ� ��������� �ǹ�
//////			return true; // ����Ʈ ����
//////		}
//////		else // ����Ʈ�� �Ұ����� ��Ȳ�̶��
//////		{
//////			return false; // ����Ʈ ����
//////		}
//////	}
//////	void getLaserPrint() { get(); cout << "���� ��� " << availableToner << endl; }// ������ �������� ���� ���
//////};
//////int main()
//////{
//////	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
//////	InkJetPrint* p1 = new InkJetPrint; // Print�� �Ļ�Ŭ���� InkJetPrint�� ��ü������ p1 ���� ����
//////	LaserPrint* p2 = new LaserPrint; // Print�� �Ļ�Ŭ���� LaserPrint�� ��ü������ p2 ���� ����
//////	cout << "��ũ�� : "; p1->getInkJetPrint(); // ��ũ�� �������� �������
//////	cout << "������ : "; p2->getLaserPrint(); // ������ �������� �������
//////	string s = "y"; // ��� ����Ʈ�� ������ �Ǵ��ϴ� �κп��� �ʿ��� ����
//////	int p, pages; // � �����͸� ����� ������, ��ŭ�� ����Ʈ�� �� ������ �Է¹��� ����
//////	while (s != "n") // s�� "n"�̶�� �ݺ��� ����
//////	{
//////		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
//////		cin >> p >> pages; // ����� �������� ��ȣ�� �ż��� �Է¹���
//////		if (p == 1) // ����� �����Ͱ� ��ũ�� �����Ͷ��
//////		{
//////			if (p1->printInkJet(pages)) // printInkJet�Լ��� �̿��� ���� �ܷ��� �ż����� ������ // ����Ʈ�� �������� �Ǵ�
//////			{
//////				cout << "����Ʈ�Ͽ����ϴ�." << endl; // �����ϸ� 
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� �� ���� �����͵��� ���� ���
//////			}
//////			else // �Ұ����ϸ� // ����Ʈ�Ϸ��� �ż����� ���� �ܷ��� ���ٸ� 
//////			{
//////				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; // �� �� ������ �˸�
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� ������ �����͵��� ���� ���
//////			}
//////		}
//////		else // ����� �����Ͱ� ������ �����Ͷ��
//////		{
//////			if (p2->printLaser(pages)) // printLaser�Լ��� �̿��� ���� �ܷ��� �ż����� ������ // ����Ʈ�� �������� �Ǵ�
//////			{
//////				cout << "����Ʈ�Ͽ����ϴ�." << endl; // �����ϸ�
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� �� ���� �����͵��� ���� ���
//////			}
//////			else // �Ұ����ϸ� // ����Ʈ�Ϸ��� �ż����� ���� �ܷ��� ���ٸ� 
//////			{
//////				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; // �� �� ������ �˸�
//////				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� ������ �����͵��� ���� ���
//////			}
//////		}
//////		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>"; // ��� �� ���̶��
//////		cin >> s; // s�� "y"���� - �ݺ��� �ݺ� // ��� ���ҰŸ� s�� "n"���� - �ݺ��� �ߴ� 
//////	}
//////	if (p1) // ��ü������ p1�� �Ҵ���� ������ �ִٸ�
//////	{
//////		delete p1; // p1�� ����Ű�� ������ ������
//////		p1 = nullptr; // p1�� �ƹ����� ����Ű�� ������ �ǹ�
//////	}
//////	if (p2) // ��ü������ p2�� �Ҵ���� ������ �ִٸ�
//////	{
//////		delete p2; // p2�� ����Ű�� ������ ������
//////		p2 = nullptr; // p2�� �ƹ����� ����Ű�� ������ �ǹ�
//////	}
//////}

#include <iostream>
void h(int* a) { *a = -*a; }
int ar[] = { 0,1,3,5,7 };
int& f(int n)
{
	return ar[n];
}
class Sample
{
public:
	static int a;
	int b;
	void f();
	static void h();
};
int Sample::a;
int main()
{
	Sample sample;
	sample.b = 5;
	sample.a = 5;
	Sample::f();
	Sample::h();
	//int n = 5;
	//h(&n);
	//std::cout << n;
	//f(0) = 100;
	//f(0) = f(1) + f(2) + f(3) + f(4);
	//int& v = f(2); v++;
	//for (int i = 0; i < 5; i++)
	//	std::cout << ar[i];
}