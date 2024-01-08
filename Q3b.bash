# Create a shell script to find a file with particular name, (show separate outputs for both the conditions)

#     • if that file exists then rename the existing file and create an empty file with that name.
#     • if that file does not exist then create a new empty file.
#     • If both the conditions done together.

# Create a file named rit.txt with below contents

# Hi
# Hello
# Welcome to MSRIT

#! /bin/bash
cd /home/ritadmin/sample
filename="rit.txt"
if [ -e $filename ]
then
echo "moving the contents of rit.txt to rit.txt_old"
mv -f  $filename $filename"_old"
touch $filename
fi


