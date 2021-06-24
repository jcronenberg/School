<?php
$sum = 0;
$op1 = 0;
$op2 = 0;
if (isset($_POST["op1"]) && isset($_POST["op2"])) {
    $op1 = $_POST["op1"];
    $op2 = $_POST["op2"];
    $sum = $op1 + $op2;
}
?>
<!doctype html>
<html lang="en">

    <head>
        <meta charset="UTF-8" />
        <title>Document</title>
    </head>

    <body>
        <center>
            <h1>Taschenrechner</h1>
            <table>
                <tr>
                    <th>Operand 1</th>
                    <th>Operator</th>
                    <th>Operand 2</th>
                    <th>Ergebnis</th>
                </tr>
                <form action="calc2.php" method="post">
                <tr>
                    <td>
                            <input name="op1" type="text" value="<?PHP echo $op1; ?>"/>
                    </td>
                    <td><center>+</center></td>
                    <td>
                            <input name="op2" type="text" value="<?PHP echo $op2; ?>"/>
                    </td>
                    <td>
                            <label for="sum">= </label>
                            <input name="sum" type="text" value="<?PHP echo $sum; ?>"/>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <input type="submit" value="Berechnen">
                    </td>
                </tr>
            </table>
        </center>
    </body>

</html>
