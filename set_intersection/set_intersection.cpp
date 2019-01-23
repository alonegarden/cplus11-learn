
//
// c++ 11 test 
// 
// use set_intersection 
 
#include <memory>
#include <string>
#include <iostream>
#include <unistd.h> 

#include <set>
#include <algorithm>
using namespace std;

void test_set_intersection()
{
    std::set<int> setAList; 
    setAList.insert(1); 
    setAList.insert(2); 
    setAList.insert(3); 
    setAList.insert(4); 
    setAList.insert(5); 

    std::set<int> setBList;
    setBList.insert(1);
    setBList.insert(5);

    std::set<int> setCList;
    set_intersection(setAList.begin(),setAList.end(),setBList.begin(),setBList.end(),inserter( setCList , setCList.begin() ));  
    printf("setCList size  = %d\n", setCList.size());
    return ;
}
int main()
{
    test_set_intersection();
    return 0;
}
