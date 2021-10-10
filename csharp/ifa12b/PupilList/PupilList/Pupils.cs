using System;

namespace PupilList
{
    [Serializable]
    public class Pupil
    {
        public int id;
        public string name;
        public string phone;
        public string location;

        public Pupil next = null;

        public Pupil()
        {
            Console.WriteLine("\nNew pupil:");
            id = MainClass.askForId();
            Console.WriteLine("What's the name?");
            name = Console.ReadLine();
            Console.WriteLine("What's the phone number?");
            phone = Console.ReadLine();
            Console.WriteLine("What's the location?");
            location = Console.ReadLine();
        }

        public Pupil(int i = -1, string n = "unknown", string p = "unknown", string l = "unknown")
        {
            id = i;
            name = n;
            phone = p;
            location = l;
        }

        public void printToConsole()
        {
            Console.WriteLine($"ID: {id}");
            Console.WriteLine($"Name: {name}");
            Console.WriteLine($"Phone number: {phone}");
            Console.WriteLine($"Location: {location}");
        }
    }
}
