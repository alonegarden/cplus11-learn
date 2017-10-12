
//
// c++ 11 test 
// 
// 在 C++ 11中，定义别名已经不再是typedef的专属能力，
// 使用using同样也可以定义类型的别名,而且从语言能力上看，using丝毫不比typedef逊色。

#include <iostream>
#include <vector>
#include <type_traits>

struct Watt{
	unsigned int v;
};

Watt operator "" _w(unsigned long long v)
{
	return { (unsigned int) v };
}

using namespace std;
using uint = unsigned int;
typedef unsigned int UINT;

int main()
{
	cout << is_same<uint, UINT>::value << endl;
	return 0;
}