
//
// c++ 11 learning
// override ˵����������ǶԻ��ຯ������д
// final ��˵��������������ܱ�������д
//

/////


#include <iostream>

using namespace std;

// ���� BB���е�f��B���е�f������һ��(�������Ͳ�һ��)
// �������������أ�������д��

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

// ����C���е�f��CC��f�������Ͳ�һ����(һ����const)  
// �������������أ�������д��

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
// �������� ��������Ϊ����д���ˣ����������Ҫ��д�麯����
//

/////

// override��Ӧ��
// DD���е�fһ��Ҫ��ȷ����д�����е��麯������Ȼ�ͻᱨ��
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

// finan��Ӧ��
// FF���f������дF�е��麯������Ϊ���ڳ����б�����Ϊ final
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
























