#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
// �������� ������ȯ ���������
// �������� - ��ȯ�Ǵ� ������ ������ �ǹ���
// ��������� - ���� ����
//            - ���� ���� : �����Ҵ� �� ��� // string ���� �ϸ� �������翩�� ��� X
//           : ��ü�� �Ű������� �Ѱ��ٶ�, ��ü�� ��ȯ�Ҷ�, ������ Ŭ���� �ڷ����� ��ü�� �����ϴ� ��� �� ȣ��
// ������� ���� ���� - const
// ��������� - ���� ����� �����

////6
//char& find(char a[], char c, bool& success) // ������ �̿��ؼ� ã�� ������ �ε��������� ������ ��ȯ
//{
//	int i = 0;
//	while (1)
//	{
//		if (a[i] == '\0') // ���ڿ� a�� ������ while ����
//		{
//			break;
//		}
//		if (a[i] == c) // ���ڿ� a�� 'M'�� �ִٸ�
//		{
//			success = true; // �������� success�� true�� �ٲٰ�
//			return a[i]; // ���ڰ����� ������ȯ
//		}
//		i++;
//	}
//	return a[0]; // �ǹ̾��� ��ȯ // b�� flase�̱� ������ �ڵ忡 ������ ��������
//}
//int main()
//{
//	char s[] = "Mike"; // char ���ڿ� ����
//	bool b = false; // ���ڿ����� M�� �߰��� �� ������ �ƴ� bool�� ���� ����
//	char& loc = find(s, 'M', b); // ��ȯ�� ������ ����
//	if (b == false) // b�� false���
//	{
//		cout << "M�� �߰��� �� ����." << endl; // M�� ã�� �� ���ٰ� ���
//		return 0;
//	}
//	loc = 'm'; // ������ ������ M -> m ���� ����
//	cout << s << endl; // �ϼ��� ���ڿ� ���
//}

////7 // push ���� �� // pop ������ ��
//class MyIntStack // Ŭ���� MyIntStack
//{
//	int p[10]; // ũ�Ⱑ 10�� �迭 p
//	int tos; // �ε����� �˷��ִ� �������
//public: // ����
//	MyIntStack() // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // �迭�� ��� �ε����� 1�� �ʱ�ȭ
//	}
//	bool push(int n) // stack�� ���� ����ִ� ����Լ�
//	{
//		if (tos >= 10) // �ε������� 10���� ũ�ų� ������
//		{
//			return false; // false ��ȯ
//		}
//		else // �ƴ϶��
//		{
//			p[tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//			return true;
//		}
//	}
//	bool pop(int& n) // stack�� ���� ���� �Ųٷ� ������ ����Լ�
//	{
//		if (tos == 0) // ���� ����� ������ 
//		{
//			return false; // false ��ȯ
//		}
//		else // �ƴ϶��
//		{
//			n = p[--tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//			return true;
//		}
//	}
//};
//int main()
//{
//	MyIntStack a; // Ŭ���� MyIntStack �� ��ü a ����
//	for (int i = 0; i < 11; i++) // 11���� Ǫ���ϸ�, ���������� stack full�� �ȴ�.
//	{
//		if (a.push(i))
//			cout << i << ' '; // Ǫ�õ� �� ����
//		else cout << endl << i + 1 << " ��° stack full" << endl;
//		// stack�� �� ���� �� á�ٰ� ���
//	}
//	int n;
//	for (int i = 0; i < 11; i++) // 11���� ���ϸ�, ���������� stack empty�� �ȴ�.
//	{
//		if (a.pop(n)) // n�� �����Ѵ�
//			cout << n << ' '; // ������ ������ ����� ������ ��� // �� �� �� ���
//		else cout << endl << i + 1 << " ��° stack empty";
//		// stack���� �� ������ �� �����ٰ� ���
//	}
//	cout << endl;
//}

