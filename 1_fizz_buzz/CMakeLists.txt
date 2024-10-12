cmake_minimum_required(VERSION 3.10)
project(c_app)

# Habilitar CTest
enable_testing()

# Agregar el ejecutable principal
add_executable(main src/main.c)

# Agregar el ejecutable de pruebas
add_executable(test_main tests/test_main.c)
add_executable(test_shon tests/test_shon.c)

# Agregar la prueba
add_test(NAME TestMain COMMAND test_main)
add_test(NAME TestShon COMMAND test_shon)