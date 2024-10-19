# Compilador y flags
CC := gcc
# # Compilador cruzado para Windows 64 bits
# CC := x86_64-w64-mingw32-gcc
CFLAGS := -Wall -Wextra -O2 -Iinclude

# Directorios
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin
BUILD_DIR := build

# Nombre del ejecutable
TARGET := $(BIN_DIR)/myapp

# Encuentra todos los archivos .c usando find
SRCS := $(shell find $(SRC_DIR) -name '*.c')

# Genera los nombres de los archivos objeto correspondientes
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Flags de inclusión
INCLUDE_FLAGS := -I$(INCLUDE_DIR)

# Regla principal
all: $(TARGET)

# Crea los directorios necesarios
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Regla para compilar el ejecutable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Regla para compilar cada archivo .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Regla para limpiar objetos y ejecutable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(BUILD_DIR)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Nueva regla para construir con CMake
cmake-build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && make

# Regla para limpiar la construcción de CMake
cmake-clean:
	rm -rf $(BUILD_DIR)

# Regla para ejecutar los tests de CMake
cmake-test: cmake-build
	cd $(BUILD_DIR) && ctest

.PHONY: all clean run cmake-build cmake-clean cmake-test