#include <iostream>
using namespace std;
// ��� - ���������ڿ� ���� ������ �� �ִ� ���� �ƴ� ��� ã��

////1 // Circle Ŭ������ ��ӹ��� NamedCircleŬ���� �����
//class Circle // �� ����� Ŭ����
//{
//	int radius; // ������
//public:
//	Circle(int radius = 0) { this->radius = radius; } // ������ 
//	int getRadius() { return radius; } // radius ���
//	void setRadius(int radius) { this->radius = radius;} // radius �� ����
//	double getArea() { return 3.14 * radius * radius; } // ����
//}; 
//class NamedCircle : public Circle // Circle�� �̸��� ���̴� Ŭ���� // ���Ŭ���� - Circle , �Ļ�Ŭ���� - NamedCircle
//{
//	string name; // ���� �̸�
//public:
//	NamedCircle(int radius, string name) : Circle(radius) // ���Ŭ���� �����ڸ� �Ļ�Ŭ������ �����ڿ��� ���� ȣ���ϰԲ� ��
//	{
//		this->name = name; // �Ű������� �Է¹��� radius�δ� Circle ������� �ʱ�ȭ
//		// �Է¹��� ���ڿ��δ� NamedCircled�� ������� �ʱ�ȭ
//		// ���Ŭ���� �����ں��� ȣ�� �� �Ļ�Ŭ���� ������ ȣ��
//	}
//	void show()
//	{
//		cout << "�������� " << getRadius() << "�� " << name << endl;
//	}
//};
//int main()
//{
//	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
//	waffle.show();
//}

////2 // 1���� ������ �迭�� ���� �����ϰ� ��
//class Circle // �� ����� Ŭ����
//{
//	int radius; // ������
//public:
//	Circle(int radius = 0) { this->radius = radius; } // ������
//	int getRadius() { return radius; } // radius ���
//	void setRadius(int radius) { this->radius = radius; } // radius �� ����
//	double getArea() { return 3.14 * radius * radius; } // ����
//};
//class NamedCircle : public Circle // Circle�� �̸��� ���̴� Ŭ���� // ���Ŭ���� - Circle , �Ļ�Ŭ���� - NamedCircle
//{
//	string name; // ���� �̸�
//public:
//	NamedCircle(int radius = 0, string name = " ") : Circle(radius) // ���Ŭ���� �����ڸ� �Ļ�Ŭ������ �����ڿ��� ���� ȣ���ϰԲ� ��
//	{
//		this->name = name; // �Ű������� �Է¹��� radius�δ� Circle ������� �ʱ�ȭ
//		// �Է¹��� ���ڿ��δ� NamedCircled�� ������� �ʱ�ȭ
//	}
//	void setNamedCircle(int n, string name) { setRadius(n); this->name = name; } // radius�� private�̹Ƿ� ����Լ��� ����
//	string getName() { return name; } // �� �̸��� ���
//	void show() { cout << "�������� " << getRadius() << "�� " << name << endl; }
//};
//int main()
//{
//	NamedCircle pizza[5]; // ���� �̸��� ������ ���� ������ ���� ��ü�� 5���� �迭�� ����
//	// ��ü�迭�� �ݵ�� �⺻�����ڰ� ȣ��
//
//	//NamedCircle a; int n(0);  string name; // ���� ū ���� ������ ���� ��ü�� �� ���� �̸��� ���������̸� �Է¹��� ���� ����
//	//cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	cout << i + 1 << ">> ";
//	//	cin >> n >> name; // �Է¹��� ���������̿� �� �̸��� ������ ����
//	//	pizza[i].setNamedCircle(n, name); // �Է¹��� ������� ��ü�� ������ �����ϴ� �Լ��� �Ű������� ����
//	//	if (a.getArea() < pizza[i].getArea()) // NamedCircleŬ������ ��ü�� CircleŬ�������� ��ӹ޾ұ� ������ public���� ������ getArea �Լ� ��� ����
//	//		a = pizza[i]; // ��ü�� ������ ���� ������
//	//}
//	//cout << "���� ������ ū ���ڴ� " << a.getName() << "�Դϴ�."; // ���� ū ���� ������ ���� ��ü a�� �� �̸��� �Լ��� ���� ���
//	int radius = 0; string name; double area = 0; int max_area_index = 0; // ���� ū ���� ������ ���� ��ü�� �� ���� �̸��� ���������̸� �Է¹��� ���� ����
//	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << i + 1 << ">> ";
//		cin >> radius >> name; // �Է¹��� ���������̿� �� �̸��� ������ ����
//		pizza[i].setNamedCircle(radius, name); // �Է¹��� ������� ��ü�� ������ �����ϴ� �Լ��� �Ű������� ����
//		if (area < pizza[i].getArea()) // NamedCircleŬ������ ��ü�� CircleŬ�������� ��ӹ޾ұ� ������ public���� ������ getArea �Լ� ��� ����
//		{
//			area = pizza[i].getArea();
//			max_area_index = i;
//		}
//	}
//	cout << "���� ������ ū ���ڴ� " << pizza[max_area_index].getName() << "�Դϴ�."; // ���� ū ���� ������ ���� ��ü a�� �� �̸��� �Լ��� ���� ���
//}

