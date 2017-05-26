
//
// c++ 11  
// lower_bound和 upper_bound
// 
/* 

stl 算法中有 lower_bound和 upper_bound, 在map中也一样有。两者的作用是一样的。

map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
map::upper_bound(key):返回map中第一个大于key的迭代器指针


*/

#include <map>
#include <iostream>
using namespace std;

int main( )
{

    map <int, int> m1;
    map <int, int> :: const_iterator m1_AcIter, m1_RcIter;
    typedef pair <int, int> Int_Pair;

    m1.insert ( Int_Pair ( 1, 10 ) );
    m1.insert ( Int_Pair ( 2, 20 ) );
    m1.insert ( Int_Pair ( 3, 30 ) );

    //返回m1中第一个key值大于2的元素的迭代器，当然是<3,20>
    m1_RcIter = m1.upper_bound( 2 );
    cout << "The first element of map m1 with a key "
        << "greater than 2 is: "
        << m1_RcIter -> second << "." << endl;

    // If no match is found for the key, end is returned
    m1_RcIter = m1. upper_bound ( 4 );

    // m1中key值并没有大于或等于4的 
   if ( m1_RcIter == m1.end( ) )
        cout << "The map m1 doesn't have an element "
            << "with a key greater than 4." << endl;
    else
        cout << "The element of map m1 with a key > 4 is: "
            << m1_RcIter -> second << "." << endl;

    // The element at a specific location in the map can be found 
    // using a dereferenced iterator addressing the location
    m1_AcIter = m1.begin( );
    m1_RcIter = m1. upper_bound ( m1_AcIter -> first );
    cout << "The 1st element of m1 with a key greater than\n"
        << "that of the initial element of m1 is: "
        << m1_RcIter -> second << "." << endl;
                
    /////
   
    //key值大于2的是<3,30>
    m1_RcIter = m1.lower_bound( 2 );
    cout << "The first element of map m1 with a key of 2 is: "
        << m1_RcIter -> second << "." << endl;

    // If no match is found for this key, end( ) is returned
    m1_RcIter = m1. lower_bound ( 4 );

    if ( m1_RcIter == m1.end( ) )
      cout << "The map m1 doesn't have an element "
           << "with a key of 4." << endl;
    else
        cout << "The element of map m1 with a key of 4 is: "
           << m1_RcIter -> second << "." << endl;

    // The element at a specific location in the map can be found 
    // using a dereferenced iterator addressing the location
    m1_AcIter = m1.end( );
    m1_AcIter--;
    m1_RcIter = m1. lower_bound ( m1_AcIter -> first );
    cout << "The element of m1 with a key matching "
        << "that of the last element is: "
        << m1_RcIter -> second << "." << endl;
    
    return 0;
}


