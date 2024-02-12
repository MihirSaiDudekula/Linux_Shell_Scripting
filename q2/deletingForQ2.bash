echo “ delete 10 levels of folders of student details”
i=1
while [ $i -le 10 ]
do
cd MSRITDept$i
j=1
while [ $j -le 20 ]
do
rm MSRITStudentDetails$j
j=$(($j+1))
done
cd ..
rmdir MSRITDept$i
i=$(($i+1))
done
