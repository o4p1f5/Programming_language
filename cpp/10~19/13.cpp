#include <iostream>
using namespace std;

// �������̵� // �߻�Ŭ���� - ��ü�� ���� �� ����

////1 
//class Converter // ���������Լ��� ���� �߻�Ŭ���� - ��ü���� �� ����
//{
//protected:
//	double ratio;
//	virtual double convert(double src) = 0; // src�� �ٸ� ������ ��ȯ�Ѵ�. // �����Լ�
//	virtual string getSourceString() = 0; // src ���� ��Ī // �����Լ�
//	virtual string getDestString() = 0; // dest ���� ��Ī // �����Լ�
//public:
//	Converter(double ratio) {this->ratio = ratio;} // ConverterŬ������ ������
//	void run() // ���â�� �����ϴ� ������� ��� �ִ� �Լ�
//	{
//		double src; // ��ȯ������ �ϴ� ���� �޴� ��������
//		// �����Լ��� ȣ���ϸ� �Ļ�Ŭ������ �������̵��� �Լ��� ȣ��
//		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
//		// ��ȯ ���� ���� �̸��� getSourceString()�� �̿��� ����ϰ�
//		// ��ȯ ���� ���� �̸��� getDestString()�� �̿��� ����Ѵ�
//		cout << getSourceString() << "�� �Է��ϼ���>> ";
//		cin >> src; // ��ȯ�ϰ��� �ϴ� ���� �Է��ϸ�
//		cout << "��ȯ ��� :" << convert(src) << getDestString() << endl; 
//		// convert�Լ��� �Ѱ��� ��ȯ�Ѵ� // �̶� �⺻Ŭ������ ���������Լ��� ���� �߻�Ŭ�����̱⶧���� �Ļ�Ŭ������ �������̵��� �Լ��� �����Ѵ�
//	}
//};
//class WonToDollar : public Converter // ConverterŬ������ ��ӹ��� �Ļ�Ŭ����
//{
//public:
//	WonToDollar(double ratio) : Converter(ratio)// �����Ϸ��� �ڵ����� Converter�� �⺻������ ȣ��
//	{
//		// WonToDollar�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	// �����Լ��� �������̵����������� �߻�Ŭ������ ��ӹ��� �Ļ�Ŭ������ �߻�Ŭ������ �ż� ��ü�� ������ �� ����.
//	// �������̵��Ҷ��� virtual ����
//	virtual double convert(double src) // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		// 1�޷� = 1010�� // �Է¹��� ���� ������ ��ȯ�ϴ� �Լ��� ������
//		return src / ratio;
//	}
//	virtual string getSourceString() // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		return "��"; // ��ȯ�Ǳ����� ������ ��Ī�� ��ȯ�ϴ� �Լ��� ������
//	}
//	virtual string getDestString() // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		return "�޷�"; // ��ȯ�� ������ ��Ī�� ��ȯ�ϴ� �Լ��� ������
//	}
//};
//int main()
//{
//	WonToDollar wd(1010); // �߻�Ŭ������ ��ӹ��� �Ļ�Ŭ������ �߻�Ŭ������ �ȴ� -> �����Լ��� �������ϸ� �ذ��
//	wd.run(); // ���Ŭ������ run ȣ�� // pubic�̶� ���� ����
//}

