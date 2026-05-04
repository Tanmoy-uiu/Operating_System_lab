#!/bin/bash


for file in *

do
    if [ -f "$file" ]; then
        echo "$file" | grep -q "[0-9]"

        if [ $? -eq 0 ]; then
            rm "$file"
        fi

    
    fi


done
