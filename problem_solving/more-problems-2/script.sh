#!/bin/bash

line=$1
pattern=$2
for file in *.txt
do
    line_count=$(head -"$line" "$file" |tail -1| grep "$pattern"|wc -l)

    if [ "$line_count" -gt 0 ]
        then 
            rm "$file"
    fi    


done
