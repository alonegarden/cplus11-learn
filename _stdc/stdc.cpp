
//
// c++ 11 直接结构体中进行初始化 如在 struct init 中的  string b{"hello"};
// 
//
 
#include <string>
#include <iostream>
#include <unistd.h> 
using namespace std;

struct C{
    C(int i): c(i) {} ;
    int c;
};

struct init {
   int a = 1; 
   string b{"hello"};
   C c{1};
};

int main ()
{

     return 0;
}
