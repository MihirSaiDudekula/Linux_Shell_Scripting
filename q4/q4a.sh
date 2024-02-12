#!/bin/bash

# Get system space usage in percentage
system_space=$(df -h / | awk 'NR==2 { print $5 }')

# Check if system space usage is greater than 80%
if [[ "${system_space%\%}" -gt 80 ]]; then
    echo "Low system space: ${system_space}"

    # List files having size greater than 1GB
    echo "Files larger than 1GB:"
    find / -type f -size +1G -exec ls -lh {} \; 2>/dev/null
else
    echo "System space usage: ${system_space}"
fi

