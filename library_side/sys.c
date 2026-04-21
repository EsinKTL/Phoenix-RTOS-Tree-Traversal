#include <sys/syscall.h>

/* User-space wrappers for our new syscalls */
int setVariable(int var) {
    return syscall(125, var);
}

int getVariable(void) {
    return syscall(126);
}

/* Not: path_info_t tanımı burada görünmeyebilir, void* kullanmak güvenlidir */
int getLongestPath(int skip_pid, void *info) {
    return syscall(127, skip_pid, info);
}

