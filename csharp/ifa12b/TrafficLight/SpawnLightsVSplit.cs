using Godot;
using System;

public class SpawnLightsVSplit : VBoxContainer
{
	LineEdit LightsLine;
	MarginContainer Controls;
	public override void _Ready()
	{
		LightsLine = (LineEdit)GetNode("InputLights/LineEdit");
		Controls = (MarginContainer)GetNode("../../");
	}

	private void _on_SpawnLightsButton_pressed()
	{
		if (Int32.TryParse(LightsLine.Text, out int amount))
			Controls.Call("ConfigureTrafficLights", amount);
	}
	private void _on_LineEdit_text_entered(String _new_text)
	{
		_on_SpawnLightsButton_pressed();
	}
}
