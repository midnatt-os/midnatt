[[gnu::naked, gnu::section(".text.startup")]] void _start(void) {
    asm volatile("movabsq $0x00000000deadbeef, %r15");
    asm volatile("movabsq $0x00000000deadbeef, %r14");
    asm volatile("movabsq $0x00000000CAFEBABE, %r13");
    asm volatile("jmp _start");
}
