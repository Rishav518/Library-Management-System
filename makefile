#     makefile
#     Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
#     Created: 08/01/24
#     Updated: 08/01/24

# Define compiler
CC=g++

# Define flags
CFLAGS=-Wall

#Final executable name
OUTPUT=library-management-system

# Source files
SOURCES=main.cpp member.cpp person.cpp librarian.cpp books.cpp

# Define your object files
OBJECTS=$(SOURCES:.cpp=.o)

# Default target
all: $(OUTPUT)

# Linking the final executable
$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)

# Compiling source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Clean target for cleaning up
clean:
	del /F /Q $(subst /,\,$(OUTPUT)) $(subst /,\,$(OBJECTS))

# Phony targets
.PHONY: all clean
