#!/bin/bash

echo -e -n "Enter year :"
read year

if [`expr $year % 4` -eq 0 -a `expr $year % 100` -ne 0 -o `expr $year %400` -eq 0]

then 
   echo "Leap"

else 
   echo "not leap"

fi
