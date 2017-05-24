
//
// c++ 11 learning adjacent_find
// ：在一个数组中寻找两个相邻的元素。如果相等呢，就返回这两个相等元素第一个元素的迭代器，呵呵，不等的话，就返回v.end().


#include <iostream>
#include <algorithm>
#include <vector>
 
void AdjacentFind_2()
{
    std::vector<int> BigVector = { 8, 23, 5, 5, 7, 29, 0, 7, 7, 7, 1, 1 };
    
    // 等价比较
    auto it = std::adjacent_find(std::begin(BigVector), std::end(BigVector));
    if (it != std::end(BigVector))
    {
        std::cout << "找到: " << *it << '\n';
        std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }
    
    // 自定谓词比较
    it = std::adjacent_find(std::begin(BigVector),std::end(BigVector),
            [](int &m, int &n) { return m == n; });
    
    if (it != std::end(BigVector)) 
    {
        std::cout << "找到: " << *it << '\n';
        std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }
}

int main()
{
    AdjacentFind_2();
    return 0;
}