#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
     // 简单的函数我们可以用lambad函数来定义
     std::vector<int> a={1,2,3,4,5};
     // 现在我们想对a进行从大到小的排序

     sort(a.begin(),a.end(),[](int x1,int x2){return x1>x2;}); 

    // 这样我们就不用跑出去定义一个cmp这么麻烦了，也省空间  
    // []内是capture，= ，& 标识传值还是引用需要的变量， lambda表达式返回的是一个函数指针

      
     for (auto it = a.begin();it!=a.end();it++)
     std::cout<<*it<<" ";
}