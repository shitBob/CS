# out 参数 
我们可以用out参数，传递未初始化的参数 

```c#
int a;
int b;



A t =new A();
t.tryref_out(out a, out b);
Console.WriteLine("a = {0}, b = {1}", a, b);

class A
{
    public void tryref_out(out  int x,out int y)
    {
        x = 5;
        y = 6;

    }
}



```