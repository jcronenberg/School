SELECT
    city.name
FROM
    city, country
WHERE
    country.name = 'Germany'
    AND city.countrycode = country.code;

SELECT
    name, surfacearea
FROM
    country
ORDER BY
    surfacearea DESC
LIMIT
    10;

SELECT code FROM country;

SELECT
    name, population
FROM
    city
ORDER BY
    population DESC
LIMIT
    1;

SELECT name FROM country WHERE governmentform = 'Republic';

SELECT
    avg(lifeexpectancy)
FROM
    country
WHERE
    continent = 'Europe';

SELECT
    name
FROM
    country
WHERE
    population > 10000000 AND continent = 'Europe';

SELECT name FROM country WHERE lifeexpectancy < 50;

SELECT name FROM country WHERE gnp > 100000;

SELECT name FROM country WHERE population < 80000000;

SELECT name FROM country WHERE lifeexpectancy > 85;

SELECT
    country.name
FROM
    country, countrylanguage
WHERE
    countrylanguage.language = 'Spanish'
    AND countrylanguage.countrycode = country.code;

SELECT
    name
FROM
    city
WHERE
    population < 100000 AND population > 50000
ORDER BY
    population DESC;

SELECT name FROM country WHERE population > 50000000;
