
//
// c++ 11  
// mismatch  : 返回两个范围中第一个元素不等价的位置。
//
 
/*
// <algorithm> 
// 等价比较（1）    
template <class InputIterator1,
    class InputIterator2>
    pair<InputIterator1, InputIterator2>
    mismatch (InputIterator1 first1,
              InputIterator1 last1,
              InputIterator2 first2);
// 自定义谓词比较（2）
template <class InputIterator1,
    class InputIterator2,
    class BinaryPredicate>
    pair<InputIterator1, InputIterator2>
    mismatch (InputIterator1 first1,
              InputIterator1 last1,
              InputIterator2 first2,
              BinaryPredicate pred);
        
*/ 

#include <iostream>
#include <algorithm>
#include <vector>
 

void Mismatch_2() 
{

    std::vector<int> BigVector = { 8, 23, 5, 6, 7, 29, 0, 5, 6, 7, 1, 1 };
    std::vector<int> SmallVector = { 8, 23, 5, 6, 3, 29, 0, 13, 6, 7, 1, 0 };

    // 等价比较
    auto p = std::mismatch(
            std::begin(BigVector),
            std::end(BigVector),
            std::begin(SmallVector));

    if (p.first != std::end(BigVector)) 
    {
        std::cout << "找到: " << *p.first << '\n';
        std::cout << "前一个元素是: " << *(p.first - 1) << '\n';
    }
    
    // 自定谓词比较
    p = std::mismatch(
            std::begin(BigVector),
            std::end(BigVector),
            std::begin(SmallVector),
            [](int &m, int &n) { return m == n; });

    if (p.first != std::end(BigVector))
    {
            std::cout << "找到: " << *p.first << '\n';
            std::cout << "前一个元素是: " << *(p.first - 1) << '\n';
    }
}
int main()
{
    Mismatch_2();
    return 0;
}