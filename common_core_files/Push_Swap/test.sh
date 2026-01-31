#!/bin/bash

echo "=== 3 numbers ==="
./push_swap 2 1 0 | wc -l

echo "=== 5 numbers ==="
./push_swap 5 4 3 2 1 | wc -l

echo "=== 100 numbers ==="
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "=== 500 numbers ==="
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
OPS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPS (should be < 5500)"
./push_swap $ARG | ./checker_linux $ARG