*This project has been created as part of the 42 curriculum by halragga*

## Description

**Fract-ol** is a graphical project that explores the beauty of fractals through interactive visualization. The program renders various types of fractals using the MiniLibX graphics library and allows users to explore them in real-time with zoom, pan, and color manipulation features.

The main goal of this project is to create a fractal explorer that demonstrates mathematical concepts like complex numbers, iterative functions, and infinite patterns. Users can interact with Mandelbrot, Julia, and Phoenix fractals, discovering the intricate beauty hidden within mathematical formulas.

### Features

- **Multiple Fractals**: Supports Mandelbrot, Julia (with customizable parameters), and Phoenix (bonus) fractals
- **Interactive Controls**: Zoom in/out using mouse scroll, pan with arrow keys
- **Dynamic Colors**: Shift color schemes on the fly with the 'C' key
- **Smooth Rendering**: Real-time fractal generation with adjustable iteration limits
- **Julia Mode** (bonus): For Julia sets, move your mouse to see how different complex parameters affect the fractal
- **Reset View**(bonus): Press 'R' to reset to the initial view

## Instructions

### Prerequisites

- Linux operating system (uses X11)
- GCC compiler
- Make
- MiniLibX library (included in `minilibx-linux/`)
- X11 development libraries

### Compilation

To compile the project, simply run:

	make

This will create the `fractol` executable.

### Usage

**Mandelbrot Set:**

	./fractol mandelbrot

**Julia Set:**

	./fractol julia

Or with custom parameters:

	./fractol julia <real> <imaginary>

Example:

	./fractol julia -0.7 0.27015

**Phoenix Fractal (Bonus):**

	./fractol phoenix

### Controls

- **Mouse Scroll Up/Down**: Zoom in/out
- **Arrow Keys**: Pan the view (left, right, up, down)
- **C**: Cycle through different color schemes
- **R**: Reset view to default
- **ESC**: Close the window and exit
- **Mouse Movement** (Julia only): Dynamically change the Julia set parameters

### Cleaning

	make clean      # Remove object files
	make fclean     # Remove object files and executable
	make re         # Rebuild everything from scratch

## Resources

### Classic References

- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Phoenix Set](https://mathworld.wolfram.com/PhoenixSet.html)
- [Complex Numbers Explained](https://www.mathsisfun.com/numbers/complex-numbers.html)
- [Fractal Geometry - Benoit Mandelbrot](https://en.wikipedia.org/wiki/The_Fractal_Geometry_of_Nature)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X11 Programming Manual](https://tronche.com/gui/x/xlib/)

### AI Usage

AI assistance was used in the following ways during the development of this project:

- **Documentation**: AI helped research mathematical formulas for fractal generation and clarify complex number operations
- **Debugging**: Used to troubleshoot memory leaks and X11 event handling issues
- **Color Algorithms**: Helped explore different color mapping techniques to create visually appealing palettes
- **Makefile Structure**: Assisted in setting up proper compilation flags and library linking for MiniLibX

All core algorithmic implementations, fractal calculations, and architectural decisions were made independently. AI served primarily as a research assistant and debugging tool rather than a code generator.
