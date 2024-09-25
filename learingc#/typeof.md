# typeof 关键词 
typeof 关键字用于获取一个类型的类型对象，它通常用于反射和动态创建类型实例。
目前不知道有什么用，挖个坑。
```c#
using System;

class Program
{
    static void Main(string[] args)
    {
        Type type = typeof(string);
        Console.WriteLine(type.FullName);
        Console.ReadKey();
    }
}
```

