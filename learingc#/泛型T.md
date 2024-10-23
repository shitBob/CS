# 泛型 Generic
类似c++中的template 

```csharp
A<int> t1 = new A<int>(5);
A<char> t2 = new A<char>(5);
for (int i = 0; i < 5; i++)
{
    t1.setitem(i, i);
}
for (int i = 0;i < 5; i++)
{
    t2.setitem(i, (char)(i + 48));
}
foreach (int i in t1.array)
{
    Console.WriteLine(i);
}
foreach (char c in t2.array)
{ Console.WriteLine(c); }


class A<T>
{
    public T[] array;
    public A(int size)
    {
        array = new T[size];
    }
    public void setitem(int index, T value)
    {  
        array[index]   = value;
    }
}


```