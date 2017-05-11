
//
// c++11 
// from http://www.cnblogs.com/TenosDoIt/p/3456704.html
//

/////
/*
 四个智能指针: auto_ptr, shared_ptr, weak_ptr, unique_ptr.
 auto_ptr已经被c++11 弃用。
*/

//////

#include<iostream>
#include <memory>

using namespace std;

class Test
{
public:
    Test(string s)
    {
        str = s;
       cout<< "Test creat\n";
    }
    
    ~Test()
    {
        cout<< "Test delete:"<< str <<endl;
    }
    
    string& getStr()
    {
        return str;
    }
    
    void setStr(string s)
    {
        str = s;
    }
    
    void print()
    {
        cout<< str << endl;
    }
private:
    string str;
};

//////
unique_ptr<Test> fun()
{
    return unique_ptr<Test>(new Test("789"));
}

/////

int main()
{
    unique_ptr<Test> ptest(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));

    ptest->print();
    ptest2 = std::move(ptest);//不能直接ptest2 = ptest

    if(ptest == nullptr)
        cout<< "ptest = nullptr" << endl;
    
    Test* p = ptest2.release(); // release()后不会被释放吗?
    p->print();
    
    if (p == nullptr)
        cout<< "p = nullptr" << endl;
    
    if (ptest2 == nullptr)
        cout<< "ptest2 = nullptr" << endl;
    
    ptest.reset(p);
    
    ptest->print()
    ;
    auto ptest3 = fun(); //这里可以用=，因为使用了移动构造函数
    ptest3->print();
    
    p->print(); 
     
    
    return 0;
}

/*
结果：
Test creat
Test creat
123
Test delete:456
ptest = nullptr
123
ptest2 = nullptr
123
Test creat
789
Test delete:789
Test delete:123
*/

/*
unique_ptr 是一个独享所有权的智能指针，它提供了严格意义上的所有权，包括：

1. 拥有它指向的对象

2. 无法进行复制构造，无法进行复制赋值操作。即无法使两个unique_ptr指向同一个对象。但是可以进行移动构造和移动赋值操作

3. 保存指向某个对象的指针，当它本身被删除释放的时候，会使用给定的删除器释放它指向的对象

unique_ptr 可以实现如下功能：

1. 为动态申请的内存提供异常安全

2. 讲动态申请的内存所有权传递给某函数

3. 从某个函数返回动态申请内存的所有权

4. 在容器中保存指针

5. auto_ptr 应该具有的功能

//////////////////////////////////////////

补充一下auto_prt的知识。

int main()
{
    auto_ptr<Test> ptest(new Test("123"));
    ptest->setStr("hello ");
    ptest->print();
    ptest.get()->print();
    ptest->getStr() += "world !";
    (*ptest).print();
    ptest.reset(new Test("123"));
    ptest->print();
    return 0;
}

当我们对智能指针进行赋值时，如ptest2 = ptest，ptest2会接管ptest原来的内存管理权，ptest会变为空指针，如果ptest2原来不为空，则它会释放原来的资源，
基于这个原因，应该避免把auto_ptr放到容器中，因为算法对容器操作时，很难避免STL内部对容器实现了赋值传递操作，这样会使容器中很多元素被置为NULL。
判断一个智能指针是否为空不能使用if(ptest == NULL)，应该使用if(ptest.get() == NULL)，

*/



