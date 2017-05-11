
//
// from http://particle128.com/posts/2015/04/smart-ptr.html
//

#include <memory>
#include <string> 
using namespace std;

string deref(unique_ptr<string> p) 
{
    if (p)
        return *p;
    else
        return string();
}

unique_ptr<string> clone(string s)
{
    return unique_ptr<string>(new string(s));
}

int main() 
{
    auto del = [] (string *ele) {delete ele;};
    // construct
    unique_ptr<string> p1;
    unique_ptr<string> p2(new string);
    unique_ptr<string, decltype(del)> pd1(new string, del); 
    // reset：用内建指针初始化和reset的格式一致
    p1.reset();
    p1.reset(new string);
    // swap
    swap(p1,p2);
    p1.swap(p2);
    // * ->
    int size = p1->size();
    string s = *p1;
    // get
    string *ps = p1.get();
    // release
    unique_ptr<string> p3(p1.release());
    p2.reset(p1.release()); // p1 release之后指向nullptr
    p1 = nullptr;

    // 一般情况下，unique_ptr不能拷贝构造和赋值
    // 只有一个例外：当unique_ptr马上要被析构的时候
    unique_ptr<string> ptr1 = clone(string("123")); // 最常见用法：函数返回
    string res = deref(unique_ptr<string>(new string("123"))); // string res1 = deref(p1); //不行
    auto ptr2((unique_ptr<string>())); // auto ptr2(p1); //不行
    ptr1 = unique_ptr<string>(); // ptr1 = p1; // 不行

    // dynamic arrays
    unique_ptr<string[]> pp(new string[10]);
    for (size_t i = 0; i != 10; ++i)
        pp[i] = to_string(i);

    return 0;
}