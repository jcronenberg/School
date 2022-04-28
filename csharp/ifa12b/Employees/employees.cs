namespace Employee {
	public abstract class Employee {
		private string Firstname;
		private string Lastname;

		public Employee(string fname, string lname)
		{
			SetFirstname(fname);
			SetLastname(lname);
		}

		public void SetFirstname(string name)
		{
			if (name == "")
				name = "Null";
			this.Firstname = name;
		}

		public string GetFirstname()
		{
			return this.Firstname;
		}

		public void SetLastname(string name)
		{
			if (name == "")
				name = "Null";
			this.Lastname = name;
		}

		public string GetLastname()
		{
			return this.Lastname;
		}

		public abstract double GetSalary();
	}

	public class Contractor : Employee
	{
		private double Salary = 1.0;

		public Contractor() : base("Null", "Null")
		{
			SetSalary(1.0);
		}

		public Contractor(double Salary, string fname, string lname) : base(fname, lname)
		{
			SetSalary(Salary);
		}

		public bool SetSalary(double Salary)
		{
			if (Salary <= 0)
				return false;

			this.Salary = Salary;
			return true;
		}

		public override double GetSalary()
		{
			return Salary;
		}
	}

	public class Worker : Employee
	{
		private int Hours = 0;
		private double Wage = 1.0;

		public Worker() : base("Null", "Null")
		{
			SetHours(0);
			SetWage(1.0);
		}

		public Worker(int Hours, double Wage, string fname, string lname) : base(fname, lname)
		{
			SetHours(Hours);
			SetWage(Wage);
		}

		public override double GetSalary()
		{
			return Hours * Wage;
		}

		public bool SetHours(int Hours)
		{
			if (Hours < 0)
				return false;

			this.Hours = Hours;
			return true;
		}

		public bool SetWage(double Wage)
		{
			if (Wage <= 0)
				return false;

			this.Wage = Wage;
			return true;
		}
	}
}
