# // Author: Christian González Martín
# // Last modified: 30 APR 2024

sizeD = 8
LF = 10
SPACE = 32

    .data
n1:     .word 10
v1:     .double 10.5, 19.5, 7.25, -76.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0
n2:     .word 5
v2:     .double 5.5, 44.5, 24.25, -2.5, 2.5
cad1:   .asciiz "\nComputer Principles. ME1. Normalising vector ...\n"
cad2:   .asciiz "\nNew max: "
cad3:   .asciiz "\nResult ...\n"

    .text
##########################################################################
printvec: # prints a vector of doubles to the console, separated by spaces
        # $a0 memory address of the vector
        # $a1 number of elements of the vector
        bnez $a1,pv_nozero
            li $v0,11
            li $a0,10
            syscall
            jr $ra
        pv_nozero:
            addi $sp,-12
            sw $ra,0($sp)
            sw $s0,4($sp)
            sw $s1,8($sp)
            move $s0,$a0
            move $s1,$a1
            l.d $f12,0($s0)
            li $v0,3
            syscall
            li $a0,32
            li $v0,11
            syscall
            add $a0,$s0,8
            add $a1,$s1,-1
            jal printvec
            lw $ra,0($sp)
            lw $s0,4($sp)
            lw $s1,8($sp)
            addi $sp,12
            jr $ra
##########################################################################

# double maxvect(double *v, const int n) {
#     double max = 0.0;
#     for (int i = 0 ; i < n ; i++) {
#         double elto = fabs(v[i]);
#         if (elto > max) {
#             max = elto;
#             std::cout << "\nNew max: " << max;
#         }
#     }
#     return(max);
# }

# void normaliza (double *v, const int n) {
#     double cociente = maxvect(v,n);
#     if (cociente == 0) return;
#     for (int i = 0 ; i < n ; i++) {
#          v[i] = v[i] / cociente;
#     }
#     return;
# }

# int main(void) {
#     std::cout << "\nComputer Principles. ME1. Normalising vector ...\n";
#     printvec(v1,n1);
#     normaliza(v1,n1);
#     std::cout << "\nResult ...\n";
#     printvec(v1,n1);
#     std::cout << "\nComputer Principles. ME1. Normalising vector ...\n";
#     printvec(v2,n2);
#     normaliza(v2,n2);
#     std::cout << "\nResult ...\n";
#     printvec(v2,n2);
#     return(0);
# }
