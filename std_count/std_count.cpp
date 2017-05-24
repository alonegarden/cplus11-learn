
//
// c++ 11 learning count
// 

/*
  count (InputIterator first, InputIterator last, const T& val);
  在 [first,last) 找到val的个数
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 
int main()
{
    std::vector<int> v{ 0, 6, 2, 3, 4, 5, 6, 4, 6, 7, 8 };
    // 返回值为 6 的元素的个数
    auto n = std::count(std::begin(v), std::end(v), 6);
    std::cout << n << '\n';
    return 0;
}