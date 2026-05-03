#!/bin/bash

for file in *.txt
do
    country_name=$(head -2 "$file"|tail -1)
    posi_name=$(head -4 "$file"|tail -1)

    if [ ! -d "$country_name" ]
        then
            mkdir "$country_name"


    fi
    if [ ! -d "$country_name/$posi_name" ]
        then
            mkdir "$country_name/$posi_name"


    fi

    mv "$file" "$country_name/$posi_name"




done
