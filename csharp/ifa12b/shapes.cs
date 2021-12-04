using System;

class CRechteck
{
    // dA is parallel to the x axis and dB parallel to the y axis
    private double dA, dB, dX, dY;

    public CRechteck(double a, double b)
    {
        if (!setSeitenlaenge(a, b)) {
            dA = 0;
            dB = 0;
        }
    }

    public CRechteck(double a, double b, double x, double y)
    {
        if (!setSeitenlaenge(a, b))
        {
            dA = 0;
            dB = 0;
        }

        if (!setCoordinates(x, y))
        {
            dX = 0;
            dY = 0;
        }
    }

    public bool setSeitenlaenge(double a, double b)
    {
        if (a <= 0 || b <= 0)
            return false;

        dA = a;
        dB = b;
        return true;
    }

    public bool setCoordinates(double x, double y)
    {
        if (x <= 0 || y <= 0)
            return false;

        dX = x;
        dY = y;
        return true;
    }

    public double getA()
    {
        return dA;
    }

    public double getB()
    {
        return dB;
    }

    public double getX()
    {
        return dX;
    }

    public double getY()
    {
        return dY;
    }

    public double getFlaeche()
    {
        return dA * dB;
    }

    public double getUmfang()
    {
        return 2 * dA + 2 * dB;
    }

    public bool detectCollision(CRechteck rechteck)
    {
        if (rechteck.getX() < dX)
            return false;
        return false;
    }
}

class CKreis
{
    private double dRadius;

    public CKreis(double r)
    {
        if (!setRadius(r))
            dRadius = 0;
    }

    public bool setRadius(double r)
    {
        if (r <= 0)
            return false;

        dRadius = r;
        return true;
    }

    public double getRadius()
    {
        return dRadius;
    }

    public double getFlaeche()
    {
        return Math.Pow(dRadius, 2) * Math.PI;
    }

    public double getUmfang()
    {
        return dRadius * 2 * Math.PI;
    }
}

class Program
{
    static void Main(string[] args)
    {
        CRechteck MeinGenialesRechteck = new CRechteck(-1, 0);
        Console.WriteLine("CRechteck(-1, 0):");
        Console.WriteLine($"dA: {MeinGenialesRechteck.getA()}, dB: {MeinGenialesRechteck.getB()}");
        Console.WriteLine($"Flaeche: {MeinGenialesRechteck.getFlaeche()}, Umfang: {MeinGenialesRechteck.getUmfang()}");
        Console.WriteLine("====================================");
        MeinGenialesRechteck = new CRechteck(5, 3);
        Console.WriteLine("CRechteck(5, 3):");
        Console.WriteLine($"dA: {MeinGenialesRechteck.getA()}, dB: {MeinGenialesRechteck.getB()}");
        Console.WriteLine($"Flaeche: {MeinGenialesRechteck.getFlaeche()}, Umfang: {MeinGenialesRechteck.getUmfang()}");
        Console.WriteLine("====================================");
        Console.WriteLine($"setSeitenlaenge(10, -1): {MeinGenialesRechteck.setSeitenlaenge(10, -1)}");
        Console.WriteLine($"setSeitenlaenge(10, 7): {MeinGenialesRechteck.setSeitenlaenge(10, 7)}");
        Console.WriteLine($"dA: {MeinGenialesRechteck.getA()}, dB: {MeinGenialesRechteck.getB()}");
        Console.WriteLine($"Flaeche: {MeinGenialesRechteck.getFlaeche()}, Umfang: {MeinGenialesRechteck.getUmfang()}");
        Console.WriteLine("====================================");

        CKreis MeinGenialerKreis = new CKreis(5);
    }
}
