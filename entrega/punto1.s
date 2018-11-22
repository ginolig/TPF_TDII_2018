.text
.arm
.global menu
menu:
        cmp   r0, #1    @case 1
        beq   op1
        cmp   r0, #2    @case 2
        beq   op2
        cmp   r0, #3    @case 3
        beq   op3
        cmp   r0, #4    @case 4
        beq   op4
        mov   r0, #0    @default
        mov   pc, lr

op1:    mov r0, #1
        mov pc, lr
op2:    mov r0, #2
        mov pc, lr
op3:    mov r0, #3
        mov pc, lr
op4:    mov r0, #4
        mov pc, lr
@constantes
.end
