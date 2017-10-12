
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

#include <iostream>
#include <vector>

class MyHome
{
public:
	MyHome(const std::initializer_list<int> &vec)
	 {
		for (auto item : vec)
		{
            m_Vec.push_back(item);
        }
    }

	void print()
	{
		for (auto item : m_Vec)
		{
        	std::cout << item << " ";
    }
    }
private:
    std::vector<int> m_Vec;
};

vector<int> Test_fuc() 
{
	string  ret = "{1, 3}";
	return ret;
}

int main()
{
    MyHome m = { 1, 2, 3};
    m.print();  // 1 2 3

    return 0;
}