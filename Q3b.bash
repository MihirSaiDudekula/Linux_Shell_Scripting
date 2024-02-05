# 3b.Create a shell script to find a file with particular name, (show separate outputs for both the conditions)
#     (i) if that file exists then rename the existing file and create an empty file with that name.
#     (ii) if that file does not exist then create a new empty file. (iii)If both the conditions done together.

#!/bin/bash

# Set the desired file name
# the placeholder can be changed
file_name="example.txt"

# Check if the file exists
if [ -e "$file_name" ]; then
    # If the file exists, rename it and create an empty file with the original name
    echo "File '$file_name' exists."

    # Rename the existing file
    mv "$file_name" "${file_name}_old"
    echo "Existing file renamed to '${file_name}_old'."

    # Create an empty file with the original name
    touch "$file_name"
    echo "New empty file created with the name '$file_name'."

    echo "Both conditions done together."
else
    # If the file does not exist, create a new empty file
    touch "$file_name"
    echo "File '$file_name' does not exist. New empty file created."
fi
