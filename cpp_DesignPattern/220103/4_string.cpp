#include <iostream>
// #include <string.h> // c언어
#include <string>
/*
int main() // c언어
{
    char s1[] = "hello";
    const char *s2 = "hello"; // 수정 불가능, 단순히 문자열의 주소만 사용

    if(strcmp(s1,s2)==0)
    {
        std::printf("동일한 문자열 입니다. \n")
    }
}*/

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if(s1==s2)
    {
        std::printf("동일한 문자열 입니다. \n");
    }

    std::string s3 = s2; // strcpy

    std::cout << s1 << ", " << s2 << ", " << s3 << std::endl;
}