
//
// c++ 11 learning 
// 

/*
 InputIterator find_if (
        InputIterator first,
        InputIterator last,
        ​UnaryPredicate pred);
 std::find_if  找到[first, last)中找到符合pred的 找到了返回跌代器，找不到返回end， pred是函数
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 

void FindIf_2()
{
    std::vector<int> v{ 0, 1, 2, 3, 4 };
    // 查找值大于 3 元素
 
    auto it = std::find_if(std::begin(v), std::end(v), [](int &n) { return n > 3; });
 
    if (it != std::end(v))
    {
        std::cout << "I find it." << '\n';
    }
}

/////

int main()
{
    FindIf_2();
    return 0;
}
