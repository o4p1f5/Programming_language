#include <iostream>
#include <cstring> // char ?? ?譈?? ??????? ???????? ??? ????
#include <string> // string?? ????? ???? ???? ?????? ????
#pragma warning (disable : 4996)
using namespace std;

////3 // ?? ???? ???? ?? ? ?? ???
//int main()
//{
//	int a(0); // ?? ?????? ??易??? ???? ????
//	int b(0); // ?? ?????? ??易??? ???? ????
//	cout << "?? ???? ??????>>"; // ?? ???? ??易??? ???? ???
//	cin >> a >> b; // ??易??? ???? ?????? ?????? ????
//	if (a > b) // a?? b???? ????
//	{
//		cout << "? ?? = " << a; // "? ?? = (a?? ?????? ????)" ???
//	}
//	else // ?????
//		cout << "? ?? = " << b; // "? ?? = (b?? ?????? ????)" ???
//
//	return 0;
//}

////4 // ??????? ?????? 5???? ????? ??易?? ???? ? ?? ???
//int main()
//{
//	double str[5]{0}; // 5???? ????? ??易??? ?譈 ????
//	cout << "5 ???? ????? ??????>>"; // ????? ??易??? ???? ???
//	for (int i = 0; i < 5; i++) // ????? ??易?? ???? ?????
//	{
//		cin >> str[i]; // ???? ????? ?????? ?譈?? ????
//	}
//	double a(str[0]); // ????? ???? a?? ?譈?? 1??﹉ ????? ????
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
// for (int i = 0; i < 5; i++) // ????? ??易?? ???? ?????
//	{
//		cin >> str[i]; // ???? ????? ?????? ?譈?? ????
//       if (a < str[i]) // ???? a?? ?????? str[i] ????? ????
//		{
//			a = str[i]; // a?? str[i]?? ???? ????
//		}
//	}
//
//	cout << "???? ? ?? = " << a; // a?? ????? ???? ? ?? ???
//	return 0;
//}

////5-1 // char?? ?譈 // ???? ????? ?? x?? ?????? ???? ???
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??易??? char?? ?譈 ????
//	int cnt = 0; // x?? ?????? ?? ???? ????
//
//	cout << "??????? ??????(100?? ???)." << endl; // ??????? ??易?????? ???? ???
//	cin.getline(str, 100, '\n'); // ??易??? ??????? str?譈?? ??????? ??????? \n?? ????
//
//	for (int i = 0; i < (int)strlen(str); i++) // ??易??? ??????? x?? ?? ????? ?????? ?????
//	{
//		if (str[i] == 'x') // ?譈 ????? x?? ?? ????
//			cnt++; // cnt?? ?? up
//	}
//
//	cout << "x?? ?????? " << cnt << endl; // x?? ?????? ?????? ???
//	return 0;
//}

//// 5-2 // string // ???? ????? ?? x?? ?????? ???? ???
//int main()
//{
//	string str; // string ?譈 ????
//	int cnt = 0; // x?? ?????? ?? ???? ????
//
//	cout << "??????? ??????(100?? ???)." << endl; // ??????? ??易?? ???? ???? ???
//	getline(cin, str, '\n'); // cin????? ??易??? ??????? str?譈?? ????, ??????? \n???? ????
//	for (int i = 0; i < (int)str.size(); i++) // ??易??? ??????? x?? ?? ????? ?????? ?????
//	{
//		if (str[i] == 'x') // ?譈 ????? x?? ?? ????
//			cnt++; // cnt?? ?? up
//	}
//	cout << "x?? ?????? " << cnt << endl; // x?? ?????? ?????? ???
//	return 0;
//}

//// 7-1 // char?譈 // "yes"?? ???? ?????? ???????? ??? ???丟??
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??易??? char?譈 ????
//	while (true) // ???? ?????
//	{
//		cout << "????????????? yes?? ????????>>"; // ??????? ??易??? ???? ???
//		cin.getline(str, 100, '\n'); // ??易??? ??????? str?? ????, ??????? \n?? ????
//		if (!strcmp(str, "yes")) // ??易??? ??????? "yes" ?? ????? 0???, ??????? !?? ????????? true?? ???
//		{
//			cout << "????????..."; // ????? ????????... ??? ?? while???? ????????
//			break;
//		}
//	}
//	return 0;
//}

