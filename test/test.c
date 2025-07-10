#include <midnatt/syscall.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>



int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    char msg[50];
    sprintf(msg, "Hello from %s", argv[0]);
    syscall2(SYSCALL_DEBUG, (uintptr_t) msg, strlen(msg));
    while (true);
    return 0;
}
