using Godot;
using System;
using System.Collections.Generic;

public class EmployeeStatistics : VBoxContainer
{
	private LineEdit AverageSalaryOutput;

	public override void _Ready()
	{
		AverageSalaryOutput = (LineEdit)GetNode("AverageSalary/LineEdit");
	}

	public void UpdateStatistics(List<Employee.Employee> employees)
	{
		double average_salary = CalculateAverageSalary(employees);
		AverageSalaryOutput.Text = Convert.ToString(average_salary);
	}

	private double CalculateAverageSalary(List<Employee.Employee> employees)
	{
		double accumulated_salary = 0.0;
		for (int i = 0; i < employees.Count; i++)
		{
			accumulated_salary += employees[i].GetSalary();
		}
		return accumulated_salary / employees.Count;
	}

	private void _on_CloseButton_pressed()
	{
		QueueFree();
	}
}
