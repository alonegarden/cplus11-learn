
//
// c++ 11 smart pointers 
// from http://particle128.com/posts/2015/04/smart-ptr.html
//
 
#include <memory>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    shared_ptr<string> sp(new string("123"));
    // construct
    weak_ptr<string> p1;
    weak_ptr<string> p2(sp);
    // copy construct
    weak_ptr<string> p3(p1);
    weak_ptr<string> p4 = p1;
    // assign
    p3 = p1;
    p3 = sp;
    // reset
    p3.reset();
    // use_count
    int n = p2.use_count();
    // expired
    bool expire = p2.expired(); // use_count() == 0 时返回true
    // lock
    if (shared_ptr<string> sp1 = p2.lock()) {
        cout << *sp1 << endl;
    }
    return 0;
}