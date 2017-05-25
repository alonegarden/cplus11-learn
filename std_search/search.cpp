
//
// c++ 11  
// search  : 在范围 A 中查找第一个与范围 B 等价的子范围的位置。
// 
 
/*
// <algorithm> 
// 等价比较（1）
template <class ForwardIterator1,
    class ForwardIterator2>
    ForwardIterator1 search (
        ForwardIterator1 first1,
        ForwardIterator1 last1,
        ForwardIterator2 first2,
        ForwardIterator2 last2);
// 自定义谓词比较（2）    
template <class ForwardIterator1,
    class ForwardIterator2,
    class BinaryPredicate>
    ForwardIterator1 search (
        ForwardIterator1 first1,
        ForwardIterator1 last1,
        ForwardIterator2 first2,
        ForwardIterator2 last2,
        BinaryPredicate pred);
*/ 

#include <iostream>
#include <algorithm>
#include <vector>
 
void Search_2()
{
    std::vector<int> BigVector = { 8, 23, 5, 6, 7, 29, 0, 5, 6, 7, 1, 1 };
    std::vector<int> SmallVector = { 5, 6, 7 };

    // 等价比较

    auto it = std::search(
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

    it = std::search(
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
    Search_2();
    return 0;
}