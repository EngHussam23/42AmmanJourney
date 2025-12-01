# 42 Amman Journey - AI Coding Agent Instructions

## Project Context

This is a 42 School programming journey repository containing Piscine exercises and Common Core projects. All code must comply with **42 Norminette** standards and project-specific constraints.

## Critical 42 Norminette Requirements

### File Structure (Every .c and .h file)

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: YYYY/MM/DD HH:MM:SS by halragga          #+#    #+#             */
/*   Updated: YYYY/MM/DD HH:MM:SS by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

### Code Standards

- **Max 25 lines per function** (excluding brackets and empty lines)
- **Max 80 characters per line**
- **Max 5 functions per file**
- Header guards: `#ifndef FILENAME_H` format (uppercase, underscores for dots)
- No global variables (except static for specific cases like `get_next_line`)
- Tab indentation (not spaces)
- No multiple statements on one line
- Declarations at start of function block
- One blank line between functions

### Naming Conventions

- Functions: `snake_case` with `ft_` prefix for libft functions
- Variables: `snake_case`
- Macros/defines: `UPPER_SNAKE_CASE`
- No reserved keywords or single-letter names (except loop counters)

## Project Architecture

### Common Core Projects Structure

```
Common_Core_Files/
├── Libft/          # Core library with ft_* functions + printf + get_next_line
├── Printf/         # Formatted output project
├── Get_Next_Line/  # File reading with static buffers
├── So_Long/        # MiniLibX game project (current focus)
├── Fract_Ol/       # Fractal renderer with MiniLibX
└── Push_Swap/      # Stack sorting algorithm
```

### Libft Integration Pattern

Each graphical project (So_Long, Fract_Ol) maintains its own `Libft/` subdirectory with a compiled `libft.a`. The libft includes:

- Standard C library recreations (`ft_strlen`, `ft_memcpy`, etc.)
- `ft_printf` and related printing functions
- `get_next_line` for file reading
- Custom utility functions

**When editing projects**: If you add/modify libft functions, update BOTH the project's local `Libft/` AND the main `Common_Core_Files/Libft/`.

### Printf (Formatted Output)

**Allowed Functions:**

- `malloc`, `free`, `write`
- `va_start`, `va_arg`, `va_copy`, `va_end` (variadic functions)

**Required Format Specifiers:**

- `%c` - character
- `%s` - string
- `%p` - pointer address (hexadecimal)
- `%d` / `%i` - signed decimal integer
- `%u` - unsigned decimal integer
- `%x` / `%X` - hexadecimal (lowercase/uppercase)
- `%%` - literal percent sign

## Build System Patterns

### Standard Makefile Structure

```makefile
NAME = program_name
CC = cc
CFLAGS = -Wall -Wextra -Werror
# For MiniLibX projects add:
MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz

SRC = file1.c file2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Compilation Commands

```bash
# Standard compilation with 42 flags
cc -Wall -Wextra -Werror file.c

# With debugging symbols
cc -g -Wall -Wextra -Werror file.c

# Creating static library
ar rcs libft.a *.o

# MiniLibX projects (So_Long, Fract_Ol)
cc -Wall -Wextra -Werror file.c -lmlx -lXext -lX11 -lm -lz
```

## Project-Specific Patterns

### Get_Next_Line (File Reading with Static Buffers)

- Uses **static variables** to maintain state between calls
- `BUFFER_SIZE` must be definable at compile time: `cc -D BUFFER_SIZE=42`
- Default `BUFFER_SIZE` defined in header as fallback (typically 4)
- Handles multiple file descriptors independently
- Returns one line at a time from file descriptor

**Allowed Functions:**

- `read`, `malloc`, `free`
- Must implement your own helper functions (no external libs)

**Key Implementation:**

- Static variable persists leftover data between function calls
- Read in chunks of `BUFFER_SIZE` bytes
- Extract lines up to `\n` character
- See: `Common_Core_Files/Get_Next_Line/get_next_line.c`

### So_Long (2D Game Project)

**Game Requirements:**

- Map file with `.ber` extension as argument
- Player collects all collectibles (`C`) before reaching exit (`E`)
- Movement: W/A/S/D keys (or arrow keys/ZQSD)
- Display movement count in shell at each move
- Cannot move through walls (`1`)

**Map Validation Rules:**

- Rectangular shape, enclosed by walls (`1`)
- Must contain: exactly 1 exit (`E`), 1 start position (`P`), at least 1 collectible (`C`)
- Valid characters: `0` (empty), `1` (wall), `C` (collectible), `E` (exit), `P` (player)
- Must have a valid path from start to all collectibles and exit
- Error handling: Print `"Error\n"` + explicit message for invalid maps

**Window Management:**

- ESC key closes window cleanly
- Window close button (X) exits cleanly
- Smooth window switching/minimizing

**Allowed Functions:**

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All math library functions (`-lm` flag)
- All MiniLibX functions
- `ft_printf` or equivalent you coded
- `gettimeofday()`

**Bonus Features (optional):**

- Enemy patrols (lose on touch)
- Sprite animations
- On-screen movement counter

### Fract_Ol (Fractal Renderer)

- Source files in `C/` subdirectory, objects in `Objects/`
- Link with: `-lmlx -lXext -lX11 -lm -lz`
- Common file structure:
  - `init.c`: MLX initialization and setup
  - `render.c`: Drawing and rendering logic
  - `events.c`: Keyboard/mouse event handlers
  - `utils.c`: Helper functions
  - `colors.c`: Color manipulation

### Makefile Object Directory Pattern

```makefile
OBJ_DIR = Objects
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
```

## Development Workflow

### Testing & Debugging

```bash
# Check norminette compliance (from project root)
norminette *.c *.h

# Or use the automated script
bash Bash_Scripting/norm_fix.sh

# Debug with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./program

# GDB debugging workflow
cc -g -Wall -Wextra -Werror main.c -o program
gdb ./program
# Inside gdb: run → bt → list → break function_name → n → print var
```

### Project Testing with Paco

42 students commonly use "paco" testers for project validation. Search GitHub for project-specific paco testers:

- Example: `paco_so_long` for So_Long project
- These testers validate map parsing, game logic, memory leaks, and edge cases
- Always verify tester results manually and understand why tests pass/fail

### Git Workflow

Helper scripts in `Bash_Scripting/`:

- `git_config.sh`: Configure git credentials
- `git_push.sh`: Automated commit and push
- `setup_github_ssh.sh`: SSH key setup for GitHub

## Common Pitfalls

1. **Norminette violations**: Always run `norminette` before committing
2. **Function length**: Break down functions exceeding 25 lines
3. **Memory leaks**: Use `valgrind` on every program - no leaks tolerated
4. **Static variables**: Only allowed where explicitly stated (e.g., get_next_line)
5. **Forbidden functions**: Each project has specific allowed functions - check the PDF subject
6. **Makefile rules**: Must not relink unnecessarily; use proper dependencies
7. **So_Long map validation**: Must check all error cases (invalid paths, missing elements, non-rectangular)
8. **Window management**: Must handle ESC key and window close button cleanly
9. **File descriptors**: Always close opened files to prevent leaks

## When Creating New Files

1. Add the 42 header comment block (see template above)
2. For `.h` files: Use uppercase header guards with filename
3. Update the corresponding `Makefile` to include new source files
4. Run `norminette` to verify compliance
5. For project-specific libft functions, update both local and main Libft

## Testing Resources

- **Paco testers**: Search GitHub for "paco\_[project_name]" (e.g., `paco_so_long`, `paco_libft`)
- Project-specific testers from 42 GitHub community (Francinette, etc.)
- `Common_Core_Files/Get_Next_Line/testing.txt`: Sample input files
- `Bash_Scripting/born_2_be_root_test.sh`: Born2BeRoot validation script
- Map files for So_Long: Create various `.ber` files to test edge cases (invalid paths, missing components, non-rectangular shapes)

## Documentation

- Subject PDFs in each project directory (e.g., `So_Long.en.subject.pdf`)
- Main norminette rules: `en.norm.pdf` in root
- Additional guides: `Bash_Scripting/Toolkit_Guide.pdf`
- Command reference: `Common_Core_Files/README.md`
