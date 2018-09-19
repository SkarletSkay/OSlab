#!/bin/bash

counter=1

while [ $counter -le 300 ]
do

	if `ln file file.lock`;  then
		var=$( tail -n 1 "file" )
		echo  $((var+1)) >> "file"
		counter=`expr $counter + 1`
		rm file.lock
	fi

done