//// 7-2 // string // "yes"?? ???? ?????? ???????? ??? ???丟??
//int main()
//{
//	string str; // ??????? ??易??? string ?譈 ????
//	while (true) // ???? ?????
//	{
//		cout << "????????????? yes?? ????????>>"; // ??????? ??易??? ???? ???
//		getline(cin, str, '\n'); // cin????? ???? ??????? str?? ????, ??????? \n?? ????
//		if (str == "yes") // ??易??? ??????? "yes" ?? ?????
//		{
//			cout << "????????..."; // ????????... ??? ?? while ?? ????????
//			break;
//		}
//	}
//	return 0;
//}

//// 8-1 // char?譈 // ???? ?? ??? ???
//int main()
//{
//	char str1[100] = { 0 }; // ??????? ??易??? ????? ????
//	char str2[100] = { 0 }; // ???? ?? ????? ?????? ?譈 ????
//
//	cout << "5 ???? ????? ';'???? ??????? ????????" << endl << ">>";
//	// 5???? ????? ??易??? ???? ???
//
//	for (int i = 0; i < 5; i++) // 5???? ????? ??易?? ???? ?? ????? ???? ?????
//	{
//		cin.getline(str1, 100, ';'); // ??易??? ??????? ?????? str1?? ????, ??????? ;
//		if (strlen(str1) > strlen(str2)) // str1?? ????? str2?? ????? ???? ?? str1?? ????? ????
//		{
//			strcpy(str2, str1); // str1?? ??????? str2?? ????
//		}
//		cout << i + 1 << " : " << str1 << endl; // ??易??? ??????? ???
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
//	string str1; // ??????? ??易??? ????? ????
//	string str2; // ???? ?? ????? ?????? ?譈 ????
//
//	cout << "5 ???? ????? ';'???? ??????? ????????" << endl << ">>";
//	// 5???? ????? ??易??? ???? ???
//
//	for (int i = 0; i < 5; i++) // 5???? ????? ??易?? ???? ?? ????? ???? ?????
//	{
//		getline(cin, str1, ';'); // cin????? ???? ??????? str1?? ????, ??????? ;
//		if (str1.size() > str2.size()) // str1?? ????? str2?? ????? ???? ?? str1?? ????? ????
//		{
//			str2 = str1; // str1?? ??????? str2?? ????
//		}
//		cout << i + 1 << " : " << str1 << endl; // ??易??? ??????? ???
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

//// 10-1 // char?譈 // ??易??? ??????? ?伉? ??????? ?????? ???
//int main()
//{
//	char str[100] = { 0 }; // ??????? ??易??? ?譈 ????
//	cout << "????? ???>>"; // ??????? ??易??? ???? ???
//	cin.getline(str, 10, '\n'); // ???? ??????? str?? ????, ??????? \n
//
//	for (int i = 0; i < (int)strlen(str); i++) // ??易??? ??????? ?伉相???????? ??????? ???
//	{
//		for (int j = 0; j <= i; j++) // i?? ??????????? ????? ?伉相譈 ????
//			cout << str[j];
//		cout << endl;
//	}
//	return 0;
//}

//// 10-2 // string // ??易??? ??????? ?伉? ??????? ?????? ???
//int main()
//{
//	string str; // ??????? ??易??? ?譈 ????
//	cout << "????? ???>>"; // ??????? ??易??? ???? ???
//	getline(cin, str, '\n'); // cin????? ???? ??????? str?? ????, ??????? \n
//
//	for (int i = 0; i < (int)str.size(); i++) // ??易??? ??????? ?伉相???????? ??????? ???
//	{
//		for (int j = 0; j <= i; j++) // i?? ??????????? ????? ?伉相譈 ????
//			cout << str[j]; 
//		cout << endl;
//	}
//	return 0;
//}