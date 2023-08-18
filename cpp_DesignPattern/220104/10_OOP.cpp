#include <iostream>
using namespace std;

// 객체 지향 프로그래밍

// 복소수 2개의 합을 구하는 함수
// 작성 방식
// 1) void add(int ar, int ai, int br, int bi, int *sr, int *si)
//    { *sr = ar + br;  *si = ai + bi;}
//   이후 메인문에서 각 변수의 값을 정해주고 함수 add에 매개변수로 넘겨줌
//   -> 복잡해보임
// 2) 복소수 타입 -> 구조체 이용
//    struct Complex { int re; int im;}
//    Complex Add(Complex c1, Complex c2) {Complex result = {c1.re + c2.re, c1.im + c2.im}; return result;}
//    이후 메인문에서 Complex c1, c2를 만들고 값을 정해주고 Complex ressult에 함수 Add를 호출
//    -> 복잡도를 낮춤 => 객체 지향 프로그램 : 프로그램에 필요한 타입을 설계하고 프로그램을 만들자.

add(int ar, int ai, int br, int bi)
{
    int sum_r= ar+br;
    int sum_i= ai+bi;

    return ...
}