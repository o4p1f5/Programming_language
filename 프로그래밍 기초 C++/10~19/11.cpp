#include <iostream>
using namespace std;

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

////8-1 // ����Լ� �̿� // ���� ������ - ����, ����
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//	Circle operator++() // ����++ ����
//	{
//		this->radius++;
//		return *this; // a ��ȯ
//	}
//	Circle operator++(int n) // ����++ ����
//	{
//		Circle tmp = *this; // �ٲ�� �� a�� �� ����
//		this->radius++; // a ����
//		return tmp; // �ٲ�� ���� ���� ��ȯ�� b�� �������
//	}
//};
//int main()
//{
//	Circle a(5), b(4); // ��ü a,b ����
//	++a; // ���� // a.operator++(); 
//	b = a++; // ���� // b = a.operator++(0); 
//	a.show(); b.show();
//}

////8-2 // ������ �Լ�
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//	friend Circle operator++(Circle& op); // ���� ++������ ���� // �Ϲ��Լ� -> �������Լ�
//	friend Circle operator++(Circle& op, int n); // ���� ++������ ���� // �Ϲ��Լ� -> �������Լ�
//};
//Circle operator++(Circle &op) // ���� // �������ϸ� ����������� ���ι��� ��ü�� �ٲ��� ����
//{
//	// ����++ ���� // ��ü a ����
//	op.radius++; // a ����
//	return op; // a ���� ��ȯ
//}
//Circle operator++(Circle &op, int n) // ���� // �������ϸ� ����������� ���ι��� ��ü�� �ٲ��� ����
//{
//	// ����++ ���� // ��ü a ����
//	Circle tmp = op; // �ٲ�� �� a�� �� ����
//	op.radius++; // a ����
//	return tmp; // �ٲ�� ���� ���� ��ȯ�� b�� �������
//}
//int main()
//{
//	Circle a(5), b(4); // ��ü a,b ����
//	++a; // ���� // operator++(a); 
//	b = a++; // ���� // b = operator++(a,0); 
//	a.show(); b.show();
//}

////9 // �������Լ��� ����
//class Circle
//{
//	int radius;
//public:
//	Circle(int radius = 0) { this->radius = radius; }
//	void show() { cout << "radius = " << radius << " �� ��" << endl; }
//	friend Circle operator+(int n, Circle op);
//};
//Circle operator+(int n, Circle op) // a�� �� �ٲ�� �ȵǹǷ� ���� X // �������
//{
//	//op.radius = op.radius + n; // op�� �������� n�� ���� ���� op�� �������� ����
//	//return op; // ��ü op ��ȯ
//	Circle tmp;
//	tmp.radius = n + op.radius;
//	return tmp;
//}
//int main()
//{
//	Circle a(5), b(4); // ��ü a,b ����
//	b = 1 + a; // b = operator+(1,a) // b = 1.operator+(a) �� 1�� ��ü�� �ƴϹǷ� �Ұ��� - ����Լ��� ������ ������ �� ����.
//	// b�� �������� a�� �������� 1�� ���� ������ ���� // ��ȯ�� ��ü�� �������
//	a.show(); b.show();
//}

