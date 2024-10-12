#include <assert.h>

// Asume que tienes una función llamada 'otra_funcion' que quieres probar
int otra_funcion(int a, int b){
    return a+b;
};

int main() {
    assert(otra_funcion(2, 3) == 5);
    return 0;
}