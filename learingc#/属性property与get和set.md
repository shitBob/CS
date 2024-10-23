# 1 属性

和没有不用参数的方法差不多

属性包含了字段，下例中的name。
以及相对应的访问方法。

例子 

```Csharp
using System;
namespace get_set
{
    public class A
    {
        string name; 

        public string Name  
        {
            get { return name; }
            set { Name = name; }
        }


        
    }

    public class run {
  static void Main(string[] args)
        {
            A a = new A();
            a.Name = "Bob";
            
        }
}

}

```

可以用更加简单的代码实现上述功能

```csharp

 public class A
    {
        public String Name { set; get; }
    }

```


# set get 关键字

这两个关键字可以帮助我们更容易的控制对于字段值的输出。

例如 
```csharp 
using System;
namespace get_set
{
    public class A
    {
        public String Name { set; get; }
        public String Status { 
            get{
                return Name=="Bob" ? "Boss" : "employer";

            } 
        
        }
    }

    public class run
    {
        static void Main(string[] args)
        {
            A a = new A();
            a.Name = "Bob";
            Console.WriteLine(a.Status);
        }
    }


}

```
