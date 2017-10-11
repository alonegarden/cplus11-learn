
//
// c++ 11 smart pointers 
// from http://particle128.com/posts/2015/04/smart-ptr.html
//
 
/* singletonrace.cpp */  
#include <iostream>  
#include <cstdlib>  
#include <sstream>  
#include <cerrno>  
#include <cstring>  
#include <unistd.h>
#include <pthread.h>

#define MAX 1024  
#define ARRAYSIZE 1024*1024*50  
   
class Singleton 
{  
public:  
    static Singleton* Instance(int nsecs);  
protected:  
    Singleton();  
private:  
    static Singleton* _instance;  
    int array[ARRAYSIZE];  
};  
   
Singleton* Singleton::_instance = 0;  
   
Singleton::Singleton() { }  
/* 
Singleton::Singleton() { 
        int idx; 
        for (idx = 0; idx < ARRAYSIZE; idx++) { 
                 array[idx] = 0; 
        } 
} 
*/  
   
Singleton* Singleton::Instance (int threadId)
{  
    if (_instance == 0) {  
        ::sleep(threadId%32 + 3);  
            _instance = new Singleton();  
    }  
    
    return _instance;  
}  
   
int runningThread = 0;  
   
void * fun(void *id)
{  
    runningThread++;  
    int threadId = *(int *)id;  
    Singleton::Instance(threadId);  
    runningThread--;  
}  
   
int main(int argc, char *argv[])  
{  
    int idx = 0;  
    pthread_attr_t thrattr;  
    pthread_t thr[MAX];  
    int id[MAX] = {0};  
    int err;  
   
    if (argc != 2) 
    {  
        std::cout << "bad command\ncommand:" << argv[0] << " cnt" << std::endl;  
        return -1;  
    }  
    
    int cnt = atoi(argv[1]);  
    if (cnt < 0 || cnt > MAX) 
    {  
        cnt = MAX;  
    }  
   
    if (err = pthread_attr_init(&thrattr) != 0) 
    {  
        std::cout << "pthread_attr_init error:" << std::strerror(err) << std::endl;  
        return -1;  
    }  
    
    if (err = pthread_attr_setstacksize(&thrattr, 102400) != 0) 
    {  
        std::cout << "pthread_attr_init error:" << std::strerror(err) << std::endl;  
        return -1;  
    }  
   
    while(idx < cnt) 
    {  
        id[idx] = idx;  
        if (err = pthread_create(&thr[idx], &thrattr, fun, &id[idx]) != 0) 
        {  
            std::cout << "thread " << idx << " create faild:" << std::strerror(err) << std::endl;  
            std::cout.flush();  
            sleep(1);  
        } 
        else
        {  
            std::cout << "thread " << idx << " created" << std::endl;  
            std::cout.flush();  
            idx++;  
        }  
    }  
   
    do{  
            sleep(1);  
            std::cout << "runningThread:" << runningThread << std::endl;  
    } while(runningThread);  
   
    std::cout << "exit without coredump" << std::endl;  
    return 0;  

}  