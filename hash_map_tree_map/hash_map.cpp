
//
// c++ 11 test 
// 
//
 
#include <memory>
#include <string>
#include <iostream>
#include <unistd.h> 
#include <stdio.h>
#include <vector>
#include <map>
#include <ext/hash_map>
#include <sys/time.h>
using namespace std;
using namespace __gnu_cxx;

struct _stItem
{
    int a;
    int b;
}Item ;


map<int, _stItem> mapItem;
hash_map<int, _stItem> hashmapItem;

int xxMax = 6000000;

const int xxKey = 4004; 

long getTimeOfDay()
{
    //struct timeval tv;
    //gettimeofday(&tv,NULL);
    //return(long)tv.tv_sec*1000 + tv.tv_usec/1000;
    timespec _spec;
	clock_gettime(CLOCK_MONOTONIC,&_spec);
	long uTick = _spec.tv_sec * 1000 + _spec.tv_nsec / 1000 / 1000;
    return uTick;
}

int main()
{

    long t1 = 0;
    long t2 = 0;

    /////map init

    t1 = getTimeOfDay(); 
    for(int i=0; i < xxMax; ++i) 
    {
        _stItem item;
        item.a = 0;
        item.b = 100+i;
	    mapItem[i] = item;
    }

    t2 = getTimeOfDay();
    printf("[map init] t2-t1 = %ld\n", t2-t1);

      /////hashmap init

    t1 = getTimeOfDay(); 
    for(int i=0; i < xxMax; ++i) 
    {
        _stItem item;
        item.a = 0;
        item.b = 100+i;
        hashmapItem[i] = item;
    }

    t2 = getTimeOfDay(); 
    printf("[hashmap init] t2-t1 = %ld\n", t2-t1);

    ///// map begin to end

    t1 = getTimeOfDay(); 
    
    auto _pos = mapItem.begin();
    auto _end = mapItem.end();
    for(;_pos!=_end; ++_pos) 
    {
        int tmp = _pos->second.b;
    }

    t2 = getTimeOfDay();
    printf("[map begin] t2-t1 = %ld\n", t2-t1);
    
    ///// hashmap begin to end

    t1 = getTimeOfDay(); 
    
    auto _pos2 = hashmapItem.begin();
    auto _end2 = hashmapItem.end();
    for(;_pos2!=_end2; ++_pos2) 
    {
        int tmp = _pos2->second.b;
    }

    t2 = getTimeOfDay();
    printf("[hashmap begin] t2-t1 = %ld\n", t2-t1);
    
    /////hashmap erase

    t1 = getTimeOfDay(); 
    for(int i=0; i < xxMax; ++i) 
    {
        _stItem item;
        item.a = 0;
        item.b = 100+i;
	    hashmapItem.erase(i);
    }

    t2 = getTimeOfDay();
    printf("[hashmap erase] t2-t1 = %ld\n", t2-t1);

    /////  map erase

    t1 = getTimeOfDay(); 
    for(int i=0; i < xxMax; ++i) 
    {
        _stItem item;
        item.a = 0;
        item.b = 100+i;
	    mapItem.erase(i);
    }

    t2 = getTimeOfDay();
    printf("[map erase] t2-t1 = %ld\n", t2-t1);

    return 0;
}