////8 // 7�� ���� // �����Ҵ� // ������ - �����Ҵ� // �Ҹ��� // ��������� - ��������
//class MyIntStack // Ŭ���� MyIntStack
//{
//	int* p; // ���� �޸𸮷� ����� ������
//	int size; // ������ �ִ� ũ��
//	int tos; // ������ ž�� ����Ű�� �ε���
//public: // ����
//	MyIntStack() // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
//		size = 0; // 0���� �ʱ�ȭ
//		p = NULL; // p�� ����Ű�� ������ ������ �ǹ� // p = nullptr;
//	}
//	MyIntStack(int size) // �Ű������� �ִ� ������
//	{
//		this->size = size; // �Լ��� ȣ���� ��ü�� size�� �Ű����� size�� �ʱ�ȭ
//		tos = 0; // tos�� 0���� �ʱ�ȭ
//		p = new int[this->size](); // p�� ũ�Ⱑ ��ü�� size��ŭ�� �����Ҵ� �迭������ �ּ� ����
//	}
//	MyIntStack(const MyIntStack& s) // ���������
//	{
//		this->size = s.size; // �Լ��� ȣ���� ��ü�� size�� �����Ű����� ��ü�� size�� �ʱ�ȭ
//		this->tos = s.tos; // �Լ��� ȣ���� ��ü�� tos�� �����Ű����� ��ü�� tos�� �ʱ�ȭ
//		p = new int[this->size](); // // p�� ũ�Ⱑ ��ü�� size��ŭ�� �����Ҵ� �迭������ �ּ� ����
//		for (int i = 0; i < size; i++)
//		{
//			p[i] = s.p[i]; // �����Ҵ� �迭������ ������ü�� �����Ҵ� �迭������ ���� ����
//		}
//	}
//	~MyIntStack() // �Ҹ���
//	{
//		if (p) // p�� �Ҵ�� ������ ����Ű�� �ִٸ�
//			delete[] p; // �� ������ ����
//		p = nullptr;
//	}
//	bool push(int n) // stack�� ���� ����ִ� ����Լ�
//	{
//		if (tos > size) // �ε������� 10���� ũ�ų� ������ // ������ �� �� ������
//		{
//			return false; // false ��ȯ
//		}
//		else // �ƴ϶��
//		{
//			p[tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//			return true; // ������ �� �� ���� ������ true ����
//		}
//	}
//	bool pop(int& n) // stack�� ���� ���� �Ųٷ� ������ ����Լ�
//	{
//		if (tos < 0) // ���� ����� ������ // ������ ����ִٸ�
//		{
//			return false; // false ��ȯ
//		}
//		else // �ƴ϶��
//		{
//			n = p[--tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//			return true; // ������ ��� ���� �ʴٸ� true ����
//		}
//	}
//};
//int main()
//{
//	MyIntStack a(10); // Ŭ���� MyIntStack�� ��ü a ����
//	a.push(10); // a.p[0]�� 10 ����
//	a.push(20); // a.p[1]�� 20 ����
//	MyIntStack b = a; // ���� ���� // a�� ������ b�� �״�� �����ؼ� b ��ü ����
//	b.push(30); // b.p[2]�� 30 ���� // b.p[0]���� ��������ڷ� ���� 10�� ����
//				                    // b.p[1]���� ��������ڷ� ���� 20�� ����
//	int n;
//	a.pop(n); // ���� a ��
//	cout << "���� a���� ���� �� " << n << endl; // a.p[1] ���
// 	b.pop(n); // ���� b ��
//	cout << "���� b���� ���� �� " << n << endl; // b.p[2] ���
//}

////9
//class Acuumulator // Ŭ���� Acuumulator
//{
//	int value; // ����Լ� value ����
//public: // ����
//	Acuumulator() // �⺻������
//	{
//		value = 0;
//	}
//	Acuumulator(int value) // �Ű� ���� value�� ��� value�� �ʱ�ȭ�Ѵ�
//	{
//		this->value = value; // �Ű������� ���� value�� �Լ��� ȣ���� ��ü�� value�� �ʱ�ȭ
//	}
//	Acuumulator& add(int n) // �Լ��� ȣ���ϴ� ��ü�� ��� ������ �� ����
//		// value�� n�� ���� ���� �����Ѵ�
//	{
//		this->value += n; // �Ű����� n�� ���� value�� ���簪�� ����
//		return *this; // ȣ���� ��ü ��ü�� ������ȯ
//	}
//	int get() // value�� ����
//	{
//		return value; // ������ �� value�� �����Ѵ�
//	}
//};
//int main()
//{
//	Acuumulator acc(10); // ��ü acc�� value�� 10���� �ʱ�ȭ
//	acc.add(5).add(6).add(7); // ȣ���� ������ ��ü��ü�� �����ؼ� �������� ������ �� ����
//	// acc�� value ����� 28�� �ȴ�
//	cout << acc.get(); // ��ü acc�� value�� ��� // 28 ���
//}

