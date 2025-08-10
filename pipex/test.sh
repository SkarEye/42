#!/bin/bash

# Script to test pipex for various edge cases and leaks

PIPEX=./pipex
INPUT_FILE=infile
OUTPUT_FILE=outfile
TMP_OUT=tmp_outfile

# Prepare test files
echo "Hello World" > $INPUT_FILE

# Test cases
declare -a tests=(
    "$INPUT_FILE \"cat\" \"wc -l\" $OUTPUT_FILE"
    "$INPUT_FILE \"grep Hello\" \"wc -c\" $OUTPUT_FILE"
    "$INPUT_FILE \"grep XYZ\" \"wc -l\" $OUTPUT_FILE" # No match
    "$INPUT_FILE \"cat\" \"cat\" $OUTPUT_FILE"
    "nofile \"cat\" \"wc -l\" $OUTPUT_FILE"            # Missing infile
    "$INPUT_FILE \"nonexistentcmd\" \"wc -l\" $OUTPUT_FILE" # Invalid cmd1
    "$INPUT_FILE \"cat\" \"nonexistentcmd\" $OUTPUT_FILE"   # Invalid cmd2
    "$INPUT_FILE \"cat\" \"grep World | wc -l\" $OUTPUT_FILE" # Piped cmd inside cmd (should fail)
)

echo "=== PIPEX TESTS START ==="
for test in "${tests[@]}"; do
    echo -e "\n> Testing: $PIPEX $test"
    # Run with valgrind for leaks & errors
    valgrind --quiet --leak-check=full --show-leak-kinds=all \
        --track-fds=yes --error-exitcode=42 \
        $PIPEX $test > $TMP_OUT 2> valgrind.log

    if [ $? -eq 42 ]; then
        echo "  [VALGRIND ERROR] Memory or FD leak detected."
        cat valgrind.log
    else
        echo "  [OK] No Valgrind leaks/errors."
    fi

    # Compare with bash equivalent
    infile=$(echo "$test" | awk '{print $1}')
    cmd1=$(echo "$test" | awk '{print $2}')
    cmd2=$(echo "$test" | awk '{print $3}')
    outfile=$(echo "$test" | awk '{print $4}')

    bash_out=$(bash -c "$cmd1 < $infile | $cmd2" 2>/dev/null)
    pipex_out=$(cat $TMP_OUT 2>/dev/null)

    if [ "$bash_out" != "$pipex_out" ]; then
        echo "  [OUTPUT MISMATCH] Your output doesn't match bash's."
    else
        echo "  [OUTPUT MATCH]"
    fi
done

rm -f $TMP_OUT valgrind.log
echo "=== PIPEX TESTS END ==="
