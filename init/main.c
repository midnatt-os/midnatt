#include <midnatt/syscall.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "bits/posix/posix_stdio.h"
#include "flanterm.h"
#include "flanterm_backends/fb.h"

typedef struct {
    void*    address;
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
    uint16_t bpp;
    uint8_t  red_mask_size;
    uint8_t  red_mask_shift;
    uint8_t  green_mask_size;
    uint8_t  green_mask_shift;
    uint8_t  blue_mask_size;
    uint8_t  blue_mask_shift;
} SysFramebuffer;

typedef struct {
    uint8_t scancode;
    bool released;
    bool extended;
} KeyEvent;



int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    char *argv2[] = { "/usr/bin/bash", "--noprofile", "--norc", nullptr };
    char *envp[] = { "TERM=dumb", nullptr };

    execve("/usr/bin/bash", argv2, envp);

    /*FILE* tty = fopen("/dev/tty","r+");
    if (tty == nullptr) {
        return 1;
    }

    int tty_fd = fileno(tty);
    dup2(tty_fd, 0);
    dup2(tty_fd, 1);
    dup2(tty_fd, 2);

    fclose(tty);*/


    /*SysFramebuffer fb;
    syscall1(SYSCALL_FETCH_FRAMEBUFFER, (uintptr_t) &fb);

    struct flanterm_context *ft_ctx = flanterm_fb_init(
        NULL,
        NULL,
        fb.address, fb.width, fb.height, fb.pitch,
        fb.red_mask_size, fb.red_mask_shift,
        fb.green_mask_size, fb.green_mask_shift,
        fb.blue_mask_size, fb.blue_mask_shift,
        NULL,
        NULL, NULL,
        NULL, NULL,
        NULL, NULL,
        NULL, 0, 0, 1,
        0, 0,
        0
    );

    FILE* kb = fopen("/dev/input/keyboard", "rb");
    if (kb == nullptr)
        return 1;

    while (true) {
        KeyEvent ke;
        ssize_t read_count = fread(&ke, sizeof(KeyEvent), 1, kb);
        if (read_count == 1) {
            char msg[100];
            sprintf(msg, "{ scancode: %#lx, released: %s, extended: %s }\n",
                ke.scancode,
                ke.released ? "true" : "false",
                ke.extended ? "true" : "false");

            flanterm_write(ft_ctx, msg, sizeof(msg));
        }
    }*/

    return 0;
}
