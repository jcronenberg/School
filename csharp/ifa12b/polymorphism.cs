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
            int rndnumber = rnd.Next(Namensliste.Length);
            if (i < 6)
            {
                Armee[i] = new Bogenschuetze(rndnumber);
            }
            else if (i < 12)
            {
                Armee[i] = new Infanterie();
            }
            else
            {
                Armee[i] = new Kavallerie();
            }

            Armee[i].Name = Namensliste[rndnumber];
            Armee[i].Angriff = rndnumber;
            Armee[i].Verteidigung = rndnumber;
            Armee[i].Reichweite = (float)rndnumber + 50;
        }

        for (int i = 0; i < armysize; i++)
        {
            Armee[i].kampf();
        }
    }
}

public class Einheit
{
    public string Name;
    public int Angriff;
    public int Verteidigung;
    public float Reichweite;

    public virtual void kampf() {
        Console.WriteLine($"Einheit fügt {Angriff} Schaden zu");
    }

}

public class Bogenschuetze : Einheit
{
    public int AnzahlPfeile = 0;
    public override void kampf() {
        Console.WriteLine($"Bogenschütze \"{Name}\" hat {AnzahlPfeile} Pfeile und schießt über {Reichweite} m und fügt {Angriff} Schaden zu");
    }

    public Bogenschuetze(int a)
    {
        AnzahlPfeile = a;
    }
}

public class Infanterie : Einheit
{
    public string SchwertArt;
    public override void kampf()
    {
        Console.WriteLine($"Infanterie \"{Name}\" greift im Nahkampf an und fügt {Angriff} Schaden zu");
    }
}

public class Kavallerie : Einheit
{
    public string PferdeArt;
    public override void kampf()
    {
        Console.WriteLine($"Kavallerie \"{Name}\" reitet los und fügt {Angriff} Schaden zu");
    }
}
