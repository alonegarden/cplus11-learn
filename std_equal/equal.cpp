
//
// c++ 11  
// equal  : 返回两个范围是否相等。
//
 
/*
// <algorithm> 
​// 等价比较（1）    
template <class InputIterator1, class InputIterator2>
  bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2);
// 自定义谓词比较（2）    
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred);
        
*/ 


#include <iostream>
#include <algorithm>
#include <vector>
 
void Equal_2() {

    std::vector<int> BigVector = { 8, 23, 5, 6, 7, 29, 0, 5, 6, 7, 1, 1 };
    std::vector<int> SmallVector = { 8, 23, 5, 6, 7, 29, 0, 5, 6, 7, 1, 1 };

    // 等价比较

    bool b = std::equal(
            std::begin(BigVector),
            std::end(BigVector),
            std::begin(SmallVector));

    if (b)
    {
        std::cout << "相等" << '\n';
    }
    
    // 自定谓词比较

    b = std::equal(
            std::begin(BigVector),
            std::end(BigVector),
            std::begin(SmallVector),
            [](int &m, int &n) { return m == n; });
        
    if (b) 
    {
            std::cout << "相等" << '\n';
    }
}
int main()
{
    Equal_2();
    return 0;
}