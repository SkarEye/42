#!/bin/sh
# ============================================================================
# benchmark.sh — measure PmergeMe timing across a range of container sizes.
#
# Drives ./pmergeme (built from test.cpp, which accepts: ./pmergeme SEED COUNT)
# and parses the two "Time to process ..." lines it prints, writing the result
# to a CSV file with columns:  size,vector_us,list_us
#
# Usage:
#   ./benchmark.sh [MAX] [STEP] [SEED] [OUTPUT] [REPEATS]
#
#   MAX     largest container size to test       (default 3000)
#   STEP    increment between sizes              (default 1   up to 100,
#                                                 then auto-coarsens)
#   SEED    base RNG seed passed to the harness  (default 42)
#   OUTPUT  CSV file to write                    (default benchmark.csv)
#   REPEATS runs per size, averaged              (default 5)
#
# Each size is run REPEATS times with seeds SEED, SEED+1, ... so the inputs
# differ between runs; the reported vector_us / list_us are the means.
#
# Examples:
#   ./benchmark.sh                       # 1..3000, auto step, seed 42, 5 reps
#   ./benchmark.sh 10000 50              # 1..10000 in steps of 50
#   ./benchmark.sh 5000 1 7 out.csv 10   # 10 runs averaged per size
# ============================================================================

set -eu

BIN=./pmergeme
MAX=${1:-3000}
STEP=${2:-0}          # 0 means "auto" (fine near the start, coarse later)
SEED=${3:-42}
OUTPUT=${4:-benchmark.csv}
REPEATS=${5:-5}

if [ "$REPEATS" -lt 1 ]; then
	echo "Error: REPEATS must be >= 1." >&2
	exit 1
fi

if [ ! -x "$BIN" ]; then
	echo "Error: $BIN not found or not executable. Run 'make' first." >&2
	exit 1
fi

# Sanity-check that the binary is the test harness (SEED COUNT interface).
if ! "$BIN" "$SEED" 2 >/dev/null 2>&1; then
	echo "Error: $BIN did not accept the 'SEED COUNT' interface." >&2
	echo "       Make sure the Makefile builds test.cpp, then 'make re'." >&2
	exit 1
fi

# CSV header.
printf 'size,vector_us,list_us\n' > "$OUTPUT"

# Pick the next size given the current one (auto-coarsening when STEP == 0).
next_size() {
	cur=$1
	if [ "$STEP" -ne 0 ]; then
		echo $((cur + STEP))
		return
	fi
	# Auto schedule: dense early, sparse later.
	if   [ "$cur" -lt 100 ];   then echo $((cur + 1))
	elif [ "$cur" -lt 1000 ];  then echo $((cur + 10))
	elif [ "$cur" -lt 10000 ]; then echo $((cur + 100))
	else                            echo $((cur + 1000))
	fi
}

echo "Benchmarking $BIN: sizes 1..$MAX (seed $SEED, $REPEATS run(s)/size) -> $OUTPUT"

size=1
while [ "$size" -le "$MAX" ]; do
	vec_sum=0
	lst_sum=0
	got=0
	rep=0
	while [ "$rep" -lt "$REPEATS" ]; do
		run_seed=$((SEED + rep))
		out=$("$BIN" "$run_seed" "$size" 2>/dev/null) || {
			rep=$((rep + 1))
			continue
		}

		vec_us=$(printf '%s\n' "$out" | awk '/with std::vector/ { print $(NF-1) }')
		lst_us=$(printf '%s\n' "$out" | awk '/with std::list/   { print $(NF-1) }')

		if [ -n "$vec_us" ] && [ -n "$lst_us" ]; then
			# Accumulate with awk to tolerate fractional microseconds.
			vec_sum=$(awk -v a="$vec_sum" -v b="$vec_us" 'BEGIN { printf "%.5f", a + b }')
			lst_sum=$(awk -v a="$lst_sum" -v b="$lst_us" 'BEGIN { printf "%.5f", a + b }')
			got=$((got + 1))
		fi
		rep=$((rep + 1))
	done

	if [ "$got" -gt 0 ]; then
		vec_avg=$(awk -v s="$vec_sum" -v n="$got" 'BEGIN { printf "%.5f", s / n }')
		lst_avg=$(awk -v s="$lst_sum" -v n="$got" 'BEGIN { printf "%.5f", s / n }')
	else
		vec_avg=NA
		lst_avg=NA
	fi

	printf '%s,%s,%s\n' "$size" "$vec_avg" "$lst_avg" >> "$OUTPUT"

	# Light progress indicator.
	if [ $((size % 100)) -eq 0 ] || [ "$size" -lt 10 ]; then
		printf '  size=%-7s vector=%-10s list=%-10s\n' "$size" "$vec_avg" "$lst_avg"
	fi

	size=$(next_size "$size")
done

echo "Done. Wrote $(($(wc -l < "$OUTPUT") - 1)) rows to $OUTPUT"
