using Godot;
using System;
using System.Collections.Generic;

public class GUI : Control
{
	private Parser.Parser GuiParser = new Parser.Parser();
	private TextEdit TextField;
	private LineEdit ErrorCount;
	private TextEdit ErrorMessages;
	private StyleBoxFlat ErrorCountStyle;
	private MarginContainer ErrorMessagesContainer;
	private bool CheckAutomatically = true;

	public override void _Ready()
	{
		TextField = (TextEdit)GetNode("VBoxContainer/MarginText/TextEdit");
		ErrorCount = (LineEdit)GetNode("VBoxContainer/MarginMiddle/HBoxContainer/ErrorCount");
		ErrorMessages = (TextEdit)GetNode("VBoxContainer/MarginBottom/ErrorMessages");
		ErrorCountStyle = (StyleBoxFlat)GD.Load("style/ErrorCountStyle.tres");
		ErrorMessagesContainer = (MarginContainer)GetNode("VBoxContainer/MarginBottom");
	}

	private void _on_Button_pressed()
	{
		GuiParser.SetInput(TextField.Text);
		if (GuiParser.CheckValid())
		{
			ErrorCountStyle.BgColor = new Color(0, 1, 0);
			ErrorMessages.Text = "";
			ClearSafeLines();
		}
		else
		{
			ErrorCountStyle.BgColor = new Color(1, 0, 0);
			HandleErrorMessages(GuiParser.GetParserErrors());
		}
		ErrorCount.Text = $"Errors: {GuiParser.GetErrorCount()}";
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
			ErrorMessages.Text += Error.GenerateErrorMsg();
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
	private void _on_CheckErrorMessages_pressed()
	{
		ErrorMessagesContainer.Visible = !ErrorMessagesContainer.Visible;
	}
}
