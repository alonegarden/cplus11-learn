
//
// c++11 learning  
// 基于范围的 for 循环
// from http://zh.cppreference.com/w/cpp/language/range-for
//

#include <iostream>
#include <vector>
 
 using namespace  std;
 
int main()
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};
    
    // 以 const 引用访问
    for (const int& i : vec)
        std::cout << i << ' ';
    cout << '\n';
 
    // 以值访问， i 的类型是 int
    for (auto i : vec) 
        std::cout << i << ' ';
    cout << '\n';
 
    // 以引用访问， i 的类型是 int&
    for (auto&& i : vec) 
        std::cout << i << ' ';
    cout << '\n';
 
    // 初始化器可以是花括号初始化列表
    for (int n : {0, 1, 2, 3, 4, 5}) 
        std::cout << n << ' ';
    cout << '\n';
 
    int a[] = {0, 1, 2, 3, 4, 5};

    // 初始化器可以是数组
    for (int n : a) 
        std::cout << n << ' ';
    cout << '\n';
 
    // 循环变量不必使用
    for (int n : a)  
        std::cout << 1 << ' '; 
    cout << '\n';
    
    cout << '\n';
    
   return 0;
}
