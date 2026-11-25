# /*
# Author: Cristhian Adoney Cruz Delgado
# Variable mapping
# x -> $s0
# c -> $s1
# resto -> $t0
# cuenta -> $s2
#
# hi -> remainder || lo -> quotient
# */

	.data
titulo:	.asciiz "This program counts how many times a digit appears in a positive integer.\n"
pideX:	.asciiz "Enter a positive integer (enter a negative number to end the program): "
pideC:	.asciiz "Enter the digit (0-9, enter anything else to end the program): "
cuenta	.asciiz "Number of times the digit appears in the number: "
fin:	.asciiz "End of program.\n"

	.text
main:

# #include <iostream>
# int main() {
#    int x, c;
#    int cuenta = 0;

#     while (true) {
while:
#         std::cout << "This program counts how many times a digit appears in a positive integer.\n";
#         std::cout << "Enter a positive integer (enter a negative number to end the program): ";
	li $v0,4
	la $a0,titulo
	syscall
	li $v0,4
	la $a0,pideX
	syscall
#         std::cin >> x;
	li $v0,5
	syscall
	move $s0,$v0

#         if (x < 0) break;
	bltz $s0,,fin_while

#         std::cout << "Enter the digit (0-9, enter anything else to end the program): ";
	li $v0,4
	la $a0,pideC
	syscall
#         std::cin >> c;
	li $v0,5
	syscall
	move $s1,$v0

#         if ((c < 0) || (c > 9)) break;
	bltz $s1,fin_while
	bgt $s1,9,fin_while
#         cuenta = 0;
	li $s2,$zero
#         int resto;
#         while ( x != 0 ) {
	while2:	beqz $s0,fin_while2
#             resto = x % 10;
#             x /= 10;
		li $t1,10
		div $s0,$t1
		mfhi $t0
		mflo $s0
#             if ( resto == c ) cuenta++;
		bne $t0,$s1,if
			addi $s2,1
		fin if:
#         }
		j while2
	fin_while2:
#         std::cout << "Number of times the digit appears in the number: " << cuenta << std::endl;
	li $v0,4
	la $a0,cuenta
	syscall
	li $v0,1
	move $a0,$s2
	syscall
	li $v0,11
	li $a0,10
	syscall
	j while
#     }
fin_while:
#     std::cout << "End of program.\n";
#     return 0;
	li $v0,4
	la $a0,fin
	syscall
	li $v0,10
	syscall
# }
