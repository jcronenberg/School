using Godot;
using System;
using System.Collections.Generic;

public class GUI : Control
{
	private Parser.Parser GuiParser = new Parser.Parser();
	private TextEdit TextField;
	private ColorRect Indicator;
	private LineEdit ErrorCount;
	private TextEdit ErrorMessages;
	private bool CheckAutomatically = false;

	public override void _Ready()
	{
		TextField = (TextEdit)GetNode("VBoxContainer/MarginText/TextEdit");
		Indicator = (ColorRect)GetNode("VBoxContainer/MarginMiddle/HBoxContainer/ColorIndicator");
		ErrorCount = (LineEdit)GetNode("VBoxContainer/MarginMiddle/HBoxContainer/ErrorCount");
		ErrorMessages = (TextEdit)GetNode("VBoxContainer/MarginBottom/ErrorMessages");
	}

	private void _on_Button_pressed()
	{
		GuiParser.SetInput(TextField.Text);
		if (GuiParser.CheckValid())
		{
			Indicator.Color = new Color(0, 1, 0);
			ErrorMessages.Text = "";
			ClearSafeLines();
		}
		else
		{
			Indicator.Color = new Color(1, 0, 0);
			HandleErrorMessages(GuiParser.GetParserErrors());
		}
		ErrorCount.Text = $"Number of errors: {GuiParser.GetErrorCount()}";
	}

	private void _on_CheckBox_pressed()
	{
		CheckAutomatically = !CheckAutomatically;
	}
	private void _on_TextEdit_text_changed()
	{
		if (CheckAutomatically)
			_on_Button_pressed();
	}

	private void HandleErrorMessages(List<Parser.ParserError> ListError)
	{
		ErrorMessages.Text = "";
		ClearSafeLines();
		foreach (Parser.ParserError Error in ListError)
		{
			ErrorMessages.Text += $"Missing {Error.MissingChar} at Line {Error.Line + 1}, Pos {Error.RelativePos + 1}\n";
			TextField.SetLineAsSafe(Error.Line, true);
		}
	}

	private void ClearSafeLines()
	{
		for (int i = 0; i < TextField.GetLineCount(); i++)
		{
			TextField.SetLineAsSafe(i, false);
		}
	}
}
