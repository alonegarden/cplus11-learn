
//
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/69.html
//

/*
 C++11��union���������������˷ſ�����������㷺�ĳ�Ա���͡�
 ����ֵ���ر�ָ�����ǣ������Զ��幹�캯��/������������������Ҳ����Ϊunion�ĳ�Ա�ˡ�
*/

#include<iostream>
struct point
{
    point() {}
    point(int x, int y): x_(x), y_(y) {}
    int x_, y_;
};

union U
{
    int z;
    double w;
    point p;  // ���Ϸ��� C++; point ��һ non-trivial ����ʽ // �Ϸ��� C++11            
};
    
int main()
{

    return 0;
} 