
//
// c++ 11 learning
// default 函数 让编译器会为这个类生成一个默认的成员特殊函数。默认构造函数，析构函数等
// 这样编译器就会自动生成默认构造函数T::T(){}，从而获得更高的代码执行效率。

class T {
    private:
        int apple;
    public:
        // T(){}        // 旧的方式 
        T() = default; // 默认构造函数 c++ 11
        T & operator = (const T&) = delete; // 显式地禁止这个方法 c++ 11
        T(int banana) { apple = banana; }
};

/////

int main()
{
    T t;
    return 0;
}