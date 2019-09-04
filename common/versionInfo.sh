#!/bin/bash

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"

case $1 in
	toolkit-common)
		grep toolkit-common: $SCRIPTPATH/versionInfo.txt | grep -o -e [0-9]'\.[0-9]'\.[0-9]''
		;;
	toolkit-common-c++)
		retval=$(grep toolkit-common-c++: $SCRIPTPATH/versionInfo.txt | grep -o -e [0-9]'\.[0-9]'\.[0-9]'')
		if [ -z "$2" ]
		  then
			if [[ "$2" == "--dd" ]]
			  then
				separator=":"
				retval=${retval//./$separator}
			fi					
		else
			if [[ "$2" == "--dd" ]]
			  then
				separator=":"
				retval=${retval//./$separator}
			fi			
		fi
		echo $retval	
		;;
	toolkit-common-c)
		grep toolkit-common-c: $SCRIPTPATH/versionInfo.txt | grep -o -e [0-9]'\.[0-9]'\.[0-9]''	
		;;
esac
