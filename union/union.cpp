
//
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/69.html
//

/*
 C++11对union的限制条件进行了放宽，以允许更灵活广泛的成员类型。
 其中值得特别指出的是，带有自定义构造函数/析构函数的类型现在也可作为union的成员了。
*/

#include<iostream>
struct point
{
    point() {}
    point(int x, int y): x_(x), y_(y) {}
    int x_, y_;
};

union U
{
    int z;
    double w;
    point p;  // 不合法的 C++; point 有一 non-trivial 建构式 // 合法的 C++11            
};
    
int main()
{

    return 0;
} 