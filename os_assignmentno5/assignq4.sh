#!/bin/bash

#  number prime or not
function print_num ()
{
  echo "$1 $2"

}

print_num 1 10

function check_prime ()
{
	flag=0
    i=2
   while [ $i -lt $1]
   do

   if [ `expr $1 % $i` -eq 0]
     then
      flag=1

     if
     i= `expr $i + 1`
    
		
    
    echo $flag

}

res=$( check_prime 9)

	echo "res = $res"
	if[ $res -eq 0]
	then
	echo "prime"
	else
	echo "not prime"
	fi
