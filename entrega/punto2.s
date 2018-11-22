.text
.arm
.global delay
delay:
        mov   r1, r0
loop:   sub   r1, #1
        cmp   r1, #0
        bhi   loop
        mov   pc, lr

@constantes
.end
