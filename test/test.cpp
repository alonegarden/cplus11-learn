
//
// c++ 11 test 
// 
//
 
#include <memory>
#include <string>
#include <iostream>
#include <unistd.h> 
#include <map>
using namespace std;



void test1()
{
    static int stA = 0;
    printf ("stA = %d\n", stA);
    stA++;
}

void test2()
{
   static int stA = 5;
    printf ("stA = %d\n", stA);

}
int main()
{
     test1();
     test1();
     test2();
     return 0;
}
