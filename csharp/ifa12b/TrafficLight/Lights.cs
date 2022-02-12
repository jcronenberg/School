using Godot;
using System;

public class Lights : Control
{
	Sprite RedLight;
	Sprite YellowLight;
	Sprite GreenLight;

	public override void _Ready()
	{
		RedLight = (Sprite)GetNode("LightsPosition/RedLight/RedCircle");
		YellowLight = (Sprite)GetNode("LightsPosition/YellowLight/YellowCircle");
		GreenLight = (Sprite)GetNode("LightsPosition/GreenLight/GreenCircle");
	}

	private void ChangeState(TrafficLight.LightStates state)
	{
		RenderLightState(state);
	}

	private void RenderLightState(TrafficLight.LightStates state)
	{
		switch (state)
		{
			case (TrafficLight.LightStates.red):
				ControlLights(true, false, false);
				break;
			case (TrafficLight.LightStates.red_yellow):
				ControlLights(true, true, false);
				break;
			case (TrafficLight.LightStates.green):
				ControlLights(false, false, true);
				break;
			case (TrafficLight.LightStates.yellow):
				ControlLights(false, true, false);
				break;
			case (TrafficLight.LightStates.off):
				ControlLights(false, false, false);
				break;
		}
	}

	private void ControlLights(bool red, bool yellow, bool green)
	{
		RedLight.Visible = red;
		YellowLight.Visible = yellow;
		GreenLight.Visible = green;
	}
}
