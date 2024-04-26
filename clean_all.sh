#!/bin/bash

echo "Starting cleanup process..."

# Remove .DS_Store files
find ./ -name '.DS_Store' -type f -delete

# Remove a.out files
find ./ -name 'a.out' -type f -delete

# Remove executable files without extensions
find . -type f ! -name "*.*" -perm +111 -exec sh -c '
    for file do
        if [ -x "$file" ]; then
            rm "$file"
        fi
    done
' sh {} +

# Call 'make clean' if a Makefile exists in the directory
for dir in $(find . -name Makefile -exec dirname {} \;); do
    echo "Calling 'make clean' in $dir..."
    (cd "$dir" && make clean)
done

echo "Cleanup complete."
