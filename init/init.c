#include <midnatt/syscall.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  for (int i = 0; envp[i] != NULL; i++) {
    syscall2(SYSCALL_DEBUG, (uint64_t)envp[i], strlen(envp[i]));
  }

  return 69;
}
