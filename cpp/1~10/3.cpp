#include <iostream>                           
#include <string>      
#include <cstdlib>  // #include <stdlib.h> // ���а����Լ� - ��  = > ���� -> stdlib
#include <ctime>    // #include <time.h>
#pragma warning (disable : 4996)               
using namespace std;
// �⺻������ ����ȭ

////1
//class Tower // Tower Ŭ���� ����
//{
//private: // ������ ����
//	int height; // �������
//public: // ����
//	Tower(); // �⺻������
//	Tower(int h); // ������ �Ű����� �ϳ��� �޴� ������
//	int getHeight(); // ���̸� ȣ���ϴ� ����Լ�
//};
//Tower::Tower() // �⺻ ������
//{
//	height = 1; // ��������� 1�� �ʱ�ȭ
//}
//Tower::Tower(int h) // �Ű������� �ִ� ������
//{
//	height = h; // ��������� �Է¹��� h�� �ʱ�ȭ
//}
//int Tower::getHeight() // ���̸� �˸��� ����Լ� ����
//{
//	return height; // ���̸� ��ȯ
//}
//int main() 
//{
//	Tower myTower; // �����ڸ� ���� height���� 1�� �ʱ�ȭ�� ��ü
//	Tower seoulTower(100); // �����ڸ� ���� height���� 100���� �ʱ�ȭ�� ��ü
//	cout << "���̴� " << myTower.getHeight() << "����" << endl; // ��ü myTower�� ����Լ��� ȣ���ϸ鼭 ���̰� ���� �˸�
//	cout << "���̴� " << seoulTower.getHeight() << "����" << endl; // ��ü seoulTower�� ����Լ��� ȣ���ϸ鼭 ���̰� ���� �˸�
//}

////2 // class Date // ������(�� �� ��)// show �Լ� // ������� ��� �Լ�
//class Date // Date Ŭ���� ����
//{
//private: // ������ ����
//		int year; // ���� ���ϴ� �������
//		int month; // ���� ���ϴ� �������
//		int day; // ���� ���ϴ� �������
//public: // ����
//	Date(); // �⺻������
//	Date(int y, int m, int d); // ������ �Ű������� �����޴� ������
//	Date(string date); // string�� �Ű������� �ϳ��޴� ������
//	void show(); // ����������� ����ϴ� �Լ�
//	int getYear(); // ������� year���� ȣ���ϴ� �Լ�
//	int getMonth(); // ������� month���� ȣ���ϴ� �Լ�
//	int getDay(); // ������� day���� ȣ���ϴ� �Լ�
//};
//Date::Date() // �⺻ ������
//{
//	year = 0; // ������� year�� 0���� �ʱ�ȭ
//	month = 0; // ������� month�� 0���� �ʱ�ȭ
//	day = 0; // ������� day�� 0���� �ʱ�ȭ
//}
//Date::Date(int y, int m, int d) // �Ű������� �ִ� ������
//{ 
//	year = y; // ������� year�� �Է¹��� y�� �ʱ�ȭ
//	month = m; // ������� month�� �Է¹��� m�� �ʱ�ȭ
//	day = d; // ������� day�� �Է¹��� d�� �ʱ�ȭ
//}
//Date::Date(string date) // ���ڿ� �Ű������� �޴� ������
//{
//	int index1 = date.find("/"); // ���� /�� ����� ���ڿ� �ε����� ��ȣ����
//	string y = date.substr(0,index1); // 0 - ���۰� // index1 - ����
//	year = stoi(y); // string ��ü�� ���ڿ��� int �� �ٲ��
//	int index2 = date.find("/", index1 + 1); // index1 �������� ã�ƶ�
//	string m = date.substr(index1 + 1, index2 - index1 - 1);
//	// index1 = 4 , index2 = 6, 6 - 4 - 1 = 1 , 
//	// ó�� ã�Ҵ� �ε����� �ϳ��� ���� 5���� 1�� ���� �ε��� 6�� ���ڿ��� (string��)m�� ����
//	month = stoi(m); // string ��ü�� ���ڿ��� int �� �ٲ��
//	string d = date.substr(index2 + 1, date.length()); // �ε��� 7���� �������� ���ڿ��� (string��)d�� ����
//	day = stoi(d); // string ��ü�� ���ڿ��� int �� �ٲ��
//}
//void Date::show() // ��������� ����Լ��� ���� ������ ����ϴ� ���
//{
//	cout << year << "��" << month << "��" << day << "��" << endl; // ����������� ���ʷ� ���ڿ��� �Բ� ���
//}
//int Date::getYear() // ������� year���� ��ȯ�ϴ� �Լ� ����
//{
//	return year;
//}
//int Date::getMonth() // ������� month���� ��ȯ�ϴ� �Լ� ����
//{
//	return month;
//}
//int Date::getDay() // ������� day���� ��ȯ�ϴ� �Լ� ����
//{
//	return day;
//}
//
//int main()
//{
//	Date birth(2014, 3, 20); // �����ڸ� ���� �Էµ� ������� ������� year, month, day�� ���ʴ�� �ʱ�ȭ�ϴ� ��ü
//	Date independanceday("1945/8/15"); // �����ڸ� ���� �Էµ� ���ڿ��� ������� year, month, day�� �ʱ�ȭ�ϴ� ��ü
//	independanceday.show(); // ��ü independanceday�� ����������� ����ϴ� ����Լ� ȣ��
//	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
//	// ��ü birth�� ����Լ��� ȣ���ϸ鼭 ����������� ���
//}

