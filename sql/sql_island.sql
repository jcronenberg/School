SELECT * FROM bewohner;

SELECT * FROM bewohner WHERE status = 'friedlich';

SELECT
    *
FROM
    bewohner
WHERE
    status = 'friedlich' AND beruf = 'Waffenschmied';

SELECT
    *
FROM
    bewohner
WHERE
    status = 'friedlich' AND beruf LIKE '%schmied';

SELECT bewohnernr FROM bewohner WHERE name = 'Fremder';

SELECT gold FROM bewohner WHERE name = 'Fremder';

SELECT * FROM gegenstand WHERE besitzer IS NULL;

UPDATE gegenstand SET besitzer = 20 WHERE besitzer IS NULL;

SELECT * FROM gegenstand WHERE besitzer = 20;

SELECT
    *
FROM
    bewohner
WHERE
    status = 'friedlich'
    AND (beruf = 'Haendler' OR beruf = 'Kaufmann');

UPDATE
    gegenstand
SET
    besitzer = 15
WHERE
    gegenstand = 'Ring' OR gegenstand = 'Teekanne';

UPDATE bewohner SET name = 'Jorik' WHERE bewohnernr = 20;

SELECT
    *
FROM
    bewohner
WHERE
    beruf = 'Baecker'
ORDER BY
    gold DESC;

SELECT * FROM bewohner WHERE beruf = 'Pilot';

SELECT
    bewohner.name
FROM
    dorf, bewohner
WHERE
    bewohner.bewohnernr = dorf.haeuptling
    AND dorf.name = 'Zwiebelhausen';

SELECT
    count(*)
FROM
    bewohner, dorf
WHERE
    dorf.dorfnr = bewohner.dorfnr
    AND dorf.name = 'Zwiebelhausen'
    AND bewohner.geschlecht = 'w';

SELECT
    bewohner.name
FROM
    bewohner, dorf
WHERE
    dorf.dorfnr = bewohner.dorfnr
    AND dorf.name = 'Zwiebelhausen'
    AND bewohner.geschlecht = 'w';

SELECT
    sum(gold)
FROM
    bewohner
WHERE
    beruf = 'Haendler'
    OR beruf = 'Kaufmann'
    OR beruf = 'Baecker';

SELECT
    status, avg(bewohner.gold)
FROM
    bewohner
GROUP BY
    status
ORDER BY
    avg(bewohner.gold);

DELETE FROM bewohner WHERE name = 'Dirty Doerthe';

UPDATE
    bewohner
SET
    status = 'friedlich'
WHERE
    beruf = 'Pilot';

INSERT INTO solution VALUES (1, 'Jeremy Bowers');

SELECT value FROM solution;
