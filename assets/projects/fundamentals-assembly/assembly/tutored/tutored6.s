functions
-argument passing :: a0-3, f12-15 using lw, la, li, ld, lf...
-return :: v0-1, f0-3 then move it
-return address :: ra
-stack pointer :: sp [top]
-frame pointer :: fp

func:
    jr $ra
main:
    jal func

stack
-push
# offset from the stack pointer
addi    $sp,$sp,-multiple of 4
sw      registers,0($sp)
...
-pop
lw      registers,0($sp)
...
# offset from the stack pointer
addi    $sp,$sp,multiple of 4

It is needed when there are not enough registers to pass or return values,
when the function calls another function, and
when saved registers are used outside the function and must be used inside it.

factorial
iterative or recursive

factorial:
    trivial case
    jr $ra
    non-trivial:
            push
            number and address
            addi next factorial
            jal factorial

            pop
            number and address
            mul resulting numbers
            jr $ra
main:
    li Number
    jal factorial
