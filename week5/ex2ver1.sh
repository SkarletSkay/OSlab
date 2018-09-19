#!/bin/bash

counter=0

while [ $counter -le 500 ]
do
	var=$( tail -n 1 "file" )
	echo  $((var+1)) >> "file"
	counter=`expr $counter + 1`
done
