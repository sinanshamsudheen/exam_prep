#!/bin/bash
echo "enter the number"
read num
temp=$num
rev=0
while [ $num -gt 0 ];
do
	rem=$((num%10))
	rev=$((rev*10 + $rem))
	num=$((num/10))
done
if [ $rev -eq $temp ];
then
	echo "palindrome"
else
	echo "not palindrome"
fi
