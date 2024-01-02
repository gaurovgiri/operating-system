#!/bin/bash

if [ $1 -eq $2 ]; then
	echo both are equal
elif [ $1 -gt $2 ]; then
	echo $1 is greater than $2
else
	echo $2 is greater than $1
fi

