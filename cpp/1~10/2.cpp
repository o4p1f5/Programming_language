#include <iostream>
#include <cstring> // char ?? ?��?? ??????? ???????? ??? ????
#include <string> // string?? ????? ???? ???? ?????? ????
#pragma warning (disable : 4996)
using namespace std;

////3 // ?? ???? ???? ?? ? ?? ???
//int main()
//{
//	int a(0); // ?? ?????? ??��??? ???? ????
//	int b(0); // ?? ?????? ??��??? ???? ????
//	cout << "?? ???? ??????>>"; // ?? ???? ??��??? ???? ???
//	cin >> a >> b; // ??��??? ???? ?????? ?????? ????
//	if (a > b) // a?? b???? ????
//	{
//		cout << "? ?? = " << a; // "? ?? = (a?? ?????? ????)" ???
//	}
//	else // ?????
//		cout << "? ?? = " << b; // "? ?? = (b?? ?????? ????)" ???
//
//	return 0;
//}

////4 // ??????? ?????? 5???? ????? ??��?? ???? ? ?? ???
//int main()
//{
//	double str[5]{0}; // 5???? ????? ??��??? ?�� ????
//	cout << "5 ???? ????? ??????>>"; // ????? ??��??? ???? ???
//	for (int i = 0; i < 5; i++) // ????? ??��?? ???? ?????
//	{
//		cin >> str[i]; // ???? ????? ?????? ?��?? ????
//	}
//	double a(str[0]); // ????? ???? a?? ?��?? 1??�� ????? ????
//	for (int i = 0; i < 5; i++) // ???? ? ???? ??? ???? ?????
//	{
//		if (a < str[i]) // ???? a?? ?????? str[i] ????? ????
//		{
//			a = str[i]; // a?? str[i]?? ???? ????
//		}
//	}
//
// // ??? ??? ?????
// double a(str[0]);
// for (int i = 0; i < 5; i++) // ????? ??��?? ???? ?????
//	{
//		cin >> str[i]; // ???? ????? ?????? ?��?? ????
//       if (a < str[i]) // ???? a?? ?????? str[i] ????? ????
//		{
//			a = str[i]; // a?? str[i]?? ???? ????
//		}
//	}
//
//	cout << "???? ? ?? = " << a; // a?? ????? ???? ? ?? ???
//	return 0;
//}

////5-1 // char?? ?�� // ???? ????? ?? x?? ?????? ???? ???
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??��??? char?? ?�� ????
//	int cnt = 0; // x?? ?????? ?? ???? ????
//
//	cout << "??????? ??????(100?? ???)." << endl; // ??????? ??��?????? ???? ???
//	cin.getline(str, 100, '\n'); // ??��??? ??????? str?��?? ??????? ??????? \n?? ????
//
//	for (int i = 0; i < (int)strlen(str); i++) // ??��??? ??????? x?? ?? ????? ?????? ?????
//	{
//		if (str[i] == 'x') // ?�� ????? x?? ?? ????
//			cnt++; // cnt?? ?? up
//	}
//
//	cout << "x?? ?????? " << cnt << endl; // x?? ?????? ?????? ???
//	return 0;
//}

//// 5-2 // string // ???? ????? ?? x?? ?????? ???? ???
//int main()
//{
//	string str; // string ?�� ????
//	int cnt = 0; // x?? ?????? ?? ???? ????
//
//	cout << "??????? ??????(100?? ???)." << endl; // ??????? ??��?? ???? ???? ???
//	getline(cin, str, '\n'); // cin????? ??��??? ??????? str?��?? ????, ??????? \n???? ????
//	for (int i = 0; i < (int)str.size(); i++) // ??��??? ??????? x?? ?? ????? ?????? ?????
//	{
//		if (str[i] == 'x') // ?�� ????? x?? ?? ????
//			cnt++; // cnt?? ?? up
//	}
//	cout << "x?? ?????? " << cnt << endl; // x?? ?????? ?????? ???
//	return 0;
//}

//// 7-1 // char?�� // "yes"?? ???? ?????? ???????? ??? ???��??
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??��??? char?�� ????
//	while (true) // ???? ?????
//	{
//		cout << "????????????? yes?? ????????>>"; // ??????? ??��??? ???? ???
//		cin.getline(str, 100, '\n'); // ??��??? ??????? str?? ????, ??????? \n?? ????
//		if (!strcmp(str, "yes")) // ??��??? ??????? "yes" ?? ????? 0???, ??????? !?? ????????? true?? ???
//		{
//			cout << "????????..."; // ????? ????????... ??? ?? while???? ????????
//			break;
//		}
//	}
//	return 0;
//}

