
//
// from https://wizardforcel.gitbooks.io/cpp-11-faq/content/6.html
//

#include <iostream>
#include <map>

using namespace std;

/////
enum class _emItem
{
    Succeed,
    Fail,
    NoItem,
    NotEnough,
    
}

/////
enum class _emFaction
{
    Succeed,
    Fail,
    NoItem,
    NotEnough,
    
}

/////
enum EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };

/////
int main()
{
    return 0;
}


/*
// md

ö���ࣨ���µ�ö�١�/��ǿ���͵�ö�١�����Ҫ���������ͳ��C++ö�ٵ��������⣺
 * ��ͳC++ö�ٻᱻ��ʽת��Ϊint��������Щ��Ӧ��ת��Ϊint������¿��ܵ��´���
 * ��ͳC++ö�ٵ�ÿһö��ֵ����������Χ�ڶ��ǿɼ��ģ����׵������Ƴ�ͻ(ͬ����ͻ)
 * ������ָ��ö�ٵĵײ��������ͣ�����ܻᵼ�´��벻������⡢�����������Լ������Խ���ǰ������

 1 ��ͳ��c++11������
 ```c++
 enum Alert { green, yellow, election, red }; // ��ͳö��
 enum class Color { red, blue };               // �µľ��������ǿ���͵�ö����
 ```
 ����ö��ֵ������ⲿ�ǲ���ֱ�ӷ��ʵģ���ӡ�����::��
 ���ᱻ��ʽת����int

2. ������ֳ�ͻ

```c++
enum class Color { WHITE=1, BLACK=2 };
enum class Species { BLACK=1. WHITE=2, YELLOW=3, BROWN=4 };

// ʹ��ʱ��ö��������Ϊ�ϲ������ռ�
// Color::WHITE
// Color::BLACK
// Species::BLACK
// Species::YELLOW

```
3. ���Ͱ�ȫ

ö�ٲ���ֱ�Ӻ����ֱȽ�
```c++

// ���뱨��
if (Color::WHITE == 1) {
    // do something
}

```

4. ָ��ö�ٵĵײ��������ͣ����Կ��Խ��м򵥵Ļ�ͨ�����Լ���֤ö��ֵ��ռ���ֽڴ�С
```c++
 enum class Color : char { red, blue }; // �����ͱ�ʾ(һ���ֽ�)
 
 // C11�����ǿ���ָ��ö��ֵ�ĵײ��������ʹ�С 
 num EE : unsigned long { EE1 = 1, EE2 = 2, EEbig = 0xFFFFFFF0U };
 
 // Eռ�����ֽ��أ��ɹ���ֻ�ܸ����㣺ȡ���ڱ�����ʵ��
enum E { E1 = 1, E2 = 2, Ebig = 0xFFFFFFF0U };
```

6. ǰ��������. ��ö���ඨ��֮ǰ��ʹ�����ö�������������ָ������ñ���
```c++
enum class Color_code : char;     // (ǰ��) ����
void foobar(Color_code* p);   // ʹ��
// ...
// ����
enum class Color_code : char { red, yellow, green, blue };
```
7. enum class������
��ö�ٲ���class������һ�����������ͣ��������������͵ķ�װ����û������һ���Ĺ�����������ơ��������һ��δָ��ֵ��ö�٣���ôĬ��ֵ��0����ʹ������û��0

```c++
enum class Color { WHITE=1, BLACK=2 };
Color c;

static_cast<int>(c); // it's 0
 ```
 8. enum class���ܶ��巽��
 
*/