CFLAGS = -Wall -Wextra -Werror

all: rush-02
	@echo "Preparing for run..."
	@echo "3"
	@echo "2"
	@echo "1"
	@echo "Tadaaaaa!!!\n"

rush-02: main.o ft_malloc.o ft_free.o input_processing.o
	@echo "Linking excutable files..."
	@cc $(CFLAGS) main.o ft_malloc.o ft_free.o rush02.o -o rush-02
	@chmod +x rush-02
	@echo "Linked successfully!\n"

main.o: main.c
	@echo "\nCreating main.o..."
	@cc $(CFLAGS) -c main.c
	@echo "main.o ready.\n"

ft_malloc.o: ft_malloc.c
	@echo "Creating ft_malloc.o..."
	@cc $(CFLAGS) -c ft_malloc.c
	@echo "ft_malloc.o ready.\n"

ft_free.o: ft_free.c
	@echo "Creating ft_free.o..."
	@cc $(CFLAGS) -c ft_free.c
	@echo "ft_free.o ready.\n"

input_processing.o: rush02.c
	@echo "Creating input_processing.c..."
	@cc $(CFLAGS) -c rush02.c
	@echo "input_processing.o ready.\n"

fclean:
	@echo "Removing all excutable and object files..."
	@rm main.o ft_malloc.o ft_free.o rush02.o rush-02
	@echo "Directory is clean!"
