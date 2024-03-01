#!/bin/zsh

find ./ -name '.DS_Store' -type f -delete
find ./ -name 'a.out' -type f -delete

find . -type f ! -name "*.*" -perm +111 -exec sh -c '
    for file do
        if [ -x "$file" ]; then
            echo "Deleting executable: $file"
            rm "$file"
        fi
    done
' sh {} +
