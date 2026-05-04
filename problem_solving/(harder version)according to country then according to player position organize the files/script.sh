#!/bin/bash


find . -type f -name "*.txt" | while read file

do
    country_name=$(head -2 "$file"|tail -1)
    position=$(head -4 "$file"|tail -1)

    if [ ! -f "$country_name" ]
        then 
            mkdir "$country_name"
    fi    

    if [ ! -f "$country_name/$position" ]
        then 
            mkdir "$country_name/$position"
    fi  

    mv "$file" "$country_name/$position" 




done
find . -type d -empty -delete
