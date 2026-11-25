#/*
# * File:   repasotablas.cpp
# * Authors: Carlos and Alberto
# *
# * Description: The user enters the multiplication table they want
# * to review. If they enter 0, the program ends. If they enter a
# * number greater than 0, the program asks the user for every product
# * of that number by the numbers from 1 to 10. At the end of each table,
# * the percentage of correct answers is shown.
# */
##include <iostream>

#int main(int argc, char** argv) {

#  std::cout << "Program for reviewing multiplication tables.\n";
#  int n; // number whose table is reviewed
#  do {
#    std::cout<<"Which table do you want to review? Enter a number (0 to exit): ";
#    std::cin >> n;
#    if (n == 0) break; // entering 0 exits the loop
#    int aciertos = 0; // initialise the number of correct answers
#    for (int i = 1; i <= 10; i++) {
#      std::cout << i << " x " << n << " ? ";
#      int resultado;
#      std::cin >> resultado;
#      if (resultado == (i * n)) {
#        aciertos++;
#      }
#    }
#    int porcentaje = aciertos * 10;
#    std::cout << "Your percentage of correct answers is " << porcentaje << "%\n";
#  } while (n != 0);
#  std::cout << "The program ends.\n";
#}

	.data
strTitulo:	.asciiz "Program for reviewing multiplication tables.\n"
strQueTabla:	.asciiz "Which table do you want to review? Enter a number (0 to exit): "
strX:		.asciiz " x "
strInterroga:	.asciiz " ? "
strTuPorcen:	.asciiz "Your percentage of correct answers is "
strPorcent:	.asciiz "%\n"
strTermina:	.asciiz "The program ends.\n"

	.text
# Assignment of variables to registers
# n 		-> $s0
# aciertos 	-> $s1
# i 		-> $s2
# resultado 	-> $s3
# porcentaje	-> $s4

#int main(int argc, char** argv) {
main:

#  std::cout << "Program for reviewing multiplication tables.\n";
	li	$v0,4
	la	$a0,strTitulo
	syscall

#  int n; // number whose table is reviewed
#  do {
do_while:
#    std::cout<<"Which table do you want to review? Enter a number (0 to exit): ";
	li	$v0,4
	la	$a0,strQueTabla
	syscall
#    std::cin >> n;
	li	$v0,5
	syscall
	move	$s0,$v0

#    if (n == 0) break; // entering 0 exits the loop
	beq	$s0,$zero,fin_do_while

#    int aciertos = 0; // initialise the number of correct answers
	move	$s1,$zero

#    for (int i = 1; i <= 10; i++) {
	li	$s2,1
for:
	bgt	$s2,10,for_fin

#      std::cout << i << " x " << n << " ? ";
	li	$v0,1
	move	$a0,$s2
	syscall

	li	$v0,4
	la	$a0,strX
	syscall

	li	$v0,1
	move	$a0,$s0
	syscall

	li	$v0,4
	la	$a0,strInterroga
	syscall

#      int resultado;
#      std::cin >> resultado;
	li	$v0,5
	syscall
	move	$s3,$v0

#      if (resultado == (i * n)) {
if_resultado:
	mul	$t0,$s2,$s0
	bne	$s3,$t0,if_resultado_fin

#        aciertos++;
	addi	$s1,1
#      }
if_resultado_fin:

#    }

	addi	$s2,1
	b	for
for_fin:

#    int porcentaje = aciertos * 10;
	mul	$s4,$s1,10

#    std::cout << "Your percentage of correct answers is " << porcentaje << "%\n";
	li	$v0,4
	la	$a0,strTuPorcen
	syscall

	li	$v0,1
	move	$a0,$s4
	syscall

	li	$v0,4
	la	$a0,strPorcent
	syscall

#  } while (n != 0);
	bne	$s0,$zero,do_while
fin_do_while:

#  std::cout << "The program ends.\n";
	li	$v0,4
	la	$a0,strTermina
	syscall

#}
	li	$v0,10
	syscall
