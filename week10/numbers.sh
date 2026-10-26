#! /bin/bash

#1.	Create a script that adds all elements of the list numbers=(1 2 3 4 5 6 7 8 9)
# numbers=(1 2 3 4 5 6 7 8 9)
sum=0
for n in $*
do
    ((sum = sum + n))
    # sum=$sum+$n
done
echo "Sum of all command line arguments is $sum"

echo "The average of of all command line arguments is "
# if [ $# -ne 0 ];then
if (( $# != 0 )) ;then
    # ((average=$sum/${#}))
    echo "scale=2; $sum/${#}" | bc
else
    echo 0
fi
# echo "scale=2; 21/6" | bc

average=$(echo "scale=2; $sum/${#}" | bc)
echo $average