////3 // �հ� ���� // ����� ���� // �Ļ������ // ������ �����ϰ� �Ұ����� ��� ã��
//class Point // ���Ŭ����
//{ 
//	int x, y;
//public:
//	Point(int x, int y) { this->x = x; this->y = y; } // �Ű������� ���� ������
//	int getX() { return x; } // x�� ��ġ ���
//	int getY() { return y; } // y�� ��ġ ���
//protected: // �ܺ����� �Ұ��� // �Ļ�Ŭ���������� ���ٰ���
//	void move(int x, int y) { this->x = x; this->y = y; } 
//	// x�� y�� ��ġ�� �����ϴ� ����Լ�
//};
//class ColorPoint : public Point // PointŬ������ ��ӹ��� �Ļ�Ŭ���� ColorPoint
//{
//	string color;
//public:
//	ColorPoint(int x, int y, string color) : Point(x, y) // ���Ŭ������ ������ ȣ����� �� // �� �� �Ļ�Ŭ������ ������ ȣ�� 
//	{
//		// �Է¹��� x,y�� ���Ŭ������ �����ڿ� ���޵ǰ�
//		this->color = color; // �Է¹��� ���ڿ��� color�� �����
//	}
//	void setPoint(int x, int y) // ����Ʈ ��ġ�� �����ϴ� �Լ�
//	{
//		move(x, y); // ���Ŭ������ protected�� �����Ǿ��־ �Ļ�Ŭ�������� ������ �� ������ �ܺο��� ���� �Ұ���
//	}
//	void setColor(string color) // color�� �����ϴ� �Լ�
//	{
//		this->color = color;
//	}
//	void show() // Ŭ������ ���� ���� �� ��ġ�� ���
//	{
//		cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
//	}
//};
//int main()
//{
//	ColorPoint cp(5, 5, "RED"); // ColorPointŬ���� ��ü cp ���� // ���޵� ���� �ΰ��� x,y�� ���ʴ�� ���� // ���ڿ��� color�� ����
//	cp.setPoint(10, 20); // x,y�� �����ų �Լ� ȣ��
//	cp.setColor("BLUE"); // ���� RED���� BLUE�� �����ϱ����� �Լ� ȣ��
//	cp.show(); // ��ü�� ����� �������� ���
//}

