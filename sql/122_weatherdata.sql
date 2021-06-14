--a
SELECT
    *
FROM
    Wettermessung AS wm
    JOIN wetterstation AS ws ON wm.stations_id = ws.s_id;

--b
--SELECT * FROM wetterstation WHERE standort = 'bamberg';
SELECT
    avg(mittel_2m) AS "Mittlere Temperatur"
FROM
    Wettermessung AS wm
WHERE
    wm.stations_id = 282 AND wm.datum LIKE '2020-08-%';

--c
SELECT
    count(DISTINCT wm.datum) AS "Anzahl Tage"
FROM
    Wettermessung AS wm;

--d
SELECT
    ws.standort AS "Name Wetterstation", ws.hoehe AS hoehe
FROM
    Wetterstation AS ws
ORDER BY
    ws.hoehe DESC
LIMIT
    10;

--e
SELECT
    ws.standort AS "Name Wetterstation"
FROM
    Wetterstation AS ws
ORDER BY
    ws.geo_breite ASC
LIMIT
    1;

--f
SELECT
    ws.standort AS "Name Wetterstation",
    ws.geo_breite AS "Breitengrad",
    ws.geo_laenge AS "Laengengrad"
FROM
    Wetterstation AS ws
ORDER BY
    ws.geo_breite + ws.geo_laenge DESC;

--g
SELECT
    ws.standort AS "Name Wetterstation",
    sum(wm.sonnenscheindauer) AS "gesamte Sonnenscheindauer"
FROM
    Wetterstation AS ws
    JOIN Wettermessung AS wm ON
            wm.stations_id = ws.s_id
GROUP BY
    ws.standort;

--h
SELECT
    ws.standort AS "Name Wetterstation",
    avg(wm.sonnenscheindauer)
        AS "durchschnittliche Sonnenscheindauer"
FROM
    Wetterstation AS ws
    JOIN Wettermessung AS wm ON
            wm.stations_id = ws.s_id
GROUP BY
    ws.standort;

--i
SELECT
    ws.standort AS "Name Wetterstation",
    avg(mittel_windstaerke) AS "Mittlere Windstaerke",
    sum(wm.sonnenscheindauer) AS "gesamte Sonnenscheindauer"
FROM
    Wetterstation AS ws
    JOIN Wettermessung AS wm ON
            wm.stations_id = ws.s_id
GROUP BY
    ws.standort;
