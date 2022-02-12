using System.Collections.Generic;

namespace IntersectionController
{
	public class IntersectionController
	{
		private int TrafficLightAmount = 4;
		private TrafficLight.TrafficLight[] TrafficLights;
		private IntersectionStates CurrentState = IntersectionStates.black__black;
		private bool AutoMode = false;
		private float ElapsedTime = 0;
		private Dictionary<IntersectionStates, int> TimeToSwitch = new Dictionary<IntersectionStates, int>()
		{
			{IntersectionStates.red__red0, 2},
			{IntersectionStates.red_yellow__red, 2},
			{IntersectionStates.green__red, 6},
			{IntersectionStates.yellow__red, 2},
			{IntersectionStates.red__red1, 2},
			{IntersectionStates.red__red_yellow, 2},
			{IntersectionStates.red__green, 6},
			{IntersectionStates.red__yellow, 2}
		};

		public IntersectionController(int TrafficLightAmount)
		{
			this.TrafficLightAmount = TrafficLightAmount;
			TrafficLights = new TrafficLight.TrafficLight[TrafficLightAmount];
			for (int i = 0; i < TrafficLightAmount; i++)
			{
				TrafficLights[i] = new TrafficLight.TrafficLight();
			}
		}

		public void SwitchOn()
		{
			if (CurrentState == IntersectionStates.black__black)
			{
				CurrentState = IntersectionStates.red__red0;
				for (int i = 0; i < TrafficLightAmount; i++)
				{
					TrafficLights[i].SwitchOn();
				}
			}

			ElapsedTime = 0;
		}

		public void SwitchOff()
		{
			CurrentState = IntersectionStates.black__black;
			for (int i = 0; i < TrafficLightAmount; i++)
			{
				TrafficLights[i].SwitchOff();
			}
		}

		public TrafficLight.LightStates[] GetTrafficLightsStates()
		{
			TrafficLight.LightStates[] states = new TrafficLight.LightStates[TrafficLightAmount];
			for (int i = 0; i < TrafficLightAmount; i++)
			{
				states[i] = TrafficLights[i].GetState();
			}
			return states;
		}

		public void SwitchAllLights()
		{
			if (CurrentState == IntersectionStates.black__black)
				return;

			// Switch first set
			for (int i = 0; i < TrafficLightAmount / 2; i++)
			{
				if (CurrentState >= IntersectionStates.red__red0 && CurrentState < IntersectionStates.red__red1)
					TrafficLights[i].NextCycle();
			}
			// Switch second set
			for (int i = TrafficLightAmount / 2; i < TrafficLightAmount; i++)
			{
				if (CurrentState >= IntersectionStates.red__red1 && CurrentState <= IntersectionStates.red__yellow)
					TrafficLights[i].NextCycle();
			}

			CurrentState += 1;
			if (CurrentState == IntersectionStates.black__black)
				CurrentState = IntersectionStates.red__red0;

			ElapsedTime = 0;
		}

		public void ToggleAutoMode()
		{
			AutoMode = !AutoMode;
			ElapsedTime = 0;
		}

		public bool UpdateAutoMode(float delta)
		{
			if (!AutoMode || CurrentState == IntersectionStates.black__black)
				return false;

			ElapsedTime += delta;
			if (ElapsedTime >= TimeToSwitch[CurrentState])
			{
				SwitchAllLights();
				ElapsedTime = 0;
				return true;
			}
			return false;
		}
	}

	// Lane1__Lane2
	public enum IntersectionStates
	{
		red__red0,
		red_yellow__red,
		green__red,
		yellow__red,
		red__red1,
		red__red_yellow,
		red__green,
		red__yellow,
		black__black
	}
}
