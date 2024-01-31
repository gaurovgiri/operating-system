#!/bin/bash

prev_term=0
next_term=1
echo -n "Fibonacci Series: $prev_term $next_term "
for ((i = 0; i < $(($1-2)); i++))
do
	evaluated=$((prev_term+next_term))
	prev_term=$next_term
	next_term=$evaluated
	
	echo -n "$next_term "
	
done

