#include <iostream>
using namespace std;

// STL : c++에서 제공하는 템플릿 기반의 라이브러리
// => 자료구조(컨테이너, 컬렉션)

// O(1) : 데이터가 늘어나도 시간이 같다.
// O(N) : 데이터가 늘어날수록 시간이 길어진다.
// O(log N) : 데이터가 늘어날수록 시간이 길어지지만 N보다 시간이 덜 든다
// O(e) : 데이터가 늘어날수록 시간이 급진적으러 길어진다

// 연속된 메모리 형태의 선형적인 자료구조 (STL 제공)
// => 임의 접근이 빠르지만 O(1), 중간 삽입과 삭제가 비용이 발생한다. O(N)

// 연결리스트 기반의 선형적인 자료구조 (STL 제공)
// => 중간 삽입과 삭제가 빠르다 O(1), 탐색이 상대적으로 느리다. O(N)

// 우선 순위 큐
// stack -> <stack> 이라는 헤더파일
// queue -> <queue> 이라는 헤더파일

// #include <stack>
/*
int main()
{
    std::stack<int> s;
    s.push(10);
    s.push(20);

    // pop() : 
    // 가장 마지막 요소를 체크는 top()
    // 스택에서 요소를 제거하는 pop()으로 나눠짐
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}
*/

// #include<vector>
/*
int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(int e:v)
    {
        std::cout << e << std::endl;
    }
}
*/


// 탐색 
// 1) Tree : 탐색 - O(log N), 정렬 - O(N)
//         : 보완 - RED-BLACK 트리
//    => <map>
// 2) Hashtable : 탐색 - O(1), 퀵소드 - O(NlogN)
//              : 데이터가 저장되는 순서가 다르다.
//    => <unordered_map>

// map => 키-값 쌍으로 이루어진 데이터
//     C++ / Java
//     C# / Swift - Dictionary 라고도 부른다.

#include <map>
int main()
{
  std::map<std::string, std::string> data;
  data["홍길동"] = "010-1234-5678";
  data["이순신"] = "010-2222-3333";

  std::cout << data["홍길동"] << std::endl;
  std::cout << data["이순신"] << std::endl;
}