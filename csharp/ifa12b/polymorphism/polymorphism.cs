using System;

public class Program
{
    public static void Main()
    {
        const int armysize = 18;
        Random rnd = new Random();
        string[] Namensliste = {"Arnold", "Albert", "Anselm", "Edeltraud", "Bertha", "Olga"};
        Einheit[] Armee = new Einheit[armysize];
        for (int i = 0; i < armysize; i++)
        {
            if (i < 6)
            {
                Armee[i] = new Bogenschuetze(rnd.Next(20), Namensliste[rnd.Next(Namensliste.Length)]);
            }
            else if (i < 12)
            {
                Armee[i] = new Infanterie(rnd.Next(20), Namensliste[rnd.Next(Namensliste.Length)]);
            }
            else
            {
                Armee[i] = new Kavallerie(rnd.Next(20), Namensliste[rnd.Next(Namensliste.Length)]);
            }
        }

        for (int i = 0; i < armysize; i++)
        {
			// Version 1
            Armee[i].kampf();
			// Version 2
            // Armee[i].kampf(Armee[(i + rnd.Next(armysize)) % armysize]);
        }
    }
}

public class Einheit
{
    public string Name;
    public int Angriff;
    public int Verteidigung;
    public float Reichweite;

    public virtual void kampf()
	{
        Console.WriteLine($"Einheit fügt {Angriff} Schaden zu");
    }

	public virtual void kampf(Einheit gegner)
	{
        Console.WriteLine($"Einheit fügt {Angriff} Schaden dem Gegner \"{gegner.Name}\" zu");
    }

    public Einheit(int a, string name)
    {
        Name = name;
        Angriff = a;
        Verteidigung = a;
        Reichweite = (float)a + 50;
    }
}

public class Bogenschuetze : Einheit
{
    public int AnzahlPfeile = 0;

    public Bogenschuetze(int a, string name) : base(a, name)
    {
        AnzahlPfeile = a;
    }

    public override void kampf()
	{
        Console.WriteLine($"Bogenschütze \"{Name}\" hat {AnzahlPfeile} Pfeile und schießt über {Reichweite} m und fügt {Angriff} Schaden zu");
    }

    public override void kampf(Einheit gegner)
    {
        Console.WriteLine($"Bogenschütze \"{Name}\" hat {AnzahlPfeile} Pfeile und schießt über {Reichweite} m und fügt {Angriff} Schaden dem Gegner \"{gegner.Name}\" zu");
    }
}

public class Infanterie : Einheit
{
    public string SchwertArt;

    public Infanterie(int a, string name) : base(a, name)
    { }

    public override void kampf()
    {
        Console.WriteLine($"Infanterie \"{Name}\" greift im Nahkampf an und fügt {Angriff} Schaden zu");
    }
}

public class Kavallerie : Einheit
{
    public string PferdeArt;

    public Kavallerie(int a, string name) : base(a, name)
    { }

    public override void kampf()
    {
        Console.WriteLine($"Kavallerie \"{Name}\" reitet los und fügt {Angriff} Schaden zu");
    }
}
