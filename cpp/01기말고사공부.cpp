#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#pragma warning (disable : 4996)
using namespace std;

//////1-1
////int main()
////{
////	int a, b;
////	cout << "���� �ΰ� �Է� :";
////	cin >> a >> b;
////	cout << a << " + " << b << " = " << a + b << endl;
////	cout << a << " - " << b << " = " << a - b << endl;
////	cout << a << " X " << b << " = " << a * b << endl;
////	return 0;
////}
//
//////1-2
////double FtoC(double n1)
////{
////	double n2 = 0;
////	n2 = 5.0 / 9.0 * (n1 - 32);
////	return n2;
////}
////double CtoF(double n1)
////{
////	double n2 = 0;
////	n2 = (n1 * (9.0 / 5.0)) + 32.0;
////	return n2;
////}
////int main()
////{
////	double n1,n2;
////	cout << "ȭ�� �µ� �Է� :";
////	cin >> n1;
////	cout << "ȭ�� �µ� " << n1 << "�� �����µ� " << FtoC(n1) << " �̴�." << endl;
////
////	cout << "���� �µ� �Է� :";
////	cin >> n2;
////	cout << "���� �µ� " << n2 << "�� ȭ���µ� " << CtoF(n2) << " �̴�.";
////	return 0;
////}
//
//////1-3
////double CmToInch(double n1)
////{
////	double n2;
////	n2 = n1 / 2.54;
////	return n2;
////}
////double InchToCm(double n1)
////{
////	double n2;
////	n2 = n1 * 2.54;
////	return n2;
////}
////int main()
////{
////	double n1, n2;
////	cout << "���� �Է�(cm) :";
////	cin >> n1;
////	cout << n1 << " Cm�� " << CmToInch(n1) << " Inch" << endl;
////
////	cout << "���� �Է�(inch) :";
////	cin >> n2;
////	cout << n2 << " Inch�� " << InchToCm(n2) << " Cm" << endl;
////}
//
//////1-4
////int main()
////{
////	double n1, n2;
////	cout << "���� �ﰢ���� �غ��� ���̸� �Է� :";
////	cin >> n1 >> n2;
////	double root = sqrt((n1*n1)+(n2*n2));
////	cout << "�غ� " << n1 << " ���� " << n2 << "�� ���� �ﰢ���� ������ " << root << " �Դϴ�.";
////}
//
//////1-5
////int main()
////{
////	int num[20] = { 1,2,3,4,5,0,2,4,7,8,6,8,3,6,9,3,2,5,3,8 };
////	int cnt[10] = {};
////	for (int i = 0; i < 20; i++)
////	{
////		cnt[num[i]]++;
////	}
////	for (int i = 0; i < 10; i++)
////	{
////		cout << "���� " << i << "�� " << cnt[i] << "��" << endl;
////	}
////}

