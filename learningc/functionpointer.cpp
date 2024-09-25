#include <iostream>
int add(int a,int b)
{
    return a+b;
}


int main()
{


    
    // 方法1 auto 关键词 ，它可以自动识别类型 
    auto fuc=add;   //当没有()的时候，add返回的是一个函数指针 
    std::cout<<fuc(1,2)<<std::endl;


    // 方法2 直接定义法 
    int(*fuc2)(int,int);    // 这样我们定义了一个和add函数类型相符合的函数指针。
    fuc2 = add ;
    std::cout<<fuc2(1,2)<<std::endl;

    // 方法3 typedef 方法 
    typedef int (*binaryFunction)(int ,int);  
    //这里的意思是，我们讲这种类型的函数指针，我们命名为 binaryFunction
    binaryFunction fuc3 = add;
    std::cout<<fuc(1,2)<<std::endl;



    


}