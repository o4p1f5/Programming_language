#include <iostream>
#include <string>
#include <memory>
#include <locale>
#include <ctime> // #include <time.h>
using namespace std;

////3-1 // []�� �̿��� �ڵ�
// int main()
//{
//	string str; // string ���ڿ� ����
//	int cnt = 0; // ���� a�� ������ ���� ���� ����
//
//	cout << "���ڿ� �Է�>> ";
//	getline(cin, str, '\n'); // cin�� ���� �Է¹��� ���ڿ��� str�� ����
//	// �����ڴ� \n���� �Ѵ�
//
//	for (int i = 0; i < (int)str.length(); i++)
//	{
//		if (str[i] == 'a') // str�� i��° �ε����� �ִ� ���ڿ��� ���� a�� ���ٸ�
//		{
//			cnt++; // cnt�� 1�� ���Ѵ�
//		}
//	}
//	cout << "���� a�� " << cnt << "�� �ֽ��ϴ�."; // ���� a�� ������ ���
//     return 0;
// }

////3-2 // find() �Լ��� �̿��� �ڵ�
// int main()
//{
//	string str; // string ���ڿ� ����
//	int index = 0; // find�Լ��� ���� ���� a�� ��ġ �ε������� ������ ����
//	int cnt = 0; // ���� a�� ������ ���� ���� ����
//
//	cout << "���ڿ� �Է�>> ";
//	getline(cin, str, '\n'); // cin�� ���� �Է¹��� ���ڿ��� str�� ����
//	// �����ڴ� \n���� �Ѵ�
//
//	for (int i = 0; i < (int)str.length(); i++)
//	{
//		index = str.find('a', index); // find() �Լ��� �̿��� str���ڿ����� a�� �ε������� ���� index�� ����
//		// ã�� ��ġ�� ������ ���� index�� �ε������� �����Ѵ�.
//		if (index == -1) // str�� a�� ���� ���ڰ� ���ٸ�
//			break; // for���� ��������
//		else // str�� a�� ���� ���ڰ� �ִٸ�
//			cnt++; // cnt�� 1 ����
//
//		index++; // a�� �ε��� ��ġ�� ���� index�� ���� �ε������� a�� ã������ index�� 1 ����
//	}
//	cout << "���� a�� " << cnt << "�� �ֽ��ϴ�."; // ã�� a�� ������ ���
//     return 0;
// }

////5 // ���� // rand() % size // ���� char�� ���� ���� ����
// int main()
//{
//	string str; // string ���ڿ� ����
//	int index = 0;  // �������� ���� ���ڰ� �������� �ε������� ������ ����
//	char ch = 0; // �������� ���� ���ڸ� ������ �� �ִ� ����
//	srand((unsigned)time(0)); // ������ ������, ���� �������� �߻���Ű�� ���� seed ����
//	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
//	while (true)
//	{
//		cout << ">>";
//		getline(cin, str, '\n'); // cin�� ���� �Է¹��� ���ڿ��� str�� ����
//		// �����ڴ� \n���� �Ѵ�
//		if (str == "exit") // ���� str�� ���ڿ� exit�� �Էµƴٸ�
//		{
//			break; // while���� ��������
//		}
//		index = rand() % (int)str.length(); // 0���� �Է¹��� ���ڿ��� ���� ������ �� �� �������� ���� ����
//		ch = 'a' + rand() % 26; // ���ĺ� 26���� �� �ϳ��� ���ڸ� �������� �̾� ch�� ����
//		str[index] = ch; // str�� index��° �ε����� �������� ���� ch ���ڸ� ����
//		cout << str << endl; // �ٲ� ���ڿ��� ���
//	}
//	return 0;
// }

////6 // �Է��� ���ڿ� �Ųٷ� ���
//// �ε��� �ݴ�� ��� // for�� ���
// int main()
//{
//	string str; // string ���ڿ� ����
//	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
//	while (true)
//	{
//		cout << ">>";
//		getline(cin, str, '\n'); // cin�� ���� �Է¹��� ���ڿ��� str�� ����
//		// �����ڴ� \n���� �Ѵ�
//		if (str == "exit") // ���� str�� ���ڿ� exit�� �Էµƴٸ�
//		{
//			break; // while���� ��������
//		}
//		for (int i = str.length(); i >= 0; i--) // str�� �Էµ� ���ڿ��� ���� ���� �ε������� �ε��� 0���� ���
//		{
//			cout << str[i];
//		}
//		cout << endl;
//	}
// }

