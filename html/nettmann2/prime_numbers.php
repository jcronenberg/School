<?php
function isPrime($number) {
    if ($number <= 1)
        return false;

    for ($i = 2; $i < sqrt($number); $i++)
        if ($number % $i == 0)
            return false;

    return true;
}

function fillNumbers($amount) {
    // Initialise numbers array
    $numbers = array();

    // Set random start
    $rand_start = rand(0, 100);

    // Generate numbers
    for ($i = 0; $i < $amount; $i++) {
        $numbers[$i] = $i + $rand_start;
    }

    return $numbers;
}

function printNumbers($numbers, $height, $width) {
    // Initial variables
    $count_primes = 0;
    $count_prime_pairs = 0;

    // Print table
    echo '<table cellpadding="5" border="1px solid black">';
    for ($i = 0; $i < $height; $i++) {
        echo '<tr>';
        for ($j = 0; $j < $width; $j++) {
            $cur_n = $numbers[$i * $height + $j];
            if (isPrime($cur_n)) {
                // Check if cur_n is also a pair
                if ((isPrime($cur_n - $width) and $i > 0) or (isPrime($cur_n + $width) and $i < ($height - 1))) {
                    $background_color = '#ff0000';
                    $count_prime_pairs++;
                } else {
                    $background_color = '#ffff00';
                    $count_primes++;
                }
            } else {
                $background_color = '#ffffff';
            }
            echo '<td bgcolor="' . $background_color . '">' . $cur_n . '</td>';
        }
        echo '</tr>';
    }
    echo '</table>';
    echo '<p>Prime Numbers: ' . $count_primes . '</p>';
    $count_prime_pairs /= 2;
    echo '<p>Prime Number Pairs: ' . $count_prime_pairs . '</p>';
}
$amount_numbers = 400;
echo '<h1>' . $amount_numbers . ' Numbers</h1>';
$arr_numbers = fillNumbers($amount_numbers);
printNumbers($arr_numbers, sqrt($amount_numbers), sqrt($amount_numbers));
?>
