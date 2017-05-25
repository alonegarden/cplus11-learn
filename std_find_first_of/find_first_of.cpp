
//
// c++ 11 test 
// find_first_of  : 查找范围 A 中第一个与范围 B 中任一元素等价的元素的位置。
// 
 
/*
// <algorithm> 
// 等价比较（1）
template <class InputIterator,
    class ForwardIterator>
    ForwardIterator1 find_first_of (
        InputIterator first1,
        InputIterator last1,
        ForwardIterator first2,
        ForwardIterator last2);
// 自定义谓词比较（2）
template <class InputIterator,
    class ForwardIterator,
    class BinaryPredicate>
    ForwardIterator1 find_first_of (
        InputIterator first1,
        InputIterator last1,
        ForwardIterator first2,
        ForwardIterator last2,
        BinaryPredicate pred);
*/ 
#include <iostream>
#include <algorithm>
#include <vector>
 

void FindFirstOf_2() 
{
    std::vector<int> BigVector = { 8, 23, 5, 6, 7, 29, 0, 5, 6, 7, 1, 1 };
    std::vector<int> SmallVector = { 18, 9, 123, 66, 5, 6, 7 };

    // 等价比较
    auto it = std::find_first_of(
            std::begin(BigVector),
            std::end(BigVector),
            std::begin(SmallVector),
            std::end(SmallVector));
    
    if (it != std::end(BigVector))
    {
        std::cout << "找到: " << *it << '\n';
        std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }
    
    // 自定谓词比较
    it = std::find_first_of(
        std::begin(BigVector),
        std::end(BigVector),
        std::begin(SmallVector),
        std::end(SmallVector),
        [](int &m, int &n) { return m == n; });
    
    if (it != std::end(BigVector)) 
    {
        std::cout << "找到: " << *it << '\n';
        std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }
}
int main()
{
    FindFirstOf_2();
    return 0;
}