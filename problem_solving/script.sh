#!/bin/bash

for file in *.txt

do
    dir_name=$(tail -2 "$file"|head -1)

    if [ ! -d "$dir_name" ]
        then
            mkdir "$dir_name"

    fi
    mv "$file" "$dir_name"


done
