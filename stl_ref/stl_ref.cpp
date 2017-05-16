
//
// c++ 11 stl 
//

/*
引用包装器(Reference Wrapper)
当模板函数参数为泛型类型的时候，无法推导出是传值还是传引用，默认情况下会使用传值的方式。
这是我们可以用std::ref显式指定以传引用的方式实例化模板函数。
*/

#include <functional>
#include <iostream>

template <class T>
void foo(T arg)
{
    arg++;
}

int main()
{
    int count = 3;
    
    //此时传的是值，模板实例化为foo(int)，count值不变
    foo(count);        
    std::cout << count << std::endl;

     //此时传的是引用，模板实例化为foo(int&)，count值加1
    foo(std::ref(count));   
    std::cout << count << std::endl;
    return 0;
}
