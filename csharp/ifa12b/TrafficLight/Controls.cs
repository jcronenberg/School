using Godot;
using System;

public class Controls : MarginContainer
{
	int TrafficLightsAmount = 4;
	bool AutoMode = false;
	HBoxContainer LightsController;

	IntersectionController.IntersectionController MyIntersectionController;
	public override void _Ready()
	{
		MyIntersectionController = new IntersectionController.IntersectionController(TrafficLightsAmount);
		LightsController = (HBoxContainer)GetNode("../LightsVSplit");
		LightsController.Call("SpawnTrafficLights", TrafficLightsAmount);
	}

	private void _on_OnButton_pressed()
	{
		MyIntersectionController.SwitchOn();
		LightsController.Call("ChangeLights", MyIntersectionController.GetTrafficLightsStates());
	}

	private void _on_OffButton_pressed()
	{
		MyIntersectionController.SwitchOff();
		LightsController.Call("ChangeLights", MyIntersectionController.GetTrafficLightsStates());
	}

	private void _on_CycleButton_pressed()
	{
		MyIntersectionController.SwitchAllLights();
		LightsController.Call("ChangeLights", MyIntersectionController.GetTrafficLightsStates());
	}

	private void _on_AutoButton_toggled(bool _button_pressed)
	{
		AutoMode = !AutoMode;
		MyIntersectionController.ToggleAutoMode();
	}

	public override void _Process(float delta)
	{
		if (MyIntersectionController.UpdateAutoMode(delta))
			LightsController.Call("ChangeLights", MyIntersectionController.GetTrafficLightsStates());
	}

	public void ConfigureTrafficLights(int TrafficLightsAmount)
	{
		MyIntersectionController = new IntersectionController.IntersectionController(TrafficLightsAmount);
		if (AutoMode)
			MyIntersectionController.ToggleAutoMode();
		LightsController.Call("SpawnTrafficLights", TrafficLightsAmount);
	}
}
