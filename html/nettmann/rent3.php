<?php
session_start();
$logged_in = false;
?>

<!DOCTYPE html>
<html lang="de">
  <head>
	  <meta charset="utf-8">
	  <meta name="viewport" content="width=device-width, initial-scale=1.0">
	  <title>Autohaus Nettmann</title>

	  <link rel="stylesheet" href="style.css">
	  <link rel="stylesheet" href="main.css">
	  <link rel="stylesheet" href="rent.css">

      <style>
          td {
              text-align: left;
          }
      </style>
  </head>
  <body>
	<div class="navigation">
		<ul>
		  <li> <a  href="#home">Servicetermin</a></li>
		  <li> <a  href="rent1.php">Mietwagen</a></li>
		  <li> <a  href="#contact">Kontakt</a></li>
		  <li> <a  href="#about">Über uns</a></li>
		  <li style="float:right"><a href="#about">Login</a></li>
		</ul>
	</div>
	<div class="bg_rent">
		<div class ="rent" style="text-align: center;">
            <?php
                if(isset($_SESSION['data_complete'])) {
                    $data_complete = $_SESSION['data_complete'];
                    if(!$data_complete) {
                        echo 'Data incomplete';
                    }
                } else {
                    $data_complete = false;
                }

                if($data_complete) {
                    $abholen = $_SESSION['abholen'];
                    $abgeben = $_SESSION['abgeben'];
                } else {
                    $abholen = 'MISSING';
                    $abgeben = 'MISSING';
                }


                if(isset($_POST["cartype"]))
                {
                    $cartype = $_POST["cartype"];
                }
                else
                {
                    $cartype = "MISSING";
                    $data_complete = false;
                }

                echo "Ihre Anfrage mit den folgenden Daten wird bearbeitet:";
                echo "<table> \n";
                echo "<tr>\n";
                echo "  <td>Abholdatum: </td> \n";
                echo "  <td> $abholen</td> \n";
                echo "</tr>\n";
                echo "<tr>\n";
                echo "  <td>Abgabedatum: </td> \n";
                echo "  <td> $abgeben</td> \n";
                echo "</tr>\n";
                echo "<tr>\n";
                echo "  <td>Wagentyp: </td> \n";
                echo "  <td> $cartype</td> \n";
                echo "</tr>\n";
                echo "</table>\n";

                if($data_complete == false)

                {
                    echo "Leider konnte Ihre Anfrage aufgrund fehlender Angaben nicht bearbeitet werden.";
                }
            ?>
		</div>
	</div>
  </body>
</html>
