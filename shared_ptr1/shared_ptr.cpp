
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

int main()
{
    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout<<ptest2->getStr()<<endl;
    cout<<ptest2.use_count()<<endl;
    ptest = ptest2;//"456"引用次数加1，“123”销毁
    ptest->print();
    cout<<ptest2.use_count()<<endl;//2
    cout<<ptest.use_count()<<endl;//2
    ptest.reset();
    ptest2.reset();//此时“456”销毁
    cout<<"done !\n";
    return 0;
}



/*
从名字share就可以看出了资源可以被多个指针共享，
它使用计数机制来表明资源被几个指针共享。可以通过成员函数use_count()来查看资源的所有者个数。出了可以通过new来构造，
还可以通过传入auto_ptr, unique_ptr,weak_ptr来构造。当我们调用release()时，当前指针会释放资源所有权，计数减一。
当计数等于0时，资源会被释放。具体的成员函数解释可以参考 

*/