//// 7-2 // string // "yes"?? ???? ?????? ???????? ??? ???��??
//int main()
//{
//	string str; // ??????? ??��??? string ?�� ????
//	while (true) // ???? ?????
//	{
//		cout << "????????????? yes?? ????????>>"; // ??????? ??��??? ???? ???
//		getline(cin, str, '\n'); // cin????? ???? ??????? str?? ????, ??????? \n?? ????
//		if (str == "yes") // ??��??? ??????? "yes" ?? ?????
//		{
//			cout << "????????..."; // ????????... ??? ?? while ?? ????????
//			break;
//		}
//	}
//	return 0;
//}

//// 8-1 // char?�� // ???? ?? ??? ???
//int main()
//{
//	char str1[100] = { 0 }; // ??????? ??��??? ????? ????
//	char str2[100] = { 0 }; // ???? ?? ????? ?????? ?�� ????
//
//	cout << "5 ???? ????? ';'???? ??????? ????????" << endl << ">>";
//	// 5???? ????? ??��??? ???? ???
//
//	for (int i = 0; i < 5; i++) // 5???? ????? ??��?? ???? ?? ????? ???? ?????
//	{
//		cin.getline(str1, 100, ';'); // ??��??? ??????? ?????? str1?? ????, ??????? ;
//		if (strlen(str1) > strlen(str2)) // str1?? ????? str2?? ????? ???? ?? str1?? ????? ????
//		{
//			strcpy(str2, str1); // str1?? ??????? str2?? ????
//		}
//		cout << i + 1 << " : " << str1 << endl; // ??��??? ??????? ???
//	}
//  // ??? ???
//  int max_len = 0;
//  for (int i = 0; i < 5; i++)
//  {
//	    cin.getline(str1, 100, ';');
//	    int len = (int)strlen(str1);
//	    if (max_len < len)
//	    {
//		    max_len = len;
//		    strcpy(str2, str1);
//	    }
//  }
//	cout << "???? ?? ????? " << str2; // ???? ?? ????? ???
//}

//// 8-2 // string // ???? ?? ??? ???
//int main()
//{
//	string str1; // ??????? ??��??? ????? ????
//	string str2; // ???? ?? ????? ?????? ?�� ????
//
//	cout << "5 ???? ????? ';'???? ??????? ????????" << endl << ">>";
//	// 5???? ????? ??��??? ???? ???
//
//	for (int i = 0; i < 5; i++) // 5???? ????? ??��?? ???? ?? ????? ???? ?????
//	{
//		getline(cin, str1, ';'); // cin????? ???? ??????? str1?? ????, ??????? ;
//		if (str1.size() > str2.size()) // str1?? ????? str2?? ????? ???? ?? str1?? ????? ????
//		{
//			str2 = str1; // str1?? ??????? str2?? ????
//		}
//		cout << i + 1 << " : " << str1 << endl; // ??��??? ??????? ???
//	} 
//  int max_len = 0;
//  for (int i = 0; i < 5; i++)
//  {
//	    getline(cin, str1, ';');
//	    int len = (int)str1.size();
//	    if (max_len < len)
//	    {
//		    max_len = len;
//		    str2 = str1;
//	    }
//  }
//	cout << "???? ?? ????? " << str2; // ???? ?? ????? ???
//}

//// 10-1 // char?�� // ??��??? ??????? ?��? ??????? ?????? ???
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??��??? ?�� ????
//	cout << "????? ???>>"; // ??????? ??��??? ???? ???
//	cin.getline(str, 10, '\n'); // ???? ??????? str?? ????, ??????? \n
//
//	for (int i = 0; i < (int)strlen(str); i++) // ??��??? ??????? ?���???????? ??????? ???
//	{
//		for (int j = 0; j <= i; j++) // i?? ??????????? ????? ?����� ????
//			cout << str[j];
//		cout << endl;
//	}
//	return 0;
//}

//// 10-2 // string // ??��??? ??????? ?��? ??????? ?????? ???
//int main()
//{
//	string str; // ??????? ??��??? ?�� ????
//	cout << "????? ???>>"; // ??????? ??��??? ???? ???
//	getline(cin, str, '\n'); // cin????? ???? ??????? str?? ????, ??????? \n
//
//	for (int i = 0; i < (int)str.size(); i++) // ??��??? ??????? ?���???????? ??????? ???
//	{
//		for (int j = 0; j <= i; j++) // i?? ??????????? ????? ?����� ????
//			cout << str[j]; 
//		cout << endl;
//	}
//	return 0;
//}