////10 // append �Լ� �����Լ� - ��������
//class Buffer // Ŭ���� Buffer
//{
//	string text; // string�� ���ڿ� text
//public: // ����
//	Buffer() // �⺻������
//	{
//		text = '0';
//	}
//	Buffer(string text) // �Ű������� �ִ� ������
//	{
//		this->text = text; // �Է¹��� ���ڿ��� ��ü�� text �ʱ�ȭ
//	}
//	void add(string next) // �Է¹��� ���ڿ��� ��ü�� text�� �߰�
//	{
//		text += next;
//	}
//	void print()
//	{
//		cout << text << endl; // text�� ����ϴ� ����Լ�
//	}
//};
//Buffer& append(Buffer& b, string a) // buf�� ���������ϴ� b�� ����Լ� ȣ��
//{
//	b.add(a); // ���ڿ� a�� add ����Լ��� �̿��� �߰�
//	return b; // buf�� ���������ϴ� b�� ��������
//}
//
//int main()
//{
//	Buffer buf("Hello"); // Hello�� buf�� ������� �ʱ�ȭ
//	Buffer& temp = append(buf, "Guys"); // buf , b�� ���� ������ temp��� �̸��� ����
//	temp.print(); // temp�� ���ڿ� ���
//	buf.print(); // buf�� ���ڿ� ���
//}

////11 // (1)���� �ϱ� // ��������� ����� - ���� ����
// string ��� �� ���� ���� ����, �Ҹ��� �ʿ� X,  ��������� ���� ���� �ʿ� X
//class Book // Ŭ���� Book
//{
//	char* title; // ���� ���ڿ�
//	int price; // ����
//public:
//	Book() // �⺻������
//	{
//		title = NULL;
//		price = 0;
//	}
//	Book(const char* title, int price) // �Ű������� �ִ� ������
//	{ 
//		int len = strlen(title); // �Է¹��� ���ڿ��� ũ��
//		this->title = new char[len + 1](); // �� ũ�⺸�� �ϳ� ū ������ ���Ҵ�
//		strcpy(this->title, title); // �Լ��� ȣ���� ��ü�� title�� �Է¹��� ���ڿ� ����
//		this->price = price; // �Լ��� ȣ���� ��ü�� price�� �Է¹��� �� ����
//	}
//	Book(Book& b) // ��������� - ���� ����
//	{
//		this->price = b.price;  // �Լ��� ȣ���� ��ü�� price�� ������ cpp�� price ����
//		int len = strlen(b.title); // ������ cpp�� title�� ����
//		this->title = new char[len + 1](); // �� ���̺��� �ϳ� ū ��ŭ ������ �Ҵ�
//		strcpy(this->title, b.title); // ���� �Ҵ�� ������ cpp�� title ����
//	}
//	~Book() // �Ҹ���
//	{
//		if (title) // title�� �Ҵ�� ������ ����Ų�ٸ�
//			delete[] title; // title�� ����Ű�� ������ ����
//		title = nullptr;
//	}
//	void set(const char* title, int price) // �Էµ� ���ڿ��� title �缳��
//	{
//		this->price = price; // �Լ��� ȣ���� ��ü�� price�� �Է¹��� ���� ����
//		if (this->title) // ������� title�� �Ҵ�� �޸𸮰� ������
//		{
//			delete[] this->title; // �� ���� ����
//			this->title = NULL;
//		}
//		this->title = new char[strlen(title) + 1](); // �Ű������� ũ�⺸�� �ϳ� ū ��ŭ�� �迭������ �Ҵ���
//		strcpy(this->title, title); // �Է¹��� å�̸��� ����
//	}
//	void show() // ��ü�� ������� ���
//	{
//		cout << title << ' ' << price << "��" << endl;
//	}
//};
//int main()
//{
//	Book cpp("��ǰC++", 10000); // Ŭ���� Book ��ü cpp����
//	Book java = cpp; // cpp�� ���� ��ü java ���� // ��������� ȣ��
//	java.set("��ǰ�ڹ�", 12000); // java�� ���ڿ��� ��ǰ�ڹٷ� �ٲٰ� ������ �����ϱ�
//	cpp.show(); // cpp�� ������� ���
//	java.show(); // jave�� ����� ������� ���
//}

