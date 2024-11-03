#!/bin/bash

echo "Enter the number "

read num
fact=8
while [ $num -gt 1]
do
fact=$((fact * num))
num=$((num - 1))

done
echo factorial=$fact