////4
//class Point // ���Ŭ����
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }// �Ű������� ���� ������
//	int getX() { return x; } // x�� ��ġ ���
//	int getY() { return y; } // y�� ��ġ ���
//protected: // �ܺ����� �Ұ��� // �Ļ�Ŭ���������� ���ٰ���
//	void move(int x, int y) { this->x = x; this->y = y; }
//	// x�� y�� ��ġ�� �����ϴ� ����Լ�
//};
//class ColorPoint : public Point // PointŬ������ ��ӹ��� �Ļ�Ŭ���� ColorPoint
//{
//	string color;
//public:
//	ColorPoint(int x = 0, int y = 0, string color = "BLACK") : Point(x, y) // ���Ŭ������ ������ ȣ����� �� // �� �� �Ļ�Ŭ������ ������ ȣ�� 
//	{
//		// ����Ʈ���� ����
//		// �Է¹��� x,y�� ���Ŭ������ �����ڿ� ���޵ǰ�
//		this->color = color; // �Է¹��� ���ڿ��� color�� �����
//	}
//	void setPoint(int x, int y) // ����Ʈ ��ġ�� �����ϴ� �Լ�
//	{
//		move(x, y); // ���Ŭ������ protected�� �����Ǿ��־ �Ļ�Ŭ�������� ������ �� ������ �ܺο��� ���� �Ұ���
//	}
//	void setColor(string color) // color�� �����ϴ� �Լ�
//	{
//		this->color = color;
//	}
//	void show() // Ŭ������ ���� ���� �� ��ġ�� ���
//	{
//		cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
//	}
//};
//int main()
//{
//	ColorPoint zeroPoint; // BLACK ���� (0,0) ��ġ�� �� // �ƹ��͵� �Է¹��� �ʾ����� ����Ʈ���� Ȯ���ϱ� ���� ��ü
//	zeroPoint.show(); // zeroPoint�� ����Ѵ�.
//
//	ColorPoint cp(5, 5); // x,y���� ������ color�� �� ���ڿ��� ���� ������ (5,5) ��ġ�� color�� ����Ʈ���� BLACK���� �ʱ�ȭ�� ��ü ����
//	cp.setPoint(10, 20); // x,y�� �����ų �Լ� ȣ��
//	cp.setColor("BLUE"); // ���� BLACK���� BLUE�� �����ϱ����� �Լ� ȣ��
//	cp.show(); // ��ü�� ����� �������� ���
//}

////5 // ���Ŭ���� // Queue = first in first out // enqueue, dequeue 
//class BaseArray
//{
//	int capacity; // �迭�� ũ��
//	int* mem; // ���� �迭�� ����� ���� �޸��� ������
//protected: // �Ļ�Ŭ���� ���� ���� // �ܺ�����X
//	BaseArray(int capacity = 100) // ������
//	{
//		this->capacity = capacity;
//		mem = new int[capacity]();
//	}
//	~BaseArray() { delete[] mem; } // �Ҹ��� // ��� ��ҵ��� ������ ������ ���������� ť�� ������ ����Ǿ��ִ� ������ ����
//	void put(int index, int val) { mem[index] = val; } // �Ҵ���� �� �迭������ index�� val�� ����
//	int get(int index) { return mem[index]; } // �Ҵ���� �� �迭������ index�� ���
//	int getCapacity() { return capacity; } // �迭�� ũ�� ���
//};
//class MyQueue : public BaseArray // BaseArrayŬ������ ��ӹ��� �Ļ�Ŭ���� MyQueue
//{
//	int head; // ť�� �Ӹ�
//	int tail; // ť�� ����
//	int size; // ť�� �ִ� ���� ������ ���� ����
//public:
//	MyQueue(int capacity) : BaseArray(capacity) // �Ű������� �Է¹��� ���� ���Ŭ������ �����ڿ� ����
//	{
//		// MyQueue Ŭ������ ����� �ƹ� ���� �����ʰ� ��� 0���� �ʱ�ȭ�Ѵ�.
//		head = 0; // ��� 0���� �ʱ�ȭ
//		tail = 0;
//		size = 0;
//	}
//	void enqueue(int n) // ť�� �Է��� ��
//	{
//		put(tail++, n); // ������ ��ġ�� �Է¹��� ������ �����ϴ� BaseArray���� ��ӹ��� �Լ� put ȣ��
//		// �Լ������� ������ tail�� �� ����
//		size++; // ���� ť�� ���� �󸶸�ŭ �Է¹޾ҳ��� ���
//	}
//	int capacity() // ť�� �� �뷮 ���
//	{
//		return getCapacity(); // BaseArrayŬ������ capacity�� ���� ������ �� ���� ������(private) ����Լ��� �̿��Ѵ�.
//	}
//	int length() // ���� ť�� ����ִ� ���� ���� ���
//	{
//		return size;
//	}
//	int dequeue() // ť�� ���
//	{
//		size--; // �ϳ��ϳ� ���� ��µɶ����� ť�� ����ִ� ���� ������ �پ��� ���� �ǹ�
//		return get(head++); // ó���Է¹޾Ҵ� ������� ���� ���
//	}
//};
//int main()
//{
//	MyQueue mQ(100); // ť�� �� �뷮�� 100���� ����
//	int n; // ť�� �� ���� �Է¹��� ���� ����
//	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> n;
//		mQ.enqueue(n); // ť�� ����
//	}
//	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
//	// ť�� �� �뷮�� ���� ������ �� ť�� ũ�� ���
//	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
//	while (mQ.length() != 0) // ���� ť�� ũ�Ⱑ 0�̶�� �ݺ��� ����
//	{
//		cout << mQ.dequeue() << " "; // ť���� �����Ͽ� ��� // ����Ҷ����� ť�� ũ�� �پ��
//	}
//	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
//	// ��� ���� �������� 0�̵� ť�� ��Ȳ ���
//}

