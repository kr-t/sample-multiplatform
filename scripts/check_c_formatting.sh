#!/bin/sh

set -e

ARGUMENT="--dry-run"

if [ $# -eq 1 ]; then
    if [ "$1" = "-f" ]; then
        echo "Fixing files in place if necessary"
        ARGUMENT="-i"
    else
        echo "Invalid option: $1"
        exit 1
    fi
fi

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
SRC_DIR="$ROOT_DIR/src"

echo "Checking C formatting."

find . -type f '(' -name '*.c' -o -name '*.h' ')' \
    '(' -path './src/*' -o -path './tests/*' ')' \
    ! -path '*/build/*' \
    -print0 | \
    xargs -0 -n1 clang-format ${ARGUMENT} -Werror