////2 // 1�� �̿�
//class Converter
//{
//protected:
//	double ratio;
//	virtual double convert(double src) = 0; // src�� �ٸ� ������ ��ȯ�Ѵ�. // �����Լ�
//	virtual string getSourceString() = 0; // src ���� ��Ī // �����Լ�
//	virtual string getDestString() = 0; // dest ���� ��Ī // �����Լ�
//public:
//	Converter(double ratio) { this->ratio = ratio; } // ConverterŬ������ ������
//	void run() // ���â�� �����ϴ� ������� ��� �ִ� �Լ�
//	{
//		double src; // ��ȯ������ �ϴ� ���� �޴� ��������
//		// �����Լ��� ȣ���ϸ� �Ļ�Ŭ������ �������̵��� �Լ��� ȣ��
//		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
//		// ��ȯ ���� ���� �̸��� getSourceString()�� �̿��� ����ϰ�
//		// ��ȯ ���� ���� �̸��� getDestString()�� �̿��� ����Ѵ�
//		cout << getSourceString() << "�� �Է��ϼ���>> ";
//		cin >> src; // ��ȯ�ϰ��� �ϴ� ���� �Է��ϸ�
//		cout << "��ȯ ��� :" << convert(src) << getDestString() << endl;
//		// convert�Լ��� �Ѱ��� ��ȯ�Ѵ� // �̶� �⺻Ŭ������ ���������Լ��� ���� �߻�Ŭ�����̱⶧���� �Ļ�Ŭ������ �������̵��� �Լ��� �����Ѵ�
//	}
//};
//class KmToMile : public Converter // ConverterŬ������ ��ӹ��� �Ļ�Ŭ����
//{
//public:
//	KmToMile(double ratio) : Converter(ratio)// �����Ϸ��� �ڵ����� Converter�� �⺻������ ȣ��
//	{
//		// KmToMile�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	// �����Լ��� �������̵����������� �߻�Ŭ������ ��ӹ��� �Ļ�Ŭ������ �߻�Ŭ������ �ż� ��ü�� ������ �� ����.
//	// �������̵��Ҷ��� virtual ����
//	virtual double convert(double src) // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		// 1mile�� 1.609344km // �Է¹��� ���� ������ ��ȯ�ϴ� �Լ��� ������
//		return src / ratio;
//	}
//	virtual string getSourceString() // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		return "Km"; // ��ȯ�Ǳ����� ������ ��Ī�� ��ȯ�ϴ� �Լ��� ������
//	}
//	virtual string getDestString() // �߻�Ŭ������ �����Լ� �������̵�
//	{
//		return "Mile"; // ��ȯ�� ������ ��Ī�� ��ȯ�ϴ� �Լ��� ������
//	}
//};
//int main()
//{
//	KmToMile toMile(1.609344);
//	toMile.run();
//}

//////3
//class LoopAdder // �߻�Ŭ����
//{
//	string name; // ������ �̸�
//	int x, y, sum; // x���� y������ ���� sum
//	void read(); // x,y ���� �о� ���̴� �Լ�
//	void write(); // sum�� ����ϴ� �Լ�
//protected:
//	LoopAdder(string name = "") // ������ �̸��� �޴´�. �ʱ갪�� ""
//	{
//		this->name = name;
//		x = 0; y = 0; sum = 0;
//	}
//	int getX() { return x; }
//	int getY() { return y; }
//	virtual int calculate() = 0; // ���������Լ�, ������ ���� ���� ���ϴ� �Լ�
//public :
//	void run(); // ������ �����ϴ� �Լ�
//};
//void LoopAdder::read() // x,y �Է�
//{
//	cout << name << ":" << endl;
//	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
//	cin >> x >> y;
//}
//void LoopAdder::write() // ��� sum ���
//{
//	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�." << endl;
//}
//void LoopAdder::run()
//{
//	read(); // x,y�� �д´�.
//	sum = calculate(); // �Ļ�Ŭ������ calculate ȣ�� // �̶� sum�� LoopAdder�� �������
//	// ������ ���鼭 ����Ѵ�.
//	write(); // ��� sum�� ����Ѵ�.
//}
//class ForLoopAdder : public LoopAdder
//{
//public:
//	ForLoopAdder(string name) : LoopAdder(name) {} 
//	int calculate()
//	{
//		int sum = 0; // �̶� sum�� ��������
//		for (int i = getX(); i <= getY(); i++)
//		{
//			sum += i;
//		}
//		return sum;
//	}
//};
//int main()
//{
//	ForLoopAdder forLoop("For Loop");
//	forLoop.run();
//}

