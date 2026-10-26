#! /bin/bash

#1.	Create a script that adds all elements of the list numbers=(1 2 3 4 5 6 7 8 9)
numbers=(1 2 3 4 5 6 7 8 9)
sum=0
for n in ${numbers[*]}
do
    ((sum = $sum + $n))
done
echo "Sam of all elements is $sum"