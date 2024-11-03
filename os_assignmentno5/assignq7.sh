#!/bin/bash

echo "Enter file name :"
read path

if [ -e $path ]
then
 if [ -d $path ]
 then
    echo "files is Directory.."
	elif [ -f $path ]
	then 
	   echo "Regular file..."
	   if [-x $path ]
	   then 
	     echo "file has executable permission"
	   fi
  fi
  else
  echo "file not exists"
fi  