////10-1 // ����Լ�
//class Statistics // ��踦 ���� Ŭ����
//{
//	int* p; // �迭�� �����Ҵ��� �� �ּҸ� ���� ������ ����
//	int size; // �ε���
//	int capacity; // �����Ҵ�� ������ ��
//public:
//	Statistics(int size = 0, int capacity = 10)
//	{
//		// ����Ʈ �Ű������� �̿��� ������
//		this->size = size;
//		this->capacity = capacity;
//		p = new int[capacity];
//	}
//	Statistics(Statistics& s) // ���������
//	{
//		this->size = s.size; // s�� ���� �ѱ�
//		this->capacity = s.capacity;
//		this->p = new int[this->capacity]; // ���޹��� capacity��ŭ ���Ӱ� �����Ҵ� �� p�� �ּ� ���� 
//		for (int i = 0; i < this->size; i++) // ������ ���� �ε��� ���̱��� �ݺ���
//			p[i] = s.p[i]; // p�� �迭������ ��ü s�� �迭������ ����� �� ����
//	}
//	~Statistics() // �Ҹ���
//	{
//		if (p) // �����Ҵ� ���� p�� ���� ����
//			delete[] p;
//	}
//	bool operator!() // ! ������ ����
//	{
//		if (!size)
//			return true; // �����Ҵ���� ������ �Է¹��� ���� �ϳ��� ������ �ǹ�
//		else
//			return false; // �����Ҵ���� ������ ���� �ԷµǾ������� �ǹ�
//	}
//	Statistics& operator<<(int op) // << ������ ���� // �Է¹��� x�迭�� ������ 
//	{
//		p[size++] = op; // ��ü stat�� size��° �ε����� �ϳ��� ���� // size�� �����ϹǷ� �ε����� �÷���
//		return *this; // ���� ��ü�� ���� ��ȯ
//	}
//	void operator~() // ~ ������ ���� // �Ҹ��� X // p���
//	{
//		for (int i = 0; i < size; i++)
//			cout << p[i] << " "; // p�� ����Ű�� ������ ����� ������ ���
//		cout << endl;
//	}
//	void operator>>(int& avg) // >> ������ ���� // p�� ����Ű�� ������ ��� �� ����
//	{
//		// avg ����
//		int sum = 0;
//		for (int i = 0; i < size; i++)
//			sum += p[i]; // ��� ���� ��
//		avg = sum / size; // ���� �����ε����� ���� ������ ����� ����
//	}
//};
//int main()
//{
//	Statistics stat; // size�� 0�̰�, �迭������ 10��ŭ �����Ҵ��ϰ� �� �ּҸ� p�� ����
//	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
//	// stat.operator!(); 
//	// stat�� size�� 0�̶�� => stat�� ���� �� ���� ���ٸ� true ��ȯ
//
//	int x[5];
//	cout << "5 ���� ������ �Է��϶�>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]�� ���� �Է�
//
//	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�. // stat.operator<<(x[i])
//	stat << 100 << 200; // 100, 200�� ��� ��ü�� �����Ѵ�.
//	//stat.operator<<(100).operator<<(200) // ������ �� �ؾ� �����ڸ� �������� ����ϴ� ����� ����� �� ����
//	
//	~stat; // stat.operator~(); // ��� �����͸� ��� ���
//
//	int avg;
//	stat >> avg; // stat.operator>(avg); // ��� ��ü�κ��� ����� �޴´�.
//	cout << "avg = " << avg << endl; // ��� ���
//}

