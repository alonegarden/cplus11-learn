
//
// c++ 11  
// lower_bound和 upper_bound
// 
/* 

stl 算法中有 lower_bound和 upper_bound, 在map中也一样有。两者的作用是一样的。

stl::lower_bound(key):返回vector中第一个大于或等于key的迭代器指针
stl::upper_bound(key):返回vector中第一个大于key的迭代器指针


*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
 
#define CLASSFOO_VECTOR(type, name, ...) \
static const type name##_a[] = __VA_ARGS__; \
std::vector<type> name(name##_a, name##_a + sizeof(name##_a) / sizeof(*name##_a))
 

void LowerBound_1() 
{

    // 构造一个 vector 对象
    CLASSFOO_VECTOR(int, foo, { 8, 23, -5, 7, 29, 0, 5, 7, -7, 1, -1 });
    // 调用 lower_bound 前必须已经排过序，至少按指定元素划分过（Partitioned）
    std::sort(foo.begin(), foo.end());
 
    std::vector<int>::iterator it;
 
    // --------- std::lower_bound ---------
    // 查找值至少（大于等于）为 5 的元素，并输出验证
    it = std::lower_bound(foo.begin(), foo.end(), 5);
    std::cout << *it << std::endl;
 
    // 查找值至少（大于等于）为 6 （实际不存在 6）的元素，并输出验证
    it = std::lower_bound(foo.begin(), foo.end(), 6);
    std::cout << *it << std::endl;
 
    // --------- std::upper_bound ---------
    // 查找值大于 5 的元素，并输出验证
    it = std::upper_bound(foo.begin(), foo.end(), 5);
    std::cout << *it << std::endl;
 
    // 查找值大于 6 （实际不存在 6）的元素，并输出验证
    it = std::upper_bound(foo.begin(), foo.end(), 6);
    std::cout << *it << std::endl;
}
int main()
{
    LowerBound_1();
    return 0;
}


