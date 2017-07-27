
//
// c++ 11 v-table 
// 
//
 
#include <memory>
#include <string>
#include <iostream>
#include <unistd.h> 
#include <stdio.h>
using namespace std;

class Base {

public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
private:
	virtual void j() { cout << "Base::j" << endl; }
};

class dev: public Base  
{  
public:  
	virtual void k() { cout << "dev::k" << endl; }  
};  

int main ()
{
	typedef void(*Fun)(void);
	Base b;
	Fun pFun = NULL;
	Fun pFun1 = NULL;
	Fun pFun2 = NULL;
	
	cout << "虚函数表地址：" << (long*)(&b) << endl;
	cout << "虚函数表 — 第一个函数地址：" << (long*)*(long*)(&b) << endl;
	
	// Invoke the first virtual function
	pFun  = (Fun)*((long*)*(long*)(&b)+0);
	pFun1 = (Fun)*((long*)*(long*)(&b)+1);
	pFun2 = (Fun)*((long*)*(long*)(&b)+2);
	
 	pFun();
 	pFun1();
 	pFun2();

	/////

	dev d;
	//d.f();             //compile error  
	//通过函数指针访问到私有的j(), j()对于对象来讲本来是不可见的,指针太强大  
        Fun pFun3 = (Fun)*((long*)*(int*)(&d)+3);   
        pFun3();  
	
	/////

	Base *b2 = new dev();  
    	//b2->k();           //compile error,父类指针无法call子类特有的虚函数  
    	//通过函数指针访问到子类特有的虚函数k(), 指针太强大  
    	Fun pFun4 = (Fun)*((long*)*(int*)b2+4);   
    	pFun4();  
    	return 0;
}
