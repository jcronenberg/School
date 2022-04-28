using Godot;
using System;

public class Input : VBoxContainer
{
	private CompanyControl.CompanyControl MyCompany;
	private Label ErrorLabel;
	private VBoxContainer Workers;
	private VBoxContainer Contractors;
	private Button ContractorButton;
	private Button WorkerButton;
	private LineEdit Firstname;
	private LineEdit Lastname;
	private LineEdit Salary;
	private LineEdit Hours;
	private LineEdit Wage;

	public override void _Ready()
	{
		MyCompany = ((MainControl)GetNode("/root/MainControl")).GetCompany();
		ErrorLabel = (Label)GetNode("ErrorLabel");
		Workers = (VBoxContainer)GetNode("WorkerContainer");
		Contractors = (VBoxContainer)GetNode("ContractorContainer");
		ContractorButton = (Button)GetNode("TypeSelectorHBox/ContractorButton");
		WorkerButton = (Button)GetNode("TypeSelectorHBox/WorkerButton");
		Firstname = (LineEdit)GetNode("FirstnameHBox/LineEdit");
		Lastname = (LineEdit)GetNode("LastnameHBox/LineEdit");
		Salary = (LineEdit)GetNode("ContractorContainer/SalaryHBox/LineEdit");
		Hours = (LineEdit)GetNode("WorkerContainer/HoursHBox/LineEdit");
		Wage = (LineEdit)GetNode("WorkerContainer/WageHBox/LineEdit");
	}

	private void _on_ContractorButton_pressed()
	{
		WorkerButton.Pressed = false;
		Workers.Visible = false;
		Contractors.Visible = true;
	}

	private void _on_WorkerButton_pressed()
	{
		ContractorButton.Pressed = false;
		Workers.Visible = true;
		Contractors.Visible = false;
	}

	private void _on_CloseButton_pressed()
	{
		QueueFree();
	}

	private void _on_CreateButton_pressed()
	{
		// Check what type is selected
		if (WorkerButton.Pressed)
		{
			double d_wage = 0.0;
			int i_hours = 0;

			// TryParse values and set error msg if necessary
			if (!Double.TryParse(Wage.Text, out d_wage))
			{
				ErrorLabel.Text = "Invalid Hourly Wage";
				return;
			}
			else if (!Int32.TryParse(Hours.Text, out i_hours))
			{
				ErrorLabel.Text = "Invalid Working Hours";
				return;
			}
			else
			{
				ErrorLabel.Text = "";
			}

			MyCompany.CreateWorker(i_hours, d_wage, Firstname.Text, Lastname.Text);
		}
		else
		{
			double d_salary = 0.0;

			// TryParse values and set error msg if necessary
			if (!Double.TryParse(Salary.Text, out d_salary))
			{
				ErrorLabel.Text = "Invalid Salary";
				return;
			}
			else
			{
				ErrorLabel.Text = "";
			}

			MyCompany.CreateContractor(d_salary, Firstname.Text, Lastname.Text);
		}
	}
}
