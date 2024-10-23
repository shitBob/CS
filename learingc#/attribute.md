# attribute 的基本概念

用法感觉很杂，不知道怎么概述

## 1 conditon
1. 定义某个关键字，如果某个关键字未定义，则不对其进行编译

下里中定义了关键字"MAN" ,所以Message函数被定义了，否则将不会有任何结果。

```csharp
#define MAN
using System;
using System.Diagnostics;
public class Myclass
{
    [Conditional("MAN")]
    public static void Message(string msg)
    {
        Console.WriteLine(msg);
    }
}
class Test
{
    static void function1()
    {
        Myclass.Message("In Function 1.");
        function2();
    }
    static void function2()
    {
        Myclass.Message("In Function 2.");
    }
    public static void Main()
    {
        Myclass.Message("In Main function.");
        function1();
        Console.ReadKey();
    }
}
```

可以同时包含多个attribute

```csharp
[Conditional("DEBUG"), Conditional("TEST1")]
void TraceMethod()
{
    // ...
}
```




## 2 obsolete 

下述代码将无法进行编译，因为词法分析发现他尝试去调用一个被Obsolete标识的函数。

```Csharp
using System;
public class MyClass
{
   [Obsolete("Don't use OldMethod, use NewMethod instead", true)]
   static void OldMethod()
   {
      Console.WriteLine("It is the old method");
   }
   static void NewMethod()
   {
      Console.WriteLine("It is the new method");
   }
   public static void Main()
   {
      OldMethod();
   }
}

```

## 3引入dll库

使用Dllimport这个attribute，我们引入了user32.dll这个库。
```csharp
using System;
using System.Runtime.InteropServices;

class Program
{
    [DllImport("user32.dll")]
    public static extern int MessageBox(IntPtr hWnd, String text, String caption, uint type);

    static void Main()
    {
        MessageBox(IntPtr.Zero, "Hello, World!", "My Message Box", 0);
    }
}
```

## 4 attribute 参数

1 位置参数 ，它和attribute的构造函数紧密相关，不可省略 

2 name参数，不是必须的，在默认的情况下可以省略。

## 5 attribute target 
attribute 有作用的对象。


下面的两个对象分别是assembly（指令集）和module（模块）

```csharp
using System;
using System.Reflection;
[assembly: AssemblyTitleAttribute("Production assembly 4")]
[module: CLSCompliant(true)]
```
---
# 自定义attribute

自定义attribute分为两个部分 

part1说明该自定义attribute作用于什么对象
part2具体定义这个attribute这个类 
```csharp
[AttributeUsage(AttributeTargets.Class |
AttributeTargets.Constructor |
AttributeTargets.Field |
AttributeTargets.Method |
AttributeTargets.Property,
AllowMultiple = true)]

public class DeBugInfo : System.Attribute
```

下面是一个具体author特征的例子

```csharp
[System.AttributeUsage(System.AttributeTargets.Class |
                       System.AttributeTargets.Struct,
                       AllowMultiple = true)  // Multiuse attribute.
]
public class AuthorAttribute : System.Attribute
{
    string Name;
    public double Version;

    public AuthorAttribute(string name)
    {
        Name = name;

        // Default value.
        Version = 1.0;
    }

    public string GetName() => Name;
}
```

由于AllowMultiple = true，我们可以使用下列的方法来使用该特征。

```csharp
[Author("P. Ackerman"), Author("R. Koch", Version = 2.0)]
public class ThirdClass
{
    // ...
}
```

