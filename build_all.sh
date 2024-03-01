#!/bin/zsh

find . -type f -name '*.c' -exec sh -c '
    for c_file; do
        # Get the directory of the .c file
        dir=$(dirname "$c_file")
        
        # Get the base name of the file without the .c extension
        base_name=$(basename "$c_file" .c)
        
        # Change to the directory where the .c file is located
        cd "$dir"
        
        # Compile the .c file to an executable with the same name
        gcc -o "$base_name" "$base_name".c
        
        # Change back to the original directory
        cd -
    done
' sh {} +
