#!/bin/bash

#executable file in current directory
echo -e -n "Enter path :"
read path

if [ -e $path ]
then 

 if [-f $path ]
 then

   echo "It is a regular file"
   echo -e -n "file type : "
   stat -c %f $path
   echo "Inode No :"
   stat -c %i $path

else
  echo "It is directory"
fi

else
  echo "path not exsts"
fi



