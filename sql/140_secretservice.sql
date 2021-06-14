--ALTER TABLE person MODIFY PersonID INT auto_increment;

INSERT
INTO
    person
        (vorname, nachname, geburtsjahr, strasse, plz, ort)
VALUES
    (
        "Linus",
        "Dorkel",
        1993,
        "Ruebenacker 13",
        44532,
        "Luenen"
    ),
    (
        "Viola",
        "Bornekamp",
        1995,
        "Eichenallee 25",
        44532,
        "Luenen"
    ),
    (
        "Lasse",
        "Wolkentied",
        1987,
        "Von Galen-Straße 40",
        59192,
        "Bergkamen"
    );

DELETE FROM person WHERE Vorname IN ('Nadja', 'Peter', 'Tom') AND Nachname IN ('Heinings', 'Klapper', 'Großfeld');

UPDATE person SET Nachname = 'Alparto' WHERE Nachname = 'Baumann';

-- MariaDB [geheimdienst]> select * from person where Nachname = 'Baumann';
-- Empty set (0.001 sec)

-- MariaDB [geheimdienst]> select * from person where Nachname = 'Alparto';
-- +----------+----------+---------+---------------------+-------+----------+-------------+
-- | PersonID | Nachname | Vorname | Strasse             | PLZ   | Ort      | Geburtsjahr |
-- +----------+----------+---------+---------------------+-------+----------+-------------+
-- |       45 | Alparto  | Reana   | Alexanderstraße 12  | 48163 | Münster  |        1981 |
-- |      118 | Alparto  | Laura   | Agnesstraße 38      | 47652 | Weeze    |        1983 |
-- |      204 | Alparto  | Tanya   | Sydneystraße 12     | 47906 | Kempen   |        1991 |
-- +----------+----------+---------+---------------------+-------+----------+-------------+
-- 3 rows in set (0.001 sec)
