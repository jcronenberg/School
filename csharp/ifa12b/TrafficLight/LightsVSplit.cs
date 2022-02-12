using Godot;
using System;

public class LightsVSplit : HBoxContainer
{
	public override void _Ready()
	{
	}

	public void SpawnTrafficLights(int amount)
	{
		var children = GetChildren();
		foreach (Node child in children)
		{
			child.QueueFree();
		}
		var scene = (PackedScene)GD.Load("res://scenes/TrafficLight.tscn");
		for (int i = 0; i < amount; i++)
		{
			AddChild(scene.Instance());
		}
	}

	public void ChangeLights(TrafficLight.LightStates[] states)
	{
		for (int i = 0; i < states.Length; i++)
		{
			GetChild(i).Call("ChangeState", states[i]);
		}
	}
}
