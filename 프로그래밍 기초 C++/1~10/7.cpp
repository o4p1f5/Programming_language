#include <iostream>
using namespace std;

////1 // c1 c2 �� �ٲٱ�
//class Circle // Circle Ŭ����
//{
//	int radius;
//public:
//	Circle() { radius = 1;}
//	Circle(int radius) { this->radius = radius;}
//	double getArea()
//	{
//		return 3.14 * radius * radius;
//	}
//	int getRadius()
//	{
//		return radius;
//	}
//};
//
//void swap(Circle& n1, Circle& n2) // �� ��ü�� ������ ���� ȣ���� ������ ������ ���� ����
//{
//	Circle tmp = n1; // ���� ������� ��ü�� n1�� �����ϰ�
//	n1 = n2; // n1�� n2�� ����
//	n2 = tmp; // �Ʊ� ����� n1�� �ٽ� n2�� �����ؼ� �� ��ü�� ���� ��ȯ
//}
//
//int main()
//{
//	int n(0), m(0); // �� ���� �������� �Է¹ޱ� ���� ���� �ΰ� ����
//	cout << "�� ���� ������ �� �Է� >> "; // �� ���� �������� �Է¹���
//	cin >> n >> m;
//	Circle c1(n), c2(m); // �Է¹��� ���������� c1, c2�� ���ʷ� ����
//	cout << "���� �� ������ �� ��� " << c1.getRadius() << " " << c2.getRadius() << endl;
//	// swap�Լ��� ������ �� �� ��ü�� �������� ���
//	swap(c1, c2); // �� ��ü�� ��ȯ��
//	cout << "���� �� ������ �� ��� " << c1.getRadius() << " " << c2.getRadius() << endl;
//	// swap�Լ��� ���� �� �� ��ü�� �������� ���
//}

////2 // �Լ����� ��ȯ�����ʾƵ� ���� ����Ǿ���Ѵ�
//// void half(int & n)
//void half(double& n) // ���� n�� �ݰ��� ���ϱ� ���� ������ ���� ȣ���� �� �Լ�
//{
//	n = n / 2.0; // n�� ���� 2�� ���� ���� n�� ����
//}
//int main()
//{
//	double n = 20; // �Ǽ��� ���� n�� ���� 20.0���� �ʱ�ȭ
//	half(n); // n�� ���� ������ ���� ������
//	cout <<  n; // n�� �ݰ��� ���
//}

////3 // test 1, text 2�� ���ļ� text3�� ����
//// �ؽ�Ʈ 1,2 �� ���� ���� ���� �ؽ�Ʈ 3�� ��������
//void combine(string s1, string s2, string& s3) // text1,text2�� ���� ���� ������ �ϰ� text3�� ������ ���� ������
//{
//	s3 = s1 + " " + s2; // �� ���ڿ��� ���� ���� text3�� ������ �����ϴ� s3�� ����
//}
//int main()
//{
//	string text1("I love you"), text2 = ("very much"); // string��ü text1�� string��ü text2�� �ʱ�ȭ
//	string text3; // string��ü text3 �⺻����
//	combine(text1, text2, text3); // combine �Լ� ȣ��
//	cout << text3; // "I love you wery much" ���
//}

////4 // ���
//bool bigger(int a, int b, int& big) // x ,y ���� ���� ���� �����ϰ� big�� ������ ���� ������
//{
//	if (a == b) // a�� b�� ���ٸ�
//	{
//		return true; // true��ȯ
//	}
//	else // ���� �ʴٸ�
//	{
//		if (a > b) // a�� b���� ũ�ٸ�
//		{
//			big = a; // big�� a ����
//		}
//		else // b�� a���� ũ�ٸ�
//			big = b; // big�� b ����
//		return false; // false ��ȯ
//	}
//}
//int main()
//{
//	int x, y, big; // �� ������ �ޱ� ���� ���� x, y �� ū���� �ޱ� ���� big ����
//	bool b; // �� ���� ������ �Ǵ��� �ޱ� ���� �� ���� ����
//	cout << "�� ������ �Է��ϼ���>> ";
//	cin >> x >> y; // �� ������ �Է¹���
//	b = bigger(x, y, big); // �� ���� ���ٸ� true�� ��ȯ�ǰ� �ٸ��ٸ� false�� ��ȯ��
//	if (b) // true�� ��ȯ�ƴٸ�
//		cout << "same" << endl; // �� ���� ���ٴ� ������ same ���
//	else // false�� ��ȯ�ƴٸ�
//		cout << "ū ���� " << big << endl; // �� ���� �ٸ��ٴ� �������� ����ƴ� big �� ���
//}

////5 // Ŭ������ �����ϰԲ� ����
//class Circle // CIrcle Ŭ����
//{
//	int radius;
//public:
//	Circle(int r) { radius = r; }
//	int getRadius() { return radius; }
//	void setRadius(int r) { radius = r; }
//	void show() { cout << "�������� " << radius << "�� ��" << endl; }
//};
//void increaseBy(Circle& a, Circle b) // ��ü x�� ������ ���� ���޷� a�� ������ �����ϰ� �ϰ�
//// ��ü y�� ���� ���� ���� ���޹���
//{
//	int r = a.getRadius() + b.getRadius(); // a�� ��, x�� �������� b�� �������� ���� ���� r�� ����
//	a.setRadius(r); // ��ü a�� �������� r�� ����
//}
//int main()
//{
//	Circle x(10), y(5); // ��ü x�� y�� ���� 10�� 5�� �ʱ�ȭ
//	increaseBy(x, y); // x ��ü�� ������ ���� �����ϰ� y��ü�� ���� ���� ������
//	x.show(); // x ��ü�� �������� ����Լ� show()�� ���
//}