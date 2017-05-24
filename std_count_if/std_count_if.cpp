
//
// c++ 11 learning count
// 

/*
 count_if (InputIterator first, InputIterator last, UnaryPredicate pred);
 std::count_if  是std::count的扩展吧，pred是一个函数 在 [first,last) 找到符合这个函数的所有个数
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
 
void CountIf()
{
    std::vector<int> foo = { 19, 6, 2, 3, 4, 5, 6, 4, 6, 7, 8 };
    
    // 返回值为大于 5 的元素的个数
    std::cout << std::count_if(foo.begin(), foo.end(),
            [](int &n) { return n > 5; }) << std::endl;
}

int main()
{
    CountIf();
    return 0;
}