#!/bin/zsh

find . -type f -name '*.c' -exec sh -c '
    for c_file; do
        dir=$(dirname "$c_file")
        base_name=$(basename "$c_file" .c)
        cd "$dir"
        gcc -o "$base_name" "$base_name".c
        cd -
    done
' sh {} +
