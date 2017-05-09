//
// bind 用来绑定函数中的某一些参数
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/49.html

#include <functional>
#include <iostream>

using namespace std;
using namespace placeholders;

int f(int a, char c, double d)
{
    cout << a << endl;
    cout << c << endl;
    cout << d << endl;
 
    return a;
}

//  绑定 2 3 
void bind_1()
{
    auto ff = bind(f, _1, 'c', 1.2);
    int x = ff(7);
    cout << x << endl;
}

//  绑定 1 
void bind_2_3()
{
    auto ff = bind(f, 11, _1,_2);
    int x = ff('e', 1.3);
    cout << x << endl;
}

//////

// 构造一个函数对象，
// 它能表示的是一个返回值为float，
// 两个参数为int，int的函数

function<float (int x, int y)> func;   

// 构造一个可以使用"()"进行调用的函数对象类型
struct int_div {   
        float operator() (int x, int y) const
             { return ((float)x)/y; };
};

////
void print(function<float (int x, int y)> f)
{
    cout << f(10,2) << endl;
}

/////

void test_div()
{
    func = int_div();          // 赋值
    cout<< func(5,3) <<endl;   // 通过函数对象进行调用
    print(func);
}


/////

struct Xclass 
{
    int foo(int i ){ return i+1; };
};

/////

// 所谓的额外参数，
// 就是成员函数默认的第一个参数，
// 也就是指向调用成员函数的对象的this指针

function<int (Xclass*, int)> classfuc;   

/////
void test_xclass()
{
    classfuc = &Xclass::foo;            // 指向成员函数
    Xclass x;
    
    int v = classfuc(&x, 5);  // 在对象x上用参数5调用X::foo()
    cout << v << endl;

    function<int (int)> ff = std::bind(classfuc, &x, _1);    // f的第一个参数是&x
    v = ff(5);                // 调用x.foo(5)
    
    cout << v << endl;
}

/////

int main()
{
    //bind_1();
    //bind_2_3();
    //test_div();
    test_xclass();
    return 0;
}