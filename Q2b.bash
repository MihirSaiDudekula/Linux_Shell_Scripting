# Develop a shell script that accepts above created filename as argument
# &amp; display its creation time and permissions of the file, on the standard
# output

#! /bin/bash
if [ $# -eq 0 ]
then
echo "display does not exit":
else
ls -l $1> t1
x=`cut -d ' ' -f 1,6,7,8,9 t1`
echo $x
fi


# 1. #!/bin/bash:
# This line specifies the interpreter to be used for this script. It indicates that this is a bash script and should be run by the bash shell.

# **2. if [ <span class="math-inline">\# \-eq 0 \]\:**
# This line checks if the number of arguments passed to the script (`#) is equal to zero (-eq 0`).

#     $#: This is a positional parameter that holds the number of arguments passed to the script.

# 3. then:
# This introduces the block of code that will be executed if the condition in the if statement is true (in this case, if no arguments were passed).

# 4. echo "display does not exit":
# This line prints the message "display does not exit" to the console.

# 5. else:
# This introduces the block of code that will be executed if the condition in the if statement is false (in this case, if one or more arguments were passed).

# 6. ls -l $1> t1:
# This line lists the contents of the file specified by the first argument ($1) in long format (-l) and redirects the output to a file named t1.

# 7. x=cut -d ' ' -f 1,6,7,8,9 t1``:
# This line assigns the output of the cut command to the variable x.

#     cut -d ' ' -f 1,6,7,8,9 t1: This command extracts specific columns from the file t1.
#         -d ' ': This specifies that the delimiter for separating columns is a space (" ").
#         -f 1,6,7,8,9: This selects the first, sixth, seventh, eighth, and ninth columns of each line in the file.

# **8. echo <span class="math-inline">x\:**
# This line prints the value of the variable `x` to the console.
# **Summary:**
# This script checks if any arguments were passed. If not, it prints an error message. If arguments are provided, it lists the contents of the first argument file in long format, extracts specific columns from the output, and finally prints the extracted columns.
# **Additional notes:**
# * The use of backticks to capture the output of the `cut` command is considered obsolete in modern bash scripting. You can achieve the same result using command substitution with parentheses: `x=(cut -d ' ' -f 1,6,7,8,9 t1)`.

#     The spacing around the comma in the -f 1,6,7,8,9 option of the cut command might be unintentional. It's generally recommended to avoid spaces around commas in arguments passed to commands.


