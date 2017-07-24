
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

#include <stdio.h>

#include <vector>

int main ()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(6);

    auto iter = vec.begin();
    for (;iter!=vec.end(); iter++)
    {
        if(*iter == 3)
            iter = vec.erase(iter);
        //else 
        //    ++iter;
    }

    for (iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << " "; 
    }

    return 0;
}
