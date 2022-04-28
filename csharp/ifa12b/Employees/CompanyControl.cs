using Godot;
using System.Collections.Generic;

namespace CompanyControl
{
	public class CompanyControl
	{
        private List<Employee.Employee> Employees = new List<Employee.Employee>();
        private MainControl MC;

        public void CreateWorker(int hours, double wage, string fname, string lname)
        {
            Employees.Add(new Employee.Worker(hours, wage, fname, lname));
            MC.Update();
        }

		public void CreateContractor(double salary, string fname, string lname)
		{
            Employees.Add(new Employee.Contractor(salary, fname, lname));
            MC.Update();
        }

		public List<Employee.Employee> GetEmployees()
		{
            return Employees;
        }

		public void SetMainControl(MainControl mc)
		{
            MC = mc;
        }
    }
}
