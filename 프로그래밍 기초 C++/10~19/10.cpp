#include <iostream>
#include <string>
using namespace std;
// ������ �ߺ� - Ŭ�������� �����ڸ� ����� �� �ֵ��� ����
// ����Լ�(��ü ����) or friend �Լ�(�Ϲ��Լ� ����)
// ��� ���� ����Լ��� friend �Լ��� ����

////1-1 // ����Լ� �̿�
//class Book
//{
//	string title; // å �̸��� ���� string ����
//	int price; // å ������ ���� ����
//	int pages; // å ������ ���� ���� ����
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ�Ű������� �̿��� �ۼ��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // å�� ������ ����ϴ� ����Լ�
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // å�� ������ ����� ����Լ�
//	Book operator+=(int money) // += �����ڸ� ������ ����Լ�
//	{
//		price += money; // �Է¹��� money�� ���� price�� ���� ���� price�� �ٽ� ����
//		return *this; // ����� ��ü(a)�� ��ȯ // �������
//	}
//	Book operator-=(int money) // -= �����ڸ� ������ ����Լ�
//	{
//		price -= money; // �Է¹��� money�� ���� price���� �� ���� price�� �ٽ� ����
//		return *this; // ����� ��ü(b)�� ��ȯ // �������
//	}
//};
//int main()
//{
//	Book a("û��", 20000, 300), b("�̷�", 30000, 500); // ��ü a�� b�� ��ü ���� �Է�
//	a += 500; // a.operator+=(500); // operator+=(a,500);
//	b -= 500; // b.operator-=(500); // operator-=(b,500);
//	a.show(); // ��ü a�� ���� ���
//	b.show(); // ��ü b�� ���� ���
//}

////1-2 // �������Լ� �̿�
//class Book
//{
//	string title; // å �̸��� ���� string ����
//	int price; // å ������ ���� ����
//	int pages; // å ������ ���� ���� ����
//public: 
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ�Ű������� �̿��� �ۼ��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // å�� ������ ����ϴ� ����Լ�
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // å�� ������ ����� ����Լ�
//	friend Book operator+=(Book& op1, int money); // �Ϲ��Լ� operator+=�� ������ȭ��
//	friend Book operator-=(Book& op1, int money); // �Ϲ��Լ� operator-=�� ������ȭ��
//};
//Book operator+=(Book& op1, int money) // ����Լ��� ���� �޸� �Լ��� ȣ���ϴ� ��ü�� ������ �ٲ��� ����
//{
//	// ���� �Ű������� �̿��� �Լ��� ȣ���ϴ� ��ü�� ������ �ٲ���
//	op1.price += money; // �Է¹��� money�� op1�� price�� ���� ���� op1�� price�� �ٽ� ���� 
//	return op1; // op1 ��ȯ
//}
//Book operator-=(Book& op1, int money) // ����Լ��� ���� �޸� �Լ��� ȣ���ϴ� ��ü�� ������ �ٲ��� ����
//{
//	// ���� �Ű������� �̿��� �Լ��� ȣ���ϴ� ��ü�� ������ �ٲ���
//	op1.price -= money; // �Է¹��� money�� op1�� price���� �� ���� op1�� price�� �ٽ� ���� 
//	return op1; // op1 ��ȯ
//}
//int main()
//{
//	Book a("û��", 20000, 300), b("�̷�", 30000, 500); // ��ü a�� b�� ��ü ���� �Է�
//	a += 500; // a.operator+=(500); // operator+=(a,500);
//	b -= 500; // b.operator-=(500); // operator-=(b,500);
//	a.show(); // ��ü a�� ���� ���
//	b.show(); // ��ü b�� ���� ���
//}

