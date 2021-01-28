<?php
if (isset($_POST["txtUsername"]) && isset($_POST["pwdPassword"])) {
    $username = $_POST["txtUsername"];
    $password = $_POST["pwdPassword"];
    if ($username == "Nettmann" && $password == "secret")
        echo "Welcome Mr " . $username;
    else
        echo "Wrong login info";
} else {
    echo "<h1>Error: Some fields were left empty</h1>";
}
?>
