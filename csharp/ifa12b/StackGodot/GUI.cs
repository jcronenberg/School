using Godot;
using System;

public class GUI : Control
{
	private const int stackSize = 8;
	private LineEdit inputField;
	private LineEdit outputField;
	private VBoxContainer stackElementsContainer;
	private Stack.Stack stack;

	public override void _Ready()
	{
		// Init stack
		stack = new Stack.Stack(stackSize);

		// Connect input/output fields
		inputField = (LineEdit)GetNode("HBoxContainer/Interaction/VBoxContainer/MarginInput/Input");
		outputField = (LineEdit)GetNode("HBoxContainer/Interaction/VBoxContainer/MarginOutput/Output");

		// Connect ElementContainer (This is where the functions for drawing the stack visualization are)
		stackElementsContainer = (VBoxContainer)GetNode("HBoxContainer/StackElementsContainer");
		// Spawn empty stack
		stackElementsContainer.Call("spawn_stack", stackSize);

		// Connect Buttons
		GetNode("HBoxContainer/Interaction/VBoxContainer/ButtonContainer/PushButton").Connect("pressed", this, nameof(_on_push_pressed));
		GetNode("HBoxContainer/Interaction/VBoxContainer/ButtonContainer/PopButton").Connect("pressed", this, nameof(_on_pop_pressed));
		// Connect push to enter action when pressed in inputField
		inputField.Connect("text_entered", this, nameof(_on_text_entered));
	}
	
	// Wrapper for _on_push_pressed since text_entered signal wants somewhere to put a string parameter
	public void _on_text_entered(String _unused)
	{
		_on_push_pressed();
	}

	public void _on_push_pressed()
	{
		int result = 0;

		// Check for valid input
		if (!int.TryParse (inputField.Text, out result)) {
			outputField.Text = "Not a valid number";
			return;
		}

		// Push and check if valid
		if (!stack.push(result)) {
			outputField.Text = "Stack is filled already";
			return;
		}

		// draw_push and set outputField
		stackElementsContainer.Call("draw_push", result);
		outputField.Text = $"Pushed {result}";
	}

	public void _on_pop_pressed()
	{
		// Check if pop is possible
		if (stack.getCounter() <= 0) {
			outputField.Text = "Stack is empty";
			return;
		}

		// Pop and save
		int poppedElement = stack.pop();

		// drawp_pop and set inputField and outputField
		stackElementsContainer.Call("draw_pop");
		inputField.Text = $"{poppedElement}";
		outputField.Text = $"Popped";
	}
}
