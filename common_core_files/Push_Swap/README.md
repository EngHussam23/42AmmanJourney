_This project has been created as part of the 42 curriculum by alragga_

# Push_swap

A sorting algorithm project that sorts data on a stack using a limited set of operations, with the smallest number of actions possible.

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum that challenges you to sort integers on a stack with the minimum number of operations. The program uses two stacks (`a` and `b`) and a specific set of instructions to manipulate them.

### Algorithm Used
- **Radix Sort** for sets of 6+ numbers (binary bit manipulation)
- **Optimized hardcoded solutions** for 2-5 numbers
- **Early exit** for already sorted stacks

### Available Operations
- `sa` - swap first 2 elements of stack a
- `sb` - swap first 2 elements of stack b  
- `ss` - sa and sb at the same time
- `pa` - push top element from b to a
- `pb` - push top element from a to b
- `ra` - rotate stack a (shift up all elements)
- `rb` - rotate stack b
- `rr` - ra and rb at the same time
- `rra` - reverse rotate a (shift down all elements)
- `rrb` - reverse rotate b
- `rrr` - rra and rrb at the same time

## Performance

| Elements | Operations | Target    | Status |
|----------|-----------|-----------|--------|
| 3        | ≤ 2       | ≤ 3       | ✅     |
| 5        | ≤ 9       | ≤ 12      | ✅     |
| 100      | ~1084     | ≤ 700     | ⚠️     |
| 500      | ~6784     | ≤ 5500    | ⚠️     |

## Compilation

```bash
make        # Compile push_swap
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## Usage

```bash
# Basic usage
./push_swap 2 1 3 6 5 8
./push_swap "4 67 3 87 23"

# Test with checker_linux (provided by 42)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Run comprehensive test suite
./test.sh
```

## Error Handling

The program outputs "Error" (to stderr) and exits with status 1 when:
- Arguments are not integers
- Any number exceeds INT_MAX or INT_MIN
- Duplicate numbers are found
- Invalid characters in input

## Project Structure

```
.
├── push_swap.h           # Header file with prototypes and structures
├── Makefile             # Compilation rules
├── c_files/
│   ├── main.c           # Entry point and sorting dispatcher
│   ├── input_validation.c
│   ├── parsing_1.c      # Argument parsing with ft_split
│   ├── parsing_2.c      # Number conversion and stack creation
│   ├── error_handling.c
│   ├── stack_ops_1.c    # Stack operations (sa, pa, pb, ra, rra)
│   ├── indexing.c       # Index assignment for radix sort
│   ├── radix_sort.c     # Main sorting algorithm
│   ├── small_sort.c     # Optimized sorting for 2-5 numbers
│   └── little_helpers_1.c
├── Libft/               # Personal C library
├── test.sh              # Comprehensive test suite with valgrind
└── checker_linux        # Validation tool (provided by 42)
```

## Testing

The project includes a comprehensive test suite ([test.sh](test.sh)) that validates:
- ✅ Edge cases (empty input, already sorted, single numbers)
- ✅ Error handling (duplicates, overflow, invalid characters)
- ✅ Basic sorting (2-5 numbers)
- ✅ Medium sets (10, 25, 50 numbers)
- ✅ Large sets (100, 500 numbers)
- ✅ Special patterns (descending, almost sorted, rotated)
- ✅ Memory leak detection with valgrind

Run tests:
```bash
./test.sh                 # Run all tests
./test.sh > results.txt   # Save results to file
```

## Memory Management

✅ **Zero memory leaks** - Verified with valgrind across all test cases
- Proper cleanup of stack nodes
- Correct handling of ft_split allocated arrays
- All edge cases tested for memory safety

## Resources

- [Push_swap Subject PDF](push_swap.subject.pdf)
- [42 Norm Documentation](en.norm.pdf)
- Algorithm visualization: [push-swap-visualizer](https://github.com/o-reo/push_swap_visualizer)

## Author

**halragga** - 42 Amman  
Project completed: January 2026