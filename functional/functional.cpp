
//
// c++11 functional  learning
//

#include <iostream>
#include <map>
#include <functional>
using namespace std;

// 普通函数
int add(int i, int j) { return i + j; }

// lambda表达式
auto mod = [](int i, int j){return i % j; };

// 函数对象类
struct divide
{
    int operator() (int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

////
int main(int argc, char *argv[])
{

    // map 这种初始化方式只在c++11下
    map<char, function<int(int, int)>> funnc_list = 
    {
        { '+', add },
        { '-', minus<int>() },
        { '*', [](int i, int j){return i * j; } },
        { '/', divide() },
        { '%', mod },
    };

    ///// 
    cout << funnc_list['+'](10, 5) << endl;
    cout << funnc_list['-'](10, 5) << endl;
    cout << funnc_list['*'](10, 5) << endl;
    cout << funnc_list['/'](10, 5) << endl;
    cout << funnc_list['%'](10, 5) << endl;
    
    return 0;
}