////2-1 // ����Լ� �̿�
//class Book
//{
//	string title; // å�� �̸�
//	int price; // å ����
//	int pages; // å�� ����
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ�Ű������� �̿��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // å�� ���� ���
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // å ���� ���
//	bool operator==(int price) // ==������ ���� - ����
//	{
//		if(this->price == price) // �Է¹��� price�� �Լ��� ȣ���� ��ü�� price�� ���ٸ�
//			return true; // true ��ȯ
//		else // ���� �ʴٸ�
//			return false; // false ��ȯ 
//	}
//	bool operator==(string title) // ==������ ���� - ����
//	{
//		if (this->title == title) // �Է¹��� title�� �Լ��� ȣ���� ��ü�� title�� ���ٸ�
//			return true; // true ��ȯ
//		else // ���� �ʴٸ�
//			return false; // false ��ȯ
//	}
//	bool operator==(Book op2) // ==������ ���� - ��ü
//	{
//		if (this->title == op2.title && price == op2.price && pages == op2.pages)
//			// �� ��ü�� ��� ������ �����ϴٸ� 
//			return true; // true ��ȯ
//		else // �ƴϸ� 
//			return false; // false ��ȯ
//	}
//};
//int main()
//{
//	Book a("��ǰ C++", 30000, 500), b("��� C++", 30000, 500); // ��ü�� ���� �Է�
//	if (a == 30000)cout << "���� 30000��" << endl; // a�� price�� 30000�̶�� true
//	// a.operator==(30000); // operator==(a,30000);
//	if (a == "��ǰ C++")cout << "��ǰ C++ �Դϴ�" << endl; // a�� title�� ��ǰC++�̶�� true
//	// a.operator==("��ǰ C++"); // operator==(a,"��ǰ C++");
//	if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl; // a�� b�� ��� ��Ұ� ���ٸ� true
//	// a.operator==(b); // operator==(a,b);
//}

