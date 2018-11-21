.text
.arm
.global delay
delay:
        mov   r1, r0
loop:   sub   r1, #1
        cmp   r1, #0
        bhi   loop
        moveq r0, #1
        movne r0, #0
        mov   pc, lr

@constantes
.end
