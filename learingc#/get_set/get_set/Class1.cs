using System;
namespace get_set
{
    public class A
    {
       public String Name {set;get;} 
    }

    public class run
    {
        static void Main(string[] args)
        {
            A a = new A();
            a.Name = "Bob";
            Console.WriteLine(a.Name);
        }
    }


}

  