////3 // class Account // ������ �̸�(string) ���¹�ȣ �ܾ� // ���� �Լ� // ������ �̸� ��ȯ �Լ� // �ܾ�ǥ�� �Լ�
//class Account // Account Ŭ���� ����
//{
//private: // ������ ����
//	string name; // ���������� �̸��� ���� string�� �������
//	int id;  // ���¹�ȣ�� ���� �������
//	int balance; // �ܾ��� ��Ÿ���� �������
//public: // ����
//	Account(); // �⺻ ������
//	Account(string n, int a, int b); // string���� ������ �ΰ�  �� ������ �Ű������� ���� ������
//	void deposit(int n); // �����ϴ� ����Լ� // �ζ��� �Լ� - ����ο��� �Լ� ����
//	string getOwner(); // ���������� �̸��� ��ȯ�ϴ� ����Լ�
//	int inquiry(); // �ܾ��� ��ȸ�ϴ� ����Լ�
//	int withdraw(int n); // ����ϴ� ����Լ�
//};
//inline Account::Account() // �⺻ ������
//{
//	name = "NULL"; // ������� name�� NULL�� �ʱ�ȭ
//	id = 0; balance = 0; // ������� id�� balance�� 0���� �ʱ�ȭ
//}
//inline Account::Account(string n, int a, int b) // �Ű������� �ִ� ������
//{
//	name = n; // ���ڿ� �Ű����� name�� �Է¹��� n�� ���ڿ��� ����
//	id = a; // �Է¹��� a�� id�� ����
//	balance = b; // �Է¹��� b�� balance�� ����
//}
//inline void Account::deposit(int n) // �����ϴ� ����Լ� ����
//{
//	balance += n; // �Է¹��� n�� ���� balance ���� ���ؼ� ����
//}
//inline string Account::getOwner() // ���������� �̸��� ��ȯ�ϴ� �Լ� ����
//{
//	return name; // ������� name ��ȯ
//}
//inline int Account::inquiry() // �ܾ��� ��ȸ�ϴ� �Լ� ����
//{
//	return balance; // ������� balance ��ȯ
//}
//inline int Account::withdraw(int n) // ����ϴ� �Լ� ����
//{
//	balance -= n; // �Է¹��� n�� ���� balance�� ������ ���� �� ���� ����
//	return balance; // ������� balance ��ȯ
//}
//int main()
//{
//	Account a("kitae", 1, 5000); // �����ڸ� ���� �Էµ� ����� ������� name, id, balance�� ���ʴ�� �ʱ�ȭ�ϴ� ��ü
//	a.deposit(50000); // ����Լ��� ȣ���� �ܾ׿� 50000���� ���� 
//	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
//	// ����Լ����� ȣ���� ���������� �̸��� �ܾ� ��ȸ�� ���� ���
//	int money = a.withdraw(20000);	// 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
//	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
//	// ����Լ����� ȣ���� ���������� �̸��� �ܾ� ��ȸ�� ���� ��� 
//}