////4 // 3���� while, do while�� �ٲٱ�
//class LoopAdder // �߻�Ŭ����
//{
//	string name; // ������ �̸�
//	int x, y, sum; // x���� y������ ���� sum
//	void read(); // x,y ���� �о� ���̴� �Լ�
//	void write(); // sum�� ����ϴ� �Լ�
//protected:
//	LoopAdder(string name = "") // ������ �̸��� �޴´�. �ʱ갪�� ""
//	{
//		this->name = name;
//		x = 0; y = 0; sum = 0;
//	}
//	int getX() { return x; }
//	int getY() { return y; }
//	virtual int calculate() = 0; // ���������Լ�, ������ ���� ���� ���ϴ� �Լ�
//public:
//	void run(); // ������ �����ϴ� �Լ�
//};
//void LoopAdder::read() // x,y �Է�
//{
//	cout << name << ":" << endl;
//	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
//	cin >> x >> y;
//}
//void LoopAdder::write() // ��� sum ���
//{
//	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�." << endl;
//}
//void LoopAdder::run()
//{
//	read(); // x,y�� �д´�.
//	sum = calculate(); // run�Լ��� ȣ���� ��ü�� �Ļ�Ŭ������ calculate ȣ�� // �̶� sum�� LoopAdder�� �������
//	// ������ ���鼭 ����Ѵ�.
//	write(); // ��� sum�� ����Ѵ�.
//}
//class WhileLoopAdder : public LoopAdder // �����Լ��� �������̵� -> while �ݺ���
//{
//public:
//	WhileLoopAdder(string name) : LoopAdder(name) {} // ������
//	// �Է¹��� ���ڿ��� �߻�Ŭ������ �����ڿ� �����ϴ� ����
//	int calculate()
//	{
//		int sum = 0; // �̶� sum�� ��������
//		int i = getX(); // x�� i�� ����
//		while (i <= getY()) // i�� y�� �Ǳ������� while�� �ݺ���
//		{
//			sum += i; // ���� sum�� i�� ���� �� sum�� ����
//			i++; // i�� + 1
//		}
//		return sum; // x ~ y���� ���� ���� ��ȯ
//	}
//};
//class DowhileLoopAdder : public LoopAdder // �����Լ��� �������̵� -> do - while �ݺ���
//{
//public:
//	DowhileLoopAdder(string name) : LoopAdder(name) {}
//	// �Է¹��� ���ڿ��� �߻�Ŭ������ �����ڿ� �����ϴ� ����
//	int calculate()
//	{
//		int sum = 0; // �̶� sum�� ��������
//		int i = getX(); // x�� i�� ����
//		do{ 
//			sum += i; // ���� sum�� i�� ���� �� sum�� ����
//			i++; // i�� + 1
//		} while (i <= getY()); // i�� y�� �Ǳ������� do - while�� �ݺ���
//		return sum; // x ~ y���� ���� ���� ��ȯ
//	}
//};
//int main()
//{
//	WhileLoopAdder whileLoop("While Loop"); // while�� ������ Ŭ����
//	DowhileLoopAdder dowhileLoop("Do while Loop"); // do-while�� ������ Ŭ����
//
//	whileLoop.run();
//	dowhileLoop.run();
//}//

////5 // and = && // or = || // xor = ^(��Ʈ ������ - �̶� bool�� �ڷ����� ����ؾ� xor�� ����� ��)
//class AbstractGate // �߻����Ʈ
//{
//protected:
//	bool x, y; // �Ļ�Ŭ������ ���� ����
//public:
//	void set(bool x, bool y) { this->x = x; this->y = y; }
//	virtual bool operation() = 0; // �����Լ� - �������̵��ʿ� // �����Լ�
//};
//class ANDGate : public AbstractGate // ����Ʈ�� AND������ �����ϴ� Ŭ����
//{
//public:
//	bool operation() // ���� // �������̵� �Լ�
//	{
//		//if (x && y) // AND ����
//		//	return true; // ��� 1 �϶� true ��ȯ
//		//else
//		//	return false; // �ƴϸ� false ��ȯ
//		return x && y;
//	}
//};
//class ORGate : public AbstractGate // ����Ʈ�� OR������ �����ϴ� Ŭ����
//{
//public:
//	bool operation() // ���� // �������̵� �Լ�
//	{
//		//if (x || y) // OR ����
//		//	return true; // 1�� �ϳ��� �ִٸ� true ��ȯ
//		//else
//		//	return false;
//		return x || y;
//	}
//};
//class XORGate : public AbstractGate // ����Ʈ�� XOR������ �����ϴ� Ŭ����
//{
//public:
//	bool operation() // ���� // �������̵� �Լ�
//	{
//		//if (x ^ y) // ��Ʈ ������ - bool�� �ڷ����� ����ϸ� xor�� ����� ��)
//		//	return true; // 1�� Ȧ�� �� �ִ� ���
//		//else
//		//	return false;
//		return x ^ y;
//	}
//};
//int main()
//{
//	ANDGate andGate; // AND ��� Ŭ������ ��ü
//	ORGate orGate; // OR ��� Ŭ������ ��ü
//	XORGate xorGate; // XOR ��� Ŭ������ ��ü
//
//	andGate.set(true, false); // ��ü�� x,y�� 0,1 ����
//	orGate.set(true, false); // ��ü�� x,y�� 0,1 ����
//	xorGate.set(true, false); // ��ü�� x,y�� 0,1 ����
//	cout.setf(ios::boolalpha); // �Ҹ� ���� "true", "flase" ���ڿ��� ����� ���� ����
//	cout << andGate.operation() << endl; // x,y�� AND ����� false
//	cout << orGate.operation() << endl; //  x,y�� OR ����� true
//	cout << xorGate.operation() << endl; // x,y�� XOR ����� true
//}

