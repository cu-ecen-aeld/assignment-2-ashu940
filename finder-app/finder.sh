#!/bin/bash

# Check if both arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Error: incorrect arguments."
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

filesdir=$1
searchstr=$2

# Clean previous build artifacts (removes old writer binary and object files)
make clean

# Compile the writer application using native compilation
make

# Check if the writer application was built successfully
if [ ! -f "./writer" ]; then
    echo "Error: writer application failed to build."
    exit 1
fi

# Check if the given path is a directory
if [ ! -d "$filesdir" ]; then
    echo "Error: '$filesdir' is not a directory."
    exit 1
fi

# Find the number of files in the directory and subdirectories
num_files=$(find "$filesdir" -type f | wc -l)

# Count the number of lines containing the search string
num_matching_lines=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# Use the writer utility to log the output
./writer /tmp/result.log "The number of files are $num_files and the number of matching lines are $num_matching_lines."

# Print the results to the console
echo "The number of files are $num_files and the number of matching lines are $num_matching_lines."
