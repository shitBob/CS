# 继承 

在继承的实现上，C#提供了继承接口的功能 

例子 ： 比如现在你有两个类，一个是圆形类，一个是正方形类 ，我想在这个两个类里面实现计算面积、周长等功能 。

下面是使用接口的实现方法。

注意 ： **实现的接口函数必须是公共的**

```c# 
using System;
namespace nihao
{
    public interface Basicmethod
    {
    double method1();
    double method2();
    }
    
    class Circle : Basicmethod
{
    public double r;
    public Circle (double x)
    {
        this.r = x;
    }
    public double method1()
    {
        return 3.14 * r * r;
    }
    public double method2()
    {
        return 2 * 3.14 * r;
    }
}
    class squre :  Basicmethod
{
    public double a;

    public squre (double x)
    { this.a = x; }
    public double method1()
    {
        return a * a;
    }
    public double method2 ()
    {
        return a * 4;
    }
}


    class program
{
    public static void Main(string[] args)
    {
        Circle yuan1 = new Circle(3);
        squre zfx    = new squre(3);

        Console.WriteLine(yuan1.method1());
        Console.WriteLine(yuan1.method2());
    }

}
}



```

