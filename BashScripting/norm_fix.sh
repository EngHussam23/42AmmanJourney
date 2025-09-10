#!/bin/bash
# 42 Norminette auto-check and basic fix script

# Check if norminette is installed
if ! command -v norminette &> /dev/null; then
    echo "Error: norminette is not installed. Install it with: pipx install norminette"
    exit 1
fi

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null; then
    echo "Warning: clang-format is not installed. Auto-formatting will be skipped."
    autoformat=false
else
    autoformat=true
fi

# Find all .c and .h files
files=$(find .. -type f \( -name "*.c" -o -name "*.h" \))

# Run norminette and save output
echo "Running norminette on all C and header files..."
norminette $files > norminette_report.txt
cat norminette_report.txt

# Attempt auto-formatting
if [ "$autoformat" = true ]; then
    echo "\nAuto-formatting with clang-format..."
    for f in $files; do
        clang-format -i "$f"
    done
    echo "Auto-formatting done. Re-running norminette:"
    norminette $files > norminette_report_after_format.txt
    cat norminette_report_after_format.txt
else
    echo "\nSkipping auto-formatting."
fi

echo "\nReview the above norminette output for remaining errors. Some issues (function length, naming, file structure) must be fixed manually."
