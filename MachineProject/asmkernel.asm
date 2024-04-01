section .data
var dq 1.5

section .text
bits 64
default rel

global daxpy_x86

;rcx: n (number of elements)- 1st
;xmm1: A (scalar) - 2nd
;r8: pointer to X (array of doubles)- 3rd
;r9: pointer to Y (array of doubles)- 4th
;rbp+32: pointer to Z (array of doubles)- 5th


daxpy_x86:
    push rbp
    mov rbp, rsp
    add rbp, 16

    mov rsi, [rbp + 32]
    
    xor r10, r10
    
daxpy_loop:
    cmp r10, rcx
    jae end_loop
    
    xorpd xmm13, xmm13
    xorpd xmm14, xmm14
    xorpd xmm15, xmm15
    
    movsd xmm13, [r8+ r10*8] ; xmm13 now contains X[i]?
    movsd xmm14, [r9 + r10*8] ; xmm14 now contains Y[i]?
    
    mulsd xmm13, xmm1 ; A * X[i]?
    
    addsd xmm14, xmm13 ; Y[i] + A * X[i]?
    
    movsd xmm15, xmm14
    
    movsd [rsi + r10*8], xmm15 ; assign to Z???
    
    ;increment counter
    inc r10
    jmp daxpy_loop
    
end_loop:
    pop rbp
    ret         