////9 // ���迬���� = �̿��ؼ� ���� ���ڿ� ã��
// class Person // Ŭ���� Person
//{
//	string name; // �̸��� �޴� �������
//	string tel; // ��ȭ��ȣ�� �޴� �������
// public:
//	Person()
//	{
//		name = " ";
//		tel = " ";
//	} // �⺻������
//	string getName() { return name; } // ������� name�� ��ȯ�ϴ� ����Լ�
//	string getTel() { return tel; } // ������� tel�� ��ȯ�ϴ� ����Լ�
//	void set(string name, string tel) // �Ű������� ��������� ���� ��ȯ�ϴ� ����Լ�
//	{
//		this->name = name; // �Է¹��� �Ű����� name�� ���� this�����Ͱ� �˷��ִ�
//		// ������� name�� ����
//		this->tel = tel; // �Է¹��� �Ű����� tel�� ���� this�����Ͱ� �˷��ִ�
//		// ������� tel�� ����
//	}
// };
// int main()
//{
//	Person person[3]; // Ŭ���� Person ��ü �迭 person ����
//	string name; // �̸��� ��� string ���� ����
//	string tel; // ��ȭ��ȣ�� ��� string ���� ����
//
//	cout << "�̸��� ��ȭ��ȣ�� �Է��� �ּ���" << endl;
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		cout << "��� " << i + 1 << ">> ";
//		cin >> name >> tel; // �Է¹��� �̸��� name�� ���� // �Է¹��� ��ȭ��ȣ�� tel�� ����
//		person[i].set(name, tel); // �Է¹��� ���ڿ����� �Ű������� �Ѱ�
//		// i��° ��ü�� name�� tel�� ����
//	}
//	cout << "��� ����� �̸��� ";
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		cout << person[i].getName() << ' '; // i��° ��ü�� name�� ���
//	}
//	cout << endl << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ���>>";
//	cin >> name; // ã�����ϴ� ����� �̸��� �Է¹޾� name�� ����
//
//	for (int i = 0; i < sizeof(person) / sizeof(Person); i++)
//	{
//		if (name == person[i].getName()) // �Է¹��� name�� ���ڿ��� i��° ��ü�� name�� �����ϴٸ�
//		{
//			cout << "��ȭ ��ȣ�� " << person[i].getTel(); // i��° ��ü�� tel�� ���
//			break;
//		}
//	}
//	return 0;
// }

////10 // �����ڿ��� �����Ҵ�
// // �ٸ� Ŭ������ Ŭ������ ��ü�� �����ͺ����� �ü������� ����
// class Person // Ŭ���� person ����
//{
//	string name; // ���� �������� �̸��� ���� ������� ����
// public:
//	Person() {}; // �⺻ ������
//	Person(string name) { this->name = name; } // �Ű������� �ִ� ������
//	string getName() { return name;} // ���� ������ �̸��� ��ȯ�ϴ� �Լ�
//	void setname(string name) { this->name = name; } // �Է¹��� ���ڿ��� ������� name�� ��ȯ
//};
//
// class Family // Ŭ���� Family ����
//{
//	Person* p; // Person �迭 ������
//	int size; // Person �迭�� ũ��, ���� �������� ��
//	string name; // ������ ��ǥ �̸�
// public:
//	Family() // �⺻ ������
//	{
//		p = NULL; // �迭 �����Ͱ� ����Ű�� ���� ����
//		size = 0; // 0���� �ʱ�ȭ
//		name = " ";
//	}
//	Family(string name, int size) // �Ű������� �ִ� ������
//	{
//		this->size = size; // �Է¹��� size�� ��ü�� size ��������� ����
//		while (true)
//		{
//			p = new Person[this->size]; // �Է¹��� size��ŭ Person �迭�� �����Ҵ��� �� �ּҸ� p�� ����
//			if (!p) // p�� 0�̶�� // �����Ҵ��� ���������� ��������ʾҴٸ�
//			{
//				continue; // while�� ó������ ���ư��� �ٽ� �����Ҵ��� ����
//			}
//			else // ����� �����Ҵ��� �ƴٸ�
//			{
//				break; // while�� ��������
//			}
//		}
//		this->name = name; // �Է¹��� ���ڿ��� ��ü�� name ��������� ����
//	}
//	void show() // ������ ����̸� ���� �������� ������������ ����ϴ� ����Լ�
//	{
//		cout << name << "������ ������ ���� " << size << "�� �Դϴ�." << endl;
//		for (int i = 0; i < size; i++)
//		{
//			cout << p[i].getName() << "    "; // p�� ����Ű�� Person �迭�� i��° ��ü��
//			// �̸��� ȣ��
//		}
//	}
//	void setName(int i, string name) // Person �迭�� ���� ������ �̸��� ä��� ����Լ�
//	{
//		p[i].setname(name); // p�� ����Ű�� Person�迭�� i��° ��ü�� ������� name��
//		// �Ű����� name�� ���ڿ��� ����
//	}
//	~Family() // �Ҹ��� // p�� ����� �� ȣ��
//	{
//		if (p)
//		{
//			delete[]p; // p�� ����Ű�� �����Ҵ� ������ ����
//		}
//		p = NULL; // p�� �ƹ����� ����Ű�� ������ ����
//	}
//};
// int main()
//{
//	Family* simpson = new Family("Simpson", 3); // Ŭ���� Family�� ��ü������ �����Ҵ��ϰ�
//	// �� �ּҸ� ��ü������ simson�� ���� // �Ű������� �ִ� ������ ȣ��
//	if (!simpson) // simpson�� 0�̶�� // �����Ҵ��� ���������� ��������ʾҴٸ�
//	{
//		return 0; // �����Լ��� ����
//	}
//	simpson->setName(0, "Mr. Simpson"); // p�� ����Ű�� Person �迭�� 0��° ��ü�� ������� name��
//	// ���ڿ� "Mr. Simpson" ����
//	simpson->setName(1, "Mrs. Simpson"); // p�� ����Ű�� Person �迭�� 1��° ��ü�� ������� name��
//	// ���ڿ� "Mrs. Simpson" ����
//	simpson->setName(2, "Bart Simpson"); // p�� ����Ű�� Person �迭�� 2��° ��ü�� ������� name��
//	// ���ڿ� "Bart Simpson" ����
//	simpson->show(); // p�� ����Ű�� Person�迭�� ����ؼ� ������������ ������
//	delete simpson; // simpson�� ����Ű�� �����Ҵ� ������ ����
//	simpson = NULL; // simpson�� �ƹ����� ����Ű�� ������ �˸�
//}

