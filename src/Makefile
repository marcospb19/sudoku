# Final program name
PROGRAM = sudoku

# Default target and pseudo-targets
.DEFAULT_GOAL = $(PROGRAM)
.PHONY = clean
.PHONY = install

# Compiler, Compilation flags, link flags
CC = clang # gcc, tcc
CFLAGS = -O2 -Wall -Wextra -std=c11
LDFLAGS = -lm

# Object files to be built
OBJECTS = sudoku.o game.o solve.o


### Main targets
$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(PROGRAM) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
###



### Pseudo-targets
clean:
	@rm $(OBJECTS) 2> /dev/null || exit 0

install: $(PROGRAM)
	@sudo cp $(PROGRAM) /usr/bin/    && \
		echo "$(PROGRAM) Installed, Thank you!" ||  \
		echo "Some error occured."
###
