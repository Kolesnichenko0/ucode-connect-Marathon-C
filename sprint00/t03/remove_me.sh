#!/bin/sh
for elem in "$@"
do
	if [ -f "$elem" ]
	then
		rm $elem
	fi
	if [ -d "$elem" ]
	then
	       	rmdir $elem
	fi
done




