
//
// c++ 11 learning
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/18.html
//


/*
二.lambda表达式

lambda表达式有如下优点：

1).声明式编程风格:就地匿名定义目标函数或函数对象，不需要额外写一个命名函数或者函数对象。以更直接的方式去写程序，好的可读性和可维护性。

2).简洁：不需要额外再写一个函数或者函数对象，避免了代码膨胀和功能分散，让开发者更加集中精力在手边的问题，同时也获取了更高的生产率。

3).在需要的时间和地点实现功能闭包，使程序更灵活。

 

lambda表达式的语法归纳如下：

[ caputrue ] ( params ) opt -> ret { body; };

1).capture是捕获列表；

2).params是参数表；(选填)

3).opt是函数选项；可以填mutable,exception,attribute（选填）

mutable说明lambda表达式体内的代码可以修改被捕获的变量，并且可以访问被捕获的对象的non-const方法。

exception说明lambda表达式是否抛出异常以及何种异常。

attribute用来声明属性。

4).ret是返回值类型。(选填)

5).body是函数体。

 

捕获列表：lambda表达式的捕获列表精细控制了lambda表达式能够访问的外部变量，以及如何访问这些变量。

1).[]不捕获任何变量。

2).[&]捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。

3).[=]捕获外部作用域中所有变量，并作为副本在函数体中使用(按值捕获)。

4).[=,&foo]按值捕获外部作用域中所有变量，并按引用捕获foo变量。

5).[bar]按值捕获bar变量，同时不捕获其他变量。

6).[this]捕获当前类中的this指针，让lambda表达式拥有和当前类成员函数同样的访问权限。如果已经使用了&或者=，就默认添加此选项。捕获this的目的是可以在lamda中使用当前类的成员函数和成员变量。


注意的细节：

1. 一个容易出错的细节是lambda表达式的延迟调用，lambda表达式按值捕获了所有外部变量。
在捕获的一瞬间，a的值就已经被复制了。如果希望lambda表达式在调用时能即时访问外部变量，我们应当使用引用方式捕获。

```c++
int a = 0;  
auto f = [=] { return a; };  
  
a+=1;  
  
cout << f() << endl;       //输出0  
  
  
int a = 0;  
auto f = [&a] { return a; };  
  
a+=1;  
  
cout << f() <<endl;       //输出1  
```

2.虽然按值捕获的变量值均补复制一份存储在lambda表达式变量中， 修改他们也并不会真正影响到外部，但我们却仍然无法修改它们。
　那么如果希望去修改按值捕获的外部变量，需要显示指明lambda表达式为mutable。
  需要注意：被mutable修饰的lambda表达式就算没有参数也要写明参数列表。
　原因：lambda表达式可以说是就地定义仿函数闭包的“语法糖”。
  它的捕获列表捕获住的任何外部变量，最终均会变为闭包类型的成员变量。 
  按照C++标准，lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量的值的。
  而mutable的作用，就在于取消operator()的const。

```c++
int a = 0;  
auto f1 = [=] { return a++; };                  //error  
auto f2 = [=] () mutable { return a++; };       //OK  

3.没有捕获变量的lambda表达式可以直接转换为函数指针，而捕获变量的lambda表达式则不能转换为函数指针。原因可以参考2中的原因。
 
```c++
typedef void(*Ptr)(int*);  
Ptr p = [](int* p) { delete p; };              //OK  
Ptr p1 = [&] (int* p) { delete p; };         //error  
 ```

```c++
std::vector<int> v = { 1, 2, 3, 4, 5, 6 };  
int even_count = 0;  
for_each(v.begin(), v.end(), [&even_count](int val){  
    if(!(val & 1)){  
        ++ even_count;  
    }  
});  
std::cout << "The number of even is " << even_count << std::endl;  

//////

int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x > 10; });  
  
int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x < 10; });  
  
int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x > 5 && x<10; });  
```
*/

#include<iostream>
using namespace std;

class A  
{  
public:  
    int i_ = 0;  
      
    void func(int x,int y)
    {  
        //auto x1 = [] { return i_; };                      // error,没有捕获外部变量  
        auto x2 = [=] { return i_ + x + y; };               // OK  
        auto x3 = [&] { return i_ + x + y; };               // OK  
        auto x4 = [this] { return i_; };                    // OK  
        //auto x5 = [this] { return i_ + x + y; };          // error,没有捕获x,y  
        auto x6 = [this, x, y] { return i_ + x + y; };      // OK  
        auto x7 = [this] { return i_++; };                  // OK 
    }        
};  

int main()
{  
    int a=0 , b=1;  
    //auto f1 = [] { return a; };                           // error,没有捕获外部变量      
    auto f2 = [&] { return a++; };                          // OK  
    auto f3 = [=] { return a; };                            // OK  
    //auto f4 = [=] {return a++; };                         // error,a是以复制方式捕获的，无法修改  
    //auto f5 = [a] { return a+b; };                        // error,没有捕获变量b  
    auto f6 = [a, &b] { return a + (b++); };                // OK  
    auto f7 = [=, &b] { return a + (b++); };                // OK  
    return 0;
}





