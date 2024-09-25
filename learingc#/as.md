# as 关键字 

as 可以很好避免拆箱中的报错，当拆箱类型不符合时，等式右边会返回一个NULL

```c#
using System;
namespace lol {
   
        class A
        {
            public int a;
            public A(int a)
            { this.a = a; }

        }
   

    class runcode {
    static void Main(String[] args)
        {
            object obj = new A(3);
            A t1;
            t1 = obj as A;
            string t2;
            t2 = obj as string;
            Console.WriteLine(t1.a);
            if (t2 == null)
            { Console.WriteLine("t2 is NULL!"); 
            }
        }



    };

  
    
}
```

**这个例子中，t2 会返回NULL（注意这种方法只能针对能返回NULL的数据类型）。**