////10-2 // �������Լ� �̿�
//class Statistics
//{
//	int* p; // �迭�� �����Ҵ��� �� �ּҸ� ���� ������ ����
//	int size; // �ε���
//	int capacity; // �����Ҵ�� ������ ��
//public:
//	Statistics(int size = 0, int capacity = 10)
//	{
//		// ����Ʈ �Ű������� �̿��� ������
//		this->size = size;
//		this->capacity = capacity;
//		p = new int[capacity];
//	}
//	Statistics(Statistics& s) // ���������
//	{
//		this->size = s.size; // s�� ���� �ѱ�
//		this->capacity = s.capacity; // ������ ���� �ε��� ���̱��� �ݺ��� 
//		this->p = new int[this->capacity]; // ���޹��� capacity��ŭ ���Ӱ� �����Ҵ� �� p�� �ּ� ���� 
//		for (int i = 0; i < this->size; i++) // ������ ���� �ε��� ���̱��� �ݺ���
//			p[i] = s.p[i]; // p�� �迭������ ��ü s�� �迭������ ����� �� ����
//	}
//	~Statistics() // �Ҹ���
//	{
//		if (p) // �����Ҵ� ���� p�� ���� ����
//			delete[] p;
//	}
//	friend bool operator!(Statistics op); // ! ������ ����
//	friend Statistics& operator<<(Statistics& op1, int op2); // << ������ ����
//	friend void operator~(Statistics op); // ~ ������ ����
//	friend void operator>>(Statistics op, int& avg); // >> ������ ����
//};
//bool operator!(Statistics op) // ! ������ ����
//{
//	if (!op.size) // ���� ��ü�� �� ���� ���ٸ�
//		return true; // true ��ȯ
//	else // �� ���� �ϳ���� �ֵ��
//		return false; // false ��ȯ
//}
//Statistics& operator<<(Statistics& op1, int op2) // ������ �����Ϸ��� �����Ǵ� ������ �����ؾ��Ѵ�
//{
//	op1.p[op1.size++] = op2; // �Է¹��� op2�� op1�� p�� ����Ű�� �� ������ size �ε����� ����
//	return op1; // ���� ��ȯ
//}
//void operator~(Statistics op) // ~ ������ ����
//{
//	for (int i = 0; i < op.size; i++)
//		cout << op.p[i] << " "; // ��ü op�� p�� ����Ű�� �������� �� ���
//	cout << endl;
//}
//void operator>>(Statistics op, int& avg) // >> ������ ����
//{
//	int sum = 0;
//	for (int i = 0; i < op.size; i++)
//		sum += op.p[i]; // ��ü op�� �� ��� ����
//	avg = sum / op.size; // ��� ���� ���� op�� size(���� ���� ����Ǿ��ִ� ������ ������ �ε���)�� ���� ��հ��� ����
//}
//int main()
//{
//	Statistics stat; // size�� 0�̰�, �迭������ 10��ŭ �����Ҵ��ϰ� �� �ּҸ� p�� ����
//	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
//	// stat.operator!(); // operator!(stat);
//	// stat�� size�� 0�̶�� => stat�� ���� �� ���� ���ٸ� true ��ȯ
//
//	int x[5];
//	cout << "5 ���� ������ �Է��϶�>>";
//	for (int i = 0; i < 5; i++) cin >> x[i]; // x[i]�� ���� �Է�
//
//	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�.
//	// operator<<(stat, x[i]);
//
//	stat << 100 << 200; // 100, 200�� ��� ��ü�� �����Ѵ�.
//	//stat.operator<<(100).operator<<(200) // ������ �� �ؾ� �����ڸ� �������� ����ϴ� ����� ����� �� ����
//	
//	~stat; // stat.operator~(); //operator~(stat) // ��� �����͸� ��� ���
//
//	int avg;
//	stat >> avg; // stat.operator>(avg); // operator(stat,avg); // ��� ��ü�κ��� ����� �޴´�.
//	cout << "avg = " << avg << endl; // ��� ���
//}

////11-1 // ����Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//class Stack // Ŭ���� Stack
//{
//	int p[10]; // ũ�Ⱑ 10�� �迭 p
//	int tos; // �ε����� �˷��ִ� �������
//public: // ����
//	Stack() // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // �迭�� ��� �ε����� 1�� �ʱ�ȭ
//	}
//	Stack& operator<< (int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//	{
//		p[tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//		return *this; // �ٲ� ��ü ����
//	}
//	bool operator! () // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//	{
//		if (tos == 0) // ���� ����� ������ 
//			return true; // true ��ȯ
//		else
//			return false; // stack�� ���� �����ִٸ� false ��ȯ
//	}
//	void operator>> (int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//	{
//		n = p[--tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//	}
//};
//int main()
//{
//	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // ���� ���� �ݺ���
//	{
//		if (!stack) break; // ���� empty // stack.operator!()
//		int x = 0; // �˵� ������ ������ ����
//		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//// ������ ��� 11-1 // ����Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//class Stack // Ŭ���� Stack
//{
//	int size;
//	int* mem;
//	int tos;
//public: // ����
//	Stack(int size = 10) // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
//		this->size = size;
//		mem = new int[size]();
//	}
//	~Stack()
//	{
//		if (mem)
//			delete[] mem;
//	}
//	Stack& operator<< (int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//	{
//		mem[tos++] = n;
//		return *this; // this => ��ü stack
//	}
//	bool operator! () // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//	{
//		if (tos <= 0) // ���� ����� ������ 
//			return true; // true ��ȯ
//		else
//			return false; // stack�� ���� �����ִٸ� false ��ȯ
//	}
//	Stack& operator>> (int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//	{
//		n = mem[--tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//		return *this;
//	}
//};
//int main()
//{
//	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // ���� ���� �ݺ���
//	{
//		if (!stack) break; // ���� empty // stack.operator!()
//		int x = 0; // �˵� ������ ������ ����
//		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

