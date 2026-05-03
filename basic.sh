#!/bin/bash
:<<'COMMENT'
x=AzizulAnik #variables takes value as a string
y="Azizul Anik   tanmoy"
z=0012  #string hisebe count kore
a=$((12))   #number hisebe nibe
echo $x
echo $y
echo $z
echo $a

# ls -1

x=$(ls -1)
echo $x

------------------------------------------------
#mathematical expression-->$((expression))

x=10
y=20

sum=$((x+y)) #mathematical expression guloke ei vabe likhbo
echo "Sum: $sum" 
------------------------------------------------

#take input from user
echo "Enter your name:" 
read name
echo "Hello, $name"

---------------------------------------------

#take input from command line
# $1, $2 , $3 , ....are the positional parameters
echo "hello,$1"
# bash basics.sh Anik--->outpout: hello,Anik

--------------------------------------------

echo "hello, $1 $2 $3"
#bash basics.sh siam afroz tanmoy--->hello, siam afroz tanmoy
----------------------------------------------
echo "hello, $3 $2"
#bash basics.sh siam afroz tanmoy --->hello, tanmoy afroz

----------------------------------------------------------


exit status er value:
ei code linux terminal a korbo:
-----1---------
echo anik-->output: anik
echo $?--->output:0(true hoisilo tai)
----2-------
true
echo $?---->output:0
---3------
false
echo $?---->output: 1
----------------------------



#conditional syntax:

x=1000  #surute $ deya hoini
#if [ $x -lt 50 -a $x -gt 0 ]
if (( $x<50 && x>0 )) #ekhane $x dileo hobe na dileo hobe
then
    echo "$x is less than 50 and greater than 0 "

#elif [ $x -lt 100 ]  
elif (( x<100 ))

then 
    echo "$x is less than 100 "
else
    echo "$x is greater than 100"

fi
    


--------------------------------------------



if true
then 
    echo "true"

else
    echo "false"

fi

------------------------------



if false
then 
    echo "true"

else
    echo "false"

fi

------------------------------


if echo "hello" 
then 
    echo "true"

else
    echo "false"

fi

-----------------------------


-f file_name = true if file name is a regular file/ bar file ta exits kore
-d name =true if name is a directory
-r file_name = true if file_name has read permission
-w file_name
-x file_name


file_name="basics.sh"
if [ -f "$file_name" ]
then 
    echo "file exists"
else
    echo "file does not exists"
fi    
-----------------------------------------------------



file_name="basis.sh"
if [ -f "$file_name" ]
then 
    echo "file exists"
else
    echo "file does not exists"
fi 

-------------------------------------------------------
#looppppppppppppppppppppppppppppppppp


*--> star, asole current folder a jotogulo filename or foldername ase segulor akta list banay

for file in *  #for file in list ,,,do print  filename
do
    echo "$file"

done

------------------------------------------

#find only text files

for file in *.txt #surute jai thakuk ses a .txt jeno thake
do
    echo "$file"

done
-----------------------------------
COMMENT
#c program type loop
for (( i=0;i<5; i++ ))
do
    echo $i

done
---------------------------------------------------
solve of cls-prob1

#!/bin/bash

for file in *.txt 
do
    dir_name=$(tail -2 "$file" | head -1)
    if [ ! -d "$dir_name" ]
        then
            mkdir "$dir_name"
    fi    

    mv "$file" "$dir_name"


done

-------------------------
solve--2

#!/bin/bash

for file in *.txt
do
    country_name=$(head -2 "$file" | tail -1)
    position_name=$(head -4 "$file" | tail -1)

    if [ ! -d "$country_name" ]; then
        mkdir "$country_name"
    fi

    if [ ! -d "$country_name/$position_name" ]; then
        mkdir -p "$country_name/$position_name"
    fi

    mv "$file" "$country_name/$position_name"
done
------_-----------------------asol solve-----------------
#!/bin/bash

find . -type f -name "*.txt" | while read file
do
    country_name=$(head -2 "$file" | tail -1)
    position_name=$(head -4 "$file" | tail -1)

    if [ ! -d "$country_name" ]; then
        mkdir "$country_name"
    fi

    if [ ! -d "$country_name/$position_name" ]; then
        mkdir -p "$country_name/$position_name"
    fi

    mv "$file" "$country_name/$position_name/"
done


find . -type d -empty -delete



------------------------------more(2)----------
#!/bin/bash

line="$1"
pattern="$2"

for file in *.txt; do
    line_count=$(head -n "$line" "$file" | tail -1 | grep "$pattern" | wc -l)

    if [ "$line_count" -gt 0 ]; then
        rm "$file"
    fi
done

--------------------------------more 1-------------------
#!/bin/bash

# 1. argument আছে কিনা check
if [ $# -eq 0 ]; then
    echo "Usage $0 filename1 filename2 ..."
    exit
fi

# 2. সব file loop
for file in "$@"; do

    # 3. file নাই
    if [ ! -e "$file" ]; then
        echo "$file doesnot exist."

    # 4. regular file না
    elif [ ! -f "$file" ]; then
        echo "$file is not a regular file."

    # 5. executable check
    elif [ -x "$file" ]; then
        echo "$file is currently executable."
        ls -l "$file"

        chmod -x "$file"

        echo "$file's executable permission is now changing."
        ls -l "$file"

    else
        echo "$file is currently not executable."
    fi

done
--------------------------------more er 3-------------------
#!/bin/bash

for file in *
do
    if [ -f "$file" ]
        then
            echo "$file" | grep -q '[0-9]'

            if [ $? -eq 0 ]
                then 
                    rm "$file"
            fi    
    fi

done
