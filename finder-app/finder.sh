#!/bin/bash

filesdir=$1
searchstr=$2
cond=$(test -n "$filesdir" && test -n "$searchstr")
if $cond
then 
	if [ -d $filesdir ]
	then 
		cd $filesdir
		filecount=$(find $filesdir -type f 2> /dev/null | wc -l)
		foundtxt=$(grep -ri "$searchstr" $filesdir 2> /dev/null | wc -l)
		echo "The number of files are $filecount and the number of matching lines are $foundtxt"
	else 
		echo "This is not a directory"
		exit 1
	fi
else 

	echo "Ther's a missing parameter, try to run script again with valid parameters"
	exit 1
fi	
