#!/bin/bash
echo "$0 listFromPortage.txt outputDirectory"
while IFS= read -r line
do 
	for word in $line
	do
		eval "wget -P " $2 $word 
	done 
done < $1
