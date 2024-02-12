# Develop a shell script that takes a valid directory name as an argument
# and recursively descend all the sub-directories, finds the maximum
# length of any file in that hierarchy, and store the output in a file.

#!/bin/bash

# you can also use for i in $*
for i in "$@"
do
    if [ -d "$i" ]
    then
        echo "The largest filename size is:"

        echo "$(ls -lR "$i" | grep "^-" | tr -s ' ' | cut -d ' ' -f 5 | sort -n | tail -1)"
        # ls -lR "$i": This command lists files and directories recursively (-R) in long format (-l)
        # |: This is the pipe operator, used to pass the output of one command as input to the next command.
        # grep "^-": This command filters the output of ls -lR "$i" to only include lines that start with a hyphen -, which indicates regular files.
        # tr -s ' ': This command squeezes (-s) repeated spaces into a single space. 
        # This is used to normalize the output from grep and ensure consistent spacing between columns.
        # cut -d ' ' -f 5: This command extracts the fifth field (column) from each line of input, using a space ' ' as the delimiter (-d). 
        # In the context of ls -l, the fifth field represents the file size.
        # sort -n: This command sorts the extracted file sizes (-n for numerical sort) in ascending order.
        # tail -1: This command selects the last line of input, which corresponds to the largest file size when the file sizes are sorted numerically.
    else
        echo "Not a directory"
    fi
done


# 3b 3c 3d covered in lab
# programs are different than manual 