////11-2 // ������ �Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//class Stack // Ŭ���� Stack
//{
//	int p[10]; // ũ�Ⱑ 10�� �迭 p
//	int tos; // �ε����� �˷��ִ� �������
//public: // ����
//	Stack() // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
//		for (int i = 0; i < 10; i++)
//			p[i] = 0; // �迭�� ��� �ε����� 1�� �ʱ�ȭ
//	}
//	friend Stack& operator<< (Stack& op, int n); // <<������ ������ȭ
//	friend bool operator! (Stack op); // !������ ������ȭ
//	friend void operator>> (Stack& op, int& n); // >>������ ������ȭ
//};
//Stack& operator<< (Stack& op, int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//{
//	// op�� ����������� ����Ǿ���ϹǷ� �����Ű������� ����ؾ� ��
//	op.p[op.tos++] = n; // tos �������� // �迭 p�� tos�� ������ n�� �� ����
//	return op; // �ٲ� ��ü ����
//}
//bool operator! (Stack op) // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//{
//	// operator>>�Լ����� ����� tos�� �̿��� �Ǵ��ؾ� ��
//	if (op.tos == 0) // ���� ����� ������ 
//		return true; // true ��ȯ
//	else
//		return false; // stack�� ���� �����ִٸ� false ��ȯ
//}
//void operator>> (Stack& op, int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//{
//	n = op.p[--op.tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//}
//int main()
//{
//	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // ���� ���� �ݺ���
//	{
//		if (!stack) break; // ���� empty // stack.operator!() // operator!(stack);
//		int x = 0; // �˵� ������ ������ ����
//		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x); // operator>>(stack,x);
//		cout << x << ' ';
//	}
//	cout << endl;
//}

//// ������ ��� 11-2 // friend�Լ� �̿� // 10���� ���� // ����Ŭ���� ����� �̿� // �����Ҵ� X
//class Stack // Ŭ���� Stack
//{
//	int size;
//	int* mem;
//	int tos;
//public: // ����
//	Stack(int size = 10) // �⺻������
//	{
//		tos = 0; // 0���� �ʱ�ȭ
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
//Stack& operator<< (Stack &op1,int n) // <<������ ���� // ���������ؼ� �� �� ������ ȣ���� ��ü��ü�� �������
//{
//	op1.mem[op1.tos++] = n;
//	return op1; // ���� - ��ü stack
//}
//bool operator! (Stack& op) // !������ ���� // stack�� ���� ���ٸ� true ��ȯ
//{
//	// �Ű������� &�� �ٿ����ϴ� ���� 
//	//- ��������ڸ� ȣ������ �ʰ� ������� 
//	//- ������ ������ָ� �Լ��� �������͵� �Ҹ��ڰ� ȣ����� �ʾ� ������ ������ 
//	//- ������ ���� ������ ��������ڸ� ���� ������ �ʾұ⶧���� ���� ���簡 �̷����� �Ҹ��ڰ� ȣ��Ǿ����� ������ �߻���
//	if (op.tos <= 0) // ���� ����� ������ 
//		return true; // true ��ȯ
//	else
//		return false; // stack�� ���� �����ִٸ� false ��ȯ
//}
//Stack& operator>> (Stack& op1,int& n) // >>������ ���� // ������ ž�� �ִ� ���� �� 
//{
//	n = op1.mem[--op1.tos]; // tos �������� // �迭 p�� tos - 1 �� ������ �ִ� ���� n�� ����
//	return op1;
//}
//
//int main()
//{
//	Stack stack; // 10���� �迭������ ���� ��ü stack ����
//	stack << 3 << 5 << 10; // 3,5,10�� ������� Ǫ�� // ������ ���� ���
//						   // stack.operator<<(3).operator<<(5).operator<<(10);
//	while (true) // ���� ���� �ݺ���
//	{
//		if (!stack) break; // ���� empty // stack.operator!()
//		int x = 0; // �˵� ������ ������ ����
//		stack >> x; // ������ ž�� �ִ� ���� �� // stack.operator>>(x)
//		cout << x << ' ';
//	}
//	cout << endl;
//}

