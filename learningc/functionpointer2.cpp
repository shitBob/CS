#include <iostream>>

int add(int a, int b)
{
    return a+b;
}

int product(int a, int b)
{
    return a*b;
}

int dosome(int a, int b,int(*func)(int,int))
{
    return func(a,b);
}


int main()
{
    //函数指针一个重要的意义是可以让我们让函数的变量可以是函数 
    //example
    int x1=3;
    int x2=6;
    std::cout<<dosome(x1,x2,add)<<std::endl;
    std::cout<<dosome(x1,x2,product)<<std::endl;

    

}