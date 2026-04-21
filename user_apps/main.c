#include <stdio.h>
#include <stdlib.h>

/* Inline Assembly Syscall - Kütüphane bağımlılığını bitiren çözüm */
static inline int syscall_internal(int n, int a1) {
    int res;
    __asm__ volatile ("int $0x80" : "=a" (res) : "a" (n), "b" (a1) : "memory");
    return res;
}

/* 'static' ekleyerek dışarıdaki (kütüphanedeki) setVariable ile çakışmayı önlüyoruz */
static void my_setVariable(int var) {
    syscall_internal(125, var);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int val = atoi(argv[1]);
    printf("Setting kernel global_var to: %d\n", val);

    my_setVariable(val);

    printf("Success! Use getVariable to check the new value.\n");
    return 0;
}
