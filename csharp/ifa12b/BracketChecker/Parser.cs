using Godot;
using System;

namespace Parser
{
    public class Parser
	{
        private const int MAX_BRACKETS = 30;
		private Stack.Stack BracketStack;
        private string Input;

		public void SetInput(string Input)
		{
            this.Input = Input;
        }

		public bool CheckValid()
		{
			BracketStack = new Stack.Stack(MAX_BRACKETS / 2);

            for (int i = 0; i < Input.Length; i++)
			{
                char current = Input[i];
				if (current == '{' || current == '[' || current == '(')
				{
                    if (!BracketStack.push(current))
                        return false;
                }
				else if (current == '}' || current == ']' || current == ')')
				{
                    int diff = current - BracketStack.pop();
					if (diff > 2 || diff < 0)
					{
                        return false;
                    }
                }
            }

            return true;
        }
    }
}
