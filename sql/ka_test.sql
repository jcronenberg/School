SELECT
    population AS "Einwohnerzahl"
FROM
    country
WHERE
    name = "Russia";

SELECT
    name AS "Landesname", population AS "Einwohnerzahl"
FROM
    country
WHERE
    population > 250000000;

SELECT
    name AS "Laendername",
    population / 1000000 AS "Einwohnerzahl in Millionen"
FROM
    country
WHERE
    continent = "Asia" AND population > 100000000;

SELECT
    name AS "Laendername"
FROM
    country
WHERE
    name LIKE "B%n";

SELECT * FROM country ORDER BY population DESC LIMIT 1;

SELECT
    count(id) AS "Anzahl"
FROM
    city
WHERE
    countrycode = "DEU";

SELECT
    continent AS "Kontinent",
    count(code) AS "Anzahl Laender"
FROM
    country
GROUP BY
    continent;

SELECT
    name AS "Landesname", population AS "Einwohnerzahl"
FROM
    country
WHERE
    continent = "Europe"
ORDER BY
    population DESC
LIMIT
    3;

SELECT
    country.name AS "Landesname",
    city.name AS "Hauptstadt",
    country.population AS "Einwohnerzahl des Landes"
FROM
    country JOIN city ON country.capital = city.id
ORDER BY
    country.population DESC;

SELECT
    country.name AS "Land",
    city.name AS "Hauptstadt",
    count(DISTINCT cl.language)
        AS "Anzahl offizieller Sprachen"
FROM
    country
    JOIN city ON country.capital = city.id
    JOIN countrylanguage AS cl ON
            country.code = cl.countrycode
WHERE
    cl.isofficial = "T"
GROUP BY
    country.name;

CREATE DATABASE sportliga;

CREATE TABLE trainer (
    id
        INT PRIMARY KEY,
    name
        VARCHAR(50),
    trainerschein
        VARCHAR(30)
);

CREATE TABLE verein (
  id INT8 PRIMARY KEY,
  name VARCHAR(50),
  trainer INT,
    CONSTRAINT trainer
        FOREIGN KEY (trainer)
        REFERENCES trainer (id)
        ON DELETE CASCADE ON UPDATE RESTRICT
);
