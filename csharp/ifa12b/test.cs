using System;
using System.Collections.Generic;

namespace Pupils
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Pupil> pupils = new List<Pupil>();
            string message = "Hello World!!";

            Console.WriteLine(message);
        }

        private string GetDebuggerDisplay()
        {
            return ToString();
        }
    }
}
