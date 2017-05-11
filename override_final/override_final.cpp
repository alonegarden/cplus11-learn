
//
// c++ 11 learning
// override 说明这个函数是对基类函数的重写
// final 则说明，这个函数不能被子类重写
//

/////


#include <iostream>

using namespace std;

// 由于 BB类中的f和B类中的f声明不一样(参数类型不一样)
// 所以这里是重载，不是重写。

class B 
{
public:
   virtual void f(short) {std::cout << "B::f" << std::endl;}
};
 
class BB : public B
{
public:
   virtual void f(int) {std::cout << "BB::f" << std::endl;}
};

//////

// 由于C类中的f和CC类f返回类型不一样，(一个有const)  
// 所以这里是重载，不是重写。

class C 
{
public:
   virtual void f(int) const {std::cout << "C::f " << std::endl;}
};
 
class CC : public C
{
public:
   virtual void f(int) {std::cout << "CC::f" << std::endl;}
};

//
// 如上两种 可能是因为笔误写错了，本意可能是要重写虚函数的
//

/////

// override的应用
// DD类中的f一定要正确的重写基类中的虚函数，不然就会报错。
//
class D 
{
public:
   virtual void f(short) {std::cout << "D::f" << std::endl;}
};
 
class DD : public D
{
public:
   // virtual void f(int) override {std::cout << "DD::f" << std::endl;} //error
    virtual void f(short) override {std::cout << "DD::f" << std::endl;} // ok
};

/////

// finan的应用
// FF类的f不能重写F中的虚函数，因为它在碁类中被声明为 final
class F : public D
{
public:
   virtual void f(short) override final {std::cout << "F::f" << std::endl;}
};

class FF : public F
{
public:
   // virtual void f(short) override final {std::cout << "FF::f" << std::endl;} //error
};

//
// 
//

int main()
{
    return 0;
}
























