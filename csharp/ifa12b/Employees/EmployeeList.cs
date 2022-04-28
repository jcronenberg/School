using Godot;
using System;

public class EmployeeList : VBoxContainer
{
	private ItemList EmployeesItemList;

	public override void _Ready()
	{
		EmployeesItemList = (ItemList)GetNode("EmployeesItemList");

		EmployeesItemList.AddItem("Firstname");
		EmployeesItemList.AddItem("Lastname");
		EmployeesItemList.AddItem("Salary");
		EmployeesItemList.AddItem("");
		EmployeesItemList.AddItem("");
		EmployeesItemList.AddItem("");
	}

	public void AddEmployee(Employee.Employee employee)
	{
		EmployeesItemList.AddItem(employee.GetFirstname());
		EmployeesItemList.AddItem(employee.GetLastname());
		EmployeesItemList.AddItem((Convert.ToString(employee.GetSalary())));
	}

	private void _on_CloseButton_pressed()
	{
		QueueFree();
	}
}