////12-1 // ����Լ� �̿� // ��������� - ���� ���� // ������ ���� // �����Ҵ� // �� ��������
//class SortedArray
//{
//    int size; // ���� �迭�� ũ��
//    int* p; // ���� �迭�� ���� ������
//    void sort() // ���� �迭�� ������������ ���� // private - Ŭ���� �ܺο��� ���� �Ұ���
//    {
//        for (int i = 0; i < size; i++) // ��������
//        {
//            for (int j = 0; j < size - 1; j++) 
//            {
//                if (p[j] > p[j + 1]) // p[j]�� p[j+1]���� Ŭ �� // ū ���� �ڷ� ������
//                {
//                    int n1 = p[j]; // ���� p[j]�� n1�� ����
//                    p[j] = p[j + 1]; // p[j]�� p[j+1] ����
//                    p[j + 1] = n1; // p[j+1]�� ���� p[j] ����
//                }
//            }
//        }
//    }
//public:
//    SortedArray() // p�� NULL�� size�� 0���� �ʱ�ȭ // �⺻������
//    {
//        p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//        size = 0;
//    }
//    SortedArray(SortedArray& src) // ���� ������ // ��������
//    {
//        size = src.size; // �����ϰ��� �ϴ� ��ü�� size ����
//        if (!src.size) // size�� 0�̶��
//            p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//        else
//            p = new int[size](); // size���� ����޾Ҵٸ� �׸�ŭ ���ο� ���� �����Ҵ�
//        for (int i = 0; i < size; i++)
//            p[i] = src.p[i]; // �����ϰ����ϴ� ��ü�� �� ���� ���� this�� �����Ҵ� ������ ����
//        sort(); // ���� �迭�� ������������ ����
//    }
//    SortedArray(int p[], int size) // �Ű������� �ִ� ������, ���� �迭�� ũ�⸦ ���޹���
//    {
//        this->size = size;
//        /*this->p = new int[size]; */
//        if (!size) // size�� 0�̶��
//            this->p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//        else 
//        {
//            this->p = new int[size](); // size���� ����޾Ҵٸ� �׸�ŭ ���ο� ���� �����Ҵ�
//            if (p)
//            {
//                for (int i = 0; i < size; i++)
//                    this->p[i] = p[i];
//            }
//        }
//        sort(); // ���� �迭�� ������������ ����
//    }
//    ~SortedArray() // �Ҹ���
//    {
//        if (p)
//            delete[] p; // �����Ҵ�� ������ ����
//        p = nullptr; // p�� �ƹ��͵� ����Ű�������� ����
//    }
//    SortedArray operator+(SortedArray& op2) // ���� �迭�� op2 �迭 �߰� //+������ ����
//    {
//        SortedArray c; // �� ��ü�� ���� ��� ���� ����� ��ü�� �ϳ� �� ����
//        // c.p,7 �̷��� ������ϸ� �������� ����Ȯ�� ����
//        c.size = this->size + op2.size; // �� ��ü�� size�� ���� ���� c�� size�� ����
//        c.p = new int[c.size](); // ����� size��ŭ ���ο� ������ �����Ҵ���
//        for (int i = 0; i < this->size; i++) // c.size��ŭ �ݺ����� ������ �� ���� �޸� ħ�� �߻�
//            c.p[i] = this->p[i]; // �ε��� 0~2���� ��ü a�� �迭 �� c�� �迭�� ����
//        for (int i = 0; i < op2.size; i++)
//            c.p[i + this->size] = op2.p[i]; // �ε��� 3~6���� ��ü b�� �迭 �� c�� �迭�� ����
//        c.sort(); // ���� �迭�� ������������ ����
//        return c; // ��ü a�� b�� ���� ���� ���� ��ü c�� ��ȯ // ���� ����
//    }
//    SortedArray& operator=(const SortedArray& op2) // ���� �迭�� op2 �迭 ���� // = ������ ����
//    {
//        // Ŭ������ ����Լ��θ� ���� �� �ִ�.
//        // op2�� ���� =�����ڸ� ȣ���� ��ü�� ����
//        if (p)
//            delete[] p;
//        this->size = op2.size;
//        if (!size)
//            this->p = nullptr;
//        else
//        {
//            this->p = new int[this->size]; // �ּҸ� ���� X , �Ҹ� �� ���� ����ó�� �ۿ� (�� ��ü�� �ϳ��� �������� �����Ѽ�)
//            for (int i = 0; i < this->size; i++)
//                this->p[i] = op2.p[i];
//        }
//        sort(); // ���� �迭�� ������������ ����
//        return *this; // ������ȯ
//    }
//    void show() // �迭�� ���� ���
//    {
//        cout << "�迭 ��� :";
//        for (int i = 0; i < size; i++)
//            cout << p[i] << ' ';
//        cout << endl;
//    }
//};
//int main()
//{
//    int n[] = { 2,20,6 };
//    int m[] = { 10,7,8,30 };
//    SortedArray a(n, 3), b(m, 4), c; // ��ü�� ����
//
//    c = a + b; // +,= ������ �ۼ� �ʿ� // a.operator+(b); // c.operator=(a+b);
//    // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
//    // = ������ ������ ���� : �⺻������ �����Ϸ��� �����ϴ� =�����ڴ� ���� ���縸 ���� -> ���� ���縦 �� �� �ְ� ������ �������
//    // (����Ʈ ���Կ����ڰ� Ŭ���� ���� �ֱ� ������ ��������ڸ� ���������ִ� �Ͱ� ���� ���Կ����ڸ� ���� �����ϱ� ���� �������Ϸ��� Ŭ�������� �� ����Լ��θ� ����������߸� �Ѵ�. - �Ϲ��Լ��� �������Լ�ȭ �Ұ���)
//    // ����Ʈ ���Կ����ڰ� ȣ��� ���� ��������ڰ� ȣ����� �ʴ´�.
//    // point& operator=(point & p) // ����Ʈ ���Կ����� = �⺻�Ҵ���Կ�����
//    a.show(); b.show(); c.show();
//}

