#include <iostream>
using namespace std;

#include <list> // 연결리스트 기반의 선형적 자료구조

// 그런데 클라이언트가 stack을 요구
// 1) stack을 다시 만든다
// 2) list를 한쪽으로만 사용하면 stack이기 때문에 list를 재사용함

// SW 재사용
// 1) 상속

// stack은 list의 모든 기능을 상속
/*
class stack : public list<int> {
public:
    void push(int n) // 값 입력
    {
        push_back(n); // list 제공
    }

    void pop() // 값 제거
    {
        pop_back(); // list 제공
    }

    int& top() // 출력
    {
        return back(); // list 제공
        // 가장 마지막 값 접근
    }
};
// 스택을 다시 만드는 것보다 안전하고 쉬움
// => int 타입만 사용가능 => 템플릿으로 만들어줌

template <typename T>
class stack : private list<T> {
public:
    // 간결한 함수들은 inline으로 표기
    inline void push(const T& n) // 복사생성자 오류 방지
    {
        list<T>::push_back(n);
        // 기반 클래스의 것임을 모를 경우가 있기때문에
        // 명시적으로 표기
    }

    inline void pop()
    {
        list<T>::pop_back();
        // 기반 클래스의 것임을 모를 경우가 있기때문에
        // 명시적으로 표기
    }

    inline T& top()
    {
        return list<T>::back();
        // 기반 클래스의 것임을 모를 경우가 있기때문에
        // 명시적으로 표기
    }
};
*/
// => Adapter Pattern
// : 기존 클래스(list)의 인터페이스(함수 이름)을 변경해서
//   사용자가 요구하는 새로운 클래스처럼 보이게 하는 패턴

// private 상속: 부모로부터 구현은 물려받지만(자식이 내부적으로 사용하지만)
//              인터페이스는 물려받지 않겠다.(부모 함수를 외부로 노출하지 않겠다.)
// => 자식클래스에 의해 기반 클래스에게 오는 위험한 접근을 막음

// 상속의 문제점
// 1. 부모 클래스와 자식 클래스의 강한 결합이 형성됩니다.
//  > 부모 클래스에 대한 변경이 자식 클래스로 전파됩니다.
//   - 유지보수에 어려움이 있습니다.
//
// 2. 부모 클래스를 자식 클래스에서 public 상속할 경우
//    불필요한 인터페이스가 외부에 노출되는 문제가 있습니다.
//   => C++ : private 상속
//
// 3. 상속을 기존 클래스의 재사용 목적으로 사용하는 것은 권장하지 않습니다.
//   => 포함을 이용하는 것이 좋을 때가 많습니다.

// 포함에 대한 모델
/*
template <typename T>
class stack {
    std::list<T> st; // 포함(상속과 달리 명시적)
public:
    inline void push(const T& n)
    {
        st.push_back(n);
    }

    inline void pop()
    {
        st.pop_back();
    }

    inline T& top()
    {
        return st.back();
    }
};
*/

// 스택 어뎁터
/*
//                                 std::deque<int> // list와 vector의 중간정도
template <typename T, typename C = std::list<int>>
// 사용자가 원하는 부모클래스를 사용할 수 있게 연결해주는 코드
class stack {
    C st;

public:
    inline void push(const T& n)
    {
        st.push_back(n);
    }

    inline void pop()
    {
        st.pop_back();
    }

    inline T& top()
    {
        return st.back();
    }
};
*/

#include <stack> // 다 지우고 이 라이브러리를 써도 프로그램 완성됨
#include <vector>

int main()
{
    stack<int, vector<int>> s; // typename C가 벡터를 만족
    s.push(10);
    s.push(20);
    s.push(30);

    // s.push_front(10); // => list의 접근하게 됨 // => 스택의 규칙이 깨짐
    // 접근변경자를 변경함.

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}