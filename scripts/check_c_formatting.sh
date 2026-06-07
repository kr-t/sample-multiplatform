#!/bin/sh

set -e

ARGUMENT="--dry-run"

case "${1:-}" in
    -f)
        echo "Fixing files in place if necessary"
        ARGUMENT="-i"
        ;;
    "")
        ;;
    *)
        echo "Invalid option: $1"
        exit 1
        ;;
esac

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

echo "Checking C formatting."

find "$ROOT_DIR" -type f \( -name '*.c' -o -name '*.h' \) \
    \( -path '*/src/*' -o -path '*/tests/*' \) \
    ! -path '*/build/*' \
    ! -path '*/Unity/*' \
    -exec clang-format "$ARGUMENT" -Werror {} +
