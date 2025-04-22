echo "SRC = \\"
find src_libc/ -type f -name "*.c" | sort | sed 's/^/	/' | sed 's/$/ \\/'