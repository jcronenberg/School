SELECT
    auftrnr AS auftragsnummer,
    kunde.name AS kunde,
    personal.name AS mitarbeiter
FROM
    auftrag
    JOIN kunde ON auftrag.kundnr = kunde.nr
    JOIN personal ON auftrag.persnr = personal.persnr;

SELECT
    k.name AS kundename,
    sum(ap.gesamtpreis) AS auftragsvolumen
FROM
    auftrag AS a
    JOIN auftragsposten AS ap ON ap.auftrnr = a.auftrnr
    JOIN kunde AS k ON k.nr = a.kundnr
GROUP BY
    kundnr
ORDER BY
    auftragsvolumen DESC;

SELECT
    lt.name AS lieferantenname,
    a.bezeichnung AS artikelname,
    a.anr AS artikelnummer
FROM
    artikel AS a
    JOIN lieferung AS lg ON a.anr = lg.anr
    JOIN lieferant AS lt ON lt.nr = lg.liefnr;

SELECT
    sum(l.bestand * a.netto) AS "Gesamtwert Lager"
FROM
    lager AS l JOIN artikel AS a ON a.anr = artnr;

SELECT
    lt.name AS Name,
    a.bezeichnung AS Bezeichnung,
    a.anr AS Artikelnummer,
    l.bestand AS Bestand,
    a.netto AS Nettostueckpreis,
    a.netto * l.bestand AS "Gesamtwert Artikel"
FROM
    artikel AS a
    JOIN lager AS l ON l.artnr = a.anr
    JOIN lieferung AS lg ON lg.anr = a.anr
    JOIN lieferant AS lt ON lt.nr = lg.liefnr;
