# Computer Principles. Preparation for the micro-exam
# Operations with functions and indirect addressing
# Author: Cristhian Adoney Cruz Delgado
# Last modified:
#include <iostream>

# const int n1 = 10;
# double v1[n1] = {10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0};
# const int n2 = 5;
# double v2[n2] = {5.5, 4.5, 4.25, 2.5, 2.5};
# const int n3 = 4;
# double v3[n3] = {7.0, 5.0, 2.0, 1.0};

sizeD = 8
LF = 10
SPACE = 32

    .data
n1:     .word 10
v1:     .double 10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0
n2:     .word 5
v2:     .double 5.5, 4.5, 4.25, 2.5, 2.5
n3:     .word 4
v3:     .double 7.0, 5.0, 2.0, 1.0
cad1:   .asciiz "\nVector with dimension "
cad2:   .asciiz "\nTrying to merge two vectors ...\n"
cad3:   .asciiz "\nEND OF PROGRAM\n"

    .text

# Register file:
# $s0 base address of the vector
# #s1 number of elements
# $s2 loop iterator (i)
# $t0 operation accumulator

# void printvec(double *v, const int n) {
print_vec:                      # prints a vector of doubles separated by spaces
    addi $sp,-16                # push 4 integer registers
    sw $ra,0($sp)
    sw $s0,4($sp)
    sw $s1,8($sp)
    sw $s2,12($sp)
    move $s0,$a0                # arguments
    move $s1,$a1
    move $s2,$zero
#     for (int i = 0; i < n; i++)
for_printvec:
        bge $s2,$s1,for_printvec_fin
#         std::cout << v[i] << " ";
        mul $t0,$s2,sizeD
        add $t0,$t0,$s0
        l.d $f12,0($t0)
        li $v0,3
        syscall
        li $v0,11
        li $a0,SPACE
        syscall

        addi $s2,1
        j for_printvec
for_printvec_fin:
#     std::cout << "\n";
    li $v0,11
    li $a0,10
    syscall
#     return;
print_vec_fin:
    sw $ra,0($sp)
    sw $s0,4($sp)
    sw $s1,8($sp)
    sw $s2,12($sp)
    addi $sp,16                 # pop 4 integer registers
    jr $ra
# }

# int ordenado(double *v, const int n) {
ordenado:
#     int resultado = 1;
#     int i = 0;
#     while (i < n-1) {
#         if (v[i+1] >= v[i]) {
#             resultado = 0;
#             break;
#         }
#         i++;
#     }
#     return(resultado);
ordenado_fin:
# }

# Register file:
# $s4 bool vector 1 sorted
# $s5 bool vector 2 sorted

# void merge(double *v1, const int n1,double *v2, const int n2) {
merge:                          # merges two vectors in decreasing order
    addi $sp,xx                 # push x registers

    move $s0,$a0                # arguments
    move $s1,$a1
    move $s2,$a2
    move $s3,$a3
#     int  o1 = ordenado(v1,n1);
    jal ordenado
    move $s4,$v0
#     if (o1 == 0) return;
    beqz $s4,merge_fin
#     int o2 = ordenado(v2,n2);
    jal ordenado
    move $s5,$v0
#     if (o2 == 0) return;
    beqz $s5,merge_fin
#     int i = 0; // index to traverse v1
#     int j = 0; // index to traverse v2
#     while ( ( i < n1) && (j < n2) ) {
#         if (v1[i] >= v2[j]) {
#             std::cout << v1[i] << " ";
#             i++;
#         }
#         else {
#             std::cout << v2[j] << " ";
#             j++;
#         }
#     }
#     while ( i < n1) {
#         std::cout << v1[i] << " ";
#         i++;
#     }
#     while ( j < n2) {
#         std::cout << v2[j] << " ";
#         j++;
#     }
#     std::cout << "\n";
#     return;
merge_fin:
    jr $ra
# }

# Register file:
#

# int main(void) {
main:
#     std::cout << "\nVector with dimension " << n1 << std::endl;
    li $v0,4
    la $a0,cad1
    syscall
    li $v0,1
    lw $a0,n1
    syscall
    li $v0,11
    li $a0,LF
    syscall
#     printvec(v1,n1);
    la $a0,v1
    lw $a1,n1
    jal print_vec
#     std::cout << "\nVector with dimension " << n2 << std::endl;
    li $v0,4
    la $a0,cad1
    syscall
    li $v0,1
    lw $a0,n2
    syscall
    li $v0,11
    li $a0,LF
    syscall
#     printvec(v2,n2);
    la $a0,v2
    lw $a1,n2
    jal print_vec
#     std::cout << "\nVector with dimension " << n3 << std::endl;
    li $v0,4
    la $a0,cad1
    syscall
    li $v0,1
    lw $a0,n3
    syscall
    li $v0,11
    li $a0,LF
    syscall
#     printvec(v3,n3);
    la $a0,v3
    lw $a1,n3
    jal print_vec
#     std::cout << "\nTrying to merge two vectors ...\n";
    li $v0,4
    la $a0,cad2
    syscall
#     merge(v1,n1,v2,n2);
    la $a0,v1
    lw $a1,n1
    la $a2,v2
    lw $a3,n2
    jal merge
#     std::cout << "\nTrying to merge two vectors ...\n";
    li $v0,4
    la $a0,cad2
    syscall
#     merge(v1,n1,v3,n3);
    la $a0,v1
    lw $a1,n1
    la $a2,v3
    lw $a3,n3
    jal merge

#     std::cout << "\nEND OF PROGRAM\n";
    li $v0,4
    la $a0,cad3
    syscall
#     return(0);
    li $v0,10
    syscall
# }
