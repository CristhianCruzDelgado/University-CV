# PR1. COMPUTER PRINCIPLES.
# Author: Cristhian Adoney Cruz Delgado
# Last modified:

# Variables: $f20 -> error; $f22 -> e; $f24 -> factorial; $f26 -> number of terms; $f28 -> last term

	.data

titulo:		.asciiz "\nPR1: Computer Principles.\n"
pet:		.asciiz "\nEnter the maximum allowed error: "
caderr:		.asciiz "\nError: the value entered must satisfy 0.00001 <= value < 1\n"
cade:		.asciiz "\nNumber e: "
cadnt:		.asciiz "\nNumber of terms: "
cadfin:		.asciiz "\nPR1: End of program.\n"

	.text

main:

# int main(int argc, char *argv[])
# {
#     double error = 0;
#     double e = 1; // 1/0!
#     double fact = 1; // 0!
#     double numterminos = 1;
#     double ultimo_termino = 1; ; // 1/0!
	li.d $f20,0.0
	li.d $f22,1.0
	li.d $f24,1.0
	li.d $f26,1.0
	li.d $f28,1.0
#     std::cout << "\nPR1: Computer Principles.\n";
	li $v0,4
	la $a0,titulo
	syscall

do_while:
#     do {
#         std::cout << "\nEnter the maximum allowed error: ";
	li $v0,4
	la $a0,pet
	syscall
#         std::cin >> error;
	li $v0,7
	syscall
	mov.d $f20,$f0
#         if (!(error >= 0.00001 && error < 1))
	li.d $f6,0.00001
	li.d $f8,1.0

	c.lt.d $f20,$f6
	bc1f bloque_if
	c.lt.d $f8,$f20
	bc1f bloque_else
	b bloque_if

bloque_if:
#             std::cout << "\nError: the value entered must satisfy 0.00001 <= value < 1\n";
	li $v0,4
	la $a0,caderr
	syscall
	b do_while

bloque_else:
#         else break;
#     } while (true);
while:
#     while (ultimo_termino >= error) {
	c.le.d $f28,$f20
	bc1f fin_while
#         fact *= numterminos;
	mul.d	$f24,$f24,$f26
#         ultimo_termino = 1/fact;
	div.d	$f28,$f8,$f24
#         e += ultimo_termino;
	add.d	$f22,$f22,$f28
#         numterminos++;
	add.d	$f26,$f26,$f8
#     }

fin_while:
#     std::cout <<  "\nNumber e: ";
	li $v0,4
	la $a0,cade
	syscall
#     std::cout << std::fixed << std::setprecision(17) << e;
	li $v0,3
	mov.d $f12,$f22
	syscall
#     std::cout << "\nNumber of terms: "
	li $v0,4
	la $a0,cadnt
	syscall
#	            << int(numterminos);
	cvt.w.d $f26,$f26
	mfc1 $s0,$f26
	li $v0,1
	move $a0,$s0
	syscall
#     std::cout << "\nPR1: End of program.\n";
	li $v0,4
	la $a0,cadfin
	syscall
#     return 0;
	li $v0, 10
	syscall
# }
