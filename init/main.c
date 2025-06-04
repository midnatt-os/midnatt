#include <midnatt/syscall.h>
#include <stdint.h>
#include <string.h>



int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    const char* msg = "Hello from init";
    syscall2(SYSCALL_DEBUG, (uint64_t) msg, strlen(msg));
    return 69420;
}