////6 // stack
//class BaseArray
//{
//	int capacity; // �迭�� ũ��
//	int* mem; // ���� �迭�� ����� ���� �޸��� ������
//protected: // �Ļ�Ŭ���� ���� ���� // �ܺ�����X
//	BaseArray(int capacity = 100) // ������
//	{
//		this->capacity = capacity;
//		mem = new int[capacity]();
//	}
//	~BaseArray() { delete[] mem; } // �Ҹ��� // ��� ��ҵ��� ������ ������ ���������� ť�� ������ ����Ǿ��ִ� ������ ����
//	void put(int index, int val) { mem[index] = val; } // �Ҵ���� �� �迭������ index�� val�� ����
//	int get(int index) { return mem[index]; } // �Ҵ���� �� �迭������ index�� ���
//	int getCapacity() { return capacity; } // �迭�� ũ�� ���
//};
//class MyStack : public BaseArray // BaseArrayŬ������ ��ӹ��� �Ļ�Ŭ���� MyStack
//{
//	int stack; // �Է¹ް� ����ؾ��ϴ� ���� ��ġ
//	int size; // ���ÿ� �ִ� ���� ������ ���� ����
//public:
//	MyStack(int capacity) : BaseArray(capacity) // �Ű������� �Է¹��� ���� ���Ŭ������ �����ڷ� ���޵ȴ�.
//	{
//		// MyQueue Ŭ������ ����� �ƹ� ���� �����ʰ� ��� 0���� �ʱ�ȭ�Ѵ�.
//		stack = 0; // ��� 0���� �ʱ�ȭ
//		size = 0;
//	}
//	void push(int n) // ���ÿ� �Է��� ��
//	{
//		put(stack++, n); // �����Ҵ�� �������� �������� ���� ����
//		// �Լ������� ������ stack�� �� ����
//		size++; // ���� ���ÿ� ���� �󸶸�ŭ �ֳ��� ���
//	}
//	int capacity() // ������ �� �뷮 ���
//	{
//		return getCapacity(); // BaseArrayŬ������ capacity�� ���� ������ �� ���� ������ ����Լ��� �̿��Ѵ�.
//	}
//	int length() // ���� ���ÿ� ����ִ� ���� ���� ���
//	{
//		return size;
//	}
//	int pop() // �׿��ִ� ���� ����������(���� ���߿� �� ������) ���Ѵ�
//	{
//		size--; // �ϳ��ϳ� ���� ��µɶ����� ���ÿ� ����ִ� ���� ������ �پ��� ���� �ǹ�
//		return get(--stack); // �ʰ� �� ������� ���� ��� 
//	}
//};
//int main()
//{
//	MyStack mStack(100); // ������ �� �뷮 ����
//	int n; // ���ÿ� �� ���� �Է¹��� ����
//	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> n;
//		mStack.push(n); // �Է¹��� ���� ����Լ��� �̿��� ���ÿ� �������� ����
//	}
//	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
//	// ������ �� �뷮�� ���� ���ÿ� ���� �󸶸�ŭ �׿����� ���
//	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
//	while (mStack.length() != 0) // ������ ũ�Ⱑ 0�� �� ������ �ݺ��� ����
//	{
//		cout << mStack.pop() << ' '; // ���� ���߿� ������ ���ʴ�� ���� ������. // ���� ó���� �� ���� ���� ���߿� ������ �ȴ�. // �Է��� �������� ���
//	}
//	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
//	// ���� ��� �������� ������ ũ�� ���
//}

