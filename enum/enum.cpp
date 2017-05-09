
//
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/6.html
//

#include <iostream>
#include <map>

using namespace std;

/////
enum class _emItem
{
    Succeed,
    Fail,
    NoItem,
    NotEnough,
    
}

/////
enum class _emFaction
{
    Succeed,
    Fail,
    NoItem,
    NotEnough,
    
}

/////
enum EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };

/////
int main()
{
    return 0;
}


/*
// md

枚举类（“新的枚举”/“强类型的枚举”）主要用来解决传统的C++枚举的三个问题：
 * 传统C++枚举会被隐式转换为int，这在那些不应被转换为int的情况下可能导致错误
 * 传统C++枚举的每一枚举值在其作用域范围内都是可见的，容易导致名称冲突(同名冲突)
 * 不可以指定枚举的底层数据类型，这可能会导致代码不容易理解、兼容性问题以及不可以进行前向声明

 1 传统与c++11的区别
 ```c++
 enum Alert { green, yellow, election, red }; // 传统枚举
 enum class Color { red, blue };               // 新的具有类域和强类型的枚举类
 ```
 它的枚举值在类的外部是不可直接访问的，需加“类名::”
 不会被隐式转换成int

2. 指定枚举的底层数据类型，所以可以进行简单的互通操作以及保证枚举值所占的字节大小
```c++
 enum class Color : char { red, blue }; // 紧凑型表示(一个字节)
 
 // C11中我们可以指定枚举值的底层数据类型大小 
 num EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };
 
 // E占几个字节呢？旧规则只能告诉你：取决于编译器实现
enum E { E1 = 1, E2 = 2, Ebig = 0xFFFFFFF0U };
```

3. 前向声明得. 在枚举类定义之前就使用这个枚举类的名字声明指针或引用变量
```c++
enum class Color_code : char;     // (前向) 声明
void foobar(Color_code* p);   // 使用
// ...
// 定义
enum class Color_code : char { red, yellow, green, blue };
```


 
*/