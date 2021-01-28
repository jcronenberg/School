<?php
if (isset($_POST["cmbCar"]) && isset($_POST["dtDate"]) && isset($_POST["optPayment"]) && isset($_POST["chkAgreement"])) {
    echo "<h1>Thank you for your Order</h1>";
    echo "You ordered:<br><br>";
    echo "Car: " . $_POST["cmbCar"] . "<br>";
    echo "Date: " . $_POST["dtDate"]. "<br>";
    echo "Payment Method: " . $_POST["optPayment"]. "<br>";
} else {
    echo "<h1>Error: Some fields were left empty</h1>";
}
?>
