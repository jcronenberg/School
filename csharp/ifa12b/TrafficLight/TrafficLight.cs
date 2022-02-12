namespace TrafficLight {
	public class TrafficLight
	{
		private LightStates CurrentState = LightStates.off;
		private bool AutoMode = false;
		private float ElapsedTime;

		public LightStates GetState()
		{
			return CurrentState;
		}

		public void NextCycle()
		{
			// Advance CurrentState
			if (CurrentState == LightStates.off)
			{
				return;
			}
			else if (CurrentState == LightStates.yellow)
			{
				CurrentState = LightStates.red;
			}
			else
			{
				CurrentState += 1;
			}

			// Reset ElapsedTime for AutoMode
			ElapsedTime = 0;
		}

		public void SwitchOn()
		{
			if (CurrentState == LightStates.off)
			{
				CurrentState = LightStates.red;
			}
		}

		public void SwitchOff()
		{
			CurrentState = LightStates.off;
		}

		public void ToggleAutoMode()
		{
			AutoMode = !AutoMode;
			ElapsedTime = 0;
		}

		// Returns true if a change in CurrentState happend otherwise returns false
		// time should be the time elapsed in seconds since the last call
		public bool UpdateAutoMode(float time)
		{
			if (!AutoMode)
				return false;

			ElapsedTime += time;
			if (ElapsedTime >= 5.0)
			{
				NextCycle();
				ElapsedTime = 0;
				return true;
			}
			return false;
		}
	}

	public enum LightStates {
		red,
		red_yellow,
		green,
		yellow,
		off
	}
}
