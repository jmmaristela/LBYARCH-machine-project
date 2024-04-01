section .data

section .text
bits 64
default rel

global daxpy

daxpy:
    ; Inputs:
    ;   rcx: n (number of elements)- 1st
    ;   xmm1: A (scalar) - 2nd
    ;   r8: pointer to X (array of doubles)- 3rd
    ;   r9: pointer to Y (array of doubles)- 4th
    ;   rbp+32: pointer to Z (array of doubles)- 5th
    ; Output:
    ;   Z[i] = A * X[i] + Y[i]
    
    push rsi
    push rbp
    mov rbp, rsp
    add rbp, 16
   

    ; Loop through the elements
    xor     r10, r10               ; Clear loop counter
    
    
daxpy_loop:
    cmp r10, rcx
    jae end

    xorps xmm14, xmm14
    xorps xmm15, xmm15

    movsd xmm14, [r8 + 8 * r10]
    vmulsd xmm15, xmm14, xmm1
    addsd xmm15, [r9 + 8 * r10]

    movsd [rbp + 32 + 8 * r10], xmm15
    
    inc r10
    jmp daxpy_loop

end:
    pop rbp
    pop rsi
    ret    