﻿using System;
namespace tryweituo
{
    delegate int changenum(int x);
    public class A
    {
        public int Value { set; get; }
        public int addvalue(int x)
        {
           return  Value += x;
        }
        public int multiple(int x)
        {
            return Value *= x;
        }
        
        public static void Main(string[] args)
        {
            A a = new A();
            a.Value = 1;
            changenum fun1 = new (a.addvalue);
            changenum fun2 = new (a.multiple);

            Console.WriteLine(fun1(5));
            Console.WriteLine(a.Value);

            A a1 = new A();
            a1.Value = 1;
            changenum fun3 = new(a1.addvalue);
            changenum fun4 = new(a1.multiple);

            Console.WriteLine(fun4(7));
            Console.WriteLine(a1.Value);
            Console.WriteLine(a.Value);






        }
    }

}