////8 // �׸��� ������ ��Ȯ�� �����ϵ��� ������ // ����� ���� ���� ����
//class Print
//{
//	string model; // �𵨸�
//	string manufacturer; // ������
//	int printedCount; // �μ� �ż�
//	int availablecount; // �μ� ���� �ܷ�
//protected:
//	Print(string model = NULL, string manufacturer = NULL, int printedCount = 0, int availablecount = 0)
//	{
//		// �𵨸�� ������, �μ������ܷ��� ���޹޾� �ʱ�ȭ�ϴ� ������
//		this->model = model;
//		this->manufacturer = manufacturer;
//		this->printedCount = printedCount;
//		this->availablecount = availablecount;
//	}
//	bool print(int pages) // ����Ʈ�� �ż��� �Է¹�����
//	{
//		printedCount = pages; // �μ�ż��� ���ϴ� printedCount�� �����ϰ�,
//		if (availablecount < printedCount) // ���� ���� �ܷ��� �μ��� �ż����� ������ �켱������ Ȯ���Ѵ�.
//		{
//			return false; // �۴ٸ� �μ� ����
//		}
//		else // �����ʴٸ�
//		{
//			availablecount -= printedCount; // ���� ���� �ܷ����� �μ��� �ż��� ���� �� ����Ʈ������ ǥ����
//			return true; // ����Ʈ�� ���������� �˸�
//		}
//	}
//	// ��� ���
//	void get() { cout << model << " ," << manufacturer << " ,���� ���� " << availablecount << "�� ,"; }
//};
//class InkJetPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� InkJetPrint
//{
//	int availableInk; // ��ũ �ܷ�
//public:
//	InkJetPrint(string model = "Officejet V40", string manufacturer = "HP", int printedCount = 0, int availablecount = 5, int availableInk = 10) : Print(model, manufacturer, printedCount, availablecount) 
//	{
//		// ��ũ���������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//		// �ٸ� �������� ��� �Էµ� �Ŀ� ��ũ �ܷ��� �ʱ�ȭ��
//		this->availableInk = availableInk;
//	}
//	bool printInkJet(int pages) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//	{
//		if (print(pages)) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//		{
//			availableInk -= pages; // pages��ŭ�� ����Ʈ�� �ϱ����� pages��ŭ�� ��ũ�� ��������� �ǹ�
//			return true; // ����Ʈ ����
//		}
//		else // ����Ʈ�� �Ұ����� ��Ȳ�̶��
//		{
//			return false; // ����Ʈ ����
//		}
//	}
//	void getInkJetPrint() { get(); cout << "���� ��ũ " << availableInk << endl; } // ��ũ�� ����Ʈ�� ���� ���
//};
//class LaserPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� LaserPrint
//{
//	int availableToner; // ��� �ܷ�
//public:
//	LaserPrint(string model = "SCX-6x45", string manufacturer = "�Ｚ����", int printedCount = 0, int availablecount = 3, int availableToner = 20) : Print(model, manufacturer, printedCount, availablecount) 
//	{
//		// ������ �������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//		// �ٸ� �������� ��� �Էµ� �Ŀ� ��� �ܷ��� �ʱ�ȭ��
//		this->availableToner = availableToner;
//	}
//	bool printLaser(int pages) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//	{
//		if (print(pages)) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//		{
//			int Toner = pages / 2;
//			availableToner -= Toner; // pages��ŭ�� ����Ʈ�� �ϱ����� pages��ŭ�� ��ʸ� ��������� �ǹ�
//			return true; // ����Ʈ ����
//		}
//		else // ����Ʈ�� �Ұ����� ��Ȳ�̶��
//		{
//			return false; // ����Ʈ ����
//		}
//	}
//	void getLaserPrint() { get(); cout << "���� ��� " << availableToner << endl; }// ������ �������� ���� ���
//};
//int main()
//{
//	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
//	InkJetPrint* p1 = new InkJetPrint; // Print�� �Ļ�Ŭ���� InkJetPrint�� ��ü������ p1 ���� ����
//	LaserPrint* p2 = new LaserPrint; // Print�� �Ļ�Ŭ���� LaserPrint�� ��ü������ p2 ���� ����
//	cout << "��ũ�� : "; p1->getInkJetPrint(); // ��ũ�� �������� �������
//	cout << "������ : "; p2->getLaserPrint(); // ������ �������� �������
//	string s = "y"; // ��� ����Ʈ�� ������ �Ǵ��ϴ� �κп��� �ʿ��� ����
//	int p, pages; // � �����͸� ����� ������, ��ŭ�� ����Ʈ�� �� ������ �Է¹��� ����
//	while (s != "n") // s�� "n"�̶�� �ݺ��� ����
//	{
//		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
//		cin >> p >> pages; // ����� �������� ��ȣ�� �ż��� �Է¹���
//		if (p == 1) // ����� �����Ͱ� ��ũ�� �����Ͷ��
//		{
//			if (p1->printInkJet(pages)) // printInkJet�Լ��� �̿��� ���� �ܷ��� �ż����� ������ // ����Ʈ�� �������� �Ǵ�
//			{
//				cout << "����Ʈ�Ͽ����ϴ�." << endl; // �����ϸ� 
//				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� �� ���� �����͵��� ���� ���
//			}
//			else // �Ұ����ϸ� // ����Ʈ�Ϸ��� �ż����� ���� �ܷ��� ���ٸ� 
//			{
//				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; // �� �� ������ �˸�
//				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� ������ �����͵��� ���� ���
//			}
//		}
//		else // ����� �����Ͱ� ������ �����Ͷ��
//		{
//			if (p2->printLaser(pages)) // printLaser�Լ��� �̿��� ���� �ܷ��� �ż����� ������ // ����Ʈ�� �������� �Ǵ�
//			{
//				cout << "����Ʈ�Ͽ����ϴ�." << endl; // �����ϸ�
//				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� �� ���� �����͵��� ���� ���
//			}
//			else // �Ұ����ϸ� // ����Ʈ�Ϸ��� �ż����� ���� �ܷ��� ���ٸ� 
//			{
//				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; // �� �� ������ �˸�
//				p1->getInkJetPrint(); p2->getLaserPrint(); // ����Ʈ�� ������ �����͵��� ���� ���
//			}
//		}
//		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>"; // ��� �� ���̶��
//		cin >> s; // s�� "y"���� - �ݺ��� �ݺ� // ��� ���ҰŸ� s�� "n"���� - �ݺ��� �ߴ� 
//	}
//	if (p1) // ��ü������ p1�� �Ҵ���� ������ �ִٸ�
//	{
//		delete p1; // p1�� ����Ű�� ������ ������
//		p1 = nullptr; // p1�� �ƹ����� ����Ű�� ������ �ǹ�
//	}
//	if (p2) // ��ü������ p2�� �Ҵ���� ������ �ִٸ�
//	{
//		delete p2; // p2�� ����Ű�� ������ ������
//		p2 = nullptr; // p2�� �ƹ����� ����Ű�� ������ �ǹ�
//	}
//}

