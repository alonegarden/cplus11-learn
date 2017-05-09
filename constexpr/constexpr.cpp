//
//  c++11 constexpt
//

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