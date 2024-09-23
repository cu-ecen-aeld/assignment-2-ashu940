#!/bin/sh

num=2

if [ "$#" -ne $num ]
then
	echo "incorrect arguments."
	echo "usage: $0 <writefile> <writestr>"
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]
then
	echo "Error: Could not create file '$writefile'."
	exit 1
fi

echo "File '$writefile' created successfully,"
