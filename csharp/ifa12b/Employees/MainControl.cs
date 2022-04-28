using Godot;
using System.Collections.Generic;

public class MainControl : Node
{
	private CompanyControl.CompanyControl MyCompany;
	private EmployeeStatistics MyEmployeeStatistics;
	private EmployeeList MyEmployeeList;

	public override void _Ready()
	{
		// Set up company
		MyCompany = new CompanyControl.CompanyControl();
		MyCompany.SetMainControl(this);

		MyEmployeeStatistics = (EmployeeStatistics)GetNode("/root/GUI/MarginContainer/HboxWindows/VBoxWindows/EmployeeStatistics");
		MyEmployeeList = (EmployeeList)GetNode("/root/GUI/MarginContainer/HboxWindows/VBoxWindows/EmployeeList");
	}

	public void Update()
	{
		List<Employee.Employee> employees = MyCompany.GetEmployees();

		MyEmployeeStatistics.UpdateStatistics(employees);
		MyEmployeeList.AddEmployee(employees[employees.Count - 1]);
	}

	public CompanyControl.CompanyControl GetCompany()
	{
		return MyCompany;
	}
}
