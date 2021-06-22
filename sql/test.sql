SELECT * FROM fahrt WHERE abfahrtshafen = "Hamburg";

SELECT avg(monatsgehalt) AS "Mittleres Gehalt" FROM kapitän;

SELECT
    zielhafen, abfahrtsdatum AS datum
FROM
    fahrt
WHERE
    abfahrtshafen = "Rotterdam"
    AND abfahrtsdatum LIKE "2018-04-%";

SELECT * FROM flotte ORDER BY baujahr DESC LIMIT 1;

SELECT
    abfahrtsdatum AS datum,
    count(id_fahrt) AS "Anzahl Fahrten"
FROM
    fahrt
GROUP BY
    abfahrtsdatum;

SELECT
    kapitän.name AS "Name Kapitän",
    sum(fahrt.strecke) AS gesamtkilometer
FROM
    kapitän
    JOIN fahrt ON kapitän.id_kapitän = fahrt.id_kapitän
GROUP BY
    id_kapitän;

--h)

SELECT
    Fahrt.Abfahrtshafen AS "Anfahrtshafen",
    sum(Schiffstyp.Ladungskapazität)
        AS "Gesamtumschlag 2020"
FROM
    Fahrt
    JOIN Flotte ON
            Fahrt.Schiffskennzeichen
            = Flotte.Schiffskennzeichen
    JOIN schiffstyp ON
            Flotte.ID_Schiffstyp
            = Schiffstyp.ID_Schiffstyp
WHERE
    Abfahrtsdatum LIKE "2020-%"
GROUP BY
    Abfahrtshafen;
HAVING sum(Schiffstyp.Ladungskapazität) > 100000

CREATE TABLE Pilot(
  ID_Pilot INT PRIMARY KEY auto_increment,
  Name VARCHAR(30) NOT NULL,
  Monatsgehalt FLOAT
);

CREATE TABLE Flug(
  ID_Flug INT PRIMARY KEY auto_increment,
  Startflughafen VARCHAR(30) NOT NULL,
  Zielflughafen VARCHAR(30) NOT NULL,
  Strecke FLOAT,
  Abflugsdatum DATE NOT NULL,
  Luftfahrzeugkennzeichen VARCHAR(30) NOT NULL,
  ID_Pilot INT,
  CONSTRAINT fk_pilot
  FOREIGN KEY (ID_Pilot) REFERENCES Pilot (ID_Pilot)
);


-- new
CREATE TABLE Flug(
  ID_Flug INT PRIMARY KEY auto_increment,
  Startflughafen VARCHAR(30) NOT NULL,
  Zielflughafen VARCHAR(30) NOT NULL,
  Strecke FLOAT,
  Abflugsdatum DATE NOT NULL,
  Luftfahrzeugkennzeichen VARCHAR(30) NOT NULL,
  CONSTRAINT fk_kennzeichen
  FOREIGN KEY (Luftfahrzeugkennzeichen) REFERENCES Flotte (Luftfahrzeugkennzeichen)
  ID_Pilot INT NOT NULL,
  CONSTRAINT fk_pilot
  FOREIGN KEY (ID_Pilot) REFERENCES Pilot (ID_Pilot)
);
