#!/bin/bash
#assignment 1 writer.sh
#script to write a string to a file
#auther: Ibrahim Nazzier
#Github: ibrahimnazzier

writefile=$1
writestr=$2
dir=$(dirname "${writefile}")
filename=$(basename "${writefile}")
if test -n "$writefile" && test -n "$writestr" && [ -n filename ]
then 
	if [ -d -$dir ] && [ -w $dir ] && [ -r $dir ]
	then 
		cd $dir    
		if [ -e $writefile ] && [ -w $writefile ] && [ -r $writefile ]
        then
            echo "$writestr" 1> ${writefile}
            cat $filename
        else -w
            touch $filename && chmod 775 $writefile
            echo "$writestr" 1> "${writefile}"
            cat $filename
        fi
	else 
		mkdir -m 775 -v -p $dir
        cd "$dir"
        touch $filename && chmod 775 $filename
        echo "$writestr" 1> ${writefile}
        cat $filename
	fi
else 
	echo "Ther's a missing parameter, try to run script again with valid parameters"
	exit 1
fi	
