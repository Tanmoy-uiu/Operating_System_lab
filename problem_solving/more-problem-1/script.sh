#!/bin/bash

if [ $# -eq 0 ]; then
    echo "usage: $0 filename1 filename2 ..."
    exit
fi
for file in "$@"
do
    if [ ! -e "$file" ]
        then
            echo "$file does not exits"
    
    elif [ ! -f "$file" ]
        then
            echo "$file is not a regular file"
   
    else
        if [ -x "$file" ]
            then
                echo "$file is currently executable"
        
        else
            echo "$file is not currently executable"
        fi
        echo "$file's executable permission is now changing"

        chmod -x "$file"
        ls -l "$file"

        

    fi

    




done
