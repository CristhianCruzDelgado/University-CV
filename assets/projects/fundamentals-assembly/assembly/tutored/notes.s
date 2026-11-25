tamaño = 4
        .data

dato1:  .word 5
dato2:  .float 3.2
dato3:  .double 3.1416
dato4:  .word 7,1,4,2,6,8,1,9,3,6

        .text
main:
    lw $t0,dato1 # load
    addi $t0,1
    sw $t0,dato1  # store

    l.s $f6,dato2 # load
    add.s $f6,$f6,$f6
    s.s $f6,dato2 # store

    l.d $f6,dato3 # load
    add.d $f6,$f6,$f6
    s.d $f6,dato3 # store

    la $t1,dato4
    lw $t0,20($t1)

    #$t1 -> base
    la $t1,dato4
    #$t2 -> index
    mul $t2,$t2,tamaño
    add $t2,$t2,$t1
    lw $t2,0($t2)

    li $v0,10
    syscall

C++:

int main() {
  const int n = 5;
  int v[n] = {3, 2, 1, 6, 4};
  int i, suma = 0;
  for (i = 0; i < n; ++i) {
    suma += v[i];
  }
  return 0;
}

Assembly:

# Variables:
# i -> $t1
# suma -> $s0
N = 5
tamaño = 4
        .data
v:  .word 3,2,1,6,4
        .text
main:
    move $zero,$s0
    move $zero,$t1
    # $t2 -> base
    la $t2,v
for:    bge $t1,N,fin_for
        # la $t2,v | moved out of the loop
        # more efficient
        lw $t3,0($t2)
        add $s0,$s0,$t3
        addi $t2,size

        addi $t1,1
        j for
fin_for:
    li $v0,10
    syscall

# less efficient
    # mul $t3,$t1,tamaño
    # add $t3,$t3,$t2
    # lw $t3,0($t3)
    # add $d0,$s0,$t3