//// ��Ǯ�� // ���������� �ľ� ���ϱ�
//class Print
//{
//	string model; // �𵨸�
//	string manufacturer; // ������
//	int printedCount; // �μ� �ż�
//	int availablecount; // �μ� ���� �ܷ�
//public:
//	Print(string model = NULL, string manufacturer = NULL, int availablecount = 0)
//	{
//		// �𵨸�� ������, �μ������ܷ��� ���޹޾� �ʱ�ȭ�ϴ� ������
//		this->model = model;
//		this->manufacturer = manufacturer;
//		this->printedCount = 0;
//		this->availablecount = availablecount;
//	}
//protected:
//	int getPrintCount() { return printedCount; }
//	int getavailablecount() { return availablecount; }
//	void print() // ����Ʈ�� �ż��� �Է¹�����
//	{
//		availablecount--; printedCount++; // ���� ���� �ܷ��� �μ��� �ż����� ������ �켱������ Ȯ���Ѵ�.
//	}
//	// ��� ���
//	void show() { cout << model << " ," << manufacturer << " ,���� ���� " << availablecount << "�� ,"; }
//};
//class InkJetPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� InkJetPrint
//{
//	int availableInk; // ��ũ �ܷ�
//public:
//	InkJetPrint(string model, string manufacturer, int availablecount , int availableInk) : Print(model, manufacturer, availablecount)
//	{
//		// ��ũ���������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//		// �ٸ� �������� ��� �Էµ� �Ŀ� ��ũ �ܷ��� �ʱ�ȭ��
//		this->availableInk = availableInk;
//	}
//	void printInkJet(int pages = 1) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//	{
//		if (getavailablecount() < pages) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//		{
//			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
//			return;
//		}
//		for (int i = 0; i < pages; i++)
//		{
//			print();
//			availableInk--;
//		}
//	}
//	void getInkJetPrint() { show(); cout << "���� ��ũ " << availableInk << endl; } // ��ũ�� ����Ʈ�� ���� ���
//};
//class LaserPrint : public Print // ���Ŭ���� Print�� ��ӹ��� �Ļ�Ŭ���� LaserPrint
//{
//	int availableToner; // ��� �ܷ�
//public:
//	LaserPrint(string model, string manufacturer, int availablecount, int availableToner) : Print(model, manufacturer, availablecount)
//	{
//		// ������ �������� �𵨸�, ������, �μ������ܷ� ������ Print�����ڿ� ����
//		// ���Ŭ������ �����ڰ� ����Ǹ� �� �� �Ļ�Ŭ������ �����ڰ� ����Ǳ⶧����
//		// �ٸ� �������� ��� �Էµ� �Ŀ� ��� �ܷ��� �ʱ�ȭ��
//		this->availableToner = availableToner;
//	}
//	void printLaser(int pages = 1) // �Է¹��� pages��ŭ ����Ʈ�ϴ� ����Լ�
//	{
//		if (getavailablecount() < pages) // ���Ŭ������ ����Լ� ȣ�� // ����Ʈ�� �����ߴٸ�
//		{
//			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
//			return;
//		}
//		for (int i = 0; i < pages; i++)
//		{
//			print();
//			availableToner--;
//		}
//	}
//	void getLaserPrint() { show(); cout << "���� ��� " << availableToner << endl; }// ������ �������� ���� ���
//};
//int main()
//{
//	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
//	InkJetPrint* p1 = new InkJetPrint("Officejet V40","HP",  5, 10); // Print�� �Ļ�Ŭ���� InkJetPrint�� ��ü������ p1 ���� ����
//	LaserPrint* p2 = new LaserPrint("SCX-6x45","�Ｚ����", 3, 20); // Print�� �Ļ�Ŭ���� LaserPrint�� ��ü������ p2 ���� ����
//	cout << "��ũ�� : "; p1->getInkJetPrint(); // ��ũ�� �������� �������
//	cout << "������ : "; p2->getLaserPrint(); // ������ �������� �������
//	string s = "y"; // ��� ����Ʈ�� ������ �Ǵ��ϴ� �κп��� �ʿ��� ����
//	int p, pages; // � �����͸� ����� ������, ��ŭ�� ����Ʈ�� �� ������ �Է¹��� ����
//	while (true) // s�� "n"�̶�� �ݺ��� ����
//	{
//		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
//		cin >> p >> pages; // ����� �������� ��ȣ�� �ż��� �Է¹���
//		switch (p)
//		{
//		case 1:
//			p1->printInkJet(pages);
//			break;
//		case 2:
//			p2->printLaser(pages);
//			break;
//		default:
//			cout << "�߸��� �Է��Դϴ�." << endl;
//			continue;
//		}
//		p1->getInkJetPrint();
//		p2->getLaserPrint();
//		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>"; // ��� �� ���̶��
//		cin >> s; // s�� "y"���� - �ݺ��� �ݺ� // ��� ���ҰŸ� s�� "n"���� - �ݺ��� �ߴ� 
//		if (s == "y")
//			continue;
//		else
//			break;
//	}
//	if (p1) // ��ü������ p1�� �Ҵ���� ������ �ִٸ�
//	{
//		delete p1; // p1�� ����Ű�� ������ ������
//		p1 = nullptr; // p1�� �ƹ����� ����Ű�� ������ �ǹ�
//	}
//	if (p2) // ��ü������ p2�� �Ҵ���� ������ �ִٸ�
//	{
//		delete p2; // p2�� ����Ű�� ������ ������
//		p2 = nullptr; // p2�� �ƹ����� ����Ű�� ������ �ǹ�
//	}
//}