////12 // 11���� ���� // ��������� - ���� ���� // (1)�� �ϱ�
//class Dept // Ŭ���� Dept
//{
//	int size; // scores �迭�� ũ��
//	int* scores; // �����Ҵ���� ���� �迭�� �ּ�
//public: // ����
//	Dept() // �⺻������
//	{
//		size = 0;
//		scores = NULL;
//	}
//	Dept(int size) // �Ű������� �ִ� ������
//	{
//		this->size = size; // �Լ��� ȣ���� ��ü�� size�� �Է¹��� ���� �ʱ�ȭ
//		scores = new int[size](); // size ��ŭ �迭 ������ �Ҵ����
//	}
//	Dept(const Dept& dept) // ���� ������
//	{
//		size = dept.size; // size ����
//		scores = new int[size + 1](); // size���� �ϳ� ũ�� ������ �Ҵ�
//		for (int i = 0; i < this->size; i++) // size ��ŭ
//		{
//			scores[i] = dept.scores[i]; // ���� �Ҵ���� ������ ��ü dept�� �迭���� ���� ����
//		}
//	}
//	~Dept() // �Ҹ���
//	{
//		if (scores) // scores�� ����Ű�� ������ �ִٸ�
//			delete[] scores; // �� ���� ����
//		scores = nullptr;
//	}
//	int getSize() // ������� ����ϴ� ����Լ�
//	{
//		return size;
//	}
//	void read() // �Է¹��� ������ ��������� scores�� ����Ű�� �� �迭������ ����
//	{
//		cout << "10�� ���� �Է�>> "; // �Է¹ޱ� ���� ����
//		for (int i = 0; i < size; i++) // size ��ŭ
//		{
//			cin >> scores[i]; // ���� �Է¹޾� �迭�� i��° ������ ����
//		}
//	}
//	bool isOver60(int index) // �迭�� index��° ������ ���� 60�� �Ѵ´ٸ�
//	{
//		if (scores[index] > 60)
//		{
//			return true; // true ��ȯ
//		} 
//		else // ���� ������
//		{
//			return false; // false ��ȯ
//		}
//	}
//};
//int countPass(Dept dept) // �Ϲ��Լ� // ��������� ȣ�� // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
//{
//	int count = 0; // 60�� �̻��� �л� ���� ���� ����
//	int n = dept.getSize(); // ��ü dept�� size�� n�� ����
//	for (int i = 0; i < n; i++) // n ��ŭ
//	{
//		if (dept.isOver60(i)) // isOver60�Լ��� ȣ���ؼ� 60�� �̻��� �л��� ���� �ִٸ�
//			count++; // ī��Ʈ�� ����
//	} // ���ٸ� �ٽ� �ݺ����� ����
//	return count; // �ݺ����� ������ ���� count���� ��ȯ
//}
//// //���� ������ ���� ����ǰ� �����
////int countPass(Dept & dept) // �Ϲ��Լ� // ��������� ȣ�� // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
////{
////	int count = 0; // 60�� �̻��� �л� ���� ���� ����
////	int n = dept.getSize(); // ��ü dept�� size�� n�� ����
////	for (int i = 0; i < n; i++) // n ��ŭ
////	{
////		if (dept.isOver60(i)) // isOver60�Լ��� ȣ���ؼ� 60�� �̻��� �л��� ���� �ִٸ�
////			count++; // ī��Ʈ�� ����
////	} // ���ٸ� �ٽ� �ݺ����� ����
////	return count; // �ݺ����� ������ ���� count���� ��ȯ
////}
//int main()
//{
//	Dept com(10); // Ŭ���� Dept ��ü com ���� // size�� 10
//	com.read(); // com�� scores�� ����Ű�� �迭 ������  �Է¹��� �� ����
//	int n = countPass(com); // ��������� ȣ�� // 60�� �̻��� ������ ���� �л� ���� n�� ����
//	cout << "60�� �̻��� " << n << "��";
//}