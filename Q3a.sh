# Develop a shell script that takes a valid directory name as an argument
# and recursively descend all the sub-directories, finds the maximum
# length of any file in that hierarchy, and store the output in a file.

#! /bin/bash
for i in $*
do
if [ -d $i ]
then
        echo "large filename size is&quot"

        echo `ls -lR $1 | grep "^-" | tr -s ' ' | cut -d ' ' -f 5 | sort -n | tail -1`
else
echo "not directory"
fi
done

# 3b 3c 3d covered in lab
# programs are different than manual 