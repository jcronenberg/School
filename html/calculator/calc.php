<?php
session_start();
function calculate($op, $op1, $op2) {
    switch($op) {
        case '+':
            return $op1 + $op2;
        case '-':
            return $op1 - $op2;
        case '*':
            return $op1 * $op2;
        case '/':
            return $op1 / $op2;
        case 'x^y':
            return pow($op1, $op2);
    }
    return 0;
}

function get_post() {
    global $res, $op1, $op2, $operator;
    if (isset($_POST["res"])) {
        $res = $_POST["res"];
    }
    if (isset($_POST["op1"])) {
        $op1 = $_POST["op1"];
    }
    if (isset($_POST["op2"])) {
        $op2 = $_POST["op2"];
    }
    if (isset($_POST["operator"])) {
        $operator = $_POST["operator"];
    }
}

$res = 0;
$op1 = 0;
$op2 = 0;
$operator = '+';

if (!isset($_POST["clear"])) {
    get_post();
}

// get results from session
if (isset($_SESSION["results"])) {
    $results = $_SESSION["results"];
}
// if not in session, create array
else {
    $results = array();
}

// Buttons
// Calculate Button
if (isset($_POST["calc_btn"])) {
    // calculation
    $res = calculate($operator, $op1, $op2);

    // Store res in session
    $_SESSION["res"] = $res;

    // Store res in results array
    array_push($results, $res);
}

// Store Button
if (isset($_POST["store_btn"]) && isset($_SESSION["res"])) {
    $store = $_SESSION["res"];
    $_SESSION["store"] = $store;
}

// Fill from register button
if (isset($_POST["use_store"]) && isset($_SESSION["store"])) {
    if (isset($_SESSION["store"])) {
        $store = $_SESSION["store"];
    }
    $op1 = $store;
}

// clear results Button
if (isset($_POST["clear_results"])) {
    $results = array();
}

$_SESSION["results"] = $results;
?>

<!doctype html>
<html lang="en">

    <head>
        <meta charset="UTF-8" />
        <title>Document</title>
    </head>

    <body>
        <center>
            <h1>Calculator</h1>
            <table>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <select name="results" style="overflow: auto; width: 50px" size="4">
                        <?php
                        for ($i = 0; $i < count($results); $i++) {
                            echo "<option>" . $results[$i] . "</option>";
                        }
                        ?>
                        </select>
                    </td>
                </tr>
                <form action="calc.php" method="post">
                <tr>
                    <th>Operand 1</th>
                    <th>Operator</th>
                    <th>Operand 2</th>
                    <th>Result</th>
                </tr>
                <tr>
                    <td>
                            <input name="op1" type="text" value="<?PHP echo $op1; ?>"/>
                    </td>
                    <td>
                        <center>
                            <select name="operator">
                                <?php
                                $list_operators = array('+', '-', '*', '/', 'x^y');
                                for ($i = 0; $i < count($list_operators); $i++) {
                                    echo "<option";
                                    if ($operator == $list_operators[$i])
                                        echo " selected";
                                    echo ">" . $list_operators[$i] . "</option>";
                                }
                                ?>
                            </select>
                        </center>
                    </td>
                    <td>
                            <input name="op2" type="text" value="<?PHP echo $op2; ?>"/>
                    </td>
                    <td>
                            <label for="res">= </label>
                            <input name="res" type="text" value="<?PHP echo $res; ?>"/>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td>
                        <?PHP
                        if(isset($_SESSION["store"])) {
                            echo "Store: " . $_SESSION["store"];
                        }
                        ?>
                    </td>
                    <td>
                        <input type="submit" name="calc_btn" value="Calculate">
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <input type="submit" name="clear" value="C">
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <input type="submit" name="clear_results" value="RC">
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <input type="submit" name="store_btn" value="M+">
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <input type="submit" name="use_store" value="MR">
                    </td>
                </tr>
                </form>
            </table>
        </center>
    </body>

</html>
