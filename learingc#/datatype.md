# 引用类型
引用类型：他们只是一个名字 ，一个内存可以挂名（引用）多个名字
## 1 Object 类型 

它是C#所有类型的基类 

它的主要操作是拆箱和装箱  

``` c#
object obj
obj = 100  // 装箱 
Console.WriteLine(obj.ToString()); //拆箱
```

## 2 Dynamic 类型 

``` c#
dynamic variable = "Hello, World!";
Console.WriteLine(variable); // 输出: Hello, World!

variable = 42;
Console.WriteLine(variable); // 输出: 42

variable = new { Name = "Alice", Age = 30 };
Console.WriteLine(variable.Name); // 输出: Alice
```

## 3 String 字符类型 
重要的是，他是引用类型。

```c#
String str = "fuckyou";
```