////13
// class Histogram // Ŭ���� Histogram ����
//{
//	string text; // ���ڿ��� ���� �������
//	int alpha[26]; // a���� z������ ��Ÿ���� int�� �迭 // �� ���ĺ��� ������ ����
// public:
//	Histogram(string text) // �Ű������� �ִ� ������
//	{
//		this->text = text; // ���ڿ� ���� ���� // �Է¹��� ���ڿ��� ��ü�� text��������� �ʱ�ȭ
//		memset(alpha, 0, sizeof(int) * 26); // �迭 alpha�� ũ�⸸ŭ�� 0���� �ʱ�ȭ
//	}
//	void put(string text) // ���ڿ��� ��ġ�� ����Լ�
//	{
//		this->text += text; // ���մ��Կ����ڷ� ���ڿ� ��ġ�� ����
//		// �Է¹��� ���ڿ��� ������ �ִ� ��ü�� ����Լ� text�� ���ڿ��� �߰�
//	}
//	void putc(char ch) // ���ڿ� ���ڿ��� �������� �����ִ� ����Լ�
//	{
//		text += ch; // ���ڵ� ������
//		// �Է¹��� ���ڸ� ������ ��ü ����Լ� text ���ڿ��� �߰�
//	}
//	void print() // ���ڿ��� �� ���ĺ��� �󸶾� �ִ� ����ϴ� ����Լ�
//	{
//		cout << text << endl << endl; // ���� ��ü�� text�� �ִ� ���ڿ� ���
//		int cnt(0); // ���ڿ� �� ���ĺ��� �� �� ���� �����ִ� ���� ����
//		for (int i = 0; i < (int)text.length(); i++) // text���ڿ��� ���̸�ŭ �ݺ���
//		{
//			if (isalpha(text[i])) // text ���ڿ��� i��° �ε����� �ִ°� �˹ٺ��ΰ�?
//			{
//				cnt++; // �´ٸ� cnt 1 ����
//				char ch = tolower(text[i]); // text ���ڿ��� i��° ���ĺ��� �빮�ڶ��
//				// �ҹ��ڷ� �ٲ㼭 ch�� ����
//				alpha[(int)(ch - 'a')]++; // ch�� ���ĺ����� 'a'��ŭ�� ���� 0 ~ 25 ������ ���� ���´�
//				// 0 ~ 25 �� a ���� z�� �����ϰ� �� �ڸ��� 1�� ������Ŵ���� text[i]�� ���ĺ��� �������� �˸�
//			}
//		}
//		cout << "�� ���ĺ� " << cnt << endl << endl; // ���ڿ� �� �� ���ĺ��� ������ ���
//		for (int i = 0; i < 26; i++)
//		{
//			cout << (char)(i + 'a') << "(" << alpha[i] << ") : ";
//			// ���ĺ� �����̰� � �ִ��� ����ϰ�
//			for (int j = 0; j < alpha[i]; j++) // �� ������ŭ *�� ���
//			{
//				cout << '*';
//			}
//			cout << endl;
//		}
//	}
// };
// int main()
//{
//	Histogram elvisHisto("Wise men say, only fools rush in But I cna't help, ");
//	// Ŭ���� Histogram ��ü elvisHisto ���� // �Ű������� �ִ� ������ ȣ��
//	elvisHisto.put("falling in love with you"); // ���ڿ��� ��ü�� text�� �߰�
//	elvisHisto.putc('-'); // ���ڸ� ��ü�� text�� �߰�
//	elvisHisto.put("Elvis Presley"); // ���ڿ��� ��ü�� text�� �߰�
//	elvisHisto.print(); // ���ĺ��� ã�� ��� ���
// }