////// 2-3
////int main()
////{
////	int a, b;
////	cout << "�� ���� �Է��϶�>>";
////	cin >> a >> b;
////	cout << "ū �� = ";
////	if (a > b)
////		cout << a;
////	else if (a < b)
////		cout << b;
////	else
////		cout << "����. �� ���� ����";
////}
//
////// 2-4
////int main()
////{
////	double num[5] = {};
////	double max;
////	cout << "5 ���� �Ǽ��� �Է��϶�>>";
////	for (int i = 0; i < 5; i++)
////	{
////		cin >> num[i];
////	}
////	max = num[0];
////	for (int i = 0; i < 5; i++)
////	{
////		if (num[i] > max)
////			max = num[i];
////	}
////	cout << "���� ū �� = " << max;
////}
//
//////2-5 Hexadecimal x-exe y-axe
////int main()
////{
////	char num[100] = {};
////	int cnt = 0;
////	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
////	cin.getline(num, 100, '\n');
////	for (int i = 0; i < 100; i++)
////	{
////		if (num[i] == 'x')
////			cnt++;
////	}
////	cout << "x�� ������ " << cnt;
////}
//
//////2-5' Hexadecimal x-exe y-axe
////int main()
////{
////	string str;
////	int cnt = 0;
////	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
////	getline(cin, str, '\n');
////	for (int i = 0; i < (int)str.size(); i++)
////	{
////		if (str[i] == 'x')
////			cnt++;
////	}
////	cout << "x�� ������ " << cnt;
////}
//
//////2-7
////int main()
////{
////	char num[100] = {};
////	while (1)
////	{
////		cout << "�����ϰ������ yes�� �Է��ϼ���>>";
////		cin.getline(num, 100, '\n');
////		if (!strcmp(num, "yes")) // �Է¹��� ���ڿ��� "yes" �� ���ٸ� 0���, ���ǹ��� !�� �پ��⶧���� true�� ���
////		{
////			cout << "�����մϴ�..."; // ���ٸ� �����մϴ�... ��� �� while���� ��������
////			break;
////		}
////	}
////}
//
//////2-7'
////int main()
////{
////	string str;
////	while (1)
////	{
////		cout << "�����ϰ������ yes�� �Է��ϼ���>>";
////		getline(cin, str, '\n');
////		if (str == "yes") // �Է¹��� ���ڿ��� "yes" �� ���ٸ� 0���, ���ǹ��� !�� �پ��⶧���� true�� ���
////		{
////			cout << "�����մϴ�..."; // ���ٸ� �����մϴ�... ��� �� while���� ��������
////			break;
////		}
////	}
////}
//
//////2-8
////int main()
////{
////	char num[100] = {};
////	char str[100] = { 0 };
////	cout << "5 ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";
////	for (int i = 0; i < 5; i++) // 5���� �̸��� �Է¹ް� ���� �� �̸��� ã�Ƴ� �ݺ���
////	{
////		cin.getline(num, 100, ';'); // �Է¹��� ���ڿ��� ���ʴ�� str1�� ����, �����ڴ� ;
////		if (strlen(num) > strlen(str)) // str1�� ���̿� str2�� ���̸� ���� �� str1�� ���̰� ��ٸ�
////		{
////			strcpy(str, num); // str1�� ���ڿ��� str2�� ����
////		}
////		cout << i + 1 << " : " << num << endl; // �Է¹��� �̸����� ���
////	}
////	cout << "���� �� �̸��� " << str; // ���� �� �̸��� ���
////}
//
//////2-8'
////int main()
////{
////	string num;
////	string str;
////	cout << "5 ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";
////	for (int i = 0; i < 5; i++) // 5���� �̸��� �Է¹ް� ���� �� �̸��� ã�Ƴ� �ݺ���
////	{
////		getline(cin, num, ';'); // �Է¹��� ���ڿ��� ���ʴ�� str1�� ����, �����ڴ� ;
////		if (num.size() > str.size()) // str1�� ���̿� str2�� ���̸� ���� �� str1�� ���̰� ��ٸ�
////		{
////			str = num; // str1�� ���ڿ��� str2�� ����
////		}
////		cout << i + 1 << " : " << num << endl; // �Է¹��� �̸����� ���
////	}
////	cout << "���� �� �̸��� " << str; // ���� �� �̸��� ���
////}
//
//////2-10
////int main()
////{
////	char str[100] = {};
////	cout << "���ڿ� �Է� >>";
////	cin.getline(str, 100);
////	for (int i = 0; i < (int)strlen(str); i++)
////	{
////		for (int j = 0; j <= i; j++)
////			cout << str[j];
////		cout << endl;
////	}
////}
//
//////2-10'
////int main()
////{
////	string str;
////	cout << "���ڿ� �Է� >>";
////	getline(cin, str);
////	for (int i = 0; i < (int)str.size(); i++)
////	{
////		for (int j = 0; j <= i; j++)
////			cout << str[j];
////		cout << endl;
////	}
////}

//3-1
class Tower
{
	int Height;
	double* real;
	double* imag;
public:
	Tower(int n=0,double rm=0,double im=0) 
	{
		Height = n; 
		real = new double;
		*real = rm;
		imag = new double;
		*imag = im;
	}
	Tower(Tower& op)
	{
		Height = op.Height;
		real = new double;
		*real = *(op.real);
		imag = new double;
		*imag = *(op.imag);
	}
	int getHeight() { return  Height; }
};
int main()
{
	Tower myTower;
	Tower seoulTower(100);
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}