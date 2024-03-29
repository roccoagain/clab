#!/bin/zsh

echo "Building..."

find . -type f -name '*.c' -exec sh -c '
    for c_file; do
        dir=$(dirname "$c_file")
        base_name=$(basename "$c_file" .c)
        cd "$dir"
        gcc -Os -o "$base_name" "$base_name".c
        cd - >/dev/null
    done
' sh {} +

echo "Done"
