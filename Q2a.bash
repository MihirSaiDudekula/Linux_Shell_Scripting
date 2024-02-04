# Consider the below scenarios and execute the given shell scripts.
# “Ramaiah College is having 10 departments (Say, CS, IS, AI, ML, Cyber
# Security, EC, Mechanical, EEE, DS, Civil) with UG and PG programs, and in
# each of the program student details, course details are maintained in 10
# different files (such as Student Details, Course details, Curriculum, Exam,
# Marks, Research Activity, NBA, Placement Activities, Library Details, Extra
# Activities….).”
# a. Develop a shell script for the above scenario to create 10 levels of folders for
# the departments and inside each level(department) of folder, create 10 files in
# each department for maintaining student details. Display the entire hierarchy on
# the standard output by using tree command.
# b. Develop a shell script that accepts above created filename as argument and
# display its creation time and permissions of the file, on the standard output.

# echo - displaying lines of text or string which are passed as arguments on the command line
# while [ $i -le 10 ] - while the variable i is lesser than equal to 10

#!/bin/bash

echo "10 levels of folders are created for the departments and 10 levels of files created for student details"

i=1
while [ $i -le 10 ]; do
    mkdir "MSRITDept$i"
    cd "MSRITDept$i" || exit 1
    j=1
    while [ $j -le 20 ]; do
        touch "MSRITStudentDetails$j"
        ((j++))
    done
    cd ..
    ((i++))
done