////2-2 // ������ �Լ� �̿�
//class Book
//{
//	string title; // å ����
//	int price; // å ����
//	int pages; // å ������ ��
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{ 
//		// ����Ʈ �Ű������� �̿��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // ��ü�� ���� ��� ���
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // ���� ���
//	friend bool operator==(Book op1, int op2); // ���ݿ� ���� ������ == ������ȭ
//	friend bool operator==(Book op1, string op2); // ���� ���� ������ == ������ȭ
//	friend bool operator==(Book op1, Book op2); // ��ü�� ���� ������ == ������ȭ
//};
//bool operator==(Book op1, int op2) // ���� �� �ʿ� X
//{
//	if (op1.price == op2) // ��ü op1�� price�� op2�� ���ٸ�
//		return true; // true ��ȯ
//	else // ���� �ʴٸ�
//		return false; // false ��ȯ
//}
//bool operator==(Book op1, string op2) // ���� �� �ʿ� X
//{
//	if (op1.title == op2) // ��ü op1�� title�� op2�� ���ٸ�
//		return true;
//	else
//		return false;
//}
//bool operator==(Book op1, Book op2) // ���� �� �ʿ� X
//{
//	if (op1.title == op2.title && op1.price == op2.price && op1.pages == op2.pages)
//		return true; // true ��ȯ
//	else // ���� �ʴٸ�
//		return false; // false ��ȯ
//}
//int main()
//{
//	Book a("��ǰ C++", 30000, 500), b("��� C++", 30000, 500); // ��ü ���� �Է�
//	if (a == 30000)cout << "���� 30000��" << endl; // a�� price�� 30000�̶�� true
//	// a.operator==(30000); // operator==(a,30000);
//	if (a == "��ǰ C++")cout << "��ǰ C++ �Դϴ�" << endl; // a�� title�� ��ǰC++�̶�� true
//	// a.operator==("��ǰ C++"); // operator==(a,"��ǰ C++");
//	if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl; // a�� b�� ��� ��Ұ� ���ٸ� true
//	// a.operator==(b); // operator==(a,b);
//}

////3-1 // ����Լ� �̿�
//class Book
//{
//	string title; // å�� �̸�
//	int price; // å ����
//	int pages; // å�� ����
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ�Ű������� �̿��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // å�� ���� ���
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // å ���� ���
//	bool operator!() // ! ������ ����
//	{
//		if(!price) // ��ü�� price�� 0�̶�� ! �����ڸ� ���� 0�� �ƴ� ���� �ȴ�
//			return true; // true ��ȯ
//		else // 0�� �ƴ� �ٸ� ���̶�� ! �����ڸ� ���� 0�� �ȴ�
//			return false; // false ��ȯ 
//	}
//};
//int main()
//{
//	Book book("�������", 0, 50); // ��ü ���� �Է� // ���� : 0
//	if (!book) cout << "��¥��" << endl; // book�� ������ 0���̶�� '��¥��' ���
//    // book.operator!();
//}

////3-2 // ������ �Լ� �̿�
//class Book
//{
//	string title; // å ����
//	int price; // å ����
//	int pages; // å ������ ��
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ �Ű������� �̿��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // ��ü�� ���� ��� ���
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // ���� ���
//	friend bool operator!(Book op1); // ������ ! �� ������ �Ϲ��Լ� ������ȭ
//};
//bool operator!(Book op1) // ! ������ ���� // ���� ������ // ���� �ʿ����
//{
//	if (!op1.price) // ��ü�� price�� 0�̶�� ! �����ڸ� ���� 0�� �ƴ� ���� �ȴ�
//		return true; // true ��ȯ
//	else // 0�� �ƴ� �ٸ� ���̶�� ! �����ڸ� ���� 0�� �ȴ�
//		return false; // false ��ȯ 
//}
//int main()
//{
//	Book book("�������", 0, 50); // ��ü ���� �Է� // ���� : 0
//	if (!book) cout << "��¥��" << endl; // book�� ������ 0���̶�� '��¥��' ���
//    // operator!(book); 
//}

////4 // friend �Լ� �̿� // < ������ // title ��
//class Book
//{
//	string title; // å �̸��� ���� string ����
//	int price; // å ������ ���� ����
//	int pages; // å ������ ���� ���� ����
//public:
//	Book(string title = " ", int price = 0, int pages = 0)
//	{
//		// ����Ʈ�Ű������� �̿��� �ۼ��� ������
//		this->title = title; this->price = price; this->pages = pages;
//	}
//	void show() // å�� ������ ����ϴ� ����Լ�
//	{
//		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
//	}
//	string getTitle() { return title; } // å�� ������ ����� ����Լ�
//	friend bool operator<(string op1, Book op2); // < �����ڸ� ������ �Ϲ��Լ��� ������ȭ ��
//};
//bool operator<(string op1, Book op2) // < �����ڸ� ������ �Ϲ��Լ�
//{
//	if (op1 < op2.title) // op2�� title�� �Է¹��� ���ڿ����� ���������� �ڿ� �ִٸ�
//		return true; // true ��ȯ
//	else // �Է¹��� ���ڿ��� �� �ڿ� �ִٸ�
//		return false; // false ��ȯ
//}
//int main()
//{
//	Book a("û��", 20000, 300); // ��ü a ���� �Է�
//	string b;
//	cout << "å �̸��� �Է��ϼ���>>";
//	getline(cin, b); // å �̸��� �Է¹���
//	if (b < a) // operator<(b,a); 
//    // b.operator<(a); //b�� ��ü�� ������ Ŭ������ string�� Book���� �ٸ��� // ����Լ��� ���� �Ұ���
//	// �Է¹��� å �̸��� ��ü a�� ���� �� � ���ڿ��� ���������� �ڿ� �ֳ� �Ǵ�
//	// ��ü�� ������ �Է¹��� ���ڿ����� �� �ڿ� �ִٸ� true ��ȯ
//		cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!" << endl;
//}

////5-1 // ����Լ��̿� // 4�� �ǽ����� 1 // + ������ // == ������ // ��� // friend
//class Color // Ŭ���� Color ����
//{
//	int red; // ������� red ����
//	int green; // ������� green ����
//	int blue; // ������� blue ����
//public: // ����
//	Color() // �⺻������
//	{
//		red = 0; green = 0; blue = 0;
//	}
//	Color(int r, int g, int b) // �Ű������� �ִ� ������
//	{
//		red = r; green = g; blue = b; // �Ű������� ������� �ʱ�ȭ
//	}
//	void setColor(int r, int g, int b) // �Ű�������
//	{
//		red = r; green = g; blue = b; // ������� ����
//	}
//	void show() // ���� ������� ���
//	{
//		cout << red << ' ' << green << ' ' << blue << endl;
//	}
//	Color operator+(Color op1) // + ������ ���� // �������(�Ű�����)
//	{
//		Color tmp; // ���� ���� ������ ��ü ���� 
//		tmp.red = red + op1.red; // �Լ��� ȣ���� ��ü(red)�� red�� op1(blue)�� red�� ���� tmp�� red�� ����
//		tmp.green = green + op1.green; // �Լ��� ȣ���� ��ü�� green�� op1�� green�� ���� tmp�� green�� ����
//		tmp.blue = blue + op1.blue; // �Լ��� ȣ���� ��ü�� blue�� op1�� blue�� ���� tmp�� blue�� ����
//		return tmp; // ��ü tmp ��ȯ
//	}
//	bool operator==(Color op1) // == ������ ����
//	{
//		if (red == op1.red && green == op1.green && blue == op1.blue)
//			// �Լ��� ȣ���� ��ü�� op1�� ��� ������ ���ٸ�
//			return true; // true ��ȯ
//		else // ���� ������ �ϳ��� �ִٸ�
//			return false; // flase ��ȯ
//	}
//};
//int main()
//{
//	Color red(255, 0, 0), blue(0, 0, 255), c;
//	c = red + blue; // red.operator+(blue); // operator+(red,blue); // �������
//	c.show(); // red�� ���������� blue�� ����������� ���� ���� c�� ���� �� c�� ���� ���
//
//	Color fuchsia(255, 0, 255); // Ǫũ�þ� ���� �� ������ ���� ��ü fuchsia����
//	if (c == fuchsia) // ����� ������ ���� ��ü c�� ���������� fuchsia ��ü�� ����������� ��� ���ٸ�
//		// c.operator==(fuchsia); // operator==(c,fuchsia);
//      cout << "����� ����"; // true ��ȯ // fuchsia�� �������
//	else // �ϳ��� ���� �ʴٸ�
//		cout << "����� �ƴ�"; // flase ��ȯ // fuchsia�� ��������� �ƴ�
//}

////5-2 // ������ �Լ� �̿�
//class Color // Ŭ���� Color ����
//{
//	int red; // ������� red ����
//	int green; // ������� green ����
//	int blue; // ������� blue ����
//public: // ����
//	Color() // �⺻������
//	{
//		red = 0; green = 0; blue = 0;
//	}
//	Color(int r, int g, int b) // �Ű������� �ִ� ������
//	{
//		red = r; green = g; blue = b; // �Ű������� ������� �ʱ�ȭ
//	}
//	void setColor(int r, int g, int b) // �Ű�������
//	{
//		red = r; green = g; blue = b; // ������� ����
//	}
//	void show() // ���� ������� ���
//	{
//		cout << red << ' ' << green << ' ' << blue << endl;
//	}
//	friend Color operator+(Color op1, Color op2);
//	friend bool operator==(Color op1, Color op2);
//};
//Color operator+(Color op1, Color op2) // + ������ ����
//{
//	Color tmp; // ���� ���� ������ ��ü ���� 
//	tmp.red = op2.red + op1.red; // �Լ��� ȣ���� ��ü�� red�� op1�� red�� ���� tmp�� red�� ����
//	tmp.green = op2.green + op1.green; // �Լ��� ȣ���� ��ü�� green�� op1�� green�� ���� tmp�� green�� ����
//	tmp.blue = op2.blue + op1.blue; // �Լ��� ȣ���� ��ü�� blue�� op1�� blue�� ���� tmp�� blue�� ����
//	return tmp; // ��ü tmp ��ȯ
//}
//bool operator==(Color op1, Color op2) // == ������ ����
//{
//	if (op2.red == op1.red && op2.green == op1.green && op2.blue == op1.blue)
//		// �Լ��� ȣ���� ��ü�� op1�� ��� ������ ���ٸ�
//		return true; // true ��ȯ
//	else // ���� ������ �ϳ��� �ִٸ�
//		return false; // flase ��ȯ
//}
//int main()
//{
//	Color red(255, 0, 0), blue(0, 0, 255), c;
//	c = red + blue; // red.operator+(blue); // operator+(red,blue);
//	c.show(); // red�� ���������� blue�� ����������� ���� ���� c�� ���� �� c�� ���� ���
//
//	Color fuchsia(255, 0, 255); // Ǫũ�þ� ���� �� ������ ���� ��ü fuchsia����
//	if (c == fuchsia) // ����� ������ ���� ��ü c�� ���������� fuchsia ��ü�� ����������� ��� ���ٸ�
//		// c.operator==(fuchsia); // operator==(c,fuchsia);
//		cout << "����� ����"; // true ��ȯ // fuchsia�� �������
//	else // �ϳ��� ���� �ʴٸ�
//		cout << "����� �ƴ�"; // flase ��ȯ // fuchsia�� ��������� �ƴ�
//}

////6-1 // ����Լ� �̿�
//class Matrix // 2���� ����� �߻�ȭ�� Matrix Ŭ����
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// ������ �Ű������� �̿��� ������
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2���� ��� ���
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	Matrix operator+(Matrix op2) // + ������ ����
//	{
//		Matrix tmp; // ���� ���� ������ ���ο� ��ü ����
//		for (int i = 0; i < 4; i++)
//		{
//			tmp.n[i] = n[i] + op2.n[i]; // �Լ��� ȣ���� ��ü�� �迭�� op2�� �迭�� ���� ���� tmp �迭�� ����
//		}
//		return tmp; // tmp ��ȯ
//	}
//	Matrix operator+=(Matrix op2) // += ������ ����
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			n[i] += op2.n[i]; // �Լ��� ȣ���� ��ü�� �迭 ���ҿ� op2�� �迭 ���Ҹ� ���Ѱ��� �ٽ� �Լ��� ȣ���� ��ü�� �迭�� ����
//		}
//		return *this; // �Լ��� ȣ���� ��ü ��ȯ
//	}
//	bool operator==(Matrix op2) // == ������ ����
//	{
//		bool same = true; // �� ��ü�� �迭 �� �ٸ� ���Ұ� �ִٸ� �� ��ü�� �迭�� ���� �����Ƿ�
//		// �̸� �Ǵ��ϱ� ���� ����
//		for (int i = 0; i < 4; i++)
//		{
//			if (n[i] != op2.n[i]) // �� ��ü�� �迭 �� i��° ���Ұ� ���� �ʴٸ�
//			{
//				same = false; // same ������ false�� �����ϰ�
//				break; // �ݺ����� ��������
//			}
//		}
//		return same; // same ��ȯ
//	}
//};
//int main()
//{
//	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
//	c = a + b; // c = a.operator+(b); // operator+(a,b);
//	a += b; // a.operator+=(b);  // operator+=(a,b);
//	a.show(); b.show(); c.show(); 
//	if (a == c) // a.operator==(c); // operator==(a,c);
//		cout << "a and c are the same" << endl;
//}

////6-2 // ������ �Լ� �̿�
//class Matrix // 2���� ����� �߻�ȭ�� Matrix Ŭ����
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// ������ �Ű������� �̿��� ������
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2���� ��� ���
//	{ 
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	friend Matrix operator+(Matrix op1, Matrix op2); // + �����ڸ� ������ �Ϲ��Լ� ������ȭ
//	friend Matrix operator+=(Matrix& op1, Matrix op2); // +=�����ڸ� ������ �Ϲ��Լ� ������ȭ
//	friend bool operator==(Matrix op1, Matrix op2); // == �����ڸ� ������ �Ϲ��Լ� ������ȭ
//};
//Matrix operator+(Matrix op1, Matrix op2) // + ������ ����
//{
//	Matrix tmp; // �� ��ü�� ���� ���� ������ ���ο� ��ü ����
//	for (int i = 0; i < 4; i++)
//	{
//		tmp.n[i] = op1.n[i] + op2.n[i];
//		// op1�� �迭 ���ҿ� op2�� �迭 ���Ҹ� ���� ���� tmp�� �迭�� ����
//	}
//	return tmp; // tmp ��ȯ
//}
//Matrix operator+=(Matrix& op1, Matrix op2) // ��ü a�� ���� ����Ǿ���ϹǷ� �����Ű����� op1���
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op1.n[i] += op2.n[i]; // �� ��ü�� �迭 ���Ҹ� ���� ���� op1�� �迭�� ����
//	}
//	return op1; // op1 ��ȯ
//}
//bool operator==(Matrix op1, Matrix op2) // == ������ ����
//{
//	bool same = true; // �� ��ü�� �迭 �� �ٸ� ���Ұ� �ִٸ� �� ��ü�� �迭�� ���� �����Ƿ�
//	// �̸� �Ǵ��ϱ� ���� ����
//	for (int i = 0; i < 4; i++)
//	{
//		if (op1.n[i] != op2.n[i]) // �� ��ü�� �迭 �� �ٸ� �κ��� �ִٸ�
//		{
//			same = false; // same�� false�� ����
//			break; // �ݺ����� ��������
//		}
//	}
//	return same; // same ��ȯ
//}
//int main()
//{
//	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
//	c = a + b; // c = a.operator+(b); // operator+(a,b);
//	a += b; // a.operator+=(b);  // operator+=(a,b);
//	a.show(); b.show(); c.show(); 
//	if (a == c) // a.operator==(c); // operator==(a,c);
//		cout << "a and c are the same" << endl;
//}

////7-1 // ����Լ� �̿� // 6�� ���� // >> , << ������
//class Matrix // 2���� ����� �߻�ȭ�� Matrix Ŭ����
//{
//	int n[4]; 
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// ������ �Ű������� �̿��� ������
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2���� ��� ���
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	void operator>>(int op1[]) // >> ������ ����
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			op1[i] = n[i]; // op1 �迭�� �Լ��� ȣ���� ��ü�� n�迭 i��° ���� ����
//		}
//	}
//	void operator<<(int op1[]) // << ������ ����
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			n[i] = op1[i]; // �Լ��� ȣ���� ��ü�� n�迭 i��° ���ҿ� op1 �迭 ����
//		}
//	}
//};
//int main()
//{
//	Matrix a(4, 3, 2, 1), b; // ��ü ����
//	int x[4], y[4] = { 1,2,3,4 }; // 2���� ����� 4���� ���� ��
//	a >> x; // a�� �� ���Ҹ� �迭 x�� ����, x[]�� {4,3,2,1}
//	// a.operator>>(x); // operator>>(a,x);
//	b << y; // �迭 y�� ���Ұ��� b�� �� ���ҿ� ����
//	// b.operator<<(y); // operator<<(b,y);
//
//	for (int i = 0; i < 4; i++)
//		cout << x[i] << ' '; // x[] ���
//	cout << endl;
//	b.show(); // b ��ü�� ���� ���
//}

////7-2 // �������Լ� �̿�
//class Matrix
//{
//	int n[4];
//public:
//	Matrix(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
//	{
//		// ������ �Ű������� �̿��� ������
//		n[0] = n1; n[1] = n2; n[2] = n3; n[3] = n4;
//	}
//	void show() // 2���� ��� ���
//	{
//		cout << "Matrix = { ";
//		for (int i = 0; i < 4; i++)
//			cout << n[i] << " ";
//		cout << "}" << endl;
//	}
//	friend void operator>>(Matrix op1, int op2[]);
//	friend void operator<<(Matrix& op1, int op2[]);
//};
//void operator>>(Matrix op1, int op2[]) // >> ������ ����
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op2[i] = op1.n[i]; // op1 �迭�� �Լ��� ȣ���� ��ü�� n�迭 i��° ���� ����
//	}
//}
//void operator<<(Matrix& op1, int op2[]) // << ������ ���� // ���� �ʿ� // ���� X��, ��������� ��ü�� ���� �ٲٴ°��̶� ���ι��� ��ü�� �ٲ��� ����
//{
//	for (int i = 0; i < 4; i++)
//	{
//		op1.n[i] = op2[i]; // �Լ��� ȣ���� ��ü�� n�迭 i��° ���ҿ� op1 �迭 ����
//	}
//}
//int main()
//{
//	Matrix a(4, 3, 2, 1), b; // ��ü ����
//	int x[4], y[4] = { 1,2,3,4 }; // 2���� ����� 4���� ���� ��
//	a >> x; // a�� �� ���Ҹ� �迭 x�� ����, x[]�� {4,3,2,1}
//	// a.operator>>(x); // operator>>(a,x);
//	b << y; // �迭 y�� ���Ұ��� b�� �� ���ҿ� ����
//	// b.operator<<(y); // operator<<(b,y);
//
//	for (int i = 0; i < 4; i++)
//		cout << x[i] << ' '; // x[] ���
//	cout << endl;
//	b.show(); // b ��ü�� ���� ���
//}