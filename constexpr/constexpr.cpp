//
//  c++11 constexpt 叫做常量表达式
//  from http://zh.cppreference.com/w/cpp/language/constexpr

#include <iostream>
#include <map>

using namespace std;



constexpr int getDefaultArraySize (int multiplier)
{
    return 10 * multiplier;
}

constexpr int multiply (int x, int y)
{
    return x * y;
}

// 将在编译时计算
const int val = multiply( 10, 10 );


int main()
{
    const int len = getDefaultArraySize( 3 );
    int array[ len ];
    array[0] = 1;
    for (int i=0; i<len; i++)
    {
         array[i] = i;
    }

    for (int i=0; i<getDefaultArraySize( 3 ); i++)
    {
        cout <<array[i] << endl;
    }
    return 0;
}

/*
1. constexpr指定符声明可以在编译时求得函数或变量的值。然后这些变量和函数（若给定了合适的函数参数）可用于仅允许编译时常量表达式之处。
   用于对象中的constexpr指定符隐含了const。用于函数中的constexpr指定符隐含inline。
*/