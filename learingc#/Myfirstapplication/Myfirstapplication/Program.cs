// See https://aka.ms/new-console-template for more information



// this is object    它是c#中所有数据类型的基类
//object obj;
//obj = 100;   //   装箱操作

//console.writeline(obj.tostring());
//object obj1 = 200;
//object obj2 = 65;
//console.writeline((int)obj + (int)obj1);

//console.writeline(obj2.tostring());


//using System;
//namespace lol {

//        class A
//        {
//            public int a;
//            public A(int a)
//            { this.a = a; }

//        }


//    class runcode {
//    static void Main(String[] args)
//        {
//            object obj = new A(3);
//            A t1;
//            t1 = obj as A;
//            string t2;
//            t2 = obj as string;
//            Console.WriteLine(t1.a);
//            if (t2 == null) { Console.WriteLine("t2 is NULL!"); }

//        }


//    };



// }





//int [] a = new int[] { 1, 2, 3, 4, 5 };

//foreach (int element in a)
//{
//    Console.WriteLine(element);
//}




//using System;
//using Myfirstapplication;
//namespace RectangleApplication
//{
//    class Rectangle
//    {
//        //成员变量
//        public double length;
//        internal double width;

//        double GetArea()
//        {
//            return length * width;
//        }
//        public void Display()
//        {
//            Console.WriteLine("长度： {0}", length);
//            Console.WriteLine("宽度： {0}", width);
//            Console.WriteLine("面积： {0}", GetArea());
//        }
//    }//end class Rectangle    
//    class ExecuteRectangle
//    {
//        static void Main(string[] args)
//        {
//            Rectangle r = new Rectangle();
//            r.length = 4.5;
//            r.width = 3.5;
//            r.Display();
//            Console.ReadLine();

//            Class1 x1 = new Class1(13);
//            Console.WriteLine(x1.b);
//        }
//    }
//}

//using System.Security.Cryptography.X509Certificates;

//int a;
//int b;



//A t =new A();
//t.tryref_out(out a, out b);
//Console.WriteLine("a = {0}, b = {1}", a, b);
//int? haha = null;

//A tb;
//tb.A()

//class A
//{
//    public void tryref_out(out  int x,out int y)
//    {
//        x = 5;
//        y = 6;

//    }
//}


A tem();



class A
{
    int value;
    public void tryref_out(out int x, out int y)
    {
        x = 5;
        y = 6;

    }
   static A() {  }
}


