#!/bin/bash

echo "Building..."

# Track directories that have been processed to avoid redundancy
processed=""

# Find all directories containing .c files, not just individual files
find . -type f -name '*.c' | while read c_file; do
    dir=$(dirname "$c_file")
    # Check if the directory has been processed
    if [[ ! $processed =~ $dir ]]; then
        processed="$processed|$dir"
        if [ -f "$dir/Makefile" ]; then
            # A Makefile exists, so use 'make'
            echo "Using Makefile in $dir"
            (cd "$dir" && make)
        else
            # No Makefile, compile all .c files in this directory manually
            echo "Manually compiling in $dir"
            for file in "$dir"/*.c; do
                base_name=$(basename "$file" .c)
                gcc -Os -o "$dir/$base_name" "$file"
            done
        fi
    fi
done

echo "Done"
