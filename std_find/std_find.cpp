
//
// c++ 11 learning 
// 

/*
 InputIterator find (InputIterator first,
                        InputIterator last,
​                        const T& val);
 std::find  找到[first, last)中的val 找到了返回跌代器，找不到返回end
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 
int main()
{
    std::vector<int> v{ 0, 1, 1, 2, 3, 4 };
 
    auto it = std::find(std::begin(v), std::end(v), 3);
 
    if (it != std::end(v))
    {
        std::cout << "I find it." << '\n';
    }
    return 0;
}