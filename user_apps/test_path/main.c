#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    int max_depth;
    int target_pid;
} path_info_t;

static inline int syscall(int n, int a1, void *a2) {
    int res;
    __asm__ volatile ("int $0x80" : "=a" (res) : "a" (n), "b" (a1), "c" (a2) : "memory");
    return res;
}

static int my_getLongestPath(int skip_pid, path_info_t *info) {
    return syscall(127, skip_pid, info);
}

void create_deep_tree(int current, int target) {
    if (current >= target) {
        printf("[Leaf] PID: %d at Depth: %d\n", getpid(), current);
        sleep(2); 
        return;
    }
    pid_t pid = fork();
    if (pid == 0) {
        create_deep_tree(current + 1, target);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
    }
}

int main(int argc, char **argv) {
    int depth = 10;
    printf("Starting Longest Path Test with Depth: %d\n", depth);

    create_deep_tree(1, depth);

    path_info_t info;
    if (my_getLongestPath(0, &info) == 0) {
        printf("\n--- RESULTS ---\n");
        printf("Max Depth: %d\n", info.max_depth);
        printf("Target PID: %d\n", info.target_pid);
    }
    return 0;
}
