
//
// c++ 11 learning unoedered map
//


#include <unordered_map>
#include <iostream>

using namespace std;

namespace ClassFoo{
void PrintIntDoubleUnOrderedMap( unordered_map<int,double>& m, char* pre) {
    unordered_map<int,double>::iterator it;
    cout << pre;
    for ( it = m.begin(); it != m.end(); it++ )
         cout << "(" << it->first << "," << it->second << ") ";
     cout <<  endl;
}

/////
void UnOrderedMapExample1() {
     unordered_map<int,double> foo1;
    // operator[]������������ʱ���Զ�����
    foo1[0] = 32.8;
    // ��ͨ����
    foo1.insert( unordered_map<int,double>::value_type(1, 33.2));
    // ����ʾ���룬std::pair<int,double>�ȼ���������
    //  unordered_map<int,double>::value_type
    foo1.insert(foo1.end(), pair<int,double>(2,35.8));
    
    // ����һ����Χ
     unordered_map<int,double> foo2;
    foo2.insert( unordered_map<int,double>::value_type(3, 36.4));
    foo2.insert( unordered_map<int,double>::value_type(4, 37.8));
    foo2.insert( unordered_map<int,double>::value_type(5, 35.4));
    foo1.insert(foo2.begin(),foo2.end());
    PrintIntDoubleUnOrderedMap(foo1,"����Ԫ�غ��foo1��");
    // ��������4
     unordered_map<int,double>::iterator it;
    it = foo1.find(4);
    if( it != foo1.end() )
    {
         cout << "foo1.find(4)��";
         cout << "(" << it->first << "," << it->second << ")" 
            <<  endl;
    }
    // ɾ�������ҵ���Ԫ��
    if( it != foo1.end() )
    {
        foo1.erase(it);
    }
    PrintIntDoubleUnOrderedMap(foo1,"ɾ������Ϊ4��Ԫ�غ��foo1��");
    
    // ����ɾ������Ϊ2��Ԫ��
    for(it = foo1.begin();it != foo1.end();it++)
    {
        //����ɾ����������2
        //ע�⣬ɾ��Ԫ�ػ�ʹ������Χ�����仯
        if(it->first == 2)
        {
            foo1.erase(it);
            break;
        }
    }
    // �ڲ�����
     cout << "bucket_count��" << foo1.bucket_count() <<  endl;
     cout << "max_bucket_count��" << foo1.max_bucket_count() <<  endl;
     cout << "bucket_size��" << foo1.bucket_size(0) <<  endl;
     cout << "load_factor��" << foo1.load_factor() <<  endl;
     cout << "max_load_factor��" << foo1.max_load_factor() <<  endl;
    PrintIntDoubleUnOrderedMap(foo1,"ɾ������Ϊ2��Ԫ�غ��foo1��");
    foo1.clear();
    PrintIntDoubleUnOrderedMap(foo1,"��պ��foo1��");
}
}
int main( )
{
    ClassFoo::UnOrderedMapExample1();
    return 0;
}