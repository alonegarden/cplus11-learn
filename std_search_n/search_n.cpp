
//
// c++ 11  
// search_n  : 在给定范围中查找第一个连续 n 个元素都等价于给定值的子范围的位置。
// 
 
/*
// <algorithm> 
// 等价比较（1）    
template <class ForwardIterator,
    class Size, class T>
    ForwardIterator search_n (
        ForwardIterator first,
        ForwardIterator last,
        Size count, const T& val);
// 自定义谓词比较（2）    
template <class ForwardIterator,
    class Size, class T,
    class BinaryPredicate>
    ForwardIterator search_n (
        ForwardIterator first,
        ForwardIterator last,
        Size count, const T& val,
        BinaryPredicate pred );
        
*/ 

#include <iostream>
#include <algorithm>
#include <vector>
 

void SearchN_2() 
{
    std::vector<int> BigVector = { 1, 99, 99, 2, 99, 99, 99, 3, 99, 99, 99, 4, 99, 99, 99, 99 };

    // 在序列中查找连续 3 个 99 第一次出现的位置
    // 等价比较

    std::vector<int>::iterator it = std::search_n(
            std::begin(BigVector),
            std::end(BigVector),
            3, 99);

    if (it != std::end(BigVector))
    {
            std::cout << "找到: " << *it << '\n';
            std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }

    // 自定谓词比较

    it = std::search_n(
            std::begin(BigVector),
            std::end(BigVector),
            3, 99,
            [](const int &m, const int &n) { return m == n; });

    if (it != std::end(BigVector)) 
    {
            std::cout << "找到: " << *it << '\n';
            std::cout << "前一个元素是: " << *(it - 1) << '\n';
    }
}
int main()
{
    SearchN_2();
    return 0;
}
