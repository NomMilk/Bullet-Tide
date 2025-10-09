global start

section .text
bits 32
start:
    ; print 'fish'
    mov dword [0xb8000], 0x0F660F66 
    hlt 
