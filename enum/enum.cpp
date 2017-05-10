
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

2. 解决名字冲突

```c++
enum class Color { WHITE=1, BLACK=2 };
enum class Species { BLACK=1. WHITE=2, YELLOW=3, BROWN=4 };

// 使用时，枚举类型名为上层命名空间
// Color::WHITE
// Color::BLACK
// Species::BLACK
// Species::YELLOW

```
3. 类型安全

枚举不能直接和数字比较
```c++

// 编译报错
if (Color::WHITE == 1) {
    // do something
}

```

4. 指定枚举的底层数据类型，所以可以进行简单的互通操作以及保证枚举值所占的字节大小
```c++
 enum class Color : char { red, blue }; // 紧凑型表示(一个字节)
 
 // C11中我们可以指定枚举值的底层数据类型大小 
 num EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };
 
 // E占几个字节呢？旧规则只能告诉你：取决于编译器实现
enum E { E1 = 1, E2 = 2, Ebig = 0xFFFFFFF0U };
```

6. 前向声明得. 在枚举类定义之前就使用这个枚举类的名字声明指针或引用变量
```c++
enum class Color_code : char;     // (前向) 声明
void foobar(Color_code* p);   // 使用
// ...
// 定义
enum class Color_code : char { red, yellow, green, blue };
```
7. enum class不是类
新枚举不是class，而是一个单独的类型，更像是整数类型的封装。它没有像类一样的构造和析构机制。如果定义一个未指定值的枚举，那么默认值是0，即使定义中没有0

```c++
enum class Color { WHITE=1, BLACK=2 };
Color c;

static_cast<int>(c); // it's 0
 ```
 8. enum class不能定义方法
 
*/