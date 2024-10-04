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