
//
// c++ 11 learning 元组
//


#include <iostream>  
#include <tuple>  
#include<vector>  

using namespace std;
using std::cout ;  
using std::endl ;  
using std::tuple;  
using std::vector;  
using std::string;  
using std::get;  
using std::make_tuple ;  
  
 
auto handleCmd()  
{  
    auto t1 = make_tuple(1, "a1", "b1", "c1");  
    cout << get<0>(t1) << " ";  
    cout << get<1>(t1) << " ";  
    cout << get<2>(t1) << " ";  
    cout << get<3>(t1) << " ";  
    cout << endl;  
  
    vector<tuple<int, string, string, string> > tv;  
  
    tv.push_back(make_tuple(1, "a1", "b1", "c1"));  
    tv.push_back(make_tuple(2, "a2", "b2", "c2"));  
  
    vector< tuple<int, string, string ,string> >::iterator itr;  
    for (itr=tv.begin(); itr!=tv.end(); itr++)  
    {  
        cout << get<0>(*itr) << " ";  
        cout << get<1>(*itr) << " ";  
        cout << get<2>(*itr) << " ";  
        cout << get<3>(*itr) << endl;  
    }  
  
    return t1;  
}  

int main()
{
    handleCmd();
    return 0;
}

/*

md
---

tuple是一个固定大小的不同类型值的集合，是泛化的std::pair。和c#中的tuple类似，但是比c#中的tuple强大得多。
我们也可以把他当做一个通用的结构体来用，不需要创建结构体又获取结构体的特征，在某些情况下可以取代结构体使程序更简洁，直观。
```c++
tuple<const char*, int>tp = make_tuple(sendPack,nSendSize); //构造一个tuple
```

这个tuple等价于一个结构体

```
struct A
{
    char* p;
    int len;
};
```
还有一种方法也可以创建元组，用std::tie，它会创建一个元组的左值引用。

```c++
auto tp = return std::tie(1, "aa", 2);
//tp的类型实际是：
std::tuple<int&,string&, int&>
```
再看看如何获取它的值：

```c++
const char* data = tp.get<0>(); //获取第一个值
int len = tp.get<1>(); //获取第二个值
```

还有一种方法也可以获取元组的值，通过std::tie解包tuple

```c++
int x,y;
string a;
std::tie(x,a,y) = tp; 
```

通过tie解包后，tp中三个值会自动赋值给三个变量。

解包时，我们如果只想解某个位置的值时，可以用std::ignore占位符来表示不解某个位置的值。比如我们只想解第三个值时：

```c++
std::tie(std::ignore,std::ignore,y) = tp; //只解第三个值了
```

还有一个创建右值的引用元组方法：forward_as_tuple。

```c++
std::map<int, std::string> m;
m.emplace(std::forward_as_tuple(10, std::string(20, 'a')));
```
它实际上创建了一个类似于std::tuple<int&&, std::string&&>类型的tuple。

我们还可以通过tuple_cat连接多个tupe

```c++
int main()
{
    std::tuple<int, std::string, float> t1(10, "Test", 3.14);
    int n = 7;
    auto t2 = std::tuple_cat(t1, std::make_pair("Foo", "bar"), t1, std::tie(n));
    n = 10;
    print(t2);
}
```
输出结果：
(10, Test, 3.14, Foo, bar, 10, Test, 3.14, 10)


*/