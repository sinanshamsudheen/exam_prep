#!/bin/bash
echo "Please enter a number"
read num
factorial=1

if [ $num -lt 0 ]; then
    echo "Factorial not defined for negative numbers"
else
    for ((i=1; i<=num; i++))
    do
        factorial=$((factorial * i))
    done
    echo "Factorial of $num is $factorial"
fi