////12-2 // �������Լ� �̿� // ��������� - ���� ���� // ������ ���� // �����Ҵ� // �� ��������
//class SortedArray
//{
//    int size; // ���� �迭�� ũ��
//    int* p; // ���� �迭�� ���� ������
//    void sort() // ���� �迭�� ������������ ����
//    {
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < size - 1; j++)
//            {
//                if (p[j] > p[j + 1]) // p[j]�� p[j+1]���� Ŭ �� // ū ���� �ڷ� ������
//                {
//                    int n1 = p[j]; // ���� p[j]�� n1�� ����
//                    p[j] = p[j + 1]; // p[j]�� p[j+1] ����
//                    p[j + 1] = n1; // p[j+1]�� ���� p[j] ����
//                }
//            }
//        }
//    }
//public:
//    SortedArray() // p�� NULL�� size�� 0���� �ʱ�ȭ // �⺻������
//    {
//        p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//        size = 0;
//    }
//    SortedArray(SortedArray& src) // ���� ������ // ��������
//    {
//        size = src.size; // �����ϰ��� �ϴ� ��ü�� size ����
//        if (!size) // size�� 0�̶��
//            p = nullptr; // p�� �ƹ��͵� ����Ű�� ����
//        else
//            p = new int[size]; // size���� ����޾Ҵٸ� �׸�ŭ ���ο� ���� �����Ҵ�
//        for (int i = 0; i < size; i++)
//            p[i] = src.p[i]; // �����ϰ����ϴ� ��ü�� �� ���� ���� this�� �����Ҵ� ������ ����
//        sort(); // ���� �迭�� ������������ ����
//    }
//    SortedArray(int p[], int size) // �Ű������� �ִ� ������, ���� �迭�� ũ�⸦ ���޹���
//    {
//        this->size = size;
//        this->p = new int[size];
//        for (int i = 0; i < size; i++)
//            this->p[i] = p[i];
//        sort(); // ���� �迭�� ������������ ����
//    }
//    ~SortedArray() // �Ҹ���
//    {
//        if (p)
//            delete[] p; // �����Ҵ�� ������ ����
//        p = nullptr; // p�� �ƹ��͵� ����Ű�������� ����
//    }
//    void show() // �迭�� ���� ���
//    {
//        cout << "�迭 ��� :";
//        for (int i = 0; i < size; i++)
//            cout << p[i] << ' ';
//        cout << endl;
//    }
//    SortedArray& operator=(const SortedArray& op2) // ���� �迭�� op2 �迭 ���� // = ������ ����
//    {
//        // op2�� ���� =�����ڸ� ȣ���� ��ü�� ����
//        this->size = op2.size;
//        this->p = new int[this->size]; // �ּҸ� ���� X , �Ҹ� �� ���� ����ó�� �ۿ� (�� ��ü�� �ϳ��� �������� �����Ѽ�)
//        for (int i = 0; i < this->size; i++)
//            this->p[i] = op2.p[i];
//        sort(); // ���� �迭�� ������������ ����
//        return *this; // ������ȯ
//    }
//    friend SortedArray operator+(SortedArray& op1, SortedArray& op2);
//};
//SortedArray operator+(SortedArray& op1, SortedArray& op2) // ���� �迭�� op2 �迭 �߰� //+������ ����
//{
//    SortedArray c; // �� ��ü�� ���� ��� ���� ����� ��ü�� �ϳ� �� ����
//    c.size = op1.size + op2.size; // �� ��ü�� size�� ���� ���� c�� size�� ����
//    c.p = new int[c.size](); // ����� size��ŭ ���ο� ������ �����Ҵ���
//    for (int i = 0; i < op1.size; i++) // c.size��ŭ �ݺ����� ������ �� ���� �޸� ħ�� �߻�
//        c.p[i] = op1.p[i]; // �ε��� 0~2���� ��ü a�� �迭 �� c�� �迭�� ����
//    for (int i = 0; i < op2.size; i++)
//        c.p[i + op1.size] = op2.p[i]; // �ε��� 3~6���� ��ü b�� �迭 �� c�� �迭�� ����
//    c.sort(); // ���� �迭�� ������������ ����
//    return c; // ��ü a�� b�� ���� ���� ���� ��ü c�� ��ȯ // ���� ����
//}
//int main()
//{
//    int n[] = { 2,20,6 };
//    int m[] = { 10,7,8,30 };
//    SortedArray a(n, 3), b(m, 4), c; // ��ü�� ����
//
//    c = a + b; // +,= ������ �ۼ� �ʿ� 
//               // a.operator+(b); // c.operator=(a+b);
//               // operator+(a,b); // operator=(c,a+b); - ����Լ� �Ұ��� - 12-1 488,489�� �����
//    // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
//
//    a.show(); b.show(); c.show();
//}

////�������� �ۼ��Ͻ� 12�� - �������Լ� �̿�
//class SortedArray {
//	int size; // ���� �迭�� ũ��
//	int* p; // ���� �迭�� ���� ������
//	void sort() // ���� �迭�� ������������ ����
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
//	SortedArray() // p�� NULL�� size�� 0���� �ʱ�ȭ
//	{
//		size = 0;
//		p = nullptr;
//	}
//	SortedArray(SortedArray& src) // ���� ������
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
//	SortedArray(int p[], int size) // ������. ���� �迭�� ũ�⸦ ���޹���
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
//	~SortedArray() // �Ҹ���
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
//	SortedArray& operator = (const SortedArray& op2) // ���� �迭�� op2 �迭�� ����
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
//	void show() // �迭�� ���� ���
//	{
//		cout << "�迭 ��� : ";
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
//	c = a + b; // +, = ������ �ۼ� �ʿ�
//			   // + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
//
//	//operator+(a,b)
//
//
//	a.show();
//	b.show();
//	c.show();
//}
