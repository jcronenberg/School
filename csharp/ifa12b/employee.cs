using System;

public class Employee
{
    private string Name;
    private int Salary = 1;

    public string getName()
    {
        return Name;
    }

    public void setName(string Name)
    {
        this.Name = Name;
    }

    public int getSalary()
    {
        return Salary;
    }

    public bool setSalary(int Salary)
    {
        if (Salary < 1)
        {
            return false;
        }
        this.Salary = Salary;
        return true;
    }
}
class MainProgram
{
    static void Main(string[] args)
    {
        Employee test = new Employee();
        Console.WriteLine("Salary test:");
        Console.WriteLine(test.setSalary(-1));
        Console.WriteLine(test.getSalary());
        Console.WriteLine(test.setSalary(2));
        Console.WriteLine(test.getSalary());
        Console.WriteLine("Name test:");
        test.setName("Peter");
        Console.WriteLine(test.getName());
    }
}
