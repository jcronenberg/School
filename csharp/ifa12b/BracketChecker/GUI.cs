using Godot;
using System;

public class GUI : Control
{
	private Parser.Parser GuiParser = new Parser.Parser();
	private TextEdit TextField;
	private ColorRect Indicator;
	public override void _Ready()
	{
		TextField = (TextEdit)GetNode("VBoxContainer/MarginText/TextEdit");
		Indicator = (ColorRect)GetNode("VBoxContainer/MarginBottom/HBoxContainer/ColorIndicator");
	}

	private void _on_Button_pressed()
	{
		GuiParser.SetInput(TextField.Text);
		if (GuiParser.CheckValid())
			Indicator.Color = new Color(0, 1, 0);
		else
			Indicator.Color = new Color(1, 0, 0);
	}
}
