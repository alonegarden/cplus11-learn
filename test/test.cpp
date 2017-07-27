
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
	int a = 9;
	int *p = &a;
	int psize = sizeof(p);
	int asize = sizeof(a);
	printf("psizeof=%d asize=%d\n", psize, asize);
	return 0;
}
