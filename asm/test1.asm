;---------------------------------------------------------------------------
; nasm - Linux 64-Bit Assembler Test for 32-Bit Program
; (c) 2017 Jens Kallup
;
; nasm -f bin test1.asm
;---------------------------------------------------------------------------
BITS 32                     ; 32-bit coded program

elf_header_start:

    db 0x7f, "ELF"          ; magic number
    db 0x01                 ; class, 1=32bit, 2=64bit
    db 0x01                 ; byteorder, 1=little, 2=big-endian
    db 0x01                 ; header version, always 0
    db 0

    times 8 db 0            ; padding

    dw 2                    ; file type: 2=executable, 3=shared obj.
    dw 3                    ; arch type
    dd 1                    ; file version, always 1

;---------------------------------------------------------------------------
    dd _start               ; entry point
;---------------------------------------------------------------------------

    dd phdr - $$            ; file position of program header
    dd 0                    ; file position of section header
    dd 0                    ; arch flags, usally 0

    dw ehdrsize             ; size of this ELF header
    dw phdrsize             ; size of an entry in program header
    dw 1                    ; number of entries in program header, or 0
    
    dw 0                    ; size of an entry in section header , or 0
    dw 0                    ; number of entries in section header, or 0
    dw 0                    ; section number that contains section strings
    
ehdrsize  equ $ - elf_header_start
;---------------------------------------------------------------------------

phdr:
    dd 1                    ; loadable code, data ...
    dd 0                    ; file offset of segment
    dd $$                   ; virtual address to map segment
    dd $$                   ; physical address, not used
    dd filesize             ; size of segment in file
    dd filesize             ; size of segment in memory
    dd 5                    ; Read, Write, Execute bits
    dd 0x1000               ; required alignment, invariably hw page size
    
phdrsize  equ $ - phdr
;---------------------------------------------------------------------------

shdr:
    
shdrsize  equ $ - shdr
;---------------------------------------------------------------------------

_start:
    mov cx, message
    mov dx, message_length
    mov ax, 4              ; function number: output
    mov di, 1              ; stdio
    int 0x80
    mov ax, 1              ; function number: exit program
    mov bx, 0              ; exit code
    int 0x80
    ret

message: db "Merry Christmas", 10
message_length  equ $ - message

filesize equ $ - $$

