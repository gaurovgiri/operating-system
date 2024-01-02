#!/bin/bash


#var1=5
#var2=3
read -p "Enter var1:" var1
read -p "Enter var2:" var2
echo "var1=$var1 var2=$var2"
#echo the sum is $var1 + $var2
echo the sum is $(($var1 + $var2))
echo the difference is $(($var1 - $var2))
echo the product is $(($var1 * $var2))
echo the division is $(($var1 / $var2))
echo the remainder is $(($var1 % $var2))
