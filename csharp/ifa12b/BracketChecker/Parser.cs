using System.Linq;
using System.Collections.Generic;

namespace Parser
{
	public class ParserError
	{
		public int AbsolutePos;
		public int RelativePos;
		public int Line;
		public char MissingChar;

		public ParserError(int pos)
		{
			AbsolutePos = pos;
		}
	}

	public class Parser
	{
		private const int MAX_BRACKETS = 30;
		private string Input;
		private List<ParserError> ListError;
		// Array of brackets
		// Keep both arrays in the same order of opposite brackets
		private char[] OpeningBrackets = {'(', '[', '{'};
		private char[] ClosingBrackets = {')', ']', '}'};

		// Change the Input string
		public void SetInput(string Input)
		{
			this.Input = Input;
		}

		// This function checks if all brackets are valid in Input string
		// return true if Input is valid
		// return false if Input is not valid
		// For every error present it adds an entry to ListError
		public bool CheckValid()
		{
			// Stores all opening brackets
			Stack.Stack BracketStack = new Stack.Stack(MAX_BRACKETS / 2);
			// Stores all positions for every element in BracketStack
			Stack.Stack PositionStack = new Stack.Stack(MAX_BRACKETS / 2);
			ListError = new List<ParserError>();

			// Step through Input string
			for (int i = 0; i < Input.Length; i++)
			{
				// Safe current char
				char current = Input[i];

				// Check if current is an opening bracket
				if (OpeningBrackets.Contains(current))
				{
					// Check if MAX_BRACKETS is exceeded
					if (!BracketStack.Push(current))
						return false;
					PositionStack.Push(i);
				}
				// Check if current is a closing bracket
				else if (ClosingBrackets.Contains(current))
				{
					// Safe popped element
					int bracket = BracketStack.Pop();

					// This is a trick that uses ascii values
					// it works because opening brackets of the same type
					// are either 1 or 2 ascii values away
					int diff = current - bracket;

					if (diff > 2 || diff < 0)
					{
						ListError.Add(new ParserError(i));
						BracketStack.Push(bracket);
						continue;
					}

					PositionStack.Pop();
				}
			}

			// Anything that remains on the BracketStack
			// is an error, as it is an opening bracket
			// that didn't get closed
			while (BracketStack.Pop() != 0) {
				ListError.Add(new ParserError(PositionStack.Pop()));
			}

			FillParserErrors();

			return ListError.Count == 0;
		}
		
		// Return number of errors
		// This assumes you have ran CheckValid() beforehand
		public int GetErrorCount()
		{
			return ListError.Count;
		}

		// Return the error list
		public List<ParserError> GetParserErrors()
		{
			return ListError;
		}

		// Fills all the missing fields in ListError
		// requires all errors in ListError to have
		// a AbsolutePos set
		private void FillParserErrors()
		{
			// Step through ListError
			foreach (ParserError Error in ListError)
			{
				int lineNumber = 0;
				int relativePosition = 0;

				// Step through Input
				for (int i = 0; i < Input.Length; i++)
				{
					if (Error.AbsolutePos == i)
					{
						Error.Line = lineNumber;
						Error.RelativePos = relativePosition;
						// Fill MissingChar with opposite bracket pointed at in Error
						for (int j = 0; j < OpeningBrackets.Length; j++)
						{
							if (Input[i] == OpeningBrackets[j])
								Error.MissingChar = ClosingBrackets[j];
							else if (Input[i] == ClosingBrackets[j])
								Error.MissingChar = OpeningBrackets[j];
						}
					}
					else if (Input[i] == '\n')
					{
						lineNumber++;
						relativePosition = 0;
					}
					else
					{
						relativePosition++;
					}
				}
			}
		}
	}
}