////4 // class CoffeeMachine // ������ Ŀ�Ƿ� �� ���� // ����Լ�
//class CoffeeMachine // CoffeeMachine Ŭ���� ����
//{
//private : // ������ ����
//	int coffee; // Ŀ�Ƿ� �������
//	int water; // ���� �������
//	int sugar; // ������ �������
//public: // ����
//	CoffeeMachine(); // �⺻������
//	CoffeeMachine(int c, int w, int s); // ������ ������ �Ű������� �޴� ������
//	void show(); // Ŀ�ǿ� ��,������ �ܿ����� �����ִ� ����Լ�
//	void drinkEspresso(); // ���������Ҹ� ����� ����Լ�
//	void drinkAmericano(); // �Ƹ޸�ī�븦 ����� ����Լ�
//	void drinkSugarCoffee(); // ����Ŀ�Ǹ� ����� ����Լ�
//	void fill(); // Ŀ�ǿ� ��,������ 10�� ä��� ����Լ�
//};
//CoffeeMachine::CoffeeMachine() // �⺻ ������
//{
//	coffee = 0; water = 0; sugar = 0; // Ŀ�ǿ� ��, ������ 0���� �ʱ�ȭ
//}
//CoffeeMachine::CoffeeMachine(int c, int w, int s) // �Ű������� �ִ� ������
//{
//	coffee = c; water = w; sugar = s; // �Է¹��� ������ �̿��� Ŀ�ǿ� ��,������ �ʱ�ȭ
//}
//void CoffeeMachine::show() // Ŀ�ǿ� ��,������ �ܿ����� �����ִ� ����Լ� ����
//{
//	cout << "Ŀ�� �ӽ� ����, Ŀ��:" << coffee << "  ��:" << water << "    ����:" << sugar << endl;
//	// ����������� �̿��� �ܿ��� ���
//}
//void CoffeeMachine::drinkEspresso() // ���������Ҹ� ����� ����Լ� ����
//{
//	coffee -= 1; // ������� coffee�� ���� 1��ŭ ����
//	water -= 1; // ������� water�� ���� 1��ŭ ����
//}
//void CoffeeMachine::drinkAmericano() // �Ƹ޸�ī�븦 ����� ����Լ� ����
//{
//	coffee -= 1; // ������� coffee�� ���� 1��ŭ ����
//	water -= 2; // ������� water�� ���� 2��ŭ ����
//}
//void CoffeeMachine::drinkSugarCoffee() // ����Ŀ�Ǹ� ����� ����Լ� ����
//{
//	coffee -= 1; // ������� coffee�� ���� 1��ŭ ����
//	water -= 2; // ������� water�� ���� 2��ŭ ����
//	sugar -= 1; // ������� sugar�� ���� 1��ŭ ����
//}
//void CoffeeMachine::fill() // // Ŀ�ǿ� ��,������ ���� 10�� ä��� ����Լ� ����
//{
//	coffee += 10; // ����Լ� coffee�� ���� 10��ŭ ����
//	water += 10; // ����Լ� water�� ���� 10��ŭ ����
//	sugar += 10; // ����Լ� sugar�� ���� 10��ŭ ����
//}
//int main()
//{
//	CoffeeMachine java(5, 10, 6); // �����ڸ� ���� �Էµ� ����� ������� coffee, water, sugar�� ���ʴ�� �ʱ�ȭ�ϴ� ��ü
//	java.drinkEspresso(); // ����Լ��� ȣ���� coffee 1 �Һ�, water 1 �Һ�
//	java.show(); // ����Լ��� ȣ���� ���� coffeeMachine�� ���� ���
//	java.drinkAmericano(); // ����Լ��� ȣ���� coffee 1 �Һ�, water 2 �Һ�
//	java.show(); // ����Լ��� ȣ���� ���� coffeeMachine�� ���� ���
//	java.drinkSugarCoffee(); // ����Լ��� ȣ���� coffee 1 �Һ�, water 2 , sugar 1 �Һ�
//	java.show(); // ����Լ��� ȣ���� ���� coffeeMachine�� ���� ���
//	java.fill(); // ����Լ��� ȣ���� coffee 10 �Һ�, water 10 , sugar 10 ä���
//	java.show(); // ����Լ��� ȣ���� ���� coffeeMachine�� ���� ���
//}

//5 // ������� �ʿ� X // ����Լ� // next()�Լ� ����
class Random // Random Ŭ���� ����
{
public: // ����
	Random(); // �⺻������
	int next(); // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ�
	int nextIntRange(int a, int b); // 2 ~ 4 ���� �� �������� ������ �̴� �Լ�
};
Random::Random() // �⺻ ������
{
	srand((unsigned)time(NULL)); // ������ ���带 �ð��� ���� ��������ִ� �Լ�
	// ��ü�� ������ �� ���带 ��������༭ ��ü���� �ٸ� ���尪�� ���� ��
}
int Random::next() // 0 ~ RAND_MAX ���� �� �������� ������ �̴� �Լ� ����
{
	int n = rand(); // �������� ���� �̾� ������ ���� n�� ����
	return n; // ���� n ��ȯ
}
int Random::nextIntRange(int mn, int mx) // 2 ~ 4 ���� �� �������� ������ �̴� �Լ� ����
{
	int range = (mx - mn) + 1; // �Է¹��� �� �ΰ��� ���� �� �ִ� ���� ������ ������ ����
	return mn + (rand() % range); // mn�� mn ������ ���� ������ �����Ѵ� 
}
int main() 
{
	Random r; // Random Ŭ���� ��ü r ����
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl; // ���������� �̴´ٴ� ���� ���
	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
	{
		int n = r.next(); // ����Լ��� ȣ���� 0���� RAND_MAX(32767) ������ ������ ������ ��ȯ�޾� ���� n�� ����
		cout << n << ' '; // �� ������������ ���
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl; // 2 ~ 4 ������ ���������� �̴´ٴ� ���� ���
	for (int i = 0; i < 10; i++) // ���� ���� 10���� �̱� ���� �ݺ��� ���
	{
		int n = r.nextIntRange(2, 4); // ����Լ��� ȣ���� 2���� 4 ������ ������ ������ ��ȯ�޾� ���� n�� ����
		cout << n << ' '; // �� ������������ ���
	}
	cout << endl;
}