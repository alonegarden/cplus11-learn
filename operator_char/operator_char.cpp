
//
// c++ 11  用户自定义字面量
// 
//
 
/*
在C++11 中，标准要求声明字面量操作符有一定的规则，该规则跟字面量的“类型” 密切相关。 
C++11 中具体规则如下： 

1 如果字面量为整型数，那么字面量操作符函数只可接受 unsigned long long 或者 const char* 为 其 参数。 
   当 unsigned long long 无法容纳该字面量的时候， 编译器会自动将该字面量转化为以\0为结束符的字符串， 
   并调用以 const char* 为参数的版本进行处理。 
   
2 如果字面量为浮点型数，则字面量操作符函数只可接受 long double 或者 const char* 为 参数。 
   const char* 版本的调用规则同整型的一样（过长则使用 const char* 版本）。 
   
3  如果字面量为字符串，则字面量操作符函数函数只可接受 const char*, size_ t 为 参数（ 已知 长度 的 字符串）。
 
4 如果字面量为字符，则字面量操作符函数只可接受一个char为参数。总体上来说，用户自定义字面量为代码书写带来了极大的便利。
  此外，在使用这个特性的时候，应该注意以下几点：·在字面量操作符函数的声明中，operator"" 与用户自定义后缀之间必须有空格。

5  后缀建议以下划线开始。 不宜使用非下划线后缀 的用户自定义字符串常量， 否则会被编译器警告。 当然，这也很好理解， 
   因为如果 重用形如 201203L 这样的字面量， 后缀“L” 无疑会引起一些混乱的状况。 为了避免混乱， 程序员最好只使用下划线开始的后缀名。


*/

#include <iostream>
#include <vector>


struct Watt{
	unsigned int v;
};

Watt operator "" _w(unsigned long long v)
{
	return { (unsigned int) v };
}


int main()
{
	Watt capacity = 1024_w;
	return 0;
}
