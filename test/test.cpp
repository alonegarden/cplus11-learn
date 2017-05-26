
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

int main()
{
    std::map<int, int> mySet;
    for(std::map<int,int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
    {
        it->first = 0;
    }

    return 0;
}
