
//
// http://particle128.com/posts/2015/04/smart-ptr.html
//


#include <memory>
#include <string> 
using namespace std;

int main() 
{
    auto del = [] (string *ele) {delete ele;};
    
    // construct
    shared_ptr<string> p1;
    shared_ptr<string> p2(new string);
    shared_ptr<string> pd1(new string, del); // 此处不能用auto,auto只能推导复制构造!
    
    // copy construct
    shared_ptr<string> p4(p2);
    shared_ptr<string> p5 = make_shared<string>("1");
    
    auto p6 = make_shared<string>();
    auto p7(p6);
    
    // assign
    p1 = p2;
    // reset：用内建指针初始化和reset的格式一致
    p1.reset();
    p1.reset(new string);
    p1.reset(new string, del);
    
    // unique
    if (!p1.unique()) { /*if the string pointed by p1 has other references*/
        p1.reset(new string(*p1));
    }
    *p1 += "1"; /*change the string refered by p1*/
    
    // swap
    swap(p1,p2);
    p1.swap(p2);
    
    // * ->
    int size = p1->size();
    string s = *p1;
    
    // get
    string *ps = p1.get();
    
    // use_count
    int n = p1.use_count();

    // dynamic arrays
    shared_ptr<string> pp(new string[10], [](string *ps){delete []ps;});
    for (size_t i = 0; i != 10; ++i)
        *(pp.get() + i) = to_string(i);

    return 0;
}