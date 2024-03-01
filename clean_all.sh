#!/bin/zsh

find ./ -name '.DS_Store' -type f -delete
find ./ -name 'a.out' -type f -delete

find . -type f ! -name "*.*" -perm +111 -exec sh -c '
    for file do
        # Check if the file is an executable
        if [ -x "$file" ]; then
            # Delete the file
            echo "Deleting executable: $file"
            rm "$file"
        fi
    done
' sh {} +