////7 // ���������Լ��� �ƴ� �����Լ� // �������̵�
//class Shape // ������ �׸��� ��� Ŭ���� // ���������Լ��� �������ʾ����Ƿ� �߻�Ŭ������ �ƴϴ�
//{
//protected:
//	string name; // ������ �̸�
//	int width, height; // ������ �����ϴ� �簢���� �ʺ�� ����
//public:
//	Shape(string n = "", int w = 0, int h = 0) { name = n, width = w; height = h; }
//	// ��� Ŭ������ ������
//	virtual double getArea() { return 0; } // ������ ���̴� ���ϴ� �Լ��� �����Լ��� ����� 
//	// �Լ��� ȣ���Ų ��ü�� Ŭ������ �������̵��� �Լ��� �����Ѵ�
//	string getName() { return name; } // �̸��� ��ȯ�ϴ� �Լ�
//};
//class Oval : public Shape // Shape�� ��ӹ޴� Ÿ�� Ŭ����
//{
//public:
//	Oval(string n, int w, int h) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Oval�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // Ÿ���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height * 3.14;
//	}
//};
//class Rect : public Shape // Shape�� ��ӹ޴� ���簢�� Ŭ����
//{ 
//public:
//	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Rect�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // ���簢���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height;
//	}
//};
//class Triangular : public Shape // Shape�� ��ӹ޴� �ﰢ�� Ŭ����
//{
//public:
//	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Triangular�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // �ﰢ���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height * 0.5;
//	}
//};
//int main()
//{
//	Shape* p[3]; // ���Ŭ������ �����͹迭
//	p[0] = new Oval("��붱", 10, 20); // ��ĳ���� // p[0]�� �ڷ����� Oval�� ������ ����� ���� ����
//	p[1] = new Rect("����", 30, 40); // ��ĳ���� // p[1]�� �ڷ����� Rect�� ������ ����� ���� ����
//	p[2] = new Triangular("�佺Ʈ", 30, 40); // ��ĳ���� // p[2]�� �ڷ����� Triangular�� ������ ����� ���� ����
//	for (int i = 0; i < 3; i++)
//		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
//	// p[i]->getName() �� ���Ŭ������ �Լ��� ȣ��
//	// p[i]->getArea()�� �� �ڷ����� �������̵��� �Լ� ȣ��
//	for (int i = 0; i < 3; i++) delete p[i]; // �����Ҵ�� p[i]�� ���� ����
//}

////8 // 7������ �����Լ��� ���������Լ��� ����� ��
//class Shape // ������ �׸��� ��� Ŭ���� // ���������Լ��� ���� �߻�Ŭ����
//{
//protected:
//	string name; // ������ �̸�
//	int width, height; // ������ �����ϴ� �簢���� �ʺ�� ����
//public:
//	Shape(string n = "", int w = 0, int h = 0) { name = n, width = w; height = h; }
//	// ��� Ŭ������ ������
//	virtual double getArea() = 0; // ������ ���̴� ���ϴ� �Լ��� ���������Լ��� ����� 
//	string getName() { return name; } // �̸��� ��ȯ�ϴ� �Լ�
//};
//class Oval : public Shape // Shape�� ��ӹ޴� Ÿ�� Ŭ����
//{
//public:
//	Oval(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Oval�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // Ÿ���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height * 3.14;
//	}
//};
//class Rect : public Shape // Shape�� ��ӹ޴� ���簢�� Ŭ����
//{
//public:
//	Rect(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Rect�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // ���簢���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height;
//	}
//};
//class Triangular : public Shape // Shape�� ��ӹ޴� �ﰢ�� Ŭ����
//{
//public:
//	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h)// �����Ϸ��� �ڵ����� Shape�� �⺻������ ȣ��
//	{
//		// Triangular�� ������� X , ������ ��� X -> ���Ŭ������ ������
//	}
//	double getArea() // �ﰢ���� ���̸� ���ϴ� �Լ��� ���Ŭ������ �����Լ� �������̵�
//	{
//		return (double)width * (double)height * 0.5;
//	}
//};
//int main()
//{
//	Shape* p[3]; // ���Ŭ������ �����͹迭
//	p[0] = new Oval("��붱", 10, 20); // ��ĳ���� // p[0]�� �ڷ����� Oval�� ������ ����� ���� ����
//	p[1] = new Rect("����", 30, 40); // ��ĳ���� // p[1]�� �ڷ����� Rect�� ������ ����� ���� ����
//	p[2] = new Triangular("�佺Ʈ", 30, 40); // ��ĳ���� // p[2]�� �ڷ����� Triangular�� ������ ����� ���� ����
//	for (int i = 0; i < 3; i++)
//		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
//	// p[i]->getName() �� ���Ŭ������ �Լ��� ȣ��
//	// p[i]->getArea()�� �� �ڷ����� �������̵��� �Լ� ȣ��
//	for (int i = 0; i < 3; i++) delete p[i]; // �����Ҵ�� p[i]�� ���� ����
//}