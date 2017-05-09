
//
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/5.html
//

#include <iostream>
#include <map>

using namespace std;

// 用于声明变量
void test_auto_1()
{
    auto i = 1;
    cout << i << endl;
}

//  在stl的迭代器中运用，让代码简洁了很多。
void test_auto_2()
{
    map<int, int> map_list = 
    {
        {1, 100},
        {2, 200},
        {3, 300},
        {4, 400},
        {5, 500},
    };
    
    auto _pos = map_list.begin();
    auto _end = map_list.end();
    for (; _pos != _end; ++_pos)
    {
        cout << _pos->first << ": " << _pos->second << endl; 
    }
}

// 在模板运用
template <typename _Tx,typename _Ty>
void Multiply(_Tx x, _Ty y)
{
    auto v = x*y;
    std::cout << v;
}

/////
int main()
{
    //test_auto_1();
    test_auto_2();
    return 0;
}

/////

/*

1. auto 变量必须在定义时初始化，这类似于const关键字。

2. 定义在一个auto序列的变量必须始终推导成同一类型。例如：

```c++
auto a4 = 10, a5 = 20, a6 = 30;//正确
auto b4 = 10, b5 = 20.0, b6 = 'a';//错误,没有推导为同一类型
```

3. 使用auto关键字做类型自动推导时，依次施加一下规则：如果初始化表达式是引用，则去除引用语义。

```c++
int a = 10;
int &b = a;

auto c = b;//c的类型为int而非int&（去除引用）
auto &d = b;//此时c的类型才为int&

c = 100;//a =10;
d = 100;//a =100;
```

4. 如果初始化表达式为const或volatile（或者两者兼有），则除去const/volatile语义。

```c++
const int a1 = 10;
auto  b1= a1; //b1的类型为int而非const int（去除const）
const auto c1 = a1;//此时c1的类型为const int
b1 = 100;//合法
c1 = 100;//非法
```

5. 如果auto关键字带上&号，则不去除const语意。

```
const int a2 = 10;
auto &b2 = a2;//因为auto带上&，故不去除const，b2类型为const int
b2 = 10; //非法
```

6. 这是因为如何去掉了const，则b2为a2的非const引用，通过b2可以改变a2的值，则显然是不合理的。
初始化表达式为数组时，auto关键字推导类型为指针。

```c++ 
int a3[3] = { 1, 2, 3 };
auto b3 = a3;
cout << typeid(b3).name() << endl;
```

程序将输出

int *

7. 若表达式为数组且auto带上&，则推导类型为数组类型。

```c++
int a7[3] = { 1, 2, 3 };
auto & b7 = a7;
cout << typeid(b7).name() << endl;
```

程序输出

int [3]

8. 函数或者模板参数不能被声明为auto

```c++
void func(auto a)  //错误
{
//... 
}
```

9. 时刻要注意auto并不是一个真正的类型。
auto仅仅是一个占位符，它并不是一个真正的类型，不能使用一些以类型为操作数的操作符，如sizeof或者typeid。

```c++
cout << sizeof(auto) << endl;//错误
cout << typeid(auto).name() << endl;//错误
```

*/