using System;
using Gtk;
using Pango;

public partial class MainWindow: Gtk.Window
{
	const int stackWidth = 100;
	const int stackHeight = 50;
    Stack.Stack stack = new Stack.Stack(8);
	bool newRender = true;
    public MainWindow () : base (Gtk.WindowType.Toplevel)
    {
        Build ();
    }
    
    protected void OnDeleteEvent (object sender, DeleteEventArgs a)
    {
        Application.Quit ();
        a.RetVal = true;
    }
    
    protected void OnPop (object sender, EventArgs e)
    {
		int poppedElement = stack.pop ();
		renderStack (true);
		this.entry1.Text = $"popped: {poppedElement}";
    }
    
    protected void onPush (object sender, EventArgs e)
    {
		int result;
		if (!int.TryParse (this.entry2.Text, out result)) {
			this.entry1.Text = "Not a valid number!";
			return;
		}
		stack.push (result);
        renderStack (false);
        this.entry1.Text = $"pushed: {this.entry2.Text}";
        //this.entry2.Text = "";
    }
    
	void renderStack(bool popped)
    {
        DrawingArea da = this.drawingarea1;
		Gdk.GC gc = da.Style.BaseGC(StateType.Normal);

		// Set up colors
		Gdk.Color colorRed = new Gdk.Color (0xff, 0, 0);
		Gdk.Color colorGreen = new Gdk.Color (0, 0xff, 0);
		Gdk.Color colorBlack = new Gdk.Color (0, 0, 0);

		// Set color green
		gc.RgbFgColor = colorGreen;

		if (newRender) {
			Console.WriteLine ("new render");
			Gdk.Rectangle baseRec = new Gdk.Rectangle (0, 0, 100, 400);
			// Draw green base rectangle
			da.GdkWindow.DrawRectangle (gc, true, baseRec);
			newRender = false;
		}

		if (popped) {
			gc.RgbFgColor = colorGreen;
		} else {
			gc.RgbFgColor = colorRed;
		}

		// Draw new rectangle
		Gdk.Rectangle newRec = new Gdk.Rectangle (0, 0, stackWidth, stackHeight);
		newRec.Y = stackHeight * 7 - stack.getCounter () * stackHeight;
		if (!popped)
			newRec.Y = newRec.Y + stackHeight;
		da.GdkWindow.DrawRectangle (gc, true, newRec);
        
        // Draw seperator lines
        gc.RgbFgColor = colorBlack;
        for (int y = 50; y < 400; y += 50) {
            da.GdkWindow.DrawLine (gc, 0, y, 100, y);
        }
        
        // Draw stack number
		if (!popped) {
			Context context = da.CreatePangoContext ();
			Pango.Layout layout = new Pango.Layout (context);
			FontDescription desc = FontDescription.FromString ("Mono 20");
			layout.FontDescription = desc;
			layout.SetText (this.entry2.Text);
			da.GdkWindow.DrawLayout (gc, 5, newRec.Y, layout);
		}
    }
}
