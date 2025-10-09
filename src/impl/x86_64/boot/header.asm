section .multiboot_header
header_start:
    ; multiboot 2
    dd 0xe85250d6
    ; projected mode i386
    dd 0
    ; header length
    dd header_end - header_start
    ;checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ;end
    dw 0
    dw 0
    dd 8
header_end:
